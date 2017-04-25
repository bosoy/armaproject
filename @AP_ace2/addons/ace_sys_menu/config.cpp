////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:45:50 2013 : Created on Sat Apr 06 11:45:50 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_menu : config.bin{
class CfgPatches
{
	class ace_sys_menu
	{
		units[] = {"ace_sys_menu_logic"};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAData","Extended_EventHandlers","ace_main","ace_sys_interaction"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_menu
		{
			list[] = {"ace_sys_menu"};
		};
	};
};
class RscText;
class RscTextMainMenu;
class RscTree;
class RscTitle;
class RscPicture;
class RscPictureKeepAspect;
class RscObject;
class RscActiveText;
class RscButton;
class RscButton_small;
class RscButtonTextOnly;
class RscProgress;
class RscListBox;
class RscEdit;
class RscSlider;
class RscStandardDisplay;
class RscFrame;
class RscBackground;
class RscCombo;
class RscLB_C;
class RscLB_LIST;
class Rsc3DStatic;
class RscHTML
{
	class HeadingStyle;
	class H1;
	class H2;
	class H3;
	class H4;
	class H5;
	class H6;
	class P;
};
class RscStructuredText
{
	class Attributes;
};
class RscMapControl
{
	class ActiveMarker;
	class Legend;
	class Bunker;
	class Bush;
	class BusStop;
	class Command;
	class Cross;
	class Fortress;
	class Fuelstation;
	class Fountain;
	class Hospital;
	class Chapel;
	class Church;
	class Lighthouse;
	class Quay;
	class Rock;
	class Ruin;
	class SmallTree;
	class Stack;
	class Tree;
	class Tourism;
	class Transmitter;
	class ViewTower;
	class Watertower;
	class Waypoint;
	class WaypointCompleted;
};
class RscMap
{
	class controls
	{
		class Map;
	};
};
class SIX_Dlg_FullBackground: RscText
{
	x = 0.0;
	y = 0.0;
	w = 1.0;
	h = 1.0;
	colorBackground[] = {0.3,0.3,0.3,0.9};
};
class SIX_Dlg_FullBackgroundFrame: RscFrame
{
	x = 0.0;
	y = 0.0;
	w = 1.0;
	h = 1.0;
	text = " Selection Dialog ";
};
class SIX_Dlg_Caption: RscText
{
	x = 0.0;
	y = 0.0;
	w = 0.3;
	colorBackground[] = {0.253906,0.410156,0.878906,1};
	colorText[] = {1,1,1,1};
};
class RscMemo: RscStructuredText
{
	type = 0;
	style = "0x00+ 16";
	font = "TahomaB";
};
class RscControlsGroup
{
	type = 15;
	idc = -1;
	style = "0x00";
	x = 0.1;
	y = 0.1;
	w = 0.3;
	h = 0.3;
	class VScrollbar
	{
		color[] = {1,1,1,1};
		width = 0.021;
	};
	class HScrollbar
	{
		color[] = {1,1,1,1};
		height = 0.028;
	};
	class Controls{};
};
class SIX_PUM3_Caption: SIX_Dlg_Caption
{
	y = 0.2;
	w = 0.3;
	text = "Popup Menu";
};
class SIX_PUM3_MenuItem: RscButton
{
	style = "0x00";
	sizeEx = "(((100/36)/100)*0.9)* 0.9";
	font = "Zeppelin32";
	colorText[] = {1,1,1,1};
	colorBackground[] = {0.5,0.5,0.5,1};
	colorFocused[] = {0,0,0.5,1};
	colorShadow[] = {1.0,0.75,0.792969,0.2};
	colorBorder[] = {1,1,1,0.2};
	colorBackgroundActive[] = {0,0,0.5,1.0};
	colorDisabled[] = {0.7,0.7,0.7,0.7};
	colorBackgroundDisabled[] = {0.5,0.5,0.5,1};
	x = 0.05;
	y = 0.2;
	w = 0.3;
	h = "(((100/36)/100)*0.9)* 0.9";
	text = "";
	action = "";
};
class SIX_PUM3_MenuItem0: SIX_PUM3_MenuItem
{
	x = 0.05;
};
class SIX_PUM3_MenuItem1: SIX_PUM3_MenuItem
{
	x = "0.05+ (0.30* 1)";
};
class SIX_PUM3_MenuItem2: SIX_PUM3_MenuItem
{
	x = "0.05+ (0.30* 2)";
};
class SIX_PUM3_PopupMenuDialog
{
	idd = 5390;
	movingEnable = "true";
	controlsBackground[] = {};
	objects[] = {};
	controls[] = {"SIX_PUM3_Caption0","SIX_PUM3_Caption1","SIX_PUM3_Caption2","SIX_PUM3_MenuItem000","SIX_PUM3_MenuItem001","SIX_PUM3_MenuItem002","SIX_PUM3_MenuItem003","SIX_PUM3_MenuItem004","SIX_PUM3_MenuItem005","SIX_PUM3_MenuItem006","SIX_PUM3_MenuItem007","SIX_PUM3_MenuItem008","SIX_PUM3_MenuItem009","SIX_PUM3_MenuItem010","SIX_PUM3_MenuItem011","SIX_PUM3_MenuItem012","SIX_PUM3_MenuItem013","SIX_PUM3_MenuItem014","SIX_PUM3_MenuItem015","SIX_PUM3_MenuItem016","SIX_PUM3_MenuItem017","SIX_PUM3_MenuItem018","SIX_PUM3_MenuItem019","SIX_PUM3_MenuItem100","SIX_PUM3_MenuItem101","SIX_PUM3_MenuItem102","SIX_PUM3_MenuItem103","SIX_PUM3_MenuItem104","SIX_PUM3_MenuItem105","SIX_PUM3_MenuItem106","SIX_PUM3_MenuItem107","SIX_PUM3_MenuItem108","SIX_PUM3_MenuItem109","SIX_PUM3_MenuItem110","SIX_PUM3_MenuItem111","SIX_PUM3_MenuItem112","SIX_PUM3_MenuItem113","SIX_PUM3_MenuItem114","SIX_PUM3_MenuItem115","SIX_PUM3_MenuItem116","SIX_PUM3_MenuItem117","SIX_PUM3_MenuItem118","SIX_PUM3_MenuItem119","SIX_PUM3_MenuItem200","SIX_PUM3_MenuItem201","SIX_PUM3_MenuItem202","SIX_PUM3_MenuItem203","SIX_PUM3_MenuItem204","SIX_PUM3_MenuItem205","SIX_PUM3_MenuItem206","SIX_PUM3_MenuItem207","SIX_PUM3_MenuItem208","SIX_PUM3_MenuItem209","SIX_PUM3_MenuItem210","SIX_PUM3_MenuItem211","SIX_PUM3_MenuItem212","SIX_PUM3_MenuItem213","SIX_PUM3_MenuItem214","SIX_PUM3_MenuItem215","SIX_PUM3_MenuItem216","SIX_PUM3_MenuItem217","SIX_PUM3_MenuItem218","SIX_PUM3_MenuItem219"};
	class SIX_PUM3_Caption0: SIX_PUM3_Caption
	{
		idc = 5892;
		x = 0.05;
		y = 0.2;
	};
	class SIX_PUM3_Caption1: SIX_PUM3_Caption
	{
		idc = 5893;
		x = "0.05+ (0.30* 1)";
		y = "0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_Caption2: SIX_PUM3_Caption
	{
		idc = 5894;
		x = "0.05+ (0.30* 2)";
		y = "0.20+ (2 * ((100/36)/100))";
	};
	class SIX_PUM3_MenuItem000: SIX_PUM3_MenuItem0
	{
		idc = 5870;
		y = "0*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem001: SIX_PUM3_MenuItem0
	{
		idc = 5871;
		y = "1*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem002: SIX_PUM3_MenuItem0
	{
		idc = 5872;
		y = "2*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem003: SIX_PUM3_MenuItem0
	{
		idc = 5873;
		y = "3*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem004: SIX_PUM3_MenuItem0
	{
		idc = 5874;
		y = "4*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem005: SIX_PUM3_MenuItem0
	{
		idc = 5875;
		y = "5*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem006: SIX_PUM3_MenuItem0
	{
		idc = 5876;
		y = "6*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem007: SIX_PUM3_MenuItem0
	{
		idc = 5877;
		y = "7*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem008: SIX_PUM3_MenuItem0
	{
		idc = 5878;
		y = "8*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem009: SIX_PUM3_MenuItem0
	{
		idc = 5879;
		y = "9*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem010: SIX_PUM3_MenuItem0
	{
		idc = 5880;
		y = "10*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem011: SIX_PUM3_MenuItem0
	{
		idc = 5881;
		y = "11*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem012: SIX_PUM3_MenuItem0
	{
		idc = 5882;
		y = "12*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem013: SIX_PUM3_MenuItem0
	{
		idc = 5883;
		y = "13*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem014: SIX_PUM3_MenuItem0
	{
		idc = 5884;
		y = "14*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem015: SIX_PUM3_MenuItem0
	{
		idc = 5885;
		y = "15*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem016: SIX_PUM3_MenuItem0
	{
		idc = 5886;
		y = "16*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem017: SIX_PUM3_MenuItem0
	{
		idc = 5887;
		y = "17*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem018: SIX_PUM3_MenuItem0
	{
		idc = 5888;
		y = "18*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem019: SIX_PUM3_MenuItem0
	{
		idc = 5889;
		y = "19*((((100/36)/100)*0.9)* 0.9) + 0.20+ ((100/36)/100)";
	};
	class SIX_PUM3_MenuItem100: SIX_PUM3_MenuItem1
	{
		idc = 51870;
		y = "0*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem101: SIX_PUM3_MenuItem1
	{
		idc = 51871;
		y = "1*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem102: SIX_PUM3_MenuItem1
	{
		idc = 51872;
		y = "2*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem103: SIX_PUM3_MenuItem1
	{
		idc = 51873;
		y = "3*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem104: SIX_PUM3_MenuItem1
	{
		idc = 51874;
		y = "4*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem105: SIX_PUM3_MenuItem1
	{
		idc = 51875;
		y = "5*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem106: SIX_PUM3_MenuItem1
	{
		idc = 51876;
		y = "6*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem107: SIX_PUM3_MenuItem1
	{
		idc = 51877;
		y = "7*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem108: SIX_PUM3_MenuItem1
	{
		idc = 51878;
		y = "8*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem109: SIX_PUM3_MenuItem1
	{
		idc = 51879;
		y = "9*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem110: SIX_PUM3_MenuItem1
	{
		idc = 51880;
		y = "10*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem111: SIX_PUM3_MenuItem1
	{
		idc = 51881;
		y = "11*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem112: SIX_PUM3_MenuItem1
	{
		idc = 51882;
		y = "12*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem113: SIX_PUM3_MenuItem1
	{
		idc = 51883;
		y = "13*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem114: SIX_PUM3_MenuItem1
	{
		idc = 51884;
		y = "14*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem115: SIX_PUM3_MenuItem1
	{
		idc = 51885;
		y = "15*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem116: SIX_PUM3_MenuItem1
	{
		idc = 51886;
		y = "16*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem117: SIX_PUM3_MenuItem1
	{
		idc = 51887;
		y = "17*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem118: SIX_PUM3_MenuItem1
	{
		idc = 51888;
		y = "18*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem119: SIX_PUM3_MenuItem1
	{
		idc = 51889;
		y = "19*((((100/36)/100)*0.9)* 0.9) + 0.20+ (2*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem200: SIX_PUM3_MenuItem2
	{
		idc = 52870;
		y = "0*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem201: SIX_PUM3_MenuItem2
	{
		idc = 52871;
		y = "1*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem202: SIX_PUM3_MenuItem2
	{
		idc = 52872;
		y = "2*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem203: SIX_PUM3_MenuItem2
	{
		idc = 52873;
		y = "3*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem204: SIX_PUM3_MenuItem2
	{
		idc = 52874;
		y = "4*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem205: SIX_PUM3_MenuItem2
	{
		idc = 52875;
		y = "5*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem206: SIX_PUM3_MenuItem2
	{
		idc = 52876;
		y = "6*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem207: SIX_PUM3_MenuItem2
	{
		idc = 52877;
		y = "7*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem208: SIX_PUM3_MenuItem2
	{
		idc = 52878;
		y = "8*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem209: SIX_PUM3_MenuItem2
	{
		idc = 52879;
		y = "9*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem210: SIX_PUM3_MenuItem2
	{
		idc = 52880;
		y = "10*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem211: SIX_PUM3_MenuItem2
	{
		idc = 52881;
		y = "11*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem212: SIX_PUM3_MenuItem2
	{
		idc = 52882;
		y = "12*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem213: SIX_PUM3_MenuItem2
	{
		idc = 52883;
		y = "13*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem214: SIX_PUM3_MenuItem2
	{
		idc = 52884;
		y = "14*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem215: SIX_PUM3_MenuItem2
	{
		idc = 52885;
		y = "15*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem216: SIX_PUM3_MenuItem2
	{
		idc = 52886;
		y = "16*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem217: SIX_PUM3_MenuItem2
	{
		idc = 52887;
		y = "17*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem218: SIX_PUM3_MenuItem2
	{
		idc = 52888;
		y = "18*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
	class SIX_PUM3_MenuItem219: SIX_PUM3_MenuItem2
	{
		idc = 52889;
		y = "19*((((100/36)/100)*0.9)* 0.9) + 0.20+ (3*((100/36)/100))";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_menu
	{
		init = "call ('\x\ace\addons\sys_menu\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ace_sys_menu_logic: ACE_Logic
	{
		scope = 1;
		displayName = "ace_sys_menu";
		class EventHandlers
		{
			init = "(_this select 0) call ('\x\ace\addons\sys_menu\init_logic.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
		};
	};
};
//};
