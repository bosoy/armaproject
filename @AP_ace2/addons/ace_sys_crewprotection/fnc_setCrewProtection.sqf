/* ----------------------------------------------------------------------------
Function: ACE_fnc_setCrewProtection

Description:
	Set unit crew protection

Parameters:
	_unit - Object [Object]
	_state - [Boolean] or [Array]

Returns:


Examples:
	(begin example)
		[_someSoldier, true] call ace_fnc_setCrewProtection;
		[_someSoldier, ["g-effects", true]] call ace_fnc_setCrewProtection;
		[_someSoldier, ["combatdeaf", true]] call ace_fnc_setCrewProtection;
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */
#include "script_component.hpp"
PARAMS_2(_unit,_enable);

if (typeName _enable == "BOOL") then {
	_unit setVariable ["ACE_CrewProtection", if (_enable) then {1} else {0}];
} else {
	if (typeName _enable != "ARRAY") exitWith {
		WARNING("Second parameter in ACE_fnc_setCrewProtection is no array");
	};
	if (count _enable < 2) exitWith {
		WARNING("Not ebough array elements in second parameter in ACE_fnc_setCrewProtection");
	};
	#define __VALS ["g-effects","combatdeaf"]
	if !(toLower (_enable select 0) in __VALS) exitWith {
		WARNING("Wrong crew protection selection");
	};
	_unit setVariable [("ACE_CrewProtection_" + (_enable select 0)), _enable select 1];
};

nil
