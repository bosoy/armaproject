////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:06:06 2013 : Created on Mon Oct 14 23:06:06 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_settings : config.bin{
class CfgPatches
{
	class ace_settings
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ace_main"};
		version = "1.14.0.597";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_settings
	{
		clientInit = "call ('\x\ace\addons\settings\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
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
	Size = 0.03921;
};
class ACE_RscEdit
{
	access = 0;
	type = 2;
	x = 0;
	y = 0;
	h = 0.04;
	w = 0.2;
	colorBackground[] = {0,0,0,1};
	colorText[] = {0.95,0.95,0.95,1};
	colorSelection[] = {0.8784,0.8471,0.651,1};
	autocomplete = "";
	text = "";
	size = 0.2;
	style = "0x00 + 0x40";
	font = "Zeppelin32";
	shadow = 2;
	sizeEx = 0.03921;
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
class ACE_Button
{
	type = 1;
	text = "";
	colorText[] = {0,0,0,1};
	colorDisabled[] = {0.4,0.4,0.4,1};
	colorBackground[] = {0.95,0.95,0.95,1};
	colorBackgroundDisabled[] = {0.95,0.95,0.95,1};
	colorBackgroundActive[] = {0.95,0.95,0.95,1};
	colorFocused[] = {0.95,0.95,0.95,1};
	colorShadow[] = {0.023529,0,0.0313725,1};
	colorBorder[] = {0.023529,0,0.0313725,1};
	soundEnter[] = {"\ca\ui\data\sound\onover",0.09,1};
	soundPush[] = {"\ca\ui\data\sound\new1",0,0};
	soundClick[] = {"\ca\ui\data\sound\onclick",0.07,1};
	soundEscape[] = {"\ca\ui\data\sound\onescape",0.09,1};
	style = 2;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	shadow = 2;
	font = "Zeppelin32";
	sizeEx = 0.03921;
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	borderSize = 0;
};
class ACE_LinkButtonBase
{
	idc = -1;
	type = 1;
	style = 0;
	default = "false";
	font = "Zeppelin32";
	sizeEx = 0.023;
	colorText[] = {1,1,1,1};
	colorFocused[] = {1,1,1,0};
	colorDisabled[] = {0,0,1,0.7};
	colorBackground[] = {1,1,1,0};
	colorBackgroundDisabled[] = {1,1,1,0.5};
	colorBackgroundActive[] = {1,1,1,0};
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	colorShadow[] = {1,1,1,0};
	colorBorder[] = {1,1,1,0.5};
	borderSize = 0;
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
	soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
	soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
	soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
	x = 0.06;
	y = 0.11;
	w = 0.15;
	h = 0.1;
	text = "";
	action = "";
	shadow = 2;
};
class ACE_SD_RscActiveText: ACE_SD_RscText
{
	type = 11;
	action = "";
	blinkingPeriod = 0;
	color[] = {0,0,0,1};
	colorActive[] = {1,0.2,0.2,1};
	text = "";
	soundEnter[] = {"",0,1};
	soundPush[] = {"",0,1};
	soundClick[] = {"",0,1};
	soundEscape[] = {"",0,1};
};
class ACE_SliderH
{
	idc = -1;
	type = 43;
	style = "0x400 + 0x10";
	x = 0;
	y = 0;
	h = 0.029412;
	w = 0.4;
	default = "false";
	color[] = {1,1,1,0.4};
	colorActive[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.2};
	arrowEmpty = "\ca\ui\data\ui_arrow_left_ca.paa";
	arrowFull = "\ca\ui\data\ui_arrow_left_active_ca.paa";
	border = "\ca\ui\data\ui_border_frame_ca.paa";
	thumb = "\ca\ui\data\ui_slider_bar_ca.paa";
};
class ACE_SD_RscControlsGroup
{
	class VScrollbar
	{
		color[] = {1,1,1,1};
		width = 0.021;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = 0;
		shadow = 0;
	};
	class HScrollbar
	{
		color[] = {1,1,1,1};
		height = 0.028;
		shadow = 0;
	};
	class ScrollBar
	{
		color[] = {1,1,1,0.6};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		shadow = 0;
		thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
		arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
		arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
		border = "\ca\ui\data\ui_border_scroll_ca.paa";
	};
	class Controls{};
	type = 15;
	idc = -1;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	shadow = 0;
	style = 16;
};
class ACE_SD_UIList
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
	default = "false";
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
class ACE_SD_UIComboBox: ACE_SD_UIList
{
	type = 4;
	style = 0;
	idc = -1;
	sizeEx = 0.025;
	wholeHeight = 0.23;
};
class ACE_Editbox
{
	idc = -1;
	type = 2;
	style = 0;
	x = 0;
	y = 0;
	w = 0.03;
	h = 0.37;
	sizeEx = 0.023;
	font = "Zeppelin32";
	text = "";
	autocomplete = "";
	shadow = 2;
	colorBackground[] = {0,0,0,1};
	colorText[] = {0.95,0.95,0.95,1};
	colorSelection[] = {0.8784,0.8471,0.651,1};
};
class ACE_SettingsDialog
{
	idd = -1;
	movingEnable = 1;
	enableSimulation = 1;
	enableDisplay = 1;
	onLoad = "uiNamespace setVariable ['ACE_SETTINGS_DIALOG', _this select 0];if !(uiNamespace getVariable 'ace_main_normal_settingsdialog') then {((_this select 0) displayCtrl 9999) ctrlEnable false}; call (uiNamespace getVariable 'ace_settings_fnc_fillSettingsDialog')";
	onUnLoad = "uiNamespace setVariable ['ace_settings_key_save', nil];uiNamespace setVariable ['ace_settings_key_save_name', nil]";
	objects[] = {};
	class controlsBackground
	{
		class BackGround: ACE_SD_RscPicture
		{
			x = -0.0670888;
			y = "SafezoneY + 0.01 * safezoneW";
			w = 1.33341;
			h = "safezoneH";
			colorBackground[] = {0,0,0,0};
			text = "\x\ace\addons\settings\data\ace_ui_background_ca.paa";
		};
	};
	class controls
	{
		class CaptionText_Header: ACE_SD_RscText
		{
			x = -0.046319;
			y = "SafezoneY + 0.05 * safezoneW";
			w = 0.311144;
			h = 0.0423372;
			sizeEx = 0.035;
			colorBackground[] = {1,1,1,0};
			colorText[] = {0.543,0.5742,0.4102,1};
			text = "$STR_SETTINGS_ACEOPTIONS";
		};
		class CaptionText_Versions: ACE_SD_RscText
		{
			x = -0.0555507;
			y = "SafezoneY + safezoneH - 0.137";
			w = 0.132306;
			h = 0.0279214;
			sizeEx = 0.021;
			colorBackground[] = {1,1,1,0};
			colorText[] = {1,1,1,0.3};
			text = "$STR_SETTINGS_VERSIONS";
		};
		class Text_VersionACE: ACE_SD_RscText
		{
			idc = 10000;
			x = -0.0555507;
			y = "SafezoneY + safezoneH - 0.09556";
			w = 0.139229;
			h = 0.0189117;
			sizeEx = 0.021;
			colorBackground[] = {1,1,1,0};
			colorText[] = {1,1,1,0.3};
			text = "xxx: d.dd.d.ddd";
		};
		class Text_VersionACEX: Text_VersionACE
		{
			idc = 10001;
			x = 0.0744493;
		};
		class Text_VersionCBA: Text_VersionACE
		{
			idc = 10002;
			x = 0.2044493;
		};
		class Text_VersionACEXRU: Text_VersionACE
		{
			idc = 10003;
			y = "SafezoneY + safezoneH - 0.06556";
		};
		class Text_VersionACEXUSNAVY: Text_VersionACEXRU
		{
			idc = 10004;
			x = 0.0744493;
		};
		class ActiveText_SideMenu_Options: ACE_SD_RscActiveText
		{
			idc = 7999;
			text = "$STR_SETTINGS_ACEOPTIONSCLIENT";
			x = -0.06;
			y = "SafezoneY + 0.13 * safezoneW";
			w = 0.15;
			h = 0.032;
			color[] = {0.8784,0.8471,0.651,1};
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {1,0,0,1};
			action = "['options'] call (uiNamespace getVariable 'ace_settings_fnc_showmenu')";
		};
		class ActiveText_SideMenu_Keys: ActiveText_SideMenu_Options
		{
			idc = 8001;
			text = "$STR_SETTINGS_KEYS";
			y = "SafezoneY + 0.1 * safezoneW";
			action = "['keys'] call (uiNamespace getVariable 'ace_settings_fnc_showmenu')";
		};
		class ActiveText_SideMenu_SP_Options: ActiveText_SideMenu_Options
		{
			idc = 8000;
			text = "SP Options";
			y = "SafezoneY + 0.16 * safezoneW";
			action = "['options_sp'] call (uiNamespace getVariable 'ace_settings_fnc_showmenu')";
		};
		class SaveButton: ACE_ButtonBase
		{
			idc = 22123;
			text = "$STR_BUTTONS_SAVE";
			onButtonClick = "call (uiNamespace getVariable 'ace_settings_fnc_saveall');if !(uiNamespace getVariable 'ace_main_normal_settingsdialog') then {(ctrlParent (_this select 0)) closeDisplay 2} else {CloseDialog 0}";
			x = 0.49827;
			y = "SafezoneY + safezoneH - 0.14";
			w = 0.226917;
			h = 0.103604;
		};
		class CancelButton: SaveButton
		{
			idc = 22124;
			text = "$STR_BUTTONS_CANCEL";
			onButtonClick = "if !(uiNamespace getVariable 'ace_main_normal_settingsdialog') then {(ctrlParent (_this select 0)) closeDisplay 2} else {CloseDialog 0}";
			default = "true";
			x = 0.734796;
		};
		class SubCaption_FixHeadbug: ACE_SD_RscText2
		{
			x = -0.0347815;
			y = "SafezoneY + 0.53 * safezoneW";
			w = 0.2;
			h = 0.03;
			sizeEx = 0.027;
			text = "$STR_TITLES_FIXHEADBUG";
		};
		class FixHeadBugButton: ACE_Button
		{
			idc = 9999;
			x = 0.183286;
			y = "SafezoneY + 0.53 * safezoneW";
			w = 0.12;
			h = 0.03;
			text = "$STR_BUTTONS_EXECUTE";
			action = "closedialog 0;0 = [] spawn ACE_fnc_FixHeadbug";
			sizeEx = 0.025;
			shadow = 0;
		};
		class SubCaption_Viewdistance: SubCaption_FixHeadbug
		{
			idc = 33000;
			y = "SafezoneY + 0.56 * safezoneW";
			text = "$STR_TITLES_CHANGEVD";
		};
		class ViewdistanceValue: SubCaption_Viewdistance
		{
			idc = 33001;
			y = "SafezoneY + 0.59 * safezoneW";
			x = 0.179825;
			text = "";
		};
		class ViewdistanceSlider: ACE_SliderH
		{
			idc = 33002;
			x = 0.179825;
			y = "SafezoneY + 0.56 * safezoneW";
			w = 0.129999;
			h = 0.0225155;
			onSliderPosChanged = "_this call (uiNamespace getVariable 'ace_settings_fnc_vdsliderchanged')";
		};
		class ViewdistanceSliderDisabled: SubCaption_FixHeadbug
		{
			idc = 33003;
			x = 0.179825;
			y = "SafezoneY + 0.56 * safezoneW";
			w = 0.13;
			h = 0.027;
			sizeEx = 0.025;
			style = 2;
			colorText[] = {0.8784,0.8471,0.651,0.7};
			text = "$STR_BUTTONS_DISABLED";
		};
		class SubCaption_Terrainggrid: SubCaption_FixHeadbug
		{
			idc = 33010;
			y = "SafezoneY + 0.62 * safezoneW";
			text = "$STR_TITLES_CHANGETG";
		};
		class ChangeTerraingridCombo: ACE_SD_UIComboBox
		{
			idc = 33012;
			x = 0.179825;
			y = "SafezoneY + 0.62 * safezoneW";
			w = 0.129999;
			h = 0.0225155;
			onLBSelChanged = "_this call (uiNamespace getVariable 'ace_settings_fnc_tgselchanged')";
		};
		class ChangeTerraingridComboDisabled: ViewdistanceSliderDisabled
		{
			idc = 33013;
			y = "SafezoneY + 0.62 * safezoneW";
		};
		class ClientsideConfig: ACE_SD_RscControlsGroup
		{
			x = 0.329816;
			y = "SafezoneY + 0.09 * safezoneW";
			w = 0.630743;
			h = "SafezoneH * 0.75";
			idc = 1000;
			class VScrollbar
			{
				color[] = {0.8784,0.8471,0.651,1};
				width = 0.02;
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
			};
			class HScrollbar
			{
				color[] = {0,0,0,0};
				height = 0.001;
			};
			class ScrollBar
			{
				color[] = {1,1,1,0.6};
				colorActive[] = {1,1,1,1};
				colorDisabled[] = {1,1,1,0.3};
				thumb = "\ca\ui\data\ui_border_frame_ca.paa";
				arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
				arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
				border = "\ca\ui\data\ui_border_scroll_ca.paa";
				shadow = 0;
			};
			class Controls
			{
				class EnableBDCText: ACE_SD_RscText2
				{
					x = 0.03;
					y = 0;
					w = 0.28;
					h = 0.023;
					sizeEx = 0.027;
					text = "$STR_TITLES_ENABLERANGEADJUSTMENT";
				};
				class EnableBDCCombo: ACE_SD_UIComboBox
				{
					idc = 1100;
					x = 0.3;
					y = 0;
					w = 0.13;
					h = 0.027;
				};
				class TextWindDeflection: EnableBDCText
				{
					y = 0.05;
					text = "$STR_TITLES_ENABLEWINDDEFLECTION";
				};
				class ComboWindDeflection: EnableBDCCombo
				{
					idc = 1101;
					y = 0.05;
				};
				class TextScanningMethod: EnableBDCText
				{
					y = 0.1;
					text = "$STR_TITLES_SCANNINGMETHOD";
				};
				class ComboScanningMethod: EnableBDCCombo
				{
					idc = 1102;
					y = 0.1;
				};
				class TextComplexUnitInfo: EnableBDCText
				{
					y = 0.15;
					text = "$STR_TITLES_COMPLEXUNITTAGS";
				};
				class ComboComplexUnitInfo: EnableBDCCombo
				{
					idc = 1103;
					y = 0.15;
				};
				class TextUnitInfoForPlayers: EnableBDCText
				{
					y = 0.2;
					text = "$STR_TITLES_UNITINFOFORPLAYERS";
				};
				class ComboUnitInfoForPlayers: EnableBDCCombo
				{
					idc = 1104;
					y = 0.2;
				};
				class TextWeaponSelect: EnableBDCText
				{
					y = 0.25;
					text = "$STR_TITLES_WEAPONSELECTFIREMODE";
				};
				class ComboWeaponSelect: EnableBDCCombo
				{
					idc = 1105;
					y = 0.25;
				};
				class TextStanceIndicator: EnableBDCText
				{
					y = 0.3;
					text = "$STR_TITLES_STANCEINDICATOR";
				};
				class ComboStanceIndicator: EnableBDCCombo
				{
					idc = 1106;
					y = 0.3;
				};
				class TextRoundcount: EnableBDCText
				{
					y = 0.35000002;
					text = "$STR_TITLES_ROUNDCOUNT";
				};
				class ComboRoundcount: EnableBDCCombo
				{
					idc = 1107;
					y = 0.35000002;
				};
				class TextIDismount: EnableBDCText
				{
					y = 0.40000004;
					text = "$STR_TITLES_IMMSERSIVEDISMOUNT";
				};
				class ComboIDismount: EnableBDCCombo
				{
					idc = 1108;
					y = 0.40000004;
				};
				class TextCartridges: EnableBDCText
				{
					y = 0.45000005;
					text = "$STR_TITLES_STAYINGBRASS";
				};
				class ComboCartridges: EnableBDCCombo
				{
					idc = 1109;
					y = 0.45000005;
				};
				class TextGestureBackground: EnableBDCText
				{
					y = 0.50000006;
					text = "$STR_TITLES_ENABLEHANDSIGNALBACKGROUND";
				};
				class ComboGestureBackground: EnableBDCCombo
				{
					idc = 1110;
					y = 0.50000006;
				};
				class TextGestureMethod: EnableBDCText
				{
					y = 0.5500001;
					text = "$STR_TITLES_HANDSIGNALMETHOD";
				};
				class ComboGestureMethod: EnableBDCCombo
				{
					idc = 1111;
					y = 0.5500001;
				};
				class TextGCurType: EnableBDCText
				{
					y = 0.6000001;
					text = "$STR_TITLES_GCURTYPE";
				};
				class ComboGCurType: EnableBDCCombo
				{
					idc = 1112;
					y = 0.6000001;
				};
				class TextGSwitchToWpn: EnableBDCText
				{
					y = 0.6500001;
					text = "$STR_TITLES_GSWITCHTOWPN";
				};
				class ComboGSwitchToWpn: EnableBDCCombo
				{
					idc = 1113;
					y = 0.6500001;
				};
				class TextGResetMode: EnableBDCText
				{
					y = 0.7000001;
					text = "$STR_TITLES_GRESETMODE";
				};
				class ComboGResetMode: EnableBDCCombo
				{
					idc = 1114;
					y = 0.7000001;
				};
				class TextGSwapMB: EnableBDCText
				{
					y = 0.7500001;
					text = "$STR_TITLES_GSWAPMB";
				};
				class ComboGSwapMB: EnableBDCCombo
				{
					idc = 1115;
					y = 0.7500001;
				};
				class TextGFastThrowAmp: EnableBDCText
				{
					y = 0.80000013;
					text = "$STR_TITLES_GFASTTHROWAMP";
				};
				class ComboGFastThrowAmp: EnableBDCCombo
				{
					idc = 1116;
					y = 0.80000013;
				};
				class TextGAmpGain: EnableBDCText
				{
					y = 0.85000014;
					text = "$STR_TITLES_GAMPGAIN";
				};
				class ComboGAmpGain: EnableBDCCombo
				{
					idc = 1117;
					y = 0.85000014;
				};
				class TextEnableGrenadeThrow2: EnableBDCText
				{
					y = 0.90000015;
					text = "$STR_TITLES_ENABLEGRENADETHROW2";
				};
				class ComboEnableGrenadeThrow2: EnableBDCCombo
				{
					idc = 1118;
					y = 0.90000015;
				};
				class TextInteractToggle: EnableBDCText
				{
					y = 0.95000017;
					text = "$STR_TITLES_INTERACTTOGGLE";
				};
				class ComboInteractToggle: EnableBDCCombo
				{
					idc = 1119;
					y = 0.95000017;
				};
				class TextRWRPos: EnableBDCText
				{
					y = 1.0000001;
					text = "$STR_TITLES_RWRPOSITION";
				};
				class ComboRWRPos: EnableBDCCombo
				{
					idc = 1120;
					y = 1.0000001;
				};
			};
		};
		class ClientsideConfig_SP: ACE_SD_RscControlsGroup
		{
			x = 0.329816;
			y = "SafezoneY + 0.09 * safezoneW";
			w = 0.630743;
			h = "SafezoneH * 0.75";
			idc = 1003;
			class VScrollbar
			{
				color[] = {0.8784,0.8471,0.651,1};
				width = 0.02;
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
			};
			class HScrollbar
			{
				color[] = {0,0,0,0};
				height = 0.001;
			};
			class ScrollBar
			{
				color[] = {1,1,1,0.6};
				colorActive[] = {1,1,1,1};
				colorDisabled[] = {1,1,1,0.3};
				thumb = "\ca\ui\data\ui_border_frame_ca.paa";
				arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
				arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
				border = "\ca\ui\data\ui_border_scroll_ca.paa";
				shadow = 0;
			};
			class Controls
			{
				class SP_EnableBDCText: ACE_SD_RscText2
				{
					x = 0.03;
					y = 0;
					w = 0.28;
					h = 0.023;
					sizeEx = 0.027;
					text = "$STR_TITLES_ENABLESPPLAYERMEDIC";
				};
				class SP_EnableBDCCombo: ACE_SD_UIComboBox
				{
					idc = 1300;
					x = 0.3;
					y = 0;
					w = 0.13;
					h = 0.027;
				};
			};
		};
		class KeysConfig: ACE_SD_RscControlsGroup
		{
			x = 0.329816;
			y = "SafezoneY + 0.09 * safezoneW";
			w = 0.630743;
			h = "SafezoneH * 0.75";
			idc = 1002;
			class VScrollbar
			{
				color[] = {0.8784,0.8471,0.651,1};
				width = 0.02;
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
			};
			class HScrollbar
			{
				color[] = {0,0,0,0};
				height = 0.001;
			};
			class ScrollBar
			{
				color[] = {1,1,1,0.6};
				colorActive[] = {1,1,1,1};
				colorDisabled[] = {1,1,1,0.3};
				thumb = "\ca\ui\data\ui_border_frame_ca.paa";
				arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
				arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
				border = "\ca\ui\data\ui_border_scroll_ca.paa";
				shadow = 0;
			};
			class Controls
			{
				class KeyFeatureText1: ACE_SD_RscText2
				{
					idc = 2000;
					type = 13;
					x = 0.03;
					y = 0;
					w = 0.26;
					h = 0.035;
					sizeEx = 0.023;
					text = "";
				};
				class SHIFTKeyText1: ACE_SD_RscPicture
				{
					idc = 4000;
					style = "48+ 3";
					x = 0.26;
					y = 0;
					w = 0.035;
					h = 0.035;
					sizeEx = 0.02;
					text = "";
				};
				class CTRLKeyText1: SHIFTKeyText1
				{
					idc = 3500;
					x = 0.305;
					text = "";
				};
				class ALTKeyText1: SHIFTKeyText1
				{
					idc = 3000;
					x = 0.35;
					text = "";
				};
				class KeyTextBox1: ACE_LinkButtonBase
				{
					idc = 2500;
					x = 0.395;
					y = 0;
					w = 0.19;
					h = 0.035;
					sizeEx = 0.026;
					text = "";
					action = "with uiNamespace do { 2500  call ace_settings_fnc_linkbuttonclicked}";
				};
				class KeyFeatureText2: KeyFeatureText1
				{
					idc = 2001;
					y = 0.037;
					text = "";
				};
				class KeyTextBox2: KeyTextBox1
				{
					idc = 2501;
					y = 0.037;
					action = "with uiNamespace do { 2501  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText2: SHIFTKeyText1
				{
					idc = 4001;
					y = 0.037;
				};
				class CTRLKeyText2: CTRLKeyText1
				{
					idc = 3501;
					y = 0.037;
				};
				class ALTKeyText2: ALTKeyText1
				{
					idc = 3001;
					y = 0.037;
				};
				class KeyFeatureText3: KeyFeatureText1
				{
					idc = 2002;
					y = 0.074;
					text = "";
				};
				class KeyTextBox3: KeyTextBox1
				{
					idc = 2502;
					y = 0.074;
					action = "with uiNamespace do { 2502  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText3: SHIFTKeyText1
				{
					idc = 4002;
					y = 0.074;
				};
				class CTRLKeyText3: CTRLKeyText1
				{
					idc = 3502;
					y = 0.074;
				};
				class ALTKeyText3: ALTKeyText1
				{
					idc = 3002;
					y = 0.074;
				};
				class KeyFeatureText4: KeyFeatureText1
				{
					idc = 2003;
					y = 0.111;
					text = "";
				};
				class KeyTextBox4: KeyTextBox1
				{
					idc = 2503;
					y = 0.111;
					action = "with uiNamespace do { 2503  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText4: SHIFTKeyText1
				{
					idc = 4003;
					y = 0.111;
				};
				class CTRLKeyText4: CTRLKeyText1
				{
					idc = 3503;
					y = 0.111;
				};
				class ALTKeyText4: ALTKeyText1
				{
					idc = 3003;
					y = 0.111;
				};
				class KeyFeatureText5: KeyFeatureText1
				{
					idc = 2004;
					y = 0.148;
					text = "";
				};
				class KeyTextBox5: KeyTextBox1
				{
					idc = 2504;
					y = 0.148;
					action = "with uiNamespace do { 2504  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText5: SHIFTKeyText1
				{
					idc = 4004;
					y = 0.148;
				};
				class CTRLKeyText5: CTRLKeyText1
				{
					idc = 3504;
					y = 0.148;
				};
				class ALTKeyText5: ALTKeyText1
				{
					idc = 3004;
					y = 0.148;
				};
				class KeyFeatureText6: KeyFeatureText1
				{
					idc = 2005;
					y = 0.185;
					text = "";
				};
				class KeyTextBox6: KeyTextBox1
				{
					idc = 2505;
					y = 0.185;
					action = "with uiNamespace do { 2505  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText6: SHIFTKeyText1
				{
					idc = 4005;
					y = 0.185;
				};
				class CTRLKeyText6: CTRLKeyText1
				{
					idc = 3505;
					y = 0.185;
				};
				class ALTKeyText6: ALTKeyText1
				{
					idc = 3005;
					y = 0.185;
				};
				class KeyFeatureText7: KeyFeatureText1
				{
					idc = 2006;
					y = 0.222;
					text = "";
				};
				class KeyTextBox7: KeyTextBox1
				{
					idc = 2506;
					y = 0.222;
					action = "with uiNamespace do { 2506  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText7: SHIFTKeyText1
				{
					idc = 4006;
					y = 0.222;
				};
				class CTRLKeyText7: CTRLKeyText1
				{
					idc = 3506;
					y = 0.222;
				};
				class ALTKeyText7: ALTKeyText1
				{
					idc = 3006;
					y = 0.222;
				};
				class KeyFeatureText8: KeyFeatureText1
				{
					idc = 2007;
					y = 0.259;
					text = "";
				};
				class KeyTextBox8: KeyTextBox1
				{
					idc = 2507;
					y = 0.259;
					action = "with uiNamespace do { 2507  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText8: SHIFTKeyText1
				{
					idc = 4007;
					y = 0.259;
				};
				class CTRLKeyText8: CTRLKeyText1
				{
					idc = 3507;
					y = 0.259;
				};
				class ALTKeyText8: ALTKeyText1
				{
					idc = 3007;
					y = 0.259;
				};
				class KeyFeatureText9: KeyFeatureText1
				{
					idc = 2008;
					y = 0.296;
					text = "";
				};
				class KeyTextBox9: KeyTextBox1
				{
					idc = 2508;
					y = 0.296;
					action = "with uiNamespace do { 2508  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText9: SHIFTKeyText1
				{
					idc = 4008;
					y = 0.296;
				};
				class CTRLKeyText9: CTRLKeyText1
				{
					idc = 3508;
					y = 0.296;
				};
				class ALTKeyText9: ALTKeyText1
				{
					idc = 3008;
					y = 0.296;
				};
				class KeyFeatureText10: KeyFeatureText1
				{
					idc = 2009;
					y = 0.333;
					text = "";
				};
				class KeyTextBox10: KeyTextBox1
				{
					idc = 2509;
					y = 0.333;
					action = "with uiNamespace do { 2509  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText10: SHIFTKeyText1
				{
					idc = 4009;
					y = 0.333;
				};
				class CTRLKeyText10: CTRLKeyText1
				{
					idc = 3509;
					y = 0.333;
				};
				class ALTKeyText10: ALTKeyText1
				{
					idc = 3009;
					y = 0.333;
				};
				class KeyFeatureText11: KeyFeatureText1
				{
					idc = 2010;
					y = 0.37;
					text = "";
				};
				class KeyTextBox11: KeyTextBox1
				{
					idc = 2510;
					y = 0.37;
					action = "with uiNamespace do { 2510  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText11: SHIFTKeyText1
				{
					idc = 4010;
					y = 0.37;
				};
				class CTRLKeyText11: CTRLKeyText1
				{
					idc = 3510;
					y = 0.37;
				};
				class ALTKeyText11: ALTKeyText1
				{
					idc = 3010;
					y = 0.37;
				};
				class KeyFeatureText12: KeyFeatureText1
				{
					idc = 2011;
					y = 0.407;
					text = "";
				};
				class KeyTextBox12: KeyTextBox1
				{
					idc = 2511;
					y = 0.407;
					action = "with uiNamespace do { 2511  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText12: SHIFTKeyText1
				{
					idc = 4011;
					y = 0.407;
				};
				class CTRLKeyText12: CTRLKeyText1
				{
					idc = 3511;
					y = 0.407;
				};
				class ALTKeyText12: ALTKeyText1
				{
					idc = 3011;
					y = 0.407;
				};
				class KeyFeatureText13: KeyFeatureText1
				{
					idc = 2012;
					y = 0.444;
					text = "";
				};
				class KeyTextBox13: KeyTextBox1
				{
					idc = 2512;
					y = 0.444;
					action = "with uiNamespace do { 2512  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText13: SHIFTKeyText1
				{
					idc = 4012;
					y = 0.444;
				};
				class CTRLKeyText13: CTRLKeyText1
				{
					idc = 3512;
					y = 0.444;
				};
				class ALTKeyText13: ALTKeyText1
				{
					idc = 3012;
					y = 0.444;
				};
				class KeyFeatureText14: KeyFeatureText1
				{
					idc = 2013;
					y = 0.481;
					text = "";
				};
				class KeyTextBox14: KeyTextBox1
				{
					idc = 2513;
					y = 0.481;
					action = "with uiNamespace do { 2513  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText14: SHIFTKeyText1
				{
					idc = 4013;
					y = 0.481;
				};
				class CTRLKeyText14: CTRLKeyText1
				{
					idc = 3513;
					y = 0.481;
				};
				class ALTKeyText14: ALTKeyText1
				{
					idc = 3013;
					y = 0.481;
				};
				class KeyFeatureText15: KeyFeatureText1
				{
					idc = 2014;
					y = 0.518;
					text = "";
				};
				class KeyTextBox15: KeyTextBox1
				{
					idc = 2514;
					y = 0.518;
					action = "with uiNamespace do { 2514  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText15: SHIFTKeyText1
				{
					idc = 4014;
					y = 0.518;
				};
				class CTRLKeyText15: CTRLKeyText1
				{
					idc = 3514;
					y = 0.518;
				};
				class ALTKeyText15: ALTKeyText1
				{
					idc = 3014;
					y = 0.518;
				};
				class KeyFeatureText16: KeyFeatureText1
				{
					idc = 2015;
					y = 0.555;
					text = "";
				};
				class KeyTextBox16: KeyTextBox1
				{
					idc = 2515;
					y = 0.555;
					action = "with uiNamespace do { 2515  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText16: SHIFTKeyText1
				{
					idc = 4015;
					y = 0.555;
				};
				class CTRLKeyText16: CTRLKeyText1
				{
					idc = 3515;
					y = 0.555;
				};
				class ALTKeyText16: ALTKeyText1
				{
					idc = 3015;
					y = 0.555;
				};
				class KeyFeatureText17: KeyFeatureText1
				{
					idc = 2016;
					y = 0.592;
					text = "";
				};
				class KeyTextBox17: KeyTextBox1
				{
					idc = 2516;
					y = 0.592;
					action = "with uiNamespace do { 2516  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText17: SHIFTKeyText1
				{
					idc = 4016;
					y = 0.592;
				};
				class CTRLKeyText17: CTRLKeyText1
				{
					idc = 3516;
					y = 0.592;
				};
				class ALTKeyText17: ALTKeyText1
				{
					idc = 3016;
					y = 0.592;
				};
				class KeyFeatureText18: KeyFeatureText1
				{
					idc = 2017;
					y = 0.629;
					text = "";
				};
				class KeyTextBox18: KeyTextBox1
				{
					idc = 2517;
					y = 0.629;
					action = "with uiNamespace do { 2517  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText18: SHIFTKeyText1
				{
					idc = 4017;
					y = 0.629;
				};
				class CTRLKeyText18: CTRLKeyText1
				{
					idc = 3517;
					y = 0.629;
				};
				class ALTKeyText18: ALTKeyText1
				{
					idc = 3017;
					y = 0.629;
				};
				class KeyFeatureText19: KeyFeatureText1
				{
					idc = 2018;
					y = 0.666;
					text = "";
				};
				class KeyTextBox19: KeyTextBox1
				{
					idc = 2518;
					y = 0.666;
					action = "with uiNamespace do { 2518  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText19: SHIFTKeyText1
				{
					idc = 4018;
					y = 0.666;
				};
				class CTRLKeyText19: CTRLKeyText1
				{
					idc = 3518;
					y = 0.666;
				};
				class ALTKeyText19: ALTKeyText1
				{
					idc = 3018;
					y = 0.666;
				};
				class KeyFeatureText20: KeyFeatureText1
				{
					idc = 2019;
					y = 0.703;
					text = "";
				};
				class KeyTextBox20: KeyTextBox1
				{
					idc = 2519;
					y = 0.703;
					action = "with uiNamespace do { 2519  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText20: SHIFTKeyText1
				{
					idc = 4019;
					y = 0.703;
				};
				class CTRLKeyText20: CTRLKeyText1
				{
					idc = 3519;
					y = 0.703;
				};
				class ALTKeyText20: ALTKeyText1
				{
					idc = 3019;
					y = 0.703;
				};
				class KeyFeatureText21: KeyFeatureText1
				{
					idc = 2020;
					y = 0.74;
					text = "";
				};
				class KeyTextBox21: KeyTextBox1
				{
					idc = 2520;
					y = 0.74;
					action = "with uiNamespace do { 2520  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText21: SHIFTKeyText1
				{
					idc = 4020;
					y = 0.74;
				};
				class CTRLKeyText21: CTRLKeyText1
				{
					idc = 3520;
					y = 0.74;
				};
				class ALTKeyText21: ALTKeyText1
				{
					idc = 3020;
					y = 0.74;
				};
				class KeyFeatureText22: KeyFeatureText1
				{
					idc = 2021;
					y = 0.777;
					text = "";
				};
				class KeyTextBox22: KeyTextBox1
				{
					idc = 2521;
					y = 0.777;
					action = "with uiNamespace do { 2521  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText22: SHIFTKeyText1
				{
					idc = 4021;
					y = 0.777;
				};
				class CTRLKeyText22: CTRLKeyText1
				{
					idc = 3521;
					y = 0.777;
				};
				class ALTKeyText22: ALTKeyText1
				{
					idc = 3021;
					y = 0.777;
				};
				class KeyFeatureText23: KeyFeatureText1
				{
					idc = 2022;
					y = 0.814;
					text = "";
				};
				class KeyTextBox23: KeyTextBox1
				{
					idc = 2522;
					y = 0.814;
					action = "with uiNamespace do { 2522  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText23: SHIFTKeyText1
				{
					idc = 4022;
					y = 0.814;
				};
				class CTRLKeyText23: CTRLKeyText1
				{
					idc = 3522;
					y = 0.814;
				};
				class ALTKeyText23: ALTKeyText1
				{
					idc = 3022;
					y = 0.814;
				};
				class KeyFeatureText24: KeyFeatureText1
				{
					idc = 2023;
					y = 0.851;
					text = "";
				};
				class KeyTextBox24: KeyTextBox1
				{
					idc = 2523;
					y = 0.851;
					action = "with uiNamespace do { 2523  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText24: SHIFTKeyText1
				{
					idc = 4023;
					y = 0.851;
				};
				class CTRLKeyText24: CTRLKeyText1
				{
					idc = 3523;
					y = 0.851;
				};
				class ALTKeyText24: ALTKeyText1
				{
					idc = 3023;
					y = 0.851;
				};
				class KeyFeatureText25: KeyFeatureText1
				{
					idc = 2024;
					y = 0.888;
					text = "";
				};
				class KeyTextBox25: KeyTextBox1
				{
					idc = 2524;
					y = 0.888;
					action = "with uiNamespace do { 2524  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText25: SHIFTKeyText1
				{
					idc = 4024;
					y = 0.888;
				};
				class CTRLKeyText25: CTRLKeyText1
				{
					idc = 3524;
					y = 0.888;
				};
				class ALTKeyText25: ALTKeyText1
				{
					idc = 3024;
					y = 0.888;
				};
				class KeyFeatureText26: KeyFeatureText1
				{
					idc = 2025;
					y = 0.925;
					text = "";
				};
				class KeyTextBox26: KeyTextBox1
				{
					idc = 2525;
					y = 0.925;
					action = "with uiNamespace do { 2525  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText26: SHIFTKeyText1
				{
					idc = 4025;
					y = 0.925;
				};
				class CTRLKeyText26: CTRLKeyText1
				{
					idc = 3525;
					y = 0.925;
				};
				class ALTKeyText26: ALTKeyText1
				{
					idc = 3025;
					y = 0.925;
				};
				class KeyFeatureText27: KeyFeatureText1
				{
					idc = 2026;
					y = 0.962;
					text = "";
				};
				class KeyTextBox27: KeyTextBox1
				{
					idc = 2526;
					y = 0.962;
					action = "with uiNamespace do { 2526  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText27: SHIFTKeyText1
				{
					idc = 4026;
					y = 0.962;
				};
				class CTRLKeyText27: CTRLKeyText1
				{
					idc = 3526;
					y = 0.962;
				};
				class ALTKeyText27: ALTKeyText1
				{
					idc = 3026;
					y = 0.962;
				};
				class KeyFeatureText28: KeyFeatureText1
				{
					idc = 2027;
					y = 0.999;
					text = "";
				};
				class KeyTextBox28: KeyTextBox1
				{
					idc = 2527;
					y = 0.999;
					action = "with uiNamespace do { 2527  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText28: SHIFTKeyText1
				{
					idc = 4027;
					y = 0.999;
				};
				class CTRLKeyText28: CTRLKeyText1
				{
					idc = 3527;
					y = 0.999;
				};
				class ALTKeyText28: ALTKeyText1
				{
					idc = 3027;
					y = 0.999;
				};
				class KeyFeatureText29: KeyFeatureText1
				{
					idc = 2028;
					y = 1.036;
					text = "";
				};
				class KeyTextBox29: KeyTextBox1
				{
					idc = 2528;
					y = 1.036;
					action = "with uiNamespace do { 2528  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText29: SHIFTKeyText1
				{
					idc = 4028;
					y = 1.036;
				};
				class CTRLKeyText29: CTRLKeyText1
				{
					idc = 3528;
					y = 1.036;
				};
				class ALTKeyText29: ALTKeyText1
				{
					idc = 3028;
					y = 1.036;
				};
				class KeyFeatureText30: KeyFeatureText1
				{
					idc = 2029;
					y = 1.073;
					text = "";
				};
				class KeyTextBox30: KeyTextBox1
				{
					idc = 2529;
					y = 1.073;
					action = "with uiNamespace do { 2529  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText30: SHIFTKeyText1
				{
					idc = 4029;
					y = 1.073;
				};
				class CTRLKeyText30: CTRLKeyText1
				{
					idc = 3529;
					y = 1.073;
				};
				class ALTKeyText30: ALTKeyText1
				{
					idc = 3029;
					y = 1.073;
				};
				class KeyFeatureText31: KeyFeatureText1
				{
					idc = 2030;
					y = 1.1099999;
					text = "";
				};
				class KeyTextBox31: KeyTextBox1
				{
					idc = 2530;
					y = 1.1099999;
					action = "with uiNamespace do { 2530  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText31: SHIFTKeyText1
				{
					idc = 4030;
					y = 1.1099999;
				};
				class CTRLKeyText31: CTRLKeyText1
				{
					idc = 3530;
					y = 1.1099999;
				};
				class ALTKeyText31: ALTKeyText1
				{
					idc = 3030;
					y = 1.1099999;
				};
				class KeyFeatureText32: KeyFeatureText1
				{
					idc = 2031;
					y = 1.1469998;
					text = "";
				};
				class KeyTextBox32: KeyTextBox1
				{
					idc = 2531;
					y = 1.1469998;
					action = "with uiNamespace do { 2531  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText32: SHIFTKeyText1
				{
					idc = 4031;
					y = 1.1469998;
				};
				class CTRLKeyText32: CTRLKeyText1
				{
					idc = 3531;
					y = 1.1469998;
				};
				class ALTKeyText32: ALTKeyText1
				{
					idc = 3031;
					y = 1.1469998;
				};
				class KeyFeatureText33: KeyFeatureText1
				{
					idc = 2032;
					y = 1.1839998;
					text = "";
				};
				class KeyTextBox33: KeyTextBox1
				{
					idc = 2532;
					y = 1.1839998;
					action = "with uiNamespace do { 2532  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText33: SHIFTKeyText1
				{
					idc = 4032;
					y = 1.1839998;
				};
				class CTRLKeyText33: CTRLKeyText1
				{
					idc = 3532;
					y = 1.1839998;
				};
				class ALTKeyText33: ALTKeyText1
				{
					idc = 3032;
					y = 1.1839998;
				};
				class KeyFeatureText34: KeyFeatureText1
				{
					idc = 2033;
					y = 1.2209997;
					text = "";
				};
				class KeyTextBox34: KeyTextBox1
				{
					idc = 2533;
					y = 1.2209997;
					action = "with uiNamespace do { 2533  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText34: SHIFTKeyText1
				{
					idc = 4033;
					y = 1.2209997;
				};
				class CTRLKeyText34: CTRLKeyText1
				{
					idc = 3533;
					y = 1.2209997;
				};
				class ALTKeyText34: ALTKeyText1
				{
					idc = 3033;
					y = 1.2209997;
				};
				class KeyFeatureText35: KeyFeatureText1
				{
					idc = 2034;
					y = 1.2579997;
					text = "";
				};
				class KeyTextBox35: KeyTextBox1
				{
					idc = 2534;
					y = 1.2579997;
					action = "with uiNamespace do { 2534  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText35: SHIFTKeyText1
				{
					idc = 4034;
					y = 1.2579997;
				};
				class CTRLKeyText35: CTRLKeyText1
				{
					idc = 3534;
					y = 1.2579997;
				};
				class ALTKeyText35: ALTKeyText1
				{
					idc = 3034;
					y = 1.2579997;
				};
				class KeyFeatureText36: KeyFeatureText1
				{
					idc = 2035;
					y = 1.2949996;
					text = "";
				};
				class KeyTextBox36: KeyTextBox1
				{
					idc = 2535;
					y = 1.2949996;
					action = "with uiNamespace do { 2535  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText36: SHIFTKeyText1
				{
					idc = 4035;
					y = 1.2949996;
				};
				class CTRLKeyText36: CTRLKeyText1
				{
					idc = 3535;
					y = 1.2949996;
				};
				class ALTKeyText36: ALTKeyText1
				{
					idc = 3035;
					y = 1.2949996;
				};
				class KeyFeatureText37: KeyFeatureText1
				{
					idc = 2036;
					y = 1.3319995;
					text = "";
				};
				class KeyTextBox37: KeyTextBox1
				{
					idc = 2536;
					y = 1.3319995;
					action = "with uiNamespace do { 2536  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText37: SHIFTKeyText1
				{
					idc = 4036;
					y = 1.3319995;
				};
				class CTRLKeyText37: CTRLKeyText1
				{
					idc = 3536;
					y = 1.3319995;
				};
				class ALTKeyText37: ALTKeyText1
				{
					idc = 3036;
					y = 1.3319995;
				};
				class KeyFeatureText38: KeyFeatureText1
				{
					idc = 2037;
					y = 1.3689995;
					text = "";
				};
				class KeyTextBox38: KeyTextBox1
				{
					idc = 2537;
					y = 1.3689995;
					action = "with uiNamespace do { 2537  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText38: SHIFTKeyText1
				{
					idc = 4037;
					y = 1.3689995;
				};
				class CTRLKeyText38: CTRLKeyText1
				{
					idc = 3537;
					y = 1.3689995;
				};
				class ALTKeyText38: ALTKeyText1
				{
					idc = 3037;
					y = 1.3689995;
				};
				class KeyFeatureText39: KeyFeatureText1
				{
					idc = 2038;
					y = 1.4059994;
					text = "";
				};
				class KeyTextBox39: KeyTextBox1
				{
					idc = 2538;
					y = 1.4059994;
					action = "with uiNamespace do { 2538  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText39: SHIFTKeyText1
				{
					idc = 4038;
					y = 1.4059994;
				};
				class CTRLKeyText39: CTRLKeyText1
				{
					idc = 3538;
					y = 1.4059994;
				};
				class ALTKeyText39: ALTKeyText1
				{
					idc = 3038;
					y = 1.4059994;
				};
				class KeyFeatureText40: KeyFeatureText1
				{
					idc = 2039;
					y = 1.4429994;
					text = "";
				};
				class KeyTextBox40: KeyTextBox1
				{
					idc = 2539;
					y = 1.4429994;
					action = "with uiNamespace do { 2539  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText40: SHIFTKeyText1
				{
					idc = 4039;
					y = 1.4429994;
				};
				class CTRLKeyText40: CTRLKeyText1
				{
					idc = 3539;
					y = 1.4429994;
				};
				class ALTKeyText40: ALTKeyText1
				{
					idc = 3039;
					y = 1.4429994;
				};
				class KeyFeatureText41: KeyFeatureText1
				{
					idc = 2040;
					y = 1.4799993;
					text = "";
				};
				class KeyTextBox41: KeyTextBox1
				{
					idc = 2540;
					y = 1.4799993;
					action = "with uiNamespace do { 2540  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText41: SHIFTKeyText1
				{
					idc = 4040;
					y = 1.4799993;
				};
				class CTRLKeyText41: CTRLKeyText1
				{
					idc = 3540;
					y = 1.4799993;
				};
				class ALTKeyText41: ALTKeyText1
				{
					idc = 3040;
					y = 1.4799993;
				};
				class KeyFeatureText42: KeyFeatureText1
				{
					idc = 2041;
					y = 1.5169992;
					text = "";
				};
				class KeyTextBox42: KeyTextBox1
				{
					idc = 2541;
					y = 1.5169992;
					action = "with uiNamespace do { 2541  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText42: SHIFTKeyText1
				{
					idc = 4041;
					y = 1.5169992;
				};
				class CTRLKeyText42: CTRLKeyText1
				{
					idc = 3541;
					y = 1.5169992;
				};
				class ALTKeyText42: ALTKeyText1
				{
					idc = 3041;
					y = 1.5169992;
				};
				class KeyFeatureText43: KeyFeatureText1
				{
					idc = 2042;
					y = 1.5539992;
					text = "";
				};
				class KeyTextBox43: KeyTextBox1
				{
					idc = 2542;
					y = 1.5539992;
					action = "with uiNamespace do { 2542  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText43: SHIFTKeyText1
				{
					idc = 4042;
					y = 1.5539992;
				};
				class CTRLKeyText43: CTRLKeyText1
				{
					idc = 3542;
					y = 1.5539992;
				};
				class ALTKeyText43: ALTKeyText1
				{
					idc = 3042;
					y = 1.5539992;
				};
				class KeyFeatureText44: KeyFeatureText1
				{
					idc = 2043;
					y = 1.5909991;
					text = "";
				};
				class KeyTextBox44: KeyTextBox1
				{
					idc = 2543;
					y = 1.5909991;
					action = "with uiNamespace do { 2543  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText44: SHIFTKeyText1
				{
					idc = 4043;
					y = 1.5909991;
				};
				class CTRLKeyText44: CTRLKeyText1
				{
					idc = 3543;
					y = 1.5909991;
				};
				class ALTKeyText44: ALTKeyText1
				{
					idc = 3043;
					y = 1.5909991;
				};
				class KeyFeatureText45: KeyFeatureText1
				{
					idc = 2044;
					y = 1.6279991;
					text = "";
				};
				class KeyTextBox45: KeyTextBox1
				{
					idc = 2544;
					y = 1.6279991;
					action = "with uiNamespace do { 2544  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText45: SHIFTKeyText1
				{
					idc = 4044;
					y = 1.6279991;
				};
				class CTRLKeyText45: CTRLKeyText1
				{
					idc = 3544;
					y = 1.6279991;
				};
				class ALTKeyText45: ALTKeyText1
				{
					idc = 3044;
					y = 1.6279991;
				};
				class KeyFeatureText46: KeyFeatureText1
				{
					idc = 2045;
					y = 1.664999;
					text = "";
				};
				class KeyTextBox46: KeyTextBox1
				{
					idc = 2545;
					y = 1.664999;
					action = "with uiNamespace do { 2545  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText46: SHIFTKeyText1
				{
					idc = 4045;
					y = 1.664999;
				};
				class CTRLKeyText46: CTRLKeyText1
				{
					idc = 3545;
					y = 1.664999;
				};
				class ALTKeyText46: ALTKeyText1
				{
					idc = 3045;
					y = 1.664999;
				};
				class KeyFeatureText47: KeyFeatureText1
				{
					idc = 2046;
					y = 1.701999;
					text = "";
				};
				class KeyTextBox47: KeyTextBox1
				{
					idc = 2546;
					y = 1.701999;
					action = "with uiNamespace do { 2546  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText47: SHIFTKeyText1
				{
					idc = 4046;
					y = 1.701999;
				};
				class CTRLKeyText47: CTRLKeyText1
				{
					idc = 3546;
					y = 1.701999;
				};
				class ALTKeyText47: ALTKeyText1
				{
					idc = 3046;
					y = 1.701999;
				};
				class KeyFeatureText48: KeyFeatureText1
				{
					idc = 2047;
					y = 1.7389989;
					text = "";
				};
				class KeyTextBox48: KeyTextBox1
				{
					idc = 2547;
					y = 1.7389989;
					action = "with uiNamespace do { 2547  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText48: SHIFTKeyText1
				{
					idc = 4047;
					y = 1.7389989;
				};
				class CTRLKeyText48: CTRLKeyText1
				{
					idc = 3547;
					y = 1.7389989;
				};
				class ALTKeyText48: ALTKeyText1
				{
					idc = 3047;
					y = 1.7389989;
				};
				class KeyFeatureText49: KeyFeatureText1
				{
					idc = 2048;
					y = 1.7759988;
					text = "";
				};
				class KeyTextBox49: KeyTextBox1
				{
					idc = 2548;
					y = 1.7759988;
					action = "with uiNamespace do { 2548  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText49: SHIFTKeyText1
				{
					idc = 4048;
					y = 1.7759988;
				};
				class CTRLKeyText49: CTRLKeyText1
				{
					idc = 3548;
					y = 1.7759988;
				};
				class ALTKeyText49: ALTKeyText1
				{
					idc = 3048;
					y = 1.7759988;
				};
				class KeyFeatureText50: KeyFeatureText1
				{
					idc = 2049;
					y = 1.8129988;
					text = "";
				};
				class KeyTextBox50: KeyTextBox1
				{
					idc = 2549;
					y = 1.8129988;
					action = "with uiNamespace do { 2549  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText50: SHIFTKeyText1
				{
					idc = 4049;
					y = 1.8129988;
				};
				class CTRLKeyText50: CTRLKeyText1
				{
					idc = 3549;
					y = 1.8129988;
				};
				class ALTKeyText50: ALTKeyText1
				{
					idc = 3049;
					y = 1.8129988;
				};
				class KeyFeatureText51: KeyFeatureText1
				{
					idc = 2050;
					y = 1.8499987;
					text = "";
				};
				class KeyTextBox51: KeyTextBox1
				{
					idc = 2550;
					y = 1.8499987;
					action = "with uiNamespace do { 2550  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText51: SHIFTKeyText1
				{
					idc = 4050;
					y = 1.8499987;
				};
				class CTRLKeyText51: CTRLKeyText1
				{
					idc = 3550;
					y = 1.8499987;
				};
				class ALTKeyText51: ALTKeyText1
				{
					idc = 3050;
					y = 1.8499987;
				};
				class KeyFeatureText52: KeyFeatureText1
				{
					idc = 2051;
					y = 1.8869987;
					text = "";
				};
				class KeyTextBox52: KeyTextBox1
				{
					idc = 2551;
					y = 1.8869987;
					action = "with uiNamespace do { 2551  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText52: SHIFTKeyText1
				{
					idc = 4051;
					y = 1.8869987;
				};
				class CTRLKeyText52: CTRLKeyText1
				{
					idc = 3551;
					y = 1.8869987;
				};
				class ALTKeyText52: ALTKeyText1
				{
					idc = 3051;
					y = 1.8869987;
				};
				class KeyFeatureText53: KeyFeatureText1
				{
					idc = 2052;
					y = 1.9239986;
					text = "";
				};
				class KeyTextBox53: KeyTextBox1
				{
					idc = 2552;
					y = 1.9239986;
					action = "with uiNamespace do { 2552  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText53: SHIFTKeyText1
				{
					idc = 4052;
					y = 1.9239986;
				};
				class CTRLKeyText53: CTRLKeyText1
				{
					idc = 3552;
					y = 1.9239986;
				};
				class ALTKeyText53: ALTKeyText1
				{
					idc = 3052;
					y = 1.9239986;
				};
				class KeyFeatureText54: KeyFeatureText1
				{
					idc = 2053;
					y = 1.9609985;
					text = "";
				};
				class KeyTextBox54: KeyTextBox1
				{
					idc = 2553;
					y = 1.9609985;
					action = "with uiNamespace do { 2553  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText54: SHIFTKeyText1
				{
					idc = 4053;
					y = 1.9609985;
				};
				class CTRLKeyText54: CTRLKeyText1
				{
					idc = 3553;
					y = 1.9609985;
				};
				class ALTKeyText54: ALTKeyText1
				{
					idc = 3053;
					y = 1.9609985;
				};
				class KeyFeatureText55: KeyFeatureText1
				{
					idc = 2054;
					y = 1.9979985;
					text = "";
				};
				class KeyTextBox55: KeyTextBox1
				{
					idc = 2554;
					y = 1.9979985;
					action = "with uiNamespace do { 2554  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText55: SHIFTKeyText1
				{
					idc = 4054;
					y = 1.9979985;
				};
				class CTRLKeyText55: CTRLKeyText1
				{
					idc = 3554;
					y = 1.9979985;
				};
				class ALTKeyText55: ALTKeyText1
				{
					idc = 3054;
					y = 1.9979985;
				};
				class KeyFeatureText56: KeyFeatureText1
				{
					idc = 2055;
					y = 2.0349984;
					text = "";
				};
				class KeyTextBox56: KeyTextBox1
				{
					idc = 2555;
					y = 2.0349984;
					action = "with uiNamespace do { 2555  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText56: SHIFTKeyText1
				{
					idc = 4055;
					y = 2.0349984;
				};
				class CTRLKeyText56: CTRLKeyText1
				{
					idc = 3555;
					y = 2.0349984;
				};
				class ALTKeyText56: ALTKeyText1
				{
					idc = 3055;
					y = 2.0349984;
				};
				class KeyFeatureText57: KeyFeatureText1
				{
					idc = 2056;
					y = 2.0719984;
					text = "";
				};
				class KeyTextBox57: KeyTextBox1
				{
					idc = 2556;
					y = 2.0719984;
					action = "with uiNamespace do { 2556  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText57: SHIFTKeyText1
				{
					idc = 4056;
					y = 2.0719984;
				};
				class CTRLKeyText57: CTRLKeyText1
				{
					idc = 3556;
					y = 2.0719984;
				};
				class ALTKeyText57: ALTKeyText1
				{
					idc = 3056;
					y = 2.0719984;
				};
				class KeyFeatureText58: KeyFeatureText1
				{
					idc = 2057;
					y = 2.1089983;
					text = "";
				};
				class KeyTextBox58: KeyTextBox1
				{
					idc = 2557;
					y = 2.1089983;
					action = "with uiNamespace do { 2557  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText58: SHIFTKeyText1
				{
					idc = 4057;
					y = 2.1089983;
				};
				class CTRLKeyText58: CTRLKeyText1
				{
					idc = 3557;
					y = 2.1089983;
				};
				class ALTKeyText58: ALTKeyText1
				{
					idc = 3057;
					y = 2.1089983;
				};
				class KeyFeatureText59: KeyFeatureText1
				{
					idc = 2058;
					y = 2.1459982;
					text = "";
				};
				class KeyTextBox59: KeyTextBox1
				{
					idc = 2558;
					y = 2.1459982;
					action = "with uiNamespace do { 2558  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText59: SHIFTKeyText1
				{
					idc = 4058;
					y = 2.1459982;
				};
				class CTRLKeyText59: CTRLKeyText1
				{
					idc = 3558;
					y = 2.1459982;
				};
				class ALTKeyText59: ALTKeyText1
				{
					idc = 3058;
					y = 2.1459982;
				};
				class KeyFeatureText60: KeyFeatureText1
				{
					idc = 2059;
					y = 2.1829982;
					text = "";
				};
				class KeyTextBox60: KeyTextBox1
				{
					idc = 2559;
					y = 2.1829982;
					action = "with uiNamespace do { 2559  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText60: SHIFTKeyText1
				{
					idc = 4059;
					y = 2.1829982;
				};
				class CTRLKeyText60: CTRLKeyText1
				{
					idc = 3559;
					y = 2.1829982;
				};
				class ALTKeyText60: ALTKeyText1
				{
					idc = 3059;
					y = 2.1829982;
				};
				class KeyFeatureText61: KeyFeatureText1
				{
					idc = 2060;
					y = 2.2199981;
					text = "";
				};
				class KeyTextBox61: KeyTextBox1
				{
					idc = 2560;
					y = 2.2199981;
					action = "with uiNamespace do { 2560  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText61: SHIFTKeyText1
				{
					idc = 4060;
					y = 2.2199981;
				};
				class CTRLKeyText61: CTRLKeyText1
				{
					idc = 3560;
					y = 2.2199981;
				};
				class ALTKeyText61: ALTKeyText1
				{
					idc = 3060;
					y = 2.2199981;
				};
				class KeyFeatureText62: KeyFeatureText1
				{
					idc = 2061;
					y = 2.256998;
					text = "";
				};
				class KeyTextBox62: KeyTextBox1
				{
					idc = 2561;
					y = 2.256998;
					action = "with uiNamespace do { 2561  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText62: SHIFTKeyText1
				{
					idc = 4061;
					y = 2.256998;
				};
				class CTRLKeyText62: CTRLKeyText1
				{
					idc = 3561;
					y = 2.256998;
				};
				class ALTKeyText62: ALTKeyText1
				{
					idc = 3061;
					y = 2.256998;
				};
				class KeyFeatureText63: KeyFeatureText1
				{
					idc = 2062;
					y = 2.293998;
					text = "";
				};
				class KeyTextBox63: KeyTextBox1
				{
					idc = 2562;
					y = 2.293998;
					action = "with uiNamespace do { 2562  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText63: SHIFTKeyText1
				{
					idc = 4062;
					y = 2.293998;
				};
				class CTRLKeyText63: CTRLKeyText1
				{
					idc = 3562;
					y = 2.293998;
				};
				class ALTKeyText63: ALTKeyText1
				{
					idc = 3062;
					y = 2.293998;
				};
				class KeyFeatureText64: KeyFeatureText1
				{
					idc = 2063;
					y = 2.330998;
					text = "";
				};
				class KeyTextBox64: KeyTextBox1
				{
					idc = 2563;
					y = 2.330998;
					action = "with uiNamespace do { 2563  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText64: SHIFTKeyText1
				{
					idc = 4063;
					y = 2.330998;
				};
				class CTRLKeyText64: CTRLKeyText1
				{
					idc = 3563;
					y = 2.330998;
				};
				class ALTKeyText64: ALTKeyText1
				{
					idc = 3063;
					y = 2.330998;
				};
				class KeyFeatureText65: KeyFeatureText1
				{
					idc = 2064;
					y = 2.367998;
					text = "";
				};
				class KeyTextBox65: KeyTextBox1
				{
					idc = 2564;
					y = 2.367998;
					action = "with uiNamespace do { 2564  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText65: SHIFTKeyText1
				{
					idc = 4064;
					y = 2.367998;
				};
				class CTRLKeyText65: CTRLKeyText1
				{
					idc = 3564;
					y = 2.367998;
				};
				class ALTKeyText65: ALTKeyText1
				{
					idc = 3064;
					y = 2.367998;
				};
				class KeyFeatureText66: KeyFeatureText1
				{
					idc = 2065;
					y = 2.4049978;
					text = "";
				};
				class KeyTextBox66: KeyTextBox1
				{
					idc = 2565;
					y = 2.4049978;
					action = "with uiNamespace do { 2565  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText66: SHIFTKeyText1
				{
					idc = 4065;
					y = 2.4049978;
				};
				class CTRLKeyText66: CTRLKeyText1
				{
					idc = 3565;
					y = 2.4049978;
				};
				class ALTKeyText66: ALTKeyText1
				{
					idc = 3065;
					y = 2.4049978;
				};
				class KeyFeatureText67: KeyFeatureText1
				{
					idc = 2066;
					y = 2.4419978;
					text = "";
				};
				class KeyTextBox67: KeyTextBox1
				{
					idc = 2566;
					y = 2.4419978;
					action = "with uiNamespace do { 2566  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText67: SHIFTKeyText1
				{
					idc = 4066;
					y = 2.4419978;
				};
				class CTRLKeyText67: CTRLKeyText1
				{
					idc = 3566;
					y = 2.4419978;
				};
				class ALTKeyText67: ALTKeyText1
				{
					idc = 3066;
					y = 2.4419978;
				};
				class KeyFeatureText68: KeyFeatureText1
				{
					idc = 2067;
					y = 2.4789977;
					text = "";
				};
				class KeyTextBox68: KeyTextBox1
				{
					idc = 2567;
					y = 2.4789977;
					action = "with uiNamespace do { 2567  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText68: SHIFTKeyText1
				{
					idc = 4067;
					y = 2.4789977;
				};
				class CTRLKeyText68: CTRLKeyText1
				{
					idc = 3567;
					y = 2.4789977;
				};
				class ALTKeyText68: ALTKeyText1
				{
					idc = 3067;
					y = 2.4789977;
				};
				class KeyFeatureText69: KeyFeatureText1
				{
					idc = 2068;
					y = 2.5159976;
					text = "";
				};
				class KeyTextBox69: KeyTextBox1
				{
					idc = 2568;
					y = 2.5159976;
					action = "with uiNamespace do { 2568  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText69: SHIFTKeyText1
				{
					idc = 4068;
					y = 2.5159976;
				};
				class CTRLKeyText69: CTRLKeyText1
				{
					idc = 3568;
					y = 2.5159976;
				};
				class ALTKeyText69: ALTKeyText1
				{
					idc = 3068;
					y = 2.5159976;
				};
				class KeyFeatureText70: KeyFeatureText1
				{
					idc = 2069;
					y = 2.5529976;
					text = "";
				};
				class KeyTextBox70: KeyTextBox1
				{
					idc = 2569;
					y = 2.5529976;
					action = "with uiNamespace do { 2569  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText70: SHIFTKeyText1
				{
					idc = 4069;
					y = 2.5529976;
				};
				class CTRLKeyText70: CTRLKeyText1
				{
					idc = 3569;
					y = 2.5529976;
				};
				class ALTKeyText70: ALTKeyText1
				{
					idc = 3069;
					y = 2.5529976;
				};
				class KeyFeatureText71: KeyFeatureText1
				{
					idc = 2070;
					y = 2.5899975;
					text = "";
				};
				class KeyTextBox71: KeyTextBox1
				{
					idc = 2570;
					y = 2.5899975;
					action = "with uiNamespace do { 2570  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText71: SHIFTKeyText1
				{
					idc = 4070;
					y = 2.5899975;
				};
				class CTRLKeyText71: CTRLKeyText1
				{
					idc = 3570;
					y = 2.5899975;
				};
				class ALTKeyText71: ALTKeyText1
				{
					idc = 3070;
					y = 2.5899975;
				};
				class KeyFeatureText72: KeyFeatureText1
				{
					idc = 2071;
					y = 2.6269975;
					text = "";
				};
				class KeyTextBox72: KeyTextBox1
				{
					idc = 2571;
					y = 2.6269975;
					action = "with uiNamespace do { 2571  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText72: SHIFTKeyText1
				{
					idc = 4071;
					y = 2.6269975;
				};
				class CTRLKeyText72: CTRLKeyText1
				{
					idc = 3571;
					y = 2.6269975;
				};
				class ALTKeyText72: ALTKeyText1
				{
					idc = 3071;
					y = 2.6269975;
				};
				class KeyFeatureText73: KeyFeatureText1
				{
					idc = 2072;
					y = 2.6639974;
					text = "";
				};
				class KeyTextBox73: KeyTextBox1
				{
					idc = 2572;
					y = 2.6639974;
					action = "with uiNamespace do { 2572  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText73: SHIFTKeyText1
				{
					idc = 4072;
					y = 2.6639974;
				};
				class CTRLKeyText73: CTRLKeyText1
				{
					idc = 3572;
					y = 2.6639974;
				};
				class ALTKeyText73: ALTKeyText1
				{
					idc = 3072;
					y = 2.6639974;
				};
				class KeyFeatureText74: KeyFeatureText1
				{
					idc = 2073;
					y = 2.7009974;
					text = "";
				};
				class KeyTextBox74: KeyTextBox1
				{
					idc = 2573;
					y = 2.7009974;
					action = "with uiNamespace do { 2573  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText74: SHIFTKeyText1
				{
					idc = 4073;
					y = 2.7009974;
				};
				class CTRLKeyText74: CTRLKeyText1
				{
					idc = 3573;
					y = 2.7009974;
				};
				class ALTKeyText74: ALTKeyText1
				{
					idc = 3073;
					y = 2.7009974;
				};
				class KeyFeatureText75: KeyFeatureText1
				{
					idc = 2074;
					y = 2.7379973;
					text = "";
				};
				class KeyTextBox75: KeyTextBox1
				{
					idc = 2574;
					y = 2.7379973;
					action = "with uiNamespace do { 2574  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText75: SHIFTKeyText1
				{
					idc = 4074;
					y = 2.7379973;
				};
				class CTRLKeyText75: CTRLKeyText1
				{
					idc = 3574;
					y = 2.7379973;
				};
				class ALTKeyText75: ALTKeyText1
				{
					idc = 3074;
					y = 2.7379973;
				};
				class KeyFeatureText76: KeyFeatureText1
				{
					idc = 2075;
					y = 2.7749972;
					text = "";
				};
				class KeyTextBox76: KeyTextBox1
				{
					idc = 2575;
					y = 2.7749972;
					action = "with uiNamespace do { 2575  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText76: SHIFTKeyText1
				{
					idc = 4075;
					y = 2.7749972;
				};
				class CTRLKeyText76: CTRLKeyText1
				{
					idc = 3575;
					y = 2.7749972;
				};
				class ALTKeyText76: ALTKeyText1
				{
					idc = 3075;
					y = 2.7749972;
				};
				class KeyFeatureText78: KeyFeatureText1
				{
					idc = 2076;
					y = 2.8119972;
					text = "";
				};
				class KeyTextBox78: KeyTextBox1
				{
					idc = 2576;
					y = 2.8119972;
					action = "with uiNamespace do { 2576  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText78: SHIFTKeyText1
				{
					idc = 4076;
					y = 2.8119972;
				};
				class CTRLKeyText78: CTRLKeyText1
				{
					idc = 3576;
					y = 2.8119972;
				};
				class ALTKeyText78: ALTKeyText1
				{
					idc = 3076;
					y = 2.8119972;
				};
				class KeyFeatureText79: KeyFeatureText1
				{
					idc = 2077;
					y = 2.848997;
					text = "";
				};
				class KeyTextBox79: KeyTextBox1
				{
					idc = 2577;
					y = 2.848997;
					action = "with uiNamespace do { 2577  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText79: SHIFTKeyText1
				{
					idc = 4077;
					y = 2.848997;
				};
				class CTRLKeyText79: CTRLKeyText1
				{
					idc = 3577;
					y = 2.848997;
				};
				class ALTKeyText79: ALTKeyText1
				{
					idc = 3077;
					y = 2.848997;
				};
				class KeyFeatureText80: KeyFeatureText1
				{
					idc = 2078;
					y = 2.885997;
					text = "";
				};
				class KeyTextBox80: KeyTextBox1
				{
					idc = 2578;
					y = 2.885997;
					action = "with uiNamespace do { 2578  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText80: SHIFTKeyText1
				{
					idc = 4078;
					y = 2.885997;
				};
				class CTRLKeyText80: CTRLKeyText1
				{
					idc = 3578;
					y = 2.885997;
				};
				class ALTKeyText80: ALTKeyText1
				{
					idc = 3078;
					y = 2.885997;
				};
				class KeyFeatureText81: KeyFeatureText1
				{
					idc = 2079;
					y = 2.922997;
					text = "";
				};
				class KeyTextBox81: KeyTextBox1
				{
					idc = 2579;
					y = 2.922997;
					action = "with uiNamespace do { 2579  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText81: SHIFTKeyText1
				{
					idc = 4079;
					y = 2.922997;
				};
				class CTRLKeyText81: CTRLKeyText1
				{
					idc = 3579;
					y = 2.922997;
				};
				class ALTKeyText81: ALTKeyText1
				{
					idc = 3079;
					y = 2.922997;
				};
				class KeyFeatureText82: KeyFeatureText1
				{
					idc = 2080;
					y = 2.959997;
					text = "";
				};
				class KeyTextBox82: KeyTextBox1
				{
					idc = 2580;
					y = 2.959997;
					action = "with uiNamespace do { 2580  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText82: SHIFTKeyText1
				{
					idc = 4080;
					y = 2.959997;
				};
				class CTRLKeyText82: CTRLKeyText1
				{
					idc = 3580;
					y = 2.959997;
				};
				class ALTKeyText82: ALTKeyText1
				{
					idc = 3080;
					y = 2.959997;
				};
				class KeyFeatureText83: KeyFeatureText1
				{
					idc = 2081;
					y = 2.9969969;
					text = "";
				};
				class KeyTextBox83: KeyTextBox1
				{
					idc = 2581;
					y = 2.9969969;
					action = "with uiNamespace do { 2581  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText83: SHIFTKeyText1
				{
					idc = 4081;
					y = 2.9969969;
				};
				class CTRLKeyText83: CTRLKeyText1
				{
					idc = 3581;
					y = 2.9969969;
				};
				class ALTKeyText83: ALTKeyText1
				{
					idc = 3081;
					y = 2.9969969;
				};
				class KeyFeatureText84: KeyFeatureText1
				{
					idc = 2082;
					y = 3.0339968;
					text = "";
				};
				class KeyTextBox84: KeyTextBox1
				{
					idc = 2582;
					y = 3.0339968;
					action = "with uiNamespace do { 2582  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText84: SHIFTKeyText1
				{
					idc = 4082;
					y = 3.0339968;
				};
				class CTRLKeyText84: CTRLKeyText1
				{
					idc = 3582;
					y = 3.0339968;
				};
				class ALTKeyText84: ALTKeyText1
				{
					idc = 3082;
					y = 3.0339968;
				};
				class KeyFeatureText85: KeyFeatureText1
				{
					idc = 2083;
					y = 3.0709968;
					text = "";
				};
				class KeyTextBox85: KeyTextBox1
				{
					idc = 2583;
					y = 3.0709968;
					action = "with uiNamespace do { 2583  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText85: SHIFTKeyText1
				{
					idc = 4083;
					y = 3.0709968;
				};
				class CTRLKeyText85: CTRLKeyText1
				{
					idc = 3583;
					y = 3.0709968;
				};
				class ALTKeyText85: ALTKeyText1
				{
					idc = 3083;
					y = 3.0709968;
				};
				class KeyFeatureText86: KeyFeatureText1
				{
					idc = 2084;
					y = 3.1079967;
					text = "";
				};
				class KeyTextBox86: KeyTextBox1
				{
					idc = 2584;
					y = 3.1079967;
					action = "with uiNamespace do { 2584  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText86: SHIFTKeyText1
				{
					idc = 4084;
					y = 3.1079967;
				};
				class CTRLKeyText86: CTRLKeyText1
				{
					idc = 3584;
					y = 3.1079967;
				};
				class ALTKeyText86: ALTKeyText1
				{
					idc = 3084;
					y = 3.1079967;
				};
				class KeyFeatureText87: KeyFeatureText1
				{
					idc = 2085;
					y = 3.1449966;
					text = "";
				};
				class KeyTextBox87: KeyTextBox1
				{
					idc = 2585;
					y = 3.1449966;
					action = "with uiNamespace do { 2585  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText87: SHIFTKeyText1
				{
					idc = 4085;
					y = 3.1449966;
				};
				class CTRLKeyText87: CTRLKeyText1
				{
					idc = 3585;
					y = 3.1449966;
				};
				class ALTKeyText87: ALTKeyText1
				{
					idc = 3085;
					y = 3.1449966;
				};
				class KeyFeatureText88: KeyFeatureText1
				{
					idc = 2086;
					y = 3.1819966;
					text = "";
				};
				class KeyTextBox88: KeyTextBox1
				{
					idc = 2586;
					y = 3.1819966;
					action = "with uiNamespace do { 2586  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText88: SHIFTKeyText1
				{
					idc = 4086;
					y = 3.1819966;
				};
				class CTRLKeyText88: CTRLKeyText1
				{
					idc = 3586;
					y = 3.1819966;
				};
				class ALTKeyText88: ALTKeyText1
				{
					idc = 3086;
					y = 3.1819966;
				};
				class KeyFeatureText89: KeyFeatureText1
				{
					idc = 2087;
					y = 3.2189965;
					text = "";
				};
				class KeyTextBox89: KeyTextBox1
				{
					idc = 2587;
					y = 3.2189965;
					action = "with uiNamespace do { 2587  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText89: SHIFTKeyText1
				{
					idc = 4087;
					y = 3.2189965;
				};
				class CTRLKeyText89: CTRLKeyText1
				{
					idc = 3587;
					y = 3.2189965;
				};
				class ALTKeyText89: ALTKeyText1
				{
					idc = 3087;
					y = 3.2189965;
				};
				class KeyFeatureText90: KeyFeatureText1
				{
					idc = 2088;
					y = 3.2559965;
					text = "";
				};
				class KeyTextBox90: KeyTextBox1
				{
					idc = 2588;
					y = 3.2559965;
					action = "with uiNamespace do { 2588  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText90: SHIFTKeyText1
				{
					idc = 4088;
					y = 3.2559965;
				};
				class CTRLKeyText90: CTRLKeyText1
				{
					idc = 3588;
					y = 3.2559965;
				};
				class ALTKeyText90: ALTKeyText1
				{
					idc = 3088;
					y = 3.2559965;
				};
				class KeyFeatureText91: KeyFeatureText1
				{
					idc = 2089;
					y = 3.2929964;
					text = "";
				};
				class KeyTextBox91: KeyTextBox1
				{
					idc = 2589;
					y = 3.2929964;
					action = "with uiNamespace do { 2589  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText91: SHIFTKeyText1
				{
					idc = 4089;
					y = 3.2929964;
				};
				class CTRLKeyText91: CTRLKeyText1
				{
					idc = 3589;
					y = 3.2929964;
				};
				class ALTKeyText91: ALTKeyText1
				{
					idc = 3089;
					y = 3.2929964;
				};
				class KeyFeatureText92: KeyFeatureText1
				{
					idc = 2090;
					y = 3.3299963;
					text = "";
				};
				class KeyTextBox92: KeyTextBox1
				{
					idc = 2590;
					y = 3.3299963;
					action = "with uiNamespace do { 2590  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText92: SHIFTKeyText1
				{
					idc = 4090;
					y = 3.3299963;
				};
				class CTRLKeyText92: CTRLKeyText1
				{
					idc = 3590;
					y = 3.3299963;
				};
				class ALTKeyText92: ALTKeyText1
				{
					idc = 3090;
					y = 3.3299963;
				};
				class KeyFeatureText93: KeyFeatureText1
				{
					idc = 2091;
					y = 3.3669963;
					text = "";
				};
				class KeyTextBox93: KeyTextBox1
				{
					idc = 2591;
					y = 3.3669963;
					action = "with uiNamespace do { 2591  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText93: SHIFTKeyText1
				{
					idc = 4091;
					y = 3.3669963;
				};
				class CTRLKeyText93: CTRLKeyText1
				{
					idc = 3591;
					y = 3.3669963;
				};
				class ALTKeyText93: ALTKeyText1
				{
					idc = 3091;
					y = 3.3669963;
				};
				class KeyFeatureText94: KeyFeatureText1
				{
					idc = 2092;
					y = 3.4039962;
					text = "";
				};
				class KeyTextBox94: KeyTextBox1
				{
					idc = 2592;
					y = 3.4039962;
					action = "with uiNamespace do { 2592  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText94: SHIFTKeyText1
				{
					idc = 4092;
					y = 3.4039962;
				};
				class CTRLKeyText94: CTRLKeyText1
				{
					idc = 3592;
					y = 3.4039962;
				};
				class ALTKeyText94: ALTKeyText1
				{
					idc = 3092;
					y = 3.4039962;
				};
				class KeyFeatureText95: KeyFeatureText1
				{
					idc = 2093;
					y = 3.4409962;
					text = "";
				};
				class KeyTextBox95: KeyTextBox1
				{
					idc = 2593;
					y = 3.4409962;
					action = "with uiNamespace do { 2593  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText95: SHIFTKeyText1
				{
					idc = 4093;
					y = 3.4409962;
				};
				class CTRLKeyText95: CTRLKeyText1
				{
					idc = 3593;
					y = 3.4409962;
				};
				class ALTKeyText95: ALTKeyText1
				{
					idc = 3093;
					y = 3.4409962;
				};
				class KeyFeatureText96: KeyFeatureText1
				{
					idc = 2094;
					y = 3.477996;
					text = "";
				};
				class KeyTextBox96: KeyTextBox1
				{
					idc = 2594;
					y = 3.477996;
					action = "with uiNamespace do { 2594  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText96: SHIFTKeyText1
				{
					idc = 4094;
					y = 3.477996;
				};
				class CTRLKeyText96: CTRLKeyText1
				{
					idc = 3594;
					y = 3.477996;
				};
				class ALTKeyText96: ALTKeyText1
				{
					idc = 3094;
					y = 3.477996;
				};
				class KeyFeatureText97: KeyFeatureText1
				{
					idc = 2095;
					y = 3.514996;
					text = "";
				};
				class KeyTextBox97: KeyTextBox1
				{
					idc = 2595;
					y = 3.514996;
					action = "with uiNamespace do { 2595  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText97: SHIFTKeyText1
				{
					idc = 4095;
					y = 3.514996;
				};
				class CTRLKeyText97: CTRLKeyText1
				{
					idc = 3595;
					y = 3.514996;
				};
				class ALTKeyText97: ALTKeyText1
				{
					idc = 3095;
					y = 3.514996;
				};
				class KeyFeatureText98: KeyFeatureText1
				{
					idc = 2096;
					y = 3.551996;
					text = "";
				};
				class KeyTextBox98: KeyTextBox1
				{
					idc = 2596;
					y = 3.551996;
					action = "with uiNamespace do { 2596  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText98: SHIFTKeyText1
				{
					idc = 4096;
					y = 3.551996;
				};
				class CTRLKeyText98: CTRLKeyText1
				{
					idc = 3596;
					y = 3.551996;
				};
				class ALTKeyText98: ALTKeyText1
				{
					idc = 3096;
					y = 3.551996;
				};
				class KeyFeatureText99: KeyFeatureText1
				{
					idc = 2097;
					y = 3.588996;
					text = "";
				};
				class KeyTextBox99: KeyTextBox1
				{
					idc = 2597;
					y = 3.588996;
					action = "with uiNamespace do { 2597  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText99: SHIFTKeyText1
				{
					idc = 4097;
					y = 3.588996;
				};
				class CTRLKeyText99: CTRLKeyText1
				{
					idc = 3597;
					y = 3.588996;
				};
				class ALTKeyText99: ALTKeyText1
				{
					idc = 3097;
					y = 3.588996;
				};
				class KeyFeatureText100: KeyFeatureText1
				{
					idc = 2098;
					y = 3.6259959;
					text = "";
				};
				class KeyTextBox100: KeyTextBox1
				{
					idc = 2598;
					y = 3.6259959;
					action = "with uiNamespace do { 2598  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText100: SHIFTKeyText1
				{
					idc = 4098;
					y = 3.6259959;
				};
				class CTRLKeyText100: CTRLKeyText1
				{
					idc = 3598;
					y = 3.6259959;
				};
				class ALTKeyText100: ALTKeyText1
				{
					idc = 3098;
					y = 3.6259959;
				};
				class KeyFeatureText101: KeyFeatureText1
				{
					idc = 2099;
					y = 3.6629958;
					text = "";
				};
				class KeyTextBox101: KeyTextBox1
				{
					idc = 2599;
					y = 3.6629958;
					action = "with uiNamespace do { 2599  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText101: SHIFTKeyText1
				{
					idc = 4099;
					y = 3.6629958;
				};
				class CTRLKeyText101: CTRLKeyText1
				{
					idc = 3599;
					y = 3.6629958;
				};
				class ALTKeyText101: ALTKeyText1
				{
					idc = 3099;
					y = 3.6629958;
				};
				class KeyFeatureText102: KeyFeatureText1
				{
					idc = 2100;
					y = 3.6999958;
					text = "";
				};
				class KeyTextBox102: KeyTextBox1
				{
					idc = 2600;
					y = 3.6999958;
					action = "with uiNamespace do { 2600  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText102: SHIFTKeyText1
				{
					idc = 4100;
					y = 3.6999958;
				};
				class CTRLKeyText102: CTRLKeyText1
				{
					idc = 3600;
					y = 3.6999958;
				};
				class ALTKeyText102: ALTKeyText1
				{
					idc = 3100;
					y = 3.6999958;
				};
				class KeyFeatureText103: KeyFeatureText1
				{
					idc = 2101;
					y = 3.7369957;
					text = "";
				};
				class KeyTextBox103: KeyTextBox1
				{
					idc = 2601;
					y = 3.7369957;
					action = "with uiNamespace do { 2601  call ace_settings_fnc_linkbuttonclicked}";
				};
				class SHIFTKeyText103: SHIFTKeyText1
				{
					idc = 4101;
					y = 3.7369957;
				};
				class CTRLKeyText103: CTRLKeyText1
				{
					idc = 3601;
					y = 3.7369957;
				};
				class ALTKeyText103: ALTKeyText1
				{
					idc = 3101;
					y = 3.7369957;
				};
			};
		};
		class OneKeyChanger: ACE_SD_RscControlsGroup
		{
			x = 0.329816;
			y = "SafezoneY + 0.09 * safezoneW";
			w = 0.630743;
			h = "SafezoneH * 0.75";
			idc = 6000;
			class Controls
			{
				class FeatureToChangeCaption: ACE_SD_RscText2
				{
					idc = 6001;
					x = 0;
					y = 0;
					w = 0.4;
					h = 0.023;
					colorBackground[] = {1,1,1,0};
					colorText[] = {1,1,1,1};
					sizeEx = 0.025;
					text = "";
				};
				class HelpText: ACE_SD_RscText2
				{
					x = 0;
					y = 0.05;
					w = 0.2;
					h = 0.023;
					sizeEx = 0.023;
					text = "$STR_SETTINGS_KEYSHELP2";
				};
				class KeyHelp2: HelpText
				{
					x = 0.19;
					y = 0.049;
					w = 0.3;
					text = "$STR_SETTINGS_KEYSHELP3";
				};
				class KeyPressedText: ACE_SD_RscText2
				{
					idc = 6002;
					x = 0;
					y = "0.12b";
					w = 0.2;
					h = 0.06;
					style = 2;
					colorBackground[] = {1,1,1,0};
					colorText[] = {1,1,1,1};
					sizeEx = 0.031;
					text = "";
				};
				class AcceptButton: ACE_ButtonBase
				{
					text = "$STR_BUTTONS_SAVE";
					x = 0;
					y = 0.19;
					w = 0.226917;
					h = 0.103604;
					action = "1 call (uiNamespace getVariable 'ace_settings_fnc_OneKeyChangerButtons')";
				};
				class DiscardButton: AcceptButton
				{
					text = "$STR_BUTTONS_CANCEL";
					x = 0.24;
					action = "0 call (uiNamespace getVariable 'ace_settings_fnc_OneKeyChangerButtons')";
				};
				class ShiftCB: ACE_SD_RscPicture
				{
					idc = 7005;
					x = "0.19 + 0.1";
					y = 0.09;
					w = 0.035;
					h = 0.035;
					colorText[] = {0,0,0,0.5};
					colorBackground[] = {0,0,0,0};
					text = "\x\ace\addons\settings\data\shift_ca.paa";
				};
				class ShiftLB: ACE_LinkButtonBase
				{
					idc = 6005;
					x = "0.19 + 0.1";
					y = 0.09;
					w = 0.035;
					h = 0.035;
					text = "";
					colorText[] = {1,0,0,0};
					action = "2 call (uiNamespace getVariable 'ace_settings_fnc_OneKeyChangerButtons')";
				};
				class CtrlCB: ShiftCB
				{
					idc = 7006;
					y = 0.13;
					text = "\x\ace\addons\settings\data\ctrl_ca.paa";
				};
				class CtrlLB: ShiftLB
				{
					idc = 6006;
					y = 0.13;
					text = "$STR_SETTINGS_KEYS_WC";
					action = "3 call (uiNamespace getVariable 'ace_settings_fnc_OneKeyChangerButtons')";
				};
				class AltCB: ShiftCB
				{
					idc = 7007;
					y = 0.17;
					text = "\x\ace\addons\settings\data\alt_ca.paa";
				};
				class AltLB: ShiftLB
				{
					idc = 6007;
					y = 0.17;
					text = "$STR_SETTINGS_KEYS_WA";
					action = "4 call (uiNamespace getVariable 'ace_settings_fnc_OneKeyChangerButtons')";
				};
			};
		};
	};
};
class RscTitles
{
	class ACE_SettingsMainMenu_Feedback
	{
		idd = -1;
		movingEnable = "true";
		fadein = 0;
		fadeout = 3;
		duration = 9;
		name = "ACE_SettingsMainMenu_Feedback";
		class controls
		{
			class TextStr
			{
				type = 0;
				idc = -1;
				style = 0;
				x = "SafeZoneX + 0.025";
				y = "SafeZoneY + SafeZoneH - 0.31";
				w = 2;
				h = 0.3;
				font = "Zeppelin32";
				sizeEx = 0.03;
				colorText[] = {1.0,1.0,1.0,0.9};
				colorBackground[] = {0,0,0,0.0};
				text = "$STR_UCFG_SAVED";
			};
		};
	};
	class ACE_SettingsMainMenu_Feedback2
	{
		idd = -1;
		movingEnable = "true";
		fadein = 0;
		fadeout = 3;
		duration = 9;
		name = "ACE_SettingsMainMenu_Feedback";
		class controls
		{
			class TextStr
			{
				type = 0;
				idc = -1;
				style = 0;
				x = "SafeZoneX + 0.025";
				y = "SafeZoneY + SafeZoneH - 0.31";
				w = 2;
				h = 0.3;
				font = "Zeppelin32";
				sizeEx = 0.03;
				colorText[] = {1.0,1.0,1.0,0.9};
				colorBackground[] = {0,0,0,0.0};
				text = "$STR_UCFG_SAVED2";
			};
		};
	};
};
class CfgSettings
{
	class ace
	{
		class ACE_SIGHT_ADJUSTMENT_RIFLE_CONFIG
		{
			enable_BDC = 1;
		};
		class ACE_WIND_CONFIG
		{
			enable_drift = 1;
		};
		class ACE_RECOGNITION
		{
			Scanning_Method = 2;
		};
		class ACE_WEAPONSELECT
		{
			firemodes_only = 0;
		};
		class ACE_STANCEINDICATOR
		{
			enabled = 0;
		};
		class ACE_ROUNDCOUNT
		{
			show_icon = 1;
		};
		class sys_cartridges
		{
			enabled = 0;
		};
		class sys_grenadethrow2
		{
			enabled = 0;
		};
		class sys_immersive_dismount
		{
			enabled = 1;
		};
		class sys_wounds
		{
			sp_player_medic = 0;
		};
		class sys_handsignals
		{
			background_enabled = 0;
		};
		class sys_air_rwr
		{
			resource_pos = 0;
		};
		class sys_grenadethrow
		{
			cursor_type = 2;
			switch_to_weapon = 0;
			reset_mode = 0;
			swap_mouse_buttons = 0;
			fast_throw_ampl = 1;
			holding_ampl_gain = 0.6;
		};
		class sys_interaction
		{
			toggle = 0;
		};
	};
	class CBA
	{
		class events
		{
			class ace_sys_afterburner
			{
				class Afterburner
				{
					key = 58;
				};
			};
			class ace_sys_ofpec_ils
			{
				class ILS
				{
					key = 37;
				};
			};
			class ace_sys_sight_adjustment_at
			{
				class Elevation_Up
				{
					key = 200;
				};
				class Elevation_Down
				{
					key = 208;
				};
			};
			class ace_sys_sight_adjustment_rifle
			{
				class Open_Adjustment_Dialog
				{
					key = 47;
					shift = 1;
				};
				class Elevation_Up
				{
					key = 200;
				};
				class Elevation_Down
				{
					key = 208;
				};
				class Windage_Left
				{
					key = 203;
				};
				class Windage_Right
				{
					key = 205;
				};
			};
			class ace_sys_sight_adjustment_gl
			{
				class Toggle_Elevation_Info
				{
					key = 82;
					shift = 1;
				};
				class Elevation_Up
				{
					key = 200;
				};
				class Elevation_Down
				{
					key = 208;
				};
			};
			class ace_sys_nvg
			{
				class brightnessUP
				{
					key = 201;
				};
				class brightnessDOWN
				{
					key = 209;
				};
			};
			class ace_sys_overheating
			{
				class Unjam
				{
					key = 19;
					shift = 1;
				};
			};
			class ace_sys_weaponrest
			{
				class Rest_weapon
				{
					key = 57;
					shift = 1;
				};
			};
			class ace_sys_interaction
			{
				class Interaction_Menu
				{
					key = 220;
					shift = 0;
				};
				class Self_Interaction_Menu
				{
					key = 221;
					shift = 0;
				};
				class TapShoulder
				{
					key = 20;
					shift = 1;
				};
				class KnockDown
				{
					key = 37;
					shift = 1;
					ctrl = 1;
				};
			};
			class ace_sys_wind_deflection
			{
				class Toggle_Wind_Info
				{
					key = 37;
					shift = 1;
				};
			};
			class ace_sys_stamina
			{
				class Panic_Button
				{
					key = 69;
				};
			};
			class ace_sys_rangefinder
			{
				class Toggle_Power
				{
					key = 19;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class Cycle_Mils
				{
					key = 19;
					shift = 0;
					ctrl = 0;
					alt = 1;
				};
				class Preload_Battery
				{
					key = 19;
					shift = 1;
					ctrl = 1;
					alt = 1;
					always = 1;
				};
				class LaserCode_Up
				{
					key = 205;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
				class LaserCode_Down
				{
					key = 203;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
			};
			class ace_sys_maptools
			{
				class Place_Ruler
				{
					key = 35;
				};
				class Align_Ruler
				{
					key = 36;
				};
				class Start_Drawing
				{
					key = 26;
				};
				class End_Straight_Line
				{
					key = 27;
				};
				class Delete_Line
				{
					key = 43;
				};
			};
			class ace_sys_air_fcs
			{
				class Lase
				{
					key = 15;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
			};
			class ace_sys_tankfcs
			{
				class Lase
				{
					key = 15;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class Battlesight
				{
					key = 48;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class Dump
				{
					key = 37;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
			};
			class ace_sys_missileguidance
			{
				class Lase_Kh29
				{
					key = 57;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class Lase_Gunship
				{
					key = 38;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class Javelin_Mode
				{
					key = 15;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class Longbow_Map
				{
					key = 15;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
				class Lase_Kh29_Up
				{
					key = 200;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class Lase_Kh29_Down
				{
					key = 208;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class Lase_Kh29_Left
				{
					key = 203;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class Lase_Kh29_Right
				{
					key = 205;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
			};
			class ace_sys_air_hud
			{
				class Pickle_Weapon
				{
					key = 57;
					shift = 1;
					ctrl = 1;
					alt = 0;
				};
			};
			class ace_sys_dagr
			{
				class Toggle_dagr
				{
					key = 199;
					shift = 0;
				};
				class Toggle_dagr_mode
				{
					key = 199;
					shift = 0;
					ctrl = 1;
				};
				class Dagr_Menu
				{
					key = 199;
					shift = 1;
				};
			};
			class ace_sys_roundcount
			{
				class Roundcount
				{
					key = 40;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
			};
			class ace_sys_weaponselect
			{
				class Safe
				{
					key = 41;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
				class Rifle
				{
					key = 2;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
				class GL
				{
					key = 3;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
				class Throw
				{
					key = 4;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
				class Launcher
				{
					key = 5;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
				class Firemodes
				{
					key = 33;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class Gunlight_Change
				{
					key = 38;
					shift = 0;
					ctrl = 0;
					alt = 1;
				};
				class Vehicle_Safe
				{
					key = 41;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
				class Vehicle_Main
				{
					key = 2;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
				class Vehicle_Launcher
				{
					key = 3;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
				class Vehicle_Other
				{
					key = 3;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
			};
			class ace_sys_playerhud
			{
				class quick_mag_check
				{
					key = 34;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
			};
			class ace_sys_ruck
			{
				class quick_ruck_check
				{
					key = 34;
					shift = 0;
					ctrl = 0;
					alt = 1;
				};
				class drag_nearest_ruck
				{
					key = 32;
					shift = 1;
					ctrl = 1;
					alt = 1;
				};
			};
			class ace_sys_mfd
			{
				class Toggle_MFD_Open
				{
					key = 16;
					shift = 1;
					ctrl = 1;
					alt = 0;
				};
			};
			class ace_sys_handsignals
			{
				class Mouse_Gesture
				{
					key = 15;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class HS_STOP
				{
					key = 79;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class HS_GO
				{
					key = 75;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class HS_COVER
				{
					key = 71;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class HS_ATTACK
				{
					key = 80;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class HS_CEASEFIRE
				{
					key = 76;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class HS_FOLLOW
				{
					key = 72;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class HS_UP
				{
					key = 81;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class HS_ADVANCE
				{
					key = 77;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class HS_POINT
				{
					key = 73;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
			};
			class ace_sys_reticles
			{
				class Reticle_Illum
				{
					key = 38;
					shift = 1;
					ctrl = 0;
					alt = 0;
				};
				class Veh_Reticle_Up
				{
					key = 200;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
				class Veh_Reticle_Down
				{
					key = 208;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
			};
			class ace_sys_grenadethrow2
			{
				class Under_Hand
				{
					key = 42;
					shift = 0;
					ctrl = 0;
					alt = 0;
				};
			};
			class ace_sys_vehicle
			{
				class Odometer_Start
				{
					key = 210;
					shift = 0;
					ctrl = 1;
					alt = 0;
				};
				class Odometer_Stop
				{
					key = 211;
					shift = 0;
					ctrl = 1;
					alt = 0;
				};
			};
			ACE_KEYS_VER = 8;
		};
	};
};
//};
