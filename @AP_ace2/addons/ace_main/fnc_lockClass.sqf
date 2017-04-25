/* ----------------------------------------------------------------------------
Function: ACE_fnc_lockClass

Description:
	Adds disability to units who uses weapon not for his faction/role

Parameters:
	_unit - Object
	Optional parameter: _types - Array of Strings

Returns:


Examples:
	(begin example)
		[_unit] call ACE_fnc_lockClass
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */

// #define DEBUG_MODE_FULL
#include "script_component.hpp"

#define DEFAULT_TYPES "RIFLE", "PISTOL", "EQUIP", "ITEM", "RUCK" //, "LAUNCHER" //, "SNIPER", "MG", "AR"

PARAMS_1(_unit);

_fnc = {
	_types = [DEFAULT_TYPES];
	_weapons = getArray(configFile >> "CfgVehicles" >> typeOf _unit >> "weapons"); {
		_type = [_x] call ace_sys_weapons_fnc_determineType;
		if !(_type in _types) then { PUSH(_types,_type) };
	} forEach _weapons;
	_types;
};

DEFAULT_PARAM(1,_types,call _fnc);

_weapons = weapons _unit;
_unit setVariable [QGVAR(types), _types];
_unit setVariable [QGVAR(default_weapons), _weapons];

if !(local _unit) exitWith {};

[_unit] spawn {
	PARAMS_1(_unit);
	_defaultWeapons = _unit getVariable QGVAR(default_weapons);
	_defaultTypes = _unit getVariable QGVAR(types);

	while {true} do {
		// get current weapon(s)
		// TODO: Handle vehicles??
		waitUntil {vehicle _unit == _unit};

		_weapon = currentWeapon _unit;
		if (_weapon != "") then {
			_disability = 0;
			// TODO: Lower effect over time
			// TODO: Allow external modification of level of disability coef..
			// if weapon is not in the list of default weapons, apply x disability
			if !(_weapon in _defaultWeapons) then {
				ADD(_disability,0.1);
				_weaponType = [_weapon] call ace_sys_weapons_fnc_determineType;
				// if weapon type is not in the list of default weapon types, apply y disability
				if !(_weaponType in _defaultTypes) then {
					ADD(_disability,0.3);
				};

				// TODO: Take Weapon Weight difference into account?

				// if weapon is not of the same faction, apply z disability
				if !((faction _unit) in ([_weapon] call ace_sys_weapons_fnc_determineFactions)) then {
					ADD(_disability,0.3);
				};
			};

			// Apply disability
			if (_disability > 0) then {
				// TODO; perhaps by reading and adding+writing hand-damage, any other?
				// Add dispersion? sys_overheating/dispersion/sight_adjustment
				// Add recoil?
				// Add camshake/wobbling?
			};
		} else {
			// Reset Effects?
		};
		sleep 1;
	};
};
