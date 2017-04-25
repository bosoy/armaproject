/*
Function: ACE_fnc_PutWeaponOnBack

Description:
	Move a weapon into the 'On Back' slot, performing checks to see if it fits.
	The weapon must already be in that unit's weapon inventory.

Parameters:
	_unit - Unit owning the weapon. [Object]
	_weapon - Class name of weapon to move into the "On Back" slot. [String]

Returns:
	"true" if weapon was successfully moved or "false" if not. [Boolean]

Example:
	(begin example)
		player addWeapon "SVD_CAMO";
		_success = [player, "SVD_CAMO"] call ACE_fnc_PutWeaponOnBack;
	(end)

Author:
	tcp, (c) 2010
*/


//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_unit,_weapon);

private ["_packable","_currentWOB"];

_packable = _weapon in (weapons _unit);
 
if ( _weapon == "" ) then {
	TRACE_1("Empty weapon", _unit);
	_packable = false;
};

if ( ! isNumber(__CONF_WEAPONS >> _weapon >> "type") ) then {
	TRACE_1("Bad type", _weapon);
	_packable = false;
};

_currentWOB = _unit getVariable ["ACE_weapononback", ""];

if ( _currentWOB != "" ) then {
	TRACE_1("Slot full", _currentWOB);
	_packable = false;
};

if ( _packable ) then {
	TRACE_3("Moving to WOB...", _unit, _weapon);
	_unit setVariable ["ACE_weapononback", _weapon, true];
	_unit removeWeapon _weapon;
};

_packable
