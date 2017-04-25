////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:46:52 2013 : Created on Sat Apr 06 11:46:52 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_survival : config.bin{
class CfgPatches
{
	class ace_sys_survival
	{
		units[] = {"ACE_Lifeboat","ACE_Lifeboat_US"};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","CAWeapons2","CAData","ace_main"};
		version = "1.14.0.590";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_survival
		{
			list[] = {"ace_sys_survival"};
		};
	};
};
class CfgVehicles
{
	class Ship;
	class ACE_Lifeboat: Ship
	{
		scope = 1;
		displayName = "$STR_DN_ACE_LIFEBOAT";
		displayNameShort = "$STR_DN_ACE_LIFEBOAT";
		side = 1;
		faction = "BIS_US";
		class Library
		{
			libTextDesc = "";
		};
		crew = "US_Soldier_Crew_EP1";
		typicalCargo[] = {};
		model = "\x\ace\addons\sys_survival\ace_loveboat.p3d";
		picture = "\x\ace\addons\sys_survival\data\picture\zodiac_CA.paa";
		Icon = "\x\ace\addons\sys_survival\data\icon\icomap_rubber_CA.paa";
		driverAction = "Zodiac_Driver";
		cargoAction[] = {"Zodiac_Driver","Zodiac_Driver","Zodiac_Driver"};
		transportSoldiers = 3;
		class TransportMagazines{};
		commanderCanSee = "2+8+32";
		gunnerCanSee = "2+8+32";
		driverCanSee = "2+8+32";
		class Turrets{};
		class UserActions
		{
			class ACE_DestroyLifeboat
			{
				displayName = "$STR_UA_ACE_DEFLATE_LIFEBOAT";
				position = "zamerny";
				radius = 5;
				priority = 0;
				condition = "(driver this == player) && {(alive this)} && {!(this getVariable ""ace_sys_survival_deflate"")}";
				statement = "this spawn ace_sys_survival_fnc_deflate";
				onlyForPlayer = 1;
			};
		};
		ACE_Lademeister = 1;
		ACE_Viewport = 10;
		maxSpeed = 0;
		class NVGMarkers
		{
			class NVGMarker01
			{
				name = "nvg_marker";
				color[] = {0.03,0.003,0.003,1};
				ambient[] = {0.003,0.0003,0.0003,1};
				brightness = 0.001;
				blinking = 1;
			};
		};
	};
	class ACE_Lifeboat_US: ACE_Lifeboat
	{
		scope = 2;
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_survival
	{
		clientInit = "call ('\x\ace\addons\sys_survival\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class ACE_Lifeboat
	{
		class ace_sys_survival
		{
			Init = "_this call ace_sys_survival_fnc_init";
		};
	};
};
//};
