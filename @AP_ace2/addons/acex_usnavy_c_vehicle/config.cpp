////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:58:58 2011 : Created on Fri Oct 21 13:58:58 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_c_vehicle : config.bin{
class CfgPatches
{
	class acex_usnavy_c_vehicle
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_usnavy_main","acex_main","acex_veh_m1","acex_usnavy_men_usmc","ace_c_vehicle"};
		version = "1.12.0.64";
	};
};
class CfgFactionClasses
{
	class Default
	{
		primaryLanguage = "EN";
	};
	class USMC
	{
		priority = 1;
		primaryLanguage = "EN";
	};
	class RU
	{
		priority = 3;
		ACE_Language = "Russian";
		primaryLanguage = "RU";
	};
	class INS
	{
		priority = 8;
		primaryLanguage = "RU";
	};
	class CDF
	{
		priority = 9;
		primaryLanguage = "CZ";
	};
	class GUE
	{
		priority = 10;
		primaryLanguage = "CZ";
	};
	class CIV
	{
		priority = 11;
		primaryLanguage = "CZ";
	};
	class CIV_RU
	{
		priority = 12;
		primaryLanguage = "RU";
	};
	class None
	{
		primaryLanguage = "EN";
	};
};
class CfgVehicles
{
	class HMMWV_Base;
	class HMMWV_Avenger: HMMWV_Base
	{
		model = "\ca\wheeled_e\HMMWV\M998A2_Avenger.p3d";
	};
	class M2HD_mini_TriPod;
	class ACE_M240_Tripod: M2HD_mini_TriPod
	{
		scope = 2;
	};
	class M1A1;
	class ACE_M1A1HC_DESERT: M1A1
	{
		crew = "ACE_USMC_Soldier_Crew_D";
	};
	class ACE_M1A1HC_TUSK;
	class ACE_M1A1HC_TUSK_DESERT: ACE_M1A1HC_TUSK
	{
		crew = "ACE_USMC_Soldier_Crew_D";
	};
	class ACE_M1A1HC_TUSK_CSAMM;
	class ACE_M1A1HC_TUSK_CSAMM_DESERT: ACE_M1A1HC_TUSK_CSAMM
	{
		crew = "ACE_USMC_Soldier_Crew_D";
	};
};
//};
