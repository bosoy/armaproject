////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Wed Feb 08 15:20:29 2012 : Created on Wed Feb 08 15:20:29 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_men_gear : config.bin{
class CfgPatches
{
	class acex_c_men_gear
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","CACharacters","CACharacters2","CACharacters_BAF","CACharacters_W_BAF","ace_main","ace_sys_ruck","ace_c_men_gear","ace_c_men","acex_c_vehicle","ace_sys_crewserved"};
		version = "1.13.0.354";
	};
};
class CfgVehicles
{
	class SoldierWB;
	class SoldierEB;
	class SoldierGB;
	class US_Soldier_Base_EP1: SoldierWB{};
	class US_Soldier_MG_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M240L_M145","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"ACE_M240L_M145","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West"};
	};
	class US_Soldier_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class US_Soldier_AAT_EP1: US_Soldier_EP1
	{
		weapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","MAAWS_HEAT","MAAWS_HEDP","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","MAAWS_HEDP","HandGrenade_West"};
	};
	class US_Soldier_Light_EP1: US_Soldier_Base_EP1
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		weapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class US_Soldier_GL_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4_AIM_GL","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_M4_AIM_GL","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class US_Soldier_Officer_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4","Colt1911","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector"};
		respawnWeapons[] = {"ACE_M4","Colt1911","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector"};
	};
	class US_Soldier_SL_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4_RCO_GL","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","M9"};
		respawnWeapons[] = {"ACE_M4_RCO_GL","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","M9"};
	};
	class US_Soldier_TL_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4_RCO_GL","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS"};
		respawnWeapons[] = {"ACE_M4_RCO_GL","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS"};
	};
	class US_Soldier_AT_Base_EP1: US_Soldier_Base_EP1{};
	class US_Soldier_LAT_EP1: US_Soldier_AT_Base_EP1
	{
		weapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","M136"};
		respawnWeapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","M136"};
	};
	class US_Soldier_AT_EP1: US_Soldier_AT_Base_EP1
	{
		weapons[] = {"ACE_M4_Aim","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","MAAWS"};
		respawnWeapons[] = {"ACE_M4_Aim","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","MAAWS"};
	};
	class US_Soldier_HAT_EP1: US_Soldier_AT_Base_EP1
	{
		weapons[] = {"ACE_M4_Aim","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Javelin","ACE_Javelin_CLU"};
		respawnWeapons[] = {"ACE_M4_Aim","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Javelin","ACE_Javelin_CLU"};
	};
	class US_Soldier_AA_EP1: US_Soldier_AT_Base_EP1
	{
		weapons[] = {"ACE_M4_Eotech","Stinger","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_M4_Eotech","Stinger","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class US_Soldier_Medic_EP1: US_Soldier_Base_EP1
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		weapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_CharliePack_ACU_Medic"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","SmokeShell"};
		respawnWeapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_CharliePack_ACU_Medic"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell"};
	};
	class US_Soldier_Spotter_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4_RCO_GL","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS"};
		respawnWeapons[] = {"ACE_M4_RCO_GL","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS"};
	};
	class US_Soldier_Engineer_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4_Aim","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_M4_Aim","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class US_Soldier_Pilot_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS"};
		respawnWeapons[] = {"ACE_M4","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS"};
	};
	class US_Soldier_Crew_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4","Colt1911","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_M4","Colt1911","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class US_Delta_Force_EP1;
	class US_Delta_Force_M14_EP1: US_Delta_Force_EP1
	{
		weapons[] = {"ACE_M14_ACOG","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9"};
		magazines[] = {"20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","ACE_20Rnd_762x51_T_DMR","ACE_Battery_Rangefinder","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShellRed","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9"};
		respawnWeapons[] = {"ACE_M14_ACOG","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9"};
		respawnMagazines[] = {"20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","ACE_20Rnd_762x51_T_DMR","ACE_Battery_Rangefinder","IR_Strobe_Target","SmokeShellRed","15Rnd_9x19_M9","15Rnd_9x19_M9"};
	};
	class ACE_US_Soldier_M224_G: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M224Proxy"};
		respawnWeapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M224Proxy"};
	};
	class ACE_US_Soldier_M224_AG: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M224TripodProxy"};
		respawnWeapons[] = {"ACE_M4","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M224TripodProxy"};
	};
	class ACE_US_Soldier_M224_AB: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnWeapons[] = {"ACE_M4","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
	};
	class ACE_US_Soldier_M252_G: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M252Proxy"};
		respawnWeapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M252Proxy"};
	};
	class ACE_US_Soldier_M252_AG: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M252TripodProxy"};
		respawnWeapons[] = {"ACE_M4","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M252TripodProxy"};
	};
	class ACE_US_Soldier_M252_AB: US_Soldier_Base_EP1
	{
		weapons[] = {"ACE_M4","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnWeapons[] = {"ACE_M4","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
	};
	class BAF_Soldier_base_EP1;
	class BAF_Soldier_Officer_MTP: BAF_Soldier_base_EP1
	{
		weapons[] = {"BAF_L85A2_RIS_Holo","ACE_L9A1","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","smokeshellyellow","smokeshellpurple","smokeshellgreen","smokeshell","smokeshellred","BAF_L109A1_HE","BAF_L109A1_HE"};
		respawnweapons[] = {"BAF_L85A2_RIS_Holo","ACE_L9A1","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector"};
		respawnmagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","smokeshellyellow","smokeshellpurple","smokeshellgreen","smokeshell","smokeshellred","BAF_L109A1_HE","BAF_L109A1_HE"};
	};
	class BAF_Soldier_scout_MTP: BAF_Soldier_base_EP1
	{
		weapons[] = {"BAF_LRR_scoped","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS","ACE_L9A1"};
		magazines[] = {"5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","smokeshell","smokeshellred","smokeshellgreen","BAF_L109A1_HE"};
		respawnweapons[] = {"BAF_LRR_scoped","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS","ACE_L9A1"};
		respawnmagazines[] = {"5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","smokeshell","BAF_L109A1_HE"};
	};
	class BAF_Soldier_Sniper_MTP: BAF_Soldier_base_EP1
	{
		weapons[] = {"BAF_LRR_scoped","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS","ACE_L9A1"};
		magazines[] = {"5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","smokeshell","smokeshellred","smokeshellgreen"};
		respawnweapons[] = {"BAF_LRR_scoped","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS","ACE_L9A1"};
		respawnmagazines[] = {"5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","5Rnd_86x70_L115A1","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","smokeshell"};
	};
	class BAF_Soldier_SniperH_MTP: BAF_Soldier_Sniper_MTP
	{
		weapons[] = {"BAF_AS50_scoped","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS","ACE_L9A1","ACE_Earplugs"};
		magazines[] = {"5Rnd_127x99_AS50","5Rnd_127x99_AS50","5Rnd_127x99_AS50","5Rnd_127x99_AS50","5Rnd_127x99_AS50","5Rnd_127x99_AS50","5Rnd_127x99_AS50","5Rnd_127x99_AS50","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","smokeshell","smokeshellred","smokeshellgreen"};
		respawnweapons[] = {"BAF_AS50_scoped","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS","ACE_L9A1","ACE_Earplugs"};
		respawnmagazines[] = {"5Rnd_127x99_AS50","5Rnd_127x99_AS50","5Rnd_127x99_AS50","5Rnd_127x99_AS50","ACE_13Rnd_9x19_L9A1","ACE_13Rnd_9x19_L9A1","smokeshell"};
	};
	class BAF_Soldier_SniperN_MTP: BAF_Soldier_SniperH_MTP
	{
		weapons[] = {"BAF_AS50_TWS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS","ACE_L9A1","ACE_Earplugs"};
		respawnWeapons[] = {"BAF_AS50_TWS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS","ACE_L9A1","ACE_Earplugs"};
	};
	class BAF_Soldier_Sniper_W: BAF_Soldier_Sniper_MTP
	{
		weapons[] = {"BAF_LRR_scoped_W","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD","ItemGPS","ACE_L9A1"};
		respawnweapons[] = {"BAF_LRR_scoped_W","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD","ItemGPS","ACE_L9A1"};
	};
	class TK_Soldier_base_EP1: SoldierEB{};
	class TK_INS_Soldier_Base_EP1;
	class TK_INS_Soldier_EP1: TK_INS_Soldier_Base_EP1{};
	class ACE_TK_INS_Soldier_AKM_EP1: TK_INS_Soldier_EP1
	{
		weapons[] = {"ACE_AKM","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnweapons[] = {"ACE_AKM","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class ACE_TK_INS_Soldier_AKMS_EP1: ACE_TK_INS_Soldier_AKM_EP1
	{
		displayname = "$STR_ACE_VDN_ACE_TK_INS_SOLDIER_AKMS";
		weapons[] = {"ACE_AKMS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnweapons[] = {"ACE_AKMS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class GER_Soldier_base_EP1: SoldierWB{};
	class GER_Soldier_MG_EP1: GER_Soldier_base_EP1
	{
		weapons[] = {"ACE_MG36_D","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","ACE_P8","ACE_Earplugs"};
		magazines[] = {"100Rnd_556x45_BetaCMag","100Rnd_556x45_BetaCMag","100Rnd_556x45_BetaCMag","100Rnd_556x45_BetaCMag","ACE_Battery_Rangefinder","ACE_DM51A1","IR_Strobe_Target","ACE_DM25","ACE_15Rnd_9x19_P8","ACE_15Rnd_9x19_P8","ACE_15Rnd_9x19_P8","ACE_15Rnd_9x19_P8"};
		respawnWeapons[] = {"ACE_MG36_D","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS","ACE_P8","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_556x45_BetaCMag","100Rnd_556x45_BetaCMag","100Rnd_556x45_BetaCMag","ACE_DM51A1","IR_Strobe_Target","ACE_DM25","ACE_15Rnd_9x19_P8","ACE_15Rnd_9x19_P8"};
	};
};
//};
