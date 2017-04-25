/*
Function: ACE_fnc_RuckMagazinesList

Description:
	Returns list of lists detailing magazines in a ruck.

Parameters:
	_unit - Unit owning ruck to pack magazine into [Object]
	_last - Return saved value from before respawn. Useful for some respawn scripts. (Optional) [Boolean]

Returns:
	List of lists. Each sublist contains magazine name and count.

Example:
	(begin example)
		_MagazinesList = [BOB] call ACE_fnc_RuckMagazinesList;
		{
			hint format["Name %1, Count %2, Ammo count per magazine: %3", _x select 0, _x select 1, _x select 2];
		} forEach _MagazinesList;
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
	_unit getVariable ["ACE_RuckMagContents_last",[]]
} else {
	_unit getVariable ["ACE_RuckMagContents",[]]
};

_safeArray = + _array;

_safeArray
