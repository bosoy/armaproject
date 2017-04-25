////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:05:10 2013 : Created on Sat Jun 08 13:05:10 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_men_gear : config.bin{
class CfgPatches
{
	class ace_c_men_gear
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CACharacters","CACharacters2","CACharacters_e","ace_main","ace_sys_ruck","ace_sys_disposal","ace_c_weapon","ace_c_men_designation"};
		version = "1.14.0.593";
	};
};
class CfgVehicles
{
	class SoldierWB;
	class SoldierEB;
	class SoldierGB;
	class US_Assault_Pack_EP1;
	class US_Assault_Pack_Explosives_EP1: US_Assault_Pack_EP1
	{
		class TransportMagazines
		{
			class _xx_PipeBomb
			{
				magazine = "PipeBomb";
				count = 1;
			};
			class _xx_ACE_C4_M
			{
				magazine = "ACE_C4_M";
				count = 4;
			};
			class _xx_ACE_Claymore_M
			{
				magazine = "ACE_Claymore_M";
				count = 2;
			};
		};
	};
	class TK_ALICE_Pack_EP1;
	class TK_ALICE_Pack_Explosives_EP1: TK_ALICE_Pack_EP1
	{
		class TransportMagazines
		{
			class _xx_PipeBomb
			{
				magazine = "PipeBomb";
				count = 1;
			};
			class _xx_ACE_POMZ_M
			{
				magazine = "ACE_POMZ_M";
				count = 2;
			};
		};
	};
	class GER_Soldier_base_EP1: SoldierWB{};
	class GER_Soldier_EP1: GER_Soldier_base_EP1
	{
		backpack = "";
		weapons[] = {"G36a_camo","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","glock17_EP1"};
		magazines[] = {"30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","ACE_Battery_Rangefinder","ACE_DM51A1","ACE_DM51A1","IR_Strobe_Target","ACE_DM25","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
		respawnWeapons[] = {"G36a_camo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS","glock17_EP1"};
		respawnMagazines[] = {"30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","ACE_DM51A1","IR_Strobe_Target","ACE_DM25","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
	};
	class GER_Soldier_Medic_EP1: GER_Soldier_base_EP1
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		backpack = "";
		canCarryBackPack = 1;
		weapons[] = {"G36C_camo","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","glock17_EP1","ACE_VTAC_RUSH72_TT_MEDIC"};
		magazines[] = {"30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","ACE_Battery_Rangefinder","IR_Strobe_Target","ACE_DM25","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
		respawnWeapons[] = {"G36C_camo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS","glock17_EP1","ACE_VTAC_RUSH72_TT_MEDIC"};
		respawnMagazines[] = {"30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","IR_Strobe_Target","ACE_DM25","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
	};
	class GER_Soldier_TL_EP1: GER_Soldier_base_EP1
	{
		backpack = "";
		weapons[] = {"G36K_camo","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","glock17_EP1"};
		magazines[] = {"30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","ACE_Battery_Rangefinder","ACE_DM51A1","IR_Strobe_Target","ACE_DM25","ACE_DM25","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
		respawnWeapons[] = {"G36K_camo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS","glock17_EP1"};
		respawnMagazines[] = {"30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","30Rnd_556x45_G36","ACE_DM51A1","IR_Strobe_Target","ACE_DM25","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
	};
	class GER_Soldier_Scout_EP1: GER_Soldier_base_EP1
	{
		backpack = "";
		weapons[] = {"G36_C_SD_camo","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","glock17_EP1"};
		magazines[] = {"30Rnd_556x45_G36SD","30Rnd_556x45_G36SD","30Rnd_556x45_G36SD","30Rnd_556x45_G36SD","30Rnd_556x45_G36SD","30Rnd_556x45_G36SD","30Rnd_556x45_G36SD","ACE_Battery_Rangefinder","ACE_DM51A1","ACE_DM51A1","IR_Strobe_Target","ACE_DM25","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
		respawnWeapons[] = {"G36_C_SD_camo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS","glock17_EP1"};
		respawnMagazines[] = {"30Rnd_556x45_G36SD","30Rnd_556x45_G36SD","30Rnd_556x45_G36SD","30Rnd_556x45_G36SD","ACE_DM51A1","IR_Strobe_Target","ACE_DM25","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
	};
	class GER_Soldier_MG_EP1: GER_Soldier_base_EP1
	{
		backpack = "";
		weapons[] = {"MG36_camo","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","glock17_EP1","ACE_Earplugs"};
		magazines[] = {"100Rnd_556x45_BetaCMag","100Rnd_556x45_BetaCMag","100Rnd_556x45_BetaCMag","100Rnd_556x45_BetaCMag","ACE_Battery_Rangefinder","ACE_DM51A1","IR_Strobe_Target","ACE_DM25","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
		respawnWeapons[] = {"MG36_camo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS","glock17_EP1","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_556x45_BetaCMag","100Rnd_556x45_BetaCMag","100Rnd_556x45_BetaCMag","ACE_DM51A1","IR_Strobe_Target","ACE_DM25","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
	};
	class US_Soldier_Base_EP1: SoldierWB{};
	class US_Soldier_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West"};
	};
	class US_Soldier_AAT_EP1: US_Soldier_EP1
	{
		weapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","MAAWS_HEAT","MAAWS_HEDP","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","MAAWS_HEDP","HandGrenade_West"};
	};
	class US_Soldier_Light_EP1: US_Soldier_Base_EP1
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		weapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag"};
		respawnWeapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag"};
	};
	class US_Soldier_GL_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"SCAR_L_CQC_EGLM_Holo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShell","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203"};
		respawnWeapons[] = {"SCAR_L_CQC_EGLM_Holo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","SmokeShell","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203"};
	};
	class US_Soldier_Officer_EP1: US_Soldier_Base_EP1
	{
		weaponSlots = "1  +  4  + 7 *   256  + 2 *  4096  +  2  + 4* 16  + 12*131072";
		weapons[] = {"SCAR_L_CQC","Colt1911","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_Battery_Rangefinder","IR_Strobe_Target","SmokeShellRed","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
		respawnWeapons[] = {"SCAR_L_CQC","Colt1911","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_Battery_Rangefinder","SmokeShellRed","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
	};
	class US_Soldier_SL_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"SCAR_L_STD_EGLM_TWS","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","M9"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_Battery_Rangefinder","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShellGreen","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_Smoke_M203","1Rnd_SmokeGreen_M203","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9"};
		respawnWeapons[] = {"SCAR_L_STD_EGLM_TWS","NVGoggles","ItemGPS","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","M9"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_Battery_Rangefinder","HandGrenade_West","IR_Strobe_Target","SmokeShellGreen","1Rnd_HE_M203","1Rnd_SmokeGreen_M203","15Rnd_9x19_M9","15Rnd_9x19_M9"};
	};
	class US_Soldier_TL_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"SCAR_L_STD_EGLM_RCO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_Battery_Rangefinder","IR_Strobe_Target","SmokeShellRed","HandGrenade_West","HandGrenade_West","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_Smoke_M203","1Rnd_Smoke_M203","1Rnd_SmokeRed_M203","1Rnd_SmokeRed_M203"};
		respawnWeapons[] = {"SCAR_L_STD_EGLM_RCO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS"};
		respawnmagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_Battery_Rangefinder","SmokeShellRed","HandGrenade_West","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_SmokeRed_M203"};
	};
	class US_Soldier_AT_Base_EP1: US_Soldier_Base_EP1{};
	class US_Soldier_LAT_EP1: US_Soldier_AT_Base_EP1
	{
		weapons[] = {"SCAR_L_CQC_Holo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","M136"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","M136"};
		respawnWeapons[] = {"SCAR_L_CQC_Holo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","M136"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","M136"};
	};
	class US_Soldier_AT_EP1: US_Soldier_AT_Base_EP1
	{
		weapons[] = {"SCAR_L_CQC_Holo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","MAAWS"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","MAAWS_HEAT","MAAWS_HEDP","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"SCAR_L_CQC_Holo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","MAAWS"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","MAAWS_HEDP","HandGrenade_West"};
	};
	class US_Soldier_HAT_EP1: US_Soldier_AT_Base_EP1
	{
		weapons[] = {"SCAR_L_CQC_Holo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Javelin","ACE_Javelin_CLU"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"SCAR_L_CQC_Holo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Javelin","ACE_Javelin_CLU"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West"};
	};
	class US_Soldier_AA_EP1: US_Soldier_AT_Base_EP1
	{
		weapons[] = {"SCAR_L_STD_HOLO","Stinger","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","Stinger"};
		respawnWeapons[] = {"SCAR_L_STD_HOLO","Stinger","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","Stinger"};
	};
	class US_Soldier_Medic_EP1: US_Soldier_Base_EP1
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		cancarrybackpack = 1;
		weapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_CharliePack_ACU_Medic"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell","SmokeShell"};
		respawnWeapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_CharliePack_ACU_Medic"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","SmokeShell"};
	};
	class US_Soldier_AR_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"M249_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"100Rnd_556x45_M249","100Rnd_556x45_M249","100Rnd_556x45_M249","100Rnd_556x45_M249","100Rnd_556x45_M249","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"M249_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_556x45_M249","100Rnd_556x45_M249","100Rnd_556x45_M249","HandGrenade_West"};
	};
	class US_Soldier_MG_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"m240_scoped_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"m240_scoped_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West"};
	};
	class US_Soldier_Spotter_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"SCAR_L_STD_EGLM_TWS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_Battery_Rangefinder","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","smokeshellYellow","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_SmokeYellow_M203","1Rnd_SmokeYellow_M203"};
		respawnWeapons[] = {"SCAR_L_STD_EGLM_TWS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","ACE_Battery_Rangefinder","smokeshellYellow","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_SmokeYellow_M203"};
	};
	class US_Soldier_Sniper_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"M110_NVG_EP1","Colt1911","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS"};
		magazines[] = {"20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","ACE_Battery_Rangefinder","HandGrenade_West","HandGrenade_West","smokeshell","smokeshellgreen","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
		respawnWeapons[] = {"M110_NVG_EP1","Colt1911","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS"};
		respawnMagazines[] = {"20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","ACE_Battery_Rangefinder","smokeshellgreen","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
	};
	class US_Soldier_Sniper_NV_EP1: US_Soldier_Sniper_EP1
	{
		weapons[] = {"M110_TWS_EP1","Colt1911","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS"};
		magazines[] = {"20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","ACE_Battery_Rangefinder","HandGrenade_West","HandGrenade_West","smokeshell","smokeshellgreen","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
		respawnWeapons[] = {"M110_TWS_EP1","Colt1911","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS"};
		respawnMagazines[] = {"20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","HandGrenade_West","ACE_Battery_Rangefinder","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
	};
	class US_Soldier_SniperH_EP1: US_Soldier_Sniper_EP1
	{
		weapons[] = {"M107","Colt1911","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS","ACE_Earplugs"};
		magazines[] = {"10Rnd_127x99_m107","10Rnd_127x99_m107","10Rnd_127x99_m107","10Rnd_127x99_m107","10Rnd_127x99_m107","10Rnd_127x99_m107","10Rnd_127x99_m107","10Rnd_127x99_m107","ACE_Battery_Rangefinder","HandGrenade_West","smokeshell","smokeshellgreen","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
		respawnWeapons[] = {"M107","Colt1911","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS","ACE_Earplugs"};
		respawnMagazines[] = {"10Rnd_127x99_m107","10Rnd_127x99_m107","10Rnd_127x99_m107","10Rnd_127x99_m107","10Rnd_127x99_m107","10Rnd_127x99_m107","ACE_Battery_Rangefinder","smokeshellgreen","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
	};
	class US_Soldier_Marksman_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"M110_NVG_EP1","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","ACE_Battery_Rangefinder","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShellRed"};
		respawnWeapons[] = {"M110_NVG_EP1","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","20Rnd_762x51_B_SCAR","HandGrenade_West","ACE_Battery_Rangefinder","SmokeShellRed"};
	};
	class US_Soldier_Engineer_EP1: US_Soldier_Base_EP1
	{
		displayName = "$STR_ACE_VDN_ACE_ENGINEER";
		weapons[] = {"SCAR_L_STD_Mk4CQT","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","ACE_C4_M","ACE_C4_M","ACE_Claymore_M","ACE_Claymore_M","SmokeShell"};
		respawnWeapons[] = {"SCAR_L_STD_Mk4CQT","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","ACE_C4_M","ACE_Claymore_M","SmokeShell"};
	};
	class US_Soldier_Pilot_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"SCAR_L_CQC","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed"};
		respawnWeapons[] = {"SCAR_L_CQC","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","SmokeShellRed"};
	};
	class US_Soldier_Crew_EP1: US_Soldier_Base_EP1
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		weapons[] = {"SCAR_L_CQC","Colt1911","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
		respawnWeapons[] = {"SCAR_L_CQC","Colt1911","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","7Rnd_45ACP_1911","7Rnd_45ACP_1911"};
	};
	class US_Delta_Force_EP1: US_Soldier_Base_EP1
	{
		ACE_Stamina = 0.8;
		weapons[] = {"SCAR_H_CQC_CCO","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","M9"};
		magazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_Battery_Rangefinder","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShellRed","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9"};
		respawnWeapons[] = {"SCAR_H_CQC_CCO","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9"};
		respawnMagazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_Battery_Rangefinder","HandGrenade_West","IR_Strobe_Target","SmokeShellRed","15Rnd_9x19_M9","15Rnd_9x19_M9"};
	};
	class US_Delta_Force_TL_EP1: US_Soldier_Base_EP1
	{
		ACE_Stamina = 0.8;
		weapons[] = {"SCAR_H_STD_EGLM_Spect","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD"};
		magazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_Battery_Rangefinder","HandGrenade_West","IR_Strobe_Target","SmokeShellGreen","SmokeShellRed","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_SmokeGreen_M203","1Rnd_SmokeRed_M203","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
		respawnWeapons[] = {"SCAR_H_CQC_CCO","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD"};
		respawnMagazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_Battery_Rangefinder","IR_Strobe_Target","SmokeShellGreen","1Rnd_HE_M203","1Rnd_SmokeGreen_M203","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
	};
	class US_Delta_Force_Medic_EP1: US_Delta_Force_EP1
	{
		cancarrybackpack = 1;
		weapons[] = {"SCAR_H_CQC_CCO","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD","ACE_CharliePack_ACU_Medic"};
		magazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_Battery_Rangefinder","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShellRed"};
		respawnWeapons[] = {"SCAR_H_CQC_CCO","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD","ACE_CharliePack_ACU_Medic"};
		respawnMagazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","ACE_Battery_Rangefinder","IR_Strobe_Target","SmokeShellRed"};
	};
	class US_Delta_Force_Assault_EP1: US_Delta_Force_EP1
	{
		weapons[] = {"SCAR_H_STD_EGLM_Spect","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9"};
		magazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_Battery_Rangefinder","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_SmokeRed_M203","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShellRed"};
		respawnWeapons[] = {"SCAR_H_STD_EGLM_Spect","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9"};
		respawnMagazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_SmokeRed_M203","15Rnd_9x19_M9","15Rnd_9x19_M9","ACE_Battery_Rangefinder","IR_Strobe_Target","SmokeShellRed"};
	};
	class US_Delta_Force_SD_EP1: US_Delta_Force_EP1
	{
		weapons[] = {"SCAR_H_CQC_CCO_SD","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD"};
		magazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_Battery_Rangefinder","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShellRed"};
		respawnWeapons[] = {"SCAR_H_CQC_CCO_SD","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD"};
		respawnMagazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","ACE_Battery_Rangefinder","IR_Strobe_Target","SmokeShellRed"};
	};
	class US_Delta_Force_MG_EP1: US_Delta_Force_EP1
	{
		weapons[] = {"Mk_48_DES_EP1","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9"};
		magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","ACE_Battery_Rangefinder","HandGrenade_West","IR_Strobe_Target","SmokeShellRed","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9"};
		respawnWeapons[] = {"Mk_48_DES_EP1","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9"};
		respawnMagazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","ACE_Battery_Rangefinder","IR_Strobe_Target","SmokeShellRed","15Rnd_9x19_M9","15Rnd_9x19_M9"};
	};
	class US_Delta_Force_AR_EP1: US_Delta_Force_EP1
	{
		weapons[] = {"M249_m145_EP1","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9"};
		magazines[] = {"100Rnd_556x45_M249","100Rnd_556x45_M249","100Rnd_556x45_M249","100Rnd_556x45_M249","ACE_Battery_Rangefinder","HandGrenade_West","IR_Strobe_Target","SmokeShellRed","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9"};
		respawnWeapons[] = {"M249_m145_EP1","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9"};
		respawnMagazines[] = {"100Rnd_556x45_M249","100Rnd_556x45_M249","100Rnd_556x45_M249","ACE_Battery_Rangefinder","IR_Strobe_Target","SmokeShellRed","15Rnd_9x19_M9","15Rnd_9x19_M9"};
	};
	class US_Delta_Force_Night_EP1: US_Delta_Force_EP1
	{
		weapons[] = {"SCAR_H_STD_TWS_SD","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD"};
		magazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_Battery_Rangefinder","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShellRed","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
		respawnWeapons[] = {"SCAR_H_STD_TWS_SD","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD"};
		respawnMagazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_Battery_Rangefinder","IR_Strobe_Target","SmokeShellRed","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
	};
	class US_Delta_Force_Marksman_EP1: US_Delta_Force_EP1
	{
		weapons[] = {"SCAR_H_LNG_Sniper","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD"};
		magazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_Battery_Rangefinder","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShellPurple","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
		respawnWeapons[] = {"SCAR_H_LNG_Sniper","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD"};
		respawnMagazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_Battery_Rangefinder","IR_Strobe_Target","SmokeShellPurple","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
	};
	class US_Delta_Force_M14_EP1: US_Delta_Force_EP1
	{
		weapons[] = {"M14_EP1","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9"};
		magazines[] = {"20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","ACE_Battery_Rangefinder","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShellRed","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9","15Rnd_9x19_M9"};
		respawnWeapons[] = {"M14_EP1","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9"};
		respawnMagazines[] = {"20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","20Rnd_762x51_DMR","ACE_Battery_Rangefinder","IR_Strobe_Target","SmokeShellRed","15Rnd_9x19_M9","15Rnd_9x19_M9"};
	};
	class US_Delta_Force_Air_Controller_EP1: US_Delta_Force_EP1
	{
		weapons[] = {"SCAR_H_CQC_CCO_SD","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD","Laserdesignator"};
		magazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","Laserbatteries","IR_Strobe_Target","SmokeShellRed","SmokeShellPurple","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
		respawnWeapons[] = {"SCAR_H_CQC_CCO_SD","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD","Laserdesignator"};
		respawnMagazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","Laserbatteries","IR_Strobe_Target","SmokeShellPurple","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD"};
	};
	class US_Pilot_Light_EP1: US_Soldier_Base_EP1
	{
		weapons[] = {"Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {};
	};
	class Drake: US_Soldier_Base_EP1
	{
		weapons[] = {"M249_m145_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"100Rnd_556x45_M249","100Rnd_556x45_M249","100Rnd_556x45_M249","100Rnd_556x45_M249","HandGrenade_West","HandGrenade_West","SmokeShellGreen","SmokeShellYellow"};
		respawnWeapons[] = {"M249_m145_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_556x45_M249","100Rnd_556x45_M249","HandGrenade_West","SmokeShellYellow"};
	};
	class Herrera: US_Soldier_Crew_EP1
	{
		weapons[] = {"SCAR_L_CQC_Holo","Colt1911","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911","7Rnd_45ACP_1911","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"SCAR_L_CQC_Holo","Colt1911","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","7Rnd_45ACP_1911","7Rnd_45ACP_1911","HandGrenade_West"};
	};
	class Graves: US_Delta_Force_EP1
	{
		weapons[] = {"SCAR_H_STD_EGLM_Spect","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD"};
		magazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_Battery_Rangefinder","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_SmokeGreen_M203","1Rnd_SmokeYellow_M203","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","HandGrenade_West","HandGrenade_West","SmokeShellPurple","SmokeShellYellow"};
		respawnWeapons[] = {"SCAR_H_STD_EGLM_Spect","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","M9SD"};
		respawnMagazines[] = {"ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","ACE_20Rnd_762x51_SB_SCAR","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_SmokeGreen_M203","1Rnd_SmokeYellow_M203","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","15Rnd_9x19_M9SD","ACE_Battery_Rangefinder","SmokeShellPurple"};
	};
	class CZ_Soldier_base_EP1: SoldierWB
	{
		weapons[] = {"M4A1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","SmokeShell"};
		respawnWeapons[] = {"M4A1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","SmokeShell"};
		class ACE;
	};
	class CZ_Soldier_SL_DES_EP1: CZ_Soldier_base_EP1
	{
		backpack = "CZ_VestPouch_Sa58_EP1";
		weapons[] = {"Sa58V_CCO_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ItemGPS","Binocular_Vector","glock17_EP1"};
		magazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShellRed","SmokeShellGreen","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"Sa58V_CCO_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ItemGPS","Binocular_Vector","glock17_EP1"};
		respawnMagazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","HandGrenade_West","IR_Strobe_Target","SmokeShellRed","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
	};
	class CZ_Soldier_DES_EP1: CZ_Soldier_base_EP1
	{
		backpack = "CZ_VestPouch_Sa58_EP1";
		weapons[] = {"Sa58V_CCO_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","HandGrenade_West","HandGrenade_West","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"Sa58V_CCO_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","HandGrenade_West","HandGrenade_West"};
	};
	class CZ_Soldier_medik_DES_EP1: CZ_Soldier_DES_EP1
	{
		weapons[] = {"Sa58V_CCO_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_CharliePack_ACU_Medic"};
		magazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","SmokeShell","SmokeShellRed","SmokeShellGreen"};
		respawnWeapons[] = {"Sa58V_CCO_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_CharliePack_ACU_Medic"};
		respawnMagazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","SmokeShell"};
	};
	class CZ_Soldier_AMG_DES_EP1: CZ_Soldier_DES_EP1
	{
		backpack = "CZ_Backpack_AmmoMG_EP1";
	};
	class CZ_Soldier_AT_DES_EP1: CZ_Soldier_base_EP1
	{
		weapons[] = {"Sa58V_CCO_EP1","MAAWS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","MAAWS_HEAT","MAAWS_HEDP","HandGrenade_West","HandGrenade_West"};
		respawnWeapons[] = {"Sa58V_CCO_EP1","MAAWS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","MAAWS_HEDP","HandGrenade_West"};
	};
	class CZ_Soldier_MG_DES_EP1: CZ_Soldier_base_EP1
	{
		weapons[] = {"M60A4_EP1","CZ_75_SP_01_PHANTOM","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"M60A4_EP1","CZ_75_SP_01_PHANTOM","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_Office_DES_EP1: CZ_Soldier_base_EP1
	{
		weapons[] = {"Sa58V_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","Binocular_Vector","glock17_EP1"};
		magazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","IR_Strobe_Target","SmokeShellRed","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"Sa58V_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","Binocular_Vector","glock17_EP1"};
		respawnMagazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","IR_Strobe_Target","SmokeShellRed","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
	};
	class CZ_Soldier_Light_DES_EP1: CZ_Soldier_base_EP1
	{
		weapons[] = {"Sa58P_EP1","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","HandGrenade_West","SmokeShell","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"Sa58P_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","HandGrenade_West","SmokeShell","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_Pilot_EP1: CZ_Soldier_base_EP1
	{
		weapons[] = {"Sa58V_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS"};
		magazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","HandGrenade_West","SmokeShell","SmokeShellRed"};
		respawnWeapons[] = {"Sa58V_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS"};
		respawnMagazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","HandGrenade_West","SmokeShellRed"};
	};
	class CZ_Soldier_Sniper_EP1: CZ_Soldier_base_EP1
	{
		weapons[] = {"SVD_des_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS","glock17_EP1"};
		magazines[] = {"10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","smokeshellred","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"SVD_des_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS","glock17_EP1"};
		respawnMagazines[] = {"10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","HandGrenade_West","IR_Strobe_Target","smokeshellred","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
	};
	class CZ_Special_Forces_Scout_DES_EP1: CZ_Soldier_base_EP1
	{
		weapons[] = {"Sa58V_CCO_EP1","glock17_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","Binocular_Vector"};
		magazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"Sa58V_CCO_EP1","glock17_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","Binocular_Vector"};
		respawnMagazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
		backpack = "CZ_VestPouch_Sa58_EP1";
	};
	class CZ_Special_Forces_MG_DES_EP1: CZ_Soldier_base_EP1
	{
		weapons[] = {"M60A4_EP1","glock17_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"M60A4_EP1","glock17_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
	};
	class CZ_Special_Forces_DES_EP1: CZ_Soldier_base_EP1
	{
		weapons[] = {"M4A3_CCO_EP1","CZ_75_SP_01_PHANTOM","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"M4A3_CCO_EP1","CZ_75_SP_01_PHANTOM","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Special_Forces_TL_DES_EP1: CZ_Soldier_base_EP1
	{
		weapons[] = {"M4A3_RCO_GL_EP1","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","LRTV_ACR","itemGPS"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","IR_Strobe_Target","SmokeShellRed","SmokeShellGreen","ACE_BB2847","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"M4A3_RCO_GL_EP1","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","LRTV_ACR","itemGPS"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","IR_Strobe_Target","SmokeShellGreen","ACE_BB2847","1Rnd_HE_M203","1Rnd_HE_M203","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		backpack = "CZ_VestPouch_M4_EP1";
	};
	class CZ_Special_Forces_GL_DES_EP1: CZ_Soldier_base_EP1
	{
		weapons[] = {"M4A3_RCO_GL_EP1","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"M4A3_RCO_GL_EP1","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","itemGPS"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","1Rnd_HE_M203","1Rnd_HE_M203","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		backpack = "CZ_VestPouch_M4_EP1";
	};
	class CZ_Soldier_Base_ACR: CZ_Soldier_base_EP1{};
	class CZ_Soldier805_DES_ACR: CZ_Soldier_DES_EP1
	{
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		backpack = "CZ_VestPouch_M4_EP1";
	};
	class CZ_Soldier_805_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		weapons[] = {"CZ805_A1_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"CZ805_A1_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_805g_Dst_ACR: CZ_Soldier_Base_ACR
	{
		backpack = "CZ_VestPouch_M4_EP1";
		weapons[] = {"CZ805_A1_GL_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203"};
		respawnWeapons[] = {"CZ805_A1_GL_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203"};
	};
	class CZ_Soldier_805g_Wdl_ACR: CZ_Soldier_805g_Dst_ACR{};
	class CZ_Soldier_Crew_Dst_ACR: CZ_Soldier_Base_ACR
	{
		weapons[] = {"Evo_mrad_ACR","CZ_75_D_COMPACT","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","HandGrenade_West","SmokeShell","SmokeShellRed","10Rnd_9x19_Compact","10Rnd_9x19_Compact","10Rnd_9x19_Compact","10Rnd_9x19_Compact"};
		respawnWeapons[] = {"Evo_mrad_ACR","CZ_75_D_COMPACT","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","HandGrenade_West","SmokeShell","SmokeShellRed","10Rnd_9x19_Compact","10Rnd_9x19_Compact"};
	};
	class CZ_Soldier_Crew_Wdl_ACR: CZ_Soldier_Crew_Dst_ACR
	{
		magazines[] = {"20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","HandGrenade_West","SmokeShell","SmokeShellRed","10Rnd_9x19_Compact","10Rnd_9x19_Compact","10Rnd_9x19_Compact","10Rnd_9x19_Compact"};
		respawnMagazines[] = {"20Rnd_9x19_EVO","20Rnd_9x19_EVO","SmokeShell","SmokeShellRed","10Rnd_9x19_Compact","10Rnd_9x19_Compact"};
	};
	class CZ_Soldier_Leader_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		backpack = "CZ_VestPouch_M4_EP1";
		weapons[] = {"CZ805_A1_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","ACE_Rangefinder_OD"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"CZ805_A2_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","ACE_Rangefinder_OD"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_Medic_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		weapons[] = {"CZ805_A2_ACR","CZ_75_D_COMPACT","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_CharliePack_ACU_Medic"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed","10Rnd_9x19_Compact","10Rnd_9x19_Compact","10Rnd_9x19_Compact","10Rnd_9x19_Compact"};
		respawnWeapons[] = {"CZ805_A2_ACR","CZ_75_D_COMPACT","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_CharliePack_ACU_Medic"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","SmokeShell","SmokeShellRed","10Rnd_9x19_Compact","10Rnd_9x19_Compact"};
	};
	class CZ_Soldier_MG_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		weapons[] = {"M60A4_EP1","CZ_75_SP_01_PHANTOM","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"M60A4_EP1","CZ_75_SP_01_PHANTOM","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_MG2_Wdl_ACR: CZ_Soldier_MG_Wdl_ACR
	{
		weapons[] = {"M249_m145_EP1","CZ_75_SP_01_PHANTOM","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"100Rnd_556x45_M249","100Rnd_556x45_M249","100Rnd_556x45_M249","100Rnd_556x45_M249","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"M249_m145_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_556x45_M249","100Rnd_556x45_M249","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_MG2_Dst_ACR: CZ_Soldier_MG2_Wdl_ACR{};
	class CZ_Soldier_Officer_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		weapons[] = {"CZ_75_SP_01_PHANTOM","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","ACE_Rangefinder_OD"};
		magazines[] = {"ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed","IR_Strobe_Target","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"CZ_75_SP_01_PHANTOM","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","ACE_Rangefinder_OD"};
		respawnMagazines[] = {"ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","HandGrenade_West","SmokeShell","SmokeShellRed","IR_Strobe_Target"};
	};
	class CZ_Soldier_Pilot_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		weapons[] = {"Evo_ACR","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS"};
		magazines[] = {"20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","HandGrenade_West","SmokeShell","SmokeShellRed"};
		respawnWeapons[] = {"Evo_ACR","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS"};
		respawnMagazines[] = {"20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","HandGrenade_West","SmokeShellRed"};
	};
	class CZ_Soldier_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		backpack = "CZ_VestPouch_Sa58_EP1";
		weapons[] = {"Sa58P_EP1","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"Sa58P_EP1","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_Recon_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		weapons[] = {"CZ805_A1_GL_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","LRTV_ACR","itemGPS"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","ACE_BB2847","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"CZ805_A1_GL_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","LRTV_ACR","itemGPS"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","ACE_BB2847","1Rnd_HE_M203","1Rnd_HE_M203","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_Spec1_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		weapons[] = {"M4A3_CCO_EP1","CZ_75_SP_01_PHANTOM","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD","itemGPS"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"M4A3_CCO_EP1","CZ_75_SP_01_PHANTOM","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD","itemGPS"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_Spec2_Wdl_ACR: CZ_Soldier_Spec1_Wdl_ACR
	{
		weapons[] = {"CZ805_A1_GL_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","LRTV_ACR","itemGPS"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","ACE_BB2847","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","1Rnd_HE_M203","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"CZ805_A1_GL_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","LRTV_ACR","itemGPS"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","ACE_BB2847","1Rnd_HE_M203","1Rnd_HE_M203","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_Spec3_Wdl_ACR: CZ_Soldier_Spec1_Wdl_ACR
	{
		weapons[] = {"M60A4_EP1","glock17_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD","itemGPS","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","17Rnd_9x19_glock17","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"M60A4_EP1","glock17_EP1","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD","itemGPS","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","HandGrenade_West","IR_Strobe_Target","SmokeShell","SmokeShellRed","17Rnd_9x19_glock17","17Rnd_9x19_glock17"};
	};
	class CZ_Soldier_Spec_Demo_Wdl_ACR: CZ_Soldier_Recon_Wdl_ACR
	{
		backpack = "";
		weapons[] = {"evo_sd_ACR","CZ_75_SP_01_PHANTOM_SD","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","ACE_Rangefinder_OD","ACE_BackPack_ACR"};
		magazines[] = {"20Rnd_9x19_EVOSD","20Rnd_9x19_EVOSD","20Rnd_9x19_EVOSD","20Rnd_9x19_EVOSD","20Rnd_9x19_EVOSD","HandGrenade_West","SmokeShell","SmokeShellRed","Mine","Mine","18Rnd_9x19_PhantomSD","18Rnd_9x19_PhantomSD","18Rnd_9x19_PhantomSD","18Rnd_9x19_PhantomSD","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"evo_sd_ACR","CZ_75_SP_01_PHANTOM_SD","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","ACE_Rangefinder_OD","ACE_BackPack_ACR"};
		respawnMagazines[] = {"20Rnd_9x19_EVOSD","20Rnd_9x19_EVOSD","20Rnd_9x19_EVOSD","HandGrenade_West","SmokeShell","Mine","18Rnd_9x19_PhantomSD","18Rnd_9x19_PhantomSD"};
		class ACE: ACE
		{
			class sys_ruck
			{
				weapons[] = {};
				magazines[] = {"20Rnd_9x19_EVOSD","20Rnd_9x19_EVOSD","20Rnd_9x19_EVOSD","20Rnd_9x19_EVOSD","20Rnd_9x19_EVOSD","20Rnd_9x19_EVOSD","ACE_Battery_Rangefinder","ACE_BB2847","PipeBomb","PipeBomb","HandGrenade_West","IR_Strobe_Target"};
			};
		};
	};
	class CZ_Soldier_Spec_Demo_Dst_ACR: CZ_Soldier_Spec_Demo_Wdl_ACR
	{
		backpack = "";
		weapons[] = {"evo_sd_ACR","CZ_75_SP_01_PHANTOM_SD","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","Binocular_Vector","ACE_BackPack_ACR"};
		respawnWeapons[] = {"evo_sd_ACR","CZ_75_SP_01_PHANTOM_SD","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","Binocular_Vector","ACE_BackPack_ACR"};
	};
	class CZ_Soldier_AT_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		weapons[] = {"CZ805_A2_ACR","CZ_75_P_07_DUTY","MAAWS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","MAAWS_HEAT","MAAWS_HEDP","HandGrenade_West","HandGrenade_West","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"CZ805_A2_ACR","CZ_75_P_07_DUTY","MAAWS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","MAAWS_HEDP","HandGrenade_West","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_RPG_Dst_ACR: CZ_Soldier_Base_ACR
	{
		weapons[] = {"Sa58V_EP1","CZ_75_P_07_DUTY","RPG7V","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","PG7VR","PG7VL","PG7VL","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"Sa58V_EP1","CZ_75_P_07_DUTY","RPG7V","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","PG7VL","PG7VL","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_Engineer_Dst_ACR: CZ_Soldier_Base_ACR
	{
		backpack = "";
		weapons[] = {"evo_mrad_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_BackPack_ACR"};
		magazines[] = {"20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","Mine","Mine","HandGrenade_West","SmokeShell","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"evo_mrad_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_BackPack_ACR"};
		respawnMagazines[] = {"20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","Mine","HandGrenade_West","SmokeShell","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		class ACE: ACE
		{
			class sys_ruck
			{
				weapons[] = {};
				magazines[] = {"20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","20Rnd_9x19_EVO","ACE_Battery_Rangefinder","ACE_BB2847","PipeBomb","PipeBomb","HandGrenade_West","IR_Strobe_Target"};
			};
		};
	};
	class CZ_Soldier_Engineer_Wdl_ACR: CZ_Soldier_Engineer_Dst_ACR
	{
		backpack = "";
	};
	class CZ_Soldier_Sniper_ACR: CZ_Soldier_Base_ACR
	{
		weapons[] = {"CZ_750_S1_ACR","CZ_75_SP_01_PHANTOM_SD","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD","itemGPS"};
		magazines[] = {"10Rnd_762x51_CZ750","10Rnd_762x51_CZ750","10Rnd_762x51_CZ750","10Rnd_762x51_CZ750","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","smokeshellred","18Rnd_9x19_PhantomSD","18Rnd_9x19_PhantomSD","18Rnd_9x19_PhantomSD","18Rnd_9x19_PhantomSD","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"CZ_750_S1_ACR","CZ_75_SP_01_PHANTOM_SD","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD","itemGPS"};
		respawnMagazines[] = {"10Rnd_762x51_CZ750","10Rnd_762x51_CZ750","HandGrenade_West","IR_Strobe_Target","smokeshellred","18Rnd_9x19_PhantomSD","18Rnd_9x19_PhantomSD"};
	};
	class CZ_Soldier_Spotter_ACR: CZ_Soldier_Sniper_ACR
	{
		weapons[] = {"CZ805_A2_SD_ACR","CZ_75_SP_01_PHANTOM_SD","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD","itemGPS"};
		magazines[] = {"30Rnd_556x45_StanagSD","30Rnd_556x45_StanagSD","30Rnd_556x45_StanagSD","30Rnd_556x45_StanagSD","30Rnd_556x45_StanagSD","30Rnd_556x45_StanagSD","30Rnd_556x45_StanagSD","30Rnd_556x45_StanagSD","HandGrenade_West","HandGrenade_West","IR_Strobe_Target","smokeshellred","18Rnd_9x19_PhantomSD","18Rnd_9x19_PhantomSD","18Rnd_9x19_PhantomSD","18Rnd_9x19_PhantomSD","ACE_Battery_Rangefinder"};
		respawnWeapons[] = {"CZ805_A2_SD_ACR","CZ_75_SP_01_PHANTOM_SD","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rangefinder_OD","itemGPS"};
		respawnMagazines[] = {"30Rnd_556x45_StanagSD","30Rnd_556x45_StanagSD","30Rnd_556x45_StanagSD","30Rnd_556x45_StanagSD","HandGrenade_West","IR_Strobe_Target","smokeshellred","18Rnd_9x19_PhantomSD","18Rnd_9x19_PhantomSD"};
	};
	class CZ_Soldier_Light_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		weapons[] = {"Throw","Put","ItemMap","ItemCompass","ItemWatch"};
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put","ItemMap","ItemCompass","ItemWatch"};
		respawnMagazines[] = {};
	};
	class CZ_Soldier_RPG_Ass_Dst_ACR: CZ_Soldier_Base_ACR
	{
		backpack = "CZ_Backpack_RPG_ACR";
		weapons[] = {"Sa58V_EP1","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","PG7VR","PG7VL","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"Sa58V_EP1","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","30Rnd_762x39_SA58","PG7VL","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Soldier_RPG_Ass_Wdl_ACR: CZ_Soldier_RPG_Ass_Dst_ACR
	{
		weapons[] = {"CZ805_A1_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"CZ805_A1_ACR","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_West","SmokeShell","SmokeShellRed","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class CZ_Sharpshooter_DES_ACR: CZ_Soldier_base_EP1
	{
		weapons[] = {"SVD","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","HandGrenade_West","HandGrenade_West","HandGrenade_West","HandGrenade_West","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
		respawnWeapons[] = {"SVD","CZ_75_P_07_DUTY","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","10Rnd_762x54_SVD","HandGrenade_West","HandGrenade_West","ACE_16Rnd_9x19_CZ75","ACE_16Rnd_9x19_CZ75"};
	};
	class UN_CDF_Soldier_base_EP1: SoldierGB{};
	class UN_CDF_Soldier_EP1: UN_CDF_Soldier_base_EP1{};
	class UN_CDF_Soldier_AMG_EP1: UN_CDF_Soldier_EP1
	{
		weapons[] = {"AK_74_GL_kobra","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","HandGrenade_East","HandGrenade_East","HandGrenade_East","HandGrenade_East","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25"};
		respawnWeapons[] = {"AK_74_GL_kobra","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","HandGrenade_East","HandGrenade_East","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25"};
	};
	class UN_CDF_Soldier_AT_EP1: UN_CDF_Soldier_base_EP1
	{
		weapons[] = {"AKS_74_kobra","ACE_RPG7V_PGO7","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","ACE_PG7VL_PGO7","ACE_PG7VM_PGO7","ACE_PG7VM_PGO7"};
		respawnWeapons[] = {"AKS_74_kobra","ACE_RPG7V_PGO7","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","ACE_PG7VL_PGO7","ACE_PG7VM_PGO7"};
	};
	class UN_CDF_Soldier_MG_EP1: UN_CDF_Soldier_base_EP1
	{
		backpack = "";
		weapons[] = {"PK","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","HandGrenade_East","HandGrenade_East"};
		respawnWeapons[] = {"PK","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","HandGrenade_East"};
	};
	class TK_Soldier_base_EP1: SoldierEB{};
	class TK_Soldier_AT_EP1: TK_Soldier_base_EP1
	{
		weapons[] = {"FN_FAL","ACE_RPG7V_PGO7","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","ACE_PG7VL_PGO7","ACE_PG7VM_PGO7","ACE_PG7VM_PGO7"};
		respawnWeapons[] = {"FN_FAL","ACE_RPG7V_PGO7","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","ACE_PG7VL_PGO7","ACE_PG7VM_PGO7"};
	};
	class TK_Soldier_MG_EP1: TK_Soldier_base_EP1
	{
		weapons[] = {"PK","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnWeapons[] = {"PK","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
	};
	class TK_Soldier_AR_EP1: TK_Soldier_base_EP1
	{
		weapons[] = {"RPK_74","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnWeapons[] = {"RPK_74","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
	};
	class TK_Soldier_Engineer_EP1: TK_Soldier_base_EP1
	{
		weapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","ACE_C4_M","ACE_C4_M","ACE_MON50_M","ACE_MON50_M","HandGrenade_East","HandGrenade_East"};
		respawnWeapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","ACE_C4_M","ACE_MON50_M","HandGrenade_East"};
	};
	class TK_Soldier_Medic_EP1: TK_Soldier_base_EP1
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		canCarryBackPack = 1;
		weapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_EAST_Medic"};
		respawnWeapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_EAST_Medic"};
	};
	class TK_Special_Forces_EP1: TK_Soldier_base_EP1
	{
		ACE_Stamina = 0.8;
	};
	class TK_Special_Forces_MG_EP1: TK_Special_Forces_EP1
	{
		weapons[] = {"PK","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Makarov","ACE_Earplugs"};
		respawnWeapons[] = {"PK","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Makarov","ACE_Earplugs"};
	};
	class TK_Soldier_Sniper_EP1;
	class TK_Soldier_SniperH_EP1: TK_Soldier_Sniper_EP1
	{
		weapons[] = {"KSVK","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular","itemGPS","ACE_Earplugs"};
		respawnWeapons[] = {"KSVK","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular","itemGPS","ACE_Earplugs"};
	};
	class TK_INS_Soldier_Base_EP1;
	class TK_INS_Bonesetter_EP1: TK_INS_Soldier_Base_EP1
	{
		weapons[] = {"LeeEnfield","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_EAST_Medic"};
		respawnWeapons[] = {"LeeEnfield","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_EAST_Medic"};
	};
	class TK_INS_Soldier_AT_EP1: TK_INS_Soldier_Base_EP1
	{
		magazines[] = {"30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","PG7V","PG7V"};
		respawnmagazines[] = {"30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","PG7V"};
	};
	class TK_GUE_Soldier_Base_EP1;
	class TK_GUE_Bonesetter_EP1: TK_GUE_Soldier_Base_EP1
	{
		weapons[] = {"LeeEnfield","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_EAST_Medic"};
		respawnWeapons[] = {"LeeEnfield","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_EAST_Medic"};
	};
	class TK_GUE_Soldier_AT_EP1: TK_GUE_Soldier_Base_EP1
	{
		magazines[] = {"30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","PG7V","PG7V"};
		respawnmagazines[] = {"30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","PG7V"};
	};
	class BAF_Soldier_base_EP1;
	class BAF_Soldier_Medic_MTP: BAF_Soldier_base_EP1
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		weapons[] = {"BAF_L85A2_RIS_SUSAT","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_MOLLE_WMARPAT_Medic"};
		respawnWeapons[] = {"BAF_L85A2_RIS_SUSAT","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_MOLLE_WMARPAT_Medic"};
	};
	class BAF_Soldier_EN_MTP: BAF_Soldier_base_EP1
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
	};
	class BAF_Soldier_HAT_MTP: BAF_Soldier_base_EP1
	{
		weapons[] = {"BAF_L85A2_RIS_Holo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Javelin","ACE_Javelin_CLU"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","BAF_L109A1_HE"};
		respawnWeapons[] = {"BAF_L85A2_RIS_Holo","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Javelin","ACE_Javelin_CLU"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","BAF_L109A1_HE"};
	};
	class BAF_Soldier_MG_MTP: BAF_Soldier_base_EP1
	{
		weapons[] = {"BAF_L7A2_GPMG","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnWeapons[] = {"BAF_L7A2_GPMG","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
	};
	class BAF_Soldier_AR_MTP: BAF_Soldier_base_EP1
	{
		weapons[] = {"BAF_L110A1_Aim","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnWeapons[] = {"BAF_L110A1_Aim","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
	};
	class BAF_Soldier_Sniper_MTP;
	class BAF_Soldier_SniperH_MTP: BAF_Soldier_Sniper_MTP
	{
		weapons[] = {"BAF_AS50_scoped","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS","Colt1911","ACE_Earplugs"};
		respawnWeapons[] = {"BAF_AS50_scoped","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS","Colt1911","ACE_Earplugs"};
	};
	class BAF_Soldier_SniperN_MTP: BAF_Soldier_SniperH_MTP
	{
		weapons[] = {"BAF_AS50_TWS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS","Colt1911","ACE_Earplugs"};
		respawnWeapons[] = {"BAF_AS50_TWS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Binocular_Vector","ItemGPS","Colt1911","ACE_Earplugs"};
	};
	class Soldier_Base_PMC;
	class Soldier_Medic_PMC: Soldier_Base_PMC
	{
		cancarrybackpack = 1;
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		weapons[] = {"m8_compact","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_VTAC_RUSH72_FT_MEDIC"};
		respawnWeapons[] = {"m8_compact","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_VTAC_RUSH72_FT_MEDIC"};
	};
	class Soldier_MG_PMC: Soldier_Base_PMC
	{
		weapons[] = {"m8_SAW","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnWeapons[] = {"m8_SAW","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
	};
	class Soldier_MG_PKM_PMC: Soldier_MG_PMC
	{
		weapons[] = {"PK","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnWeapons[] = {"PK","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
	};
	class Soldier_Sniper_PMC;
	class Soldier_Sniper_KSVK_PMC: Soldier_Sniper_PMC
	{
		weapons[] = {"KSVK","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","ACE_Earplugs"};
		respawnWeapons[] = {"KSVK","NVGoggles","Binocular_Vector","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","itemGPS","ACE_Earplugs"};
	};
	class Soldier_Crew_PMC: Soldier_Base_PMC
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
	};
};
//};
