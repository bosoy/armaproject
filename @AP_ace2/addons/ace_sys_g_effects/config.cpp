////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 09:06:38 2013 : Created on Sat Jun 08 09:06:38 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_g_effects : config.bin{
class CfgPatches
{
	class ace_sys_g_effects
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_sys_goggles"};
		version = "1.14.0.593";
		author[] = {"Rocko","Xeno"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_g_effects
	{
		init = "call ('\x\ace\addons\sys_g_effects\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_g_effects\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class Plane
	{
		class ace_sys_g_effects
		{
			clientInit = "_this call ace_sys_g_effects_fnc_checkp";
			exclude[] = {"BIS_Steerable_Parachute","UAV"};
		};
	};
};
class Extended_Engine_EventHandlers
{
	class Plane
	{
		class ace_sys_g_effects
		{
			engine = "if (local (_this select 0)) then {_this call ace_sys_g_effects_fnc_start_engine}";
			exclude[] = {"BIS_Steerable_Parachute","UAV"};
		};
	};
};
class RscTitles
{
	class ACE_geffectsfb
	{
		idd = -1;
		movingEnable = 0;
		duration = 1e+011;
		fadein = 1.5;
		fadeout = 0;
		name = "ACE_geffectsfb";
		class controls
		{
			class ACE_geffectsfb_BG
			{
				idc = 1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_g_effects\data\fovbig.paa";
			};
		};
	};
	class ACE_geffectsfs
	{
		idd = -1;
		movingEnable = 0;
		duration = 1e+011;
		fadein = 1.5;
		fadeout = 0;
		name = "ACE_geffectsfs";
		class controls
		{
			class ACE_geffectsfs_BG
			{
				idc = 1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_g_effects\data\fovsmall.paa";
			};
		};
	};
	class ACE_geffectsfb_nothing
	{
		idd = -1;
		movingEnable = 0;
		duration = 1;
		fadein = 0;
		fadeout = 1.5;
		name = "ACE_geffectsfb_nothing";
		class controls
		{
			class ACE_geffectsfb_nothing_BG2
			{
				idc = 2;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_g_effects\data\fovbig.paa";
			};
		};
	};
	class ACE_geffectsfs_nothing
	{
		idd = -1;
		movingEnable = 0;
		duration = 1;
		fadein = 0;
		fadeout = 1.5;
		name = "ACE_geffectsfs_nothing";
		class controls
		{
			class ACE_geffectsfs_nothing_BG2
			{
				idc = 2;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_g_effects\data\fovsmall.paa";
			};
		};
	};
	class ACE_geffects_nothing
	{
		idd = -1;
		movingEnable = 0;
		duration = 1;
		fadein = 0;
		fadeout = 0;
		name = "ACE_geffects_nothing";
		class controls
		{
			class ACE_geffects_nothing_BG2
			{
				idc = 2;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_g_effects\data\clear_empty_ca.paa";
			};
		};
	};
};
class CfgSounds
{
	class ACE_OverGLimit_US
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_g_effects\data\sounds\usa\GOverLimit.ogg","db+10",1.0};
		titles[] = {};
	};
	class ACE_MaximumG_US
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_g_effects\data\sounds\usa\MaximumG.ogg","db+10",1.0};
		titles[] = {};
	};
	class ACE_OverGLimit_RU
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_g_effects\data\sounds\rus\GOverLimit.wav","db+10",1.0};
		titles[] = {};
	};
	class ACE_MaximumG_RU
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_g_effects\data\sounds\rus\MaximumG.wav","db+10",1.0};
		titles[] = {};
	};
};
//};
