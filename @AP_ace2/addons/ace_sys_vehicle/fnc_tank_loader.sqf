#include "script_component.hpp"

#define __LOADER_EXIT_CODE {if (_vehicle ammo _x > 0) then {_vehicle setWeaponReloadingTime [_gunner,_x,1]}} forEach _muzzles

// (c) 2012 by zGuba
// Loader speeding up process of reload

PARAMS_4(_vehicle,_weapon,_muzzle,_mode);

private ["_gunnerInfo","_gunner","_loader","_vehicleClass","_weaponClass","_loaderPath","_loaderSpeedup","_muzzles"];

_gunnerInfo = [_vehicle, _weapon] call CBA_fnc_getFirer;
_gunner = _gunnerInfo select 0;

if !(local _gunner) exitWith {};

// Weapon class
_weaponClass = configFile >> "CfgWeapons" >> _weapon;

// Muzzles
_muzzles = getArray (_weaponClass >> "muzzles");
_muzzles set [count _muzzles,_weapon];

// Reload time speed divisor
_loaderSpeedup = getNumber (_weaponClass >> "ace_loader_speedup");
if (_loaderSpeedup <= 0) exitWith {};

// Vehicle class
_vehicleClass = configFile >> "CfgVehicles" >> typeOf _vehicle;

// Loader position
_loaderPath = getArray (_vehicleClass >> "ace_loader_path");

// Active loader
_loader = _vehicle turretUnit _loaderPath;
if (isNull _loader) exitWith {__LOADER_EXIT_CODE};
if !(alive _loader) exitWith {__LOADER_EXIT_CODE};
if (_loader call ace_sys_wounds_fnc_isUncon) exitWith {__LOADER_EXIT_CODE};
if ([_loader] call ACE_fnc_isTurnedOut) exitWith {__LOADER_EXIT_CODE};

{if (_vehicle ammo _x > 0) then {_vehicle setWeaponReloadingTime [_gunner, _x, 1/_loaderSpeedup]}} forEach _muzzles;
