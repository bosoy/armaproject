////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:53 2013 : Created on Thu Jan 03 12:00:53 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_help : config.bin{
class CfgPatches
{
	class cba_help
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"cba_common","CBA_hashes"};
		version = "1.0.1.196";
		author[] = {"alef","Rocko","Sickboy"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
};
class RscStandardDisplay;
class RscStructuredText;
class RscActiveText;
class RscButton;
class CBA_CREDITS_CONT: RscStructuredText
{
	idc = -1;
	colorBackground[] = {0,0,0,0};
	x = "(0.025 * safeZoneW) + safeZoneX";
	y = "(0.964 * safeZoneH) + safeZoneY";
	w = "0.725 * safeZoneW";
	h = "0.025 * safeZoneH";
	size = "0.025 * SafeZoneH";
	class Attributes
	{
		font = "TahomaB";
		color = "#E0D8A6";
		align = "left";
		valign = "top";
		shadow = "true";
		shadowColor = "#191970";
		size = "1";
	};
};
class CBA_CREDITS_M: RscActiveText
{
	idc = -1;
	style = 48;
	x = "(0 * safeZoneW) + safeZoneX";
	y = "(0 * safeZoneH) + safeZoneY";
	w = "1 * safeZoneW";
	h = "1 * safeZoneH";
	default = 0;
	text = "#(argb,8,8,3)color(1,1,1,1)";
	color[] = {0,0,0,0};
	colorActive[] = {0,0,0,0};
	onMouseEnter = "(_this select 0) ctrlEnable false; (_this select 0) ctrlShow false; [_this] call compile preprocessFile '\x\cba\addons\help\show.sqf';";
};
class CBA_CREDITS_VER_BTN: RscButton
{
	idc = -1;
	colorText[] = {1,1,1,0};
	colorDisabled[] = {1,1,1,0};
	colorBackground[] = {1,1,1,0};
	colorBackgroundDisabled[] = {1,1,1,0};
	colorBackgroundActive[] = {1,1,1,0};
	colorShadow[] = {1,1,1,0};
	colorFocused[] = {1,1,1,0};
	soundClick[] = {"",0.1,1};
	x = -1;
	y = -1;
	w = 0;
	h = 0;
	text = "";
};
class RscDisplayMain: RscStandardDisplay
{
	class controls
	{
		class CA_Version;
		class CBA_CREDITS_VER: CA_Version
		{
			idc = 2222712;
			y = -1;
		};
		class CBA_CREDITS_VER_BTN: CBA_CREDITS_VER_BTN
		{
			idc = 2222713;
			onMouseButtonClick = "[_this] call compile preprocessFile '\x\cba\addons\help\showver.sqf';";
			onMouseEnter = "cba_help_VerTime= diag_tickTime + 20";
			onMouseExit = "cba_help_VerTime= diag_tickTime + 2";
		};
		class CBA_CREDITS_M: CBA_CREDITS_M
		{
			idc = 2222711;
			onMouseEnter = "(_this select 0) ctrlEnable false; (_this select 0) ctrlShow false; [_this, true] call compile preprocessFile '\x\cba\addons\help\showver.sqf';";
		};
	};
};
class RscDisplayInterrupt: RscStandardDisplay
{
	class controls
	{
		class CBA_CREDITS_CONT: CBA_CREDITS_CONT
		{
			idc = 2222710;
		};
		class CBA_CREDITS_M: CBA_CREDITS_M
		{
			idc = 2222711;
		};
	};
};
class RscDisplayMPInterrupt: RscStandardDisplay
{
	class controls
	{
		class CBA_CREDITS_CONT: CBA_CREDITS_CONT
		{
			idc = 2222710;
		};
		class CBA_CREDITS_M: CBA_CREDITS_M
		{
			idc = 2222711;
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_help
	{
		clientInit = "call ('\x\cba\addons\help\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class cba_help
	{
		clientInit = "call ('\x\cba\addons\help\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
//};
