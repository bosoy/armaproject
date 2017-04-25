/*
Function: ACE_fnc_HasRuck

Description:
	Determine if a unit has a ruck.

Parameters:
	_unit - Unit to check for a ruck [Object]

Returns:
	"true" if has ruck or "false" if not [Boolean]

Example:
	(begin example)
		_armyMule = [BOB] call ACE_fnc_HasRuck;
	(end)

Author:
	tcp, (c) 2009,2010
*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);

private ["_hasRuck","_weapon_on_back"];

_hasRuck = false;

if ( [_unit] call FUNC(RuckBusy) ) exitWith { TRACE_1("Aborting, RuckBusy", _unit); _hasRuck };

// Check if on back.
_weapon_on_back = _unit getVariable ["ACE_weapononback",""];
if ( _weapon_on_back != "" && {isClass (__CONF_WEAPONS >> _weapon_on_back)} ) then {
	if ( isNumber(__CONF_WEAPONS >> _weapon_on_back >> "ACE_PackSize") ) then {
		_hasRuck = true;
	};
};

if (!_hasRuck) then {
	// fixed for units getting both ruck and launcher in cfgVehicles
	{ // if a pack is found but it's not the secondary weapon, it is moved to back
		if ( isNumber(__CONF_WEAPONS >> _x >> "ACE_PackSize") ) exitWith {
			if (_x != secondaryWeapon _unit) then {
				[_unit, _x] call ACE_fnc_PutWeaponOnBack;
			};
			_hasRuck = true;
		};
	} forEach weapons _unit;
};

_hasRuck
