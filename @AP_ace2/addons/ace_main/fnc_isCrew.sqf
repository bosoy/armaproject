/* ----------------------------------------------------------------------------
Function: ACE_fnc_isCrew

Description:
	Returns if unit is a crew unit

Parameters:
	_object - Object

Returns:


Examples:
	(begin example)
		[_unit] call ACE_fnc_isCrew
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_bool"];
PARAMS_1(_unit);

_bool = _unit getVariable "ace_is_crew";
if (isNil "_bool") then {
	_bool = (getNumber(configFile >> "CfgVehicles" >> typeOf _unit >> "ace_isCrew") == 1);
};

_bool
