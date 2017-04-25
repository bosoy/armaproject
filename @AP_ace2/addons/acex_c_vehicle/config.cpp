////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jul 28 13:16:33 2012 : Created on Sat Jul 28 13:16:33 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_vehicle : config.bin{
class CfgPatches
{
	class acex_c_vehicle
	{
		units[] = {"ACE_Offroad_SPG9_INS","ACE_UAZ_SPG9_CDF","ACE_ZSU_RU","ACE_Ural_RU","ACE_UralOpen_RU","ACE_UralRepair_RU","ACE_UralReammo_RU","ACE_UralRefuel_RU","ACE_Ural_ZU23_RU"};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","ace_c_vehicle","CAA10","CA_AH64D","CAWheeled","CAWheeled3","CATracked"};
		version = "1.13.0.364";
	};
};
class CfgFactionClasses
{
	class Default
	{
		primaryLanguage = "EN";
	};
	class ACE_USMC_Desert
	{
		displayName = "$STR_ACE_FAC_BLUFOR_USMC_DES";
		priority = 2;
		side = 1;
		ACE_Language = "English";
		primaryLanguage = "EN";
	};
	class ACE_USARMY
	{
		displayName = "$STR_ACE_FAC_BLUFOR_USARMY";
		priority = 3;
		side = 1;
		ACE_Language = "English";
		primaryLanguage = "EN";
	};
	class ACE_USARMY_DESERT
	{
		displayName = "$STR_ACE_FAC_BLUFOR_USARMY_DES";
		priority = 4;
		side = 1;
		ACE_Language = "English";
		primaryLanguage = "EN";
	};
	class ACE_160SOAR
	{
		displayName = "$STR_ACE_FAC_BLUFOR_160SOAR";
		priority = 5;
		side = 1;
		ACE_Language = "English";
		primaryLanguage = "EN";
	};
	class ACE_USAF
	{
		priority = 6;
		primaryLanguage = "EN";
	};
	class ACE_USNAVY
	{
		priority = 7;
		primaryLanguage = "EN";
	};
	class ACE_VDV
	{
		displayName = "$STR_ACE_FAC_OPFOR_VDV";
		priority = 4;
		side = 0;
		ACE_Language = "Russian";
		primaryLanguage = "RU";
	};
	class ACE_GRU
	{
		displayName = "$STR_ACE_FAC_OPFOR_GRU";
		priority = 5;
		side = 0;
		ACE_Language = "Russian";
		primaryLanguage = "RU";
	};
	class ACE_MVD
	{
		displayName = "$STR_ACE_FAC_OPFOR_MVD";
		priority = 6;
		side = 0;
		ACE_Language = "Russian";
		primaryLanguage = "RU";
	};
};
class CfgVehicleClasses
{
	class ACE_VC_Air_USArmySOAR
	{
		displayName = "$STR_ACE_VC_BLUFOR_160SOAR";
	};
	class ACE_VC_USNavySeals_AOR1
	{
		displayName = "$STR_ACE_VC_BLUFOR_USNAVY_AOR1";
	};
	class ACE_VC_USNavySeals_AOR2
	{
		displayName = "$STR_ACE_VC_BLUFOR_USNAVY_AOR2";
	};
	class ACE_VC_USNavySeals_Woodland
	{
		displayName = "$STR_ACE_VC_BLUFOR_USNAVY_WOOD";
	};
	class ACE_EasterEggs
	{
		displayName = "$STR_ACE_EASTEREGGS";
	};
	class ACE_AirD
	{
		displayName = "$STR_ACE_VC_AIR_DESERT";
	};
};
//};
