////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:06:58 2013 : Created on Mon Oct 14 23:06:58 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_cargo : config.bin{
class CfgPatches
{
	class ace_sys_cargo
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ace_main","ace_c_vehicle","ace_c_weapon","ace_sys_interaction"};
		version = "1.14.0.597";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_cargo
		{
			list[] = {"ace_sys_cargo"};
		};
	};
};
class CfgVehicles
{
	class USOrdnanceBox_EP1;
	class ACE_CARGO_DUMMY_BOX: USOrdnanceBox_EP1
	{
		displayName = "";
		displayNameShort = "";
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class All;
	class Land;
	class Man: Land
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class LandVehicle: Land
	{
		ACE_canBeLoad = 1;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Tank: LandVehicle
	{
		ACE_canBeLoad = 1;
		ACE_canBeCargo = 0;
		ACE_canGear = 1;
		ACE_canLoadFront = 0;
	};
	class M113_Base: Tank
	{
		ACE_canBeLoad = 1;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class M2A2_Base: Tank
	{
		ACE_canBeLoad = 1;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class BAF_FV510_D: Tank
	{
		ACE_canBeLoad = 1;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Tracked_APC: Tank
	{
		ACE_canBeLoad = 1;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Car: LandVehicle
	{
		ACE_canBeLoad = 1;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
		class Turrets
		{
			class MainTurret;
		};
	};
	class BIS_alice_emptydoor: Car
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Wheeled_APC: Car
	{
		ACE_canBeLoad = 1;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Motorcycle: Landvehicle
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 1;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class StaticWeapon: LandVehicle
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 1;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class StaticCanon: StaticWeapon
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Air;
	class Helicopter: Air
	{
		ACE_canBeLoad = 1;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class ParachuteBase: Helicopter
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Plane: Air
	{
		ACE_canBeLoad = 1;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Ship;
	class SmallShip: Ship
	{
		ACE_canBeLoad = 1;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class BigShip: Ship
	{
		ACE_canBeLoad = 1;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Boat: Ship{};
	class RubberBoat: Boat{};
	class Zodiac: RubberBoat
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 1;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
		ACE_Weight = 260;
	};
	class PBX: RubberBoat
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 1;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
		ACE_Weight = 260;
	};
	class Static;
	class Building: Static
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Strategic;
	class ReammoBox: Strategic
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 1;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Library_WeaponHolder: Strategic
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class WeaponHolder: ReammoBox
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class NonStrategic;
	class Gunracktrue: NonStrategic
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 1;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Grave: NonStrategic
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Body: Grave
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 1;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
		ACE_Weight = 79.9;
	};
	class Thing: All
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Wreck: Thing
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class ACE_Object: Thing
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class RoadCone: Thing
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 1;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
		ACE_Weight = 1;
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_cargo
	{
		init = "call ('\x\ace\addons\sys_cargo\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_cargo
	{
		clientInit = "call ('\x\ace\addons\sys_cargo\XEH_postInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Killed_EventHandlers
{
	class AllVehicles
	{
		class ace_sys_cargo
		{
			killed = "_this call ace_sys_cargo_fnc_clearCargo";
		};
	};
};
class ACE_CARGO_RscBgFrame
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
class ACE_CARGO_RscBackground
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
class ACE_CARGO_RscPicture
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
class ACE_CARGO_RscButton
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
	default = 0;
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
class ACE_CARGO_RscButton2: ACE_CARGO_RscButton
{
	x = -1.0;
	y = -1.0;
	idc = -1;
	w = 0.01;
	h = 0.01;
	default = 1;
};
class ACE_CARGO_RscShortcutButton
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
class ACE_CARGO_RscShortcutButtonMain: ACE_CARGO_RscShortcutButton
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
class ACE_CARGO_RscEdit
{
	type = 2;
	idc = -1;
	style = "0x00";
	font = "TahomaB";
	sizeEx = 0.02;
	colorText[] = {0,0,0,1};
	colorSelection[] = {0.5,0.5,0.5,1};
	autocomplete = 0;
	text = "";
};
class ACE_CARGO_RscLB_C
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
class ACE_CARGO_RscListBox: ACE_CARGO_RscLB_C
{
	soundSelect[] = {"",0.1,1};
	type = 5;
};
class ACE_CARGO_RscCombo: ACE_CARGO_RscLB_C
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
class ACE_CARGO_RscSliderH
{
	access = 0;
	type = 3;
	idc = -1;
	sizeEx = 0.025;
	style = 1024;
	color[] = {0.2,0.2,0.2,1};
	colorActive[] = {1,1,1,1};
};
class ACE_CARGO_RscSliderV
{
	access = 0;
	type = 3;
	idc = -1;
	sizeEx = 0.025;
	style = 0;
	color[] = {0.2,0.2,0.2,1};
	colorActive[] = {1,1,1,1};
};
class ACE_CARGOUIList
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
class ACE_CARGOUIComboBox: ACE_CARGOUIList
{
	type = 5;
	style = 0;
	idc = -1;
	sizeEx = 0.025;
	wholeHeight = 0.3;
};
class ACE_CARGO_RscText
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
class ACE_Cargo_List
{
	name = "ACE_Cargo_List";
	idd = -1;
	movingEnable = 0;
	objects[] = {};
	onLoad = "uiNamespace setVariable ['ACE_Cargo_List', _this select 0];['back'] call ace_sys_cargo_fnc_onload";
	onUnload = "[ace_sys_cargo_vehicle,objnull,0,0] call ace_sys_cargo_fnc_cbusy;";
	class controlsBackground
	{
		class BG: ACE_CARGO_RscText
		{
			idc = -1;
			type = 0;
			style = 48;
			x = "0.270792 * safezoneW + safezoneX";
			y = "0.224911 * safezoneH + safezoneY";
			w = "0.455752 * safezoneW";
			h = "0.547272 * safezoneH";
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			text = "\ca\ui\data\ui_gameoptions_background_ca.paa";
			font = "Zeppelin32";
			sizeEx = 0.032;
		};
	};
	class controls
	{
		class Title: ACE_CARGO_RscText
		{
			idc = 30;
			x = "0.289755 * safezoneW + safezoneX";
			y = "0.231139 * safezoneH + safezoneY";
			w = "0.0458417 * safezoneW";
			h = "0.0550178 * safezoneH";
			sizeEx = 0.05;
			colorBackground[] = {1,1,1,0.0};
			colorText[] = {0.643,0.5742,0.4102,1.0};
			text = "";
		};
		class Content: ACE_CARGOUIComboBox
		{
			idc = 99;
			text = "";
			x = "0.277061 * safezoneW + safezoneX";
			y = "0.283526 * safezoneH + safezoneY";
			w = "0.416083 * safezoneW";
			h = "0.322891 * safezoneH";
			colorSelect[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			colorBackground[] = {0.8,0.8,0.8,1};
			colorSelectBackground[] = {0,0,0,1};
			colorScrollbar[] = {0.2,0.2,0.2,1};
			arrowEmpty = "\ca\ui\data\ui_arrow_combo_ca.paa";
			arrowFull = "\ca\ui\data\ui_arrow_combo_active_ca.paa";
			wholeHeight = 0.45;
			rowHeight = 0.06;
			color[] = {0.8,0.8,0.8,1};
			colorActive[] = {0,0,0,1};
			colorDisabled[] = {0,0,0,0.3};
			font = "Zeppelin32";
			sizeEx = 0.035;
			soundSelect[] = {"",0.1,1};
			soundExpand[] = {"",0.1,1};
			soundCollapse[] = {"",0.1,1};
			maxHistoryDelay = 1;
			autoScrollSpeed = -1;
			autoScrollDelay = 5;
			autoScrollRewind = 0;
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
			onLBSelChanged = "[_this,'back'] call ace_sys_cargo_fnc_lbselchanged";
		};
		class Apply_B: ACE_CARGO_RscShortcutButtonMain
		{
			idc = 10;
			x = "0.451603 * safezoneW + safezoneX";
			y = "0.618615 * safezoneH + safezoneY";
			w = "0.103494 * safezoneW";
			h = "0.0451332 * safezoneH";
			size = 0.02;
			sizeEx = 0.02;
			text = "$STR_DIAG_ACE_CARGO_UNLOAD";
			action = "[ace_sys_cargo_vehicle,'back'] call ace_sys_cargo_fnc_unload";
		};
		class Quit_B: Apply_B
		{
			idc = 20;
			x = "0.566379 * safezoneW + safezoneX";
			text = "$STR_DIAG_ACE_CARGO_CANCEL";
			action = "closeDialog 0;";
		};
	};
};
class ACE_CargoFront_List: ACE_Cargo_List
{
	name = "ACE_CargoFront_List";
	onLoad = "uiNamespace setVariable ['ACE_CargoFront_List', _this select 0];['front'] call ace_sys_cargo_fnc_onload";
	class controls: controls
	{
		class Title: Title{};
		class Content: Content
		{
			onLBSelChanged = "[_this,'front'] call ace_sys_cargo_fnc_lbselchanged";
		};
		class Apply_B: Apply_B
		{
			action = "[ace_sys_cargo_vehicle,'front'] call ace_sys_cargo_fnc_unload";
		};
		class Quit_B: Quit_B{};
	};
};
class CfgFunctions
{
	class ACE
	{
		class Cargo
		{
			class canLoadCargo
			{
				description = "Checks if vehicle is able to load cargo";
				file = "\x\ace\Addons\sys_cargo\fnc_canLoadCargo.sqf";
			};
			class listCargo
			{
				description = "Lists cargo of a vehicle.";
				file = "\x\ace\Addons\sys_cargo\fnc_listCargo.sqf";
			};
			class loadCargo
			{
				description = "Load cargo into vehicles.";
				file = "\x\ace\Addons\sys_cargo\fnc_loadCargo.sqf";
			};
			class unloadCargo
			{
				description = "Unloads cargo from a vehicle.";
				file = "\x\ace\Addons\sys_cargo\fnc_unloadCargo.sqf";
			};
		};
	};
};
//};
