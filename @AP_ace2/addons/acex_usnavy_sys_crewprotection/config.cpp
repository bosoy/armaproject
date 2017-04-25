////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:59:54 2011 : Created on Fri Oct 21 13:59:54 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_sys_crewprotection : config.bin{
class CfgPatches
{
	class acex_usnavy_sys_crewprotection
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CACharacters","CACharacters2","CACharacters_E","acex_usnavy_main"};
		version = "1.12.0.64";
		author[] = {"Rocko"};
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
	class USMC_Soldier_Base;
	class USMC_Soldier_Crew: USMC_Soldier_Base
	{
		ACE_isCrew = 1;
		ACE_CrewProtection = 1;
	};
	class USMC_Soldier_Pilot: USMC_Soldier_Base
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class USMC_LHD_Crew_Base: USMC_Soldier_Base
	{
		ACE_isCrew = 1;
		ACE_CrewProtection = 1;
	};
	class FR_GL;
	class FR_R;
	class FR_Assault_GL: FR_GL
	{
		ACE_CrewProtection = 1;
	};
	class FR_Assault_R: FR_R
	{
		ACE_CrewProtection = 1;
	};
};
//};
