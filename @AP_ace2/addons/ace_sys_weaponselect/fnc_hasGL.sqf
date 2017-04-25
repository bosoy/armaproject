#include "script_component.hpp"
#define __cfg (configFile >> "CfgWeapons" >> _wpn)

private ["_class","_hasGL","_wpn","_muzzles","_curmuzzle"];
_hasGL = false;
_wpn = _this;

_muzzles = getArray (__cfg >> "muzzles");
{
	scopeName "muzzlecheck";
	_curmuzzle = _x;
	_class = inheritsFrom (__cfg >> _x);
	while { isClass _class } do {
		if (configName (_class) == "GrenadeLauncher") exitwith { _hasGL = true; breakOut "muzzlecheck" };
		_class = inheritsFrom (_class);
	};
} foreach _muzzles;

[_hasGL,_curmuzzle]