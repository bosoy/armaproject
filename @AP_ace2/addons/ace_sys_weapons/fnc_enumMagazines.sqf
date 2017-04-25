/* ----------------------------------------------------------------------------
Function: ACE_fnc_enumMagazines

Description:
	Enumurates the available Magazines for specified Weapon

Parameters:
	_weapon - Weapon to enumurate magazines for [Object]

Returns:
	List of Magazines [Array]

Examples:
	(begin example)
		_ar = ["M16A4"] call ace_fnc_enumMagazines;
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */

// #define DEBUG_MODE_FULL
#include "script_component.hpp"
private ["_objList", "_typeList", "_c", "_arWeaps", "_attendant"];
_objList = [];
_typeList = [];

PARAMS_1(_arWeaps);
_c = (count _arWeaps) - 1;
_attendant = getNumber(configFile >> "CfgVehicles" >> typeOf player >> "attendant") == 1;
_totalMags = [];

for "_i" from 0 to _c do {
	private ["_entry", "_cfg", "_muzzles", "_muzzle", "_magazines", "_ar", "_objDisplayName", "_weapDisplayName"];
	_entry = _arWeaps select (_c - _i); // run backwards
	_cfg = (configFile >> "CfgWeapons" >> _entry);
	_weapDisplayName = getText (_cfg >> "DisplayName");
	if (isArray(_cfg >> "muzzles")) then {
		_muzzles = getArray(_cfg >> "muzzles");
		if (count _muzzles > 0) then {
			_magazines = []; {
				if (_x == "this") then {
					_magazines = getArray (_cfg >> "magazines");
				} else {
					_magazines = _magazines + (getArray (_cfg >> _x >> "magazines"));
				};
			} forEach _muzzles;
		} else {
			_magazines = getArray (_cfg >> "magazines");
		};
	} else {
		_magazines = getArray (_cfg >> "magazines");
	};
	// make menu of _magazines for this Weapon
	_ar = []; {
		_cfg = (configFile >> "CfgMagazines" >> _x);
		if (true) then {
			if ((getNumber(_cfg >> "scope")) != 2) exitWith {};
			if (_x in _totalMags) exitWith {};
			PUSH(_totalMags,_x);
			_exit = false;
			if !(_attendant) then {
				if (_x in ["ACE_Morphine", "ACE_Splint", "ACE_IV", "ACE_Plasma", "ACE_LargeBandage"] || {configName(inheritsFrom(_cfg)) in ["ACE_Morphine", "ACE_LargeBandage"]}) then {
					_exit = true;
				};
			};
			if (_exit) exitWith {};
			if (getNumber(_cfg >> "Armory" >> "disabled") == 1) exitWith {};
			if (getNumber(_cfg >> "ace_hide") == 1) exitWith {}; // Should be deprecated, use Armory->disabled instead

			_objDisplayName = getText (_cfg >> "DisplayName");
			if (_objDisplayName != "") then {
				_mag = [_x, _objDisplayName];
				PUSH(_ar,_mag);
			};
		};
	} forEach _magazines;
	TRACE_2("",_weapDisplayName,_magazines);
	PUSH(_objList,_ar);
	PUSH(_typeList,_weapDisplayName);
};

// Return magazines
[_objList, _typeList];
