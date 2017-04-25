#include "script_component.hpp"
#define __cfg (configFile >> "CfgWeapons" >> _wpn)

private ["_class","_hasGL","_wpn","_muzzles"];
_hasGL = false;
_wpn = currentWeapon _this;
if (_wpn != primaryWeapon _this) exitwith { false };
_muzzles = getArray (__cfg >> "muzzles");
if (_wpn in ["M32_EP1","M79_EP1","Mk13_EP1","ACE_M32","ACE_MK13","ACE_M79"]) then {_hasGL = true};
{
	scopeName "muzzlecheck";
	_class = inheritsFrom (__cfg >> _x);
	while { isClass _class } do {
		if (configName (_class) == "GrenadeLauncher") exitwith { _hasGL = true; breakOut "muzzlecheck" };
		_class = inheritsFrom (_class);
	};
} foreach _muzzles;

_hasGL