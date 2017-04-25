/* ----------------------------------------------------------------------------
Function: ACE_fnc_removeweaponcargo

Description:
	Function to remove a weapon from a vehicles cargo.

Parameters:
	- Vehicle from where to remove [Object]
	- Weapon to remove [String]
	- Amount of stuff to remove [Number]
	
Returns:
		nothing

Examples:
	(begin example)
		[myTruck, "M15", 10] call ACE_fnc_removeweaponcargo
	(end)

Author:
	(c) Rocko, Nou 2011
---------------------------------------------------------------------------- */
// fnc_removeweaponcargo.sqf

#include "script_component.hpp"

PARAMS_3(_vehicle,_weapon,_count);
if (isNil "_count") then { _count = 1; };
_currentWeapons = getWeaponCargo _vehicle;
clearWeaponCargoGlobal _vehicle;
{
	_currentcount = (_currentWeapons select 1) select _forEachIndex;
	if (_x == _weapon) then {
		_currentcount = _currentcount - _count;
	};
	if (_currentcount > 0) then {
		_vehicle addWeaponCargoGlobal [_x, _currentcount];
	};
} forEach (_currentWeapons select 0);
