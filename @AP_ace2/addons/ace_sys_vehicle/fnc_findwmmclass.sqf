#include "script_component.hpp"

// (c) 2011 by zGuba
// Determines path to mode / muzzle config based on fired EH.
// Syntax: _firedEH_array call acse_sys_fnc_selectclass
// Output: config class

private [
	"_muzzleClass","_modeClass",
	"_class"
];

PARAMS_4(_vehicle,_weapon,_muzzle,_mode);

if (isClass (configFile >> "CfgWeapons" >> _weapon >> _muzzle)) then {
	_muzzleClass = configFile >> "CfgWeapons" >> _weapon >> _muzzle;
	_modeClass = configFile >> "CfgWeapons" >> _weapon >> _muzzle >> _mode;
} else {
	_muzzleClass = configFile >> "CfgWeapons" >> _muzzle;
	_modeClass = configFile >> "CfgWeapons" >> _muzzle >> _mode;
};

if (_mode == _muzzle) then {
	_class = _muzzleClass;
} else {
	_class = _modeClass;
};

_class
