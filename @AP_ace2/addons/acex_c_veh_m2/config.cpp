////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 28 15:59:47 2011 : Created on Fri Oct 28 15:59:47 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_m2 : config.bin{
class CfgPatches
{
	class acex_veh_m2
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","acex_c_vehicle","Extended_EventHandlers","CATracked","CAWeapons","CA_Anims","CAData"};
		version = "1.12.0.349";
		author[] = {};
	};
};
class CfgVehicles
{
	class M2A2_EP1;
	class ACE_M2A2_W: M2A2_EP1
	{
		vehicleclass = "ArmouredW";
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m2\base_co.paa","\x\acex\addons\t_veh_m2\a3_co.paa","\x\acex\addons\t_veh_m2\ultralp_co.paa","","\x\acex\addons\t_veh_m2\base_co.paa"};
	};
	class ACE_M2A2_G: ACE_M2A2_W
	{
		scope = 1;
	};
	class M2A3_EP1;
	class ACE_M2A3_W: M2A3_EP1
	{
		vehicleclass = "ArmouredW";
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m2\base_co.paa","\x\acex\addons\t_veh_m2\a3_co.paa","\x\acex\addons\t_veh_m2\ultralp_co.paa"};
	};
	class M6_EP1;
	class ACE_M6A1_W: M6_EP1
	{
		vehicleclass = "ArmouredW";
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m2\base_co.paa","\x\acex\addons\t_veh_m2\a3_co.paa","\x\acex\addons\t_veh_m2\ultralp_co.paa","\x\acex\addons\t_veh_m2\base_co.paa",""};
	};
	class ACE_M6A1_G: ACE_M6A1_W
	{
		scope = 1;
	};
};
//};
