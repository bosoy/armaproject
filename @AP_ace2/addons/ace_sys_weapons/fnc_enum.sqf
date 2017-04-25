/* ----------------------------------------------------------------------------
Function: ACE_fnc_enum

Description:
	Enumurates the available weapons and magazines for specified unit

Parameters:
	_unit - Unit or Vehicle to check [Object]

Returns:
	List of weapons [Array]

Examples:
	(begin example)
		_ar = [player] call ace_fnc_enum;
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */
#include "script_component.hpp"
PARAMS_1(_unit);

//private ["_side", "_types", "_ranges", "_type", "_range"];
private ["_side", "_types", "_type"];

_side = toUpper(faction _unit);
switch (_side) do {
	case "ACE_USAF": { _side = "USMC" };
	case "ACE_USNAVY": { _side = "USMC"; };
	case "ACE_USMC_DESERT": { _side = "USMC"; };
	case "ACE_USARMY": { _side = "BIS_US"; };
	case "ACE_USARMY_DESERT": { _side = "BIS_US"; };
	case "ACE_160SOAR": { _side = "BIS_US"; };
	//case "BIS_CZ": { _side = "BIS_US"; };
	case "BIS_UN": { _side = "CDF"; };
	case "ACE_GRU": { _side = "RU"; };
	case "ACE_VDV": { _side = "RU"; };
	case "ACE_MVD": { _side = "RU"; };
	case "ACE_RU_DESERT": { _side = "RU"; };
	case "BIS_TK_INS": { _side = "INS"; };
	case "BIS_TK_GUE": { _side = "GUE"; };
	case "CIV_RU": { _side = "CIV"; };
	case "BIS_TK_CIV": { _side = "CIV"; };
	case "BIS_CIV_SPECIAL": { _side = "CIV"; };
};
_types = ["RIFLE", "PISTOL", "EQUIP", "ITEM", "RUCK", "LAUNCHER"]; //, "SNIPER", "MG", "AR"];
_weapons = getArray(configFile >> "CfgVehicles" >> typeOf _unit >> "weapons"); {
	_type = [_x] call FUNC(determineType);
	if !(_type in _types) then { PUSH(_types,_type) };
} forEach _weapons;

if (GVAR(test)) exitWith {
	["", ["RIFLE", "PISTOL", "EQUIP", "ITEM", "RUCK", "LAUNCHER", "SNIPER", "MG", "AR"], "noarmorycheck"] call ace_fnc_enumWeapons;
};

private ["_menu", "_ar", "_arList", "_arTypes", "_c", "_items"];
if (GVAR(lock) select 0) then {
	_v = _unit getVariable QGVAR(range);
	if (isNil "_v") then {
		private ["_weap"];
		_weap = currentWeapon _unit;
		_range = if (_weap != "" && {!(_weap in ["Throw", "Put"])}) then { _weap call FUNC(determineZoom) } else { ["SHORT"] };
		if ("MEDIUM" in _range) then { _range = ["SHORT", "MEDIUM"] };
		if ("LONG" in _range) then { _range = ["SHORT", "MEDIUM", "LONG"] };
		_unit setVariable [QGVAR(range), _range];
	};
	_ar = [_side, _types, _unit getVariable QGVAR(range)] call ace_fnc_enumWeapons;
} else {
	_ar = [_side, _types] call ace_fnc_enumWeapons;
};

_ar;
