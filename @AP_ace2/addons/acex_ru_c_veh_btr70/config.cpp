////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:39:48 2012 : Created on Fri Nov 09 22:39:48 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_btr70 : config.bin{
class CfgPatches
{
	class acex_ru_veh_btr70
	{
		units[] = {"ACE_BTR70_RU","ACE_BTR70_CDF","ACE_BTR70_INS","ACE_BTR70_GUE"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CATracked","Extended_EventHandlers","acex_ru_main","acex_veh_btr70","acex_m_veh_btr70","acex_t_veh_btr70","acex_ru_t_veh_btr70","rhs_decals"};
		version = "1.14.0.76";
		author[] = {"Manfred and Soul Assassin (RHS)"};
		authorUrl = "http://forums.bistudio.com/showthread.php?t=106906";
	};
};
class WeaponCloudsMGun;
class CfgVehicles
{
	class ACE_BTR70_Base;
	class ACE_BTR70_RU: ACE_BTR70_Base
	{
		scope = 2;
		faction = "RU";
		crew = "RU_Soldier_Crew";
		typicalCargo[] = {"RU_Soldier_Crew","RU_Soldier_Crew","RU_Soldier_Crew","RU_Soldier","RU_Soldier_MG","RU_Soldier_AT"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_btr70\btr70_tri1_1_co.paa","\x\acex_ru\addons\t_veh_btr70\btr70_tri1_2_co.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa"};
	};
	class ACE_BTR70_RU_D: ACE_BTR70_Base
	{
		scope = 2;
		faction = "RU";
		vehicleClass = "ArmouredD";
		crew = "ACE_RU_Soldier_Crew_D";
		typicalCargo[] = {"ACE_RU_Soldier_Crew_D","ACE_RU_Soldier_Crew_D","ACE_RU_Soldier_Crew_D","ACE_RU_Soldier_D","ACE_RU_Soldier_MG_D","ACE_RU_Soldier_AT_D"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_btr70\btr70_des_1_co.paa","\x\acex_ru\addons\t_veh_btr70\btr70_des_2_co.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa"};
	};
	class ACE_BTR70_CDF: ACE_BTR70_Base
	{
		scope = 2;
		side = 1;
		faction = "CDF";
		crew = "CDF_Soldier_Crew";
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_btr70\btr70_CDF_1_co.paa","\x\acex_ru\addons\t_veh_btr70\btr70_CDF_2_co.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa"};
	};
	class ACE_BTR70_INS: ACE_BTR70_Base
	{
		scope = 2;
		faction = "INS";
		crew = "INS_Soldier_Crew";
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_btr70\btr70_chdkz_1_co.paa","\x\acex_ru\addons\t_veh_btr70\btr70_chdkz_2_co.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa"};
	};
	class ACE_BTR70_GUE: ACE_BTR70_Base
	{
		scope = 2;
		side = 2;
		faction = "GUE";
		crew = "GUE_Soldier_Crew";
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_btr70\btr70_napa_1_co.paa","\x\acex_ru\addons\t_veh_btr70\btr70_napa_2_co.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa"};
	};
};
class CfgGroups
{
	class West
	{
		class CDF
		{
			class Mechanized
			{
				class ACE_CDF_Mechanized_Squad_BTR70
				{
					name = "$STR_ACE_GDN_ACE_CDF_MECHANIZED_SQUAD_BTR70";
					faction = "CDF";
					rarityGroup = 0.9;
					class Unit0
					{
						side = 1;
						vehicle = "CDF_Soldier_TL";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_BTR70_CDF";
						rank = "SERGEANT";
						position[] = {-5,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "CDF_Soldier_MG";
						rank = "SERGEANT";
						position[] = {3,0,0};
					};
					class Unit3
					{
						side = 1;
						vehicle = "CDF_Soldier_MG";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit4
					{
						side = 1;
						vehicle = "CDF_Soldier_Marksman";
						rank = "CORPORAL";
						position[] = {7,0,0};
					};
					class Unit5
					{
						side = 1;
						vehicle = "CDF_Soldier_RPG";
						rank = "PRIVATE";
						position[] = {9,0,0};
					};
					class Unit6
					{
						side = 1;
						vehicle = "CDF_Soldier_GL";
						rank = "PRIVATE";
						position[] = {11,0,0};
					};
					class Unit7
					{
						side = 1;
						vehicle = "CDF_Soldier";
						rank = "PRIVATE";
						position[] = {13,0,0};
					};
				};
			};
		};
	};
	class East
	{
		class RU
		{
			class Mechanized
			{
				class RU_MechInfSquad_2
				{
					name = "$STR_ACE_GDN_RU_MECHINFSQUAD_2";
				};
				class ACE_RU_Mechanized_Squad_BTR70
				{
					name = "$STR_ACE_GDN_ACE_RU_MECHANIZED_SQUAD_BTR70";
					faction = "RU";
					rarityGroup = 0.9;
					class Unit0
					{
						side = 0;
						vehicle = "RU_Soldier_SL";
						rank = "LIEUTENANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_BTR70_RU";
						rank = "SERGEANT";
						position[] = {-5,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "RU_Soldier_MG";
						rank = "SERGEANT";
						position[] = {3,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "RU_Soldier_MG";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit4
					{
						side = 0;
						vehicle = "RU_Soldier_AT";
						rank = "CORPORAL";
						position[] = {7,0,0};
					};
					class Unit5
					{
						side = 0;
						vehicle = "RU_Soldier_LAT";
						rank = "PRIVATE";
						position[] = {9,0,0};
					};
					class Unit6
					{
						side = 0;
						vehicle = "RU_Soldier_GL";
						rank = "PRIVATE";
						position[] = {11,0,0};
					};
					class Unit7
					{
						side = 0;
						vehicle = "RU_Soldier_Marksman";
						rank = "PRIVATE";
						position[] = {11,0,0};
					};
					class Unit8
					{
						side = 0;
						vehicle = "RU_Soldier";
						rank = "PRIVATE";
						position[] = {11,0,0};
					};
				};
			};
		};
		class INS
		{
			class Mechanized
			{
				class ACE_INS_Mechanized_Squad_BTR70
				{
					name = "$STR_ACE_GDN_ACE_INS_MECHANIZED_SQUAD_BTR70";
					faction = "INS";
					rarityGroup = 0.25;
					class Unit0
					{
						side = 0;
						vehicle = "INS_Soldier_CO";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_BTR70_INS";
						rank = "SERGEANT";
						position[] = {-5,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "INS_Soldier_MG";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "INS_Soldier_AT";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit4
					{
						side = 0;
						vehicle = "INS_Soldier_2";
						rank = "CORPORAL";
						position[] = {7,0,0};
					};
					class Unit5
					{
						side = 0;
						vehicle = "INS_Soldier_GL";
						rank = "CORPORAL";
						position[] = {9,0,0};
					};
					class Unit6
					{
						side = 0;
						vehicle = "INS_Soldier_1";
						rank = "PRIVATE";
						position[] = {11,0,0};
					};
					class Unit7
					{
						side = 0;
						vehicle = "INS_Soldier_AR";
						rank = "PRIVATE";
						position[] = {13,0,0};
					};
				};
			};
		};
	};
	class Guerrila
	{
		class GUE
		{
			class Mechanized
			{
				class ACE_GUE_Mechanized_Squad_BTR70
				{
					name = "$STR_ACE_GDN_ACE_GUE_MECHANIZED_SQUAD_BTR70";
					faction = "GUE";
					rarityGroup = 0.05;
					class Unit0
					{
						side = 2;
						vehicle = "GUE_Soldier_CO";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 2;
						vehicle = "ACE_BTR70_GUE";
						rank = "CORPORAL";
						position[] = {-5,0,0};
					};
					class Unit2
					{
						side = 2;
						vehicle = "GUE_Soldier_MG";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit3
					{
						side = 2;
						vehicle = "GUE_Soldier_GL";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit4
					{
						side = 2;
						vehicle = "GUE_Soldier_3";
						rank = "CORPORAL";
						position[] = {7,0,0};
					};
					class Unit5
					{
						side = 2;
						vehicle = "GUE_Soldier_AR";
						rank = "PRIVATE";
						position[] = {9,0,0};
					};
					class Unit6
					{
						side = 2;
						vehicle = "GUE_Soldier_Sniper";
						rank = "PRIVATE";
						position[] = {11,0,0};
					};
					class Unit7
					{
						side = 2;
						vehicle = "GUE_Soldier_AT";
						rank = "PRIVATE";
						position[] = {13,0,0};
					};
				};
			};
		};
	};
};
//};
