// by Xeno
#define THIS_FILE "x_airtaxiserver.sqf"
#include "x_setup.sqf"
#define __del \
{deleteVehicle _x} forEach [_vehicle] + _crew
private ["_vehicle", "_crew", "_player", "_sidep", "_grp", "_spos", "_cdir", "_veca", "_unit", "_pospl", "_helperh", "_toldp", "_endtime", "_doend"];
if (!isServer) exitWith {};

_player = _this;
_sidep = side (group _player);

_dstart_pos = call FUNC(GetRanPointOuterAir);

_grp = [_sidep] call FUNC(creategroup);
_spos = [_dstart_pos select 0, _dstart_pos select 1, 300];
_cdir = [_spos, position _player] call FUNC(DirTo);
_veca = [_spos, _cdir, GVAR(taxi_aircraft), _grp] call FUNC(spawnVehicle);
_vehicle = _veca select 0;
_crew = _veca select 1;
_unit = driver _vehicle;
__addDead(_vehicle)
_unit setSkill 1;

_vehicle lockdriver true;

_pospl = getPosASL player;
_pospl set [2,0];
_helperh = GVAR(HeliHEmpty) createVehicleLocal _pospl;
_vehicle flyInHeight 80;
_unit doMove (position _player);
_vehicle flyInHeight 80;
_grp setBehaviour "CARELESS";
[QGVAR(airtaxi_marker), position _vehicle, "ICON", "ColorBlue", [1,1], "Air Taxi", 0, if (_sidep == west) then {"b_air"} else {"o_air"}] call FUNC(CreateMarkerGlobal);

sleep 10;

if (!alive _player) exitWith {
	deleteMarker QGVAR(airtaxi_marker);
	[QGVAR(ataxi), [_player, 1]] call FUNC(NetCallEventSTO);
	sleep 120;
	__del;
};

[QGVAR(ataxi), [_player, 0]] call FUNC(NetCallEventSTO);

_toldp = false;
_endtime = time + 720;
_doend = false;
while {alive _unit && alive _vehicle && canMove _vehicle} do {
	QGVAR(airtaxi_marker) setMarkerPos (getPosASL _vehicle);
	if (!_toldp) then {
		if (_vehicle distance _helperh < 1000 && alive _player) then {
			[QGVAR(ataxi), [_player, 6]] call FUNC(NetCallEventSTO);
			_toldp = true;
		};
	};
	if (unitReady _unit) exitWith {
		sleep 0.1;
		_vehicle land "LAND";
	};
	if (time > _endtime) exitWith {
		_doend = true;
	};
	sleep 2.012;
};

if (!alive _unit || !alive _vehicle || !canMove _vehicle || _doend) exitWith {
	deleteMarker QGVAR(airtaxi_marker);
	[QGVAR(ataxi), [_player, 2]] call FUNC(NetCallEventSTO);
	sleep 120;
	__del;
};

if (alive _unit && alive _player && alive _vehicle && canMove _vehicle) then {
	_endtime = time + 820;
	_doend = false;
	while {alive _unit && alive _vehicle && alive _player && !(_player in crew _vehicle) && canMove _vehicle} do {
		QGVAR(airtaxi_marker) setMarkerPos (getPosASL _vehicle);
		if (time > _endtime) exitWith {
			_doend = true;
			deleteMarker QGVAR(airtaxi_marker);
			[QGVAR(ataxi), [_player, 2]] call FUNC(NetCallEventSTO);
			sleep 120;
			__del;
		};
		sleep 1.012;
	};
	if (_doend) exitWith {};
	if (alive _unit && alive _vehicle && canMove _vehicle) then {
		[QGVAR(ataxi), [_player, 3]] call FUNC(NetCallEventSTO);
		
		sleep 30 + random 5;
		[QGVAR(ataxi), [_player, 5]] call FUNC(NetCallEventSTO);
		_vehicle flyInHeight 80;
		_unit doMove (position GVAR(AISPAWN));
		_vehicle flyInHeight 80;
		_grp setBehaviour "CARELESS";
		sleep 5;
		_doend = false;
		while {alive _unit && alive _vehicle && canMove _vehicle} do {
			QGVAR(airtaxi_marker) setMarkerPos (getPosASL _vehicle);
			if (unitReady _unit) exitWith {
				sleep 0.1;
				_vehicle land "LAND";
			};
			if (!alive _unit || !alive _vehicle || !canMove _vehicle) exitWith {
				_doend = true;
				[QGVAR(ataxi), [_player, 2]] call FUNC(NetCallEventSTO);
				deleteMarker QGVAR(airtaxi_marker);
				sleep 120;
				__del;
			};
			sleep 2.012
		};
		if (_doend) exitWith {};
		
		while {alive _unit && alive _vehicle && alive _player && (_player in crew _vehicle) && canMove _vehicle} do {
			sleep 3.221;
		};
		sleep 20 + random 5;
		
		if (alive _unit && alive _vehicle && canMove _vehicle) then {
			[QGVAR(ataxi), [_player, 4]] call FUNC(NetCallEventSTO);
			_vehicle flyInHeight 80;
			_unit doMove _dstart_pos;
			_vehicle flyInHeight 80;
			_grp setBehaviour "CARELESS";
			_endtime = time + 720;
			while {alive _unit && alive _vehicle && canMove _vehicle} do {
				QGVAR(airtaxi_marker) setMarkerPos (getPosASL _vehicle);
				if (_vehicle distance _dstart_pos < 300) exitWith {};
				if (time > _endtime) exitWith {};
				sleep 2.012
			};
			deleteMarker QGVAR(airtaxi_marker);
			sleep 120;
			__del;
		} else {
			[QGVAR(ataxi), [_player, 1]] call FUNC(NetCallEventSTO);
			deleteMarker QGVAR(airtaxi_marker);
			sleep 120;
			__del;
		};
	} else {
		[QGVAR(ataxi), [_player, 1]] call FUNC(NetCallEventSTO);
		deleteMarker QGVAR(airtaxi_marker);
		sleep 120;
		__del;
	};
};

deleteVehicle _helperh;