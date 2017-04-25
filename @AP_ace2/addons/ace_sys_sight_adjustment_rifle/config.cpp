////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:07:30 2013 : Created on Sat Jun 08 13:07:30 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_sight_adjustment_rifle : config.bin{
class CfgPatches
{
	class ace_sys_sight_adjustment_rifle
	{
		units[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","CAweapons","CAweapons2","CAUI"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_sight_adjustment_rifle
	{
		clientInit = "call ('\x\ace\addons\sys_sight_adjustment_rifle\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class CAManBase
	{
		class ace_sys_sight_adjustment_rifle
		{
			clientFiredBis = "if (isPlayer(_this select 0)) then { if ((_this select 1) == ((_this select 0) getvariable 'ace_sa_rfl_cw')) then { _this call ace_sys_sight_adjustment_rifle_fnc_fired} }";
		};
	};
};
class cfgWeapons
{
	class Rifle;
	class SVD: Rifle
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "range";
		ace_sa_defaultrange = 300;
		ace_sa_defaultelevation = 2.4;
		ace_sa_zerooffset = 0;
		ace_sa_defaultwindage = 0;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 1000;
		ace_sa_windage = 10;
		ace_sa_stepwindage = 0.5;
		ace_sa_elev_unit = "mil_E";
		ace_sa_wind_unit = "mil_E";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 0;
		ace_sa_table_elev[] = {{0,0},{100,0.6},{200,1.4},{300,2.4},{350,2.9},{400,3.3},{450,3.9},{500,4.6},{550,5.4},{600,6.1},{650,6.9},{700,7.7},{750,8.6},{800,9.7},{850,10.9},{900,12},{950,13.5},{1000,14.8}};
		ace_drift[] = {{0,0},{100,0.025},{200,0.085},{300,0.19},{400,0.36},{500,0.6},{600,0.98},{700,1.45},{800,2.1},{900,2.9},{1000,4.15}};
	};
	class M24: Rifle
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "angle";
		ace_sa_defaultelevation = 9;
		ace_sa_defaultwindage = 0;
		ace_sa_defaultrange = 300;
		ace_sa_zerooffset = 0;
		ace_sa_minelevation = -10;
		ace_sa_maxelevation = 51;
		ace_sa_stepelevation = 1;
		ace_sa_windage = 35;
		ace_sa_stepwindage = 0.5;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 1000;
		ace_sa_elev_unit = "moa";
		ace_sa_wind_unit = "moa";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 100;
		ace_drift[] = {{0,0},{100,0.03},{200,0.08},{300,0.18},{400,0.305},{500,0.57},{600,0.92},{700,1.3},{800,1.85},{900,2.5},{1000,3.3}};
		ace_sa_table_elev[] = {{0,0},{100,3},{200,6},{300,9},{400,13},{500,18},{600,23},{700,28},{800,35},{900,41},{1000,50}};
	};
	class DMR: Rifle
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "angle";
		ace_sa_defaultelevation = 9;
		ace_sa_defaultwindage = 0;
		ace_sa_defaultrange = 300;
		ace_sa_zerooffset = 0;
		ace_sa_minelevation = -10;
		ace_sa_maxelevation = 51;
		ace_sa_stepelevation = 1;
		ace_sa_windage = 35;
		ace_sa_stepwindage = 0.5;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 1000;
		ace_sa_elev_unit = "moa";
		ace_sa_wind_unit = "moa";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 100;
		ace_drift[] = {{0,0},{100,0.03},{200,0.08},{300,0.18},{400,0.305},{500,0.57},{600,0.92},{700,1.3},{800,1.85},{900,2.5},{1000,3.3}};
		ace_sa_table_elev[] = {{0,0},{100,3},{200,6},{300,9},{400,13},{500,18},{600,23},{700,28},{800,35},{900,41},{1000,50}};
	};
	class M110_TWS_EP1: Rifle
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "angle";
		ace_sa_defaultelevation = 9;
		ace_sa_defaultwindage = 0;
		ace_sa_defaultrange = 300;
		ace_sa_zerooffset = 0;
		ace_sa_minelevation = -10;
		ace_sa_maxelevation = 51;
		ace_sa_stepelevation = 1;
		ace_sa_windage = 35;
		ace_sa_stepwindage = 0.5;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 1000;
		ace_sa_elev_unit = "moa";
		ace_sa_wind_unit = "moa";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 100;
		ace_drift[] = {{0,0},{100,0.03},{200,0.08},{300,0.18},{400,0.305},{500,0.57},{600,0.92},{700,1.3},{800,1.85},{900,2.5},{1000,3.3}};
		ace_sa_table_elev[] = {{0,0},{100,3},{200,6},{300,9},{400,13},{500,18},{600,23},{700,28},{800,35},{900,41},{1000,50}};
	};
	class SCAR_H_Base;
	class SCAR_H_LNG_Sniper: SCAR_H_Base
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "angle";
		ace_sa_defaultelevation = 9;
		ace_sa_defaultwindage = 0;
		ace_sa_defaultrange = 300;
		ace_sa_zerooffset = 0;
		ace_sa_minelevation = -10;
		ace_sa_maxelevation = 51;
		ace_sa_stepelevation = 1;
		ace_sa_windage = 35;
		ace_sa_stepwindage = 0.5;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 1000;
		ace_sa_elev_unit = "moa";
		ace_sa_wind_unit = "moa";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 100;
		ace_drift[] = {{0,0},{100,0.03},{200,0.08},{300,0.18},{400,0.305},{500,0.57},{600,0.92},{700,1.3},{800,1.85},{900,2.5},{1000,3.3}};
		ace_sa_table_elev[] = {{0,0},{100,3},{200,6},{300,9},{400,13},{500,18},{600,23},{700,28},{800,35},{900,41},{1000,50}};
	};
	class M107: Rifle
	{
		distanceZoomMin = 589;
		distanceZoomMax = 589;
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "angle";
		ace_sa_defaultelevation = 12.5;
		ace_sa_defaultwindage = 0;
		ace_sa_defaultrange = 500;
		ace_sa_zerooffset = 0;
		ace_sa_minelevation = -15;
		ace_sa_maxelevation = 110;
		ace_sa_stepelevation = 0.25;
		ace_sa_windage = 100;
		ace_sa_stepwindage = 0.25;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 2000;
		ace_sa_elev_unit = "moa";
		ace_sa_wind_unit = "moa";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 100;
		ace_sa_table_elev[] = {{0,0},{100,0.5},{200,4.0},{300,6.25},{400,9.5},{500,12.5},{600,15.25},{700,19.25},{800,23},{900,26.75},{1000,31.5},{1100,36.5},{1200,41.75},{1300,47},{1400,53.75},{1500,60.5},{1600,68},{1700,75.75},{1800,84.5},{1900,94},{2000,104.5}};
		ace_drift[] = {{0,0},{100,0.013},{200,0.03},{300,0.07},{400,0.139},{500,0.211},{600,0.41},{700,0.46},{800,0.7},{900,0.93},{1000,1.24},{1100,1.6},{1200,2},{1300,2.42},{1400,3},{1500,3.66},{1600,4.35},{1700,5.2},{1800,6.1},{1900,7.2},{2000,8.4}};
	};
	class m107_TWS_EP1: m107{};
	class BAF_AS50_scoped: Rifle
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "angle";
		ace_sa_defaultelevation = 12.5;
		ace_sa_defaultwindage = 0;
		ace_sa_defaultrange = 500;
		ace_sa_zerooffset = 0;
		ace_sa_minelevation = -15;
		ace_sa_maxelevation = 110;
		ace_sa_stepelevation = 0.25;
		ace_sa_windage = 100;
		ace_sa_stepwindage = 0.25;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 2000;
		ace_sa_elev_unit = "moa";
		ace_sa_wind_unit = "moa";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 100;
		ace_sa_table_elev[] = {{0,0},{100,0.5},{200,4.0},{300,6.25},{400,9.5},{500,12.5},{600,15.25},{700,19.25},{800,23},{900,26.75},{1000,31.5},{1100,36.5},{1200,41.75},{1300,47},{1400,53.75},{1500,60.5},{1600,68},{1700,75.75},{1800,84.5},{1900,94},{2000,104.5}};
		ace_drift[] = {{0,0},{100,0.013},{200,0.03},{300,0.07},{400,0.139},{500,0.211},{600,0.41},{700,0.46},{800,0.7},{900,0.93},{1000,1.24},{1100,1.6},{1200,2},{1300,2.42},{1400,3},{1500,3.66},{1600,4.35},{1700,5.2},{1800,6.1},{1900,7.2},{2000,8.4}};
	};
	class BAF_LRR_scoped: Rifle
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "angle";
		ace_sa_defaultelevation = 2.6;
		ace_sa_defaultwindage = 0;
		ace_sa_defaultrange = 400;
		ace_sa_zerooffset = 0;
		ace_sa_minelevation = -5;
		ace_sa_maxelevation = 20;
		ace_sa_stepelevation = 0.1;
		ace_sa_windage = 6;
		ace_sa_stepwindage = 0.1;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 1500;
		ace_sa_elev_unit = "mil";
		ace_sa_wind_unit = "mil";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 100;
		ace_sa_table_elev[] = {{0,0},{100,0.6},{200,1.2},{300,1.8},{400,2.6},{500,3.4},{600,4.3},{700,5.2},{800,6.2},{900,7.4},{1000,8.6},{1100,9.9},{1200,11.3},{1300,12.9},{1400,14.6},{1500,16.5}};
		ace_drift[] = {{0,0},{100,0.002},{200,0.02},{300,0.062},{400,0.118},{500,0.215},{600,0.324},{700,0.471},{800,0.649},{900,0.858},{1000,1.135},{1100,1.474},{1200,1.885},{1300,2.311},{1400,2.832},{1500,3.417}};
	};
	class KSVK: Rifle
	{
		distanceZoomMin = 500;
		distanceZoomMax = 500;
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "range";
		ace_sa_defaultrange = 500;
		ace_sa_defaultelevation = 3.7;
		ace_sa_zerooffset = 0;
		ace_sa_defaultwindage = 0;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 2000;
		ace_sa_windage = 10;
		ace_sa_stepwindage = 0.5;
		ace_sa_elev_unit = "mil_E";
		ace_sa_wind_unit = "mil_E";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 0;
		ace_sa_table_elev[] = {{0,0},{100,0.2},{200,1.1},{300,1.8},{350,2.4},{400,2.8},{450,3.3},{500,3.7},{550,4.2},{600,4.8},{650,5.5},{700,6},{750,6.5},{800,7.1},{850,7.8},{900,8.5},{950,9.2},{1000,10.25},{1050,11},{1100,11.5},{1150,12.25},{1200,13.25},{1250,14.25},{1300,15.25},{1350,16.25},{1400,17.25},{1450,18.25},{1500,19.5},{1550,20.75},{1600,22.25},{1650,23.5},{1700,24.75},{1750,26},{1800,27.75},{1850,29.5},{1900,31},{1950,33},{2000,35}};
		ace_drift[] = {{0,0},{100,0.013},{200,0.03},{300,0.07},{400,0.139},{500,0.211},{600,0.41},{700,0.46},{800,0.8},{900,1.1},{1000,1.5},{1100,1.9},{1200,2.3},{1300,2.87},{1400,3.5},{1500,4.25},{1600,5.05},{1700,6.1},{1800,7.25},{1900,8.55},{2000,11.2}};
	};
	class M4A1;
	class M4SPR: M4A1
	{
		distanceZoomMin = 360;
		distanceZoomMax = 360;
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "angle";
		ace_sa_defaultelevation = 9;
		ace_sa_defaultwindage = 0;
		ace_sa_defaultrange = 300;
		ace_sa_zerooffset = -0.6;
		ace_sa_minelevation = -10;
		ace_sa_maxelevation = 60;
		ace_sa_stepelevation = 1;
		ace_sa_windage = 35;
		ace_sa_stepwindage = 0.5;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 1000;
		ace_sa_elev_unit = "moa";
		ace_sa_wind_unit = "moa";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 100;
		ace_drift[] = {{0,0},{100,0.03},{200,0.07},{300,0.17},{400,0.37},{500,0.71},{600,1.2},{700,1.81},{800,2.75},{900,4},{1000,6.2}};
		ace_sa_table_elev[] = {{0,0},{100,2},{200,5},{300,9},{400,13},{500,17},{600,23},{700,29},{800,37},{900,46},{1000,57}};
	};
	class VSS_vintorez: Rifle
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "range";
		ace_sa_defaultrange = 100;
		ace_sa_defaultelevation = 5.1;
		ace_sa_zerooffset = 1.5;
		ace_sa_defaultwindage = 0;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 400;
		ace_sa_windage = 10;
		ace_sa_stepwindage = 0.5;
		ace_sa_elev_unit = "mil_E";
		ace_sa_wind_unit = "mil_E";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 0;
		ace_sa_table_elev[] = {{0,0},{100,5.1},{150,8.2},{200,11.3},{250,14.1},{300,17.4},{350,20.3},{400,23}};
		ace_drift[] = {{0,0},{100,0.06},{200,0.25},{300,0.6},{400,1.1}};
	};
};
class CfgSounds
{
	class ace_sadj_click
	{
		name = "ace_sadj_click";
		sound[] = {"\x\ace\addons\sys_sight_adjustment_rifle\sound\scope_click.wav",1,1};
		titles[] = {};
	};
};
class RscText;
class ACE_SYS_SA_RFL_RscText: RscText
{
	type = 0;
	idc = -1;
	style = 0;
	colorBackground[] = {0,0,0,0};
	colorText[] = {0,0,0,1};
	font = "ACE_HANDWRITTEN";
	sizeEx = 0.06;
	linespacing = 1.0;
	text = "";
	shadow = 0;
};
class RscTextRightAl;
class ACE_SYS_SA_RFL_RscTextRightAl: RscTextRightAl
{
	type = 0;
	idc = -1;
	style = 1;
	colorBackground[] = {0,0,0,0};
	colorText[] = {0,0,0,1};
	font = "ACE_HANDWRITTEN";
	sizeEx = 0.024;
	linespacing = 1.0;
	text = "";
	shadow = 0;
};
class RscStructuredText;
class ACE_SYS_SA_RFL_RscStructuredText: RscStructuredText
{
	type = 13;
	style = "0x0c";
	size = 0.0208333;
	colorText[] = {0,0,0,1};
	class Attributes
	{
		font = "ACE_HANDWRITTEN";
		color = "#000000";
		align = "center";
		shadow = 0;
	};
};
class RscListBox;
class ACE_SYS_SA_RFL_RscListBox: RscListBox
{
	style = 0;
	idc = -1;
	color[] = {0,0,0,1};
	colorSelect[] = {1,1,1,1};
	colorSelectBackground[] = {0,0,0,0};
	colorSelect2[] = {0,0,0,0};
	colorSelectBackground2[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	colorBackground[] = {0,0,0,0};
	colorScrollbar[] = {1,1,1,1};
	colorBorder[] = {1,1,1,1};
	font = "BitStream";
	sizeEx = 0.022;
	rowHeight = 0.024;
	canDrag = 0;
	shadow = 0;
};
class RscFrame;
class RscButton;
class ACE_SYS_SA_RFL_RscButton: RscButton
{
	idc = -1;
	type = 1;
	style = "0x02";
	default = "false";
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.1;
	text = "";
	font = "ACE_HANDWRITTEN";
	sizeEx = 0.05;
	shadow = 0;
	colorText[] = {0,0,0,1};
	colorDisabled[] = {0,0,0,0};
	colorBackground[] = {0,0,0,0};
	colorBackgroundDisabled[] = {0,0,0,0};
	colorBackgroundActive[] = {0,0,0,0};
	offsetX = 0.002;
	offsetY = 0.002;
	offsetPressedX = 0.001;
	offsetPressedY = 0.001;
	colorFocused[] = {0,0,0,0};
	colorShadow[] = {0,0,0,0};
	colorBorder[] = {0,0,0,0};
	borderSize = 0;
	soundEnter[] = {"",0.1,1};
	soundPush[] = {"",0.1,1};
	soundClick[] = {"",0.1,1};
	soundEscape[] = {"",0.1,1};
};
class RscEdit;
class ACE_SYS_SA_RFL_RscEdit: RscEdit
{
	type = 2;
	idc = -1;
	style = "0x02+ 0x0c";
	font = "ACE_HANDWRITTEN";
	sizeEx = 0.024;
	colorText[] = {0,0,0,1};
	colorSelection[] = {0.5,0.5,0.5,0.5};
	colorBorder[] = {0,0,0,0};
	colorShadow[] = {0,0,0,0};
	color[] = {0,0,0,0};
	BorderSize = 0;
	autocomplete = 0;
	text = "";
	shadow = 0;
};
class ACE_SYS_SA_RFL_RscPicture
{
	type = 0;
	idc = -1;
	style = 48;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = "ACE_HANDWRITTEN";
	sizeEx = 0;
	lineSpacing = 0;
	text = "";
	borderSize = 0;
};
class ACE_SYS_SA_RFL_MainBack: ACE_SYS_SA_RFL_RscText
{
	text = "";
	colorText[] = {0.34,0.34,0.34,0.5};
	colorBackground[] = {0.34,0.34,0.34,0.5};
};
class ACE_SYS_SA_RFL_ControlBack: ACE_SYS_SA_RFL_MainBack
{
	text = "\CA\UI\Data\ui_gradient_reverse_gs.paa";
	colorText[] = {0.34,0.34,0.34,0.5};
	colorBackground[] = {0.34,0.34,0.34,0.5};
};
class ACE_SYS_SA_RFL_TitleBack: ACE_SYS_SA_RFL_RscPicture
{
	text = "\CA\UI\Data\ui_gradient_title_gs.paa";
	colorText[] = {0.34,0.34,0.34,0.5};
	colorBackground[] = {0.34,0.34,0.34,0.5};
};
class ACE_SYS_SA_RFL_ArrowDown: ACE_SYS_SA_RFL_RscPicture
{
	text = "\x\ace\addons\sys_sight_adjustment_rifle\data\arrow_down.paa";
	colorText[] = {0.20392,0.4,0.05882,1.0};
	colorBackground[] = {0,0,0,0};
};
class ACE_SYS_SA_RFL_ArrowUp: ACE_SYS_SA_RFL_ArrowDown
{
	text = "\x\ace\addons\sys_sight_adjustment_rifle\data\arrow_up.paa";
};
class ACE_SYS_SA_RFL_ArrowLeft: ACE_SYS_SA_RFL_ArrowDown
{
	text = "\x\ace\addons\sys_sight_adjustment_rifle\data\arrow_left.paa";
};
class ACE_SYS_SA_RFL_ArrowRight: ACE_SYS_SA_RFL_ArrowDown
{
	text = "\x\ace\addons\sys_sight_adjustment_rifle\data\arrow_right.paa";
};
class RscListNBox;
class ACE_SYS_SA_RFL_RscListNBox: RscListNBox
{
	style = 0;
	idc = -1;
	color[] = {1,1,1,1};
	colorSelect[] = {0,0,0,1};
	colorSelectBackground[] = {0,0,0,0};
	colorSelect2[] = {0,0,0,0};
	colorSelectBackground2[] = {0,0,0,0};
	colorText[] = {0,0,0,1};
	colorBackground[] = {0,0,0,0};
	colorScrollbar[] = {1,1,1,1};
	colorBorder[] = {1,1,1,1};
	font = "ACE_HANDWRITTEN";
	sizeEx = 0.06;
	period = 0;
	columns[] = {0,0.31,0.61};
	shadow = 0;
	moving = 1;
};
class ACE_SYS_SA_RFL_RNG_Dialog
{
	idd = 30830;
	movingEnable = 1;
	class controlsBackground
	{
		class RangeCardBG: ACE_SYS_SA_RFL_RscPicture
		{
			idc = 4000;
			text = "\x\ace\addons\sys_sight_adjustment_rifle\data\rangetable_ca.paa";
			x = "0.236454 * safezoneW + safezoneX";
			y = "-0.0159765 * safezoneH + safezoneY";
			w = "0.533634 * safezoneW";
			h = "0.984463 * safezoneH";
		};
	};
	objects[] = {};
	class controls
	{
		class Txt_HeaderRange: ACE_SYS_SA_RFL_RscText
		{
			idc = 4002;
			text = "Range";
			x = "0.41 * safezoneW + safezoneX";
			y = "0.25 * safezoneH + safezoneY";
			w = "0.0391531 * safezoneW";
			h = "0.0469741 * safezoneH";
		};
		class Txt_HeaderElev: Txt_HeaderRange
		{
			idc = 4003;
			text = "Elevation";
			x = "0.47 * safezoneW + safezoneX";
			w = "0.0487754 * safezoneW";
		};
		class Txt_HeaderIndirElev: Txt_HeaderElev
		{
			idc = 4004;
			text = "Wind";
			x = "0.54 * safezoneW + safezoneX";
			w = "0.0487754 * safezoneW";
		};
		class LB: ACE_SYS_SA_RFL_RscListNBox
		{
			idc = 4005;
			rowHeight = 0.025;
			lineSpacing = 3;
			x = "0.415 * safezoneW + safezoneX";
			y = "0.284 * safezoneH + safezoneY";
			w = "0.204906 * safezoneW";
			h = "0.68 * safezoneH";
		};
	};
};
class ACE_SYS_SA_RFL_ELEV_Dialog: ACE_SYS_SA_RFL_RNG_Dialog
{
	idd = 30831;
	class controls: controls
	{
		class Txt_HeaderRange: Txt_HeaderRange{};
		class Txt_HeaderElev: Txt_HeaderElev{};
		class Txt_HeaderIndirElev: Txt_HeaderIndirElev{};
		class LB: LB{};
	};
};
class ACE_SYS_SA_RFL_RNG_ANGLE_Dialog
{
	idd = 30832;
	movingEnable = 1;
	onLoad = "with uiNameSpace do { ACE_SYS_SA_RFL_ELEV_Dialog = _this select 0 };";
	class controlsBackground
	{
		class DialogFrame: ACE_SYS_SA_RFL_MainBack
		{
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165";
			y = "SafeZoneY + 0";
			w = 0.345;
			h = 0.19;
			moving = 1;
		};
		class InnerDialogFrame: ACE_SYS_SA_RFL_MainBack
		{
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.007";
			y = "SafeZoneY + 0+ 0.01";
			w = 0.331;
			h = 0.17;
			moving = 1;
			colorBackground[] = {0,0,0,1};
			colorBorder[] = {0,0,0,1};
			BorderSize = 0.003;
		};
	};
	objects[] = {};
	class controls
	{
		class Txt_Rng: ACE_SYS_SA_RFL_RscText
		{
			idc = 3000;
			text = "Range";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.01";
			y = "SafeZoneY + 0+ 0.035";
			w = 0.06;
			h = 0.028;
		};
		class Txt_Elev: ACE_SYS_SA_RFL_RscText
		{
			idc = 3666;
			text = "Elev";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.01";
			y = "SafeZoneY + 0+ 0.035 + 0.08";
			w = 0.06;
			h = 0.028;
		};
		class Txt_RngUnit: ACE_SYS_SA_RFL_RscText
		{
			style = "0x02";
			SizeEx = 0.02;
			idc = 3501;
			text = "";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.065";
			y = "SafeZoneY + 0+ 0.06";
			w = 0.05;
			h = 0.022;
		};
		class Txt_ElevUnit: ACE_SYS_SA_RFL_RscText
		{
			style = "0x02";
			SizeEx = 0.02;
			idc = 3667;
			text = "";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.065";
			y = "SafeZoneY + 0+ 0.06 + 0.08";
			w = 0.05;
			h = 0.022;
		};
		class Btn_PreviousRng: ACE_SYS_SA_RFL_RscButton
		{
			idc = 3031;
			text = "-";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.12";
			y = "SafeZoneY + 0+ 0.045";
			w = 0.025;
			h = 0.025;
			action = "call ace_sys_sight_adjustment_rifle_fnc_prevRng_Elev";
		};
		class Btn_NextRng: ACE_SYS_SA_RFL_RscButton
		{
			idc = 3032;
			text = "+";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.12";
			y = "SafeZoneY + 0+ 0.026";
			w = 0.025;
			h = 0.025;
			action = "call ace_sys_sight_adjustment_rifle_fnc_nextRng_Elev";
		};
		class Btn_PreviousElev: ACE_SYS_SA_RFL_RscButton
		{
			idc = 3668;
			text = "-";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.12";
			y = "SafeZoneY + 0+ 0.045 + 0.08";
			w = 0.025;
			h = 0.025;
			action = "call ace_sys_sight_adjustment_rifle_fnc_prevElev_Elev";
		};
		class Btn_NextElev: ACE_SYS_SA_RFL_RscButton
		{
			idc = 3669;
			text = "+";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.12";
			y = "SafeZoneY + 0+ 0.026 + 0.08";
			w = 0.025;
			h = 0.025;
			action = "call ace_sys_sight_adjustment_rifle_fnc_nextElev_Elev";
		};
		class Txt_Range: ACE_SYS_SA_RFL_RscTextRightAl
		{
			idc = 3033;
			text = "";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.065";
			y = "SafeZoneY + 0+ 0.035";
			w = 0.05;
			h = 0.028;
		};
		class Edt_Elev: ACE_SYS_SA_RFL_RscTextRightAl
		{
			idc = 3670;
			style = "0x02";
			text = "";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.065";
			y = "SafeZoneY + 0+ 0.035 + 0.08";
			w = 0.05;
			h = 0.028;
		};
		class Txt_Windage: ACE_SYS_SA_RFL_RscText
		{
			idc = 3200;
			text = "Windage";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.17";
			y = "SafeZoneY + 0+ 0.035";
			w = 0.07;
			h = 0.028;
		};
		class Txt_WindUnit: ACE_SYS_SA_RFL_RscText
		{
			style = "0x02";
			SizeEx = 0.02;
			idc = 3502;
			text = "mil";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.262";
			y = "SafeZoneY + 0+ 0.06";
			w = 0.04;
			h = 0.022;
		};
		class Edt_Windage: ACE_SYS_SA_RFL_RscText
		{
			style = "0x02";
			idc = 3097;
			text = "";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.262";
			y = "SafeZoneY + 0+ 0.035";
			w = 0.04;
			h = 0.028;
		};
		class Btn_PreviousWnd: ACE_SYS_SA_RFL_RscButton
		{
			idc = 3041;
			text = "-";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.24";
			y = "SafeZoneY + 0+ 0.035";
			w = 0.025;
			h = 0.025;
			action = "call ace_sys_sight_adjustment_rifle_fnc_prevWnd";
		};
		class Btn_NextWnd: ACE_SYS_SA_RFL_RscButton
		{
			idc = 3042;
			text = "+";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.3";
			y = "SafeZoneY + 0+ 0.035";
			w = 0.025;
			h = 0.025;
			action = "call ace_sys_sight_adjustment_rifle_fnc_nextWnd";
		};
		class Btn_Apply: ACE_SYS_SA_RFL_RscButton
		{
			idc = 3148;
			default = 1;
			text = "$STR_ACE_SA_CONFIRM";
			x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.244";
			y = "SafeZoneY + 0+ 0.12 + 0.001";
			w = 0.07;
			h = 0.035;
			action = "call ace_sys_sight_adjustment_rifle_fnc_ApplyRange_ElevChanges";
		};
	};
};
class RscTitles
{
	class ACE_SYS_SA_RIFLE_RSC
	{
		idd = 135387;
		onLoad = "with uiNameSpace do { ACE_SYS_SA_RIFLE_RSC = _this select 0 };";
		onUnLoad = "with uiNameSpace do { ACE_SYS_SA_RIFLE_RSC = displayNull };";
		movingEnable = 0;
		duration = 2;
		fadeIn = 0;
		fadeOut = 0;
		controls[] = {"ACE_RscGeneric_BG","ACE_RscGeneric_1"};
		class ACE_RscGeneric_BG
		{
			idc = 1;
			type = 0;
			font = "TahomaB";
			colorBackground[] = {0,0,0,0.8};
			colorText[] = {0,0,0,0};
			text = "";
			style = 128;
			sizeEx = "( 16 / 408 )";
			x = "SafeZoneX + 0.001";
			y = "SafeZoneY + 0.04";
			h = 0.037;
			w = 0.17;
		};
		class ACE_RscGeneric_1: ACE_RscGeneric_BG
		{
			idc = 2;
			style = "0x02";
			h = 0.033;
			w = 0.17;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			font = "TahomaB";
			sizeEx = 0.033;
			shadow = 2;
		};
	};
};
//};
