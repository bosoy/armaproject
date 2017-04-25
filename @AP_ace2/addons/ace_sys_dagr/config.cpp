////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:07:12 2013 : Created on Mon Oct 14 23:07:12 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_dagr : config.bin{
class CfgPatches
{
	class ace_sys_dagr
	{
		units[] = {};
		weapons[] = {"ACE_DAGR"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","CAWeapons","ace_main"};
		version = "1.14.0.597";
		author[] = {"Rosuto"};
		class ACE_Options
		{
			group = "ITEMS";
			title = "DAGR";
			class Toggle_dagr
			{
				title = "Toggle DAGR";
			};
			class Toggle_dagr_mode
			{
				title = "Toggle DAGR modes";
			};
			class Dagr_Menu
			{
				title = "Open DAGR menu";
			};
		};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_dagr
		{
			list[] = {"ace_sys_dagr"};
		};
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_dagr
	{
		clientInit = "call ('\x\ace\addons\sys_dagr\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class cfgWeapons
{
	class ItemCore;
	class ACE_DAGR: ItemCore
	{
		scope = 2;
		displayName = "DAGR";
		picture = "\x\ace\addons\sys_dagr\data\DAGR_icon.paa";
		descriptionShort = "DAGR";
		ACE_Weight = 0.5;
		ACE_Size = 300;
		ACE_GPS = 1;
	};
};
class RscText;
class DAGR_Button
{
	idc = -1;
	type = 1;
	style = "0x00";
	default = "false";
	font = "Zeppelin32";
	sizeEx = 0.02;
	colorText[] = {0,1,0,1};
	colorFocused[] = {0,0,0,0};
	colorDisabled[] = {0,0,0,0};
	colorBackground[] = {0,0,0,0};
	colorBackgroundDisabled[] = {0,0,0,0};
	colorBackgroundActive[] = {0,0,0,0};
	offsetX = 0;
	offsetY = 0;
	offsetPressedX = 0;
	offsetPressedY = 0;
	colorShadow[] = {0,0,0,0};
	colorBorder[] = {0,0,0,0};
	borderSize = 0;
	soundEnter[] = {"",0,1};
	soundPush[] = {"",0,1};
	soundClick[] = {"",0,1};
	soundEscape[] = {"",0,1};
	x = 0.5;
	y = 0.5;
	w = 0.07;
	h = 0.05;
	text = "";
	action = "";
};
class DAGR_Menu_Pic
{
	type = 0;
	idc = -1;
	style = 48;
	x = 0;
	y = 0;
	w = 0.7;
	h = 1.4;
	text = "";
	colorBackground[] = {};
	colorText[] = {};
	font = "Zeppelin32";
	sizeEx = 0.04;
	waitForLoad = 0;
};
class DAGR_Menu_Text
{
	type = 0;
	idc = -1;
	style = "0x00";
	x = 0.5;
	y = 0.5;
	w = 0.15;
	h = 0.15;
	colorBackground[] = {0,0,0,0};
	colorText[] = {0.239,0.216,0.153,1};
	font = "Zeppelin32";
	sizeEx = 0.03;
	waitForLoad = 0;
	text = "";
};
class DAGR_Menu
{
	idd = 266860;
	movingEnable = "false";
	duration = 100000;
	fadein = 0;
	fadeout = 0;
	name = "Dagr_Menu";
	onLoad = "uiNamespace setVariable ['DAGR_Menu', _this select 0]";
	controls[] = {"DAGR_MENU_UI","DAGR_PWR_Button","DAGR_UP_Button","DAGR_DOWN_Button","DAGR_LEFT_Button","DAGR_RIGHT_Button","DAGR_NEXT_Button","DAGR_SEL_Button","DAGR_MENU_Button","DAGR_F1_Button","DAGR_F2_Button","DAGR_F3_Button","DAGR_F1_Text","DAGR_F2_Text","DAGR_F3_Text","DAGR_MENU_OPTION0","DAGR_MENU_OPTION1","DAGR_MENU_OPTION2","DAGR_MENU_OPTION3","DAGR_MENU_OPTION4","DAGR_MENU_SELECTION0","DAGR_MENU_SELECTION1","DAGR_MENU_SELECTION2","DAGR_MENU_SELECTION3","DAGR_MENU_SELECTION4","DAGR_MENU_Main_Text","DAGR_MENU_PSELECTION1","DAGR_MENU_PSELECTION2","DAGR_MENU_PSELECTION3","DAGR_MENU_PSELECTION4","DAGR_MENU_PSELECTION5","DAGR_MENU_PSELECTION6","DAGR_MENU_PSELECTION7","DAGR_MENU_PSELECTION8"};
	class DAGR_MENU_UI: DAGR_Menu_Pic
	{
		idc = 266861;
		x = 0.175;
		y = -0.173;
		text = "\x\ace\addons\sys_dagr\data\dagr_menu.paa";
		sizeEx = 0.1;
	};
	class DAGR_PWR_Button: DAGR_Button
	{
		idc = 266863;
		action = "DAGR_PWR = true";
		x = 0.4;
		y = 0.65;
	};
	class DAGR_UP_Button: DAGR_Button
	{
		idc = 266864;
		action = "DAGR_UP = true";
		x = 0.5;
		y = 0.675;
	};
	class DAGR_DOWN_Button: DAGR_Button
	{
		idc = 266865;
		action = "DAGR_Down = true";
		x = 0.5;
		y = 0.81;
	};
	class DAGR_LEFT_Button: DAGR_Button
	{
		idc = 266866;
		action = "DAGR_LEFT = true";
		x = 0.4;
		y = 0.735;
		w = 0.05;
		h = 0.07;
	};
	class DAGR_RIGHT_Button: DAGR_Button
	{
		idc = 266867;
		action = "DAGR_RIGHT = true";
		x = 0.62;
		y = 0.735;
		w = 0.05;
		h = 0.07;
	};
	class DAGR_NEXT_Button: DAGR_Button
	{
		idc = 266868;
		action = "DAGR_NEXT = true";
		x = 0.6;
		y = 0.65;
	};
	class DAGR_SEL_Button: DAGR_Button
	{
		idc = 266869;
		action = "DAGR_SEL = true";
		x = 0.54;
		y = 0.735;
		w = 0.06;
		h = 0.06;
	};
	class DAGR_MENU_Button: DAGR_Button
	{
		idc = 266870;
		action = "DAGR_MENU_B = true";
		x = 0.46;
		y = 0.735;
		w = 0.06;
		h = 0.06;
	};
	class DAGR_F1_Button: DAGR_Button
	{
		idc = 266871;
		action = "DAGR_F1 = true";
		x = 0.4;
		y = 0.575;
	};
	class DAGR_F2_Button: DAGR_Button
	{
		idc = 266872;
		action = "DAGR_F2 = true";
		x = 0.495;
		y = 0.575;
	};
	class DAGR_F3_Button: DAGR_Button
	{
		idc = 266873;
		action = "DAGR_F3 = true";
		x = 0.59;
		y = 0.575;
	};
	class DAGR_F1_Text: DAGR_Menu_Text
	{
		idc = 266874;
		x = 0.388;
		y = 0.38;
		text = "";
	};
	class DAGR_F2_Text: DAGR_Menu_Text
	{
		idc = 266875;
		x = 0.506;
		y = 0.38;
	};
	class DAGR_F3_Text: DAGR_Menu_Text
	{
		idc = 266876;
		x = 0.612;
		y = 0.38;
	};
	class DAGR_MENU_OPTION0: DAGR_Menu_Text
	{
		idc = 2668777;
		style = "0x02";
		sizeEx = 0.035;
		x = 0.43;
		y = 0.19;
	};
	class DAGR_MENU_OPTION1: DAGR_Menu_Text
	{
		idc = 2668778;
		style = "0x02";
		sizeEx = 0.035;
		x = 0.43;
		y = 0.225;
	};
	class DAGR_MENU_OPTION2: DAGR_Menu_Text
	{
		idc = 2668779;
		style = "0x02";
		sizeEx = 0.035;
		x = 0.43;
		y = 0.26;
	};
	class DAGR_MENU_OPTION3: DAGR_Menu_Text
	{
		idc = 2668780;
		style = "0x02";
		sizeEx = 0.035;
		x = 0.43;
		y = 0.295;
	};
	class DAGR_MENU_OPTION4: DAGR_Menu_Text
	{
		idc = 2668781;
		style = "0x02";
		sizeEx = 0.035;
		x = 0.43;
		y = 0.33;
	};
	class DAGR_MENU_SELECTION0: DAGR_Menu_Pic
	{
		idc = 2668783;
		x = 0.42;
		y = 0.246;
		w = 0.17;
		h = 0.035;
		sizeEx = 0.05;
	};
	class DAGR_MENU_SELECTION1: DAGR_Menu_Pic
	{
		idc = 2668784;
		x = 0.42;
		y = 0.281;
		w = 0.17;
		h = 0.035;
		sizeEx = 0.05;
	};
	class DAGR_MENU_SELECTION2: DAGR_Menu_Pic
	{
		idc = 2668785;
		x = 0.42;
		y = 0.316;
		w = 0.17;
		h = 0.035;
		sizeEx = 0.05;
	};
	class DAGR_MENU_SELECTION3: DAGR_Menu_Pic
	{
		idc = 2668786;
		x = 0.42;
		y = 0.351;
		w = 0.17;
		h = 0.035;
		sizeEx = 0.05;
	};
	class DAGR_MENU_SELECTION4: DAGR_Menu_Pic
	{
		idc = 2668787;
		x = 0.42;
		y = 0.386;
		w = 0.17;
		h = 0.035;
		sizeEx = 0.05;
	};
	class DAGR_MENU_Main_Text: DAGR_Menu_Text
	{
		idc = 2668782;
		style = "0x02";
		x = 0.38;
		y = 0.32;
		w = 0.25;
		h = 0.035;
		sizeEx = 0.04;
	};
	class DAGR_MENU_PSELECTION1: DAGR_Menu_Pic
	{
		idc = 2668788;
		x = 0.451;
		y = 0.352;
		w = 0.01;
		h = 0.003;
	};
	class DAGR_MENU_PSELECTION2: DAGR_Menu_Pic
	{
		idc = 2668789;
		x = 0.465;
		y = 0.352;
		w = 0.01;
		h = 0.003;
	};
	class DAGR_MENU_PSELECTION3: DAGR_Menu_Pic
	{
		idc = 2668790;
		x = 0.479;
		y = 0.352;
		w = 0.01;
		h = 0.003;
	};
	class DAGR_MENU_PSELECTION4: DAGR_Menu_Pic
	{
		idc = 2668791;
		x = 0.493;
		y = 0.352;
		w = 0.01;
		h = 0.003;
	};
	class DAGR_MENU_PSELECTION5: DAGR_Menu_Pic
	{
		idc = 2668792;
		x = 0.507;
		y = 0.352;
		w = 0.01;
		h = 0.003;
	};
	class DAGR_MENU_PSELECTION6: DAGR_Menu_Pic
	{
		idc = 2668793;
		x = 0.521;
		y = 0.352;
		w = 0.01;
		h = 0.003;
	};
	class DAGR_MENU_PSELECTION7: DAGR_Menu_Pic
	{
		idc = 2668794;
		x = 0.535;
		y = 0.352;
		w = 0.01;
		h = 0.003;
	};
	class DAGR_MENU_PSELECTION8: DAGR_Menu_Pic
	{
		idc = 2668795;
		x = 0.549;
		y = 0.352;
		w = 0.01;
		h = 0.003;
	};
};
class RscTitles
{
	class DAGR_Text
	{
		type = 0;
		idc = -1;
		style = "0x01";
		x = 0;
		y = 0;
		w = 0.15;
		h = 0.05;
		text = "";
		colorBackground[] = {0,0,0,0};
		colorText[] = {0.239,0.216,0.153,1};
		font = "Zeppelin32";
		sizeEx = 0.04;
		waitForLoad = 0;
	};
	class DAGR_Pic
	{
		type = 0;
		idc = -1;
		style = 48;
		x = 0;
		y = 0;
		w = 0.5;
		h = 0.5;
		text = "";
		colorBackground[] = {};
		colorText[] = {};
		font = "Zeppelin32";
		sizeEx = 0.02;
		waitForLoad = 0;
	};
	class DAGR_Display
	{
		idd = 266850;
		movingEnable = "false";
		duration = 100000;
		fadein = 0;
		fadeout = 0;
		name = "Dagr_Display";
		onLoad = "uiNamespace setVariable ['DAGR_Display', _this select 0]";
		controls[] = {"DAGR_UI","DAGR_Grid","DAGR_Speed","DAGR_Elevation","DAGR_Heading","DAGR_Time","DAGR_WP","DAGR_Bearing","DAGR_DIST"};
		class DAGR_UI: DAGR_Pic
		{
			idc = 266856;
			x = "(SafeZoneW + SafeZoneX) - 0.45";
			y = "(SafeZoneH + SafeZoneY) - 0.47";
		};
		class DAGR_Grid: DAGR_Text
		{
			idc = 266851;
			x = "(SafeZoneW + SafeZoneX) - 0.370";
			y = "(SafeZoneH + SafeZoneY)- 0.250";
			w = 0.25;
			h = 0.06;
			sizeEx = 0.07;
		};
		class DAGR_Speed: DAGR_Text
		{
			idc = 266852;
			x = "(SafeZoneW + SafeZoneX) - 0.388";
			y = "(SafeZoneH + SafeZoneY) - 0.181";
		};
		class DAGR_Elevation: DAGR_Text
		{
			idc = 266853;
			x = "(SafeZoneW + SafeZoneX) - 0.270";
			y = "(SafeZoneH + SafeZoneY) - 0.181";
		};
		class DAGR_Heading: DAGR_Text
		{
			idc = 266854;
			x = "(SafeZoneW + SafeZoneX) - 0.413";
			y = "(SafeZoneH + SafeZoneY) - 0.1294";
		};
		class DAGR_Time: DAGR_Text
		{
			idc = 266855;
			x = "(SafeZoneW + SafeZoneX) - 0.275";
			y = "(SafeZoneH + SafeZoneY) - 0.129";
		};
		class DAGR_WP: DAGR_Text
		{
			idc = 266857;
			x = "(SafeZoneW + SafeZoneX) - 0.235";
			y = "(SafeZoneH + SafeZoneY) - 0.181";
		};
		class DAGR_Bearing: DAGR_Text
		{
			idc = 266858;
			x = "(SafeZoneW + SafeZoneX) - 0.413";
			y = "(SafeZoneH + SafeZoneY) - 0.181";
		};
		class DAGR_DIST: DAGR_Text
		{
			idc = 266859;
			x = "(SafeZoneW + SafeZoneX) - 0.265";
			y = "(SafeZoneH + SafeZoneY) - 0.129";
		};
	};
};
//};
