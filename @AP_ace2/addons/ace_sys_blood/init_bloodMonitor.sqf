/*
	BloodMonitor:
	Monitors units array and spurts out some blood out of bleeding units, every x seconds.
	This is not synchronized. This is a performance choice. Too many bleeding units could cause too much Network traffic.
	Where as Spurt (hit) events are less frequent.

	TODO: Evaluate usage of allUnits, and setVariable (public) for bleeding? Altough; would defeat purpose of globalHit eh ;)
*/
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

LOG("BloodMonitor activated!");

_cond = if (isNil "ace_sys_wounds_enabled") then {
	{alive _x && {getDammage _x > 0.3}}
} else {
	{alive _x && {_x getVariable ["ace_w_bleed", 0] > 0}}
};

private ["_del", "_pos"];
while {true} do {
	waitUntil {sleep 0.226;count GVAR(units) > 0};
	_del = [];
	// TODO: Consider performance implications
	{
		//if (alive _x && {(getDammage _x > 0.3 || {_x getVariable ["ace_w_bleed", 0] > 0})}) then { // TODO: ace_w_bleed doesn't work in MP until the unit is examined - perhaps at least broadcast start and end state?
		if (call _cond) then {
		//if (_x != vehicle _x) exitWith {}; // only bleed when not inside vehicle
			TRACE_1("Unit is bleeding - spawning blood","");
			// TODO: Amount of blood depending on damage
			_pos = getPosATL _x;
			_pos set [2, 0];
			["ACE_Blooddrop_2", _pos, getDir _x] call FUNC(spawnBlood);
		} else {
			TRACE_1("Unit is not bleeding - Resetting","");
			PUSH(_del,_x);
			_x setVariable [QGVAR(bleeding), nil];
		};
	} forEach GVAR(units);
	SUB(GVAR(units),_del);
	sleep 8;
};
