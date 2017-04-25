////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sun Apr 07 20:04:48 2013 : Created on Sun Apr 07 20:04:48 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_wind_deflection : config.bin{
class CfgPatches
{
	class ace_sys_wind_deflection
	{
		units[] = {};
		weapons[] = {"ACE_Kestrel4500"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_weapon","ace_settings","ace_sys_interaction"};
		version = "1.14.0.591";
		author[] = {"q1184","Rocko"};
		class ACE_Options
		{
			group = "INTERACTION";
			title = " ";
			class Toggle_Wind_Info
			{
				title = "$STR_ACE_MENU_MEASUREWIND";
			};
		};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_wind_deflection
		{
			list[] = {"ace_sys_wind_deflection"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_wind_deflection
	{
		clientInit = "call ('\x\ace\addons\sys_wind_deflection\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
		init = "call ('\x\ace\addons\sys_wind_deflection\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_wind_deflection
	{
		serverInit = "call ('\x\ace\addons\sys_wind_deflection\XEH_PostServerInit.sqf' call SLX_XEH_COMPILE)";
		init = "call ('\x\ace\addons\sys_wind_deflection\XEH_postInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class Man
	{
		class ace_sys_wind_deflection
		{
			clientFiredBisPlayer = "if (!isNull (_this select 6) && {((_this select 6) isKindOf 'bulletBase')}) then {_this call ace_sys_wind_deflection_fnc_fired_man}";
		};
	};
};
class cfgAmmo
{
	class BulletCore;
	class BulletBase: BulletCore
	{
		ace_windcoef = 0.4;
	};
	class B_545x39_Ball: BulletBase
	{
		ace_windcoef = 0.55;
	};
	class B_556x45_Ball: BulletBase
	{
		ace_windcoef = 0.55;
	};
	class B_762x39_Ball: BulletBase
	{
		ace_windcoef = 0.59;
	};
	class B_9x39_SP5: BulletBase
	{
		ace_windcoef = 0.2;
	};
	class B_762x51_Ball: BulletBase
	{
		ace_windcoef = 0.4;
	};
	class B_762x54_Ball: BulletBase
	{
		ace_windcoef = 0.45;
	};
	class B_127x99_Ball: BulletBase
	{
		ace_windcoef = 0.24;
	};
	class B_127x108_Ball: BulletBase
	{
		ace_windcoef = 0.24;
	};
	class B_127x107_Ball: BulletBase
	{
		ace_windcoef = 0.24;
	};
	class B_86x70_Ball_noTracer: BulletBase
	{
		ace_windcoef = 0.25;
	};
};
class RscTitles
{
	class ACE_RscWindIntuitive
	{
		idd = -1;
		onLoad = "with uiNameSpace do { ACE_RscWindIntuitive = _this select 0 };";
		movingEnable = 0;
		duration = 10;
		fadeIn = "false";
		fadeOut = "false";
		controls[] = {"ACE_RscWindIntuitive_BG","ACE_RscWindIntuitive_1"};
		class ACE_RscWindIntuitive_BG
		{
			idc = -1;
			type = 0;
			style = 128;
			font = "TahomaB";
			colorBackground[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
			text = "";
			sizeEx = 0.027;
			x = "SafeZoneX + 0.001";
			y = "SafeZoneY + 0.04";
			w = 0.3;
			h = 0.3;
			size = 0.034;
		};
		class ACE_RscWindIntuitive_1: ACE_RscWindIntuitive_BG
		{
			idc = 1591514;
			style = 48;
			colorText[] = {0,0,0,0.1};
			font = "Bitstream";
			sizeEx = 0.03;
			text = "";
		};
	};
};
//};
