/*
EJECT UNIT SCRIPT

© AUGUST 2009 - norrin
Based loosely on the OFPEC fast rope script

***********************************************************************************************************************************
eject_unit.sqf
*/

#include "script_component.hpp"

private ["_unit", "_rope", "_heli", "_count", "_ropelen", "_nomorerope", "_ropeend", "_Offset", "_i"];

_unit = player;
_rope = _this select 3;
_heli = vehicle _unit;
_count = 1;
#define __particle "\ca\data\Cl_basic.p3d"

(GVAR(fr_state) select 0) removeAction (GVAR(fr_state) select 1);
GVAR(fr_state) set [0, objNull];
GVAR(fr_state) set [1, -9999];

sleep 1;

if (isNull _rope) exitWith {};
if (_heli getVariable "ACE_RopeAbort") exitWith {};

_ropelen = switch (toUpper typeOf _rope) do {
	case "ACE_FASTROPE_50": {16};
	case "ACE_FASTROPE_60": {19};
	case "ACE_FASTROPE_90": {28};
	case "ACE_FASTROPE_120": {37};
};
_ropelen = _ropelen + 1;

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
	if (animationState player != "MLB_Fast_Rope") then {[QGVAR(a1), player] call CBA_fnc_globalEvent};
	_unit attachto [_rope,[0,0,_height_elevator]];
	sleep 0.03;
	_ropeend = (position _heli select 2) - (_ropelen + 1);
	if (position _unit select 2 < ((position _heli select 2) - _ropelen)) then {_nomorerope = true};
};

if (_heli getVariable "ACE_RopeAbort") then {_nomorerope = true};

if (!_nomorerope) then {
	while {!_nomorerope && {((getPos _unit) select 2) > 3} && {!(_heli getVariable "ACE_RopeAbort")}} do {
		detach _unit;
		_height_elevator = _height_elevator - 0.3;
		if (animationState player != "MLB_Fast_Rope") then {[QGVAR(a1), player] call CBA_fnc_globalEvent};
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
		if (animationState player != "MLB_Fast_Rope") then {[QGVAR(a1), player] call CBA_fnc_globalEvent};
		_unit attachto [_rope,[0,0,_height_elevator]];
		sleep 0.03;
		if (position _unit select 2 < ((position _heli select 2) - _ropelen)) then {_nomorerope = true};
	};
};
sleep 0.03;
detach _unit;

if (!_nomorerope) then {
	_pos_land = getPos _unit;
	_Offset = _unit distance _pos_land;
	_unit setPos [(getPos _unit select 0),(getPos _unit select 1), _offset];
};

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
