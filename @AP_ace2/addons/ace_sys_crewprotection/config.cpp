////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Dec 01 21:38:56 2012 : Created on Sat Dec 01 21:38:56 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_crewprotection : config.bin{
class CfgPatches
{
	class ace_sys_crewprotection
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CACharacters","CACharacters2","CACharacters_E","ace_main"};
		version = "1.14.0.584";
		author[] = {"Rocko"};
	};
};
class CfgFunctions
{
	class ACE
	{
		class Crewprotection
		{
			class hasCrewProtection
			{
				description = "Find out if given unit has crew protection";
				file = "\x\ace\Addons\sys_crewprotection\fnc_hasCrewProtection.sqf";
			};
			class setCrewProtection
			{
				description = "Set unit crew protection";
				file = "\x\ace\Addons\sys_crewprotection\fnc_setCrewProtection.sqf";
			};
		};
	};
};
class CfgVehicles
{
	class CAManbase;
	class SoldierWB: CAManbase
	{
		ACE_CrewProtection = 0;
	};
	class SoldierEB: CAManbase
	{
		ACE_CrewProtection = 0;
	};
	class SoldierGB: CAManbase
	{
		ACE_CrewProtection = 0;
	};
	class Civilian: CAManBase
	{
		ACE_CrewProtection = 0;
	};
	class US_Soldier_Base_EP1;
	class US_Soldier_Pilot_EP1: US_Soldier_Base_EP1
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class US_Pilot_Light_EP1: US_Soldier_Base_EP1
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class US_Soldier_Crew_EP1: US_Soldier_Base_EP1
	{
		ACE_isCrew = 1;
		ACE_CrewProtection = 1;
	};
	class US_Soldier_Engineer_EP1: US_Soldier_Base_EP1
	{
		ACE_CrewProtection = 1;
	};
	class US_Delta_Force_EP1: US_Soldier_Base_EP1
	{
		ACE_CrewProtection = 1;
	};
	class US_Delta_Force_TL_EP1: US_Soldier_Base_EP1
	{
		ACE_CrewProtection = 1;
	};
	class US_Delta_Force_Medic_EP1: US_Delta_Force_EP1
	{
		ACE_CrewProtection = 1;
	};
	class US_Delta_Force_Assault_EP1: US_Delta_Force_EP1
	{
		ACE_CrewProtection = 1;
	};
	class US_Delta_Force_SD_EP1: US_Delta_Force_EP1
	{
		ACE_CrewProtection = 1;
	};
	class US_Delta_Force_MG_EP1: US_Delta_Force_EP1
	{
		ACE_CrewProtection = 1;
	};
	class US_Delta_Force_AR_EP1: US_Delta_Force_EP1
	{
		ACE_CrewProtection = 1;
	};
	class US_Delta_Force_Night_EP1: US_Delta_Force_EP1
	{
		ACE_CrewProtection = 1;
	};
	class US_Delta_Force_Marksman_EP1: US_Delta_Force_EP1
	{
		ACE_CrewProtection = 1;
	};
	class US_Delta_Force_M14_EP1: US_Delta_Force_EP1
	{
		ACE_CrewProtection = 1;
	};
	class US_Delta_Force_Air_Controller_EP1: US_Delta_Force_EP1
	{
		ACE_CrewProtection = 1;
	};
	class CZ_Soldier_base_EP1;
	class CZ_Soldier_Pilot_EP1: CZ_Soldier_base_EP1
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class CZ_Soldier_Base_ACR: CZ_Soldier_base_EP1{};
	class CZ_Soldier_Crew_Dst_ACR: CZ_Soldier_Base_ACR
	{
		ACE_isCrew = 1;
		ACE_CrewProtection = 1;
	};
	class CZ_Soldier_Pilot_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class CZ_Soldier_Recon_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		ACE_CrewProtection = 1;
	};
	class UN_CDF_Soldier_base_EP1;
	class UN_CDF_Soldier_Pilot_EP1: UN_CDF_Soldier_base_EP1
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class UN_CDF_Soldier_Crew_EP1: UN_CDF_Soldier_base_EP1
	{
		ACE_isCrew = 1;
		ACE_CrewProtection = 1;
	};
	class TK_Soldier_base_EP1;
	class TK_Soldier_Crew_EP1: TK_Soldier_base_EP1
	{
		ACE_isCrew = 1;
		ACE_CrewProtection = 1;
	};
	class TK_Soldier_Pilot_EP1: TK_Soldier_base_EP1
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class BAF_Soldier_base_EP1;
	class BAF_Pilot_MTP: BAF_Soldier_base_EP1
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class BAF_Crewman_MTP: BAF_Soldier_base_EP1
	{
		ACE_isCrew = 1;
		ACE_CrewProtection = 1;
	};
	class Soldier_Base_PMC;
	class Soldier_PMC: Soldier_Base_PMC
	{
		ACE_CrewProtection = 1;
	};
	class Soldier_M4A3_PMC: Soldier_PMC
	{
		ACE_CrewProtection = 1;
	};
	class Soldier_Pilot_PMC: Soldier_Base_PMC
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class Soldier_MG_PMC: Soldier_Base_PMC
	{
		ACE_CrewProtection = 1;
	};
	class Soldier_MG_PKM_PMC: Soldier_MG_PMC
	{
		ACE_CrewProtection = 1;
	};
	class Soldier_Sniper_PMC: Soldier_Base_PMC
	{
		ACE_CrewProtection = 1;
	};
	class Soldier_Sniper_KSVK_PMC: Soldier_Sniper_PMC
	{
		ACE_CrewProtection = 1;
	};
	class Soldier_GL_PMC: Soldier_Base_PMC
	{
		ACE_CrewProtection = 1;
	};
	class Soldier_GL_M16A2_PMC: Soldier_GL_PMC
	{
		ACE_CrewProtection = 1;
	};
	class Soldier_AA_PMC: Soldier_Base_PMC
	{
		ACE_CrewProtection = 1;
	};
	class Soldier_AT_PMC: Soldier_Base_PMC
	{
		ACE_CrewProtection = 1;
	};
};
//};
