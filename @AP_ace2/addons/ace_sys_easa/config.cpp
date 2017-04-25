////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Apr 12 20:54:58 2013 : Created on Fri Apr 12 20:54:58 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_easa : config.bin{
class CfgPatches
{
	class ace_sys_easa
	{
		units[] = {"ACE_EASA","ACE_EASA_Vehicle"};
		weapons[] = {"ACE_HellfireLauncher","ACE_SidewinderLaucher","ACE_BombLauncher","ACE_Mk82BombLauncher","ACE_B61BombLauncher","ACE_MaverickLauncher","ACE_AT2Launcher","ACE_Ch29Launcher_Su34","ACE_R73Launcher","ACE_AirBombLauncher"};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","Extended_EventHandlers","ace_main","ace_c_vehicle","ace_c_weapon","CAMisc_E"};
		version = "1.14.0.592";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_easa
		{
			list[] = {"ace_sys_easa"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_easa
	{
		init = "call ('\x\ace\addons\sys_easa\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgWeapons
{
	class HellfireLauncher;
	class ACE_HellfireLauncher: HellfireLauncher
	{
		ACE_EASA = 1;
	};
	class SidewinderLaucher;
	class ACE_SidewinderLaucher: SidewinderLaucher
	{
		ACE_EASA = 1;
	};
	class BombLauncher;
	class ACE_BombLauncher: BombLauncher
	{
		ACE_EASA = 1;
	};
	class Mk82BombLauncher;
	class ACE_Mk82BombLauncher: Mk82BombLauncher
	{
		ACE_EASA = 1;
	};
	class MaverickLauncher;
	class ACE_MaverickLauncher: MaverickLauncher
	{
		ACE_EASA = 1;
	};
	class ACE_HellfireLauncher_Apache: HellfireLauncher
	{
		ACE_EASA = 1;
	};
	class ACE__B61BombLauncher;
	class ACE_B61BombLauncher: ACE__B61BombLauncher
	{
		ACE_EASA = 1;
	};
	class AT2Launcher;
	class ACE_AT2Launcher: AT2Launcher
	{
		ACE_EASA = 1;
	};
	class Ch29Launcher_Su34;
	class ACE_Kh29Launcher: Ch29Launcher_Su34
	{
		ACE_EASA = 1;
	};
	class ACE_Kh25Launcher: Ch29Launcher_Su34
	{
		ACE_EASA = 1;
	};
	class R73Launcher;
	class ACE_R73Launcher: R73Launcher
	{
		ACE_EASA = 1;
	};
	class AirBombLauncher;
	class ACE_AirBombLauncher: AirBombLauncher
	{
		ACE_EASA = 1;
	};
	class ACE_FAB500M62Launcher: AirBombLauncher
	{
		ACE_EASA = 1;
	};
	class ACE_KAB500KRLauncher: BombLauncher
	{
		ACE_EASA = 1;
	};
	class ACE_KAB500LLauncher: ACE_KAB500KRLauncher
	{
		ACE_EASA = 1;
	};
};
class CfgMagazines
{
	class Vehiclemagazine;
	class ACE_1Rnd_EASA_Pylon: Vehiclemagazine
	{
		scope = 1;
		displayName = "Pylon";
		ammo = "FakeAmmo";
		ACE_EASA_RACK = 1;
		ACE_EASA = 0;
		ACE_EASA_COUNT = 4;
		ACE_EASA_WEAPON = "FakeWeapon";
		ACE_EASA_NAME = "Pylon X";
		ACE_EASA_CARRIER[] = {"Plane","Helicopter"};
	};
	class 8Rnd_Hellfire;
	class ACE_1Rnd_Hellfire: 8Rnd_Hellfire
	{
		count = 1;
		ACE_EASA_SIDE = 1;
		ACE_EASA_WEAPON = "ACE_HellfireLauncher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "AGM-114K";
		ACE_EASA_CARRIER[] = {"Plane","Helicopter","UAV"};
	};
	class 4Rnd_Sidewinder_AV8B;
	class ACE_1Rnd_Sidewinder: 4Rnd_Sidewinder_AV8B
	{
		count = 1;
		ACE_EASA_SIDE = 1;
		ACE_EASA_WEAPON = "ACE_SidewinderLaucher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "AIM-9";
		ACE_EASA_CARRIER[] = {"Plane","Helicopter"};
	};
	class 6Rnd_GBU12_AV8B;
	class ACE_1Rnd_GBU12: 6Rnd_GBU12_AV8B
	{
		count = 1;
		ACE_EASA_SIDE = 1;
		ACE_EASA_WEAPON = "ACE_Bomblauncher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "GBU-12";
		ACE_EASA_CARRIER[] = {"Plane"};
	};
	class 6Rnd_Mk82;
	class ACE_1Rnd_Mk82: 6Rnd_Mk82
	{
		count = 1;
		ACE_EASA_SIDE = 1;
		ACE_EASA_WEAPON = "ACE_Mk82BombLauncher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "Mk82";
		ACE_EASA_CARRIER[] = {"Plane"};
	};
	class 2Rnd_Maverick_A10;
	class ACE_1Rnd_Maverick: 2Rnd_Maverick_A10
	{
		count = 1;
		ACE_EASA_SIDE = 1;
		ACE_EASA_WEAPON = "ACE_MaverickLauncher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "AGM-65D";
		ACE_EASA_CARRIER[] = {"Plane"};
	};
	class 4Rnd_R73;
	class ACE_1Rnd_R73: 4Rnd_R73
	{
		count = 1;
		ACE_EASA_SIDE = 0;
		ACE_EASA_WEAPON = "ACE_R73Launcher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "R-73";
		ACE_EASA_CARRIER[] = {"Plane"};
	};
	class ACE_1Rnd_Kh25: 4Rnd_R73
	{
		count = 1;
		ACE_EASA_SIDE = 0;
		ACE_EASA_WEAPON = "ACE_Kh25Launcher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "Kh-25 ML";
		ACE_EASA_CARRIER[] = {"Plane"};
	};
	class 4Rnd_Ch29;
	class ACE_1Rnd_Kh29: 4Rnd_Ch29
	{
		count = 1;
		ACE_EASA_SIDE = 0;
		ACE_EASA_WEAPON = "ACE_Kh29Launcher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "Ch-29";
		ACE_EASA_CARRIER[] = {"Plane"};
	};
	class 4Rnd_FAB_250;
	class ACE_1Rnd_FAB_250: 4Rnd_FAB_250
	{
		count = 1;
		ACE_EASA_SIDE = 0;
		ACE_EASA_WEAPON = "ACE_AirBombLauncher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "FAB-250";
		ACE_EASA_CARRIER[] = {"Plane"};
	};
	class ACE_1Rnd_FAB500M62: 6Rnd_Mk82
	{
		ACE_EASA_SIDE = 0;
		ACE_EASA_WEAPON = "ACE_FAB500M62Launcher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "FAB-500 M62";
		ACE_EASA_CARRIER[] = {"Plane"};
	};
	class ACE_1Rnd_KAB500KR: 6Rnd_Mk82
	{
		ACE_EASA_SIDE = 0;
		ACE_EASA_WEAPON = "ACE_KAB500KRLauncher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "KAB-500 KR";
		ACE_EASA_CARRIER[] = {"Plane"};
	};
	class ACE_1Rnd_KAB500L: 6Rnd_Mk82
	{
		ACE_EASA_SIDE = 0;
		ACE_EASA_WEAPON = "ACE_KAB500LLauncher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "KAB-500 L";
		ACE_EASA_CARRIER[] = {"Plane"};
	};
	class 4Rnd_AT2_Mi24D;
	class ACE_1Rnd_AT2_Mi24D: 4Rnd_AT2_Mi24D
	{
		count = 1;
		ACE_EASA_SIDE = 0;
		ACE_EASA_WEAPON = "ACE_AT2Launcher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "Falanga 3M11";
		ACE_EASA_CARRIER[] = {"Helicopter"};
	};
	class ACE_8Rnd_Hellfire_L;
	class ACE_1Rnd_Hellfire_L: ACE_8Rnd_Hellfire_L
	{
		count = 1;
		ACE_EASA_SIDE = 1;
		ACE_EASA_WEAPON = "ACE_HellfireLauncher_Apache";
		ACE_EASA = 1;
		ACE_EASA_NAME = "AGM-114L";
		ACE_EASA_CARRIER[] = {"AH64D"};
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ACE_EASA: ACE_Logic
	{
		displayName = "$STR_ACE_EASA_NAME";
		icon = "\x\ace\addons\sys_easa\data\icon\icon_ace_easa_ca.paa";
		picture = "\x\ace\addons\sys_easa\data\icon\icon_ace_easa_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then {private [""_o""];_o = _this execVM ""\x\ace\addons\sys_easa\ACE_EASA_Init.sqf""};";
		};
	};
	class PowGen_Big_EP1;
	class ACE_EASA_Vehicle: PowGen_Big_EP1
	{
		scope = 1;
		displayName = "";
		icon = "";
		class UserActions
		{
			class ACE_EASA
			{
				displayName = "$STR_ACE_EASA_ACTION";
				position = "start1";
				radius = 5;
				onlyforPlayer = 1;
				condition = "alive this";
				statement = "this execVM '\x\ace\addons\sys_easa\ua_change_load.sqf'";
			};
		};
	};
};
class ACE_EASA_RscText
{
	type = 0;
	idc = -1;
	style = "0x00";
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = "TahomaB";
	sizeEx = 0.02;
	text = "";
};
class ACE_EASA_RscBgFrame
{
	type = 0;
	idc = -1;
	style = 64;
	colorBackground[] = {0.4,0.4,0.4,0.75};
	colorText[] = {0,0,0,1};
	font = "TahomaB";
	SizeEX = 0.025;
	text = "";
};
class ACE_EASA_RscBackground
{
	colorBackground[] = {0.4,0.4,0.4,0.75};
	text = "";
	type = 0;
	idc = -1;
	style = "0x00";
	colorText[] = {1,1,1,1};
	font = "TahomaB";
	sizeEx = 0.04;
};
class ACE_EASA_RscPicture
{
	type = 0;
	idc = -1;
	style = 48;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = "TahomaB";
	sizeEx = 0.02;
	text = "";
};
class ACE_EASA_RscButton
{
	type = 1;
	idc = -1;
	style = "0x02";
	colorText[] = {0,0,0,1};
	font = "TahomaB";
	sizeEx = 0.025;
	soundPush[] = {"",0.2,1};
	soundClick[] = {"\ca\ui\data\sound\new1",0.2,1};
	soundEscape[] = {"\ca\ui\data\sound\onescape",0.2,1};
	default = "false";
	text = "";
	action = "";
	colorActive[] = {0,0,0,0};
	colorDisabled[] = {0,0,0,0.1};
	colorBackground[] = {0,0,0,0.3};
	colorBackgroundActive[] = {0,0,0,0.4};
	colorBackgroundDisabled[] = {0,0,0,0.3};
	colorFocused[] = {0.84,1,0.55,1};
	colorShadow[] = {1,1,1,0.1};
	colorBorder[] = {0,0,0,0.1};
	offsetX = 0;
	offsetY = 0;
	offsetPressedX = 0;
	offsetPressedY = 0;
	borderSize = 0;
	soundEnter[] = {"",0.15,1};
};
class ACE_EASA_RscButton2: ACE_EASA_RscButton
{
	x = -1.0;
	y = -1.0;
	idc = -1;
	w = 0.01;
	h = 0.01;
	default = "true";
};
class ACE_EASA_RscShortcutButton
{
	type = 16;
	idc = -1;
	style = 0;
	default = 0;
	w = 0.183825;
	h = 0.104575;
	color[] = {0.543,0.5742,0.4102,1};
	color2[] = {0.95,0.95,0.95,1};
	colorBackground[] = {1,1,1,1};
	colorbackground2[] = {1,1,1,0.4};
	colorDisabled[] = {1,1,1,0.25};
	periodFocus = 1.2;
	periodOver = 0.8;
	class HitZone
	{
		left = 0.004;
		top = 0.029;
		right = 0.004;
		bottom = 0.029;
	};
	class ShortcutPos
	{
		left = 0.0145;
		top = 0.026;
		w = 0.0392157;
		h = 0.0522876;
	};
	class TextPos
	{
		left = 0.05;
		top = 0.034;
		right = 0.005;
		bottom = 0.005;
	};
	animTextureNormal = "\ca\ui\data\ui_button_normal_ca.paa";
	animTextureDisabled = "\ca\ui\data\ui_button_disabled_ca.paa";
	animTextureOver = "\ca\ui\data\ui_button_over_ca.paa";
	animTextureFocused = "\ca\ui\data\ui_button_focus_ca.paa";
	animTexturePressed = "\ca\ui\data\ui_button_down_ca.paa";
	animTextureDefault = "\ca\ui\data\ui_button_default_ca.paa";
	period = 0.4;
	font = "Zeppelin32";
	size = 0.03921;
	sizeEx = 0.03921;
	text = "";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
	soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
	soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
	soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
	action = "";
	class Attributes
	{
		font = "Zeppelin32";
		color = "#E5E5E5";
		align = "left";
		shadow = "true";
	};
	class AttributesImage
	{
		font = "Zeppelin32";
		color = "#E5E5E5";
		align = "left";
	};
	textureNoShortcut = "#(argb,8,8,3)color(0,0,0,0)";
};
class ACE_EASA_RscShortcutButtonMain: ACE_EASA_RscShortcutButton
{
	type = 16;
	idc = -1;
	style = 0;
	default = 0;
	w = 0.313726;
	h = 0.104575;
	color[] = {0.543,0.5742,0.4102,1};
	colorDisabled[] = {1,1,1,0.25};
	class HitZone
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	};
	class ShortcutPos
	{
		left = 0.0204;
		top = 0.026;
		w = 0.0392157;
		h = 0.0522876;
	};
	class TextPos
	{
		left = 0.08;
		top = 0.034;
		right = 0.005;
		bottom = 0.005;
	};
	animTextureNormal = "\ca\ui\data\ui_button_main_normal_ca.paa";
	animTextureDisabled = "\ca\ui\data\ui_button_main_disabled_ca.paa";
	animTextureOver = "\ca\ui\data\ui_button_main_over_ca.paa";
	animTextureFocused = "\ca\ui\data\ui_button_main_focus_ca.paa";
	animTexturePressed = "\ca\ui\data\ui_button_main_down_ca.paa";
	animTextureDefault = "\ca\ui\data\ui_button_main_normal_ca.paa";
	period = 0.5;
	font = "Zeppelin32";
	size = 0.03921;
	sizeEx = 0.03921;
	text = "";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
	soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
	soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
	soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
	action = "";
	class Attributes
	{
		font = "Zeppelin32";
		color = "#E5E5E5";
		align = "left";
		shadow = "false";
	};
	class AttributesImage
	{
		font = "Zeppelin32";
		color = "#E5E5E5";
		align = "false";
	};
};
class ACE_EASA_RscEdit
{
	type = 2;
	idc = -1;
	style = "0x00";
	font = "TahomaB";
	sizeEx = 0.02;
	colorText[] = {0,0,0,1};
	colorSelection[] = {0.5,0.5,0.5,1};
	autocomplete = "false";
	text = "";
};
class ACE_EASA_RscLB_C
{
	style = "0x00";
	idc = -1;
	colorSelect[] = {0.4,0.4,0.4,1};
	colorSelectBackground[] = {0.2,0.2,0.2,1};
	colorText[] = {0.2,0.2,0.2,1};
	colorBackground[] = {0.4,0.4,0.4,1};
	font = "TahomaB";
	sizeEx = 0.025;
	rowHeight = 0.04;
};
class ACE_EASA_RscListBox: ACE_EASA_RscLB_C
{
	soundSelect[] = {"",0.1,1};
	type = 5;
};
class ACE_EASA_RscCombo: ACE_EASA_RscLB_C
{
	sizeEx = 0.02;
	type = 4;
	wholeHeight = 0.3;
	soundSelect[] = {"",0.15,1};
	soundExpand[] = {"",0.15,1};
	soundCollapse[] = {"",0.15,1};
	maxHistoryDelay = 1;
	arrowEmpty = "\ca\ui\data\ui_arrow_combo_ca.paa";
	arrowFull = "\ca\ui\data\ui_arrow_combo_active_ca.paa";
	class ScrollBar
	{
		color[] = {1,1,1,0.6};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
		arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
		arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
		border = "\ca\ui\data\ui_border_scroll_ca.paa";
	};
	color[] = {0,0,0,0.6};
	colorActive[] = {0,0,0,1};
	colorDisabled[] = {0,0,0,0.3};
	colorSelectBackground[] = {0.543,0.5742,0.4102,1};
};
class ACE_EASA_RscSliderH
{
	access = 0;
	type = 3;
	idc = -1;
	sizeEx = 0.025;
	style = 1024;
	color[] = {0.2,0.2,0.2,1};
	colorActive[] = {1,1,1,1};
};
class ACE_EASA_RscSliderV
{
	access = 0;
	type = 3;
	idc = -1;
	sizeEx = 0.025;
	style = 0;
	color[] = {0.2,0.2,0.2,1};
	colorActive[] = {1,1,1,1};
};
class ACE_UIList
{
	w = 0.275;
	h = 0.04;
	colorSelect[] = {0.023529,0,0.0313725,1};
	colorText[] = {0.023529,0,0.0313725,1};
	colorBackground[] = {0.95,0.95,0.95,1};
	colorSelectBackground[] = {0.543,0.5742,0.4102,1};
	colorScrollbar[] = {0.023529,0,0.0313725,1};
	arrowEmpty = "\ca\ui\data\ui_arrow_combo_ca.paa";
	arrowFull = "\ca\ui\data\ui_arrow_combo_active_ca.paa";
	wholeHeight = 0.45;
	color[] = {0,0,0,0.6};
	colorActive[] = {0,0,0,1};
	colorDisabled[] = {0,0,0,0.3};
	font = "Zeppelin32";
	sizeEx = 0.029;
	soundSelect[] = {"",0.1,1};
	soundExpand[] = {"",0.1,1};
	soundCollapse[] = {"",0.1,1};
	maxHistoryDelay = 1;
	class ScrollBar
	{
		color[] = {1,1,1,0.6};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
		arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
		arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
		border = "\ca\ui\data\ui_border_scroll_ca.paa";
	};
};
class ACE_UIComboBox: ACE_UIList
{
	type = 4;
	style = 0;
	idc = -1;
	sizeEx = 0.025;
	wholeHeight = 0.3;
};
class ACE_EASA_RscText2
{
	type = 0;
	idc = -1;
	style = "0x00";
	x = 0.0;
	y = 0.0;
	w = 0.3;
	h = 0.03;
	sizeEx = 0.023;
	colorBackground[] = {0.5,0.5,0.5,0.75};
	colorText[] = {0,0,0,1};
	font = "Zeppelin32";
	text = "";
};
class ACE_Aircraft_Loadout
{
	name = "ACE_Aircraft_Loadout";
	idd = -1;
	movingEnable = 0;
	controlsBackground[] = {"BG"};
	objects[] = {};
	controls[] = {"PylonsFrame","CannonFrame","CannonList","TypeFrame","TypeName","Title","Apply_B","Quit_B","p0","p1","p2","p4","p5","p6","p7","p8","p9","p10","p11","p12","p13","p14","p15","p16","p17","p18","p3","p19","p20","p21","p22","p23","Default_B","TypePic"};
	onload = "_this call ace_sys_easa_fnc_onload";
	class BG: ACE_EASA_RscText
	{
		idc = -1;
		type = 0;
		style = 48;
		x = "SafeZoneX";
		y = "SafeZoneY";
		w = "SafeZoneW + 0.02";
		h = "SafeZoneH";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "\x\ace\addons\sys_easa\data\easa_background_ca.paa";
		font = "Zeppelin32";
		sizeEx = 0.032;
	};
	class Title: ACE_EASA_RscText2
	{
		x = "SafeZoneX + 0.13";
		y = "SafeZoneY + 0.05";
		w = 0.4;
		h = 0.1;
		sizeEx = 0.035;
		colorBackground[] = {1,1,1,0.0};
		colorText[] = {0.643,0.5742,0.4102,1.0};
		text = "$STR_ACE_EASA_NAME";
	};
	class PylonsFrame: Title
	{
		x = 0.7;
		y = "0.15625 - (2*0.03125)";
		w = 0.3;
		h = "(21*0.03125)";
		text = "$STR_ACE_EASA_DIA_PYLONS";
	};
	class CannonFrame: PylonsFrame
	{
		idc = 20;
		x = 0.595;
		y = "0.15625 + (19*0.03125)";
		h = "(3*0.03125)";
		text = "Cannon Name";
	};
	class CannonList: ACE_UIComboBox
	{
		idc = 21;
		x = 0.6;
		y = "0.15625 + (21.5*0.03125)";
		w = 0.2;
		h = 0.03125;
	};
	class TypeFrame: PylonsFrame
	{
		x = "0.6 + 0.2 + 0.05";
		w = "(2 * 0.2)";
		h = "(5 * 0.03125)";
		sizeEx = 0.028;
		text = "";
	};
	class TypeName: ACE_EASA_RscText
	{
		idc = 22;
		style = "0x02";
		x = "0.6 + 0.2 + 0.05";
		y = "0.15625 + (0.03125/2)";
		w = "(2 * 0.2)";
		h = "2 *(0.03125)";
		sizeEx = 0.05;
		colorText[] = {1,0,0,1};
		text = "Name";
	};
	class TypePic: ACE_EASA_RscPicture
	{
		idc = 537;
		style = "48+ 0x02";
		x = "0.6 + 0.2 + 0.17";
		y = "0.15625 + (0.03125/2) + 0.1";
		w = 0.2;
		h = 0.2;
		sizeEx = 0.05;
		colorText[] = {0.643,0.5742,0.4102,1.0};
		text = "";
	};
	class Apply_B: ACE_EASA_RscShortcutButtonMain
	{
		idc = -1;
		x = "SafeZoneX + (SafeZoneW - 0.4)";
		y = "SafeZoneY + (SafeZoneH - 0.15)";
		text = "$STR_ACE_EASA_DIA_SELECTED";
		action = "[ace_sys_easa_air] call ace_sys_easa_fnc_apply_loadout";
	};
	class Default_B: ACE_EASA_RscShortcutButtonMain
	{
		idc = -1;
		x = "SafeZoneX + (SafeZoneW - 0.75)";
		y = "SafeZoneY + (SafeZoneH - 0.15)";
		text = "$STR_ACE_EASA_DIA_DEFAULT";
		action = "[ace_sys_easa_air] call ace_sys_easa_fnc_default_loadout";
	};
	class Quit_B: ACE_EASA_RscShortcutButtonMain
	{
		idc = -1;
		x = "SafeZoneX + 0.1";
		y = "SafeZoneY + (SafeZoneH - 0.15)";
		text = "$STR_ACE_EASA_DIA_CANCEL";
		action = "closeDialog 0";
	};
	class p0: ACE_UIComboBox
	{
		idc = 100;
		x = 0.6;
		y = 0.40625;
		w = 0.1;
		h = 0.03125;
	};
	class p1: p0
	{
		idc = 101;
		y = 0.46875;
	};
	class p2: p0
	{
		idc = 102;
		y = 0.375;
	};
	class p3: p0
	{
		idc = 103;
		y = 0.5;
	};
	class p4: ACE_UIComboBox
	{
		idc = 104;
		x = 0.7;
		y = 0.40625;
		w = 0.1;
		h = 0.03125;
	};
	class p5: p4
	{
		idc = 105;
		y = 0.46875;
	};
	class p6: p4
	{
		idc = 106;
		y = 0.375;
	};
	class p7: p4
	{
		idc = 107;
		y = 0.5;
	};
	class p8: ACE_UIComboBox
	{
		idc = 108;
		x = 0.6;
		y = 0.28125;
		w = 0.1;
		h = 0.03125;
	};
	class p9: p8
	{
		idc = 109;
		y = 0.59375;
	};
	class p10: p8
	{
		idc = 110;
		y = 0.25;
	};
	class p11: p8
	{
		idc = 111;
		y = 0.625;
	};
	class p12: ACE_UIComboBox
	{
		idc = 112;
		x = 0.7;
		y = 0.28125;
		w = 0.1;
		h = 0.03125;
	};
	class p13: p12
	{
		idc = 113;
		y = 0.59375;
	};
	class p14: p12
	{
		idc = 114;
		y = 0.25;
	};
	class p15: p12
	{
		idc = 115;
		y = 0.625;
	};
	class p16: ACE_UIComboBox
	{
		idc = 116;
		x = 0.6;
		y = 0.1875;
		w = 0.1;
		h = 0.03125;
	};
	class p17: p16
	{
		idc = 117;
		y = 0.6875;
	};
	class p18: p16
	{
		idc = 118;
		y = 0.15625;
	};
	class p19: p16
	{
		idc = 119;
		y = 0.71875;
	};
	class p20: ACE_UIComboBox
	{
		idc = 120;
		x = 0.7;
		y = 0.1875;
		w = 0.1;
		h = 0.03125;
	};
	class p21: p20
	{
		idc = 121;
		y = 0.6875;
	};
	class p22: p20
	{
		idc = 122;
		y = 0.15625;
	};
	class p23: p20
	{
		idc = 123;
		y = 0.71875;
	};
};
//};
