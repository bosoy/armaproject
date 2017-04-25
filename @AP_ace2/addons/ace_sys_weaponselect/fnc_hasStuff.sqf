// check if player has stuff for throw or put wpns, return bool and first muzzle that has mags for it

#include "script_component.hpp"
#define __cfg (configFile >> "CfgWeapons" >> _this)

private ["_hasStuff","_mags","_muzzles","_curmuzzle","_mzmags"];
_hasStuff = false;
_muzzles = getArray (__cfg>>"muzzles");
_mags = magazines player;
{
	scopeName "muzzlecheck";
	_curmuzzle = _x;
	_mzmags = getArray(__cfg>>_curmuzzle>>"magazines");
	{
		if (_x in _mzmags) exitwith { _hasStuff = true; breakOut "muzzlecheck"};

	} foreach _mags;

} foreach _muzzles;


[_hasStuff,_curmuzzle]