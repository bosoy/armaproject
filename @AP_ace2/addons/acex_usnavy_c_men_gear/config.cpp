////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Wed Feb 08 15:25:28 2012 : Created on Wed Feb 08 15:25:28 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_c_men_gear : config.bin{
class CfgPatches
{
	class acex_usnavy_c_men_gear
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_usnavy_main","CACharacters","CACharacters2","ace_main","ace_sys_ruck","ace_c_men_gear","acex_c_vehicle"};
		version = "1.13.0.68";
	};
};
class CfgVehicles
{
	class SoldierWB;
	class SoldierEB;
	class SoldierGB;
	class USMC_Soldier_Base: SoldierWB{};
	class USMC_Soldier_Light: USMC_Soldier_Base{};
	class USMC_Soldier: USMC_Soldier_Base
	{
		weapons[] = {"m16a4_acg","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","HandGrenade_West","HandGrenade_West","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"m16a4_acg","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West"};
	};
	class USMC_Soldier2: USMC_Soldier_Base
	{
		weapons[] = {"ACE_M1014_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"8Rnd_B_Beneli_74Slug","8Rnd_B_Beneli_74Slug","8Rnd_B_Beneli_74Slug","8Rnd_B_Beneli_74Slug","8Rnd_B_Beneli_Pellets","8Rnd_B_Beneli_Pellets","8Rnd_B_Beneli_Pellets","8Rnd_B_Beneli_Pellets","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"ACE_M1014_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"8Rnd_B_Beneli_Pellets","8Rnd_B_Beneli_Pellets","8Rnd_B_Beneli_Pellets","8Rnd_B_Beneli_74Slug","8Rnd_B_Beneli_74Slug","8Rnd_B_Beneli_74Slug","HandGrenade_West","HandGrenade_West"};
	};
	class USMC_Soldier_GL: USMC_Soldier_Base
	{
		weapons[] = {"ACE_M16A4_EOT_GL","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","HandGrenade_West","HandGrenade_West","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203"};
		respawnWeapons[] = {"ACE_M16A4_EOT_GL","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203"};
	};
	class USMC_Soldier_AR: USMC_Soldier_Base
	{
		weapons[] = {"M249","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"200Rnd_556x45_M249","200Rnd_556x45_M249","200Rnd_556x45_M249","200Rnd_556x45_M249","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShell"};
		respawnWeapons[] = {"M249","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"200Rnd_556x45_M249","200Rnd_556x45_M249","HandGrenade_West","SmokeShell"};
	};
	class USMC_Soldier_MG: USMC_Soldier_Base
	{
		weapons[] = {"ACE_M240B","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","SmokeShell","SmokeShell"};
		respawnWeapons[] = {"ACE_M240B","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","SmokeShell"};
	};
	class USMC_SoldierM_Marksman: USMC_Soldier_Base
	{
		weapons[] = {"ACE_M110","M9","NVGoggles","ACE_Rangefinder_OD","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_20Rnd_762x51_SB_M110","ACE_20Rnd_762x51_SB_M110","ACE_20Rnd_762x51_SB_M110","ACE_20Rnd_762x51_SB_M110","ACE_20Rnd_762x51_SB_M110","ACE_20Rnd_762x51_SB_M110","ACE_20Rnd_762x51_T_M110","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_Battery_Rangefinder","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9"};
		respawnWeapons[] = {"ACE_M110","M9","NVGoggles","ACE_Rangefinder_OD","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_20Rnd_762x51_SB_M110","ACE_20Rnd_762x51_SB_M110","ACE_20Rnd_762x51_SB_M110","HandGrenade_West","SmokeShell","ACE_Battery_Rangefinder","15Rnd_9x19_M9","15Rnd_9x19_M9"};
	};
	class USMC_Soldier_AT_Base: USMC_Soldier_Base{};
	class USMC_Soldier_LAT: USMC_Soldier_AT_Base
	{
		weapons[] = {"m16a4_acg","ACE_M136_CSRS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","M136"};
		respawnWeapons[] = {"m16a4_acg","ACE_M136_CSRS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","M136","HandGrenade_West"};
	};
	class USMC_Soldier_HAT: USMC_Soldier_AT_Base
	{
		weapons[] = {"ACE_M4_Aim","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Javelin","ACE_Javelin_CLU"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell"};
		respawnWeapons[] = {"ACE_M4_Aim","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Javelin","ACE_Javelin_CLU"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell"};
	};
	class USMC_Soldier_AT: USMC_Soldier_AT_Base
	{
		accuracy = 1000;
		weapons[] = {"ACE_M16A4_EOT","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","SMAW","ACE_Earplugs"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","SMAW_HEAA","SMAW_HEAA","SMAW_HEDP","ACE_SMAW_Spotting","ACE_SMAW_Spotting"};
		respawnWeapons[] = {"ACE_M16A4_EOT","NVGoggles","SMAW","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SMAW_HEAA","SmokeShell","ACE_SMAW_Spotting"};
	};
	class USMC_Soldier_AA: USMC_Soldier_AT_Base
	{
		weapons[] = {"ACE_M4","Stinger","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","Stinger"};
		respawnWeapons[] = {"ACE_M4","Stinger","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","Stinger","SmokeShell"};
	};
	class USMC_Soldier_Officer: USMC_Soldier_Base
	{
		weapons[] = {"ACE_M4_Eotech","M9","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_Battery_Rangefinder","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9"};
		respawnWeapons[] = {"ACE_M4_Eotech","M9","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_Battery_Rangefinder","15Rnd_9x19_M9","15Rnd_9x19_M9"};
	};
	class USMC_Soldier_SL: USMC_Soldier_Base
	{
		weapons[] = {"ACE_M4_ACOG","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD","M9"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","ACE_Battery_Rangefinder","SmokeShell","SmokeShellRed","SmokeShellGreen","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9"};
		respawnWeapons[] = {"ACE_M4_ACOG","ACE_Rangefinder_OD","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_Battery_Rangefinder","HandGrenade_West","SmokeShell"};
	};
	class USMC_Soldier_TL: USMC_Soldier_Base
	{
		weapons[] = {"M16A4_ACG_GL","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShell","SmokeShellGreen","ACE_Battery_Rangefinder","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_Smoke_M203","1Rnd_Smoke_M203","1Rnd_SmokeRed_M203","1Rnd_SmokeGreen_M203"};
		respawnWeapons[] = {"M16A4_ACG_GL","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD"};
		respawnmagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","ACE_Battery_Rangefinder","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_Smoke_M203"};
	};
	class USMC_Soldier_Medic: USMC_Soldier_Base
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		weapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_MOLLE_WMARPAT_Medic"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","SmokeShellPurple"};
		respawnWeapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_MOLLE_WMARPAT_Medic"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell"};
	};
	class USMC_Soldier_Crew: USMC_Soldier_Base
	{
		weapons[] = {"ACE_M4","M9","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","SmokeShell","SmokeShellRed"};
		respawnWeapons[] = {"ACE_M4","M9","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","15Rnd_9x19_M9","15Rnd_9x19_M9","SmokeShell"};
	};
	class USMC_SoldierS: USMC_Soldier_Base
	{
		weapons[] = {"ACE_M4_ACOG","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","LaserDesignator","M9SD"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","SmokeShell","SmokeShellPurple","SmokeShellYellow","Laserbatteries"};
		respawnWeapons[] = {"ACE_M4_ACOG","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","LaserDesignator"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","SmokeShellPurple","SmokeShellYellow","Laserbatteries"};
	};
	class USMC_SoldierS_Spotter: USMC_Soldier_Base
	{
		weapons[] = {"M16A4_acg","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ItemGPS","ACE_Rangefinder_OD","ACE_Kestrel4500","ACE_SpottingScope"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","smokeshell","smokeshellYellow","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"M16A4_acg","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ItemGPS","ACE_Rangefinder_OD"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","smokeshell","smokeshellYellow","ACE_Battery_Rangefinder"};
	};
	class USMC_SoldierS_Sniper: USMC_Soldier_Base{};
	class USMC_SoldierS_SniperH: USMC_SoldierS_Sniper
	{
		weapons[] = {"M107","Colt1911","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular","ACE_Earplugs"};
		respawnWeapons[] = {"M107","Colt1911","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular","ACE_Earplugs"};
	};
	class USMC_SoldierS_Engineer: USMC_Soldier_Base
	{
		weapons[] = {"ACE_M4_Aim","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_CharliePack_WMARPAT","Binocular"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","Mine","Mine","HandGrenade_West","SmokeShell"};
		respawnWeapons[] = {"ACE_M4_Aim","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_CharliePack_WMARPAT","Binocular"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","Mine","SmokeShell"};
	};
	class USMC_LHD_Crew_Base: USMC_Soldier_Base
	{
		ACE_Stamina = 1.2;
		ACE_DefaultWeight = 5;
	};
	class FR_Base: SoldierWB
	{
		ACE_Stamina = 0.8;
	};
	class FR_TL: FR_Base
	{
		weapons[] = {"ACE_M4A1_RCO2_GL","M9SD","ItemGPS","NVGoggles","ACE_Rangefinder_OD","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShell","ACE_Battery_Rangefinder","1Rnd_SmokeRed_M203","1Rnd_SmokeGreen_M203","FlareRed_M203","FlareGreen_M203","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
		respawnWeapons[] = {"ACE_M4A1_RCO2_GL","M9SD","ItemGPS","NVGoggles","ACE_Rangefinder_OD","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_Battery_Rangefinder","1Rnd_SmokeRed_M203","1Rnd_SmokeGreen_M203","FlareRed_M203","FlareGreen_M203","HandGrenade_West","SmokeShell","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
	};
	class FR_Commander: FR_Base
	{
		weapons[] = {"M4A1_Aim","M9","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","SmokeShellRed","SmokeShellPurple","SmokeShellYellow","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9"};
		respawnWeapons[] = {"M4A1_Aim","M9","ItemGPS","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","SmokeShellRed","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9"};
	};
	class FR_R: FR_Base
	{
		weapons[] = {"ACE_M4A1_Aim_SD","Colt1911","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","HandGrenade_West","SmokeShell","SmokeShell","PipeBomb","ACE_M4SLAM_M","ACE_M4SLAM_M","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
		respawnWeapons[] = {"ACE_M4A1_Aim_SD","Colt1911","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","HandGrenade_West","SmokeShell","PipeBomb","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
	};
	class FR_Corpsman: FR_Base
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		weapons[] = {"M4A1_Aim","NVGoggles","ItemGPS","M9SD","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","SmokeShellRed","SmokeShellGreen","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
		respawnWeapons[] = {"M4A1_Aim","NVGoggles","ItemGPS","M9SD","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","SmokeShellRed","SmokeShellGreen","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
	};
	class FR_AR: FR_Base
	{
		weapons[] = {"M249_m145_EP1","M9SD","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular","NVgoggles","ACE_Earplugs"};
		magazines[] = {"200Rnd_556x45_M249","200Rnd_556x45_M249","200Rnd_556x45_M249","200Rnd_556x45_M249","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShell","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
		respawnWeapons[] = {"M249_m145_EP1","M9SD","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular","NVgoggles","ACE_Earplugs"};
		respawnMagazines[] = {"200Rnd_556x45_M249","200Rnd_556x45_M249","HandGrenade_West","SmokeShell","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
	};
	class ACE_FR_MG: FR_AR
	{
		displayName = "$STR_DN_MGUNNER";
		weapons[] = {"Mk_48","M9SD","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular","NVgoggles","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","SmokeShell","SmokeShell","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
		respawnWeapons[] = {"Mk_48","M9SD","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular","NVgoggles","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","SmokeShell","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
	};
	class FR_GL: FR_Base
	{
		weapons[] = {"M4A1_HWS_GL_camo","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203"};
		respawnWeapons[] = {"M4A1_HWS_GL_camo","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","SmokeShell","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203"};
	};
	class FR_Sapper: FR_Base
	{
		weapons[] = {"ACE_M4A1_Eotech","M9SD","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","PipeBomb","PipeBomb","ACE_M4SLAM_M","ACE_M4SLAM_M","SmokeShell","SmokeShell","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
		respawnWeapons[] = {"ACE_M4A1_Eotech","M9SD","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","PipeBomb","ACE_M4SLAM_M","ACE_M4SLAM_M","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
	};
	class FR_Marksman: FR_Base
	{
		weapons[] = {"DMR","M9SD","ItemGPS","NVGoggles","ACE_Rangefinder_OD","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","HandGrenade_West","SmokeShell","SmokeShellYellow","SmokeShellPurple","ACE_Battery_Rangefinder","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
		respawnWeapons[] = {"DMR","M9SD","ItemGPS","NVGoggles","ACE_Rangefinder_OD","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","HandGrenade_West","ACE_Battery_Rangefinder","SmokeShell","SmokeShellPurple"};
	};
	class FR_AC: FR_Base
	{
		weapons[] = {"M4A1_HWS_GL_SD_Camo","Colt1911","ItemGPS","NVGoggles","LaserDesignator","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","SmokeShellGreen","SmokeShellGreen","SmokeShellYellow","SmokeShellRed","Laserbatteries","FlareRed_M203","FlareGreen_M203","7Rnd_45ACP_1911","7Rnd_45ACP_1911","1Rnd_SmokeRed_M203","1Rnd_SmokeRed_M203","1Rnd_SmokeGreen_M203","1Rnd_SmokeYellow_M203"};
		respawnWeapons[] = {"M4A1_HWS_GL_SD_Camo","Colt1911","ItemGPS","NVGoggles","LaserDesignator","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","ACE_30Rnd_556x45_SB_S_Stanag","SmokeShellGreen","SmokeShellRed","1Rnd_SmokeRed_M203","1Rnd_SmokeGreen_M203","FlareRed_M203","FlareGreen_M203","7Rnd_45ACP_1911","7Rnd_45ACP_1911","Laserbatteries"};
	};
	class FR_Assault_R: FR_R
	{
		weapons[] = {"ACE_M4A1_Eotech","Colt1911","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellPurple","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
		respawnWeapons[] = {"ACE_M4A1_Eotech","Colt1911","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","HandGrenade_West","SmokeShell","SmokeShellPurple","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
	};
	class FR_Assault_GL: FR_GL
	{
		weapons[] = {"ACE_SOC_M4A1_GL_EOTECH","Colt1911","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellPurple","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_Smoke_M203","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
		respawnWeapons[] = {"ACE_SOC_M4A1_GL_EOTECH","Colt1911","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","ACE_30Rnd_556x45_SB_Stanag","HandGrenade_West","SmokeShell","SmokeShellPurple","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_Smoke_M203","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
	};
	class FR_Rodriguez: FR_AR
	{
		weapons[] = {"Mk_48","M9SD","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular","NVgoggles","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShell","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
		respawnWeapons[] = {"Mk_48","M9SD","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular","NVgoggles","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","SmokeShell","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
	};
};
//};
