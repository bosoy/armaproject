////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:07:38 2013 : Created on Mon Oct 14 23:07:38 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_maptools : config.bin{
class CfgPatches
{
	class ace_sys_maptools
	{
		units[] = {};
		weapons[] = {"ACE_Map_Tools"};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAUI","ACE_main","ace_sys_interaction"};
		version = "1.14.0.597";
		author[] = {"Noubernou"};
		class ACE_Options
		{
			title = "$STR_ACE_MAPTOOLS_NAME";
			class place_ruler
			{
				title = "$STR_ACE_MAPTOOLS_PLACERULER";
			};
			class align_ruler
			{
				title = "$STR_ACE_MAPTOOLS_ALIGNRULER";
			};
			class start_drawing
			{
				title = "$STR_ACE_MAPTOOLS_STARTDRAWING";
			};
			class end_straight_line
			{
				title = "$STR_ACE_MAPTOOLS_ENDSTRAIGHTLINE";
			};
			class delete_line
			{
				title = "$STR_ACE_MAPTOOLS_DELETELINE";
			};
		};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_maptools
		{
			list[] = {"ace_sys_maptools"};
		};
	};
};
class CfgMarkers
{
	class FlatCompass
	{
		name = "Flat Compass";
		icon = "\x\ace\addons\sys_maptools\data\flat_compass.paa";
		color[] = {1,1,1,1.0};
		size = 32;
		scope = 0;
		shadow = "true";
	};
	class FlatCompass50
	{
		name = "Flat Compass 50%";
		icon = "\x\ace\addons\sys_maptools\data\flat_compass_50.paa";
		color[] = {1,1,1,1.0};
		size = 32;
		scope = 0;
		shadow = "true";
	};
	class FlatCompass25
	{
		name = "Flat Compass 25%";
		icon = "\x\ace\addons\sys_maptools\data\flat_compass_25.paa";
		color[] = {1,1,1,1.0};
		size = 32;
		scope = 0;
		shadow = "true";
	};
	class FlatCompass12
	{
		name = "Flat Compass 12.5%";
		icon = "\x\ace\addons\sys_maptools\data\flat_compass_12.paa";
		color[] = {1,1,1,1.0};
		size = 32;
		scope = 0;
		shadow = "true";
	};
	class FlatCompassRose
	{
		name = "Flat Compass Rose";
		icon = "\x\ace\addons\sys_maptools\data\flat_compass_rose.paa";
		color[] = {1,1,1,1.0};
		size = 32;
		scope = 0;
		shadow = "false";
	};
	class FlatCompassRose50
	{
		name = "Flat Compass Rose 50%";
		icon = "\x\ace\addons\sys_maptools\data\flat_compass_rose_50.paa";
		color[] = {1,1,1,1.0};
		size = 32;
		scope = 0;
		shadow = "false";
	};
	class FlatCompassRose25
	{
		name = "Flat Compass Rose 25%";
		icon = "\x\ace\addons\sys_maptools\data\flat_compass_rose_25.paa";
		color[] = {1,1,1,1.0};
		size = 32;
		scope = 0;
		shadow = "false";
	};
	class FlatCompassRose12
	{
		name = "Flat Compass Rose 12.5";
		icon = "\x\ace\addons\sys_maptools\data\flat_compass_rose_12.paa";
		color[] = {1,1,1,1.0};
		size = 32;
		scope = 0;
		shadow = "false";
	};
};
class CfgWeapons
{
	class ItemCore;
	class ACE_Map_Tools: ItemCore
	{
		scope = 2;
		displayName = "$STR_ACE_MAPTOOLS_NAME";
		picture = "\x\ace\addons\sys_maptools\data\map_tools_icon.paa";
		descriptionShort = "$STR_ACE_MAPTOOLS_NAME";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_maptools
	{
		clientInit = "call ('\x\ace\addons\sys_maptools\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_maptools
	{
		clientInit = "call ('\x\ace\addons\sys_maptools\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
//};
