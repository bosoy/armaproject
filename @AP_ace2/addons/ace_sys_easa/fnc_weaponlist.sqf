/* ACE2 Module: Exchangeable Armament System for Aircrafts (EASA) */
// (c) 2009 by rocko
//
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_pylons","_carrier_type"];
_pylons = [GVAR(air)] call FUNC(pylonlist);
if (GVAR(air) isKindOf "PLANE") then { _carrier_type = "Plane"; };
if (GVAR(air) isKindOf "HELICOPTER") then { _carrier_type = "Helicopter"; };
if (GVAR(air) isKindOf "UAV") then { _carrier_type = "UAV"; };

#define __disp (uiNameSpace getVariable "ACE_AIRACRAFT_LOADOUT")
#define __picCtrl (__disp displayCtrl 537)

__picCtrl ctrlSetText (getText(configFile >> "CfgVehicles" >> (typeOf GVAR(air)) >> "picture"));

waitUntil { GVAR(pylons_processed) };
GVAR(pylons_processed) = false;

if (format["%1",_pylons] == format["%1",[0,0,0]]) exitWith {
	closeDialog 0;
	format["%1 has no weapon slots", (typeOf GVAR(air))] spawn ace_fnc_visual;	//TODO: Add localize
	false;
};

TRACE_1("WEAPON LIST PROCESS","");

private ["_entry","_name","_side_rule","_weapons","_names","_side","_carrier"];
_weapons = [];
_names = [];

private ["_rules"];
_rules = [GVAR(air),"","GET"] call FUNC(rules);

_side_rule = _rules select 1;
if (_side_rule == -2) then { _side_rule = getNumber(configFile >> "CfgVehicles" >> (typeOf GVAR(air)) >> "side"); };

_nuke_rule = _rules select 2;

for "_i" from 0 to ((count (configFile >> "CfgMagazines")) - 1) do {
	_entry = (configFile >> "CfgMagazines") select _i;
	_name = getText(_entry >> "ACE_EASA_NAME"); if (_name == "") then { _name = configName _entry; };
	_side = getNumber(_entry >> "ACE_EASA_SIDE");
	_nuke = getNumber(_entry >> "ACE_EASA_NUKE");
	_carrier = getArray(_entry >> "ACE_EASA_CARRIER");

	// HOLY DEBUG
	//if (getNumber(_entry >> "ACE_EASA") == 1) then
	//{
	//	TRACE_5("",_entry,_name,_side,_nuke,_carrier);
	//	TRACE_2("",_carrier,_carrier_type);
	//	if (_carrier_type in _carrier) then
	//	{
	//		LOG("In Types");
	//	};
	//};
	//
	if (getNumber(_entry >> "ACE_EASA") == 1 && {_side == _side_rule || {_side_rule == -1}} && {_carrier_type in _carrier} && {(_nuke == 0 || {_nuke == _nuke_rule})}) then {
		PUSH(_weapons,configName _entry);
		PUSH(_names, _name);
	};
};

// RULE 1 - Weapon limitations (TODO: VERY LATER)
// run everytime weapon list is processed, but set init amount once
// _cap = _rules select 0;
// _cap_init = GVAR(easa) getVariable "ACE_EASA_CAP_INIT";
// if (isNil "_cap_init") then
// {
//	GVAR(easa) setVariable ["ACE_EASA_INIT",true,true];
// };
// if R
// _capacity = [];
// for "_i" from 0 to ((count _weapons) - 1) do
// {
//	_entry = [_weapons select _i, _init_count];
// 	PUSH(_capacity,_entry);
// };
//

_all_pylons = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23];
_pylons_available = [[0,1,2,3,4,5,6,7],[8,9,10,11,12,13,14,15],[16,17,18,19,20,21,22,23]];

private["_pylons_not_available"];
_pylons_not_available = [];
for "_x" from 0 to (count _pylons) - 1 do {
	_tmp_pylon = _pylons_available select _x;
	_tmp_pylon_used = [_tmp_pylon, (_pylons select _x)] call BIS_fnc_subSelect;
	_pylons_not_available = _pylons_not_available + _tmp_pylon_used;
};

#define __dsp (uiNamespace getVariable "ACE_AIRACRAFT_LOADOUT")
#define __ctrl22 (__dsp displayCtrl 22)
__ctrl22 ctrlSetText format["%1", (getText(configFile >> "CfgVehicles" >> (typeOf GVAR(air)) >> "displayName"))];

//#define __ctrl20 (__dsp displayCtrl 20)

for "_x" from 0 to (count _pylons_not_available) - 1 do {
	ctrlShow [(((_pylons_not_available) select _x) + 100), false];
};
_pylons_available = _all_pylons - _pylons_not_available;

//private["_cap","_count"];
//_cap = GVAR(air) getVariable "ACE_EASA_CAP";

for "_x" from 0 to (count _pylons_available) - 1 do {
	for "_y" from 0 to (count _weapons) - 1 do {
		_index = lbAdd[(((_pylons_available) select _x) + 100), _names select _y];
		lbSetData [(((_pylons_available) select _x) + 100), _index, _weapons select _y];
		//lbSetValue [(((_pylons_available) select _x) + 100), _index, _count];
		// TODO: Add certain amount of magazines per hangar
	};
};

TRACE_1("WEAPON LIST PROCESS DONE","");

false
