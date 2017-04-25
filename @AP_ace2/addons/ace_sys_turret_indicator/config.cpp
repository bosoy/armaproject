////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:35:21 2012 : Created on Fri Nov 09 22:35:21 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_turret_indicator : config.bin{
class CfgPatches
{
	class ace_sys_turret_indicator
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_vehicle"};
		version = "1.14.0.581";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_turret_indicator
		{
			list[] = {"ace_sys_turret_indicator"};
		};
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_turret_indicator
	{
		clientInit = "call ('\x\ace\addons\sys_turret_indicator\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_GetIn_EventHandlers
{
	class All
	{
		class ace_sys_turret_indicator
		{
			clientGetIn = "_this call ace_sys_turret_indicator_fnc_getIn";
		};
	};
};
class RscTitles
{
	class ACE_RscTurretIndicator
	{
		idd = -1;
		onLoad = "with uiNameSpace do { ACE_RscTurretIndicator = _this select 0 };";
		movingEnable = 0;
		duration = 10000;
		fadeIn = 0;
		fadeOut = 0;
		controls[] = {"ACE_RscTurretIndicator_BG","ACE_RscTurretIndicator_gun","ACE_RscTurretIndicator_com","ACE_RscTurretIndicator_digind"};
		class ACE_RscTurretIndicator_BG
		{
			idc = 1591513;
			type = 0;
			style = "48+0x800";
			font = "TahomaB";
			colorBackground[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
			text = "x\ace\addons\sys_turret_indicator\data\hull.paa";
			sizeEx = 0.03;
			x = "SafeZoneX + 0.1";
			y = "SafeZoneY + 0.1";
			w = 0.35;
			h = 0.35;
			size = 0.034;
			shadow = 0;
			fixedWidth = 1;
			lineSpacing = 0;
		};
		class ACE_RscTurretIndicator_gun: ACE_RscTurretIndicator_BG
		{
			idc = 1591514;
			text = "";
		};
		class ACE_RscTurretIndicator_com: ACE_RscTurretIndicator_BG
		{
			idc = 1591515;
			text = "";
		};
		class ACE_RscTurretIndicator_digind: ACE_RscTurretIndicator_BG
		{
			idc = 1591516;
			style = "0x02";
			text = "";
			size = 0.03;
		};
	};
};
class CfgVehicles
{
	class LandVehicle;
	class Car: LandVehicle{};
	class Wheeled_APC: Car
	{
		ace_sys_turret_indicator_enable = 1;
	};
	class Tank: LandVehicle
	{
		ace_sys_turret_indicator_enable = 1;
	};
	class ZSU_Base: Tank
	{
		ace_sys_turret_indicator_enable = 0;
	};
	class 2S6M_Tunguska: Tank
	{
		ace_sys_turret_indicator_enable = 0;
	};
	class Helicopter;
	class Mi24_Base: Helicopter
	{
		ace_sys_turret_indicator_enable = 1;
	};
	class Mi24_Base_RU;
	class Mi24_P: Mi24_Base_RU
	{
		ace_sys_turret_indicator_enable = 0;
	};
	class AH1_Base: Helicopter
	{
		ace_sys_turret_indicator_enable = 1;
	};
	class AW159_Lynx_BAF: Helicopter
	{
		ace_sys_turret_indicator_enable = 1;
	};
};
//};
