////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Wed Feb 08 15:24:51 2012 : Created on Wed Feb 08 15:24:51 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_naval : config.bin{
class CfgPatches
{
	class acex_ru_veh_naval
	{
		units[] = {"ACE_Ural_RU_D","ACE_UralOpen_RU_D","ACE_UAZ_RU_D","ACE_BRDM2_RU_D","ACE_BRDM2_ATGM_RU_D","ACE_Mi17_RU_D","ACE_Mi17_Rockets_RU_D"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_ru_main","CACharacters","CACharacters2","ace_main","ace_sys_ruck","ace_c_men_gear","acex_c_vehicle","acex_ru_t_veh_naval","acex_ru_men_naval"};
		version = "1.13.0.65";
	};
};
class CfgVehicles
{
	class Ural_Base;
	class ACE_Ural_RU_D: Ural_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		vehicleClass = "CarD";
		crew = "ACE_Ru_Soldier_D";
		accuracy = 0.5;
		typicalCargo[] = {"ACE_Ru_Soldier_D","ACE_Ru_Soldier_D"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_naval\ural_kabina_d_co.paa","\x\acex_ru\addons\t_veh_naval\ural_dcanvas_co.paa"};
	};
	class UralOpen_Base;
	class ACE_UralOpen_RU_D: UralOpen_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		vehicleClass = "CarD";
		accuracy = 0.5;
		crew = "ACE_Ru_Soldier_D";
		typicalCargo[] = {"ACE_Ru_Soldier_D","ACE_Ru_Soldier_D"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_naval\ural_kabina_d_co.paa","\x\acex_ru\addons\t_veh_naval\ural_dpen_co.paa"};
	};
	class UAZ_Unarmed_TK_EP1;
	class ACE_UAZ_RU_D: UAZ_Unarmed_TK_EP1
	{
		scope = 2;
		side = 0;
		faction = "RU";
		vehicleClass = "CarD";
		accuracy = 0.5;
		crew = "ACE_Ru_Soldier_D";
		typicalCargo[] = {"ACE_Ru_Soldier_D","ACE_Ru_Soldier_D"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_naval\uaz_d_co.paa",""};
	};
	class BRDM2_Base;
	class ACE_BRDM2_RU_D: BRDM2_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		vehicleClass = "ArmouredD";
		crew = "ACE_RU_Soldier_Crew_D";
		accuracy = 0.5;
		typicalCargo[] = {"ACE_RU_Soldier_Crew_D","ACE_Ru_Soldier_D","ACE_Ru_Soldier_D","ACE_Ru_Soldier_D"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_naval\brdm2_01_d_co.paa","\x\acex_ru\addons\t_veh_naval\brdm2_02_d_ca.paa"};
	};
	class BRDM2_ATGM_Base;
	class ACE_BRDM2_ATGM_RU_D: BRDM2_ATGM_Base
	{
		scope = 2;
		side = 0;
		faction = "RU";
		vehicleClass = "ArmouredD";
		crew = "ACE_RU_Soldier_Crew_D";
		accuracy = 0.5;
		typicalCargo[] = {"ACE_RU_Soldier_Crew_D","ACE_RU_Soldier_Crew_D","ACE_Ru_Soldier_D"};
		weapons[] = {"ACE_AT5B_Launcher"};
		magazines[] = {"ACE_5Rnd_AT5B_BRDM2","ACE_5Rnd_AT5B_BRDM2"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_naval\brdm2_atgm_01_d_co.paa","\x\acex_ru\addons\t_veh_naval\brdm2_02_d_ca.paa"};
	};
	class BTR60_TK_EP1;
	class ACE_BTR60_RU_D: BTR60_TK_EP1
	{
		scope = 1;
		side = 0;
		faction = "RU";
		vehicleClass = "ArmouredD";
		crew = "ACE_RU_Soldier_Crew_D";
		typicalCargo[] = {"ACE_RU_Soldier_Crew_D","ACE_RU_Soldier_Crew_D","ACE_Ru_Soldier_D"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_naval\btr60_body_d_co.paa","\CA\wheeled_e\BTR60\Data\btr60_details_co.paa"};
	};
	class ACE_Mi17_RU;
	class ACE_Mi17_RU_D: ACE_Mi17_RU
	{
		scope = 1;
		vehicleClass = "ACE_AirD";
		crew = "ACE_RU_Soldier_Pilot_D";
		typicalCargo[] = {"ACE_RU_Soldier_Pilot_D","ACE_RU_Soldier_Pilot_D","ACE_Ru_Soldier_AT_D","ACE_Ru_Soldier_MG_D"};
		hiddenSelectionsTextures[] = {"\ca\air\data\mi8_body_g_vsr_co.paa","ca\air\data\mi8_det_g_co.paa","ca\air\data\clear_empty.paa","ca\air\data\mi8_decals_ca.paa"};
	};
	class Mi17_Rockets_RU;
	class ACE_Mi17_Rockets_RU_D: Mi17_Rockets_RU
	{
		scope = 1;
		side = 0;
		vehicleClass = "ACE_AirD";
		crew = "ACE_RU_Soldier_Pilot_D";
		typicalCargo[] = {"ACE_RU_Soldier_Pilot_D","ACE_RU_Soldier_Pilot_D","ACE_Ru_Soldier_AT_D","ACE_Ru_Soldier_MG_D"};
	};
};
//};
