/*
Function: ACE_fnc_HasWeapon

Description:
	Check Weapon on Back Slot in addition to regular slots when checking for presence of a weapon.

Parameters:
	_unit - Unit owning the weapon. [Object]
	_wep - Weapon class to remove [String]
Returns:
	BOOL - Successfully found or not

Example:
	(begin example)
		[player, "ACE_ParachutePack"] call ACE_fnc_HasWeapon;
	(end)

Author:
	tcp
*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_unit,_wep);

_return = if ( _wep == ([_unit] call ACE_fnc_WeaponOnBackName) ) then {
	true
} else {
	_unit hasWeapon _wep
};

_return;