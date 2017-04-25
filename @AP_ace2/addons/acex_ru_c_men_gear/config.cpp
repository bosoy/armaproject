////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 28 16:01:36 2011 : Created on Fri Oct 28 16:01:36 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_men_gear : config.bin{
class CfgPatches
{
	class acex_ru_c_men_gear
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_ru_main","CACharacters","CACharacters2","ace_main","ace_sys_ruck","ace_c_men_gear","acex_c_vehicle"};
		version = "1.12.0.62";
	};
};
class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class HitPoints
		{
			class HitHead;
		};
	};
	class SoldierWB: CAManBase{};
	class SoldierEB: CAManBase{};
	class SoldierGB: CAManBase{};
	class RU_Soldier_Base: SoldierEB
	{
		weapons[] = {"ACE_AK74M","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_AK74M","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class RU_Soldier: RU_Soldier_Base
	{
		weapons[] = {"ACE_AK74M","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_AK74M","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class RU_Soldier_Medic: RU_Soldier_Base
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
	};
	class RU_Soldier_AR: RU_Soldier_Base
	{
		weapons[] = {"ACE_RPK74M","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnWeapons[] = {"ACE_RPK74M","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class RU_Soldier_MG: RU_Soldier_Base
	{
		weapons[] = {"PK","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
		respawnWeapons[] = {"PK","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
	};
	class RU_Soldier_GL: RU_Soldier_Base
	{
		weapons[] = {"ACE_AK74M_GL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_AK74M_GL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class RU_Soldier_SL: RU_Soldier_Base
	{
		weapons[] = {"ACE_AK74M_PSO","ItemGPS","Binocular","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Makarov"};
		respawnWeapons[] = {"ACE_AK74M_PSO","ItemGPS","Binocular","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","Makarov"};
	};
	class RU_Soldier_TL: RU_Soldier_Base
	{
		weapons[] = {"ACE_AK74M_GL_Kobra","ItemGPS","Binocular","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_AK74M_GL_Kobra","ItemGPS","Binocular","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class RU_Soldier_LAT: RU_Soldier_Base
	{
		weapons[] = {"ACE_AK74M","RPG18","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_AK74M","RPG18","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class RU_Soldier_AT: RU_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_ATSPECIALIST";
		weapons[] = {"ACE_AK74M","ACE_RPG7V_PGO7","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_AK74M","ACE_RPG7V_PGO7","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class RU_Soldier_HAT: RU_Soldier_Base
	{
		weapons[] = {"ACE_AK74M","NVGoggles","MetisLauncher","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_AK74M","NVGoggles","MetisLauncher","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class RU_Soldier_AA: RU_Soldier_Base
	{
		weapons[] = {"ACE_AK74M","NVGoggles","Igla","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_AK74M","NVGoggles","Igla","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class RU_Soldier_Spotter: RU_Soldier_Base
	{
		weapons[] = {"ACE_AK74M_PSO","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_AK74M_PSO","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class MVD_Soldier_Base: SoldierEB
	{
		weapons[] = {"ACE_AK105_Kobra","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"ACE_AK105_Kobra","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class MVD_Soldier: MVD_Soldier_Base
	{
		weapons[] = {"ACE_AK105_Kobra","ItemGPS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","HandGrenade_East","HandGrenade_East","HandGrenade_East","HandGrenade_East","ACE_RDGM","SmokeShellOrange"};
		respawnWeapons[] = {"ACE_AK105_Kobra","ItemGPS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","HandGrenade_East","HandGrenade_East","ACE_RDGM","SmokeShellOrange"};
	};
	class MVD_Soldier_GL: MVD_Soldier_Base
	{
		weapons[] = {"ACE_AKS74P_GL_Kobra","ItemGPS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_RDGM","SmokeShellOrange","ACE_1Rnd_HE_GP25P","ACE_1Rnd_HE_GP25P","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25"};
		respawnWeapons[] = {"ACE_AKS74P_GL_Kobra","ItemGPS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_RDGM","SmokeShellOrange","ACE_1Rnd_HE_GP25P","ACE_1Rnd_HE_GP25P","1Rnd_HE_GP25","1Rnd_HE_GP25"};
	};
	class MVD_Soldier_TL: MVD_Soldier_Base
	{
		weapons[] = {"ACE_AKS74P_GL_PSO","ItemGPS","Binocular","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","HandGrenade_East","HandGrenade_East","SmokeShellOrange","SmokeShellBlue","ACE_1Rnd_HE_GP25P","ACE_1Rnd_HE_GP25P","ACE_1Rnd_HE_GP25P","ACE_1Rnd_HE_GP25P","1Rnd_SMOKE_GP25","1Rnd_SMOKE_GP25","FlareWhite_GP25","FlareRed_GP25"};
		respawnWeapons[] = {"ACE_AKS74P_GL_PSO","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","HandGrenade_East","SmokeShellOrange","SmokeShellBlue","ACE_1Rnd_HE_GP25P","ACE_1Rnd_HE_GP25P","1Rnd_SMOKE_GP25","1Rnd_SMOKE_GP25","FlareWhite_GP25","FlareRed_GP25"};
	};
	class MVD_Soldier_AT: MVD_Soldier_Base
	{
		weapons[] = {"ACE_AK105_Kobra","ItemGPS","ACE_RPG7V_PGO7","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_PG7VL_PGO7","ACE_PG7VL_PGO7","ACE_OG7_PGO7"};
		respawnWeapons[] = {"ACE_AK105_Kobra","ItemGPS","ACE_RPG7V_PGO7","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_PG7VL_PGO7","ACE_OG7_PGO7"};
	};
	class MVD_Soldier_MG: MVD_Soldier
	{
		weapons[] = {"Pecheneg","ItemGPS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","HandGrenade_East","HandGrenade_East"};
		respawnWeapons[] = {"Pecheneg","ItemGPS","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","HandGrenade_East"};
	};
	class RUS_Soldier_Base: SoldierEB{};
	class RUS_Soldier1: RUS_Soldier_Base
	{
		weapons[] = {"ACE_AK74M_SD_1P78","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_30Rnd_545x39_AP_S_AK","ACE_30Rnd_545x39_AP_S_AK","ACE_30Rnd_545x39_AP_S_AK","ACE_30Rnd_545x39_AP_S_AK","ACE_30Rnd_545x39_AP_S_AK","ACE_30Rnd_545x39_AP_S_AK","ACE_30Rnd_545x39_AP_S_AK","HandGrenade_East","HandGrenade_East","HandGrenade_East","PipeBomb"};
		respawnWeapons[] = {"ACE_AK74M_SD_1P78","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_30Rnd_545x39_AP_S_AK","ACE_30Rnd_545x39_AP_S_AK","ACE_30Rnd_545x39_AP_S_AK","ACE_30Rnd_545x39_AP_S_AK","ACE_30Rnd_545x39_AP_S_AK","HandGrenade_East","HandGrenade_East","PipeBomb"};
	};
	class RUS_Soldier2: RUS_Soldier1
	{
		weapons[] = {"ACE_Val_Kobra","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_20Rnd_9x39_SP6_VSS","ACE_20Rnd_9x39_SP6_VSS","ACE_20Rnd_9x39_SP6_VSS","ACE_20Rnd_9x39_SP6_VSS","ACE_20Rnd_9x39_SP6_VSS","ACE_20Rnd_9x39_SP6_VSS","ACE_20Rnd_9x39_SP6_VSS","HandGrenade_East","HandGrenade_East","HandGrenade_East","PipeBomb"};
		respawnWeapons[] = {"ACE_Val","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_20Rnd_9x39_SP6_VSS","ACE_20Rnd_9x39_SP6_VSS","ACE_20Rnd_9x39_SP6_VSS","ACE_20Rnd_9x39_SP6_VSS","ACE_20Rnd_9x39_SP6_VSS","HandGrenade_East","HandGrenade_East","PipeBomb"};
	};
	class RUS_Soldier3: RUS_Soldier_Base
	{
		weapons[] = {"ACE_AKS74_UN","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_30Rnd_545x39_EP_S_AK","ACE_30Rnd_545x39_EP_S_AK","ACE_30Rnd_545x39_EP_S_AK","ACE_30Rnd_545x39_EP_S_AK","ACE_30Rnd_545x39_EP_S_AK","ACE_30Rnd_545x39_EP_S_AK","HandGrenade_East","HandGrenade_East","ACE_RDGM","SmokeShellOrange","SmokeShellBlue"};
		respawnWeapons[] = {"ACE_AKS74_UN","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_30Rnd_545x39_EP_S_AK","ACE_30Rnd_545x39_EP_S_AK","ACE_30Rnd_545x39_EP_S_AK","ACE_30Rnd_545x39_EP_S_AK","ACE_RDGM","SmokeShellOrange","SmokeShellBlue"};
	};
	class RUS_Soldier_GL: RUS_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_RUS_SOLDIER_GL";
		weapons[] = {"ACE_AK74M_GL_Kobra","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_RPG22"};
		magazines[] = {"ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","HandGrenade_East","HandGrenade_East","ACE_RDGM","SmokeShellOrange","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","ACE_RPG22"};
		respawnWeapons[] = {"ACE_AK74M_GL_Kobra","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_RPG22"};
		respawnMagazines[] = {"ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","HandGrenade_East","HandGrenade_East","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","ACE_RPG22"};
	};
	class RUS_Soldier_TL: RUS_Soldier_Base
	{
		weapons[] = {"ACE_AK74M_GL_PSO","ItemGPS","Binocular","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","HandGrenade_East","HandGrenade_East","ACE_RDGM","SmokeShellBlue","SmokeShellOrange","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25"};
		respawnWeapons[] = {"ACE_AK74M_GL_PSO","ItemGPS","Binocular","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_30Rnd_545x39_AP_AK","ACE_RDGM","SmokeShellBlue","SmokeShellOrange","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25","1Rnd_HE_GP25"};
	};
	class RUS_Commander: RUS_Soldier_Base
	{
		weapons[] = {"ACE_AK105_Kobra","ItemGPS","Binocular","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","MakarovSD"};
		magazines[] = {"ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","HandGrenade_East","HandGrenade_East","ACE_RDGM","SmokeShellBlue","SmokeShellOrange","8Rnd_9x18_MakarovSD","8Rnd_9x18_MakarovSD","8Rnd_9x18_MakarovSD","8Rnd_9x18_MakarovSD"};
		respawnWeapons[] = {"ACE_AK105_Kobra","ItemGPS","Binocular","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","MakarovSD"};
		respawnMagazines[] = {"ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_30Rnd_545x39_EP_AK","ACE_RDGM","SmokeShellBlue","SmokeShellOrange","8Rnd_9x18_MakarovSD","8Rnd_9x18_MakarovSD"};
	};
	class RUS_Soldier_Marksman: RUS_Soldier_Base
	{
		weapons[] = {"VSS_vintorez","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","MakarovSD"};
		magazines[] = {"20Rnd_9x39_SP5_VSS","20Rnd_9x39_SP5_VSS","20Rnd_9x39_SP5_VSS","20Rnd_9x39_SP5_VSS","20Rnd_9x39_SP5_VSS","20Rnd_9x39_SP5_VSS","20Rnd_9x39_SP5_VSS","HandGrenade_East","HandGrenade_East","ACE_RDGM","SmokeShellOrange","8Rnd_9x18_MakarovSD","8Rnd_9x18_MakarovSD","8Rnd_9x18_MakarovSD","8Rnd_9x18_MakarovSD"};
		respawnWeapons[] = {"VSS_vintorez","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","MakarovSD"};
		respawnMagazines[] = {"20Rnd_9x39_SP5_VSS","20Rnd_9x39_SP5_VSS","20Rnd_9x39_SP5_VSS","20Rnd_9x39_SP5_VSS","ACE_RDGM","SmokeShellOrange","8Rnd_9x18_MakarovSD","8Rnd_9x18_MakarovSD"};
	};
	class RUS_Soldier_Sab: RUS_Soldier_Base
	{
		weapons[] = {"bizon_silenced","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_EAST"};
		magazines[] = {"64Rnd_9x19_Bizon","64Rnd_9x19_Bizon","64Rnd_9x19_Bizon","64Rnd_9x19_Bizon","64Rnd_9x19_Bizon","ACE_Pomz_M","ACE_Pomz_M","PipeBomb","PipeBomb","ACE_RDGM","SmokeShellBlue"};
		respawnWeapons[] = {"bizon_silenced","ItemGPS","NVGoggles","Binocular","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_EAST"};
		respawnMagazines[] = {"64Rnd_9x19_Bizon","64Rnd_9x19_Bizon","64Rnd_9x19_Bizon","ACE_Pomz_M","ACE_Pomz_M","PipeBomb","ACE_RDGM","SmokeShellBlue"};
	};
	class Ins_Soldier_Base: SoldierEB{};
	class Ins_Soldier_Medic: Ins_Soldier_Base
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
	};
	class Ins_Soldier_AT: Ins_Soldier_Base
	{
		weapons[] = {"AK_47_M","ACE_RPG7V_PGO7","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","ACE_PG7VL_PGO7","ACE_PG7VM_PGO7","ACE_PG7VM_PGO7"};
		respawnWeapons[] = {"AK_47_M","ACE_RPG7V_PGO7","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","ACE_PG7VL_PGO7","ACE_PG7VM_PGO7"};
	};
	class CDF_Soldier_Base: SoldierWB{};
	class CDF_Soldier: CDF_Soldier_Base{};
	class CDF_Soldier_Light: CDF_Soldier_Base{};
	class CDF_Soldier_AR: CDF_Soldier_Base
	{
		weapons[] = {"RPK_74","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"75Rnd_545x39_RPK","75Rnd_545x39_RPK","75Rnd_545x39_RPK","75Rnd_545x39_RPK","75Rnd_545x39_RPK","75Rnd_545x39_RPK","75Rnd_545x39_RPK","75Rnd_545x39_RPK","HandGrenade_East","HandGrenade_East","SmokeShell","SmokeShell"};
		respawnWeapons[] = {"RPK_74","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"75Rnd_545x39_RPK","75Rnd_545x39_RPK","75Rnd_545x39_RPK","75Rnd_545x39_RPK","75Rnd_545x39_RPK","75Rnd_545x39_RPK","HandGrenade_East","SmokeShell"};
	};
	class CDF_Soldier_MG: CDF_Soldier_Base
	{
		weapons[] = {"PK","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
		respawnWeapons[] = {"PK","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
	};
	class CDF_Soldier_Medic: CDF_Soldier_Base
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
	};
	class CDF_Soldier_RPG: CDF_Soldier_Base
	{
		weapons[] = {"AK_74","ACE_RPG7V_PGO7","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","ACE_PG7VL_PGO7","ACE_PG7VM_PGO7","ACE_PG7VM_PGO7"};
		respawnWeapons[] = {"AK_74","ACE_RPG7V_PGO7","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","ACE_PG7VL_PGO7","ACE_PG7VM_PGO7"};
	};
	class GUE_Soldier_Base: SoldierGB{};
	class GUE_Soldier_Medic: GUE_Soldier_Base{};
	class GUE_Soldier_AT: GUE_Soldier_Base
	{
		weapons[] = {"AK_47_M","ACE_RPG7V_PGO7","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","ACE_PG7VL_PGO7","ACE_PG7VM_PGO7","ACE_PG7VM_PGO7"};
		respawnWeapons[] = {"AK_47_M","ACE_RPG7V_PGO7","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","ACE_PG7VL_PGO7","ACE_PG7VM_PGO7"};
	};
};
//};
