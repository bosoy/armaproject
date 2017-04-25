////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.51
//Mon Jul 28 05:52:54 2014 : Source 'file' date Mon Jul 28 05:52:54 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_sight_adjustment : config.bin{
class CfgPatches
{
	class ace_sys_sight_adjustment
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ace_main","ace_c_weapon","ace_c_vehicle","ace_sys_interaction"};
		version = "1.14.0.593";
		author[] = {"q1184"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_sight_adjustment
		{
			list[] = {"ace_sys_sight_adjustment"};
		};
	};
};
class RscText;
class ACE_SYS_SA_RscText: RscText
{
	type = 0;
	idc = -1;
	style = 0;
	colorBackground[] = {0,0,0,0};
	colorText[] = {0,0,0,1};
	font = "TahomaB";
	sizeEx = 0.021;
	linespacing = 1.0;
	text = "";
	shadow = 0;
};
class RscTextRightAl;
class ACE_SYS_SA_RscTextRightAl: RscTextRightAl
{
	type = 0;
	idc = -1;
	style = 1;
	colorBackground[] = {0,0,0,0};
	colorText[] = {0,0,0,1};
	font = "TahomaB";
	sizeEx = 0.024;
	linespacing = 1.0;
	text = "";
	shadow = 0;
};
class RscStructuredText;
class ACE_SYS_SA_RscStructuredText: RscStructuredText
{
	access = 0;
	type = 13;
	style = "0x0c";
	size = 0.0208333;
	colorText[] = {0,0,0,1};
	class Attributes
	{
		font = "TahomaB";
		color = "000000";
		align = "center";
		shadow = 0;
	};
};
class RscListBox;
class ACE_SYS_SA_RscListBox: RscListBox
{
	access = 0;
	style = 0;
	idc = -1;
	color[] = {0,0,0,1};
	colorSelect[] = {0,0,0,1};
	colorSelectBackground[] = {0,0,0,0};
	colorSelect2[] = {0,0,0,0};
	colorSelectBackground2[] = {0,0,0,0};
	colorText[] = {0,0,0,1};
	colorBackground[] = {0,0,0,0};
	colorScrollbar[] = {0,0,0,1};
	colorBorder[] = {0,0,0,1};
	font = "BitStream";
	sizeEx = 0.022;
	rowHeight = 0.024;
	canDrag = 0;
	shadow = 0;
};
class RscFrame;
class RscButton;
class ACE_SYS_SA_RscButton: RscButton
{
	access = 0;
	idc = -1;
	type = 1;
	style = "0x02";
	default = 0;
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.1;
	text = "";
	font = "TahomaB";
	sizeEx = 0.024;
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
	shadow = 0;
};
class RscEdit;
class ACE_SYS_SA_RscEdit: RscEdit
{
	type = 2;
	idc = -1;
	style = "0x02+ 0x0c";
	font = "TahomaB";
	sizeEx = 0.024;
	colorText[] = {0,0,0,1};
	colorSelection[] = {0.20392,0.4,0.05882,1.0};
	autocomplete = 0;
	text = "";
	shadow = 0;
};
class ACE_SYS_SA_RscPicture
{
	access = 0;
	type = 0;
	idc = -1;
	style = 48;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = "TahomaB";
	sizeEx = 0;
	lineSpacing = 0;
	text = "";
	borderSize = 0;
};
class ACE_SYS_SA_MainBack: ACE_SYS_SA_RscText
{
	text = "";
	colorText[] = {0.34,0.34,0.34,0.5};
	colorBackground[] = {0.34,0.34,0.34,0.5};
};
class ACE_SYS_SA_ControlBack: ACE_SYS_SA_MainBack
{
	text = "\CA\UI\Data\ui_gradient_reverse_gs.paa";
	colorText[] = {0.34,0.34,0.34,0.5};
	colorBackground[] = {0.34,0.34,0.34,0.5};
};
class ACE_SYS_SA_TitleBack: ACE_SYS_SA_RscPicture
{
	text = "\CA\UI\Data\ui_gradient_title_gs.paa";
	colorText[] = {0.34,0.34,0.34,0.5};
	colorBackground[] = {0.34,0.34,0.34,0.5};
};
class ACE_SYS_SA_ArrowDown: ACE_SYS_SA_RscPicture
{
	text = "\CA\UI\textures\arrow_down.paa";
	colorText[] = {0,0,0,1};
	colorBackground[] = {0,0,0,0};
};
class ACE_SYS_SA_ArrowUp: ACE_SYS_SA_ArrowDown
{
	text = "\CA\UI\textures\arrow_up.paa";
};
class ACE_SYS_SA_ArrowLeft: ACE_SYS_SA_ArrowDown
{
	text = "\x\ace\addons\sys_sight_adjustment\data\arrow_left.paa";
};
class ACE_SYS_SA_ArrowRight: ACE_SYS_SA_ArrowDown
{
	text = "\x\ace\addons\sys_sight_adjustment\data\arrow_right.paa";
};
class ACE_SYS_SA_RNG_Dialog
{
	idd = -1;
	movingEnable = 1;
	controlsBackground[] = {"DialogFrame","InnerDialogFrame"};
	class DialogFrame: ACE_SYS_SA_MainBack
	{
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165";
		y = "SafeZoneY + 0";
		w = 0.345;
		h = 0.15;
		moving = 1;
	};
	class InnerDialogFrame: ACE_SYS_SA_MainBack
	{
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.007";
		y = "SafeZoneY + 0+ 0.01";
		w = 0.331;
		h = 0.13;
		moving = 1;
		colorBackground[] = {0.8,0.8,0.8,0.7};
		colorBorder[] = {0,0,0,1};
		BorderSize = 0.003;
	};
	objects[] = {};
	controls[] = {"Txt_Elev","Txt_RngUnit","Txt_Windage","Txt_WindUnit","Btn_PreviousElev","Btn_NextElev","Btn_PreviousWnd","Btn_NextWnd","Txt_Elev0","Edt_Windage","ArrowUpRng","ArrowDownRng","ArrowLeft","ArrowRight","Btn_Apply"};
	class Txt_Elev: ACE_SYS_SA_RscText
	{
		idc = 3000;
		text = "Range";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.01";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.06;
		h = 0.028;
	};
	class Txt_RngUnit: ACE_SYS_SA_RscText
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
	class Btn_PreviousElev: ACE_SYS_SA_RscButton
	{
		idc = 3031;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.12";
		y = "SafeZoneY + 0+ 0.045";
		w = 0.025;
		h = 0.025;
		action = "call ace_sys_sight_adjustment_fnc_prevRng";
	};
	class ArrowDownRng: ACE_SYS_SA_ArrowDown
	{
		idc = -1;
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.12";
		y = "SafeZoneY + 0+0.045";
		w = 0.025;
		h = 0.025;
	};
	class Btn_NextElev: ACE_SYS_SA_RscButton
	{
		idc = 3032;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.12";
		y = "SafeZoneY + 0+ 0.026";
		w = 0.025;
		h = 0.025;
		action = "call ace_sys_sight_adjustment_fnc_nextRng";
	};
	class ArrowUpRng: ACE_SYS_SA_ArrowUp
	{
		idc = -1;
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.12";
		y = "SafeZoneY + 0+ 0.026";
		w = 0.025;
		h = 0.025;
	};
	class Txt_Elev0: ACE_SYS_SA_RscTextRightAl
	{
		idc = 3033;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.065";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.05;
		h = 0.028;
	};
	class Txt_Windage: ACE_SYS_SA_RscText
	{
		idc = 3200;
		text = "Windage";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.17";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.07;
		h = 0.028;
		colorText[] = {0,0,0,1};
	};
	class Txt_WindUnit: ACE_SYS_SA_RscText
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
	class Edt_Windage: ACE_SYS_SA_RscText
	{
		style = "0x02";
		idc = 3097;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.262";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.04;
		h = 0.028;
	};
	class Btn_PreviousWnd: ACE_SYS_SA_RscButton
	{
		idc = 3041;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.24";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.025;
		h = 0.025;
		action = "call ace_sys_sight_adjustment_fnc_prevWnd";
	};
	class ArrowLeft: ACE_SYS_SA_ArrowLeft
	{
		idc = -1;
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.24";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.025;
		h = 0.025;
	};
	class Btn_NextWnd: ACE_SYS_SA_RscButton
	{
		idc = 3042;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.3";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.025;
		h = 0.025;
		action = "call ace_sys_sight_adjustment_fnc_nextWnd";
	};
	class ArrowRight: ACE_SYS_SA_ArrowRight
	{
		idc = -1;
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.3";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.025;
		h = 0.025;
	};
	class Btn_Apply: ACE_SYS_SA_RscButton
	{
		idc = 3148;
		default = 1;
		text = "$STR_ACE_SA_CONFIRM";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.244";
		y = "SafeZoneY + 0+ 0.1 + 0.001";
		w = 0.07;
		h = 0.035;
		action = "call ace_sys_sight_adjustment_fnc_ApplyRngChanges";
	};
};
class ACE_SYS_SA_ELEV_Dialog
{
	idd = -1;
	movingEnable = 1;
	controlsBackground[] = {"DialogFrame","InnerDialogFrame"};
	class DialogFrame: ACE_SYS_SA_MainBack
	{
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165";
		y = "SafeZoneY + 0";
		w = 0.345;
		h = 0.15;
		moving = 1;
	};
	class InnerDialogFrame: ACE_SYS_SA_MainBack
	{
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.007";
		y = "SafeZoneY + 0+ 0.01";
		w = 0.331;
		h = 0.13;
		moving = 1;
		colorBackground[] = {0.8,0.8,0.8,0.7};
		colorBorder[] = {0,0,0,1};
		BorderSize = 0.003;
	};
	objects[] = {};
	controls[] = {"Txt_Elev","Txt_Windage","Txt_ElevUnit","Txt_WindUnit","Btn_PreviousElev","Btn_NextElev","Btn_PreviousWnd","Btn_NextWnd","Edt_Elev","Edt_Windage","ArrowUp","ArrowDown","ArrowLeft","ArrowRight","Btn_Apply","Btn_RngCard","RangeCardFrame","InnerRangeCardFrame","Txt_HeaderElev","Txt_HeaderIndirElev","Txt_HeaderRange","LB","Column","Column1"};
	class Txt_Elev: ACE_SYS_SA_RscText
	{
		idc = 3000;
		text = "Elev";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.01";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.06;
		h = 0.028;
	};
	class Txt_ElevUnit: ACE_SYS_SA_RscText
	{
		style = "0x02";
		SizeEx = 0.02;
		idc = 3501;
		text = "mil";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.065";
		y = "SafeZoneY + 0+ 0.06";
		w = 0.05;
		h = 0.022;
	};
	class Btn_PreviousElev: ACE_SYS_SA_RscButton
	{
		idc = 3031;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.12";
		y = "SafeZoneY + 0+ 0.045";
		w = 0.025;
		h = 0.025;
		action = "call ace_sys_sight_adjustment_fnc_prevElev";
		colorDisabled[] = {0,0,0,0};
		colorBackground[] = {0,0,0,0};
		colorBackgroundDisabled[] = {0,0,0,0};
		colorBackgroundActive[] = {0,0,0,0};
	};
	class ArrowDown: ACE_SYS_SA_ArrowDown
	{
		idc = -1;
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.12";
		y = "SafeZoneY + 0+0.045";
		w = 0.025;
		h = 0.025;
	};
	class Btn_NextElev: ACE_SYS_SA_RscButton
	{
		idc = 3032;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.12";
		y = "SafeZoneY + 0+0.026";
		w = 0.025;
		h = 0.025;
		action = "call ace_sys_sight_adjustment_fnc_nextElev";
		colorDisabled[] = {0,0,0,0};
		colorBackground[] = {0,0,0,0};
		colorBackgroundDisabled[] = {0,0,0,0};
		colorBackgroundActive[] = {0,0,0,0};
	};
	class ArrowUp: ACE_SYS_SA_ArrowUp
	{
		idc = -1;
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.12";
		y = "SafeZoneY + 0+ 0.026";
		w = 0.025;
		h = 0.025;
	};
	class Edt_Elev: ACE_SYS_SA_RscEdit
	{
		idc = 3033;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.065";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.05;
		h = 0.028;
	};
	class Txt_Windage: ACE_SYS_SA_RscText
	{
		idc = 3200;
		text = "Windage";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.17";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.07;
		h = 0.028;
		colorText[] = {0,0,0,1};
	};
	class Txt_WindUnit: ACE_SYS_SA_RscText
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
	class Edt_Windage: ACE_SYS_SA_RscEdit
	{
		idc = 3097;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.262";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.04;
		h = 0.028;
	};
	class Btn_PreviousWnd: ACE_SYS_SA_RscButton
	{
		idc = 3041;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.24";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.025;
		h = 0.025;
		action = "call ace_sys_sight_adjustment_fnc_prevWnd";
	};
	class ArrowLeft: ACE_SYS_SA_ArrowLeft
	{
		idc = -1;
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.24";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.025;
		h = 0.025;
	};
	class Btn_NextWnd: ACE_SYS_SA_RscButton
	{
		idc = 3042;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.3";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.025;
		h = 0.025;
		action = "call ace_sys_sight_adjustment_fnc_nextWnd";
	};
	class ArrowRight: ACE_SYS_SA_ArrowRight
	{
		idc = -1;
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.3";
		y = "SafeZoneY + 0+ 0.035";
		w = 0.025;
		h = 0.025;
	};
	class Btn_RngCard: ACE_SYS_SA_RscButton
	{
		idc = 3147;
		sizeEx = 0.021;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.01";
		y = "SafeZoneY + 0+ 0.1";
		w = 0.09;
		h = 0.035;
		action = "";
	};
	class Btn_Apply: ACE_SYS_SA_RscButton
	{
		idc = 3148;
		default = 1;
		text = "Confirm";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.244";
		y = "SafeZoneY + 0+ 0.1 + 0.001";
		w = 0.07;
		h = 0.035;
		action = "call ace_sys_sight_adjustment_fnc_ApplyElevChanges";
	};
	class RangeCardFrame: ACE_SYS_SA_MainBack
	{
		idc = 4000;
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165";
		y = "SafeZoneY + 0+0.15";
		w = 0.26;
		h = 0.3;
		moving = 1;
	};
	class InnerRangeCardFrame: ACE_SYS_SA_MainBack
	{
		idc = 4001;
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.007";
		y = "SafeZoneY + 0+0.15+ 0.01";
		w = 0.246;
		h = 0.28;
		moving = 1;
		colorBackground[] = {0.8,0.8,0.8,0.7};
		text = "";
		colorText[] = {0,0,0,1};
	};
	class Txt_HeaderRange: ACE_SYS_SA_RscText
	{
		idc = 4002;
		text = "Range, m";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.01";
		y = "SafeZoneY + 0+0.15+ 0.035";
		w = 0.07;
		h = 0.028;
	};
	class Txt_HeaderElev: ACE_SYS_SA_RscText
	{
		idc = 4003;
		text = "Elev, mil";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.085";
		y = "SafeZoneY + 0+0.15+ 0.035";
		w = 0.085;
		h = 0.028;
	};
	class Txt_HeaderIndirElev: ACE_SYS_SA_RscText
	{
		idc = 4004;
		text = "Indir.";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.157";
		y = "SafeZoneY + 0+0.15+ 0.035";
		w = 0.11;
		h = 0.028;
	};
	class LB: ACE_SYS_SA_RscListBox
	{
		idc = 4005;
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.01";
		y = "SafeZoneY + 0+0.15+ 0.07";
		w = 0.242;
		h = 0.2;
		moving = 1;
	};
	class Column: ACE_SYS_SA_RscButton
	{
		idc = 4006;
		text = "";
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.01 + 0.075";
		y = "SafeZoneY + 0+0.15+ 0.07";
		w = 0.00015;
		h = 0.202;
		colorBackground[] = {0,0,0,0};
		colorBorder[] = {0.5,0.5,0.5,0.5};
		BorderSize = 0.00015;
		action = "";
	};
	class Column1: Column
	{
		idc = 4007;
		x = "SafeZoneX + SafeZoneW*0.5 - 0.165+ 0.152";
	};
};
class ACE_SYS_SA_RangeCard
{
	idd = 2999;
	movingEnable = 1;
	controlsBackground[] = {"RangeCardFrame","InnerRangeCardFrame"};
	class RangeCardFrame: ACE_SYS_SA_MainBack
	{
		x = 0.37;
		y = "SafeZoneY + 0+0.15";
		w = 0.26;
		h = 0.3;
		moving = 1;
	};
	class InnerRangeCardFrame: ACE_SYS_SA_MainBack
	{
		x = "0.37+ 0.007";
		y = "SafeZoneY + 0+0.15+ 0.01";
		w = 0.246;
		h = 0.28;
		moving = 1;
		colorBackground[] = {0.8,0.8,0.8,0.7};
		text = "";
		colorText[] = {0,0,0,1};
	};
	objects[] = {};
	controls[] = {"Txt_HeaderElev","Txt_HeaderIndirElev","Txt_HeaderRange","LB","Column","Column1","Btn_CloseRC"};
	class Txt_HeaderRange: ACE_SYS_SA_RscText
	{
		idc = 4002;
		text = "Range, m";
		x = "0.37+ 0.01";
		y = "SafeZoneY + 0+0.15+ 0.035";
		w = 0.07;
		h = 0.028;
	};
	class Txt_HeaderElev: ACE_SYS_SA_RscText
	{
		idc = 4003;
		text = "Elev, mil";
		x = "0.37+ 0.085";
		y = "SafeZoneY + 0+0.15+ 0.035";
		w = 0.085;
		h = 0.028;
	};
	class Txt_HeaderIndirElev: ACE_SYS_SA_RscText
	{
		idc = 4004;
		text = "Indir.";
		x = "0.37+ 0.157";
		y = "SafeZoneY + 0+0.15+ 0.035";
		w = 0.1;
		h = 0.028;
	};
	class LB: ACE_SYS_SA_RscListBox
	{
		idc = 4005;
		x = "0.37+ 0.01";
		y = "SafeZoneY + 0+0.15+ 0.07";
		w = 0.242;
		h = 0.2;
		moving = 1;
	};
	class Column: ACE_SYS_SA_RscButton
	{
		idc = 4006;
		text = "";
		x = "0.37+ 0.01 + 0.075";
		y = "SafeZoneY + 0+0.15+ 0.07";
		w = 0.00015;
		h = 0.202;
		colorBackground[] = {0,0,0,0};
		colorBorder[] = {0.5,0.5,0.5,0.5};
		BorderSize = 0.00015;
		action = "";
	};
	class Column1: Column
	{
		idc = 4007;
		x = "0.37+ 0.152";
	};
	class Btn_CloseRC: ACE_SYS_SA_RscButton
	{
		idc = 3999;
		text = "x";
		x = "0.37+ 0.235";
		y = "SafeZoneY + 0+0.15+ 0.01";
		w = 0.025;
		h = 0.025;
		action = "closeDialog 1";
	};
};
class cfgWeapons
{
	class MGun;
	class AGS30: MGun
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "angle";
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
		ace_sa_minelevation = 0;
		ace_sa_maxelevation = 1167;
		ace_sa_stepelevation = 1;
		ace_sa_windage = 50;
		ace_sa_stepwindage = 1;
		ace_sa_elev_unit = "mil_E";
		ace_sa_wind_unit = "mil_E";
		ace_sa_range_unit = "meters";
		ace_sa_TE_enabled = 1;
		ace_sa_table_elev[] = {{ 0,0 },{ 50,2 },{ 100,9 },{ 150,17 },{ 200,25 },{ 250,33 },{ 300,41 },{ 350,49 },{ 400,58 },{ 450,67 },{ 500,76 },{ 550,86 },{ 600,96 },{ 650,106 },{ 700,116 },{ 750,127 },{ 800,139 },{ 850,151 },{ 900,164 },{ 950,177 },{ 1000,191,1167 },{ 1050,206,1149 },{ 1100,221,1131 },{ 1150,237,1113 },{ 1200,254,1094 },{ 1250,273,1074 },{ 1300,292,1052 },{ 1350,313,1029 },{ 1400,335,1005 },{ 1450,359,978 },{ 1500,386,949 },{ 1550,417,917 },{ 1600,453,879 },{ 1650,496,833 },{ 1700,557,768 },{ 1730,667,667 }};
	};
	class Mk19: MGun
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "range";
		ace_sa_defaultelevation = 35;
		ace_sa_defaultwindage = -8;
		ace_sa_minelevation = 300;
		ace_sa_maxelevation = 1500;
		ace_sa_stepelevation = 100;
		ace_sa_windage = 10;
		ace_sa_stepwindage = 1;
		ace_sa_elev_unit = "mil";
		ace_sa_wind_unit = "mil";
		ace_sa_range_unit = "meters";
		ace_sa_TE_enabled = 1;
		ace_sa_table_elev[] = {{ 0,0 },{ 100,9 },{ 200,18.6 },{ 300,29.1 },{ 400,40.4 },{ 500,52.6 },{ 600,65.9 },{ 700,80.3 },{ 800,96 },{ 900,113.1 },{ 1000,131.9 },{ 1100,152.5 },{ 1200,175.2 },{ 1300,200.4 },{ 1400,228.6 },{ 1500,260.3 },{ 1600,296.7 },{ 1700,339.2 },{ 1800,390.8 },{ 1900,458.3 },{ 2000,570.1 }};
	};
	class BAF_static_GMG: MGun
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "range";
		ace_sa_defaultelevation = 6;
		ace_sa_defaultwindage = 0;
		ace_sa_minelevation = 300;
		ace_sa_maxelevation = 1500;
		ace_sa_stepelevation = 100;
		ace_sa_windage = 10;
		ace_sa_stepwindage = 1;
		ace_sa_elev_unit = "mil";
		ace_sa_wind_unit = "mil";
		ace_sa_range_unit = "meters";
		ace_sa_TE_enabled = 1;
		ace_sa_table_elev[] = {{ 0,0 },{ 100,9 },{ 200,18.6 },{ 300,29.1 },{ 400,40.4 },{ 500,52.6 },{ 600,65.9 },{ 700,80.3 },{ 800,96 },{ 900,113.1 },{ 1000,131.9 },{ 1100,152.5 },{ 1200,175.2 },{ 1300,200.4 },{ 1400,228.6 },{ 1500,260.3 },{ 1600,296.7 },{ 1700,339.2 },{ 1800,390.8 },{ 1900,458.3 },{ 2000,570.1 }};
	};
	class M2: MGun
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "range";
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
		ace_sa_minelevation = 100;
		ace_sa_maxelevation = 2600;
		ace_sa_stepelevation = 100;
		ace_sa_windage = 10;
		ace_sa_stepwindage = 1;
		ace_sa_elev_unit = "mil";
		ace_sa_wind_unit = "mil";
		ace_sa_range_unit = "yards";
		ace_sa_TE_enabled = 0;
		ace_sa_table_elev[] = {{ 0,0 },{ 100,0.52 },{ 200,1.21 },{ 300,1.89 },{ 400,2.62 },{ 500,3.41 },{ 600,4.21 },{ 700,5.11 },{ 800,6.09 },{ 900,7.03 },{ 1000,8.13 },{ 1100,9.35 },{ 1200,10.63 },{ 1300,12 },{ 1400,13.53 },{ 1500,15.14 },{ 1600,16.9 },{ 1700,18.79 },{ 1800,20.8 },{ 1900,22.99 },{ 2000,25.35 },{ 2100,27.94 },{ 2200,30.76 },{ 2300,33.77 },{ 2400,36.95 },{ 2500,40.55 },{ 2600,44.56 }};
	};
	class DshKM: MGun
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "range";
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
		ace_sa_minelevation = 100;
		ace_sa_maxelevation = 2000;
		ace_sa_stepelevation = 100;
		ace_sa_windage = 10;
		ace_sa_stepwindage = 1;
		ace_sa_elev_unit = "mil";
		ace_sa_wind_unit = "mil";
		ace_sa_range_unit = "meters";
		ace_sa_TE_enabled = 0;
		ace_sa_table_elev[] = {{ 0,0 },{ 100,0.7 },{ 200,1.4 },{ 300,2.3 },{ 400,3.2 },{ 500,4.2 },{ 600,5.3 },{ 700,6.5 },{ 800,7.8 },{ 900,9.2 },{ 1000,10.8 },{ 1100,12.4 },{ 1200,14.3 },{ 1300,16.2 },{ 1400,18.4 },{ 1500,20.8 },{ 1600,23.4 },{ 1700,26.4 },{ 1800,29.5 },{ 1900,32.9 },{ 2000,36.8 }};
	};
	class KORD: MGun
	{
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "range";
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
		ace_sa_minelevation = 100;
		ace_sa_maxelevation = 2000;
		ace_sa_stepelevation = 100;
		ace_sa_windage = 10;
		ace_sa_stepwindage = 1;
		ace_sa_elev_unit = "mil";
		ace_sa_wind_unit = "mil";
		ace_sa_range_unit = "meters";
		ace_sa_TE_enabled = 0;
		ace_sa_table_elev[] = {{ 0,0 },{ 100,0.7 },{ 200,1.4 },{ 300,2.3 },{ 400,3.2 },{ 500,4.2 },{ 600,5.3 },{ 700,6.5 },{ 800,7.8 },{ 900,9.2 },{ 1000,10.8 },{ 1100,12.4 },{ 1200,14.3 },{ 1300,16.2 },{ 1400,18.4 },{ 1500,20.8 },{ 1600,23.4 },{ 1700,26.4 },{ 1800,29.5 },{ 1900,32.9 },{ 2000,36.8 }};
	};
	class CannonCore;
	class M252: CannonCore
	{
		ace_sa_TE_enabled = 0;
	};
	class 2B14: CannonCore
	{
		ace_sa_TE_enabled = 0;
	};
	class M119: CannonCore
	{
		ace_sa_TE_enabled = 1;
		ace_sa_elev_unit = "mil";
	};
	class D30: CannonCore
	{
		ace_sa_TE_enabled = 1;
		ace_sa_elev_unit = "mil";
	};
	class ACE_M252_Tri: M252{};
	class ACE_M224_Tri: ACE_M252_Tri
	{
		ace_sa_TE_enabled = 0;
	};
};
class cfgVehicles
{
	class Land;
	class LandVehicle: Land
	{
		class NewTurret;
	};
	class Tank: LandVehicle
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				ace_sa_enabled = 0;
				class Turrets
				{
					class CommanderOptics: NewTurret
					{
						ace_sa_enabled = 1;
						ace_sa_te_enabled = 1;
					};
				};
			};
		};
	};
	class Tracked_APC: Tank
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						ace_sa_enabled = 0;
						ace_sa_te_enabled = 0;
					};
				};
			};
		};
	};
	class Car: LandVehicle
	{
		ace_sa_enabled = 1;
		ace_sa_te_enabled = 1;
		class Turrets
		{
			class MainTurret;
		};
	};
	class Wheeled_APC: Car
	{
		ace_sa_enabled = 0;
		ace_sa_te_enabled = 0;
	};
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class StaticMGWeapon: StaticWeapon
	{
		ace_sa_enabled = 1;
		ace_sa_te_enabled = 1;
	};
	class StaticGrenadeLauncher: StaticWeapon
	{
		ace_sa_enabled = 1;
		ace_sa_te_enabled = 1;
	};
	class StaticMortar: StaticWeapon
	{
		ace_sa_enabled = 1;
		ace_sa_te_enabled = 1;
	};
	class StaticCannon: StaticWeapon
	{
		ace_sa_enabled = 1;
		ace_sa_te_enabled = 1;
	};
	class AllVehicles;
	class Air: AllVehicles
	{
		class NewTurret;
	};
	class Helicopter: Air
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class Plane: Air
	{
		class NewTurret;
	};
	class Truck;
	class Ship: AllVehicles
	{
		class NewTurret;
		class Turrets;
	};
	class Boat: Ship{};
	class HMMWV_Base;
	class HMMWV_M2: HMMWV_Base
	{
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
	};
	class HMMWV_MK19: HMMWV_Base{};
	class HMMWV_M998_crows_MK19_DES_EP1: HMMWV_Base
	{
		ace_sa_enabled = 0;
		ace_sa_te_enabled = 1;
	};
	class HMMWV_M998_crows_M2_DES_EP1: HMMWV_Base
	{
		ace_sa_enabled = 0;
		ace_sa_te_enabled = 0;
	};
	class BAF_Jackal2_BASE_D: Car
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class BAF_Jackal2_L2A1_D: BAF_Jackal2_BASE_D
	{
		class Turrets: Turrets
		{
			class M2_Turret: MainTurret
			{
				ace_sa_enabled = 1;
			};
		};
	};
	class BAF_Jackal2_GMG_D: BAF_Jackal2_BASE_D
	{
		class Turrets: Turrets
		{
			class GMG_Turret: MainTurret
			{
				ace_sa_enabled = 1;
				ace_sa_te_enabled = 1;
			};
		};
	};
	class AAV: Tracked_APC
	{
		ace_sa_enabled = 1;
		ace_sa_te_enabled = 1;
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
	};
	class BTR90_Base: Wheeled_APC
	{
		ace_sa_enabled = 1;
		ace_sa_te_enabled = 1;
	};
	class UAZ_Base;
	class UAZ_MG_Base: UAZ_Base
	{
		ace_sa_defaultelevation = -3.8;
		ace_sa_defaultwindage = 0;
	};
	class UAZ_AGS30_Base;
	class UAZ_AGS30_RU: UAZ_AGS30_Base
	{
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
	};
	class M113_Base: Tank
	{
		ace_sa_enabled = 1;
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
	};
	class T72_Base: Tank
	{
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
	};
	class T90: Tank
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: NewTurret
					{
						ace_sa_enabled = 1;
						ace_sa_te_enabled = 1;
					};
				};
			};
		};
	};
	class M1A1: Tank
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						ace_sa_defaultelevation = 0;
						ace_sa_defaultwindage = 0;
						ace_sa_range_unit = "meters";
						ace_sa_maxelevation = 2000;
						ace_sa_table_elev[] = {{ 0,0 },{ 100,0.52 },{ 200,1.37 },{ 300,1.9 },{ 400,2.72 },{ 500,4.1 },{ 600,4.6 },{ 700,5.58 },{ 800,6.7 },{ 900,7.93 },{ 1000,9.22 },{ 1100,10.7 },{ 1200,12.18 },{ 1300,13.85 },{ 1400,15.7 },{ 1500,17.75 },{ 1600,19.85 },{ 1700,22.2 },{ 1800,24.76 },{ 1900,27.5 },{ 2000,30.5 }};
					};
				};
			};
		};
	};
	class StrykerBase_EP1: Wheeled_APC
	{
		ace_sa_enabled = 0;
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
	};
	class M1126_ICV_BASE_EP1: StrykerBase_EP1{};
	class M1126_ICV_M2_EP1: M1126_ICV_BASE_EP1
	{
		ace_sa_enabled = 0;
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
		ace_sa_range_unit = "meters";
		ace_sa_maxelevation = 2000;
		ace_sa_table_elev[] = {{ 0,0 },{ 100,0.52 },{ 200,1.37 },{ 300,1.9 },{ 400,2.72 },{ 500,4.1 },{ 600,4.6 },{ 700,5.58 },{ 800,6.7 },{ 900,7.93 },{ 1000,9.22 },{ 1100,10.7 },{ 1200,12.18 },{ 1300,13.85 },{ 1400,15.7 },{ 1500,17.75 },{ 1600,19.85 },{ 1700,22.2 },{ 1800,24.76 },{ 1900,27.5 },{ 2000,30.5 }};
	};
	class M1126_ICV_mk19_EP1: M1126_ICV_BASE_EP1
	{
		ace_sa_enabled = 0;
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
		ace_sa_maxelevation = 2000;
		ace_sa_minelevation = 300;
		ace_sa_stepelevation = 100;
		ace_sa_windage = 10;
		ace_sa_stepwindage = 1;
		ace_sa_elev_unit = "mil";
		ace_sa_wind_unit = "mil";
		ace_sa_range_unit = "meters";
		ace_sa_TE_enabled = 0;
		ace_sa_table_elev[] = {{ 0,0 },{ 100,9 },{ 200,18.6 },{ 300,28 },{ 400,39 },{ 500,51 },{ 600,64 },{ 700,78 },{ 800,93 },{ 900,110 },{ 1000,128 },{ 1100,148 },{ 1200,171 },{ 1300,195 },{ 1400,223 },{ 1500,255 },{ 1600,285 },{ 1700,326 },{ 1800,380 },{ 1900,450 },{ 2000,570 }};
	};
	class RHIB: Boat
	{
		ace_sa_enabled = 1;
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class RHIB2Turret: RHIB
	{
		class Turrets: Turrets
		{
			class MainTurret;
			class BackTurret: MainTurret
			{
				ace_sa_enabled = 1;
				ace_sa_defaultelevation = 43;
				ace_sa_defaultwindage = 0;
				ace_sa_TE_enabled = 0;
			};
		};
	};
	class DSHKM_base;
	class DSHkM_Mini_TriPod: DSHKM_base
	{
		ace_sa_defaultelevation = 4.2;
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_sight_adjustment
	{
		clientInit = "call ('\x\ace\addons\sys_sight_adjustment\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class LandVehicle
	{
		class ace_sys_sight_adjustment
		{
			exclude[] = {"ACE_Stretcher"};
			clientFiredBis = "if (!isnil {(_this select 0) getVariable 'ace_sys_sight_adjustment_params'}) then {_this call ace_sys_sight_adjustment_fnc_fired};";
		};
	};
	class Ship
	{
		class ace_sys_sight_adjustment
		{
			clientFiredBis = "if (!isnil {(_this select 0) getVariable 'ace_sys_sight_adjustment_params'}) then {_this call ace_sys_sight_adjustment_fnc_fired};";
		};
	};
};
//};
