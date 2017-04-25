#include "script_component.hpp"

private ["_array", "_dragee", "_vec", "_unit"];

_array = _this select 3;
_dragee = _array select 0;
_vec = _array select 1;

_unit = player;

GVAR(drag) = false;

if (GVAR(dropAction) != -3333) then {player removeAction GVAR(dropAction);GVAR(dropAction) = -3333};

detach _unit;
detach _dragee;

if (alive _dragee) then {
	hintSilent format [localize "STR_ACE_WOUNDS_XLOAD", name _dragee];
} else {
	hintSilent (localize "STR_ACE_WOUNDS_BODYLOAD");
};

if ((alive _dragee && {(_dragee call FUNC(isUncon))}) || {!alive _dragee}) then {
	[_dragee, 101] call FUNC(animator);
} else {
	[_dragee, 102] call FUNC(animator);
};
[QGVAR(aswmnon), _unit] call CBA_fnc_globalEvent;
_dragee setVariable ["ace_w_carry", objNull, true];

sleep 3;

[_dragee, 103, _vec] call FUNC(animator);
_dragee assignAsCargo _vec;
