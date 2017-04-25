////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:06:37 2013 : Created on Sat Jun 08 13:06:37 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_frag : config.bin{
class CfgPatches
{
	class ace_sys_frag
	{
		units[] = {"ACE_Frag_Disable_Logic"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","CAMisc_E","ace_sys_missileguidance","ace_c_weapon"};
		version = "1.14.0.593";
		author[] = {"Nou"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_frag
		{
			list[] = {"ace_sys_frag"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_frag
	{
		init = "call ('\x\ace\addons\sys_frag\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_frag
	{
		init = "call ('\x\ace\addons\sys_frag\XEH_post_init.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class AllVehicles
	{
		ace_sys_frag = "_this call ace_sys_frag_fnc_fired";
	};
};
class CfgAmmo
{
	class GrenadeBase;
	class Grenade;
	class GrenadeHand: Grenade
	{
		ACE_FRAG_SKIP = 0;
		ACE_FRAG_FORCE = 1;
		ACE_FRAG_MULTIPLIER = 1.2;
	};
	class GrenadeHand_stone: GrenadeHand
	{
		ACE_FRAG_SKIP = 1;
	};
	class SmokeShell: GrenadeHand
	{
		ACE_FRAG_SKIP = 1;
	};
	class RocketBase;
	class R_Hydra_HE: RocketBase
	{
		ACE_FRAG_SKIP = 1;
	};
	class R_57mm_HE: RocketBase
	{
		ACE_FRAG_SKIP = 1;
	};
	class R_80mm_HE: RocketBase
	{
		ACE_FRAG_SKIP = 1;
	};
	class R_S8T_AT: RocketBase
	{
		ACE_FRAG_SKIP = 1;
	};
	class G_40mm_HE: GrenadeBase
	{
		ACE_FRAG_SKIP = 0;
		ACE_FRAG_FORCE = 1;
		ACE_FRAG_MULTIPLIER = 1.8;
	};
	class ACE_G_40mm_HEDP: G_40mm_HE
	{
		ACE_FRAG_MULTIPLIER = 2;
	};
	class ACE_G_40mm_HE: ACE_G_40mm_HEDP
	{
		ACE_FRAG_MULTIPLIER = 1.8;
	};
	class ACE_G_40mm_Practice: ACE_G_40mm_HE
	{
		ACE_FRAG_SKIP = 1;
	};
	class ACE_G40mm_HE_VOG25P: G_40mm_HE
	{
		ACE_FRAG_SKIP = 0;
		ACE_FRAG_FORCE = 1;
		ACE_FRAG_MULTIPLIER = 1.8;
	};
	class R_SMAW_HEDP;
	class R_MEEWS_HEDP: R_SMAW_HEDP
	{
		ACE_FRAG_FORCE = 1;
		ACE_FRAG_MULTIPLIER = 1.2;
	};
	class MissileBase;
	class M_Hellfire_AT: MissileBase
	{
		ACE_FRAG_FORCE = 1;
		ACE_FRAG_MULTIPLIER = 1.75;
	};
	class B_762x54_Ball;
	class ACE_frag_base: B_762x54_Ball
	{
		timeToLive = 12;
		typicalSpeed = 800;
	};
	class ACE_frag_tiny: ACE_frag_base
	{
		hit = 6;
		airFriction = -0.0008324;
	};
	class ACE_frag_small: ACE_frag_base
	{
		hit = 10;
		airFriction = -0.0009324;
	};
	class ACE_frag_medium: ACE_frag_base
	{
		hit = 14;
		airFriction = -0.0010324;
	};
	class ACE_frag_large: ACE_frag_base
	{
		hit = 18;
		indirectHit = 2;
		indirectHitRange = 0.25;
		airFriction = -0.0011324;
	};
	class ACE_frag_huge: ACE_frag_base
	{
		hit = 22;
		indirectHit = 4;
		indirectHitRange = 0.5;
		airFriction = -0.0012324;
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ACE_Frag_Disable_Logic: ACE_Logic
	{
		displayName = "$STR_DN_ACE_SYS_FRAG";
		icon = "\x\ace\addons\sys_frag\data\icon\ace_frag_ico_ca.paa";
		picture = "\x\ace\addons\sys_frag\data\icon\ace_frag_ico_ca.paa";
		vehicleClass = "Modules";
		class EventHandlers
		{
			init = "ace_sys_frag_enabled= false";
		};
	};
};
//};
