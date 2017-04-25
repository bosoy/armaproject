// return the list of muzzles for weapon that have mags for them

#include "script_component.hpp"
#define __cfg (configFile >> "CfgWeapons" >> _this)

private ["_mags","_muzzles","_nonemptymuzzles","_mzmags","_curmuzzle"];
_muzzles = getArray (__cfg>>"muzzles");
_mags = magazines player;
_nonemptymuzzles = [];
{
	_curmuzzle = _x;
	_mzmags = getArray(__cfg>>_curmuzzle>>"magazines");
	{
		if (_x in _mzmags) exitwith { if !(_curmuzzle in _nonemptymuzzles) then {_nonemptymuzzles set[count _nonemptymuzzles,_curmuzzle]}};

	} foreach _mags;

} foreach _muzzles;
_nonemptymuzzles