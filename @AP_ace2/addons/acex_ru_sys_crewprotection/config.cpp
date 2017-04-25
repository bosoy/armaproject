////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:57:14 2011 : Created on Fri Oct 21 13:57:14 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_sys_crewprotection : config.bin{
class CfgPatches
{
	class acex_ru_sys_crewprotection
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CACharacters","CACharacters2","CACharacters_E","acex_ru_main"};
		version = "1.12.0.61";
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
	class CDF_Soldier_Base;
	class CDF_Soldier_Pilot: CDF_Soldier_Base
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class CDF_Soldier_Crew: CDF_Soldier_Base
	{
		ACE_isCrew = 1;
		ACE_CrewProtection = 1;
	};
	class RU_Soldier_Base;
	class RU_Soldier_Pilot: RU_Soldier_Base
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class RU_Soldier_Crew: RU_Soldier_Base
	{
		ACE_isCrew = 1;
		ACE_CrewProtection = 1;
	};
	class GUE_Soldier_1;
	class GUE_Soldier_Pilot: GUE_Soldier_1
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class GUE_Soldier_Crew: GUE_Soldier_1
	{
		ACE_isCrew = 1;
		ACE_CrewProtection = 1;
	};
	class Ins_Soldier_Base;
	class Ins_Soldier_Pilot: Ins_Soldier_Base
	{
		ACE_isPilot = 1;
		ACE_CrewProtection = 1;
	};
	class Ins_Soldier_Crew: Ins_Soldier_Base
	{
		ACE_isCrew = 1;
		ACE_CrewProtection = 1;
	};
};
//};
