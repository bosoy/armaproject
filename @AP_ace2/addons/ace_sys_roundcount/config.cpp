////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:07:16 2013 : Created on Sat Jun 08 13:07:16 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_roundcount : config.bin{
class CfgPatches
{
	class ace_sys_roundcount
	{
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","CAWeapons","CAUI","ace_main","ace_sys_weapons"};
		version = "1.14.0.593";
		author[] = {"Rocko"};
		class ACE_Options
		{
			group = "WEP";
			title = " ";
			class Roundcount
			{
				title = "$STR_ACE_MENU_ROUNDCOUNT";
			};
		};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_roundcount
		{
			list[] = {"ace_sys_roundcount"};
		};
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_roundcount
	{
		clientInit = "call ('\x\ace\addons\sys_roundcount\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class RscIGUIText;
class RscIGUIValue;
class RscInGameUI
{
	class RscUnitInfoSoldier
	{
		controls[] = {"CA_Ammo","CA_Weapon","CA_Mode"};
		class CA_Ammo: RscIGUIValue
		{
			sizeEx = 0;
		};
		class CA_Mode: RscIGUIText{};
		class CA_Weapon: RscIGUIText{};
	};
};
class RscTitles
{
	class ACE_RscRoundCount_Text
	{
		idd = 1814;
		movingEnable = 1;
		duration = 3;
		fadeIn = 1;
		faseOut = 1;
		name = "ACE_RscRoundCount_Text";
		onLoad = "with uiNamespace do {ACE_RscRoundCount_Text = _this select 0}";
		class Controls
		{
			class ACE_RscRoundCount_BG
			{
				idc = -1;
				type = 0;
				font = "TahomaB";
				colorBackground[] = {0.388,0.545,0.247,0.49};
				colorText[] = {0,0,0,0};
				text = "";
				style = 128;
				sizeEx = "( 16 / 408 )";
				x = "SafeZoneX + 0.001";
				y = "SafeZoneY + 0.04";
				h = 0.04;
				w = 0.385;
			};
			class ACE_RscRoundCount_TXT
			{
				idc = 18141;
				type = 0;
				style = "0x02 + 0x100";
				x = "SafeZoneX + 0.006";
				y = "SafeZoneY + 0.041";
				h = 0.035;
				w = 0.385;
				colorBackground[] = {0.388,0.545,0.247,0};
				font = "bitstream";
				sizeEx = 0.0284375;
				colorText[] = {1,1,1,1};
				text = "";
			};
		};
	};
	class ACE_RscRoundCount_Icon: ACE_RscRoundCount_Text
	{
		name = "ACE_RscRoundCount_Icon";
		onLoad = "with uiNamespace do {ACE_RscRoundCount_Icon = _this select 0}";
		class Controls: Controls
		{
			class ACE_RscRoundCount_BG: ACE_RscRoundCount_BG
			{
				colorBackground[] = {0.388,0.545,0.247,0};
			};
			class ACE_RscRoundCount_IMG: ACE_RscRoundCount_TXT
			{
				style = "48 + 0x800 + 0x02";
				w = 0.09625;
				h = 0.09625;
			};
		};
	};
};
//};
