#include "script_component.hpp"

//	This script is called on init. It checks unit's magazine space and when needed
//	changes the mags to the ones compatible with the unit's weapon. Thus there's no need to specify
//	magazines specific to this particular weapon in the soldier's config, as everything is done automatically.

PARAMS_1(_unit);

private ["_lastWeap", "_lastMuzzle", "_cfg", "_weapMags", "_unitMags", "_muzzles"];

_lastWeap = secondaryWeapon _unit;
if (!(local _unit) || {_lastWeap == ""}) exitWith {};
_cfg = (configFile >> "CfgWeapons" >> _lastWeap);
_weapMags = getArray (_cfg >> "magazines");
_lastMuzzle = _lastWeap;
_muzzles = getArray (_cfg >> "muzzles");
if ("this" != (_muzzles select 0)) then {
	_lastMuzzle = _muzzles select 0;
	if (_lastMuzzle != "this") then { _cfg = (_cfg >> _lastMuzzle) };
	_weapMags = getArray (_cfg >> "magazines");
};

_unitMags = magazines _unit;
{
	[_unit,_lastWeap,_weapMags,_x] call compile preprocessFileLineNumbers "\x\ace\addons\sys_modelspecial\fnc_MagReplace.sqf";
} forEach _unitMags;
