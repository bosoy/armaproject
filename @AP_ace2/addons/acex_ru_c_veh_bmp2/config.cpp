////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:39:47 2012 : Created on Fri Nov 09 22:39:47 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_bmp2 : config.bin{
class CfgPatches
{
	class acex_ru_veh_bmp2
	{
		units[] = {"ACE_BMP2_RU","ACE_BMP2D_RU"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CATracked","acex_main","acex_m_veh_bmp2","acex_t_veh_bmp2"};
		version = "1.14.0.76";
	};
};
class CfgVehicles
{
	class Tracked_APC;
	class BMP2_Base: Tracked_APC
	{
		class Turrets;
		class MainTurret;
	};
	class ACE_BMP2_RU: BMP2_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		accuracy = 0.5;
		crew = "RU_Soldier_Crew";
		typicalCargo[] = {"RU_Soldier_Crew","RU_Soldier_Crew","RU_Soldier_Crew","RU_Soldier","RU_Soldier_MG","RU_Soldier_AT"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_bmp2\bmp2_01_ru_co.paa","\x\acex_ru\addons\t_veh_bmp2\bmp2_02_ru_co.paa"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_2A42","PKT","ACE_AT5B_Launcher"};
				magazines[] = {"250Rnd_30mmAP_2A42","250Rnd_30mmHE_2A42","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","ACE_AT5B"};
			};
		};
	};
	class ACE_BMP2D_RU: ACE_BMP2_RU
	{
		accuracy = 1.5;
		displayName = "$STR_DN_ACE_BMP2D_RU";
		model = "\x\acex\addons\m_veh_bmp2\ace_bmp2d";
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\tracked_e\bmp\data\bmp2_01.rvmat","ca\tracked_e\bmp\data\bmp2_01_damage.rvmat","ca\tracked_e\bmp\data\bmp2_01_destruct.rvmat","ca\tracked_e\bmp\data\bmp2_02.rvmat","ca\tracked_e\bmp\data\bmp2_02_damage.rvmat","ca\tracked_e\bmp\data\bmp2_02_destruct.rvmat","ca\tracked_e\bmp\data\bmp_hq.rvmat","ca\tracked_e\bmp\data\bmp_hq_damage.rvmat","ca\tracked_e\bmp\data\bmp_hq_destruct.rvmat","ca\tracked_e\bmp\data\bmp2_pasy.rvmat","ca\tracked_e\bmp\data\bmp2_pasy_damage.rvmat","ca\tracked_e\bmp\data\bmp2_pasy_destruct.rvmat","x\acex\addons\c_veh_bmp2\bmp2_03.rvmat","x\acex\addons\c_veh_bmp2\bmp2_03_damage.rvmat","x\acex\addons\c_veh_bmp2\bmp2_03_destruct.rvmat"};
		};
		canfloat = 0;
		ace_armor_hull[] = {{40,40},{28,33},{28,33},{16,16},{16,16},{50,50}};
		ace_armor_turret[] = {{33,33},{19,19},{19,19},{25,25},{16,16}};
	};
};
//};
