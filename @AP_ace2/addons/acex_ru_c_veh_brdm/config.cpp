////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:39:47 2012 : Created on Fri Nov 09 22:39:47 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_brdm : config.bin{
class CfgPatches
{
	class acex_ru_veh_brdm
	{
		units[] = {"ACE_BRDM2_ATGM_Base","ACE_BRDM2_SA9_Base","ACE_BRDM2_RU","ACE_BRDM2_ATGM_RU","ACE_BRDM2_SA9_RU","ACE_BRDM2_HQ_RU"};
		weapons[] = {"ACE_9K35Launcher"};
		requiredVersion = 1.54;
		requiredAddons[] = {"CAWheeled","acex_ru_main","acex_m_veh_brdm","acex_ru_t_veh_brdm"};
		version = "1.14.0.76";
	};
};
class CfgVehicles
{
	class BRDM2_Base;
	class BRDM2_ATGM_Base: BRDM2_Base
	{
		class Turrets;
	};
	class ACE_BRDM2_ATGM_Base: BRDM2_ATGM_Base
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class ACE_BRDM2_SA9_Base: ACE_BRDM2_ATGM_Base
	{
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_brdm\9P31_01_co.paa","\ca\wheeled\data\brdm2_02_co.paa","\x\acex_ru\addons\t_veh_brdm\9K31M_Launcher_co.paa","\x\acex_ru\addons\t_veh_brdm\9P31_turret_co.paa"};
	};
	class ACE_BRDM2_RU: BRDM2_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		accuracy = 0.5;
		crew = "RU_Soldier";
		typicalCargo[] = {"RU_Soldier","RU_Soldier"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_brdm\9P31_01_ru_co.paa","\x\acex_ru\addons\t_veh_brdm\9P31_02_ru_co.paa"};
	};
	class ACE_BRDM2_ATGM_RU: ACE_BRDM2_ATGM_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		accuracy = 0.5;
		crew = "RU_Soldier";
		typicalCargo[] = {"RU_Soldier","RU_Soldier"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_AT5B_Launcher"};
				magazines[] = {"ACE_5Rnd_AT5B_BRDM2","ACE_5Rnd_AT5B_BRDM2"};
			};
		};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_brdm\9P31_01_ru_co.paa","\x\acex_ru\addons\t_veh_brdm\9P31_02_ru_co.paa"};
	};
	class ACE_BRDM2_SA9_RU: ACE_BRDM2_SA9_Base
	{
		scope = 1;
		side = 0;
		faction = "RU";
		accuracy = 0.5;
		crew = "RU_Soldier";
		typicalCargo[] = {"RU_Soldier","RU_Soldier"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_brdm\9P31_01_ru_co.paa","\x\acex_ru\addons\t_veh_brdm\9P31_02_ru_co.paa","\x\acex_ru\addons\t_veh_brdm\9K31M_Launcher_ru_co.paa","\x\acex_ru\addons\t_veh_brdm\9P31_Turret_ru_co.paa"};
	};
	class ACE_BRDM2_SA9_CDF: ACE_BRDM2_SA9_Base
	{
		scope = 2;
		side = 1;
		faction = "CDF";
		accuracy = 0.5;
		crew = "CDF_Soldier_Crew";
		typicalCargo[] = {"CDF_Soldier_Crew","CDF_Soldier_Crew"};
		hiddenSelectionsTextures[] = {"\ca\wheeled\data\brdm2_atgm_01_camo_co.paa","\ca\wheeled\data\brdm2_02_camo_co.paa","\x\acex_ru\addons\t_veh_brdm\9K31M_Launcher_camo_co.paa","\x\acex_ru\addons\t_veh_brdm\9P31_turret_camo_co.paa"};
	};
	class ACE_BRDM2_SA9_INS: ACE_BRDM2_SA9_Base
	{
		scope = 2;
		side = 0;
		faction = "INS";
		accuracy = 0.5;
		crew = "Ins_Soldier_Crew";
		typicalCargo[] = {"Ins_Soldier_Crew","Ins_Soldier_Crew","Ins_Soldier_2","Ins_Soldier_1"};
		hiddenSelectionsTextures[] = {"\ca\wheeled\data\brdm2_atgm_01_co.paa","\ca\wheeled\data\brdm2_02_co.paa","\x\acex_ru\addons\t_veh_brdm\9K31M_Launcher_co.paa","\x\acex_ru\addons\t_veh_brdm\9P31_turret_co.paa"};
	};
	class ACE_BRDM2_SA9_Gue: ACE_BRDM2_SA9_Base
	{
		scope = 2;
		side = 2;
		faction = "GUE";
		accuracy = 0.5;
		crew = "GUE_Soldier_1";
		typicalCargo[] = {"GUE_Soldier_1","GUE_Soldier_1","GUE_Soldier_1","GUE_Soldier_1"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_brdm\9P31_01_co.paa","\ca\wheeled\data\brdm2_02_co.paa","\x\acex_ru\addons\t_veh_brdm\9K31M_Launcher_co.paa","\x\acex_ru\addons\t_veh_brdm\9P31_turret_co.paa"};
	};
	class BRDM2_HQ_Base: BRDM2_Base
	{
		model = "\ca\wheeled_E\BRDM2\BRDM2_HQ";
		hiddenSelections[] = {"Camo1"};
	};
	class ACE_BRDM2_HQ_RU: BRDM2_HQ_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		accuracy = 0.5;
		crew = "RU_Soldier";
		typicalCargo[] = {"RU_Soldier","RU_Soldier","RU_Soldier","RU_Soldier"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_brdm\9P31_01_ru_co.paa"};
	};
	class BRDM2_HQ_Gue: BRDM2_HQ_Base
	{
		hiddenSelectionsTextures[] = {"\ca\wheeled\data\brdm2_01_co.paa",""};
	};
};
//};
