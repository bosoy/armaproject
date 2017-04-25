////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:40:18 2012 : Created on Fri Nov 09 22:40:18 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_c_men_usmc : config.bin{
class CfgPatches
{
	class acex_usnavy_men_usmc
	{
		units[] = {"ACE_USMC_Soldier_D","ACE_USMC_Soldier2_D","ACE_USMC_Soldier_GL_D","ACE_USMC_Soldier_AR_D","ACE_USMC_Soldier_MG_D","ACE_USMC_Soldier_LAT_D","ACE_USMC_Soldier_AT_D","ACE_USMC_Soldier_HAT_D","ACE_USMC_Soldier_AA_D","ACE_USMC_SoldierS_Sniper_D","ACE_USMC_SoldierS_SniperH_D","ACE_USMC_SoldierM_Marksman_D","ACE_USMC_Soldier_SL_D","ACE_USMC_Soldier_TL_D","ACE_USMC_Soldier_Medic_D","ACE_USMC_Soldier_Officer_D","ACE_USMC_Soldier_Crew_D","ACE_USMC_SoldierS_Engineer_D"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CACharacters2","ace_c_men_gear","ace_sys_ruck","acex_usnavy_t_men_usmc","acex_usnavy_m_men_usmc","acex_wep_m16"};
		version = "1.14.0.77";
		author[] = {"Binkowski","Schnapsdrossel"};
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
	class USMC_Soldier_Base: SoldierWB
	{
		vehicleclass = "MenW";
	};
	class USMC_Soldier_Light: USMC_Soldier_Base
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.6;
			};
		};
	};
	class USMC_Soldier_Crew: USMC_Soldier_Base
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class USMC_Soldier: USMC_Soldier_Base
	{
		class TalkTopics;
	};
	class USMC_Soldier2;
	class USMC_Soldier_GL;
	class USMC_Soldier_Officer;
	class USMC_Soldier_SL;
	class USMC_Soldier_TL;
	class USMC_Soldier_LAT;
	class USMC_Soldier_AT;
	class USMC_Soldier_HAT;
	class USMC_Soldier_AA;
	class USMC_Soldier_Medic;
	class USMC_Soldier_AR;
	class USMC_Soldier_MG;
	class USMC_SoldierS_Spotter;
	class USMC_SoldierS_Sniper;
	class USMC_SoldierS_SniperH;
	class USMC_SoldierM_Marksman;
	class USMC_SoldierS;
	class USMC_SoldierS_Engineer;
	class ACE_USMC_Soldier_TAR: USMC_Soldier
	{
		displayName = "$STR_ACE_VDN_ACE_TEAMAR";
		accuracy = 3.7;
		picture = "\Ca\characters\data\Ico\i_null_CA.paa";
		icon = "\Ca\characters2\data\icon\i_machinegunner_CA.paa";
		weapons[] = {"ACE_M27_IAR_CCO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"30Rnd_556x45_STANAG","30Rnd_556x45_STANAG","30Rnd_556x45_STANAG","30Rnd_556x45_STANAG","30Rnd_556x45_STANAG","30Rnd_556x45_STANAG","30Rnd_556x45_STANAG","30Rnd_556x45_STANAG","30Rnd_556x45_STANAG","ACE_30Rnd_556x45_T_Stanag","HandGrenade_West","SmokeShell"};
		respawnWeapons[] = {"ACE_M27_IAR_CCO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"30Rnd_556x45_STANAG","30Rnd_556x45_STANAG","30Rnd_556x45_STANAG","30Rnd_556x45_STANAG","30Rnd_556x45_STANAG","ACE_30Rnd_556x45_T_Stanag","HandGrenade_West","SmokeShell"};
	};
	class ACE_USMC_Soldier_Terp: USMC_Soldier
	{
		ace_bwc = 1;
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_TRANSLATOR";
		accuracy = 3.7;
		languages[] = {"EN","CZ","RU","TK"};
		class TalkTopics: TalkTopics
		{
			core_cz = "Core_Full";
			core_en = "Core_Full_E";
			core_ru = "Core_Full";
			core_tk = "Core_Full_E";
		};
	};
	class ACE_USMC_Soldier_D: USMC_Soldier
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier";
	};
	class ACE_USMC_Soldier2_D: USMC_Soldier2
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier";
	};
	class ACE_USMC_Soldier_GL_D: USMC_Soldier_GL
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_TL";
	};
	class ACE_USMC_Soldier_AR_D: USMC_Soldier_AR
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_MG";
	};
	class ACE_USMC_Soldier_TAR_D: ACE_USMC_Soldier_TAR
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier";
	};
	class ACE_USMC_Soldier_MG_D: USMC_Soldier_MG
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_MG";
	};
	class ACE_USMC_Soldier_LAT_D: USMC_Soldier_LAT
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_AT";
	};
	class ACE_USMC_Soldier_AT_D: USMC_Soldier_AT
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_AT";
	};
	class ACE_USMC_Soldier_HAT_D: USMC_Soldier_HAT
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_AT";
	};
	class ACE_USMC_Soldier_AA_D: USMC_Soldier_AA
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_AT";
	};
	class ACE_USMC_SoldierS_Sniper_D: USMC_SoldierS_Sniper
	{
		vehicleclass = "MenDDPM";
		model = "\ca\characters_E\Ghillie\Ghillie_Overall";
		hiddenSelectionsTextures[] = {"\ca\characters_E\Ghillie\Data\ghillie_overall1_desert_co.paa"};
	};
	class ACE_USMC_SoldierS_SniperH_D: USMC_SoldierS_SniperH
	{
		vehicleclass = "MenDDPM";
		model = "\ca\characters_E\Ghillie\Ghillie_Overall";
		hiddenSelectionsTextures[] = {"\ca\characters_E\Ghillie\Data\ghillie_overall1_desert_co.paa"};
	};
	class ACE_USMC_SoldierM_Marksman_D: USMC_SoldierM_Marksman
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_DMR";
	};
	class ACE_USMC_SoldierS_Spotter_D: USMC_SoldierS_Spotter
	{
		vehicleclass = "MenDDPM";
		model = "\ca\characters_E\Ghillie\Ghillie_Overall";
		hiddenSelectionsTextures[] = {"\ca\characters_E\Ghillie\Data\ghillie_overall1_desert_co.paa"};
	};
	class ACE_USMC_SoldierS_D: USMC_SoldierS
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_FR";
	};
	class ACE_USMC_Soldier_SL_D: USMC_Soldier_SL
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_CO";
	};
	class ACE_USMC_Soldier_TL_D: USMC_Soldier_TL
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_TL";
	};
	class ACE_USMC_Soldier_Medic_D: USMC_Soldier_Medic
	{
		scope = 2;
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_medic";
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		weapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_MOLLE_DMARPAT_Medic"};
		respawnWeapons[] = {"ACE_M4_Eotech","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_MOLLE_DMARPAT_Medic"};
	};
	class ACE_USMC_Soldier_Officer_D: USMC_Soldier_Officer
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\USMC_soldier_Officer";
	};
	class ACE_USMC_Soldier_Crew_D: USMC_Soldier_Crew
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_crew";
	};
	class ACE_USMC_SoldierS_Engineer_D: USMC_SoldierS_Engineer
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_mine";
	};
	class ACE_USMC_Soldier_Light_D: USMC_Soldier_Light
	{
		ace_bwc = 1;
		vehicleclass = "MenDDPM";
	};
	class ACE_USMC_Soldier_Terp_D: ACE_USMC_Soldier_Terp
	{
		vehicleclass = "MenDDPM";
		model = "\x\acex_usnavy\addons\m_men_usmc\usmc_soldier_light";
	};
	class FR_Base: SoldierWB{};
	class FR_Miles: FR_Base
	{
		accuracy = 1000;
		ace_sys_recognize_accuracyOnly = 1;
	};
	class FR_Marksman: FR_Base{};
	class FR_Sykes: FR_Marksman
	{
		accuracy = 1000;
		ace_sys_recognize_accuracyOnly = 1;
	};
	class FR_Corpsman: FR_Base{};
	class FR_OHara: FR_Corpsman
	{
		accuracy = 1000;
		ace_sys_recognize_accuracyOnly = 1;
	};
	class FR_AR: FR_Base{};
	class FR_Rodriguez: FR_AR
	{
		accuracy = 1000;
		ace_sys_recognize_accuracyOnly = 1;
	};
	class FR_GL: FR_Base{};
	class FR_Cooper: FR_GL
	{
		accuracy = 1000;
		ace_sys_recognize_accuracyOnly = 1;
	};
};
class CfgGroups
{
	class West
	{
		class ACE_USMC_Desert
		{
			name = "$STR_ACE_FAC_BLUFOR_USMC_DES";
			class Infantry
			{
				name = "$STR_WF_TEAMINF";
				class ACE_USMC_D_InfSquad
				{
					name = "$STR_CFGGROUPS_WEST_USMC_INFANTRY_USMC_INFSQUAD";
					faction = "ACE_USMC_Desert";
					rarityGroup = 0.5;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_SL_D";
						rank = "LIEUTENANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_TL_D";
						rank = "SERGEANT";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_AR_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_LAT_D";
						rank = "CORPORAL";
						position[] = {7,0,0};
					};
					class Unit4
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_D";
						rank = "PRIVATE";
						position[] = {9,0,0};
					};
					class Unit5
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_TL_D";
						rank = "SERGEANT";
						position[] = {12,0,0};
					};
					class Unit6
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_AR_D";
						rank = "CORPORAL";
						position[] = {14,0,0};
					};
					class Unit7
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_LAT_D";
						rank = "CORPORAL";
						position[] = {16,0,0};
					};
					class Unit8
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_D";
						rank = "PRIVATE";
						position[] = {18,0,0};
					};
					class Unit9
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_TL_D";
						rank = "SERGEANT";
						position[] = {3,-5,0};
					};
					class Unit10
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_AR_D";
						rank = "CORPORAL";
						position[] = {5,-5,0};
					};
					class Unit11
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_LAT_D";
						rank = "CORPORAL";
						position[] = {7,-5,0};
					};
					class Unit12
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_D";
						rank = "PRIVATE";
						position[] = {9,-5,0};
					};
				};
				class ACE_USMC_D_FireTeam
				{
					name = "$STR_CFGGROUPS_WEST_USMC_INFANTRY_USMC_FIRETEAM";
					faction = "ACE_USMC_Desert";
					rarityGroup = 0.05;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_TL_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_AR_D";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_LAT_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_D";
						rank = "PRIVATE";
						position[] = {7,0,0};
					};
				};
				class ACE_USMC_D_FireTeam_MG
				{
					name = "$STR_CFGGROUPS_WEST_USMC_INFANTRY_USMC_FIRETEAM_MG";
					faction = "ACE_USMC_Desert";
					rarityGroup = 0.1;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_TL_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_MG_D";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_AR_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_LAT_D";
						rank = "PRIVATE";
						position[] = {7,0,0};
					};
				};
				class ACE_USMC_D_FireTeam_AT
				{
					name = "$STR_CFGGROUPS_WEST_USMC_INFANTRY_USMC_FIRETEAM_AT";
					faction = "ACE_USMC_Desert";
					rarityGroup = 0.1;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_TL_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_AR_D";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_AT_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_LAT_D";
						rank = "PRIVATE";
						position[] = {7,0,0};
					};
				};
				class ACE_USMC_D_FireTeam_Support
				{
					name = "$STR_CFGGROUPS_WEST_USMC_INFANTRY_USMC_FIRETEAM_SUPPORT";
					faction = "ACE_USMC_Desert";
					rarityGroup = 0.05;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_TL_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_AR_D";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_LAT_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_Medic_D";
						rank = "CORPORAL";
						position[] = {7,0,0};
					};
				};
				class ACE_USMC_D_HeavyATTeam
				{
					name = "$STR_CFGGROUPS_WEST_USMC_INFANTRY_USMC_HEAVYATTEAM";
					faction = "ACE_USMC_Desert";
					rarityGroup = 0.15;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_HAT_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_AT_D";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "ACE_USMC_Soldier_LAT_D";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
				};
				class ACE_USMC_D_SniperTeam
				{
					name = "$STR_CFGGROUPS_WEST_USMC_INFANTRY_USMC_SNIPERTEAM";
					faction = "ACE_USMC_Desert";
					rarityGroup = 0.05;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_USMC_SoldierS_Sniper_D";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_USMC_SoldierS_Spotter_D";
						rank = "SERGEANT";
						position[] = {3,0,0};
					};
				};
			};
		};
	};
};
//};
