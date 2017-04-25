/*
Function: ACE_fnc_RuckWeaponsList

Description:
	Returns list of lists detailing weapons in a ruck.

Parameters:
	_unit - Unit owning ruck to pack weapon into [Object]
	_last - Return saved value from before respawn. Useful for some respawn scripts. (Optional) [Boolean]

Returns:
	List of lists. Each sublist contains weapon name and count.

Example:
	(begin example)
		_WeaponsList = [BOB] call ACE_fnc_RuckWeaponsList;
		{
			hint format["Name %1, Count %2", _x select 0, _x select 1];
		} forEach _WeaponsList;

	(end)

Author:
	tcp, (c) 2010
*/


// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);
DEFAULT_PARAM(1,_last,false);
private ["_array", "_safeArray"];

_array = if (_last) then {
	_unit getVariable ["ACE_RuckWepContents_last",[]]
} else {
	_unit getVariable ["ACE_RuckWepContents",[]]
};

_safeArray = + _array;

_safeArray
