////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:07:40 2013 : Created on Sat Jun 08 13:07:40 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_towing : config.bin{
class CfgPatches
{
	class ace_sys_towing
	{
		units[] = {"ACE_TowingRope_1"};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_sys_vehicledamage","ace_sys_interaction"};
		version = "1.14.0.593";
		author[] = {"Sickboy"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_towing
		{
			list[] = {"ace_sys_towing"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_towing
	{
		clientInit = "call ('\x\ace\addons\sys_towing\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgMagazines
{
	class ACE_Rope_M;
	class ACE_Rope_TOW_M: ACE_Rope_M
	{
		ACE_Size = 64;
		ACE_Weight = 10;
		ace_sys_towing_veh = "ACE_TowingRope";
	};
	class ACE_Rope_TOW_M_5: ACE_Rope_TOW_M
	{
		scope = 2;
		displayName = "$STR_DN_ACE_TOWINGROPE_5";
		ace_sys_towing_veh = "ACE_TowingRope_5";
	};
};
class CfgVehicles
{
	class ACE_Object;
	class ACE_TowingRope: ACE_Object
	{
		scope = 1;
		displayName = "";
		model = "\x\ace\addons\sys_towing\ace_tow1.p3d";
		destructype = "Destructno";
		armor = 999999;
		ace_sys_towing_mag = "ACE_Rope_TOW_M";
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
	};
	class ACE_TowingRope_5: ACE_TowingRope
	{
		scope = 1;
		displayName = "$STR_DN_ACE_TOWINGROPE_5";
		ace_sys_towing_mag = "ACE_Rope_TOW_M_5";
	};
};
//};
