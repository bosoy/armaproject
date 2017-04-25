/* ----------------------------------------------------------------------------
Function: ACE_fnc_changeLoadout

Description:
	changes the loadout of given unit

Parameters:
	_unit - Unit [Object]
	_weapons - entry format "weapon" [Array]
	_magazines - entry format ["magazine", 5]   [Array]

Optional Parameters:
	_removeExisting - Set to false to leave existing weapons+magazines. Default: true

Returns:
	nil incase unit is null or nil (doesn't exist)
	false incase unit isn't local
	true incase success

Examples:
	(begin example)
		[player, ["M16A2", "Binocular"], [["Mine", 3], ["Handgrenade", 5]]] spawn ACE_fnc_changeLoadOut;
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_unit,_weapons,_magazines);
DEFAULT_PARAM(3,_removeExisting,true);

if (isNil "_unit") exitWith { nil };
if (isNull _unit) exitWith { nil };
if !(local _unit) exitWith { false };

// Remove existing Weapons and Magazines
if (_removeExisting) then { removeAllWeapons _unit };
// Add Weapons - TODO: Add Verification of magazine existing?
{ _unit addWeapon _x } forEach _weapons;
// Add Magazines - TODO: Add Verification of magazine existing?
{ for "_i" from 1 to (_x select 1) do { _unit addMagazine (_x select 0) } } forEach _magazines;

true;
