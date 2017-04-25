#include "\x\ace\addons\sys_explosives\script_component.hpp"

private ["_by","_h"];

PARAMS_4(_unit,_mine,_vehicle,_posASL);

if (3 < ((getPosASL _unit) distance _posASL)) exitWith {};

_by = _mine getVariable [QUOTE(GVARMAIN(attachedBy)), ""];
if !(_by == "" || {_by == "sys_cargo" && {_unit getVariable ["ace_sys_cargo_carrying", false]} && {_mine == _unit getVariable ["ace_sys_cargo_carried_object",objNull]}}) exitWith {};


if (_by == "sys_cargo") then {
	_unit setVariable ["ace_sys_cargo_carrying", false];
	_h = ["","",-1,["stop",_mine]] spawn ace_sys_cargo_fnc_carry;
	waitUntil {scriptDone _h};
};

_mine attachTo [_vehicle, _vehicle worldToModel (if (surfaceIsWater _posASL) then {_posASL} else {ASLToATL _posASL})];
_mine setVariable [QUOTE(GVARMAIN(attachedBy)), QUOTE(COMPONENT), true];
//_mine setVariable [QGVARMAIN(attachedTo), _vehicle, true];
