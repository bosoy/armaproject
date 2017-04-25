/* ACE2 Module: Exchangeable Armament System for Aircrafts (EASA) */
// (c) 2009 by rocko
//
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

// Loading ammo for the cannon

// Get Config Cannon
PARAMS_1(_veh);

private["_weapons","_magazines"];
if (isClass(configFile >> "CfgVehicles" >> (typeOf _veh) >> "Turrets" >> "MainTurret")) then {
	_weapons = (getArray(configFile >> "CfgVehicles" >> (typeOf _veh) >> "Turrets" >> "MainTurret" >> "weapons"));
	_magazines = (getArray(configFile >> "CfgVehicles" >> (typeOf _veh) >> "Turrets" >> "MainTurret" >> "magazines"));
} else {
	_weapons = (getArray(configFile >> "CfgVehicles" >> (typeOf _veh) >> "weapons"));
	_magazines = (getArray(configFile >> "CfgVehicles" >> (typeOf _veh) >> "magazines"));
};

// Get Config Magazines
if ((getText(configFile >> "CfgMagazines" >> _item_mag >> "ammo") isKindOf "BulletBase")) then {
	_magazines_index set [(count _magazines_index),  _x];
	TRACE_1("Found Cannon magazine to keep",_item_mag);
};

private["_weapons_index"];
_weapons_index = [];
for "_xx" from 0 to (count _weapons) - 1 do {
	_item_wep = (_weapons select _xx);
	_item_wep_mag = getArray(configFile >> "CfgWeapons" >> (_weapons select _xx) >> "magazines");
	_matches = [_item_wep_mag, {_x in _magazines}] call BIS_fnc_conditionalSelect;
	if (count _matches == 0) then {
		_weapons_index set [(count _weapons_index), _xx];
	} else { TRACE_1("Weapon for this magazine is to remove",_matches); };
};
_weapons = [_weapons, _weapons_index] call BIS_fnc_removeIndex;