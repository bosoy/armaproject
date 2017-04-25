#include "script_component.hpp"

// _this (c) by Xeno

private ["_topull"];
closeDialog 0;

PARAMS_1(_topull);

TRACE_1("Pulling", _topull);

if (!alive player) exitWith {};
if (vehicle _topull == _topull) exitWith {};

if (alive _topull) then {
	[_topull, 104] call ace_sys_wounds_fnc_animator2; // Can be used to unassign from vehicle
	_topull action ["eject", vehicle _topull];
	sleep 0.5;
	[_topull, 105] call ace_sys_wounds_fnc_animator;
};

false