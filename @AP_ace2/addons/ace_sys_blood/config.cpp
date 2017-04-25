////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Jul 15 17:10:03 2013 : Created on Mon Jul 15 17:10:03 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_blood : config.bin{
class CfgPatches
{
	class ace_sys_blood
	{
		units[] = {"ACE_Blooddrop_1","ACE_Blooddrop_2"};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main"};
		version = "1.14.0.595";
		author[] = {"Sickboy"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_blood
		{
			list[] = {"ace_sys_blood"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_blood
	{
		init = "call ('\x\ace\addons\sys_blood\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_blood\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_blood
	{
		clientInit = "call ('\x\ace\addons\sys_blood\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Hit_EventHandlers
{
	class CAManBase
	{
		ace_sys_blood = "if ((_this select 0) == vehicle (_this select 0)) then {_this call ace_sys_blood_fnc_hit}";
	};
};
class Extended_Killed_EventHandlers
{
	class CAManBase
	{
		ace_sys_blood = "if ((_this select 0) == vehicle (_this select 0)) then {_this call ace_sys_blood_fnc_hit}";
	};
};
class Extended_Dammaged_EventHandlers
{
	class CAManBase
	{
		ace_sys_blood = "_this call ace_sys_blood_fnc_damaged";
	};
};
class CfgNonAIVehicles
{
	class Bird;
	class ACE_Bloodsplat_1: Bird
	{
		scope = 1;
		vehicleClass = "";
		displayName = "";
		model = "\x\ace\addons\sys_blood\splat_1.p3d";
		submerged = 0;
		submergeSpeed = 0;
		timeToLive = 1;
		disappearAtContact = 1;
		maxSpeed = 7000;
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		weight = 1;
		gravityFactor = 1;
		airFriction2[] = {0,0,0};
		airFriction1[] = {0,0,0};
		airFriction0[] = {0,0,0};
	};
	class ACE_Bloodsplat_2: ACE_Bloodsplat_1
	{
		model = "\x\ace\addons\sys_blood\splat_2.p3d";
	};
};
class CfgVehicles
{
	class Static;
	class ACE_Blooddrop_1: Static
	{
		htMin = 60;
		htMax = 1800;
		afMax = 200;
		mfMax = 100;
		mFact = 0;
		tBody = 0;
		simulation = "SeaGull";
		armor = 0;
		timeToLive = 1;
		side = -1;
		shadow = 0;
		scope = 1;
		VehicleClass = "";
		displayName = "";
		model = "\x\ace\addons\sys_blood\drop_1.p3d";
		accuracy = 0;
		camouflage = 0;
		destrType = "DestructNo";
		minHeight = 0;
		avgHeight = 0;
		maxHeight = 0;
		minSpeed = 0;
		maxSpeed = 0;
		acceleration = 0;
		turning = 0;
		straightDistance = 0;
		flySound[] = {"",0.0316228,1,1};
		singSound[] = {"",0.0316228,1,1};
		canBeShot = 0;
		airFriction2[] = {25,12,2.5};
		airFriction1[] = {1500,700,100};
		airFriction0[] = {40,20,60};
	};
	class ACE_Blooddrop_2: ACE_Blooddrop_1
	{
		model = "\x\ace\addons\sys_blood\drop_2.p3d";
	};
};
//};
