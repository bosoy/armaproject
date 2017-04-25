#include "script_component.hpp"

private ["_pos", "_smoke", "_fire", "_shards", "_dirt", "_i", "_xv", "_yv", "_dir", "_Crater", "_speed", "_velz", "_tv", "_zv", "_dr"];

PARAMS_4(_vehicle,_int,_t,_s);
_pos = getpos _vehicle;
if (!isDedicated) then {
	// Particle effects
	_smoke = "#particlesource" createVehicleLocal _pos;
	_smoke attachto [_vehicle,[0,0,0],"destructionEffect1"];
	_smoke setParticleParams [["\ca\Data\ParticleEffects\Universal\Universal",16,7,48],
		"", "Billboard", 1, 15*_s, [0, 0, 0], [0, 0, 0], 1, 1.275, 1, 0, [8*_s,14*_s],
		[[0.1,0.1,0.1,1*_s],[0.1,0.1,0.1,0]], [0.5], 0.1, 0.1, "", "", _vehicle];
	_smoke setParticleRandom [4*_s, [2*_s, 2*_s, 2*_s], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];
	_smoke setDropInterval 0.02 * _s;

	_fire = "#particlesource" createVehicleLocal _pos;
	_fire attachto [_vehicle,[0,0,0],"destructionEffect2"];
	_fire setParticleParams [["\ca\Data\ParticleEffects\Universal\Universal",16,2,80],
			"", "Billboard", 1, 2*_s, [0, 1, 0], [0, 0, 0], 1, 1.275, 1, 0, [7*_s,13*_s],
					[[1,1,1,-1*_s],[1,1,1,0]], [0.5], 0.01, 0.01, "", "", _vehicle,360];
	_fire setParticleRandom [0.5*_s, [0.5*_s, 0.5*_s, 0.5*_s], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];
	_fire setDropInterval 0.01 * _s;
	
	_dirt = "#particlesource" createVehicleLocal _pos;
	_dirt attachto [_vehicle,[0,0,0],"destructionEffect1"];
	_dirt setParticleParams [["\ca\Data\ParticleEffects\Universal\Universal",16,12,9,0], "", "Billboard", 1, 5*_s, [0, 0, 0], [0, 0, 5], 0, 5, 1, 0, [10*_s,20*_s],
		[[0.1,0.1,0.1,1*_s],[0.1,0.1,0.1,0.7*_s],[0.1,0.1,0.1,0]], [1000], 0, 0, "", "", _vehicle,360];
		_dirt setParticleRandom [0, [1*_s, 1*_s, 1*_s], [1*_s, 1*_s, 2.5*_s], 0, 0, [0, 0, 0, 0.5*_s], 0, 0];
	_dirt setDropInterval 0.05 * _s;
};

//creating ground craters
_i = 0;
while {_s > 0.6 && {(speed _vehicle) > 0.1}} do {
	_pos=getpos _vehicle;
	_vel = velocity _vehicle;
	_xv=_vel select 0;
	_yv=_vel select 1;
	_dir = abs(_xv atan2 _yv);

	// disabled, nobody needs it
	/*if (_s > 0.6) then {
		_Crater= "CraterLong" createvehiclelocal [_pos select 0, _pos select 1, 0];
		_Crater setdir (_dir + (180 * _i));
		_Crater setpos [_pos select 0, _pos select 1, 0];
		_Crater setPos [_pos select 0, _pos select 1, ((0 - _i)/13)]; //all setpos commands so it is placed correctly on sloped terrain
	};*/
	_speed = (speed _vehicle);
	_zv = _vel select 2;

	if (_zv > 1) then {_vehicle setvelocity [_xv/1.3,_yv/1.3,0]} else {_vehicle setvelocity [_xv/1.2, _yv/1.2, _zv]};

	if (!isDedicated) then {
		_tv = [_xv,_yv,_zv] distance [0,0,0];
		_dr = if (_tv > 2) then {1/_tv} else {1};
		_smoke setDropInterval _dr * 1.5 * _s;
		_fire setDropInterval _dr * 1.5 * _s;
		_dirt setDropInterval _dr * _s;
	};

	sleep (0.25 - (_speed / 1000));
	_i = _i + 1;
};
if (!isDedicated) then {
	deleteVehicle _smoke;
	deleteVehicle _fire;
	deleteVehicle _dirt;
};

_vehicle setvelocity [0,0,-0.1];
if (local _vehicle) then {
	[QGVAR(Burn), [_vehicle,_int,_t]] call CBA_fnc_globalEvent;
	[_vehicle,_int,false] spawn BIS_Effects_Secondaries;
};

sleep 0.5;
_vehicle setvelocity [0,0,-0.01];
