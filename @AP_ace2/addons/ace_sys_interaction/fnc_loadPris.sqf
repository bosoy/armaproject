#include "script_component.hpp"

private ["_array", "_dragee", "_vec", "_unit"];

_array = _this select 3;
_dragee = _array select 0;
_vec = _array select 1;

_unit = player;

if (alive _dragee) then {
	hintSilent format [localize "STR_ACE_WOUNDS_XLOAD", name _dragee];
} else {
	hintSilent (localize "STR_ACE_WOUNDS_BODYLOAD");
};

[_dragee, 102] call ace_sys_wounds_fnc_animator;
["ace_sys_wounds_aswmnon", _unit] call CBA_fnc_globalEvent;
[QGVAR(loadhint), [_dragee, player, _vec]] call CBA_fnc_globalEvent;

sleep 3;

[_dragee, 103, _vec] call ace_sys_wounds_fnc_animator;
_dragee assignAsCargo _vec;
