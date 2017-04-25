////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Aug 11 06:51:13 2014 : Created on Mon Aug 11 06:51:13 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_su25 : config.bin{
class CfgPatches
{
	class acex_ru_veh_su25
	{
		units[] = {"ACE_Su25","ACE_Su39"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_ru_main","acex_c_vehicle","Extended_EventHandlers","CAAir3","CAAir_E","CAWeapons","CA_Anims","CAData"};
		version = "1.14.0.76";
		author[] = {"Aushilfe"};
	};
};
class CfgVehicles
{
	class Su25_base;
	class ACE_Su25_base: Su25_base
	{
		scope = 1;
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_su25\su25_body1_rus_des_co.paa","\x\acex_ru\addons\t_veh_su25\su25_body2_rus_des_co.paa"};
	};
	class Su39: Su25_base{};
	class ACE_Su25: Su39
	{
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_SU25_FAB250";
		vehicleClass = "ACE_AirD";
		crew = "ACE_RU_Soldier_Pilot_D";
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_su25\su25_body1_rus_des_co.paa","\x\acex_ru\addons\t_veh_su25\su25_body2_rus_des_co.paa"};
		weapons[] = {"GSh302","AirBombLauncher","R73Launcher_2","ACE_S8Launcher_Plane","CMFlareLauncher"};
		magazines[] = {"ACE_250Rnd_30mm_GSh302","4Rnd_FAB_250","2Rnd_R73","40Rnd_S8T","40Rnd_80mm","120Rnd_CMFlare_Chaff_Magazine"};
	};
	class ACE_Su39: ACE_Su25
	{
		displayName = "$STR_ACE_VDN_SU25_KH29";
		vehicleClass = "ACE_AirD";
		crew = "ACE_RU_Soldier_Pilot_D";
		weapons[] = {"GSh302","Ch29Launcher","R73Launcher_2","ACE_S8Launcher_Plane","CMFlareLauncher"};
		magazines[] = {"ACE_250Rnd_30mm_GSh302","4Rnd_Ch29","2Rnd_R73","40Rnd_S8T","40Rnd_80mm","120Rnd_CMFlare_Chaff_Magazine"};
	};
};
//};
