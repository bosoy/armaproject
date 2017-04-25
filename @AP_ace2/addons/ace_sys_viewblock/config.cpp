////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:08:30 2013 : Created on Mon Oct 14 23:08:30 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_viewblock : config.bin{
class CfgPatches
{
	class ace_sys_viewblock
	{
		units[] = {"ACE_Viewblock_Base","ACE_Viewblock_Inv5x5","ACE_Viewblock_Inv6x6","ACE_Viewblock_Inv7x7","ACE_Viewblock_Inv8x8","ACE_Viewblock_Inv10x10","ACE_Viewblock_Vis10x10"};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"CAData","CATracked","CAAir","Extended_EventHandlers","ace_main","CAWeapons","CAWeapons2"};
		version = "1.14.0.597";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_viewblock
		{
			list[] = {"ace_sys_viewblock"};
		};
	};
};
class CfgAmmo
{
	class GrenadeHand;
	class SmokeShell: GrenadeHand
	{
		ACE_Simulation = "shotSmoke";
	};
	class G_40mm_Smoke: SmokeShell
	{
		ACE_Simulation = "shotSmoke";
	};
	class G_40mm_SmokeRed: G_40mm_Smoke
	{
		ACE_Simulation = "shotSmoke";
	};
	class G_40mm_SmokeGreen: G_40mm_Smoke
	{
		ACE_Simulation = "shotSmoke";
	};
	class G_40mm_SmokeYellow: G_40mm_Smoke
	{
		ACE_Simulation = "shotSmoke";
	};
	class SmokeShellRed: SmokeShell
	{
		ACE_Simulation = "shotSmoke";
	};
	class SmokeShellGreen: SmokeShell
	{
		ACE_Simulation = "shotSmoke";
	};
	class SmokeShellYellow: SmokeShell
	{
		ACE_Simulation = "shotSmoke";
	};
	class SmokeShellPurple: SmokeShell
	{
		ACE_Simulation = "shotSmoke";
	};
	class SmokeShellBlue: SmokeShell
	{
		ACE_Simulation = "shotSmoke";
	};
	class SmokeShellOrange: SmokeShell
	{
		ACE_Simulation = "shotSmoke";
	};
	class SmokeShellVehicle: SmokeShell
	{
		ACE_Simulation = "shotSmoke";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_viewblock
	{
		init = "call ('\x\ace\addons\sys_viewblock\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_viewblock
	{
		clientInit = "call ('\x\ace\addons\sys_viewblock\XEH_PostClientInit.sqf' call SLX_XEH_COMPILE)";
		serverInit = "call ('\x\ace\addons\sys_viewblock\XEH_PostServerInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class Tank
	{
		ace_sys_viewblock = "if (local (_this select 0) && {(_this select 4) isKindOf 'SmokeLauncherAmmo' || {(_this select 4) isKindOf 'SmokeShellVehicle'}}) then { _this spawn ace_sys_viewblock_fnc_fired_veh}";
	};
	class Car
	{
		ace_sys_viewblock = "if (local (_this select 0) && {(_this select 4) isKindOf 'SmokeLauncherAmmo' || {(_this select 4) isKindOf 'SmokeShellVehicle'}}) then { _this spawn ace_sys_viewblock_fnc_fired_veh}";
	};
};
class CfgVehicleClasses
{
	class ACE_Misc
	{
		displayName = "ACE Misc";
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ACE_Viewblock_EnableAIGrassVB_Mod: ACE_Logic
	{
		displayName = "$STR_ACE_VB_GRASBLOCK_MOD";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then {ace_sys_viewblock_blockgrass = true;publicVariable 'ace_sys_viewblock_blockgrass'};";
		};
	};
	class Strategic;
	class ACE_Viewblock_Base: Strategic
	{
		scope = 1;
		vehicleClass = "ACE_Misc";
		displayName = "";
		mapSize = 0.1;
		side = 3;
		accuracy = 0.005;
		icon = "";
		animated = 0;
		simulation = "House";
		camouflage = 10;
		audible = 40;
		irtarget = 0;
		lasertarget = 0;
		armor = 1000000;
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		cost = 100000000;
		threat[] = {0,0,0};
		model = "\x\ace\addons\sys_viewblock\ace_vb.p3d";
		class DestructionEffects{};
		destrType = "DestructNo";
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class ACE_Viewblock_Inv5x5: ACE_Viewblock_Base
	{
		model = "\x\ace\addons\sys_viewblock\ace_vb_5x5.p3d";
	};
	class ACE_Viewblock_Inv6x6: ACE_Viewblock_Base
	{
		model = "\x\ace\addons\sys_viewblock\ace_vb_6x6.p3d";
	};
	class ACE_Viewblock_Inv7x7: ACE_Viewblock_Base
	{
		model = "\x\ace\addons\sys_viewblock\ace_vb_7x7.p3d";
	};
	class ACE_Viewblock_Inv8x8: ACE_Viewblock_Base
	{
		model = "\x\ace\addons\sys_viewblock\ace_vb_8x8.p3d";
	};
	class ACE_Viewblock_Inv10x10: ACE_Viewblock_Base
	{
		model = "\x\ace\addons\sys_viewblock\ace_vb_10x10.p3d";
	};
	class ACE_Viewblock_InvWPxWP: ACE_Viewblock_Base
	{
		model = "\x\ace\addons\sys_viewblock\ace_vb_wpxwp.p3d";
	};
	class ACE_Viewblock_Gas: ACE_Viewblock_Base
	{
		model = "\x\ace\addons\sys_viewblock\ace_vb_gas.p3d";
	};
	class ACE_Viewblock_Gas_Debug: ACE_Viewblock_Base
	{
		model = "\x\ace\addons\sys_viewblock\ace_vb_gas_debug.p3d";
	};
	class ACE_Viewblock_Vis10x10: ACE_Viewblock_Base
	{
		model = "\x\ace\addons\sys_viewblock\ace_vb_10x10_vis.p3d";
	};
	class ACE_Viewblock_Blind: ACE_Viewblock_Base
	{
		model = "\x\ace\addons\sys_viewblock\ace_vb_blind.p3d";
	};
	class ACE_Viewblock_ProneInGrass: ACE_Viewblock_Base
	{
		model = "\x\ace\addons\sys_viewblock\ace_vb_proneingrass.p3d";
	};
	class ACE_Viewblock_ProneInGrass_Debug: ACE_Viewblock_Base
	{
		model = "\x\ace\addons\sys_viewblock\ace_vb_proneingrass_debug.p3d";
	};
};
//};
