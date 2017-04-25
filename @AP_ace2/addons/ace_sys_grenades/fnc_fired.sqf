//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __CFG (configFile >> "CfgAmmo" >> _ammo >> "ACE_GRENADE_TYPE")

private ["_ammo","_grenadeType","_object"];

PARAMS_3(_unit,_weapon,_muzzle);

_ammo = _this select 4;
_object = _this select 6; // uses BIS Fired EH

_grenadeType = "NONE";
if (isText __CFG) then {
	_grenadeType = getText __CFG;
};

if (_grenadeType == "NONE") exitwith {};

// RIFLE GRENADES              // Pass unit to determine distance
[_object, _grenadeType, _ammo, _unit] call FUNC(dummy);
