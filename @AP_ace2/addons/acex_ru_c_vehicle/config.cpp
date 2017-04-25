////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:55:17 2011 : Created on Fri Oct 21 13:55:17 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_vehicle : config.bin{
class CfgPatches
{
	class acex_ru_c_vehicle
	{
		units[] = {"ACE_Offroad_SPG9_INS","ACE_UAZ_SPG9_CDF","ACE_ZSU_RU","ACE_Ural_RU","ACE_UralOpen_RU","ACE_UralRepair_RU","ACE_UralReammo_RU","ACE_UralRefuel_RU","ACE_Ural_ZU23_RU"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CAWheeled","CAWheeled3","CATracked","CAWheeled_E_Ural","CATracked_E_ZSU","acex_ru_main","ace_c_vehicle","ace_sys_crewserved"};
		version = "1.12.0.61";
	};
};
class CfgFactionClasses
{
	class Default
	{
		primaryLanguage = "EN";
	};
	class USMC
	{
		priority = 1;
		primaryLanguage = "EN";
	};
	class RU
	{
		priority = 3;
		ACE_Language = "Russian";
		primaryLanguage = "RU";
	};
	class ACE_VDV
	{
		displayName = "$STR_ACE_FAC_OPFOR_VDV";
		priority = 4;
		side = 0;
		ACE_Language = "Russian";
		primaryLanguage = "RU";
	};
	class ACE_GRU
	{
		displayName = "$STR_ACE_FAC_OPFOR_GRU";
		priority = 5;
		side = 0;
		ACE_Language = "Russian";
		primaryLanguage = "RU";
	};
	class ACE_MVD
	{
		displayName = "$STR_ACE_FAC_OPFOR_MVD";
		priority = 6;
		side = 0;
		ACE_Language = "Russian";
		primaryLanguage = "RU";
	};
	class ACE_RU_Desert
	{
		displayName = "$STR_ACE_FAC_OPFOR_D";
		priority = 7;
		side = 0;
		ACE_Language = "Russian";
		primaryLanguage = "RU";
	};
	class INS
	{
		priority = 8;
		primaryLanguage = "RU";
	};
	class CDF
	{
		priority = 9;
		primaryLanguage = "CZ";
	};
	class GUE
	{
		priority = 10;
		primaryLanguage = "CZ";
	};
	class CIV
	{
		priority = 11;
		primaryLanguage = "CZ";
	};
	class CIV_RU
	{
		priority = 12;
		primaryLanguage = "RU";
	};
	class None
	{
		primaryLanguage = "EN";
	};
};
class CfgVehicles
{
	class Helicopter;
	class Ural_Base;
	class ACE_Ural_RU: Ural_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		accuracy = 0.5;
		crew = "RU_Soldier";
		typicalCargo[] = {"RU_Soldier","RU_Soldier"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_ural\ural_kabina_co.paa","\x\acex_ru\addons\t_veh_ural\ural_plachta_co.paa"};
	};
	class UralOpen_Base;
	class ACE_UralOpen_RU: UralOpen_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		accuracy = 0.5;
		crew = "RU_Soldier";
		typicalCargo[] = {"RU_Soldier","RU_Soldier"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_ural\ural_kabina_co.paa","\x\acex_ru\addons\t_veh_ural\ural_open_co.paa"};
	};
	class UralRepair_Base;
	class ACE_UralRepair_RU: UralRepair_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		accuracy = 0.5;
		crew = "RU_Soldier";
		typicalCargo[] = {"RU_Soldier","RU_Soldier"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_ural\ural_kabina_co.paa","\x\acex_ru\addons\t_veh_ural\ural_repair_co.paa"};
	};
	class UralReammo_Base;
	class ACE_UralReammo_RU: UralReammo_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		accuracy = 0.5;
		crew = "RU_Soldier";
		typicalCargo[] = {"RU_Soldier","RU_Soldier"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_ural\ural_kabina_co.paa","\x\acex_ru\addons\t_veh_ural\ural_ammo_co.paa"};
	};
	class UralRefuel_Base;
	class ACE_UralRefuel_RU: UralRefuel_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		accuracy = 0.5;
		crew = "RU_Soldier";
		typicalCargo[] = {"RU_Soldier","RU_Soldier"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_ural\ural_kabina_co.paa","\x\acex_ru\addons\t_veh_ural\ural_open_co.paa","\ca\wheeled\data\ural_fuel_chdkz_co.paa"};
	};
	class Ural_ZU23_Base;
	class ACE_Ural_ZU23_RU: Ural_ZU23_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		accuracy = 0.5;
		crew = "RU_Soldier";
		typicalCargo[] = {"RU_Soldier","RU_Soldier"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_ural\ural_kabina_co.paa","\x\acex_ru\addons\t_veh_ural\ural_open_co.paa"};
	};
	class ZSU_Base;
	class ACE_ZSU_RU: ZSU_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		displayName = "$STR_ACE_VDN_ZSU_M";
		accuracy = 0.5;
		crew = "RU_Soldier_Crew";
		typicalCargo[] = {"RU_Soldier_Crew","RU_Soldier_Crew","RU_Soldier_Crew"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_zsu\zsu_01_ru_co.paa","\x\acex_ru\addons\t_veh_zsu\zsu_02_ru_co.paa","\x\acex_ru\addons\t_veh_zsu\zsu_03_ru_co.paa"};
	};
	class StaticATWeapon;
	class ACE_Konkurs: StaticATWeapon
	{
		scope = 2;
	};
	class M2HD_mini_TriPod;
	class ACE_M240_Tripod: M2HD_mini_TriPod
	{
		scope = 2;
	};
	class ACE_CSW_Box_Base;
	class ACE_CSW_Box_KONKURS: ACE_CSW_Box_Base
	{
		scope = 2;
	};
};
//};
