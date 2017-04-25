//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090719
// Contact: http://creobellum.org
// Purpose: Setup players based on class
///////////////////////////////////////////////////////////////////

KIT_Officer = {
	// 6 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4];
	_unit addMagazine "HandGrenade_West";
	_unit addMagazine "SmokeShell";
	// 4 Minislots
	{_unit addMagazine "15Rnd_9x19_M9SD";} count [1];
	{_unit addMagazine "1Rnd_HE_M203"} count [1,2];
	{_unit addMagazine "ACE_HuntIR_M203"} count [1];
	// Weapons
	_unit addWeapon "ACE_M4A1_GL_SD";
	_unit selectWeapon "ACE_M4A1_GL_SD";
	_unit addWeapon "M9SD";
	_unit addWeapon "Binocular";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addWeapon "ACE_PRC119";
	[_unit, "SmokeShell", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "HandGrenade_West", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "1Rnd_HE_M203", 6] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_HuntIR_M203", 3] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_HuntIR_monitor", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_SquadLead = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6];
	{_unit addMagazine "HandGrenade_West"} count [1];
	{_unit addMagazine "ACE_Battery_Rangefinder"} count [1];
	{_unit addMagazine "SmokeShell"} count [1,2];
	{_unit addMagazine "SmokeShellGreen"} count [1];
	{_unit addMagazine "SmokeShellRed"} count [1];
	// 8 Minislots
	{_unit addMagazine "1Rnd_HE_M203"} count [1,2,3,4,5,6];
	{_unit addMagazine "15Rnd_9x19_M9SD"} count [1,2];
	// Weapons
	_unit addWeapon "ACE_M4A1_GL_SD";
	_unit selectWeapon "ACE_M4A1_GL_SD";
	_unit addWeapon "M9SD";
	_unit addWeapon "ACE_Rangefinder_OD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addWeapon "ACE_PRC119";
	[_unit, "1Rnd_HE_M203", 8] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_TeamLead = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	{_unit addMagazine "SmokeShell"} count [1,2];
	{_unit addMagazine "SmokeShellGreen"} count [1];
	{_unit addMagazine "SmokeShellRed"} count [1];
	// 8 Minislots
	{_unit addMagazine "1Rnd_HE_M203"} count [1,2,3,4,5,6];
	{_unit addMagazine "15Rnd_9x19_M9SD"} count [1,2];
	// Weapons
	_unit addWeapon "ACE_M4A1_GL_SD";
	_unit selectWeapon "ACE_M4A1_GL_SD";
	_unit addWeapon "M9SD";
	_unit addWeapon "Binocular";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addWeapon "ACE_CharliePack";
	[_unit, "1Rnd_HE_M203", 8] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_Medic = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6];
	{_unit addMagazine "SmokeShell"} count [1,2,3,4];
	{_unit addMagazine "SmokeShellGreen"} count [1];
	{_unit addMagazine "SmokeShellRed"} count [1];
	// 8 Minislots
	{_unit addMagazine "1Rnd_HE_M203"} count [1,2,3,4,5,6];
	{_unit addMagazine "15Rnd_9x19_M9SD"} count [1,2];
	// Weapons
	_unit addWeapon "ACE_M4A1_ACOG_SD";
	_unit selectWeapon "ACE_M4A1_ACOG_SD";
	_unit addWeapon "M9SD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addWeapon "ACE_Rucksack_MOLLE_Brown_Medic";
	[_unit, "SmokeShell", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShellGreen", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShellRed", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 14] call ACE_Sys_Ruck_fnc_AddMagToRuck;[_unit, "ACE_LargeBandage", 14] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 14] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_MGunner = {
	// 12 Slots
	{_unit addMagazine "100Rnd_762x51_M240";} count [1,2,3,4];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9SD"} count [1,2];
	// Weapons
	_unit addWeapon "ACE_M240G_M145";
	_unit selectWeapon "ACE_M240G_M145";
	_unit addWeapon "M9SD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addWeapon "ACE_Rucksack_MOLLE_Brown";
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShell", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_AR = {
	// 12 Slots
	{_unit addMagazine "200Rnd_556x45_M249";} count [1,2,3,4,5];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9SD"} count [1,2];
	// Weapons
	_unit addWeapon "ACE_M249Para_M145";
	_unit selectWeapon "ACE_M249Para_M145";
	_unit addWeapon "M9SD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addWeapon "ACE_Rucksack_MOLLE_Green";
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShell", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_Grenadier = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6,7,8];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	{_unit addMagazine "SmokeShell"} count [1,2];
	// 8 Minislots
	{_unit addMagazine "1Rnd_HE_M203"} count [1,2,3,4,5,6,7,8];
	// Weapons
	_unit addWeapon "ACE_M4A1_GL_SD";
	_unit selectWeapon "ACE_M4A1_GL_SD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addWeapon "ACE_Rucksack_MOLLE_Green";
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "HandGrenade_West", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShell", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_Armour_LAT = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6,7,8];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	{_unit addMagazine "SmokeShell"} count [1,2];
	// 8 Minislots
	{_unit addMagazine "1Rnd_HE_M203"} count [1,2,3,4,5,6];
	{_unit addMagazine "15Rnd_9x19_M9SD"} count [1,2];
	// Weapons
	_unit addWeapon "ACE_M4A1_ACOG_SD";
	_unit selectWeapon "ACE_M4A1_ACOG_SD";
	_unit addWeapon "M136";
	_unit addWeapon "M9SD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit setVariable ["ACE_weapononback", "ACE_Rucksack_MOLLE_Green"];
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "200Rnd_556x45_M249", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "HandGrenade_West", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShell", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_Armour_SMAW = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6];
	{_unit addMagazine "SMAW_HEAA"} count [1,2,3];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9SD"} count [1,2];
	// Weapons
	_unit addWeapon "ACE_M4A1_ACOG_SD";
	_unit selectWeapon "ACE_M4A1_ACOG_SD";
	_unit addWeapon "SMAW";
	_unit addWeapon "M9SD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit setVariable ["ACE_weapononback", "ACE_Rucksack_MOLLE_Brown"];
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "HandGrenade_West", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShell", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_Armour_HAT = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6];
	{_unit addWeaponCargo "ACE_Javelin_CLU"} count [1];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9SD"} count [1,2];
	// Weapons
	_unit addWeapon "ACE_M4A1_ACOG_SD";
	_unit selectWeapon "ACE_M4A1_ACOG_SD";
	_unit addWeapon "Javelin";
	_unit addWeapon "M9SD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit setVariable ["ACE_weapononback", "ACE_Rucksack_MOLLE_Brown"];
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "HandGrenade_West", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShell", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_AA = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6];
	{_unit addMagazine "Stinger"} count [1];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9SD"} count [1,2];
	// Weapons
	_unit addWeapon "ACE_M4A1_ACOG_SD";
	_unit selectWeapon "ACE_M4A1_ACOG_SD";
	_unit addWeapon "Stinger";
	_unit addWeapon "M9SD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit setVariable ["ACE_weapononback", "ACE_Rucksack_MOLLE_Brown"];
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "HandGrenade_West", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShell", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_FAC = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	{_unit addMagazine "SmokeShell"} count [1];
	{_unit addMagazine "SmokeShellPurple"} count [1];
	{_unit addMagazine "SmokeShellYellow"} count [1];
	{_unit addMagazine "LaserBatteries"} count [1];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9SD"} count [1,2];
	// Weapons
	_unit addWeapon "ACE_M4SPR_SD";
	_unit selectWeapon "ACE_M4SPR_SD";
	_unit addWeapon "M9SD";
	_unit addWeapon "Laserdesignator";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addWeapon "ACE_Rucksack_MOLLE_WMARPAT";
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "HandGrenade_West", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShell", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_Engineer = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6];
	{_unit addMagazine "HandGrenade_West"} count [1];
	{_unit addMagazine "SmokeShell"} count [1];
	{_unit addMagazine "Mine"} count [1,2];
	// 8 Minislots
	{_unit addMagazine "1Rnd_HE_M203"} count [1,2,3,4,5,6];
	{_unit addMagazine "15Rnd_9x19_M9SD"} count [1,2];
	// Weapons
	_unit addWeapon "ACE_M4A1_GL_SD";
	_unit selectWeapon "ACE_M4A1_GL_SD";
	_unit addWeapon "M9SD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addWeapon "ACE_Rucksack_MOLLE_WMARPAT";
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "HandGrenade_West", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShell", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_Rifleman = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6];
	{_unit addMagazine "HandGrenade_West"} count [1];
	{_unit addMagazine "SmokeShell"} count [1];
	// 8 Minislots
	// Weapons
	_unit addWeapon "ACE_M4A1_ACOG_SD";
	_unit selectWeapon "ACE_M4A1_ACOG_SD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	_unit addWeapon "ACE_Rucksack_MOLLE_Brown";
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SMAW_HEAA", 3] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "HandGrenade_West", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShell", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_Rifleman2 = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6];
	{_unit addMagazine "HandGrenade_West"} count [1];
	{_unit addMagazine "SmokeShell"} count [1];
	// 8 Minislots
	// Weapons
	_unit addWeapon "ACE_M4A1_ACOG_SD";
	_unit selectWeapon "ACE_M4A1_ACOG_SD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	_unit addWeapon "ACE_Rucksack_MOLLE_Brown";
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "Javelin", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "HandGrenade_West", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShell", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

// Not Used
KIT_Demo = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6];
	{_unit addMagazine "HandGrenade_West"} count [1];
	{_unit addMagazine "SmokeShell"} count [1];
	{_unit addMagazine "PipeBomb"} count [1,2];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9SD"} count [1,2];
	// Weapons
	_unit addWeapon "ACE_M4A1_ACOG_SD";
	_unit selectWeapon "ACE_M4A1_ACOG_SD";
	_unit addWeapon "M9SD";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
	// Backpack
	_unit addWeapon "ACE_Rucksack_MOLLE_Brown";
	[_unit, "ACE_IRStrobe", 1] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "30Rnd_556x45_StanagSD", 4] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "HandGrenade_West", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "SmokeShell", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Bandage", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Morphine", 7] call ACE_Sys_Ruck_fnc_AddMagToRuck;
	[_unit, "ACE_Epinephrine", 2] call ACE_Sys_Ruck_fnc_AddMagToRuck;
};

KIT_AsstGunner = {
	// 12 Slots
	{_unit addMagazine "30Rnd_556x45_StanagSD";} count [1,2,3,4,5,6];
	{_unit addMagazine "100Rnd_762x51_M240";} count [1,2];
	{_unit addMagazine "SmokeShell"} count [1,2];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9"} count [1,2];
	{_unit addMagazine "1Rnd_HE_M203"} count [1,2,3,4,5,6];
	// Weapons
	_unit addWeapon "M16A2";
	_unit selectWeapon "M16A2";
	_unit addWeapon "M9";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
};

KIT_Marksman = {
	// 12 Slots
	{_unit addMagazine "5Rnd_762x51_M24";} count [1,2,3,4,5,6,7,8];
	{_unit addMagazine "HandGrenade_West"} count [1,2];
	{_unit addMagazine "SmokeShellPurple"} count [1];
	{_unit addMagazine "SmokeShellYellow"} count [1];
	// 8 Minislots
	{_unit addMagazine "15Rnd_9x19_M9"} count [1,2,3,4];
	// Weapons
	_unit addWeapon "M24";
	_unit selectWeapon "M24";
	_unit addWeapon "M9SD";
	_unit addWeapon "Binocular";
	_unit addweapon "NVGoggles";
	_unit addweapon "ItemMap";
	_unit addweapon "ItemGPS";
	_unit addweapon "ItemCompass";
	_unit addweapon "ItemWatch";
	_unit addweapon "ItemRadio";
};