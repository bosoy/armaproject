////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:45:01 2013 : Created on Sat Apr 06 11:45:01 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_fastroping : config.bin{
class CfgPatches
{
	class ace_sys_fastroping
	{
		units[] = {"ACE_FastRope_Base","ACE_FastRope_50","ACE_FastRope_60","ACE_FastRope_90","ACE_FastRope_120","ACE_NoFastRope","ACE_Rope_Box_Base","ACE_RopeBox"};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_weapon","ace_sys_interaction","CAAir","CAAir2","CAAir3","CAAir_E","CAAir_E_AH6J"};
		version = "1.14.0.590";
		author[] = {"Xeno"};
	};
};
class CfgVehicleClasses
{
	class ACE_Ammunition_Rope
	{
		displayName = "$STR_VC_ACE_AMMO_ROPE";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_fastroping
	{
		init = "call ('\x\ace\addons\sys_fastroping\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_fastroping
	{
		clientInit = "call ('\x\ace\addons\sys_fastroping\XEH_postInitClient.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class Air
	{
		class ace_sys_fastroping
		{
			clientInit = "_this call ace_sys_fastroping_fnc_init";
		};
	};
};
class CfgMovesBasic
{
	class Actions;
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class MLB_Fast_rope: Crew
		{
			file = "\x\ace\addons\sys_fastroping\anims\MLB_Fast_Rope.rtm";
			interpolateTo[] = {};
		};
	};
};
class CfgVehicles
{
	class BuoySmall;
	class ACE_FastRope_Base: BuoySmall
	{
		scope = 1;
		model = "\x\ace\addons\sys_fastroping\ace_rope_50.p3d";
		displayName = "";
		mapSize = 0;
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class ACE_FastRope_50: ACE_FastRope_Base
	{
		model = "\x\ace\addons\sys_fastroping\ace_rope_50.p3d";
	};
	class ACE_FastRope_60: ACE_FastRope_50
	{
		model = "\x\ace\addons\sys_fastroping\ace_rope_60.p3d";
	};
	class ACE_FastRope_90: ACE_FastRope_50
	{
		model = "\x\ace\addons\sys_fastroping\ace_rope_90.p3d";
	};
	class ACE_FastRope_120: ACE_FastRope_50
	{
		model = "\x\ace\addons\sys_fastroping\ace_rope_120.p3d";
	};
	class House;
	class LadderLong: House{};
	class ACE_Jakobladder: LadderLong
	{
		scope = 2;
		displayName = "";
		mapsize = 0;
		model = "\x\ace\addons\sys_fastroping\ace_jakobladder.p3d";
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class Air;
	class Helicopter: Air
	{
		ACE_canFastrope = 0;
	};
	class Plane: Air
	{
		ACE_canFastrope = 0;
	};
	class UH60_Base;
	class MH60S: UH60_Base
	{
		ACE_canFastrope = 1;
		ACE_RopeAttachment[] = {{-0.9,2,-2}};
	};
	class UH60M_base_EP1: UH60_Base
	{
		ACE_canFastrope = 1;
		ACE_RopeAttachment[] = {{-0.9,2,-2}};
	};
	class UH1_Base: Helicopter
	{
		ACE_canFastrope = 1;
		ACE_RopeAttachment[] = {{-0.9,-3.5,-1.5}};
	};
	class MV22: Plane
	{
		ACE_canFastrope = 1;
		ACE_RopeAttachment[] = {{0,-5,-2.1},{1.2,3.5,-2.4}};
	};
	class Mi24_Base: Helicopter
	{
		ACE_canFastrope = 1;
		ACE_RopeAttachment[] = {{-0.86,3.5,-2},{0.62,3.5,-2}};
	};
	class Mi17_base: Helicopter
	{
		ACE_canFastrope = 1;
		ACE_RopeAttachment[] = {{0.03,-2.5,0},{-1.05,5.1,-2.25}};
	};
	class CH47_base_EP1: Helicopter
	{
		ACE_canFastrope = 1;
		ACE_RopeAttachment[] = {{0,0.14,-3},{0,-7.5,-1.1}};
	};
	class UH1H_base: Helicopter
	{
		ACE_canFastrope = 1;
		ACE_RopeAttachment[] = {{-0.9,2,-1.5}};
	};
	class AH6_Base_EP1;
	class MH6J_EP1: AH6_Base_EP1
	{
		ACE_canFastrope = 1;
		ACE_RopeAttachment[] = {{-1.05115,0.735097,-1.15},{1.05115,0.735097,-1.15}};
	};
	class BAF_Merlin_HC3_D: Helicopter
	{
		ACE_canFastrope = 1;
		ACE_RopeAttachment[] = {{-1,5.5,-2},{1.5,3.7,-2}};
	};
	class AW159_Lynx_BAF: Helicopter
	{
		ACE_canFastrope = 1;
		ACE_RopeAttachment[] = {{0.9,3.5,-1.05},{-0.9,3.5,-1.05}};
	};
	class Ka60_Base_PMC: Helicopter
	{
		ACE_canFastrope = 1;
		ACE_RopeAttachment[] = {{-1.4,1.3,-0.1},{1.4,1.3,-0.1}};
	};
	class ACE_Logic;
	class ACE_NoFastRope: ACE_Logic
	{
		displayName = "$STR_ACE_FASTROPE";
		icon = "\x\ace\addons\sys_fastroping\data\icon\icon_ace_fastrope_ca.paa";
		picture = "\x\ace\addons\sys_fastroping\data\icon\icon_ace_fastrope_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "ACE_NoFastRope = false; publicVariable 'ACE_NoFastRope'";
		};
	};
	class ReammoBox;
	class ACE_Rope_Box_Base: ReammoBox
	{
		scope = 1;
		vehicleClass = "ACE_Ammunition_Rope";
		displayName = "";
		model = "\Ca\misc\Misc_cargo_cont_tiny";
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class ACE_RopeBox: ACE_Rope_Box_Base
	{
		scope = 2;
		displayName = "$STR_VDN_ACE_ROPE_BOX";
		class TransportMagazines
		{
			class _xx_ACE_Rope_M_50
			{
				magazine = "ACE_Rope_M_50";
				count = 5;
			};
			class _xx_ACE_Rope_M_60
			{
				magazine = "ACE_Rope_M_60";
				count = 5;
			};
			class _xx_ACE_Rope_M_90
			{
				magazine = "ACE_Rope_M_90";
				count = 5;
			};
			class _xx_ACE_Rope_M_120
			{
				magazine = "ACE_Rope_M_120";
				count = 5;
			};
			class _xx_ACE_Rope_M5
			{
				magazine = "ACE_Rope_M5";
				count = 20;
			};
		};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class ACE_Rope_M: CA_Magazine
	{
		scope = 1;
		displayName = "$STR_DN_ACE_ROPE_M";
		picture = "\x\ace\addons\sys_fastroping\data\equip\m_rope_ca.paa";
		model = "\x\ace\addons\sys_fastroping\m_ace_rope.p3d";
		type = "3 * 256";
		ammo = "FakeAmmo";
		count = 1;
		initSpeed = 0;
		maxLeadSpeed = 0;
		nameSound = "mine";
		ACE_Weight = 2;
		ACE_Size = 400;
		ACE_NoPack = 1;
		descriptionShort = "";
	};
	class ACE_Rope_M_50: ACE_Rope_M
	{
		scope = 2;
		type = "2 * 256";
		displayName = "$STR_DN_ACE_ROPE_M50";
		ACE_FastRope_Length = 16;
		ACE_FastRope_Model = "ACE_FastRope_50";
		ACE_Size = 64;
		ACE_Weight = 14.3256;
	};
	class ACE_Rope_M_60: ACE_Rope_M
	{
		scope = 2;
		displayName = "$STR_DN_ACE_ROPE_M60";
		ACE_FastRope_Length = 19;
		ACE_FastRope_Model = "ACE_FastRope_60";
		ACE_Size = 76;
		ACE_Weight = 17.202;
	};
	class ACE_Rope_M_90: ACE_Rope_M
	{
		scope = 2;
		displayName = "$STR_DN_ACE_ROPE_M90";
		ACE_FastRope_Length = 28;
		ACE_FastRope_Model = "ACE_FastRope_90";
		ACE_Size = 112;
		ACE_Weight = 25.756;
	};
	class ACE_Rope_M_120: ACE_Rope_M
	{
		scope = 2;
		displayName = "$STR_DN_ACE_ROPE_M120";
		ACE_FastRope_Length = 37;
		ACE_FastRope_Model = "ACE_FastRope_120";
		ACE_Size = 148;
		ACE_Weight = 34.31;
	};
};
class CfgWeapons
{
	class Default;
	class Put: Default
	{
		class ACE_Dummy_Utility;
		class ace_sys_fastroping: ACE_Dummy_Utility
		{
			magazines[] = {"ACE_Rope_M","ACE_Rope_M_50","ACE_Rope_M_60","ACE_Rope_M_90","ACE_Rope_M_120"};
		};
	};
};
//};
