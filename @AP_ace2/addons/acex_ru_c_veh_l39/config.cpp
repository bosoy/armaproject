////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:39:49 2012 : Created on Fri Nov 09 22:39:49 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_l39 : config.bin{
class CfgPatches
{
	class acex_ru_veh_l39
	{
		units[] = {"ACE_L39"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_ru_main","acex_c_vehicle","Extended_EventHandlers","CAAir3","CAAir_E","CAWeapons","CA_Anims","CAData"};
		version = "1.14.0.76";
		author[] = {"Aushilfe"};
	};
};
class CfgVehicles
{
	class Plane;
	class L39_base: Plane{};
	class ACE_L39_base: L39_base
	{
		scope = 1;
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_l39\l-39_body_ru_co.paa","\x\acex_ru\addons\t_veh_l39\l-39_body_1_ru_co.paa"};
		weapons[] = {"GSh23L_L39","ACE_UB16_Pods"};
		magazines[] = {"150Rnd_23mm_GSh23L","ACE_1Rnd_UB16","ACE_1Rnd_UB16","ACE_1Rnd_UB16","ACE_1Rnd_UB16","ACE_64Rnd_57mm"};
	};
	class ACE_L39_RU: ACE_L39_base
	{
		accuracy = 1.5;
		displayName = "L-39ZA Albatros";
		scope = 2;
		side = 0;
		faction = "RU";
		crew = "RU_Soldier_Pilot";
		typicalCargo[] = {"RU_Soldier_Pilot"};
	};
	class ACE_L39_RU_BO: ACE_L39_RU
	{
		accuracy = 1000;
		displayName = "L-39ZA (FAB-250)";
		weapons[] = {"GSh23L_L39","ACE_AirBombLauncher"};
		magazines[] = {"150Rnd_23mm_GSh23L","ACE_4Rnd_FAB_250"};
	};
};
//};
