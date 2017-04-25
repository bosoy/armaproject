////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:55:13 2011 : Created on Fri Oct 21 13:55:13 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_mi17 : config.bin{
class CfgPatches
{
	class acex_ru_veh_mi17
	{
		units[] = {"ACE_Mi17_RU"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_ru_main","ace_c_vehicle","CAAir"};
		version = "1.12.0.61";
	};
};
class CfgVehicles
{
	class Helicopter;
	class Mi17_base_RU;
	class ACE_Mi17_RU: Mi17_Base_RU
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_MI17_INS";
		vehicleClass = "Air";
		crew = "RU_Soldier_Pilot";
		typicalCargo[] = {"RU_Soldier_Pilot","RU_Soldier_Pilot","RU_Soldier_AT","RU_Soldier_MG"};
		hiddenSelectionsTextures[] = {"\ca\air\data\mi8_body_g_vsr_co.paa","ca\air\data\mi8_det_g_co.paa","ca\air\data\clear_empty.paa","ca\air\data\mi8_decals_ca.paa"};
	};
};
//};
