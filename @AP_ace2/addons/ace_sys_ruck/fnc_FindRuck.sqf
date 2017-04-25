/*
Function: ACE_fnc_FindRuck

Description:
	Return name of ruck.

Parameters:
	_unit - Unit to search for a ruck [Object]

Returns:
	Ruck classname if unit has a ruck, "" if not [String]

Example:
	(begin example)
		_ruckName = [BOB] call ACE_fnc_FindRuck;
	(end)

Author:
	tcp (c) 2009, 2010
*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);

private ["_ruck","_weapon_on_back"];

// Check secondary weapon slot, then if on back.
_weapon_on_back = _unit getVariable ["ACE_weapononback",""];
_ruckBak = getNumber(__CONF_WEAPONS >> _weapon_on_back >> "ACE_PackSize");
_ruckSec = getNumber(__CONF_WEAPONS >> secondaryWeapon _unit >> "ACE_PackSize");

_ruck = switch (true) do {
	case (_ruckBak > _ruckSec): {_weapon_on_back};
	case (_ruckSec > 0): {secondaryWeapon _unit};
	default {""};
};

_ruck