/*
EJECT UNIT SCRIPT

© AUGUST 2009 - norrin
Based loosely on the OFPEC fast rope script

***********************************************************************************************************************************
eject_unit.sqf
*/

#include "script_component.hpp"

#define ACE_TEXT_ORANGE(Text) ("<t color='#ffa500'>" + ##Text + "</t>")

private ["_heli", "_group", "_count", "_target", "_endcond", "_wtime", "_ropelen", "_nomorerope", "_Offset", "_i", "_ang"];

PARAMS_3(_unit,_distance,_rope);

_heli = vehicle _unit;
_group = group _unit;
_units_group = units _group;
_no_group = count _units_group;
_count = 0;
#define __particle "\ca\data\Cl_basic.p3d"

if (!local _unit || {_unit == (driver vehicle _unit)} || {_unit == gunner (vehicle _unit)}) exitWith {};

sleep 1;

if (_heli getVariable "ACE_RopeAbort") exitWith {};

if (player == _unit) exitWith {
	if (!isNull (GVAR(fr_state) select 0) && {(GVAR(fr_state) select 1) != -9999}) then {
		(GVAR(fr_state) select 0) removeAction (GVAR(fr_state) select 1);
	};
	GVAR(fr_state) set [0, _heli];
	GVAR(fr_state) set [1, (_heli addAction[ACE_TEXT_ORANGE(localize "STR_ACE_USE_ROPE"), QPATHTO_F(player_fastrope), _rope, -1000, false, false, "","(player in _target) && {((_target getVariable 'ACE_RopeInUse') == 1)} && {(count(assignedVehicleRole player) != 2)} && {(player != driver _target)}"])];
};

_endcond = false;
while {_unit != _units_group select _count} do {
	_wtime = time + 1 + random 1;
	waitUntil {sleep 0.106;time >= _wtime || {(_heli getVariable "ACE_RopeAbort")} || {((position _heli select 2) < 2)}};
	if (_heli getVariable "ACE_RopeAbort") exitWith {};
	if (position _heli select 2 < 2) exitWith {_endcond = true};
	INC(_count);
};

if ((_heli getVariable "ACE_RopeAbort") || _endcond) exitWith {};

_ropelen = switch (toUpper typeOf _rope) do {
	case "ACE_FASTROPE_50": {16};
	case "ACE_FASTROPE_60": {19};
	case "ACE_FASTROPE_90": {28};
	case "ACE_FASTROPE_120": {37};
};
INC(_ropelen);

_unit setUnitPos "Up";
_unit action ["GetOut", _heli];
sleep 0.2;
[_unit] allowGetIn false;

_height_elevator = 0;

[QGVAR(a1), _unit] call CBA_fnc_globalEvent;
_unit disableAI "ANIM"; _unit disableAI "MOVE";

_random_dir = 70 + round (random 40);
_unit setdir ((getDir _heli) + _random_dir);
sleep 0.1;
// fix for choppers with roadway lod
if ((position _heli select 2) > 5 && {(position _unit select 2) < 2}) then {
	_punp = getPosASL _unit;
	_punp set [2, (position _heli select 2) - 1];
	_unit setPos _punp;
};
_unit attachto [_rope,[0,0,_height_elevator]];

_fast_height = 5 + (_count * 1.5);
_nomorerope = false;
while {!_nomorerope && {((getPos _unit) select 2) > _fast_height} && {!(_heli getVariable "ACE_RopeAbort")}} do {
	detach _unit;
	_height_elevator = _height_elevator - 0.6;
	_unit attachto [_rope,[0,0,_height_elevator]];
	sleep 0.03;
	if (position _unit select 2 < ((position _heli select 2) - _ropelen)) then {_nomorerope = true};
};

if (_heli getVariable "ACE_RopeAbort") then {_nomorerope = true};

if (!_nomorerope) then {
	while {!_nomorerope && {((getPos _unit) select 2) > 3} && {!(_heli getVariable "ACE_RopeAbort")}} do {
		detach _unit;
		_height_elevator = _height_elevator - 0.3;
		_unit attachto [_rope,[0,0,_height_elevator]];
		sleep 0.03;
		if (position _unit select 2 < ((position _heli select 2) - _ropelen)) then {_nomorerope = true};
	};
};

if (_heli getVariable "ACE_RopeAbort") then {_nomorerope = true};

if (!_nomorerope) then {
	while {!_nomorerope && {((getPos _unit) select 2) > 1.5} && {!(_heli getVariable "ACE_RopeAbort")}} do {
		detach _unit;
		_height_elevator = _height_elevator - 0.1;
		_unit attachto [_rope,[0,0,_height_elevator]];
		sleep 0.03;
		if (position _unit select 2 < ((position _heli select 2) - _ropelen)) then {_nomorerope = true};
	};
};
sleep 0.03;
detach _unit;

_Offset = 0;
if (!_nomorerope) then {
	_pos_land = getPos _unit;
	_Offset = _unit distance _pos_land;
	_unit setPos [getPos _unit select 0,getPos _unit select 1, _offset];
};
unassignVehicle _unit;

_i = floor (random 2);
switch (_i) do {
	case 0: {
		_unit enableAI "ANIM";_unit enableAI "MOVE";
		[QGVAR(a2), _unit] call CBA_fnc_globalEvent;
	};
	case 1: {
		_unit enableAI "ANIM";_unit enableAI "MOVE";
		[QGVAR(a2), _unit] call CBA_fnc_globalEvent;
	};
};

sleep 0.2;

if (!_nomorerope) then {
	drop [__particle,"","Billboard",100,1,[(getPos _unit) select 0,(getPos _unit) select 1,_Offset],[0,0,0],10,25.5,20,0.14,[0.4,1.0],[[0.8,0.6,0.3,1],[0.8,0.6,0.4,1],[0.9,0.7,0.4,
	1],[0.8,0.7,0,0]],[0,1,0,1],0,0,"","",""];
};


if (alive _unit) then {
	_ang = ceil(random 360);
	_pos_unit = getPos _unit;
	_unit doMove [(_pos_unit select 0) + (_distance * sin _ang), (_pos_unit select 1) + (_distance * cos _ang), _Offset];
	sleep 3;

	[_unit] allowGetIn true;
};
