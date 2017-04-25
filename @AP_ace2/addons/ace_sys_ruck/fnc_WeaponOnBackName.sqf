/*
Function: ACE_fnc_WeaponOnBackName

Description:
	Returns class name of weapon in Weapon On Back slot.

Parameters:
	_unit - Unit [Object]
	_last - Return saved value from before respawn. Useful for some respawn scripts. (Optional) [Boolean]

Returns:
	String

Example:
	(begin example)
		_WOB = [BOB] call ACE_fnc_WeaponOnBackName;

	(end)

Author:
	tcp
*/


//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);
DEFAULT_PARAM(1,_last,false);

if (_last) then {
	_unit getVariable ["ACE_weapononback_last",""];
} else {
	_unit getVariable ["ACE_weapononback",""];
};