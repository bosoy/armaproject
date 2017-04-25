/* ----------------------------------------------------------------------------
Function: ACE_fnc_weaponFeature

Description:
	Function to retrieve a muzzle feature

Parameters:
	- [weapon class string, magazine string, feature string]

Returns:
		boolean

Examples:
	(begin example)
		[currentWeapon, currentMagazine, "ace_enable_reflex"] call ACE_fnc_WeaponFeature
	(end)

Author:
	(c) zGuba 2010
---------------------------------------------------------------------------- */
private["_wc","_mc","_wf","_wmagazines","_mmagazines","_mcount","_f"];
_wc = _this select 0;
_mc = toUpper (_this select 1);	// Case sensitive
_wf = _this select 2;

#define __wfeature getNumber (configFile >> "CfgWeapons" >> _wc >> _wf)
#define __wmagazines getArray (configFile >> "CfgWeapons" >> _wc >> "magazines")
#define __m (getArray (configFile >> "CfgWeapons" >> _wc >> "muzzles")) - ["this"]
#define __mfeature getNumber (configFile >> "CfgWeapons" >> _wc >> _x >> _wf)
#define __mmagazines getArray (configFile >> "CfgWeapons" >> _wc >> _x >> _magazines)

// Main class check
_wmagazines = __wmagazines;
_mcount = (count _wmagazines) - 1;
if (_mcount > -1) then {
	for "_mcur" from 0 to _mcount do {
		_wmagazines set [_mcur,toUpper (_wmagazines select _mcur)];
	};
};
if (_mc in _wmagazines) then {
	_f = (0 max __wfeature) min 1;
}
else {
	_f = 0;
};

{ // Muzzle check
	_mmagazines = __mmagazines;
	_mcount = (count _mmagazines) - 1;
	if (_mcount > -1) then {
		for "_mcur" from 0 to _mcount do {
			_mmagazines set [_mcur,toUpper (_mmagazines select _mcur)];
		};
	};
	if (_mc in _mmagazines) then {
		_f = _f + ((0 max __mfeature) min 1);
	};
} forEach __m;

(_f == 1)
