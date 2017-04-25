////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 28 16:01:37 2011 : Created on Fri Oct 28 16:01:37 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_men_naval : config.bin{
class CfgPatches
{
	class acex_ru_men_naval
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_ru_main","CACharacters","CACharacters2","ace_main","ace_sys_ruck","ace_c_men_gear","acex_c_vehicle","acex_ru_c_vehicle","acex_ru_c_men_gear","acex_ru_m_men_naval","acex_ru_t_men_naval"};
		version = "1.12.0.62";
	};
};
class CfgVehicles
{
	class SoldierEB;
	class RU_Soldier_Base: SoldierEB
	{
		vehicleClass = "MenW";
	};
	class RU_Soldier;
	class ACE_RU_Soldier_D: RU_Soldier
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class RU_Soldier2;
	class ACE_RU_Soldier2_D: RU_Soldier2
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class RU_Soldier_GL;
	class ACE_RU_Soldier_GL_D: RU_Soldier_GL
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class RU_Soldier_Light;
	class ACE_RU_Soldier_Light_D: RU_Soldier_Light
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier_Light";
	};
	class RU_Soldier_Officer;
	class ACE_RU_Soldier_Officer_D: RU_Soldier_Officer
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier_CO";
	};
	class RU_Soldier_SL;
	class ACE_RU_Soldier_SL_D: RU_Soldier_SL
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier_CO";
	};
	class RU_Soldier_TL;
	class ACE_RU_Soldier_TL_D: RU_Soldier_TL
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class RU_Soldier_MG;
	class ACE_RU_Soldier_MG_D: RU_Soldier_MG
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class RU_Soldier_AR;
	class ACE_RU_Soldier_AR_D: RU_Soldier_AR
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class RU_Soldier_LAT;
	class ACE_RU_Soldier_LAT_D: RU_Soldier_LAT
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class RU_Soldier_AT;
	class ACE_RU_Soldier_AT_D: RU_Soldier_AT
	{
		scope = 2;
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier_AT";
	};
	class RU_Soldier_HAT;
	class ACE_RU_Soldier_HAT_D: RU_Soldier_HAT
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class RU_Soldier_AA;
	class ACE_RU_Soldier_AA_D: RU_Soldier_AA
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class RU_Soldier_Marksman;
	class ACE_RU_Soldier_Marksman_D: RU_Soldier_Marksman
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class RU_Soldier_Medic;
	class ACE_RU_Soldier_Medic_D: RU_Soldier_Medic
	{
		scope = 2;
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class RU_Soldier_Pilot;
	class ACE_RU_Soldier_Pilot_D: RU_Soldier_Pilot
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier_Pilot";
	};
	class RU_Soldier_Crew;
	class ACE_RU_Soldier_Crew_D: RU_Soldier_Crew
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier_Crew";
	};
	class RU_Soldier_Sniper;
	class ACE_RU_Soldier_Sniper_D: RU_Soldier_Sniper
	{
		vehicleClass = "MenDDPM";
		model = "\ca\characters_E\Ghillie\Ghillie_Overall";
		hiddenSelectionsTextures[] = {"\ca\characters_E\Ghillie\Data\ghillie_overall1_desert_co.paa"};
	};
	class RU_Soldier_SniperH;
	class ACE_RU_Soldier_SniperH_D: RU_Soldier_SniperH
	{
		vehicleClass = "MenDDPM";
		model = "\ca\characters_E\Ghillie\Ghillie_Overall";
		hiddenSelectionsTextures[] = {"\ca\characters_E\Ghillie\Data\ghillie_overall1_desert_co.paa"};
	};
	class RU_Soldier_Spotter;
	class ACE_RU_Soldier_Spotter_D: RU_Soldier_Spotter
	{
		vehicleClass = "MenDDPM";
		model = "\ca\characters_E\Ghillie\Ghillie_Overall";
		hiddenSelectionsTextures[] = {"\ca\characters_E\Ghillie\Data\ghillie_overall1_desert_co.paa"};
	};
	class RU_Commander;
	class ACE_RU_Commander_D: RU_Commander
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\DCommander";
	};
	class ACE_RU_Soldier_RPOM;
	class ACE_RU_Soldier_RPOM_D: ACE_RU_Soldier_RPOM
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class ACE_SoldierE_KonkursG;
	class ACE_SoldierE_KonkursG_D: ACE_SoldierE_KonkursG
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class ACE_SoldierE_KonkursAG;
	class ACE_SoldierE_KonkursAG_D: ACE_SoldierE_KonkursAG
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
	class ACE_RU_Soldier_Engineer;
	class ACE_RU_Soldier_Engineer_D: ACE_RU_Soldier_Engineer
	{
		vehicleClass = "MenDDPM";
		model = "\x\acex_ru\addons\m_men_naval\dsoldier";
	};
};
class CfgGroups
{
	class East
	{
		class ACE_Naval_Infantry_RU
		{
			name = "$STR_ACE_FAC_OPFOR_D";
			class Infantry
			{
				name = "$STR_CfgGroups_East_RU_Infantry";
				class ACE_RU_InfSquad_D
				{
					name = "$STR_CfgGroups_East_RU_Infantry_RU_InfSquad";
					faction = "ACE_RU_Desert";
					rarityGroup = 0.7;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_SL_D";
						rank = "LIEUTENANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_MG_D";
						rank = "SERGEANT";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AT_D";
						rank = "SERGEANT";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_LAT_D";
						rank = "CORPORAL";
						position[] = {7,0,0};
					};
					class Unit4
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_GL_D";
						rank = "CORPORAL";
						position[] = {9,0,0};
					};
					class Unit5
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_Marksman_D";
						rank = "CORPORAL";
						position[] = {11,0,0};
					};
					class Unit6
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_MG_D";
						rank = "CORPORAL";
						position[] = {13,0,0};
					};
					class Unit7
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AT_D";
						rank = "CORPORAL";
						position[] = {15,0,0};
					};
					class Unit8
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AR_D";
						rank = "PRIVATE";
						position[] = {17,0,0};
					};
					class Unit9
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_LAT_D";
						rank = "PRIVATE";
						position[] = {19,0,0};
					};
					class Unit10
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_GL_D";
						rank = "PRIVATE";
						position[] = {21,0,0};
					};
					class Unit11
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_D";
						rank = "PRIVATE";
						position[] = {23,0,0};
					};
				};
				class ACE_RU_InfSection_D
				{
					name = "$STR_CfgGroups_East_RU_Infantry_RU_InfSection";
					faction = "ACE_RU_Desert";
					rarityGroup = 0.2;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_TL_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AR_D";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AT_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_GL_D";
						rank = "PRIVATE";
						position[] = {7,0,0};
					};
					class Unit4
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_D";
						rank = "PRIVATE";
						position[] = {9,0,0};
					};
				};
				class ACE_RU_InfSection_AT_D
				{
					name = "$STR_CfgGroups_East_RU_Infantry_RU_InfSection_AT";
					faction = "ACE_RU_Desert";
					rarityGroup = 0.2;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_HAT_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_HAT_D";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AT_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AT_D";
						rank = "PRIVATE";
						position[] = {7,0,0};
					};
					class Unit4
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_D";
						rank = "PRIVATE";
						position[] = {9,0,0};
					};
				};
				class ACE_RU_InfSection_AA_D
				{
					name = "$STR_CfgGroups_East_RU_Infantry_RU_InfSection_AA";
					faction = "ACE_RU_Desert";
					rarityGroup = 0.1;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AA_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AA_D";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AA_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
				};
				class ACE_RU_InfSection_MG_D
				{
					name = "$STR_CfgGroups_East_RU_Infantry_RU_InfSection_MG";
					faction = "ACE_RU_Desert";
					rarityGroup = 0.2;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_TL_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_MG_D";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_MG_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_GL_D";
						rank = "PRIVATE";
						position[] = {7,0,0};
					};
					class Unit4
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AT_D";
						rank = "PRIVATE";
						position[] = {9,0,0};
					};
				};
				class ACE_RU_SniperTeam_D
				{
					name = "$STR_CfgGroups_East_RU_Infantry_RU_SniperTeam";
					faction = "ACE_RU_Desert";
					rarityGroup = 0.05;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_Sniper_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_Spotter_D";
						rank = "SERGEANT";
						position[] = {3,0,0};
					};
				};
			};
			class Motorized
			{
				name = "$STR_CfgGroups_East_RU_Motorized";
				class ACE_RU_MotInfSquad_D
				{
					name = "$STR_CfgGroups_East_RU_Motorized_RU_MotInfSquad";
					faction = "ACE_RU_Desert";
					rarityGroup = 0.3;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_SL_D";
						rank = "LIEUTENANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_Ural_RU_D";
						rank = "SERGEANT";
						position[] = {-5,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_MG_D";
						rank = "SERGEANT";
						position[] = {3,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AT_D";
						rank = "SERGEANT";
						position[] = {5,0,0};
					};
					class Unit4
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_LAT_D";
						rank = "CORPORAL";
						position[] = {7,0,0};
					};
					class Unit5
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_GL_D";
						rank = "CORPORAL";
						position[] = {9,0,0};
					};
					class Unit6
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_Marksman_D";
						rank = "CORPORAL";
						position[] = {11,0,0};
					};
					class Unit7
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_MG_D";
						rank = "CORPORAL";
						position[] = {13,0,0};
					};
					class Unit8
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_LAT_D";
						rank = "CORPORAL";
						position[] = {15,0,0};
					};
					class Unit9
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AR_D";
						rank = "PRIVATE";
						position[] = {17,0,0};
					};
					class Unit10
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AT_D";
						rank = "PRIVATE";
						position[] = {19,-5,0};
					};
					class Unit11
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_GL_D";
						rank = "PRIVATE";
						position[] = {21,-5,0};
					};
					class Unit12
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_D";
						rank = "PRIVATE";
						position[] = {23,-5,0};
					};
				};
				class ACE_RU_MotInfSection_Patrol_D
				{
					name = "$STR_CfgGroups_East_RU_Motorized_RU_MotInfSection_Patrol";
					faction = "ACE_RU_Desert";
					rarityGroup = 0.4;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_TL_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_UAZ_RU_D";
						rank = "CORPORAL";
						position[] = {-5,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AR_D";
						rank = "PRIVATE";
						position[] = {3,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AT_D";
						rank = "PRIVATE";
						position[] = {5,0,0};
					};
				};
			};
			class Mechanized
			{
				name = "$STR_CfgGroups_East_RU_Mechanized";
				class ACE_RU_MechReconSection_D
				{
					name = "$STR_CfgGroups_West_CDF_Mechanized_CDF_MechReconSection";
					faction = "ACE_RU_Desert";
					rarityGroup = 0.5;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_TL_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_BRDM2_RU_D";
						rank = "SERGEANT";
						position[] = {-5,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_MG_D";
						rank = "SERGEANT";
						position[] = {3,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AT_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
				};
				class ACE_RU_MechATSection_D
				{
					name = "$STR_CfgGroups_West_CDF_Mechanized_CDF_MechATSection";
					faction = "ACE_RU_Desert";
					rarityGroup = 0.5;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_TL_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_BRDM2_ATGM_RU_D";
						rank = "SERGEANT";
						position[] = {-5,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_BRDM2_RU_D";
						rank = "SERGEANT";
						position[] = {-10,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_MG_D";
						rank = "SERGEANT";
						position[] = {3,0,0};
					};
					class Unit4
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AT_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
				};
				class ACE_RU_MechInfSquad_2_D
				{
					name = "$STR_CfgGroups_East_RU_Mechanized_RU_MechInfSquad_2";
					faction = "ACE_RU_Desert";
					rarityGroup = 0.9;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_SL_D";
						rank = "LIEUTENANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_BTR70_RU_D";
						rank = "SERGEANT";
						position[] = {-5,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_MG_D";
						rank = "SERGEANT";
						position[] = {3,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_MG_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit4
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_AT_D";
						rank = "CORPORAL";
						position[] = {7,0,0};
					};
					class Unit5
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_LAT_D";
						rank = "PRIVATE";
						position[] = {9,0,0};
					};
					class Unit6
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_GL_D";
						rank = "PRIVATE";
						position[] = {11,0,0};
					};
					class Unit7
					{
						side = 0;
						vehicle = "ACE_RU_Soldier_D";
						rank = "PRIVATE";
						position[] = {13,0,0};
					};
				};
			};
		};
	};
};
//};
