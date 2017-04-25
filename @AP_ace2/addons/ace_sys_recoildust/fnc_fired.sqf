#include "script_component.hpp"

private["_ammo"];

if (rain > 0.6) exitWith { false };
if (fog > 0.75) exitWith { false };

#define __weaponsType getNumber(configFile >> "CfgWeapons" >> _weapon >> "type")
#define __ammoStrength getNumber(configFile >> "CfgAmmo" >> _ammo >> "hit")
#define __house [_unit] call ACE_fnc_inBuilding

PARAMS_2(_unit,_weapon);
_ammo = _this select 4;

if (player distance _unit > 1500) exitWith { false };
if !(__weaponsType in [1, 4, 5]) exitWith { false };
if (__ammoStrength < 15)exitWith { false };

if (__house) then {
	[_unit,_ammo,__ammoStrength] execFSM "\x\ace\addons\sys_recoildust\recoildust.fsm";
};

false
