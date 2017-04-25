#include "script_component.hpp"
#define __toler 0.00001

//////////////////////////////////////////
// Continuous Turret Traverse Rate Code //
//////////////////////////////////////////
//
// Computes average turret traverse and elevation rates and tank velocity
// Outputs to vehicle-specific variables
private ["_tazichange","_azcount","_f","_tazichangeprev","_rangefinder","_timestep","_avgtime","_computrelead",
"_weapondir","_wx","_wy","_wz","_weapondirang","_weaponazimuth",
"_tazimuth","_televation","_ttime","_tankvel","_lastelement"];

_rangefinder = (weapons _this) select 0;

_timestep = 0.1; // update rate
_avgtime = 1.5 - _timestep;  // minimum time to average over

_computelead = true;

[_this,_timestep] spawn { // smoothly interpolate turret speeds for every frame
	private ["_f","_player","_rangefinder","_avgtime","_computrelead",
	"_weapondir","_wx","_wy","_wz","_weapondirang","_weaponazimuth",
	"_tazimuth","_televation","_ttime","_tankvel","_tankvel0","_tankvel1","_avgtankvel",
	"_oldazimuthspeed","_oldelevationspeed","_oldavgtankvel","_endtimer",
	"_ttimechange","_tazichange","_telechange","_azimuthspeed","_elevationspeed"
	];

	sleep 0.001;

	_player = player;
	PARAMS_2(_veh,_timestep);
	_computelead = true;

	_oldazimuthspeed = 0;
	_oldelevationspeed = 0;
	_oldavgtankvel = 0;

	_endtimer = 10;

	while { _computelead } do {
		_ttime = _veh getVariable ["ace_turret_time", []];
		_tazimuth = _veh getVariable ["ace_turret_azimuth", []];
		_televation = _veh getVariable ["ace_turret_elevation", []];
		_tankvel = _veh getVariable ["ace_tank_velocity", []];

		if(count _tazimuth >= 2)then
		{
			_ttimechange =  -(_ttime select 1) + (_ttime select (count _ttime - 1));
			_tazichange =  -(_tazimuth select 1) + (_tazimuth select (count _tazimuth - 1));
			_telechange =  -(_televation select 1) + (_televation select (count _televation - 1));
			if (_tazichange > 180) then {_tazichange = _tazichange-360};
			if (_tazichange < -180) then {_tazichange = _tazichange+360};

			_azimuthspeed = 0;
			_elevationspeed = 0;
			if (_ttimechange != 0) then {
				_azimuthspeed = _tazichange / _ttimechange * pi/180;
				_elevationspeed = _telechange / _ttimechange * pi/180;
			};

			// I don't know how or why this works the way it does
			_azimuthspeed = _oldazimuthspeed + (_azimuthspeed-_oldazimuthspeed)/7.5;
			_elevationspeed = _oldelevationspeed + (_elevationspeed-_oldelevationspeed)/7.5;

			if (abs(_azimuthspeed) < __toler) then {_azimuthspeed = 0};
			if (abs(_elevationspeed) < __toler) then {_elevationspeed = 0};

			_oldazimuthspeed = _azimuthspeed;
			_oldelevationspeed = _elevationspeed;

			// dump currently active lead when turret not moving
			if (_azimuthspeed == 0) then {
				_f = _veh getvariable "ace_tankfcs_fired";
				if (!isNil "_f" && {count _f > 1}) then {
					if (((_f select 1) select 0) != 0) then	{ //current lead > 0
						[] call FUNC(dumplead);
						//player sidechat "lead dumped";
					};
				};
			};

			_tankvel1 = _tankvel select (count _tankvel - 1);
			_tankvel0 = _tankvel select 1;
			_avgtankvel = [((_tankvel1 select 0) + (_tankvel0 select 0))/2,
			((_tankvel1 select 1) + (_tankvel0 select 1))/2,
			((_tankvel1 select 2) + (_tankvel0 select 2))/2];

			_veh setVariable ["ace_turret_speed", [_azimuthspeed, _elevationspeed]];
			_veh setVariable ["ace_avg_tank_velocity", _avgtankvel];

			// Run at least twice
			if (count _tazimuth >= 2) then { _computelead = _veh getVariable ["ace_compute_lead", false] };

			if (count _tazimuth >= 2 && {!(_veh getVariable ["ace_compute_lead", false])}) then {
				_endtimer = _endtimer - 1;
				if (_endtimer <= 0) then {
					_computelead = false;
				};
			};
		};
		//hint format ["Turret Azimuth Rate: %1 deg/s\nTurret Elevation Rate: %2 deg/s",_azimuthspeed * 180/pi,_elevationspeed * 180/pi];
		// hint format ["Turret Azimuth Rate: %1 mrad/s\nTurret Elevation Rate: %2 mrad/s\nVelocity: %3 m/s",_azimuthspeed * 1000,_elevationspeed * 1000,_avgtankvel];
		sleep 0.001;
	};

	_veh setVariable ["ace_turret_speed", [0, 0]];
	_veh setVariable ["ace_avg_tank_velocity", [0,0,0]];
};

while { _computelead } do { // update turret position every _timestep
	_weapondir = _this weaponDirection _rangefinder;
	_wx = _weapondir select 0;
	_wy = _weapondir select 1;
	_wz = _weapondir select 2;
	//_weapondirang = [_wx atan2 _wy, sqrt(_wy*_wy + _wx*_wx) atan2 (-_wz)];
	//_weaponazimuth = _weapondirang select 0;
	//_weaponelevation = _weapondirang select 1;
	_weaponazimuth = [_wx atan2 _wy] call cba_fnc_simplifyangle;
	_weaponelevation = [sqrt(_wx^2 + _wy^2) atan2 (-_wz)] call cba_fnc_simplifyangle;
	_weapondirang = [_weaponazimuth, _weaponelevation];

	// create turret position and time arrays with _avgtime/_timestep elements
	// element (0) will be the turret position _avgtime seconds ago
	// element (_avgtime/_timestep - 1) will be the current turret position
	// elements will be rotated every _timestep

	_tazimuth = _this getVariable ["ace_turret_azimuth", []];
	_televation = _this getVariable ["ace_turret_elevation", []];
	_ttime = _this getVariable ["ace_turret_time", []];
	_tankvel = _this getVariable ["ace_tank_velocity", []];

	_azcount = count _tazimuth;

	// if tracking direction changed, reset the azimuth array at once and dump lead
	if (_azcount >= 2) then {
		_tazichange = _weaponazimuth - (_tazimuth select (_azcount - 1));
		if (_tazichange > 180) then {_tazichange = _tazichange-360};
		if (_tazichange < -180) then {_tazichange = _tazichange+360};
		_tazichangeprev = _this getvariable ["ace_tankfcs_azichangeprev", 0];
		//hint format ["Curr change: %1 deg\nPrev change: %2 deg",_tazichange,_tazichangeprev];

		if (_tazichangeprev != 0 && _tazichangeprev*_tazichange <= 0) then {
			for "_i" from 0 to _azcount-1 do {
				_tazimuth set [_i,_weaponazimuth];
			};
			_f = _this getvariable ["ace_tankfcs_fired", []];
			if (count _f > 1) then {
				if (abs((_f select 1) select 0) > 0) then {	//current lead > 0
					[] call FUNC(dumplead);
					//player sidechat format ["lead dumped_2, azichange %1",_tazichange];
				};
			};
		};
		_this setvariable ["ace_tankfcs_azichangeprev",_tazichange];
	};
	if ( _azcount >= (_avgtime/_timestep) ) then {
		_tazimuth set [0,9999]; // so it won't remove duplicates
		_televation set [0,9999];
		_ttime set [0,9999];
		_tankvel set [0,9999];

		_tazimuth = _tazimuth - [9999];
		_televation = _televation - [9999];
		_ttime = _ttime - [9999];
		_tankvel = _tankvel - [9999];
	};

	_tazimuth set [count _tazimuth,_weaponazimuth];
	_televation set [count _televation,_weaponelevation];
	_ttime set [count _ttime,time];
	_tankvel set [count _tankvel,velocity _this];

	_this setVariable ["ace_turret_time", _ttime];
	_this setVariable ["ace_turret_azimuth", _tazimuth];
	_this setVariable ["ace_turret_elevation", _televation];
	_this setVariable ["ace_tank_velocity", _tankvel];

	//hint format ["[ttime,tazim,telev,tankvel] %1",[_ttime,_tazimuth,_televation,_tankvel]];

	// Run at least twice
	if ( count _tazimuth >= 2 ) then { _computelead = _this getVariable ["ace_compute_lead", false] };

	sleep _timestep;
};
