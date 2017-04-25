#include "script_component.hpp"
#define __wcfg configFile >> "CfgWeapons" >> _weapon
#define __acfg configFile >> "CfgAmmo" >> _ammo

if !(difficultyenabled "camerashake") exitwith {};

private ["_pwr"];
PARAMS_7(_unit,_firer,_dist,_weapon,_muzzle,_mode,_ammo);
if (_dist > 20) exitwith {};

switch (true) do {
	case (_ammo isKindOf "RocketBase"): {
		_pwr = 5/(1+sqrt _dist);
	};
	case (_ammo isKindOf "ShellBase"): {
		_pwr = 9/(1+sqrt _dist);
	};
	case (_ammo isKindOf "MissileBase"): {
		_pwr = 5/(1+sqrt _dist);
	};
	default {_pwr = 0};
};
if (_pwr < 0.001) exitwith {};

addcamshake [_pwr,0.25,23];
