// #define DEBUG_MODE_FULL
#include "script_component.hpp"
private ["_medic", "_lead", "_hasSecondary", "_hasRuck", "_type", "_faction","_earPluggedUnits","_sixUnitType","_radioUnits"];
PARAMS_1(_unit);
_type = typeOf _unit;
_lead = _unit == leader _unit;
_hasSecondary = secondaryWeapon _unit != "";
_faction = faction _unit;
_sixUnitType = _unit getVariable "SIX_BC_UNITTYPE";
if (isNil "_sixUnitType") then { ERROR("UnitType variable not found, please report!") };
_medic = [_unit] call ace_sys_wounds_fnc_isMedic;


//////////////////////////////
// Make designated medics into medics.
if (_medic && _sixUnitType != "Medic") then {
	_sixUnitType = "Medic";
};
if (!_medic && _sixUnitType == "Medic") then {
	_unit setVariable ["ace_w_ismedic", true, true];
	_medic = true;
};

//////////////////////////////
// AUTOMATIC ADDITION OF MAPTOOLS
if !(_unit hasWeapon "ACE_Map_Tools") then { _unit addWeapon "ACE_Map_Tools" };


//////////////////////////////
// AUTOMATIC ADDITION OF EARPLUGS
_earPluggedUnits = ["Automatic Rifleman", "MG Gunner", "Heavy Gunner"]; //Case sensitive
if (_sixUnitType in _earPluggedUnits) then {
	if !(_unit hasWeapon "ACE_Earplugs") then { _unit addWeapon "ACE_Earplugs" };
};

//////////////////////////////
// AUTOMATIC ADDITION OF RUCK
removeBackpack _unit;
_hasRuck = false;
{ if (getNumber(configFile >> "CfgWeapons" >> _x >> "ace_sys_weapons_TYPE") == 4094) exitWith { _hasRuck = true } } forEach (weapons _unit);
if (!_hasSecondary && !_hasRuck) then {
	// TODO: Read from config


	_hm = [[], "ACE_CharliePack_ACU_Medic"] call CBA_fnc_hashCreate;
	[_hm, east, "ACE_Rucksack_EAST_Medic"] call CBA_fnc_hashSet;
	[_hm, resistance, "ACE_Rucksack_EAST_Medic"] call CBA_fnc_hashSet;

	_h = [[], "ACE_CharliePack_ACU"] call CBA_fnc_hashCreate;
	[_h, east, "ACE_Rucksack_RD92"] call CBA_fnc_hashSet;
	[_h, resistance, "ACE_Rucksack_RD90"] call CBA_fnc_hashSet;

	_hr = [[], "ACE_PRC119"] call CBA_fnc_hashCreate;
	[_hr, east, "ACE_P159_RD99"] call CBA_fnc_hashSet;
	[_hr, resistance, "ACE_P159_RD54"] call CBA_fnc_hashSet;
	
	// ACRE
	if (isClass(configFile >> "CfgPatches" >> "acre_sys_prc117f")) then {
		[_hr, west, "ACRE_PRC117F"] call CBA_fnc_hashSet;
		[_hr, east, "ACRE_PRC117F"] call CBA_fnc_hashSet;
		[_hr, resistance, "ACRE_PRC117F"] call CBA_fnc_hashSet;
	};
	// Faction-specific rucks
	switch (_faction) do {
		case "USMC":
		{
			[_hm, west, "ACE_Rucksack_MOLLE_WMARPAT_Medic"] call CBA_fnc_hashSet;
			[_h, west, "ACE_Rucksack_MOLLE_WMARPAT"] call CBA_fnc_hashSet;
		};
		case "CDF":
		{
			[_hm, west, "ACE_Rucksack_EAST_Medic"] call CBA_fnc_hashSet;
			[_h, west, "ACE_Rucksack_RD92"] call CBA_fnc_hashSet;
		};
		/* -Not really needed as all the RDxx packs are identical ATM.
		case "RU":
		{
			[_hm, east, "ACE_Rucksack_EAST_Medic"] call CBA_fnc_hashSet;
			[_h, east, "ACE_Rucksack_RD99"] call CBA_fnc_hashSet;
		};
		case "GUE":
		{
			[_hm, resistance, "ACE_Rucksack_EAST_Medic"] call CBA_fnc_hashSet;
			[_h, resistance, "ACE_Rucksack_RD54"] call CBA_fnc_hashSet;
		};
		*/
	};

	switch (_sixUnitType) do {
		case "Medic": {
			_unit addWeapon ([_hm, GETVAR(_side)] call CBA_fnc_hashGet);
		};
		case "RTO": {
			_unit addWeapon ([_hr, GETVAR(_side)] call CBA_fnc_hashGet);
		};
		case "Platoon Sergeant": {
			_unit addWeapon ([_hr, GETVAR(_side)] call CBA_fnc_hashGet);
		};
		case "Commander": {
			_unit addWeapon ([_hr, GETVAR(_side)] call CBA_fnc_hashGet);
		};
		case "Pilot": {
			_unit addWeapon ([_hr, GETVAR(_side)] call CBA_fnc_hashGet);
		};
		default {
			_unit addWeapon ([_h, GETVAR(_side)] call CBA_fnc_hashGet);
		};
	};
	_hasRuck = true;
};

TRACE_7("",_unit,_type,_medic,_lead,_hasSecondary,_hasRuck,_sixUnitType);


//////////////////////////////
// ADD STANDARD ITEMS TO RUCK
if (_hasRuck) then {
	if (_medic) then {
		// MEDICS
		if !([_unit,"ACE_Medkit"] call ace_sys_wounds_fnc_hasRuckMagazine) then {
			{ [_unit, _x, 10] call ACE_fnc_PackMagazine } forEach ["ACE_Bandage", "ACE_Morphine", "ACE_Epinephrine"];
			{ [_unit, _x, 4] call ACE_fnc_PackMagazine } forEach ["ACE_Medkit"];
		};
	} else {
		// NON MEDICS
		{ [_unit, _x, 3] call ACE_fnc_PackMagazine } forEach ["ACE_Bandage"];
	};
};

//////////////////////////////
// Add PRC-148s
if (isClass(configFile >> "CfgPatches" >> "acre_sys_prc148")) then {
	_radioUnits = ["Squad Leader", "Platoon Leader","Platoon Sergeant","RTO","Team Leader","Sniper","Commander","Pilot"]; //Case sensitive
	if (_sixUnitType in _radioUnits) then {
		if !(_unit hasWeapon "ACRE_PRC148") then { _unit addWeapon "ACRE_PRC148" };
	};
};


//////////////////////////////
// REMOVAL OF ACOG from GL
// TODO: Fixup this lame hardcoding :P
if (_unit hasWeapon "M16A4_acg_gl" && !_lead) then {
	TRACE_1("Had ACOG. Removing",_unit);
	_unit removeWeapon "M16A4_acg_gl";
	_unit addWeapon "M16A4_gl";
};
