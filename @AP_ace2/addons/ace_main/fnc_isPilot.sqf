/* ----------------------------------------------------------------------------
Function: ACE_fnc_isPilot

Description:
	Returns if unit is a pilot unit

Parameters:
	_object - Object

Returns:


Examples:
	(begin example)
		[_unit] call ACE_fnc_isPilot
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);
private "_ret";

_ret = _unit getVariable "ace_is_pilot";
if (isNil "_ret") then {
	_ret = (getNumber(configFile >> "CfgVehicles" >> typeOf _unit >> "ace_isPilot") == 1);
};

_ret
