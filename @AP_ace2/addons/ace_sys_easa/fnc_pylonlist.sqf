/* ACE2 Module: Exchangeable Armament System for Aircrafts (EASA) */
// (c) 2009 by rocko
//
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_veh);

TRACE_1("PYLON LIST PROCESS","");
TRACE_1("Aircraft:", (typeOf _veh));

private["_weapons","_magazines"];
if (isClass(configFile >> "CfgVehicles" >> (typeOf _veh) >> "Turrets" >> "MainTurret")) then {
	_weapons = (getArray(configFile >> "CfgVehicles" >> (typeOf _veh) >> "Turrets" >> "MainTurret" >> "weapons"));
	_magazines = (getArray(configFile >> "CfgVehicles" >> (typeOf _veh) >> "Turrets" >> "MainTurret" >> "magazines"));
} else {
	_weapons = (getArray(configFile >> "CfgVehicles" >> (typeOf _veh) >> "weapons"));
	_magazines = (getArray(configFile >> "CfgVehicles" >> (typeOf _veh) >> "magazines"));
};
TRACE_1("Weapons from config:",_weapons);
TRACE_1("Magazines from config:",_magazines);

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
	if ((getText(configFile >> "CfgMagazines" >> _item_mag >> "ammo") isKindOf "Laserbeam")) then {
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
	} else { TRACE_1("Weapon for this magazine is to remove",_matches); };
};
_weapons = [_weapons, _weapons_index] call BIS_fnc_removeIndex;

TRACE_1("Weapons to consider for pylons:",_weapons);
TRACE_1("Magazines to consider for pylons:",_magazines);

// Calculate available pylons
_pylons = [];
for "_x" from 0 to (count _magazines) - 1 do {
	_pylon_item = _magazines select _x;
	//if (getNumber(configFile >> "CfgMagazines" >> _pylon_item >> "ACE_EASA_RACK") == 1) then
	//{
	//	_pylon_cap = getNumber(configFile>> "CfgMagazines" >> _pylon_item >> "ACE_EASA_COUNT"); // Translates a weaponcarrier into single magazines
	//} else {
		_pylon_cap  = (getNumber(configFile >> "CfgMagazines" >> _pylon_item >> "count"));
	//};
	_pylons set [(count _pylons), _pylon_cap];
};

if ((count _pylons) == 0) then { { PUSH(_pylons,_x) } forEach [0,0,0] };
if ((count _pylons) == 1) then { { PUSH(_pylons,_x) } forEach [0,0] };
if ((count _pylons) == 2) then { { PUSH(_pylons,_x) } forEach [0] };

GVAR(pylons_processed) = true;

TRACE_1("Pylons available This array must be == 3", _pylons);
TRACE_1("PYLON LIST PROCESS DONE","");
_pylons
