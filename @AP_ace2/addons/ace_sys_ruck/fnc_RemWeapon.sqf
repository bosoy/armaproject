/*
Function: ACE_fnc_RemWeapon

Description:
	Remove from Weapon on Back Slot first, in addition to regular slots, when removing a weapon.

Parameters:
	_unit - Unit owning the weapon. [Object]
	_wep - Weapon class to remove [String]
Returns:
	BOOL - Successfully removed or not

Example:
	(begin example)
		[player, "ACE_ParachutePack"] call ACE_fnc_RemWeapon;
	(end)

Author:
	tcp
*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_unit,_wep);

_return = false;

_removed = [_unit, "WOB", _wep] call ACE_fnc_RemoveGear;

if ( _removed ) then {
	_return = true;
} else {
	if ( _unit hasWeapon _wep ) then {
		_unit removeWeapon _wep;
		_return = true;
	} else {
		_return = false;
	};
};

_return;