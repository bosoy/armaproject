////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:39:49 2012 : Created on Fri Nov 09 22:39:49 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_mi24 : config.bin{
class CfgPatches
{
	class acex_ru_veh_mi24
	{
		units[] = {"ACE_Mi24_V_CDF","ACE_Mi24_D_INS"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_ru_main","ace_c_vehicle","acex_ru_t_veh_mi24","CAAir2","CAAir_E","CAAir_E_Mi24"};
		version = "1.14.0.76";
	};
};
class CfgVehicles
{
	class Helicopter;
	class Mi24_Base: Helicopter
	{
		class Turrets;
	};
	class ACE_Mi24_Base_INS: Mi24_Base
	{
		accuracy = 1.5;
		side = 0;
		faction = "INS";
		class Turrets: Turrets
		{
			class MainTurret;
		};
		ACE_NBC_Protection = 0;
	};
	class ACE_Mi24_D_INS: ACE_Mi24_Base_INS
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_MI24_D";
		model = "\x\ace\addons\m_vehicle\mi24\ace_mi24d";
		irScanRangeMax = 3000;
		crew = "Ins_Soldier_Pilot";
		typicalCargo[] = {"Ins_Soldier_Pilot","Ins_Soldier_Pilot","Ins_Soldier_AT","Ins_Soldier_MG"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_mi24\mi24d_ins_001_co.paa","\x\acex_ru\addons\t_veh_mi24\mi24d_ins_002_co.paa"};
		weapons[] = {"57mmLauncher_128","CMFlareLauncher"};
		magazines[] = {"128Rnd_57mm","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_missileguidance_limits[] = {15,15,-4,0};
				weapons[] = {"YakB","AT2Launcher"};
				magazines[] = {"1470Rnd_127x108_YakB","4Rnd_AT2_Mi24D"};
			};
		};
		class Library
		{
			libTextDesc = "$STR_LIB_MI24_D";
		};
	};
};
//};
