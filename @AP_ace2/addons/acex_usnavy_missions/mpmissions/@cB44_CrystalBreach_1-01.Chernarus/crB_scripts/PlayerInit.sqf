//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090719
// Contact: http://creobellum.org
// Purpose: Setup players based on class
///////////////////////////////////////////////////////////////////

sleep 0.2;

_unit = _this select 0;

waitUntil{!isNull _unit};
waitUntil{local _unit};

if (side _unit != west) exitWith{};

//if (_unit == player) then {hint format["%1", typeOf _unit];};

removeAllItems _unit;
removeAllWeapons _unit;

//waitUntil {_unit call ACE_Sys_Ruck_HasRucksack};

_loadout = Param2;
if (isNil "_loadout") then {
	_loadout = defValueParam2;
};

switch (_loadout) do {
	case 1: {
		#include "LoadoutM4SD.sqf";
	};
	case 2: {
		#include "LoadoutM16Iron.sqf";
	};
	case 3: {
		#include "LoadoutM16.sqf";
	};
	case 4: {
		#include "LoadoutM16.sqf";
		if (_unit == player) then {
			_boxnew = "USBasicWeaponsBox" createVehicleLocal (position ACE_AMMO);
			_boxnew setPos (position ACE_AMMO);
			[_boxnew] execVM "x_scripts\x_weaponcargo_ace.sqf";
		};
	};
};

switch (typeOf _unit) do {
	// Officer
	case "USMC_Soldier_Officer": { [] call KIT_Officer; };

	// Squad Leader
	case "USMC_Soldier_SL": { [] call KIT_SquadLead; };

	// Team Leader
	case "FR_TL": { [] call KIT_TeamLead; };
	case "USMC_Soldier_TL": { [] call KIT_TeamLead; };

	// Medic
	case "FR_Corpsman": { [] call KIT_Medic; };
	case "USMC_Soldier_Medic": { [] call KIT_Medic; };

	// Machine Gunner
	case "FR_AR": { [] call KIT_MGunner; };
	case "USMC_Soldier_MG": { [] call KIT_MGunner; };

	// Auto Rifleman
	case "USMC_Soldier_AR": { [] call KIT_AR; };

	// Demo
	case "FR_Sapper": { [] call KIT_Demo; };

	// Grenadier
	case "USMC_Soldier_GL": { [] call KIT_Grenadier; };

	// AT4
	case "USMC_Soldier_LAT": { [] call KIT_Armour_LAT; };

	// SMAW
	case "USMC_Soldier_AT": { [] call KIT_Armour_SMAW; };

	// HAT
	case "USMC_Soldier_HAT": { [] call KIT_Armour_HAT; };

	// AA
	case "USMC_Soldier_AA": { [] call KIT_AA; };

	// Forward Air Controller
	case "FR_AC": { [] call KIT_FAC; };
	case "USMC_SoldierS": { [] call KIT_FAC; };

	// Marksman	/ Rifleman
	case "FR_Marksman": { [] call KIT_Marksman; };
	case "USMC_SoldierM_Marksman": { [] call KIT_Marksman; };

	// Engineer
	case "USMC_SoldierS_Engineer": { [] call KIT_Engineer; };

	// Asst Gunner
	case "FR_R": { [] call KIT_AsstGunner; };

	// Asst SMAW
	case "USMC_Soldier": { [] call KIT_Rifleman; };

	// Asst HAT
	case "USMC_Soldier2": { [] call KIT_Rifleman2; };
};

sleep 0.1;
