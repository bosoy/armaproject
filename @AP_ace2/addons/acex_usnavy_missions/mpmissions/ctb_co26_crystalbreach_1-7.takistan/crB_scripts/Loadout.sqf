//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090719
// Modified: 20100719
// Contact: http://creobellum.org
// Purpose: Setup players based on class
///////////////////////////////////////////////////////////////////

KIT_SquadLead_Iron = {
	_unit = _this select 0;
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_Stanag";} count [1,2,3,4,5,6];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	{_unit addMagazine "IR_Strobe_Target"} count [1];
	{_unit addMagazine "SmokeShell"} count [1,2];
	{_unit addMagazine "SmokeShellGreen"} count [1];
	// 8 Minislots
	{_unit addMagazine "1Rnd_HE_M203"} count [1,2,3,4,5,6];
	{_unit addMagazine "15Rnd_9x19_M9"} count [1,2];
	// Weapons
	_unit addWeapon "SCAR_L_CQC_EGLM_Holo";
	_unit selectWeapon "SCAR_L_CQC_EGLM_Holo";
	_unit addWeapon "M9";
	_unit addWeapon "Binocular_Vector";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addBackpack "US_Patrol_Pack_EP1";
	unitBackpack _unit addMagazineCargo ["30Rnd_556x45_Stanag", 4];
	unitBackpack _unit addMagazineCargo ["1Rnd_HE_M203", 4];
};

KIT_Medic_Iron = {
	_unit = _this select 0;
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_Stanag";} count [1,2,3,4,5,6];
	{_unit addMagazine "SmokeShell"} count [1,2];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9"} count [1,2];
	// Weapons
	_unit addWeapon "SCAR_L_CQC";
	_unit selectWeapon "SCAR_L_CQC";
	_unit addWeapon "M9";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
};

KIT_AR_Iron = {
	_unit = _this select 0;
	// 12 Slots
	{_unit addMagazine "200Rnd_556x45_M249";} count [1,2,3,4,5];
	{_unit addMagazine "HandGrenade_West"} count [1];
	{_unit addMagazine "SmokeShell"} count [1];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9"} count [1,2];
	// Weapons
	_unit addWeapon "M249_EP1";
	_unit selectWeapon "M249_EP1";
	_unit addWeapon "M9";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
};

KIT_AsstGunner_Iron = {
	_unit = _this select 0;
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_Stanag";} count [1,2,3,4,5,6];
	{_unit addMagazine "200Rnd_556x45_M249";} count [1];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	{_unit addMagazine "SmokeShell"} count [1,2];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9"} count [1,2];
	// Weapons
	_unit addWeapon "SCAR_L_CQC";
	_unit selectWeapon "SCAR_L_CQC";
	_unit addWeapon "M9";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addBackpack "US_Patrol_Pack_EP1";
	unitBackpack _unit addMagazineCargo ["200Rnd_556x45_M249", 4];
};

KIT_Grenadier_Iron = {
	_unit = _this select 0;
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_Stanag";} count [1,2,3,4,5,6,7,8];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	{_unit addMagazine "SmokeShell"} count [1,2];
	// 8 Minislots
	{_unit addMagazine "1Rnd_HE_M203"} count [1,2,3,4,5,6,7,8];
	// Weapons
	_unit addWeapon "SCAR_L_CQC_EGLM_Holo";
	_unit selectWeapon "SCAR_L_CQC_EGLM_Holo";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
};

KIT_MGunner_Iron = {
	_unit = _this select 0;
	// 12 Slots
	{_unit addMagazine "100Rnd_762x51_M240";} count [1,2,3,4];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9"} count [1,2];
	// Weapons
	_unit addWeapon "M60A4_EP1";
	_unit selectWeapon "M60A4_EP1";
	_unit addWeapon "M9";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
};

KIT_AsstGunner2_Iron = {
	_unit = _this select 0;
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_Stanag";} count [1,2,3,4,5,6];
	{_unit addMagazine "100Rnd_762x51_M240";} count [1];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	{_unit addMagazine "SmokeShell"} count [1,2];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9"} count [1,2];
	// Weapons
	_unit addWeapon "SCAR_L_CQC";
	_unit selectWeapon "SCAR_L_CQC";
	_unit addWeapon "M9";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addBackpack "US_Patrol_Pack_EP1";
	unitBackpack _unit addMagazineCargo ["100Rnd_762x51_M240", 4];
};

KIT_Marksman_Iron = {
	_unit = _this select 0;
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_Stanag";} count [1,2,3,4,5,6,7,8];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	{_unit addMagazine "SmokeShellPurple"} count [1];
	{_unit addMagazine "SmokeShellYellow"} count [1];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9"} count [1,2,3,4];
	// Weapons
	_unit addWeapon "SCAR_L_STD_Mk4CQT";
	_unit selectWeapon "SCAR_L_STD_Mk4CQT";
	_unit addWeapon "M9";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addBackpack "US_Patrol_Pack_EP1";
	unitBackpack _unit addMagazineCargo ["30Rnd_556x45_Stanag", 6];
	unitBackpack _unit addMagazineCargo ["HandGrenade_West", 1];
	unitBackpack _unit addMagazineCargo ["SmokeShell", 1];
};
