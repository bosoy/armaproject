/*
 DROP BODY SCRIPT

 Allows players to drop unconscious bodies

 JUNE 2009 - norrin
*****************************************************************************************************************************
Start drop_body.sqf
*/

#include "script_component.hpp"
private ["_data", "_dragee", "_unit", "_switchm"];

_data = _this select 3;
_dragee	= _data select 0;
_switchm = _data select 1;
_disabledonly = if (count _data > 2) then {_data select 2} else {false};

if (GVAR(dropAction) != -3333) then {
	player removeAction GVAR(dropAction);
	GVAR(dropAction) = -3333;
};
if (GVAR(carryAction) != -3333) then {
	player removeAction GVAR(carryAction);
	GVAR(carryAction) = -3333;
};
GVAR(drag) = false;
GVAR(carry) = false;
_unit = player;

detach _unit;
detach _dragee;
_unit setVariable [QGVAR(is_carrying),false];
_dragee setVariable ["ace_w_carry", objNull, true];
if (_disabledOnly && {!(_dragee call FUNC(isUncon))}) then {
	[_dragee, 105] call FUNC(animator);
} else {
	if (alive _dragee && {!(_dragee call FUNC(isUncon))}) then {
		[_dragee, 102] call FUNC(animator);
	} else {
		[_dragee, 101] call FUNC(animator);
	};
};
if (_switchm == 0) then {
	[QGVAR(aswmnon), _unit] call CBA_fnc_globalEvent;
};
// Reset Stamina Boost while carrying wounded
[_unit, 0] call ace_sys_stamina_fnc_inc_mass;
