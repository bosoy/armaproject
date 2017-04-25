/* ACE2 Module: Exchangeable Armament System for Aircrafts (EASA) */
// (c) 2009 by rocko
//
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_veh);

TRACE_1("REMOVE PROCESS","");

private["_weapons","_magazines"];
_weapons = weapons _veh;
_veh setVehicleAmmo 1; // Workaround to detect empty magazines
_magazines = magazines _veh;

TRACE_1("Current Loadout",_weapons);
TRACE_1("Current Loadout",_magazines);

private["_magazines_index"];
_magazines_index = [];
for "_x" from 0 to (count _magazines) - 1 do {
	_item_mag = (_magazines select _x);
	_item_ammo = getText(configFile >> "CfgMagazines" >> _item_mag >> "ammo");
	_item_proxy = getText(configFile >> "CfgAmmo" >> _item_ammo >> "proxyShape");
	if ((getText(configFile >> "CfgMagazines" >> _item_mag >> "ammo") isKindOf "RocketBase")) then {
		_magazines_index set [(count _magazines_index), _x];
		TRACE_1("Found FFAR magazine to keep",_item_mag);
	};
	if ((getText(configFile >> "CfgMagazines" >> _item_mag >> "ammo") isKindOf "BulletBase")) then {
		_magazines_index set [(count _magazines_index), _x];
		TRACE_1("Found Cannon magazine to keep",_item_mag);
	};
	if ((getText(configFile >> "CfgMagazines" >> _item_mag >> "ammo") isKindOf "MissileBase") && {(_item_proxy == "")}) then {
		_magazines_index set [(count _magazines_index), _x];
		TRACE_1("Found Missile w/o model to keep",_item_mag);
	};
};
_magazines = [_magazines, _magazines_index] call BIS_fnc_removeIndex;

private["_weapons_index"];
_weapons_index = [];
for "_xx" from 0 to (count _weapons) - 1 do {
	_item_wep = (_weapons select _xx);
	_item_wep_mag = getArray(configFile >> "CfgWeapons" >> (_weapons select _xx) >> "magazines");
	_matches = [_item_wep_mag, {_x in _magazines}] call BIS_fnc_conditionalSelect;
	if (count _matches == 0) then {
		_weapons_index set [(count _weapons_index), _xx];
	} else {
		TRACE_1("Weapon for this magazine is to remove",_matches);
	};
};
_weapons = [_weapons, _weapons_index] call BIS_fnc_removeIndex;

TRACE_1("Removing",_magazines);
TRACE_1("Removing",_weapons);

{
	_veh removeWeapon _x;
	#ifdef DEBUG_MODE_FULL
		sleep 1;
	#endif
	TRACE_1("Removed",_x);
} foreach _weapons;
{
	_veh removeMagazines _x;
	#ifdef DEBUG_MODE_FULL
		sleep 1;
	#endif
	TRACE_1("Removed",_x);
} foreach _magazines;

TRACE_1("REMOVE PROCESS DONE","");

false
