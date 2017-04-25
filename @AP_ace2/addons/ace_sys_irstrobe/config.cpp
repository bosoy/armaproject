////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:06:45 2013 : Created on Sat Jun 08 13:06:45 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_irstrobe : config.bin{
class CfgPatches
{
	class ace_sys_irstrobe
	{
		units[] = {"ACE_MS2000_STROBE_OBJECT","ACE_VIP_STROBE_OBJECT"};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","Extended_EventHandlers","ace_main","ace_sys_nvg","ace_sys_interaction"};
		version = "1.14.0.593";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_irstrobe
		{
			list[] = {"ace_sys_irstrobe"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_irstrobe
	{
		init = "call ('\x\ace\addons\sys_irstrobe\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_irstrobe\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Killed_EventHandlers
{
	class CAManBase
	{
		ace_sys_irstrobe = "_this call ace_sys_irstrobe_fnc_killed";
	};
};
class CfgAmmo
{
	class GrenadeCore;
	class IRStrobeBase: GrenadeCore
	{
		deflecting = 10;
		ACE_Simulation = "shotIR";
		visibleFire = 0;
		audibleFire = 0;
		visibleFireTime = 0;
	};
	class IRStrobe: IRStrobeBase
	{
		displayName = "MS-2000";
		model = "\x\ace\addons\sys_irstrobe\ace_irstrobe_ms2000.p3d";
		deflecting = 10;
		simulation = "shotShell";
		class NVGMarkers{};
		ACE_IRObject = "ACE_MS2000_STROBE_OBJECT";
	};
	class ACE_VIP_IRStrobe: IRStrobe
	{
		displayName = "VIP Strobe";
		model = "\x\ace\addons\sys_irstrobe\ace_irstrobe_vip.p3d";
		ACE_IRObject = "ACE_VIP_STROBE_OBJECT";
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class IR_Strobe_Target: CA_Magazine
	{
		model = "\x\ace\addons\sys_irstrobe\ace_irstrobe_vip.p3d";
		displayName = "VIP Strobe";
		displaynameshort = "";
		descriptionShort = "$STR_DSS_ACE_IRSTROBE";
		namesound = "obj_object";
		namesoundweapon = "obj_object";
		ammo = "ACE_VIP_IRStrobe";
		class Library
		{
			libTextDesc = "";
		};
		ACE_Weight = 0.4;
		ACE_Size = 1200;
	};
	class IR_Strobe_Marker: IR_Strobe_Target
	{
		model = "\x\ace\addons\sys_irstrobe\ace_irstrobe_ms2000.p3d";
		picture = "\x\ace\addons\sys_irstrobe\data\equip\m_irstrobe_ca.paa";
		displayName = "MS-2000";
		displaynameshort = "";
		descriptionShort = "$STR_DSS_ACE_IRSTROBE";
		namesound = "obj_object";
		namesoundweapon = "obj_object";
		ammo = "IRStrobe";
		class Library
		{
			libTextDesc = "";
		};
		ACE_Weight = 0.115;
		ACE_Size = 211;
	};
	class ACE_IRStrobe: IR_Strobe_Marker
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
	};
};
class CfgWeapons
{
	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		class ThrowMuzzle;
		class IRStrobe: ThrowMuzzle
		{
			displayName = "$STR_DN_ACE_IRSTROBE";
			magazines[] = {"IR_Strobe_Marker","IR_Strobe_Target"};
		};
	};
};
class CfgVehicles
{
	class Thing;
	class RoadCone: Thing
	{
		class ACE;
	};
	class ACE_MS2000_STROBE_OBJECT: RoadCone
	{
		htMin = 60;
		htMax = 1800;
		afMax = 200;
		mfMax = 100;
		mFact = 1;
		tBody = 250;
		scope = 1;
		mapsize = 0;
		displayName = "$STR_DN_ACE_IRSTROBE";
		model = "\x\ace\addons\sys_irstrobe\ace_irstrobe_ms2000_throwie.p3d";
		class ACE: ACE
		{
			class ACE_IRSTROBE
			{
				magazine = "IR_Strobe_Marker";
			};
		};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class ACE_VIP_STROBE_OBJECT: ACE_MS2000_STROBE_OBJECT
	{
		displayName = "VIP Strobe";
		model = "\x\ace\addons\sys_irstrobe\ace_irstrobe_vip_throwie.p3d";
		class ACE: ACE
		{
			class ACE_IRSTROBE: ACE_IRSTROBE
			{
				magazine = "IR_Strobe_Target";
			};
		};
	};
};
//};
