//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090719
// Modified: 20100420
// Contact: http://creobellum.org
// Purpose: Setup players based on class
///////////////////////////////////////////////////////////////////

sleep 0.2;

private["_unit", "_loadout", "_loadoutx"];
_unit = _this select 0;
waitUntil{!isNull _unit};

if (side _unit == civilian) exitWith{};

//if (_unit == player) then {
//	hint format["%1", typeOf _unit];
//};

call compile preprocessFileLineNumbers "crB_scripts\Loadout.sqf";

_loadoutx = "";
switch (typeOf _unit) do {
	// Squad Leader
	case "US_Soldier_SL_EP1": { _loadoutx = "KIT_SquadLead_Iron"; };
	case "TK_Soldier_SL_EP1": { _loadoutx = "KIT_SquadLead_Iron"; };

	// Team Leader
	case "US_Soldier_TL_EP1": { _loadoutx = "KIT_SquadLead_Iron"; };
	case "TK_GUE_Soldier_TL_EP1": { _loadoutx = "KIT_SquadLead_Iron"; };

	// Medic
	case "US_Soldier_Medic_EP1": { _loadoutx = "KIT_Medic_Iron"; };
	case "TK_Soldier_Medic_EP1": { _loadoutx = "KIT_Medic_Iron"; };
	case "TK_GUE_Bonesetter_EP1": { _loadoutx = "KIT_Medic_Iron"; };

	// Auto Rifleman
	case "US_Soldier_AR_EP1": { _loadoutx = "KIT_AR_Iron"; };
	case "TK_Soldier_AR_EP1": { _loadoutx = "KIT_AR_Iron"; };
	case "TK_GUE_Soldier_AR_EP1": { _loadoutx = "KIT_AR_Iron"; };

	// Grenadier
	case "US_Soldier_GL_EP1": { _loadoutx = "KIT_Grenadier_Iron"; };
	case "TK_Soldier_GL_EP1": { _loadoutx = "KIT_Grenadier_Iron"; };

	// Asst Auto Rifleman
	case "US_Soldier_AAR_EP1": { _loadoutx = "KIT_AsstGunner_Iron"; };
	case "TK_Soldier_EP1": { _loadoutx = "KIT_AsstGunner_Iron"; };
	case "TK_GUE_Soldier_EP1": { _loadoutx = "KIT_AsstGunner_Iron"; };

	// Machine Gunner
	case "US_Soldier_MG_EP1": { _loadoutx = "KIT_MGunner_Iron"; };

	// Asst Machine Gunner
	case "US_Soldier_AMG_EP1": { _loadoutx = "KIT_AsstGunner2_Iron"; };

	// Marksman
	case "US_Soldier_Marksman_EP1": { _loadoutx = "KIT_Marksman_Iron"; };

};

if(_loadoutx != "") then {
	clearMagazineCargo _unit;
	clearWeaponCargo _unit;
	removeBackpack _unit;
	removeAllItems _unit;
	removeAllWeapons _unit;
	call compile format["[_unit] call %1" , _loadoutx];
};

sleep 5;

if (_unit == player) then {
	call{[] execVM "x_scripts\x_playerspawn.sqf";};
};
