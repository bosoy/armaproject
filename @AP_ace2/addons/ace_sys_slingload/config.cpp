////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:08:20 2013 : Created on Mon Oct 14 23:08:20 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_slingload : config.bin{
class CfgPatches
{
	class ace_sys_slingload
	{
		units[] = {"ACE_Slingrope_L","ACE_Slingrope_M","ACE_Slingrope_P","ACE_Slingrope"};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_weapon","ace_sys_interaction","CAAir","CAAir2","CAAir3","CAAir_E_AH6J"};
		version = "1.14.0.597";
		author[] = {"Rocko"};
	};
	class ace_sys_ravlifter
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ace_main"};
		version = "1.14.0.597";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_slingload
		{
			list[] = {"ace_sys_slingload"};
		};
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ACE_DisableSlingload: ACE_Logic
	{
		displayName = "$STR_DN_ACE_DISABLE_SLINGLOAD";
		icon = "\x\ace\addons\sys_slingload\data\icon\icon_ace_lifter_ca.paa";
		picture = "\x\ace\addons\sys_slingload\data\icon\icon_ace_lifter_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then { ace_sys_slingload_disabled = true; publicvariable 'ace_sys_slingload_disabled'};";
		};
	};
	class Thing;
	class ACE_Slingrope_L: Thing
	{
		scope = 1;
		animated = 0;
		displayName = "";
		model = "\x\ace\addons\sys_slingload\ace_slingrope_L.p3d";
		destructype = "Destructno";
		cost = 0;
		armor = 999999;
		ace_slingrope = 1;
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class ACE_Slingrope_M: ACE_Slingrope_L
	{
		model = "\x\ace\addons\sys_slingload\ace_slingrope_M.p3d";
		ace_slingrope = 1;
	};
	class ACE_Slingrope_P: ACE_Slingrope_L
	{
		model = "\x\ace\addons\sys_slingload\ace_slingrope_P.p3d";
		ace_slingrope = 1;
	};
	class ACE_Slingrope: ACE_Slingrope_L
	{
		model = "\x\ace\addons\sys_slingload\ace_slingrope.p3d";
		ace_slingrope = 1;
	};
	class Air;
	class Helicopter: Air
	{
		ACE_canLift = 0;
	};
	class Plane: Air
	{
		ACE_canLift = 0;
	};
	class UH60_Base;
	class MH60S: UH60_Base
	{
		ACE_canLift = 1;
		ACE_GeoLifterAttachment[] = {{0,1.54,-5.1}};
		ACE_MaxLoad = 5886;
		ACE_Weight = 5224;
	};
	class UH60M_US_base_EP1;
	class UH60M_EP1: UH60M_US_base_EP1
	{
		ACE_canLift = 1;
		ACE_GeoLifterAttachment[] = {{0,1.25,-5.25}};
		ACE_MaxLoad = 5886;
		ACE_Weight = 5224;
	};
	class UH1_Base: Helicopter
	{
		ACE_canLift = 1;
		ACE_GeoLifterAttachment[] = {{0,-4.3,-4.9}};
		ACE_MaxLoad = 3000;
		ACE_Weight = 5370;
	};
	class UH1H_Base: Helicopter
	{
		ACE_canLift = 1;
		ACE_GeoLifterAttachment[] = {{0,1.2,-4.8}};
		ACE_MaxLoad = 3000;
		ACE_Weight = 5370;
	};
	class MV22: Plane
	{
		ACE_canLift = 1;
		ACE_GeoLifterAttachment[] = {{0,0,-5.9}};
		ACE_MaxLoad = 6800;
		ACE_Weight = 15000;
	};
	class Mi24_Base: Helicopter
	{
		ACE_canLift = 1;
		ACE_GeoLifterAttachment[] = {{-0.1,2.5,-5.2}};
		ACE_MaxLoad = 2600;
		ACE_Weight = 11000;
	};
	class Mi17_base: Helicopter
	{
		ACE_canLift = 1;
		ACE_GeoLifterAttachment[] = {{0,1.9,-5.5}};
		ACE_MaxLoad = 5900;
		ACE_Weight = 7100;
	};
	class CH47_base_EP1: Helicopter
	{
		ACE_canLift = 1;
		ACE_GeoLifterAttachment[] = {{0,0,-5.6}};
		ACE_MaxLoad = 10000;
		ACE_Weight = 12000;
	};
	class AH6_Base_EP1;
	class MH6J_EP1: AH6_Base_EP1
	{
		ACE_canLift = 0;
		ACE_GeoLifterAttachment[] = {{0,-0.8,0.5}};
		ACE_MaxLoad = 1000;
		ACE_Weight = 3370;
	};
	class BAF_Merlin_HC3_D: Helicopter
	{
		ACE_canLift = 1;
		ACE_GeoLifterAttachment[] = {{0.2,2.5,-4.9}};
		ACE_MaxLoad = 6000;
		ACE_Weight = 11000;
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_slingload
	{
		init = "call ('\x\ace\addons\sys_slingload\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_slingload\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class ACE_Rope_MRL: CA_Magazine
	{
		scope = 1;
		displayName = "$STR_DN_ACE_ROPE_MRL";
		picture = "\x\ace\addons\sys_slingload\data\equip\m_rope_ca.paa";
		model = "\x\ace\addons\sys_slingload\m_ace_rope.p3d";
		type = "3 * 256";
		ammo = "FakeAmmo";
		count = 1;
		initSpeed = 0;
		maxLeadSpeed = 0;
		nameSound = "mine";
		ACE_Weight = 2;
		ACE_Size = 400;
		ACE_NoPack = 1;
		ACE_SlingRope = 1;
		descriptionShort = "";
	};
	class ACE_Rope_M5: ACE_Rope_MRL
	{
		scope = 2;
		displayName = "$STR_DN_ACE_ROPE_M5";
		ACE_Size = 64;
		ACE_Weight = 14.3256;
	};
};
class CfgWeapons
{
	class Default;
	class Put: Default
	{
		class ACE_Dummy_Utility;
		class ace_sys_ravlifter: ACE_Dummy_Utility
		{
			magazines[] = {"ACE_Rope_MRL","ACE_Rope_M5"};
		};
	};
};
//};
