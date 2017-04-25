/* ----------------------------------------------------------------------------
Function: ACE_fnc_isBurning

Description:
	Returns if vehicle/unit is burning

Parameters:
	_object - Object

Returns:


Examples:
	(begin example)
		[_unit] call ACE_fnc_isBurning
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

// TODO: Other methods of detecting burning.
private ["_burning"];
PARAMS_1(_v);
if (isNull _v) exitWith { false };

_burning = false;
if (_v isKindOf "Default") then {
	// Ammo
	_burning = getNumber(configFile >> "CfgAmmo" >> typeOf _v >> "ace_fire") == 1; // Always burning
} else {
	// Vehicles

	// Fire places etc
	if (inFlamed _v) exitWith { true };

	// Scripted burning
	_burning = _v getVariable ["ace_is_burning", false];
	// _burning = _v getVariable ["ace_onfire", false]; // Don't need to use, either the vehicle is on fire, or there's an object spawned which is on fire.
	if !(_burning) then {
		// Always burning
		_burning = getNumber(configFile >> "CfgVehicles" >> typeOf _v >> "ace_fire") == 1;
	};
};

TRACE_1("Return",_burning);
_burning;
