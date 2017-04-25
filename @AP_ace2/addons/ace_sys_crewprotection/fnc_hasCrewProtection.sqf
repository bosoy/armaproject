/* ----------------------------------------------------------------------------
Function: ACE_fnc_hasCrewProtection

Description:
	Find out if given unit has crew protection

Parameters:
	_unit - Object [Object]

Returns:
	True if unit has crew protection [Boolean]

Examples:
	(begin example)
		_ar = [_someSoldier] call ace_fnc_hasCrewProtection;
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */
#define CFG configFile >> "CfgVehicles" >> (typeOf _unit) >> "ACE_CrewProtection"
#include "script_component.hpp"
PARAMS_1(_unit);

(getNumber(CFG) == 1 || {(_unit getVariable ["ACE_CrewProtection",0]) == 1})
