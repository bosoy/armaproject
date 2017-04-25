/* ----------------------------------------------------------------------------
Function: ACE_fnc_removemagazinecargo

Description:
	Function to remove a magazine from a vehicles cargo.

Parameters:
	- Vehicle from where to remove [Object]
	- Magazine to remove [String]
	- Amount of stuff to remove [Number]
	
Returns:
		nothing

Examples:
	(begin example)
		[myTruck, "M16_Mag", 10] call ACE_fnc_removemagazinecargo
	(end)

Author:
	(c) Rocko, Nou 2011
---------------------------------------------------------------------------- */
// fnc_removemagazinecargo.sqf

#include "script_component.hpp"

PARAMS_3(_vehicle,_magazine,_count);
if (isNil "_count") then { _count = 1; };
_currentMagazines = getMagazineCargo _vehicle;
clearMagazineCargoGlobal _vehicle;
{
	_currentcount = (_currentMagazines select 1) select _forEachIndex;
	if (_x == _magazine) then {
		_currentcount = _currentcount - _count;
	};
	if (_currentcount > 0) then {
		_vehicle addMagazineCargoGlobal [_x, _currentcount];
	};
} forEach (_currentMagazines select 0);
