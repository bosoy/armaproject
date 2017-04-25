////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:07:13 2013 : Created on Mon Oct 14 23:07:13 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_dogtag : config.bin{
class CfgPatches
{
	class ace_sys_dogtag
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_weapon","ace_sys_interaction"};
		version = "1.14.0.597";
		author[] = {"Rocko","Xeno"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_dogtag
		{
			list[] = {"ace_sys_dogtag"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_dogtag
	{
		init = "call ('\x\ace\addons\sys_dogtag\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_dogtag\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Respawn_EventHandlers
{
	class CAManBase
	{
		class ace_sys_dogtag
		{
			respawn = "_this spawn ace_sys_dogtag_fnc_respawn";
		};
	};
};
class Extended_InitPost_EventHandlers
{
	class CAManBase
	{
		class ace_sys_dogtag
		{
			init = "_this call ace_sys_dogtag_fnc_unitInit";
		};
	};
};
class RscTitles
{
	class ACE_DogTag
	{
		idd = 666100;
		movingEnable = 1;
		duration = 5;
		fadein = 1;
		fadeout = 1;
		name = "ACE_DogTag";
		onLoad = "with uiNameSpace do {ACE_DogTag = _this select 0}";
		onUnload = "";
		class controls
		{
			class ACE_DogTag_BG
			{
				idc = -1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.9,0.9,0.9,1};
				font = "Bitstream";
				sizeEx = 0.023;
				x = 0.75;
				y = 0.35;
				w = 0.25;
				h = 0.15;
				text = "\x\ace\addons\sys_dogtag\data\dt.paa";
			};
			class ACE_DogTag_Name
			{
				idc = 666;
				type = 0;
				colorText[] = {0,0,0,0.8};
				font = "Bitstream";
				colorBackground[] = {255,255,255,0};
				text = "";
				style = 128;
				sizeEx = 0.02;
				x = 0.805;
				y = 0.31;
				w = 0.2;
				h = 0.15;
			};
			class ACE_DogTag_Blood: ACE_DogTag_Name
			{
				idc = 667;
				text = "";
				y = 0.33;
			};
			class ACE_DogTag_Branch: ACE_DogTag_Name
			{
				idc = 668;
				text = "";
				y = 0.35;
			};
			class ACE_DogTag_Religion: ACE_DogTag_Name
			{
				idc = 669;
				text = "";
				y = 0.37;
			};
		};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class ACE_DogTag: CA_Magazine
	{
		scope = 2;
		ACE_Weight = 0.09;
		model = "\x\ace\addons\sys_dogtag\dogtag.p3d";
		displayName = "$STR_ACE_DOG";
		picture = "\x\ace\addons\sys_dogtag\data\m_dogtag_ca.paa";
		count = 1;
		type = 16;
		class Library
		{
			libTextDesc = "$STR_ACE_DOGD";
		};
		class Armory
		{
			disabled = 1;
		};
	};
};
class CfgWeapons
{
	class Default;
	class Put: Default
	{
		class ACE_Dummy_Utility;
		class ace_sys_dogtag: ACE_Dummy_Utility
		{
			magazines[] = {"ACE_DogTag"};
		};
	};
};
class ACE_SD_RscText
{
	type = 0;
	idc = -1;
	style = 0;
	x = 0.0;
	y = 0.0;
	w = 0.3;
	h = 0.03;
	sizeEx = 0.023;
	colorBackground[] = {0.5,0.5,0.5,0.75};
	colorText[] = {0,0,0,1};
	font = "Zeppelin32";
	text = "";
	shadow = 2;
};
class ACE_SD_RscText2
{
	access = 0;
	type = 0;
	idc = -1;
	colorBackground[] = {0,0,0,0};
	colorText[] = {0.8784,0.8471,0.651,1};
	text = "";
	fixedWidth = 0;
	x = 0;
	y = 0;
	h = 0.037;
	w = 0.3;
	style = 0;
	shadow = 2;
	font = "Zeppelin32";
	SizeEx = 0.03921;
};
class ACE_SD_RscPicture
{
	type = 0;
	idc = -1;
	style = 48;
	x = 0.1;
	y = 0.1;
	w = 0.4;
	h = 0.2;
	sizeEx = "(((100/36)/100)*0.9)";
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = "Zeppelin32";
	text = "";
};
class ACE_ButtonBase
{
	type = 16;
	x = 0;
	y = 0;
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
	shortcuts[] = {};
	textureNoShortcut = "#(argb,8,8,3)color(0,0,0,0)";
	color[] = {0.8784,0.8471,0.651,1};
	color2[] = {0.95,0.95,0.95,1};
	colorDisabled[] = {1,1,1,0.25};
	colorBackground[] = {1,1,1,1};
	colorBackground2[] = {1,1,1,0.4};
	class Attributes
	{
		font = "Zeppelin32";
		color = "#E5E5E5";
		align = "left";
		shadow = "true";
	};
	idc = -1;
	style = 0;
	default = 0;
	shadow = 2;
	w = 0.23;
	h = 0.104575;
	periodFocus = 1.2;
	periodOver = 0.8;
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
	soundEnter[] = {"\ca\ui\data\sound\onover",0.09,1};
	soundPush[] = {"\ca\ui\data\sound\new1",0,0};
	soundClick[] = {"\ca\ui\data\sound\onclick",0.07,1};
	soundEscape[] = {"\ca\ui\data\sound\onescape",0.09,1};
	action = "";
	class AttributesImage
	{
		font = "Zeppelin32";
		color = "#E5E5E5";
		align = "left";
	};
};
class ACE_ITEMSUIList
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
class ACE_ITEMSUIComboBox: ACE_ITEMSUIList
{
	type = 5;
	style = 0;
	idc = -1;
	sizeEx = 0.025;
	wholeHeight = 0.3;
	shadow = 2;
};
class ACE_Items_RscShortcutButton
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
class ACE_Items_RscShortcutButtonMain: ACE_Items_RscShortcutButton
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
class ACE_ItemsDialog
{
	idd = -1;
	movingEnable = 1;
	onLoad = "uiNamespace setVariable ['ACE_ItemsDialog', _this select 0];call ace_sys_dogtag_fnc_fill_itemsdialog";
	onUnLoad = "uiNamespace setVariable ['ACE_ItemsDialog', displayNull]";
	objects[] = {};
	class controlsBackground
	{
		class BackGround: ACE_SD_RscPicture
		{
			x = 0;
			y = 0.135;
			w = 1.2549;
			h = 0.753;
			colorBackground[] = {0,0,0,0};
			text = "\ca\ui\data\ui_background_controls_ca.paa";
		};
	};
	class controls
	{
		class ItemsCB: ACE_ITEMSUIComboBox
		{
			idc = 100;
			text = "";
			x = 0.03;
			w = 0.43;
			y = 0.295;
			h = 0.44;
			colorSelect[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			colorBackground[] = {0.8,0.8,0.8,1};
			colorSelectBackground[] = {0,0,0,1};
			colorScrollbar[] = {0.2,0.2,0.2,1};
			arrowEmpty = "\ca\ui\data\ui_arrow_combo_ca.paa";
			arrowFull = "\ca\ui\data\ui_arrow_combo_active_ca.paa";
			wholeHeight = 0.45;
			rowHeight = 0.05;
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
			onLBSelChanged = "_this call ace_sys_dogtag_fnc_lbselchanged";
		};
		class CloseButton: ACE_ButtonBase
		{
			idc = -1;
			text = "Close";
			action = "closeDialog 0";
			default = "true";
			x = 0.7;
			y = 0.78;
		};
		class MainCaption: ACE_SD_RscText
		{
			x = 0.04;
			y = 0.13;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1,1,1,0};
			colorText[] = {0.643,0.5742,0.4102,1};
			text = "ACE ADDITIONAL ITEMS";
		};
		class CBCaption: ACE_SD_RscText
		{
			x = 0.04;
			y = 0.24;
			w = 0.2;
			h = 0.03;
			sizeEx = 0.039;
			colorBackground[] = {1,1,1,0};
			colorText[] = {1,1,1,1};
			text = "Select Item:";
		};
		class ACE_Logo: ACE_SD_RscPicture
		{
			x = 0.87;
			y = 0.138;
			w = 0.1;
			h = 0.1;
			colorBackground[] = {0,0,0,0};
			text = "\x\ace\addons\sys_dogtag\data\logo_ACE2_ca.paa";
		};
		class ItemCaption: ACE_SD_RscText
		{
			x = 0.49;
			y = 0.24;
			w = 0.1;
			h = 0.03;
			sizeEx = 0.039;
			colorBackground[] = {1,1,1,0};
			colorText[] = {1,1,1,1};
			text = "Selected:";
		};
		class ItemCaptionText: ItemCaption
		{
			idc = 101;
			x = 0.6;
			w = 0.35;
			text = "";
		};
		class ItemPic: ACE_SD_RscPicture
		{
			idc = 102;
			x = 0.49;
			y = 0.295;
			w = 0.25;
			h = 0.25;
			colorBackground[] = {0,0,0,0};
			text = "\x\ace\addons\sys_dogtag\data\logo_ACE2_ca.paa";
		};
		class ItemCaption1: ACE_SD_RscText2
		{
			idc = 110;
			x = 0.49;
			y = 0.53;
			w = 0.1;
			h = 0.023;
			sizeEx = 0.027;
			text = "";
		};
		class ItemText1: ACE_SD_RscText2
		{
			idc = 111;
			x = 0.6;
			y = 0.53;
			w = 0.35;
			h = 0.023;
			sizeEx = 0.027;
			text = "";
		};
		class ItemCaption2: ItemCaption1
		{
			idc = 112;
			y = 0.57;
		};
		class ItemText2: ItemText1
		{
			idc = 113;
			y = 0.57;
			text = "";
		};
		class ItemCaption3: ItemCaption1
		{
			idc = 114;
			y = 0.61;
		};
		class ItemText3: ItemText1
		{
			idc = 115;
			y = 0.61;
			text = "";
		};
		class LayDownbutton: ACE_Items_RscShortcutButtonMain
		{
			idc = 10;
			x = 0.7;
			w = 0.248;
			y = 0.67;
			h = 0.07;
			size = 0.027;
			sizeEx = 0.027;
			shadow = 2;
			text = "Put to ground";
		};
	};
};
//};
