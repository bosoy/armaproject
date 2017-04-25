/* ace_sys_wounds(.pbo)  */
#include "script_component.hpp"

// _this (c) by Xeno

private ["_topull"];
closeDialog 0;

PARAMS_1(_topull);

TRACE_1("Pulling", _topull);

if (!alive player) exitWith {};

if (!alive _topull) exitWith {
	hintSilent format [localize "STR_ACE_WOUNDS_XDIED", name _topull];
};

if (vehicle _topull == _topull) exitWith {};

if (alive _topull) then {
	[_topull, 104] call FUNC(animator2);
	_topull action ["eject", vehicle _topull];
	sleep 0.5;
	[_topull, 101] call FUNC(animator);
} else {
	// pull dead unit ??? In tests it didn't work,, moving in logics as cargo didn't help too
};

false