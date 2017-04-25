////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.88
//Thu Feb 05 04:22:23 2015 : Source 'file' date Thu Feb 05 04:22:23 2015
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class C:/Users/Дима/Documents/ArmA 2 Other Profiles/[KPblM]Dimon_UA/missions/ace_sys_modelspecial/config.bin{
class CfgPatches
{
	class ace_sys_modelspecial
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_c_weapon","ace_main"};
		version = "1.14.0.586";
		author[] = {"q1184","Sickboy","zGuba"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_modelspecial
	{
		clientInit = "call ('\x\ace\addons\sys_modelspecial\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_modelspecial
	{
		clientInit = "call ('\x\ace\addons\sys_modelspecial\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class CAManBase
	{
		class ace_sys_modelspecial
		{
			init = "_this call compile preprocessFileLineNumbers ('\x\ace\addons\sys_modelspecial\fnc_invInit.sqf')";
		};
	};
};
class CfgMagazines
{
	class Default
	{
		ace_replace = 0;
	};
	class CA_LauncherMagazine;
	class PG7V: CA_LauncherMagazine
	{
		ace_replace = 1;
		class ace_sys_modelspecial_replacements
		{
			rpg7v = "PG7V";
			ace_rpg7v_pgo7 = "ACE_PG7V_PGO7";
		};
	};
	class ACE_PG7VM: PG7V
	{
		class ace_sys_modelspecial_replacements
		{
			rpg7v = "ACE_PG7VM";
			ace_rpg7v_pgo7 = "ACE_PG7VM_PGO7";
		};
	};
	class PG7VL: PG7V
	{
		class ace_sys_modelspecial_replacements
		{
			rpg7v = "PG7VL";
			ace_rpg7v_pgo7 = "ACE_PG7VL_PGO7";
		};
	};
	class PG7VR: PG7V
	{
		class ace_sys_modelspecial_replacements
		{
			rpg7v = "PG7VR";
			ace_rpg7v_pgo7 = "ACE_PG7VR_PGO7";
		};
	};
	class ACE_TBG7V: PG7VR
	{
		class ace_sys_modelspecial_replacements
		{
			rpg7v = "ACE_TBG7V";
			ace_rpg7v_pgo7 = "ACE_TBG7V_PGO7";
		};
	};
	class OG7: CA_LauncherMagazine
	{
		ace_replace = 1;
		class ace_sys_modelspecial_replacements
		{
			rpg7v = "OG7";
			ace_rpg7v_pgo7 = "ACE_OG7_PGO7";
		};
	};
};
class CfgWeapons
{
	class Default
	{
		ace_replace = 0;
	};
	class Launcher;
	class RPG7V: Launcher
	{
		ace_replace = 1;
	};
};
//};
