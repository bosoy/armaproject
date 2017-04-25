class CfgPatches
{
	class ace_main
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_XEH","CBA_OA_XEH","CBA_MAIN","CBA_OA_MAIN","CA_Modules","CAFonts","CorePatch","CorePatch2","anti_core_patch"};
		author[] = {"ACE Team"};
		authorUrl = "http://ace.dev-heaven.net";
		versionDesc = "A.C.E.";
		versionAct = "['MAIN',_this] execVM '\x\ace\addons\main\about.sqf';";
		version = "1.14.0.597";
		versionStr = "1.14.0.597";
		versionAr[] = {1,14,0,597};
	};
	class ace_c_men_ruckless
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
	class ace_settings_no_intro
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
	class ace_settings_recognize
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
	class ace_settings_staying_brass
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
	class ace_settings_ruckless
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
	class ace_settings_no_radio_chat
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
	class ace_settings_crosshair
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
	class ace_settings_identities
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
	class ace_settings_immersive_dismount
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
	class ace_sys_bi_arty
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
	class ace_sys_nuke
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
	class ace_c_men_sounds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
	class acex_veh_static
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = "1.14.0.597";
		ace_bwc = 1;
	};
};
class CfgMods
{
	class ace
	{
		dir = "@ACE";
		name = "Core - Advanced Combat Environment";
		picture = "ca\ui\data\logo_arma2ep1_ca.paa";
		hidePicture = "true";
		hideName = "true";
		actionName = "Website";
		action = "http://ace.dev-heaven.net";
		description = "Bugtracker: http://dev-heaven.net/projects/ace-mod2<br />Documentation: http://ace.dev-heaven.net";
	};
};
class CfgSettings
{
	class CBA
	{
		class Versioning
		{
			class ace
			{
				level = 2;
				handler = "ace_main_fnc_mismatch";
				class Dependencies
				{
					CBA[] = {"cba_main",{ 1,0,0 },"true"};
					XEH[] = {"cba_xeh",{ 1,0,0 },"true"};
				};
			};
		};
	};
};
class CfgSounds
{
	class ACE_VERSION_DING
	{
		name = "ACE_VERSION_DING";
		sound[] = {"\x\ace\addons\main\sound\ace_version_ding.ogg","db+10",1};
		titles[] = {};
	};
};
class CfgAmmo
{
	class Default;
};
class CfgMagazines
{
	class Default
	{
		class ACE{};
	};
};
class CfgWeapons
{
	class Default
	{
		class ACE{};
	};
	class ItemCore;
	class ACE_Obsolete_Item: ItemCore
	{
		scope = 1;
		displayName = "OBSOLETE ITEM";
		displayNameShort = "OBSOLETE ITEM";
		picture = "\x\ace\addons\main\data\obsolete\icon_obsolete_ca.paa";
		model = "\x\ace\addons\main\data\obsolete\obsolete.p3d";
		class Armory
		{
			disabled = 0;
		};
	};
	class ACE_JerryCan_Dummy: ACE_Obsolete_Item
	{
		displayName = "Banana";
		ACE_Size = 1;
		ACE_Weight = 1;
		picture = "\x\ace\addons\main\data\obsolete\icon_banana_ca.paa";
		model = "\x\ace\addons\main\data\obsolete\banana.p3d";
	};
	class ACE_JerryCan_Dummy_15: ACE_JerryCan_Dummy
	{
		scope = 2;
	};
};
class RscStandardDisplay;
class RscText;
class RscPicture;
class RscActiveText;
class RscStructuredText;
class RscEdit;
class RscButton_small;
class RscShortcutButton;
class RscButton;
class RscLine;
class CA_Title;
class RscControlsGroup;
class RscFrame;
class ACE_MenuRscShortcutButton: RscShortcutButton
{
	idc = -1;
	style = 0;
	default = 0;
	w = 0.28;
	h = 0.052;
	color[] = {0.95,0.95,0.95,1};
	colorDisabled[] = {0.95,0.95,0.95,0.25};
	class HitZone
	{
		left = 0.0;
		top = 0.0;
		right = 0.0;
		bottom = 0.0;
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
		left = 0.01;
		top = 0;
		right = 0.005;
		bottom = 0.005;
	};
	animTextureNormal = "#(argb,8,8,3)color(1,1,1,0)";
	animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0)";
	animTextureOver = "#(argb,8,8,3)color(1,1,1,0.2)";
	animTextureFocused = "#(argb,8,8,3)color(1,1,1,0)";
	animTexturePressed = "#(argb,8,8,3)color(1,1,1,0.5)";
	animTextureDefault = "#(argb,8,8,3)color(1,1,1,0)";
	period = 0.5;
	font = "Zeppelin32";
	size = 0.051;
	sizeEx = 0.05;
	text = "";
	soundEnter[] = {"\ca\ui\data\sound\onover",0.09,1};
	soundPush[] = {"\ca\ui\data\sound\new1",0.0,0};
	soundClick[] = {"\ca\ui\data\sound\onclick",0.07,1};
	soundEscape[] = {"\ca\ui\data\sound\onescape",0.09,1};
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
	toolTip = "";
};
class ACE_ABOUT_CTRL: RscActiveText
{
	idc = -1;
	style = "0x02+ 0x04+ 0x100";
	x = "(0.025 * safeZoneW) + safeZoneX";
	y = "(0.92 * safeZoneH) + safeZoneY";
	w = "0.04 * safeZoneW";
	h = "0.02 * safeZoneH";
	sizeEx = "0.025 * SafeZoneH";
	color[] = {0.8784,0.8471,0.651,1};
	colorActive[] = {0.543,0.5742,0.4102,1};
	text = "About";
	onButtonClick = "";
};
class ACE_ABOUT_NEXT: ACE_ABOUT_CTRL
{
	idc = -1;
	style = 48;
	x = "(0.065 * safeZoneW) + safeZoneX";
	w = "0.03 * safeZoneW";
	text = "x\ace\addons\main\data\clear.paa";
	onButtonClick = "ACE_ABOUT_INC = 1;";
};
class RscShortcutButtonMain;
class RscDisplayMain: RscStandardDisplay
{
	onLoad = "['onLoad',_this,'RscDisplayMain'] call compile preprocessFile '\x\ace\addons\main\adjustDispmain.sqf'";
	onUnload = "['onUnload',_this,'RscDisplayMain'] call compile preprocessFile '\x\ace\addons\main\adjustDispmain.sqf'";
	class controls
	{
		delete CA_TitleMainMenu;
		delete CA_SinglePlayer;
		delete CA_MP;
		delete CA_Options;
		delete CA_PlayerProfile;
		delete CA_Expansions;
		delete CA_Exit;
		delete CA_PlayerName;
		delete CA_ModList;
		delete ModIcons;
		delete cwr2_multi;
		delete cwr2_single;
		delete cwr2_Editor;
		delete cwr2_exp;
		delete cwr2_profile;
		delete cwr2_options;
		delete cwr2_Exit;
		class ACE_TitleMainMenu: CA_Title
		{
			idc = 1003;
			x = 0.01;
			y = 0.192;
			w = 0.28;
			sizeEx = 0.08;
			text = "$STR_DISP_MAIN_MENU";
		};
		class ACE_SinglePlayer: ACE_MenuRscShortcutButton
		{
			idc = 138;
			default = 1;
			x = 0.01;
			y = 0.35;
			toolTip = "$STR_TOOLTIP_MAIN_SINGLEPLAYER";
			text = "$STR_DISP_MAIN_SINGLE_PLAYER";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_MP: ACE_SinglePlayer
		{
			idc = 105;
			default = 0;
			y = 0.41;
			toolTip = "$STR_TOOLTIP_MAIN_MULTIPLAYER";
			text = "$STR_CA_MAIN_MULTI";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_GameOptions: ACE_MP
		{
			idc = 102;
			default = 0;
			y = 0.47;
			action = "";
			toolTip = "$STR_TOOLTIP_MAIN_OPTIONS";
			text = "$STR_CA_MAIN_OPTIONS";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_Options: ACE_MP
		{
			idc = 768;
			default = 0;
			y = 0.53;
			action = "uiNamespace setVariable ['ace_main_normal_settingsdialog', false];if (isNil {uiNamespace getVariable 'ace_settings_settings'}) then {call compile preprocessFileLineNumbers '\x\ace\addons\settings\initall.sqf'};(uiNamespace getVariable 'ace_main_main_display') createDisplay 'ACE_SettingsDialog'";
			toolTip = "Configure ACE options";
			text = "$STR_ACE_SETTINGS";
		};
		class ACE_PlayerProfile: ACE_MP
		{
			idc = 1001;
			y = 0.59;
			onButtonClick = "_display = ctrlParent (_this select 0);  _ctrl109 =_display displayCtrl 109; ctrlActivate _ctrl109; debuglog _ctrl109";
			toolTip = "$STR_TOOLTIP_MAIN_PLAYER";
			text = "$STR_DISP_PROFILE";
			class KeyHints{};
		};
		class ACE_Expansions: ACE_MP
		{
			idc = 140;
			y = 0.65;
			action = "";
			toolTip = "$STR_TOOLTIP_MAIN_EXPANSIONS";
			text = "$STR_DISP_EXPANSIONS";
			class KeyHints{};
		};
		class ACE_Exit: ACE_MP
		{
			idc = 106;
			y = 0.8;
			shortcuts[] = {"0x00050000 + 3"};
			text = "$STR_CA_MAIN_QUIT";
			toolTip = "$STR_TOOLTIP_MAIN_EXIT";
		};
		class ACE_CA_ModList: RscStructuredText
		{
			idc = 139;
			style = 1;
			x = "(SafeZoneW + SafeZoneX) - (0.53)";
			y = "SafeZoneY + 0.2091503*1.5";
			w = 0.5;
			h = 0.5;
			size = 0.02674;
			class Attributes
			{
				font = "Zeppelin32";
				color = "#dfd7a5";
				align = "right";
				shadow = 0;
			};
		};
		class ACE_ModIcons: RscControlsGroup
		{
			idc = 141;
			x = "SafeZoneX+0.03";
			y = "(SafeZoneH + SafeZoneY) - (0.113*SafeZoneH)";
			w = 0.8;
			h = 0.2;
			class Controls{};
		};
		class ACE_OptionsCWR: ACE_MenuRscShortcutButton
		{
			colorText[] = {1,1,1,1};
			default = 0;
			font = "Zeppelin32";
			idc = 769;
			sizeEx = 0.034;
			style = "0x00";
			text = "ACE SETTINGS";
			toolTip = "Configure ACE options";
			type = 11;
			w = 0.25;
			x = "(1.0/1.945)";
			y = 0.615;
			color[] = {1,1,1,1};
			colorActive[] = {0.3,0.4,0,1};
			colorBackground[] = {0.5,0.5,0.5,0};
			shadow = 0;
			shadowColor = "#000000";
			shadowOffset = 0;
			action = "uiNamespace setVariable ['ace_main_normal_settingsdialog', false];(uiNamespace getVariable 'ace_main_main_display') createDisplay 'ACE_SettingsDialog'";
		};
		class ACE_CA_PlayerName: RscText
		{
			idc = 109;
			style = 256;
			colorbackground[] = {0.1,0.1,0.1,0};
			x = 0.01;
			y = 0.25;
			w = 0.5;
			h = 0.05;
		};
	};
	class controlsBackground
	{
		delete Mainback;
		delete CWR2_Hline;
		delete CWR2_Vline;
		class vertical_line: RscLine
		{
			x = 0.002;
			y = "SafeZoneY";
			w = 0;
			h = "SafeZoneY + SafeZoneH - 0.02;";
			colorText[] = {1,1,1,1};
		};
	};
};
class RscDisplayInterrupt: RscStandardDisplay
{
	onLoad = "['onLoad',_this,'RscDisplayInterrupt'] call compile preprocessFile '\x\ace\addons\main\adjust.sqf'";
	class controlsBackground
	{
		class vertical_line: RscLine
		{
			x = 0.002;
			y = "SafeZoneY";
			w = 0;
			h = "SafeZoneY + SafeZoneH - 0.02;";
			colorText[] = {1,1,1,1};
		};
		delete Mainback;
	};
	class controls
	{
		class ACE_PGTitle: CA_Title
		{
			idc = 523;
			x = 0.01;
			y = 0.192;
			sizeEx = 0.08;
			text = "$STR_DISP_INT_TITLE";
		};
		class ACE_PG_Save: ACE_MenuRscShortcutButton
		{
			idc = 103;
			x = 0.01;
			y = 0.35;
			text = "$STR_DISP_INT_SAVE";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_PG_Skip: ACE_PG_Save
		{
			idc = 1002;
			y = 0.41;
			text = "$STR_DISP_INT_SKIP";
			onButtonClick = "private ['_dummy']; _dummy = [_this,'skip'] call compile preprocessFile '\ca\ui\scripts\pauseCutScene.sqf'";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_PG_Revert: ACE_PG_Save
		{
			idc = 119;
			y = 0.47;
			text = "$str_disp_revert";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_PG_Again: ACE_PG_Revert
		{
			idc = 1003;
			text = "$STR_DISP_INT_AGAIN";
			onButtonClick = "private ['_dummy']; _dummy = [_this,'again'] call compile preprocessFile '\ca\ui\scripts\pauseCutScene.sqf'";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_PG_Options: ACE_PG_Save
		{
			idc = 101;
			shortcuts[] = {};
			y = 0.53;
			text = "$STR_DISP_INT_OPTIONS";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_SETTINGS: ACE_PG_Save
		{
			idc = 113801;
			y = 0.59;
			text = "$STR_ACE_SETTINGS";
			action = "uiNamespace setVariable ['ace_main_normal_settingsdialog', true];createdialog 'ACE_SettingsDialog'";
		};
		class ACE_PG_Abort: ACE_PG_Save
		{
			idc = 104;
			shortcuts[] = {};
			y = 0.67;
			text = "$STR_DISP_INT_ABORT";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_ButtonCancel: ACE_PG_Save
		{
			idc = 2;
			shortcuts[] = {"0x00050000 + 1","0x00050000 + 8"};
			y = 0.8;
			text = "$STR_DISP_INT_CONTINUE";
		};
		class ACE_DebugConsole: ACE_PG_Save
		{
			idc = 1212;
			shortcuts[] = {};
			y = 0.9;
			text = "Debug Console";
			action = "createdialog 'ACE_MP_Debug_Console';";
		};
		class ACE_MissionTitle: RscText
		{
			idc = 120;
			x = 0.01;
			y = 0.25;
			w = 0.5;
			text = "";
		};
		class ACE_DifficultyTitle: RscText
		{
			idc = 121;
			x = 0.01;
			y = 0.29;
			text = "";
		};
		class ACE_ABOUT_CTRL: ACE_ABOUT_CTRL
		{
			idc = -1;
			onButtonClick = "['SING',_this] execVM '\x\ace\addons\main\about.sqf'";
		};
		class ACE_ABOUT_NEXT: ACE_ABOUT_NEXT
		{
			idc = -1;
		};
		delete MissionTitle;
		delete DifficultyTitle;
		delete CA_PGTitle;
		delete PG_Skip;
		delete PG_Again;
		delete PG_Revert;
		delete PG_Options;
		delete PG_Abort;
		delete PG_Save;
		delete ButtonCancel;
		delete HintA_Select;
	};
};
class RscDisplayMPInterrupt: RscStandardDisplay
{
	onLoad = "['onLoad',_this,'RscDisplayMPInterrupt'] call compile preprocessFile '\x\ace\addons\main\adjustMP.sqf';with uiNameSpace do {ACE_Main_Debug_RSC = _this select 0};[] spawn ace_main_fnc_debugadd;['Init', _this] execVM '\ca\ui\scripts\pauseLoadinit.sqf'";
	class controlsBackground
	{
		class vertical_line: RscLine
		{
			x = 0.002;
			y = "SafeZoneY";
			w = 0;
			h = "SafeZoneY + SafeZoneH - 0.02;";
			colorText[] = {1,1,1,1};
		};
		delete Mainback;
	};
	class controls
	{
		delete MissionTitle;
		delete DifficultyTitle;
		delete Paused_Title;
		delete CA_B_Skip;
		delete CA_B_REVERT;
		delete CA_B_Respawn;
		delete CA_B_Options;
		delete CA_B_Abort;
		delete CA_B_SAVE;
		delete ButtonCancel;
		class ACE_MissionTitle: RscText
		{
			idc = 120;
			x = 0.01;
			y = 0.25;
			w = 0.5;
			text = "";
		};
		class ACE_DifficultyTitle: RscText
		{
			idc = 121;
			x = 0.01;
			y = 0.29;
			text = "";
		};
		class ACE_Paused_Title: CA_Title
		{
			idc = 523;
			x = 0.01;
			y = 0.192;
			sizeEx = 0.08;
			text = "$STR_DISP_MAIN_MULTI";
		};
		class ACE_CA_B_SAVE: ACE_MenuRscShortcutButton
		{
			idc = 103;
			x = 0.01;
			y = 0.35;
			text = "$STR_DISP_INT_SAVE";
		};
		class ACE_CA_B_Skip: ACE_CA_B_SAVE
		{
			idc = 1002;
			text = "$STR_DISP_INT_SKIP";
		};
		class ACE_CA_B_REVERT: ACE_CA_B_SAVE
		{
			idc = 119;
			y = 0.41;
			text = "$str_disp_revert";
		};
		class ACE_CA_B_Options: ACE_CA_B_SAVE
		{
			idc = 101;
			y = 0.47;
			text = "$STR_DISP_INT_OPTIONS";
		};
		class ACE_SETTINGS: ACE_CA_B_SAVE
		{
			idc = 113801;
			y = 0.53;
			text = "$STR_ACE_SETTINGS";
			action = "uiNamespace setVariable ['ace_main_normal_settingsdialog', true];createdialog 'ACE_SettingsDialog';";
		};
		class ACE_CA_B_Abort: ACE_CA_B_SAVE
		{
			idc = 104;
			y = 0.65;
			text = "$STR_DISP_INT_ABORT";
		};
		class ACE_ButtonCancel: ACE_CA_B_SAVE
		{
			idc = 2;
			shortcuts[] = {"0x00050000 + 1","0x00050000 + 8"};
			default = 1;
			y = 0.77;
			text = "$STR_DISP_INT_CONTINUE";
		};
		class ACE_CA_B_Respawn: ACE_CA_B_SAVE
		{
			idc = 1010;
			onButtonClick = "createDialog 'ACE_RESPAWN_DIALOG'";
			y = 0.89;
			text = "$STR_DISP_INT_RESPAWN";
			colorText[] = {1,0,0,1};
		};
		class ACE_ABOUT_CTRL: ACE_ABOUT_CTRL
		{
			idc = -1;
			onButtonClick = "['MULT',_this] execVM '\x\ace\addons\main\about.sqf'";
		};
		class ACE_ABOUT_NEXT: ACE_ABOUT_NEXT
		{
			idc = -1;
		};
		class ACE_DEBUG_CTRL: ACE_ABOUT_CTRL
		{
			idc = 1100;
			x = "(0.095 * safeZoneW) + safeZoneX";
			w = "0.11 * safeZoneW";
			text = "ACE Debug Console";
			onButtonClick = "(findDisplay 49) closeDisplay 0;createDialog 'ACE_MP_Debug_Console'";
		};
	};
};
class RscDisplaySingleplayer
{
	class controlsBackground
	{
		delete Mainback;
		delete MainbackFaded;
		delete vertline;
		delete CWR2_Hline;
		delete CWR2_Vline;
		class vertical_line: RscLine
		{
			x = 0.002;
			y = "SafeZoneY";
			w = 0;
			h = "SafeZoneH";
			colorText[] = {1,1,1,1};
		};
	};
	class controls
	{
		delete CA_Missions;
		delete CA_Training;
		delete CA_Library;
		delete CA_Editor;
		delete CA_Campaign;
		delete CA_EditProfileTitle;
		delete ButtonCancel;
		delete HintX_Select;
		delete cwr2_Title;
		delete cwr2_Library;
		delete cwr2_training;
		delete cwr2_missions;
		delete cwr2_campaign;
		delete cwr2_editor;
		delete cwr2_back;
		class ACE_EditProfileTitle: CA_Title
		{
			x = 0.01;
			y = 0.192;
			w = 0.28;
			sizeEx = 0.08;
			text = "$STR_DISP_MAIN_SINGLE_PLAYER";
		};
		class ACE_Campaign: ACE_MenuRscShortcutButton
		{
			idc = 104;
			x = 0.01;
			y = 0.35;
			text = "$STR_DISP_MAIN_XBOX_CAMPAIGN";
			toolTip = "$STR_TOOLTIP_SINGLEPLAYER_CAMPAIGN";
			action = "uiNamespace setVariable ['ace_editor_debugc_available', nil]";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_Missions: ACE_Campaign
		{
			idc = 103;
			y = 0.41;
			text = "$STR_DISP_MAIN_SINGLE";
			toolTip = "$STR_TOOLTIP_SINGLEPLAYER_MISSIONS";
			action = "uiNamespace setVariable ['ace_editor_debugc_available', nil]";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_Training: ACE_Campaign
		{
			idc = 101;
			y = 0.47;
			action = "uiNamespace setVariable ['ace_editor_debugc_available', nil];_displayParent = findDisplay 140; _displayMission = _displayParent createMissionDisplay ['','tutorial']";
			default = 1;
			text = "$STR_DISP_MAIN_TRAINING";
			toolTip = "$STR_TOOLTIP_SINGLEPLAYER_TRAINING";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_Library: ACE_Campaign
		{
			idc = 1108;
			y = 0.53;
			onButtonClick = "_dummy = _this execVM ""\ca\ui\scripts\armory\launchArmory.sqf"" ";
			text = "$STR_CA_MAIN_LIBRARY";
			toolTip = "$STR_TOOLTIP_SINGLEPLAYER_LIBRARY";
			action = "uiNamespace setVariable ['ace_editor_debugc_available', nil]";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_Editor: ACE_Campaign
		{
			idc = 102;
			y = 0.65;
			text = "$STR_CA_MAIN_CUSTOM";
			toolTip = "$STR_TOOLTIP_SINGLEPLAYER_EDITOR";
			action = "uiNamespace setVariable ['ace_editor_debugc_available', true]";
			class KeyHints
			{
				class A
				{
					key = "0x00050000 + 0";
					hint = "";
				};
			};
		};
		class ACE_ButtonCancel: ACE_Campaign
		{
			idc = 2;
			shortcuts[] = {"0x00050000 + 1"};
			y = 0.8;
			text = "$STR_DISP_BACK";
		};
	};
};
class RscDisplayOptions
{
	class controlsBackground
	{
		delete Mainback;
		delete MainbackFaded;
		delete vertline;
		delete CWR2_Hline;
		delete CWR2_Vline;
		class vertical_line: RscLine
		{
			x = 0.002;
			y = "SafeZoneY";
			w = 0;
			h = "SafeZoneH";
			colorText[] = {1,1,1,1};
		};
	};
	class controls
	{
		delete BAudio;
		delete BConfigure;
		delete BGameOptions;
		delete BCredits;
		delete BVideo;
		delete HintX_Select;
		delete ButtonCancel;
		delete CA_EditProfileTitle;
		delete cwr2_Title;
		delete cwr2_gameOptions;
		delete cwr2_confgr;
		delete cwr2_Audio;
		delete cwr2_video;
		delete cwr2_credits;
		delete cwr2_back;
		class ACE_EditProfileTitle: CA_Title
		{
			x = 0.01;
			y = 0.192;
			w = 0.28;
			sizeEx = 0.08;
			text = "$STR_CA_MAIN_OPTIONS";
		};
		class ACE_BVideo: ACE_MenuRscShortcutButton
		{
			idc = 301;
			x = 0.01;
			y = 0.35;
			text = "$STR_DISP_OPTIONS_VIDEO";
			toolTip = "$STR_TOOLTIP_OPTIONS_VIDEO";
		};
		class ACE_BAudio: ACE_BVideo
		{
			idc = 302;
			y = 0.41;
			default = 0;
			text = "$STR_DISP_OPTIONS_AUDIO";
			toolTip = "$STR_TOOLTIP_OPTIONS_AUDIO";
		};
		class ACE_BConfigure: ACE_BAudio
		{
			idc = 303;
			y = 0.47;
			text = "$STR_DISP_OPTIONS_CONFIGURE";
			toolTip = "$STR_TOOLTIP_OPTIONS_CONFIGURE";
		};
		class ACE_BGameOptions: ACE_BAudio
		{
			idc = 307;
			y = 0.53;
			text = "$STR_DISP_OPTIONS_GAME_OPTIONS";
			toolTip = "$STR_TOOLTIP_OPTIONS_GAMEOPTIONS";
		};
		class ACE_BCredits: ACE_BAudio
		{
			idc = -1;
			y = 0.59;
			onButtonClick = "private [""_dummy""]; _dummy = [false] execVM ""\ca\ui\scripts\startCredits.sqf"";";
			text = "$STR_DISP_MAIN_CREDITS";
			toolTip = "";
		};
		class ACE_ButtonCancel: ACE_BAudio
		{
			idc = 2;
			y = 0.8;
			shortcuts[] = {"0x00050000 + 1"};
			text = "$STR_DISP_BACK";
		};
	};
};
class ACE_VERSION_MISMATCH
{
	idd = 114111;
	movingEnable = 1;
	duration = 99999999;
	fadein = 0.5;
	fadeout = 0.5;
	name = "ACE_VERSION_MISMATCH";
	onLoad = "with uiNameSpace do { ACE_VERSION_MISMATCH = _this select 0 }; playSound ""ACE_VERSION_DING"";";
	controls[] = {"ACE_VERSION_MISMATCH_BG","ACE_VERSION_MISMATCH_TITLE","ACE_VERSION_MISMATCH_TEXT","ACE_VERSION_MISMATCH_BUTT","ACE_VERSION_MISMATCH_LINE","ACE_VERSION_MISMATCH_HTML","ACE_VERSION_MISMATCH_LINE2"};
	class ACE_VERSION_MISMATCH_BG
	{
		moving = 1;
		idc = 101;
		type = 0;
		colorText[] = {0,1,0,0.5};
		font = "Bitstream";
		colorBackground[] = {0.1882,0.2588,0.149,0.76};
		text = "";
		style = 128;
		sizeEx = 0.015;
		size = 0.015;
		x = "SafeZoneX+ 0.2";
		y = "SafeZoneY+ 0.4";
		w = 0.6;
		h = 0.35;
	};
	class ACE_VERSION_MISMATCH_TITLE
	{
		access = 0;
		type = 13;
		idc = 4112;
		style = "2 + 16";
		lineSpacing = 1;
		x = "SafeZoneX+ 0.21";
		y = "SafeZoneY+ 0.41";
		w = 0.5;
		h = 0.12;
		sizeEx = 0.035;
		size = 0.035;
		colorBackground[] = {0.1882,0.2588,0.149,0};
		colorText[] = {0,0,0,1};
		text = "FEHLER";
		font = "BitStream";
		class Attributes
		{
			font = "BitStream";
			color = "#FF0F00";
			align = "left";
			shadow = "false";
		};
	};
	class ACE_VERSION_MISMATCH_LINE
	{
		idc = -1;
		type = 0;
		style = 176;
		x = "SafeZoneX+ 0.2 + 0.01";
		y = "SafeZoneY+ 0.445";
		w = 0.58;
		h = 0.0;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0.1882,0.2588,0.149,0};
		font = "Bitstream";
		sizeEx = 0.04;
		size = 0.04;
		text = "";
	};
	class ACE_VERSION_MISMATCH_TEXT: ACE_VERSION_MISMATCH_TITLE
	{
		idc = 114113;
		style = "0x00";
		x = "SafeZoneX+ 0.2";
		y = "SafeZoneY+ 0.446";
		w = 0.6;
		h = 0.25;
		sizeEx = 0.027;
		size = 0.027;
		text = "";
		class Attributes
		{
			font = "TahomaB";
			color = "#000000";
			align = "center";
			valign = "middle";
			shadow = "false";
			shadowColor = "#ff0000";
			size = "1";
		};
	};
	class ACE_VERSION_MISMATCH_LINE2: ACE_VERSION_MISMATCH_LINE
	{
		y = "SafeZoneY+ 0.65";
	};
	class ACE_VERSION_MISMATCH_BUTT
	{
		idc = 114114;
		type = 11;
		style = "0x00";
		x = "SafeZoneX+ 0.7";
		y = "SafeZoneY+ 0.7";
		w = 0.1;
		h = 0.035;
		font = "Zeppelin32";
		sizeEx = 0.018;
		size = 0.018;
		color[] = {1,1,1,1};
		colorActive[] = {1,0.2,0.2,1};
		soundEnter[] = {"",0,1};
		soundPush[] = {"",0,1};
		soundClick[] = {"",0,1};
		soundEscape[] = {"",0,1};
		action = "closedialog 0";
		text = "";
		default = "true";
	};
	class ACE_VERSION_MISMATCH_HTML: ACE_VERSION_MISMATCH_TITLE
	{
		idc = -1;
		x = "SafeZoneX+ 0.2";
		y = "SafeZoneY+ 0.7";
		w = 0.575;
		h = 0.05;
		size = 0.027;
		colorText[] = {1,1,1,1};
		sizeEx = 0.027;
		text = "http://dev-heaven.net/projects/activity/ace-mod2";
		class Attributes{};
	};
};
class ACE_ProgressBarFocus
{
	name = "ACE_ProgressBarFocus";
	idd = -1;
	movingEnable = 0;
	controlsBackground[] = {"Background"};
	objects[] = {};
	controls[] = {};
	onLoad = "with uiNamespace do {ACE_ProgressBarFocus = _this select 0}";
	class Background
	{
		colorBackground[] = {0,0,0,0};
		type = 0;
		colorText[] = {1,1,1,1};
		sizeEx = 0.04;
		style = 48;
		font = "BitStream";
		idc = -1;
		x = "safeZoneXAbs";
		y = "SafeZoneY";
		w = "safeZoneWAbs + 0.05";
		h = "SafeZoneH + 0.05";
		text = "\x\ace\addons\main\data\rsc\focus.paa";
	};
};
class ACE_Progressbar_RscText
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
class ACE_DBC_RscGroupBox2
{
	type = 0;
	idc = -1;
	style = 112;
	text = "";
	colorBackground[] = {1,1,1,0.6};
	colorText[] = {0,0,0,0};
	font = "BitStream";
	sizeEx = 0.02;
};
class ACE_MP_Debug_Console
{
	idd = 135663;
	movingEnable = 1;
	onLoad = "ace_debug_console_run = true;if (!isMultiplayer && {isNil 'ace_main_fnc_dbc_run'}) then {ace_main_fnc_dbc_run = compile preprocessFile 'x\ace\addons\main\fnc_dbcrun.sqf'};'load' spawn ace_main_fnc_dbc_run";
	onUnload = "ace_debug_console_run = false; 'unload' call ace_main_fnc_dbc_run";
	class Controls
	{
		class Drag: ACE_DBC_RscGroupBox2
		{
			x = 0.1;
			y = 0.07;
			w = 0.8;
			h = 0.83;
			colorbackground[] = {0,0,0,0.8};
			colortext[] = {0,0,0,0};
			moving = 1;
		};
		class Header: RscText
		{
			style = 2;
			x = 0.1;
			y = 0.07;
			w = 0.8;
			h = 0.04;
			text = "ACE Debug Console";
			sizeEx = 0.04;
			colortext[] = {1,1,1,1};
		};
		class SubBackground1: ACE_DBC_RscGroupBox2
		{
			x = 0.11;
			y = 0.115;
			w = 0.78;
			h = 0.41;
			style = 128;
			colorBackground[] = {0.709,0.972,0.384,0.2};
		};
		class SubBackground2: ACE_DBC_RscGroupBox2
		{
			x = 0.11;
			y = 0.535;
			w = 0.78;
			h = 0.35;
			style = 128;
			colorBackground[] = {0.709,0.972,0.384,0.2};
		};
		class ValueInput1: RscEdit
		{
			IDC = 316011;
			x = 0.12;
			y = 0.125;
			w = 0.76;
			h = 0.04;
			autocomplete = "scripting";
		};
		class ValueOutput1: RscEdit
		{
			IDC = 316012;
			x = 0.12;
			y = "0.165-0.001";
			w = 0.76;
			h = 0.04;
		};
		class ValueInput2: ValueInput1
		{
			IDC = 316021;
			y = 0.225;
		};
		class ValueOutput2: ValueOutput1
		{
			IDC = 316022;
			y = "0.265-0.001";
		};
		class ValueInput3: ValueInput1
		{
			IDC = 316031;
			y = 0.325;
		};
		class ValueOutput3: ValueOutput1
		{
			IDC = 316032;
			y = "0.365-0.001";
		};
		class ValueInput4: ValueInput1
		{
			IDC = 316041;
			y = 0.425;
		};
		class ValueOutpu4: ValueOutput1
		{
			IDC = 316042;
			y = "0.465-0.001";
		};
		class CommandInput1: RscEdit
		{
			IDC = 316101;
			x = 0.12;
			y = 0.55;
			w = 0.695;
			h = 0.04;
			autocomplete = "scripting";
		};
		class CommandButton1: RscButton_small
		{
			idc = 200;
			x = 0.82;
			y = 0.55;
			w = 0.06;
			h = 0.04;
			colorText[] = {0.75,0.75,0.75,1};
			colorBackground[] = {"0.709/2","0.972/2","0.384/2",1};
			text = "Exec";
			action = "call compile (ctrlText 316101);";
			default = 1;
		};
		class CommandInput2: CommandInput1
		{
			IDC = 316102;
			y = 0.6;
		};
		class CommandButton2: CommandButton1
		{
			idc = 201;
			y = 0.6;
			action = "call compile (ctrlText 316102);";
		};
		class CommandInput3: CommandInput1
		{
			IDC = 316103;
			y = 0.65;
		};
		class CommandButton3: CommandButton1
		{
			idc = 202;
			y = 0.65;
			action = "call compile (ctrlText 316103);";
		};
		class CommandInput4: CommandInput1
		{
			IDC = 316104;
			y = 0.7;
		};
		class CommandButton4: CommandButton1
		{
			idc = 203;
			y = 0.7;
			action = "call compile (ctrlText 316104);";
		};
		class CommandInput5: CommandInput1
		{
			IDC = 316105;
			y = 0.75;
		};
		class CommandButton5: CommandButton1
		{
			idc = 204;
			y = 0.75;
			action = "call compile (ctrlText 316105);";
		};
		class CommandInput6: CommandInput1
		{
			IDC = 316106;
			y = 0.8;
		};
		class CommandButton6: CommandButton1
		{
			idc = 205;
			y = 0.8;
			action = "call compile (ctrlText 316106);";
			default = "true";
		};
	};
};
class ACE_RESPAWN_DIALOG
{
	idd = 114113;
	movingEnable = 1;
	duration = 99999999;
	fadein = 0.5;
	fadeout = 0.5;
	name = "ACE_RESPAWN_DIALOG";
	class controlsBackground
	{
		class ACE_RESPAWN_DIALOG_BG: RscPicture
		{
			idc = 1200;
			text = "\x\ace\addons\main\data\rsc\ace_respawn_dialog_bg_ca.paa";
			x = "0.364348 * safezoneW + safezoneX";
			y = "0.0763965 * safezoneH + safezoneY";
			w = "0.228451 * safezoneW";
			h = "0.080259 * safezoneH";
		};
		class ACE_RESPAWN_DIALOG_FRAME: RscFrame
		{
			idc = 1800;
			x = "0.364348 * safezoneW + safezoneX";
			y = "0.0763965 * safezoneH + safezoneY";
			w = "0.228451 * safezoneW";
			h = "0.080259 * safezoneH";
		};
	};
	class controls
	{
		class ACE_RESPAWN_DIALOG_CONFIRM: RscShortcutButton
		{
			idc = 1700;
			text = "$STR_WORDS_YES";
			x = "0.369079 * safezoneW + safezoneX";
			y = "0.114677 * safezoneH + safezoneY";
			w = "0.0644059 * safezoneW";
			h = "0.0500376 * safezoneH";
			action = "closeDialog 0; if (alive player) then { player setdamage 1 };";
		};
		class ACE_RESPAWN_DIALOG_ABORT: ACE_RESPAWN_DIALOG_CONFIRM
		{
			idc = 1701;
			text = "$STR_WORDS_NO";
			x = "0.524186 * safezoneW + safezoneX";
			action = "closeDialog 0";
		};
		class ACE_RESPAWN_DIALOG_HEADER: RscText
		{
			idc = 1000;
			text = "Respawn ?";
			x = "0.436381 * safezoneW + safezoneX";
			y = "0.075389 * safezoneH + safezoneY";
			w = "0.0875404 * safezoneW";
			h = "0.0409712 * safezoneH";
		};
	};
};
class ACE_ABOUT_DLG
{
	idd = 114137;
	movingEnable = 0;
	onLoad = "with uiNameSpace do { ACE_ABOUT_DLG = _this select 0; };";
	onKeyDown = "if((_this select 1) == 1) then {ACE_ABOUT_STP = true;};";
	class controlsBackground
	{
		class Contents: RscStructuredText
		{
			idc = 1141371;
			colorBackground[] = {0,0,0,0};
			x = "(0.45 * safeZoneW) + safeZoneX";
			y = "(0.25 * safeZoneH) + safeZoneY";
			w = "0.45 * safeZoneW";
			h = "0.6 * safeZoneH";
			size = "0.025 * SafeZoneH";
			class Attributes
			{
				font = "TahomaB";
				color = "#C8C8C8";
				align = "left";
				valign = "middle";
				shadow = "true";
				shadowColor = "#191970";
				size = "1";
			};
		};
		class ACE_ABOUT_NEXT: ACE_ABOUT_CTRL
		{
			idc = 1141372;
			x = "(0.065 * safeZoneW) + safeZoneX";
			w = "0.03 * safeZoneW";
			text = "";
			action = "";
		};
	};
};
class RscTitles
{
	class ACE_RscGeneric
	{
		idd = 135135;
		onLoad = "with uiNameSpace do { ACE_RscGeneric = _this select 0 };";
		movingEnable = 0;
		duration = 4;
		fadeIn = 0;
		fadeOut = 0;
		controls[] = {"ACE_RscGeneric_BG","ACE_RscGeneric_1","ACE_RscGeneric_2"};
		class ACE_RscGeneric_BG
		{
			idc = -1;
			type = 0;
			font = "TahomaB";
			colorBackground[] = {0.2,0.15,0.1,0.8};
			colorText[] = {0,0,0,0};
			text = "";
			style = 128;
			sizeEx = "( 16 / 408 )";
			x = "SafeZoneX + 0.001";
			y = "SafeZoneY + 0.04";
			h = 0.035;
			w = 0.385;
		};
		class ACE_RscGeneric_1: ACE_RscGeneric_BG
		{
			idc = 135136;
			style = "0x02";
			h = 0.033;
			w = 0.383;
			colorText[] = {0.8784,0.8471,0.651,1};
			colorBackground[] = {0,0,0,0};
			font = "TahomaB";
			sizeEx = 0.03;
			shadow = 2;
		};
		class ACE_RscGeneric_2: ACE_RscGeneric_1
		{
			idc = 135137;
			y = "SafeZoneY + 0.033 + 0.04";
		};
	};
	class ACE_RscGenericNF: ACE_RscGeneric
	{
		idd = 1358008;
		onLoad = "with uiNameSpace do { ACE_RscGenericNF = _this select 0 };";
		duration = 40000;
		controls[] = {"ACE_RscGenericNF_BG","ACE_RscGenericNF_1","ACE_RscGenericNF_2","ACE_RscGenericNF_3"};
		class ACE_RscGenericNF_BG: ACE_RscGeneric_BG
		{
			idc = 1358012;
		};
		class ACE_RscGenericNF_1: ACE_RscGeneric_1
		{
			idc = 1358009;
		};
		class ACE_RscGenericNF_2: ACE_RscGeneric_2
		{
			idc = 1358010;
			y = "SafeZoneY + 0.033 + 0.04";
		};
		class ACE_RscGenericNF_3: ACE_RscGeneric_2
		{
			idc = 1358011;
			style = 48;
			font = "Bitstream";
		};
	};
	class ACE_ProgressBar
	{
		idd = 10200;
		movingEnable = 0;
		objects[] = {};
		duration = 1e+011;
		name = "ACE_ProgressBar";
		onLoad = "with uiNameSpace do {ACE_Rsc_Progressbar = _this select 0}";
		onUnload = "";
		controls[] = {"ACE_ProgressBarBackground","ACE_ProgressBar","ACE_Progress_Label"};
		controlsBackground[] = {};
		class ACE_ProgressBarBackground: ACE_Progressbar_RscText
		{
			style = 128;
			idc = 1;
			x = "SafeZoneX + 0.001";
			y = "SafeZoneY + 0.04";
			h = 0.08;
			w = 0.385;
			colorBackground[] = {0,0,0,0.5};
		};
		class ACE_ProgressBar: ACE_Progressbar_RscText
		{
			style = 128;
			idc = 2;
			x = "SafeZoneX + 0.011";
			y = "SafeZoneY + 0.085";
			h = 0.013;
			w = 0.0;
			colorBackground[] = {0.543,0.5742,0.4102,0.8};
		};
		class ACE_Progress_Label: ACE_Progressbar_RscText
		{
			idc = 3;
			text = "STAND BY";
			x = "SafeZoneX + 0.152";
			w = 0.2;
			y = "SafeZoneY + 0.045";
			font = "EtelkaMonospaceProBold";
			sizeEx = 0.023;
			colorBackground[] = {1,1,1,0};
			colorText[] = {1,1,1,1};
		};
	};
	class ACE_RscAnimatedLetters
	{
		idd = 116666;
		movingEnable = 0;
		duration = 1e+011;
		onLoad = "with uiNameSpace do {ACE_ANIM_LETTERS = _this select 0}";
		class ControlsBackground{};
		class Controls
		{
			idc = 5000;
			class L1
			{
				idc = 5000;
				style = "0x02";
				type = 0;
				x = 0.5;
				y = 0.5;
				h = 0.3;
				w = 0.1;
				font = "Zeppelin32";
				sizeEx = 0.032;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.643,0.5742,0.4102,1.0};
				text = "";
			};
			class L2: L1
			{
				idc = 5001;
			};
			class L3: L1
			{
				idc = 5002;
			};
			class L4: L1
			{
				idc = 5003;
			};
			class L5: L1
			{
				idc = 5004;
			};
			class L6: L1
			{
				idc = 5005;
			};
			class L7: L1
			{
				idc = 5006;
			};
			class L8: L1
			{
				idc = 5007;
			};
			class L9: L1
			{
				idc = 5008;
			};
			class L10: L1
			{
				idc = 5009;
			};
			class L11: L1
			{
				idc = 5010;
			};
			class L12: L1
			{
				idc = 5011;
			};
			class L13: L1
			{
				idc = 5012;
			};
			class L14: L1
			{
				idc = 5013;
			};
			class L15: L1
			{
				idc = 5014;
			};
			class L16: L1
			{
				idc = 5015;
			};
			class L17: L1
			{
				idc = 5016;
			};
			class L18: L1
			{
				idc = 5017;
			};
			class L19: L1
			{
				idc = 5018;
			};
			class L20: L1
			{
				idc = 5019;
			};
			class L21: L1
			{
				idc = 5020;
			};
			class L22: L1
			{
				idc = 5021;
			};
			class L23: L1
			{
				idc = 5022;
			};
			class L24: L1
			{
				idc = 5023;
			};
			class L25: L1
			{
				idc = 5024;
			};
			class L26: L1
			{
				idc = 5025;
			};
			class L27: L1
			{
				idc = 5026;
			};
			class L28: L1
			{
				idc = 5027;
			};
			class L29: L1
			{
				idc = 5028;
			};
			class L30: L1
			{
				idc = 5029;
			};
			class L31: L1
			{
				idc = 5030;
			};
			class L32: L1
			{
				idc = 5031;
			};
			class L33: L1
			{
				idc = 5032;
			};
			class L34: L1
			{
				idc = 5033;
			};
			class L35: L1
			{
				idc = 5034;
			};
			class L36: L1
			{
				idc = 5035;
			};
			class L37: L1
			{
				idc = 5036;
			};
			class L38: L1
			{
				idc = 5037;
			};
			class L39: L1
			{
				idc = 5038;
			};
			class L40: L1
			{
				idc = 5039;
			};
			class L41: L1
			{
				idc = 5040;
			};
			class L42: L1
			{
				idc = 5041;
			};
			class L43: L1
			{
				idc = 5042;
			};
			class L44: L1
			{
				idc = 5043;
			};
			class L45: L1
			{
				idc = 5044;
			};
			class L46: L1
			{
				idc = 5045;
			};
			class L47: L1
			{
				idc = 5046;
			};
			class L48: L1
			{
				idc = 5047;
			};
			class L49: L1
			{
				idc = 5048;
			};
			class L50: L1
			{
				idc = 5049;
			};
			class L51: L1
			{
				idc = 5050;
			};
			class L52: L1
			{
				idc = 5051;
			};
			class L53: L1
			{
				idc = 5052;
			};
			class L54: L1
			{
				idc = 5053;
			};
			class L55: L1
			{
				idc = 5054;
			};
			class L56: L1
			{
				idc = 5055;
			};
			class L57: L1
			{
				idc = 5056;
			};
			class L58: L1
			{
				idc = 5057;
			};
			class L59: L1
			{
				idc = 5058;
			};
			class L60: L1
			{
				idc = 5059;
			};
			class L61: L1
			{
				idc = 5060;
			};
			class L62: L1
			{
				idc = 5061;
			};
			class L63: L1
			{
				idc = 5062;
			};
			class L64: L1
			{
				idc = 5063;
			};
			class L65: L1
			{
				idc = 5064;
			};
			class L66: L1
			{
				idc = 5065;
			};
			class L67: L1
			{
				idc = 5066;
			};
			class L68: L1
			{
				idc = 5067;
			};
			class L69: L1
			{
				idc = 5068;
			};
			class L70: L1
			{
				idc = 5069;
			};
			class L71: L1
			{
				idc = 5070;
			};
			class L72: L1
			{
				idc = 5071;
			};
			class L73: L1
			{
				idc = 5072;
			};
			class L74: L1
			{
				idc = 5073;
			};
			class L75: L1
			{
				idc = 5074;
			};
			class L76: L1
			{
				idc = 5075;
			};
			class L77: L1
			{
				idc = 5076;
			};
			class L78: L1
			{
				idc = 5077;
			};
			class L79: L1
			{
				idc = 5078;
			};
			class L80: L1
			{
				idc = 5079;
			};
			class L81: L1
			{
				idc = 5080;
			};
			class L82: L1
			{
				idc = 5081;
			};
			class L83: L1
			{
				idc = 5082;
			};
			class L84: L1
			{
				idc = 5083;
			};
			class L85: L1
			{
				idc = 5084;
			};
			class L86: L1
			{
				idc = 5085;
			};
			class L87: L1
			{
				idc = 5086;
			};
			class L88: L1
			{
				idc = 5087;
			};
			class L89: L1
			{
				idc = 5088;
			};
			class L90: L1
			{
				idc = 5089;
			};
			class L91: L1
			{
				idc = 5090;
			};
			class L92: L1
			{
				idc = 5091;
			};
			class L93: L1
			{
				idc = 5092;
			};
			class L94: L1
			{
				idc = 5093;
			};
			class L95: L1
			{
				idc = 5094;
			};
			class L96: L1
			{
				idc = 5095;
			};
			class L97: L1
			{
				idc = 5096;
			};
			class L98: L1
			{
				idc = 5097;
			};
			class L99: L1
			{
				idc = 5098;
			};
			class L100: L1
			{
				idc = 5099;
			};
			class L101: L1
			{
				idc = 5100;
			};
			class L102: L1
			{
				idc = 5101;
			};
			class L103: L1
			{
				idc = 5102;
			};
			class L104: L1
			{
				idc = 5103;
			};
			class L105: L1
			{
				idc = 5104;
			};
			class L106: L1
			{
				idc = 5105;
			};
			class L107: L1
			{
				idc = 5106;
			};
			class L108: L1
			{
				idc = 5107;
			};
			class L109: L1
			{
				idc = 5108;
			};
			class L110: L1
			{
				idc = 5109;
			};
			class L111: L1
			{
				idc = 5110;
			};
			class L112: L1
			{
				idc = 5111;
			};
			class L113: L1
			{
				idc = 5112;
			};
			class L114: L1
			{
				idc = 5113;
			};
			class L115: L1
			{
				idc = 5114;
			};
			class L116: L1
			{
				idc = 5115;
			};
			class L117: L1
			{
				idc = 5116;
			};
			class L118: L1
			{
				idc = 5117;
			};
			class L119: L1
			{
				idc = 5118;
			};
			class L120: L1
			{
				idc = 5119;
			};
			class L121: L1
			{
				idc = 5120;
			};
			class L122: L1
			{
				idc = 5121;
			};
			class L123: L1
			{
				idc = 5122;
			};
			class L124: L1
			{
				idc = 5123;
			};
			class L125: L1
			{
				idc = 5124;
			};
			class L126: L1
			{
				idc = 5125;
			};
			class L127: L1
			{
				idc = 5126;
			};
			class L128: L1
			{
				idc = 5127;
			};
			class L129: L1
			{
				idc = 5128;
			};
			class L130: L1
			{
				idc = 5129;
			};
			class L131: L1
			{
				idc = 5130;
			};
			class L132: L1
			{
				idc = 5131;
			};
			class L133: L1
			{
				idc = 5132;
			};
			class L134: L1
			{
				idc = 5133;
			};
			class L135: L1
			{
				idc = 5134;
			};
			class L136: L1
			{
				idc = 5135;
			};
			class L137: L1
			{
				idc = 5136;
			};
			class L138: L1
			{
				idc = 5137;
			};
			class L139: L1
			{
				idc = 5138;
			};
			class L140: L1
			{
				idc = 5139;
			};
			class L141: L1
			{
				idc = 5140;
			};
			class L142: L1
			{
				idc = 5141;
			};
			class L143: L1
			{
				idc = 5142;
			};
			class L144: L1
			{
				idc = 5143;
			};
			class L145: L1
			{
				idc = 5144;
			};
			class L146: L1
			{
				idc = 5145;
			};
			class L147: L1
			{
				idc = 5146;
			};
			class L148: L1
			{
				idc = 5147;
			};
			class L149: L1
			{
				idc = 5148;
			};
			class L150: L1
			{
				idc = 5149;
			};
			class L151: L1
			{
				idc = 5150;
			};
			class L152: L1
			{
				idc = 5151;
			};
			class L153: L1
			{
				idc = 5152;
			};
			class L154: L1
			{
				idc = 5153;
			};
			class L155: L1
			{
				idc = 5154;
			};
			class L156: L1
			{
				idc = 5155;
			};
			class L157: L1
			{
				idc = 5156;
			};
			class L158: L1
			{
				idc = 5157;
			};
			class L159: L1
			{
				idc = 5158;
			};
			class L160: L1
			{
				idc = 5159;
			};
			class L161: L1
			{
				idc = 5160;
			};
			class L162: L1
			{
				idc = 5161;
			};
			class L163: L1
			{
				idc = 5162;
			};
			class L164: L1
			{
				idc = 5163;
			};
			class L165: L1
			{
				idc = 5164;
			};
			class L166: L1
			{
				idc = 5165;
			};
			class L167: L1
			{
				idc = 5166;
			};
			class L168: L1
			{
				idc = 5167;
			};
			class L169: L1
			{
				idc = 5168;
			};
			class L170: L1
			{
				idc = 5169;
			};
			class L171: L1
			{
				idc = 5170;
			};
			class L172: L1
			{
				idc = 5171;
			};
			class L173: L1
			{
				idc = 5172;
			};
			class L174: L1
			{
				idc = 5173;
			};
			class L175: L1
			{
				idc = 5174;
			};
			class L176: L1
			{
				idc = 5175;
			};
			class L177: L1
			{
				idc = 5176;
			};
			class L178: L1
			{
				idc = 5177;
			};
			class L179: L1
			{
				idc = 5178;
			};
			class L180: L1
			{
				idc = 5179;
			};
			class L181: L1
			{
				idc = 5180;
			};
			class L182: L1
			{
				idc = 5181;
			};
			class L183: L1
			{
				idc = 5182;
			};
			class L184: L1
			{
				idc = 5183;
			};
			class L185: L1
			{
				idc = 5184;
			};
			class L186: L1
			{
				idc = 5185;
			};
			class L187: L1
			{
				idc = 5186;
			};
			class L188: L1
			{
				idc = 5187;
			};
			class L189: L1
			{
				idc = 5188;
			};
			class L190: L1
			{
				idc = 5189;
			};
			class L191: L1
			{
				idc = 5190;
			};
			class L192: L1
			{
				idc = 5191;
			};
			class L193: L1
			{
				idc = 5192;
			};
			class L194: L1
			{
				idc = 5193;
			};
			class L195: L1
			{
				idc = 5194;
			};
			class L196: L1
			{
				idc = 5195;
			};
			class L197: L1
			{
				idc = 5196;
			};
			class L198: L1
			{
				idc = 5197;
			};
			class L199: L1
			{
				idc = 5198;
			};
			class L200: L1
			{
				idc = 5199;
			};
			class L201: L1
			{
				idc = 5200;
			};
			class L202: L1
			{
				idc = 5201;
			};
			class L203: L1
			{
				idc = 5202;
			};
			class L204: L1
			{
				idc = 5203;
			};
			class L205: L1
			{
				idc = 5204;
			};
			class L206: L1
			{
				idc = 5205;
			};
			class L207: L1
			{
				idc = 5206;
			};
			class L208: L1
			{
				idc = 5207;
			};
			class L209: L1
			{
				idc = 5208;
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_main
	{
		init = "call ('\x\ace\addons\main\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\settings\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
		serverInit = "call ('\x\ace\addons\main\XEH_preServerInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_main
	{
		serverInit = "call ('\x\ace\addons\main\XEH_PostServerInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\main\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_GetOut_EventHandlers
{
	class AllVehicles
	{
		class ace_main
		{
			clientGetOut = "if (ace_main_dismount_enabled&& {_this select 2 == player}) then { _this call ace_main_fnc_CAMERA}";
		};
	};
};
class Extended_FiredBIS_EventHandlers
{
	class CAManBase
	{
		class ace_main
		{
			firedBis = "_this call ace_main_fnc_fired";
		};
	};
};
class Extended_Init_EventHandlers
{
	class ACE_Logic
	{
		class ace_main
		{
			init = "(_this select 0) enableSimulation false";
		};
	};
};
class CfgFunctions
{
	class ACE
	{
		class Main
		{
			class add2clean
			{
				description = "Add an item to a timed cleanup list. Item is automatically removed after it's lifetime expires.";
				file = "\x\ace\Addons\main\fnc_add2clean.sqf";
			};
			class add2fifo
			{
				description = "Add an item to a queue. Items in excess of the specified purge count will be deleted in First-in First-out ( FIFO ) order.";
				file = "\x\ace\Addons\main\fnc_add2fifo.sqf";
			};
			class add2sfifo
			{
				description = "adds an object to the slowly running FIFO";
				file = "\x\ace\Addons\main\fnc_add2sfifo.sqf";
			};
			class addClientToServerEventhandler
			{
				description = "Registers an event handler for a client to server event which only runs on the server (thus is only needed on the server)";
				file = "\x\ace\Addons\main\fnc_addClientToServerEventhandler.sqf";
			};
			class addMagazineCargoEx
			{
				description = "Add magazines with a specific bullet count to the cargo space of vehicles.";
				file = "\x\ace\Addons\main\fnc_addMagazineCargoEx.sqf";
			};
			class addReceiverOnlyEventhandler
			{
				description = "Registers an event handler for an ACE event which is only broadcasted to the receiver (and no other clients)";
				file = "\x\ace\Addons\main\fnc_addReceiverOnlyEventhandler.sqf";
			};
			class bulletCam
			{
				description = "BulletCam for debugging";
				file = "\x\ace\Addons\main\fnc_bulletCam.sqf";
			};
			class clientToServerEvent
			{
				description = "Raises an ACE event only on the server (only broadcasted to server and not to other clients)";
				file = "\x\ace\Addons\main\fnc_clientToServerEvent.sqf";
			};
			class DelPropertyObj
			{
				description = "Func";
				file = "\x\ace\Addons\main\fnc_DelPropertyObj.sqf";
			};
			class FixHeadbug
			{
				description = "Func";
				file = "\x\ace\Addons\main\fnc_FixHeadbug.sqf";
			};
			class FixHeadbugAlt
			{
				description = "Func";
				file = "\x\ace\Addons\main\fnc_FixHeadbugAlt.sqf";
			};
			class GetProperty
			{
				description = "Func";
				file = "\x\ace\Addons\main\fnc_GetProperty.sqf";
			};
			class groupdebug
			{
				description = "Debug Markers etc for Groups";
				file = "\x\ace\Addons\main\fnc_groupdebug.sqf";
			};
			class inBuilding
			{
				description = "Function to check if a person or a position is inside a house.";
				file = "\x\ace\Addons\main\fnc_inBuilding.sqf";
			};
			class inFront
			{
				description = "Function to check if Object2 is in front of Object1";
				file = "\x\ace\Addons\main\fnc_inFront.sqf";
			};
			class isBurning
			{
				description = "Returns if vehicle/unit is burning";
				file = "\x\ace\Addons\main\fnc_isBurning.sqf";
			};
			class isCrew
			{
				description = "Returns if unit is a crew unit";
				file = "\x\ace\Addons\main\fnc_isCrew.sqf";
			};
			class isPilot
			{
				description = "Returns if unit is a pilot unit";
				file = "\x\ace\Addons\main\fnc_isPilot.sqf";
			};
			class isVehTurnedOut
			{
				description = "Checks whether a vehicle has any crew turned out. Accepts vehicle or individual unit as parameter. By default, if crew (even exposed gunners) do not have the option to turn in, they are considered turned in. Use optional parameter _exposure to be treat only sealed or pressurized vehicles as capable of being turned in.";
				file = "\x\ace\Addons\main\fnc_isVehTurnedOut.sqf";
			};
			class lockClass
			{
				description = "Adds disability to units who uses weapon not for his faction/role";
				file = "\x\ace\Addons\main\fnc_lockClass.sqf";
			};
			class particle
			{
				description = "Creates particlesource and attaches on unit";
				file = "\x\ace\Addons\main\fnc_particle.sqf";
			};
			class receiverOnlyEvent
			{
				description = "Raises an ACE event only on the receiver and is only broadcasted there Can be called on any client or on the server. If called on a client the params are broadcasted to the server first, server then checks the owner and sends the params only to that specific client";
				file = "\x\ace\Addons\main\fnc_receiverOnlyEvent.sqf";
			};
			class registerSimulation
			{
				description = "Register simulationType for CAManBase";
				file = "\x\ace\Addons\main\fnc_registerSimulation.sqf";
			};
			class removeClientToServerEvent
			{
				description = "Removes an event handler previously registered with ACE_fnc_addClientToServerEventhandler.";
				file = "\x\ace\Addons\main\fnc_removeClientToServerEvent.sqf";
			};
			class removeMagazineCargo
			{
				description = "Function to remove a magazine from a vehicles cargo.";
				file = "\x\ace\Addons\main\fnc_removeMagazineCargo.sqf";
			};
			class removeReceiverOnlyEvent
			{
				description = "Removes an event handler previously registered with ACE_fnc_addReceiverOnlyEventhandler.";
				file = "\x\ace\Addons\main\fnc_removeReceiverOnlyEvent.sqf";
			};
			class removeWeaponCargo
			{
				description = "Function to remove a weapon from a vehicles cargo.";
				file = "\x\ace\Addons\main\fnc_removeWeaponCargo.sqf";
			};
			class SetProperty
			{
				description = "Func";
				file = "\x\ace\Addons\main\fnc_SetProperty.sqf";
			};
			class track
			{
				description = "Tracks an object with markers and particles";
				file = "\x\ace\Addons\main\fnc_track.sqf";
			};
			class TurretFeature
			{
				description = "Function to retrieve a turret feature";
				file = "\x\ace\Addons\main\fnc_TurretFeature.sqf";
			};
			class unitvehpos
			{
				description = "Function to retrieve unit position in vehicle, analogous to assignedvehiclerole but more reliable";
				file = "\x\ace\Addons\main\fnc_unitvehpos.sqf";
			};
			class visual
			{
				description = "-";
				file = "\x\ace\Addons\main\fnc_visual.sqf";
			};
			class WeaponFeature
			{
				description = "Function to retrieve a muzzle feature";
				file = "\x\ace\Addons\main\fnc_WeaponFeature.sqf";
			};
		};
	};
	class CBA
	{
		class Events
		{
			class readKeyFromConfig
			{
				description = "Reads key setting from config";
				file = "\x\ace\Addons\main\fnc_readKeyFromConfig.sqf";
			};
		};
	};
	class BIS
	{
		class misc
		{
			class PosToGrid
			{
				file = "\x\ace\Addons\main\fnc_posToGrid.sqf";
			};
		};
	};
};
class ACE_Config
{
	class ace_pbos
	{
		access = 2;
		ace_pbos[] = {"ace_anims_fastswitch","ace_anims_movement","ace_anims_reload","ace_anims_turn","ace_anims_weaponsway","ace_sys_backblast","ace_sys_combatdeaf","ace_sys_muzzleblast","ace_sys_mv","ace_sys_recognize","ace_sys_rotoreffects","ace_sys_stamina","ace_sys_vehicledamage","ace_sys_wind_deflection","ace_sys_wounds"};
	};
};
class CfgMarkers
{
	class Flag;
	class ACE_Radiation_Area: Flag{};
};
class CfgVehicles
{
	class All
	{
		class ACE{};
	};
	class ParaChuteG;
	class ACE_B61_Parachute: ParaChuteG{};
	class Logic;
	class ACE_Logic: Logic
	{
		displayname = "$STR_ACE_LOGIC";
	};
	class ACE_Required_Logic: ACE_Logic
	{
		displayName = "$STR_ACE_REQUIRED";
		vehicleClass = "Modules";
	};
	class ACE_BI_ARTY_Logic: ACE_Logic
	{
		scope = 1;
		displayName = "$STR_ACE_BI_ARTY";
		icon = "\x\ace\addons\main\data\icon\icon_ARTY_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "_this spawn ('\ca\modules\arty\data\scripts\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
		};
	};
	class ACE_BI_ARTY_Virtual_Artillery: ACE_Logic
	{
		scope = 1;
		displayName = "$STR_ACE_BI_ARTY_VIRT";
		icon = "\x\ace\addons\main\data\icon\icon_ARTY_virtual_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "_this spawn ('\ca\modules\arty\data\scripts\ARTY_initVirtual.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
		};
	};
	class HeliHEmpty;
	class ACE_LogicDummy: HeliHEmpty
	{
		scope = 1;
		SLX_XEH_DISABLED = 1;
		class EventHandlers
		{
			init = "(_this select 0) enableSimulation false";
		};
	};
	class Land;
	class Man: Land
	{
		class ViewPilot;
	};
	class ACE_DummyManBase: Man
	{
		picture = "\Ca\characters\data\Ico\i_null_CA.paa";
		Icon = "\Ca\characters\data\map_ico\i_wojak_CA.paa";
		fsmDanger = "Ca\characters\scripts\danger.fsm";
		moves = "CfgMovesMaleSdr";
		gestures = "CfgGesturesMale";
		boneHead = "";
		boneHeadCutScene = "";
		boneLEye = "";
		boneREye = "";
		boneLEyelidUp = "";
		boneREyelidUp = "";
		boneLEyelidDown = "";
		boneREyelidDown = "";
		boneLPupil = "";
		boneRPupil = "";
		bonePrimaryWeapon = "";
		triggerAnim = "ca\anims\characters\data\anim\sdr\trigger.rtm";
		woman = 0;
		faceType = "man";
		class TalkTopics
		{
			core = "Core";
			core_en = "Core_Degenerated";
			core_ru = "Core_Degenerated";
			core_cz = "Core_Degenerated";
		};
		languages[] = {};
		minGunElev = -80;
		maxGunElev = 60;
		minGunTurn = -1;
		maxGunTurn = 1;
		minGunTurnAI = -30;
		maxGunTurnAI = 30;
		class HeadLimits;
		minHeadTurnAI = -60;
		maxHeadTurnAI = 60;
		class ViewPilot: ViewPilot
		{
			initFov = 0.7;
			minFov = 0.25;
			maxFov = 1.1;
			initAngleX = 8;
			minAngleX = -85;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
		};
		selectionHeadWound = "";
		selectionBodyWound = "";
		selectionLArmWound = "";
		selectionRArmWound = "";
		selectionLLegWound = "";
		selectionRLegWound = "";
		selectionHeadHide = "";
		selectionNeckHide = "";
		memoryPointLStep = "";
		memoryPointRStep = "";
		memoryPointAim = "";
		memoryPointCameraTarget = "";
		memoryPointCommonDamage = "";
		memoryPointLeaningAxis = "";
		memoryPointAimingAxis = "";
		memoryPointHeadAxis = "";
		selectionLBrow = "";
		selectionMBrow = "";
		selectionRBrow = "";
		selectionLMouth = "";
		selectionMMouth = "";
		selectionRMouth = "";
		selectionEyelid = "";
		selectionLip = "";
		class HitPoints
		{
			class HitHead
			{
				armor = 0.7;
				material = -1;
				name = "";
				passThrough = 1;
			};
			class HitBody
			{
				armor = 0.8;
				material = -1;
				name = "";
				passThrough = 1;
			};
			class HitHands
			{
				armor = 0.5;
				material = -1;
				name = "";
				passThrough = 1;
			};
			class HitLegs
			{
				armor = 0.5;
				material = -1;
				name = "";
				passThrough = 1;
			};
		};
		useInternalLODInVehicles = 1;
		accuracy = 0;
		vehicleClass = "Men";
		type = 0;
		threat[] = {1,0.05,0.05};
		vegetation0[] = {"Ca\sounds\Characters\Noises\Bush\bush1",1,1,20};
		vegetation1[] = {"Ca\sounds\Characters\Noises\Bush\bush2",1,1,20};
		vegetation2[] = {"Ca\sounds\Characters\Noises\Bush\bush3",1,1,20};
		vegetationSounds[] = {"vegetation0",0.33,"vegetation1",0.33,"vegetation2",0.33};
		class HitDamage
		{
			class Group0
			{
				hitSounds[] = {{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 }};
				damageSounds[] = {{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "hands",{ "",0.0562341,1,120,0.25,20,40,60 } },{ "hands",{ "",0.0562341,1,120,0.25,20,40,60 } },{ "hands",{ "",0.0562341,1,120,0.25,20,40,60 } },{ "hands",{ "",0.0562341,1,120,0.25,20,40,60 } },{ "legs",{ "",0.0562341,1,120,20,40,60 } },{ "legs",{ "",0.0562341,1,120,20,40,60 } }};
			};
			class Group1
			{
				hitSounds[] = {{ { "",0.177828,1,120 },0.2 },{ { "",0.177828,1,120 },0.2 },{ { "",0.177828,1,120 },0.2 },{ { "",0.177828,1,120 },0.2 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 }};
				damageSounds[] = {{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "hands",{ "",0.0562341,1,120,0.33,20,40,60 } },{ "hands",{ "",0.0562341,1,120,0.33,20,40,60 } },{ "hands",{ "",0.0562341,1,120,0.33,20,40,60 } },{ "legs",{ "",0.0562341,1,120,0.33,20,40,60 } },{ "legs",{ "",0.0562341,1,120,0.33,20,40,60 } },{ "legs",{ "",0.0562341,1,120,0.33,20,40,60 } }};
			};
			class Group2
			{
				hitSounds[] = {{ { "",0.177828,1,120 },0.2 },{ { "",0.177828,1,120 },0.2 },{ { "",0.177828,1,120 },0.2 },{ { "",0.177828,1,120 },0.2 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 }};
				damageSounds[] = {{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "body",{ "",0.0562341,1,120,0.125,20,40,60 } },{ "hands",{ "",0.0562341,1,120,0.33,20,40,60 } },{ "hands",{ "",0.0562341,1,120,0.33,20,40,60 } },{ "hands",{ "",0.0562341,1,120,0.33,20,40,60 } },{ "legs",{ "",0.0562341,1,120,0.5,20,40,60 } },{ "legs",{ "",0.0562341,1,120,0.5,20,40,60 } }};
			};
			class Group3
			{
				hitSounds[] = {{ { "",0.177828,1,120 },0.15 },{ { "",0.177828,1,120 },0.15 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 },{ { "",0.177828,1,120 },0.1 }};
				damageSounds[] = {{ "body",{ "",0.0707946,1,120,0.2,20,40,60 } },{ "body",{ "",0.0707946,1,120,0.2,20,40,60 } },{ "body",{ "",0.0707946,1,120,0.2,20,40,60 } },{ "body",{ "",0.0707946,1,120,0.2,20,40,60 } },{ "body",{ "",0.0707946,1,120,0.2,20,40,60 } },{ "hands",{ "",0.0707946,1,120,0.33,20,40,60 } },{ "hands",{ "",0.0707946,1,120,0.33,20,40,60 } },{ "hands",{ "",0.0707946,1,120,0.33,20,40,60 } },{ "legs",{ "",0.0707946,1,120,0.5,20,40,60 } },{ "legs",{ "",0.0707946,1,120,0.5,20,40,60 } }};
			};
		};
		class SoundBreath
		{
			breath0[] = {{ { { "",0.0562341,1,20 },0.2 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } },{ { { "",0.0562341,1,25 },0.2 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } },{ { { "",0.1,1,25 },0.2 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.18 },{ { "",0.1,1,25 },0.05 } }};
			breath1[] = {{ { { "",0.0562341,1,25 },0.2 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } },{ { { "",0.0562341,1,25 },0.2 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } },{ { { "",0.1,1,25 },0.2 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.18 },{ { "",0.1,1,25 },0.05 } }};
			breath2[] = {{ { { "",0.0562341,1,25 },0.2 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } },{ { { "",0.0562341,1,25 },0.2 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } },{ { { "",0.1,1,25 },0.2 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } }};
			breath3[] = {{ { { "",0.0562341,1,25 },0.2 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } },{ { { "",0.0562341,1,25 },0.2 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } },{ { { "",0.1,1,25 },0.2 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } }};
			breath4[] = {{ { { "",0.0562341,1,25 },0.2 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } },{ { { "",0.0562341,1,25 },0.2 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } },{ { { "",0.1,1,25 },0.2 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } }};
			breath5[] = {{ { { "",0.0562341,1,25 },0.2 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } },{ { { "",0.0562341,1,25 },0.2 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.19 },{ { "",0.0562341,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } },{ { { "",0.1,1,25 },0.2 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.19 },{ { "",0.1,1,25 },0.18 },{ { "",0.125893,1,25 },0.05 } }};
		};
		class SoundGear
		{
			primary[] = {{ "walk",{ "",0.00177828,1,10 } },{ "walk",{ "",0.00177828,1,10 } },{ "walk",{ "",0.00177828,1,10 } },{ "walk",{ "",0.00177828,1,10 } },{ "walk",{ "",0.00177828,1,10 } },{ "walk",{ "",0.00177828,1,10 } },{ "walk",{ "",0.00177828,1,10 } },{ "walk",{ "",0.00177828,1,10 } },{ "run",{ "",0.00316228,1,15 } },{ "run",{ "",0.00316228,1,15 } },{ "run",{ "",0.00316228,1,15 } },{ "run",{ "",0.00316228,1,15 } },{ "run",{ "",0.00316228,1,15 } },{ "run",{ "",0.00316228,1,15 } },{ "run",{ "",0.00316228,1,15 } },{ "run",{ "",0.00316228,1,15 } },{ "sprint",{ "",0.00562341,1,20 } },{ "sprint",{ "",0.00562341,1,20 } },{ "sprint",{ "",0.00562341,1,20 } },{ "sprint",{ "",0.00562341,1,20 } },{ "sprint",{ "",0.00562341,1,20 } },{ "sprint",{ "",0.00562341,1,20 } },{ "sprint",{ "",0.00562341,1,20 } },{ "sprint",{ "",0.00562341,1,20 } }};
			secondary[] = {{ "walk",{ "",0.00177828,1,10 } },{ "run",{ "",0.00316228,1,10 } },{ "sprint",{ "",0.00562341,1,10 } }};
		};
		class SoundEquipment
		{
			soldier[] = {{ "walk",{ "",0.00177828,1,13 } },{ "walk",{ "",0.00177828,1,13 } },{ "walk",{ "",0.00177828,1,13 } },{ "walk",{ "",0.00177828,1,13 } },{ "walk",{ "",0.00177828,1,13 } },{ "walk",{ "",0.00177828,1,13 } },{ "walk",{ "",0.00177828,1,13 } },{ "walk",{ "",0.00177828,1,13 } },{ "run",{ "",0.00316228,1,20 } },{ "run",{ "",0.00316228,1,20 } },{ "run",{ "",0.00316228,1,20 } },{ "run",{ "",0.00316228,1,20 } },{ "run",{ "",0.00316228,1,20 } },{ "run",{ "",0.00316228,1,20 } },{ "run",{ "",0.00316228,1,20 } },{ "run",{ "",0.00316228,1,20 } },{ "sprint",{ "",0.00398107,1,25 } },{ "sprint",{ "",0.00398107,1,25 } },{ "sprint",{ "",0.00398107,1,25 } },{ "sprint",{ "",0.00398107,1,25 } },{ "sprint",{ "",0.00398107,1,25 } },{ "sprint",{ "",0.00398107,1,25 } },{ "sprint",{ "",0.00398107,1,25 } },{ "sprint",{ "",0.00398107,1,25 } }};
			civilian[] = {{ "walk",{ "",0.177828,1,8 } },{ "walk",{ "",0.177828,1,8 } },{ "walk",{ "",0.177828,1,8 } },{ "walk",{ "",0.177828,1,8 } },{ "walk",{ "",0.177828,1,8 } },{ "walk",{ "",0.177828,1,8 } },{ "walk",{ "",0.177828,1,8 } },{ "walk",{ "",0.177828,1,8 } },{ "run",{ "",0.1,1,15 } },{ "run",{ "",0.1,1,15 } },{ "run",{ "",0.1,1,15 } },{ "run",{ "",0.1,1,15 } },{ "run",{ "",0.1,1,15 } },{ "run",{ "",0.1,1,15 } },{ "run",{ "",0.1,1,15 } },{ "run",{ "",0.1,1,15 } },{ "sprint",{ "",0.0562341,1,20 } },{ "sprint",{ "",0.0562341,1,20 } },{ "sprint",{ "",0.0562341,1,20 } },{ "sprint",{ "",0.0562341,1,20 } },{ "sprint",{ "",0.0562341,1,20 } },{ "sprint",{ "",0.0562341,1,20 } },{ "sprint",{ "",0.0562341,1,20 } },{ "sprint",{ "",0.0562341,1,20 } }};
		};
		class SoundEnvironExt
		{
			normalExt[] = {{ "",0.0199526,1,27 },{ "",0.0199526,1,27 },{ "",0.0199526,1,27 },{ "",0.0199526,1,27 },{ "",0.0199526,1,27 },{ "",0.0199526,1,27 },{ "",0.0199526,1,27 },{ "",0.0199526,1,27 },{ "run",{ "",0.0199526,1,27 } },{ "run",{ "",0.0199526,1,27 } },{ "run",{ "",0.0199526,1,27 } },{ "run",{ "",0.0199526,1,27 } },{ "run",{ "",0.0199526,1,27 } },{ "run",{ "",0.0199526,1,27 } },{ "run",{ "",0.0199526,1,27 } },{ "run",{ "",0.0199526,1,27 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "sprint",{ "",0.0199526,1,32 } },{ "sprint",{ "",0.0199526,1,32 } },{ "sprint",{ "",0.0199526,1,32 } },{ "sprint",{ "",0.0199526,1,32 } },{ "sprint",{ "",0.0199526,1,32 } },{ "sprint",{ "",0.0199526,1,32 } },{ "sprint",{ "",0.0199526,1,32 } },{ "sprint",{ "",0.0199526,1,32 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,30 } },{ "bodyfall",{ "",0.0199526,1,30 } },{ "bodyfall",{ "",0.0199526,1,30 } },{ "bodyfall",{ "",0.0199526,1,30 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,30 } },{ "ladder",{ "",0.0199526,1,30 } },{ "ladder",{ "",0.0199526,1,30 } },{ "ladder",{ "",0.0199526,1,30 } },{ "ladder",{ "",0.0199526,1,30 } },{ "ladder",{ "",0.0199526,1,30 } }};
			normal[] = {{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "sprint",{ "",0.0199526,1,35 } },{ "sprint",{ "",0.0199526,1,35 } },{ "sprint",{ "",0.0199526,1,35 } },{ "sprint",{ "",0.0199526,1,35 } },{ "sprint",{ "",0.0199526,1,35 } },{ "sprint",{ "",0.0199526,1,35 } },{ "sprint",{ "",0.0199526,1,35 } },{ "sprint",{ "",0.0199526,1,35 } },{ "crawl",{ "",0.0199526,1,15 } },{ "crawl",{ "",0.0199526,1,15 } },{ "crawl",{ "",0.0199526,1,15 } },{ "crawl",{ "",0.0199526,1,15 } },{ "standup",{ "",0.0199526,1,15 } },{ "standup",{ "",0.0199526,1,15 } },{ "standup",{ "",0.0199526,1,15 } },{ "standup",{ "",0.0199526,1,15 } },{ "laydown",{ "",0.0199526,1,15 } },{ "laydown",{ "",0.0199526,1,15 } },{ "laydown",{ "",0.0199526,1,15 } },{ "laydown",{ "",0.0199526,1,15 } },{ "bodyfall",{ "",0.0199526,1,25 } },{ "bodyfall",{ "",0.0199526,1,25 } },{ "bodyfall",{ "",0.0199526,1,25 } },{ "bodyfall",{ "",0.0199526,1,25 } },{ "swim",{ "",0.0177828,1,25 } },{ "swim",{ "",0.0177828,1,25 } },{ "swim",{ "",0.0177828,1,25 } },{ "slide",{ "",0.0199526,1,10 } },{ "slide",{ "",0.0199526,1,10 } },{ "slide",{ "",0.0199526,1,10 } },{ "ladder",{ "",0.0199526,1,25 } },{ "ladder",{ "",0.0199526,1,25 } },{ "ladder",{ "",0.0199526,1,25 } },{ "ladder",{ "",0.0199526,1,25 } },{ "ladder",{ "",0.0199526,1,25 } },{ "ladder",{ "",0.0199526,1,25 } }};
			road[] = {{ "",0.0199526,0.8,23 },{ "",0.0199526,0.8,23 },{ "",0.0199526,0.8,23 },{ "",0.0199526,0.8,23 },{ "",0.0199526,0.8,23 },{ "",0.0199526,0.8,23 },{ "",0.0199526,0.8,23 },{ "",0.0199526,0.8,23 },{ "run",{ "",0.0199526,0.8,23 } },{ "run",{ "",0.0199526,0.8,23 } },{ "run",{ "",0.0199526,0.8,23 } },{ "run",{ "",0.0199526,0.8,23 } },{ "run",{ "",0.0199526,0.8,23 } },{ "run",{ "",0.0199526,0.8,23 } },{ "run",{ "",0.0199526,0.8,23 } },{ "run",{ "",0.0199526,0.8,23 } },{ "walk",{ "",0.0199526,0.8,18 } },{ "walk",{ "",0.0199526,0.8,18 } },{ "walk",{ "",0.0199526,0.8,18 } },{ "walk",{ "",0.0199526,0.8,18 } },{ "walk",{ "",0.0199526,0.8,18 } },{ "walk",{ "",0.0199526,0.8,18 } },{ "walk",{ "",0.0199526,0.8,18 } },{ "walk",{ "",0.0199526,0.8,18 } },{ "sprint",{ "",0.0199526,0.8,30 } },{ "sprint",{ "",0.0199526,0.8,30 } },{ "sprint",{ "",0.0199526,0.8,30 } },{ "sprint",{ "",0.0199526,0.8,30 } },{ "sprint",{ "",0.0199526,0.8,30 } },{ "sprint",{ "",0.0199526,0.8,30 } },{ "sprint",{ "",0.0199526,0.8,30 } },{ "sprint",{ "",0.0199526,0.8,30 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			rock[] = {{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			water[] = {{ "",0.0562341,1,35 },{ "",0.0562341,1,35 },{ "",0.0562341,1,35 },{ "",0.0562341,1,35 },{ "",0.0562341,1,35 },{ "",0.0562341,1,35 },{ "",0.0562341,1,35 },{ "",0.0562341,1,35 },{ "run",{ "",0.0562341,1,35 } },{ "run",{ "",0.0562341,1,35 } },{ "run",{ "",0.0562341,1,35 } },{ "run",{ "",0.0562341,1,35 } },{ "run",{ "",0.0562341,1,35 } },{ "run",{ "",0.0562341,1,35 } },{ "run",{ "",0.0562341,1,35 } },{ "run",{ "",0.0562341,1,35 } },{ "walk",{ "",0.0562341,1,30 } },{ "walk",{ "",0.0562341,1,30 } },{ "walk",{ "",0.0562341,1,30 } },{ "walk",{ "",0.0562341,1,30 } },{ "walk",{ "",0.0562341,1,30 } },{ "walk",{ "",0.0562341,1,30 } },{ "walk",{ "",0.0562341,1,30 } },{ "walk",{ "",0.0562341,1,30 } },{ "sprint",{ "",0.0562341,1,40 } },{ "sprint",{ "",0.0562341,1,40 } },{ "sprint",{ "",0.0562341,1,40 } },{ "sprint",{ "",0.0562341,1,40 } },{ "sprint",{ "",0.0562341,1,40 } },{ "sprint",{ "",0.0562341,1,40 } },{ "sprint",{ "",0.0562341,1,40 } },{ "sprint",{ "",0.0562341,1,40 } },{ "crawl",{ "",0.0562341,1,20 } },{ "crawl",{ "",0.0562341,1,20 } },{ "crawl",{ "",0.0562341,1,20 } },{ "crawl",{ "",0.0562341,1,20 } },{ "standup",{ "",0.0562341,1,20 } },{ "standup",{ "",0.0562341,1,20 } },{ "standup",{ "",0.0562341,1,20 } },{ "standup",{ "",0.0562341,1,20 } },{ "laydown",{ "",0.0562341,1,20 } },{ "laydown",{ "",0.0562341,1,20 } },{ "laydown",{ "",0.0562341,1,20 } },{ "laydown",{ "",0.0562341,1,20 } },{ "bodyfall",{ "",0.0562341,1,20 } },{ "bodyfall",{ "",0.0562341,1,20 } },{ "bodyfall",{ "",0.0562341,1,20 } },{ "bodyfall",{ "",0.0562341,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "slide",{ "",0.0562341,1,20 } },{ "slide",{ "",0.0562341,1,20 } },{ "slide",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } }};
			gravel[] = {{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "crawl",{ "",0.0562341,1,20 } },{ "crawl",{ "",0.0562341,1,20 } },{ "crawl",{ "",0.0562341,1,20 } },{ "crawl",{ "",0.0562341,1,20 } },{ "standup",{ "",0.0562341,1,20 } },{ "standup",{ "",0.0562341,1,20 } },{ "standup",{ "",0.0562341,1,20 } },{ "standup",{ "",0.0562341,1,20 } },{ "laydown",{ "",0.0562341,1,20 } },{ "laydown",{ "",0.0562341,1,20 } },{ "laydown",{ "",0.0562341,1,20 } },{ "laydown",{ "",0.0562341,1,20 } },{ "bodyfall",{ "",0.0562341,1,20 } },{ "bodyfall",{ "",0.0562341,1,20 } },{ "bodyfall",{ "",0.0562341,1,20 } },{ "bodyfall",{ "",0.0562341,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "slide",{ "",0.0562341,1,20 } },{ "slide",{ "",0.0562341,1,20 } },{ "slide",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } }};
			gravel2[] = {{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "",0.0562341,1,32 },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "run",{ "",0.0562341,1,32 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "walk",{ "",0.0562341,1,26 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "sprint",{ "",0.0562341,1,36 } },{ "crawl",{ "",0.0562341,1,20 } },{ "crawl",{ "",0.0562341,1,20 } },{ "crawl",{ "",0.0562341,1,20 } },{ "crawl",{ "",0.0562341,1,20 } },{ "standup",{ "",0.0562341,1,20 } },{ "standup",{ "",0.0562341,1,20 } },{ "standup",{ "",0.0562341,1,20 } },{ "standup",{ "",0.0562341,1,20 } },{ "laydown",{ "",0.0562341,1,20 } },{ "laydown",{ "",0.0562341,1,20 } },{ "laydown",{ "",0.0562341,1,20 } },{ "laydown",{ "",0.0562341,1,20 } },{ "bodyfall",{ "",0.0562341,1,20 } },{ "bodyfall",{ "",0.0562341,1,20 } },{ "bodyfall",{ "",0.0562341,1,20 } },{ "bodyfall",{ "",0.0562341,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "slide",{ "",0.0562341,1,20 } },{ "slide",{ "",0.0562341,1,20 } },{ "slide",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } },{ "ladder",{ "",0.0562341,1,20 } }};
			sand[] = {{ "",0.0199526,1,22 },{ "",0.0199526,1,22 },{ "",0.0199526,1,22 },{ "",0.0199526,1,22 },{ "",0.0199526,1,22 },{ "",0.0199526,1,22 },{ "",0.0199526,1,22 },{ "",0.0199526,1,22 },{ "run",{ "",0.0199526,1,22 } },{ "run",{ "",0.0199526,1,22 } },{ "run",{ "",0.0199526,1,22 } },{ "run",{ "",0.0199526,1,22 } },{ "run",{ "",0.0199526,1,22 } },{ "run",{ "",0.0199526,1,22 } },{ "run",{ "",0.0199526,1,22 } },{ "run",{ "",0.0199526,1,22 } },{ "walk",{ "",0.0199526,1,18 } },{ "walk",{ "",0.0199526,1,18 } },{ "walk",{ "",0.0199526,1,18 } },{ "walk",{ "",0.0199526,1,18 } },{ "walk",{ "",0.0199526,1,18 } },{ "walk",{ "",0.0199526,1,18 } },{ "walk",{ "",0.0199526,1,18 } },{ "walk",{ "",0.0199526,1,18 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			drygrass[] = {{ "",0.01,0.9,27 },{ "",0.01,0.9,27 },{ "",0.01,0.9,27 },{ "",0.01,0.9,27 },{ "",0.01,0.9,27 },{ "",0.01,0.9,27 },{ "",0.01,0.9,27 },{ "",0.01,0.9,27 },{ "run",{ "",0.01,0.9,27 } },{ "run",{ "",0.01,0.9,27 } },{ "run",{ "",0.01,0.9,27 } },{ "run",{ "",0.01,0.9,27 } },{ "run",{ "",0.01,0.9,27 } },{ "run",{ "",0.01,0.9,27 } },{ "run",{ "",0.01,0.9,27 } },{ "run",{ "",0.01,0.9,27 } },{ "walk",{ "",0.00891251,0.9,22 } },{ "walk",{ "",0.00891251,0.9,22 } },{ "walk",{ "",0.00891251,0.9,22 } },{ "walk",{ "",0.00891251,0.9,22 } },{ "walk",{ "",0.00891251,0.9,22 } },{ "walk",{ "",0.00891251,0.9,22 } },{ "walk",{ "",0.00891251,0.9,22 } },{ "walk",{ "",0.00891251,0.9,22 } },{ "sprint",{ "",0.0177828,0.9,35 } },{ "sprint",{ "",0.0177828,0.9,35 } },{ "sprint",{ "",0.0177828,0.9,35 } },{ "sprint",{ "",0.0177828,0.9,35 } },{ "sprint",{ "",0.0177828,0.9,35 } },{ "sprint",{ "",0.0177828,0.9,35 } },{ "sprint",{ "",0.0177828,0.9,35 } },{ "sprint",{ "",0.0177828,0.9,35 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			grass[] = {{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "",0.0199526,1,23 },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "run",{ "",0.0199526,1,23 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			forest[] = {{ "",0.0199526,0.9,27 },{ "",0.0199526,0.9,27 },{ "",0.0199526,0.9,27 },{ "",0.0199526,0.9,27 },{ "",0.0199526,0.9,27 },{ "",0.0199526,0.9,27 },{ "",0.0199526,0.9,27 },{ "",0.0199526,0.9,27 },{ "run",{ "",0.0199526,0.9,27 } },{ "run",{ "",0.0199526,0.9,27 } },{ "run",{ "",0.0199526,0.9,27 } },{ "run",{ "",0.0199526,0.9,27 } },{ "run",{ "",0.0199526,0.9,27 } },{ "run",{ "",0.0199526,0.9,27 } },{ "run",{ "",0.0199526,0.9,27 } },{ "run",{ "",0.0199526,0.9,27 } },{ "walk",{ "",0.0199526,0.9,22 } },{ "walk",{ "",0.0199526,0.9,22 } },{ "walk",{ "",0.0199526,0.9,22 } },{ "walk",{ "",0.0199526,0.9,22 } },{ "walk",{ "",0.0199526,0.9,22 } },{ "walk",{ "",0.0199526,0.9,22 } },{ "walk",{ "",0.0199526,0.9,22 } },{ "walk",{ "",0.0199526,0.9,22 } },{ "sprint",{ "",0.0199526,0.9,32 } },{ "sprint",{ "",0.0199526,0.9,32 } },{ "sprint",{ "",0.0199526,0.9,32 } },{ "sprint",{ "",0.0199526,0.9,32 } },{ "sprint",{ "",0.0199526,0.9,32 } },{ "sprint",{ "",0.0199526,0.9,32 } },{ "sprint",{ "",0.0199526,0.9,32 } },{ "sprint",{ "",0.0199526,0.9,32 } },{ "crawl",{ "",0.0199526,0.9,20 } },{ "crawl",{ "",0.0199526,0.9,20 } },{ "crawl",{ "",0.0199526,0.9,20 } },{ "crawl",{ "",0.0199526,0.9,20 } },{ "standup",{ "",0.0199526,0.9,20 } },{ "standup",{ "",0.0199526,0.9,20 } },{ "standup",{ "",0.0199526,0.9,20 } },{ "standup",{ "",0.0199526,0.9,20 } },{ "laydown",{ "",0.0199526,0.9,20 } },{ "laydown",{ "",0.0199526,0.9,20 } },{ "laydown",{ "",0.0199526,0.9,20 } },{ "laydown",{ "",0.0199526,0.9,20 } },{ "bodyfall",{ "",0.0199526,0.9,20 } },{ "bodyfall",{ "",0.0199526,0.9,20 } },{ "bodyfall",{ "",0.0199526,0.9,20 } },{ "bodyfall",{ "",0.0199526,0.9,20 } },{ "swim",{ "",0.0177828,0.9,20 } },{ "swim",{ "",0.0177828,0.9,20 } },{ "swim",{ "",0.0177828,0.9,20 } },{ "slide",{ "",0.0199526,0.9,20 } },{ "slide",{ "",0.0199526,0.9,20 } },{ "slide",{ "",0.0199526,0.9,20 } },{ "ladder",{ "",0.0199526,0.9,20 } },{ "ladder",{ "",0.0199526,0.9,20 } },{ "ladder",{ "",0.0199526,0.9,20 } },{ "ladder",{ "",0.0199526,0.9,20 } },{ "ladder",{ "",0.0199526,0.9,20 } },{ "ladder",{ "",0.0199526,0.9,20 } }};
			mud[] = {{ "",0.0199526,1,19 },{ "",0.0199526,1,19 },{ "",0.0199526,1,19 },{ "",0.0199526,1,19 },{ "",0.0199526,1,19 },{ "",0.0199526,1,19 },{ "",0.0199526,1,19 },{ "",0.0199526,1,19 },{ "run",{ "",0.0199526,1,19 } },{ "run",{ "",0.0199526,1,19 } },{ "run",{ "",0.0199526,1,19 } },{ "run",{ "",0.0199526,1,19 } },{ "run",{ "",0.0199526,1,19 } },{ "run",{ "",0.0199526,1,19 } },{ "run",{ "",0.0199526,1,19 } },{ "run",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,17 } },{ "walk",{ "",0.0199526,1,17 } },{ "walk",{ "",0.0199526,1,17 } },{ "walk",{ "",0.0199526,1,17 } },{ "walk",{ "",0.0199526,1,17 } },{ "walk",{ "",0.0199526,1,17 } },{ "walk",{ "",0.0199526,1,17 } },{ "walk",{ "",0.0199526,1,17 } },{ "sprint",{ "",0.0199526,1,23 } },{ "sprint",{ "",0.0199526,1,23 } },{ "sprint",{ "",0.0199526,1,23 } },{ "sprint",{ "",0.0199526,1,23 } },{ "sprint",{ "",0.0199526,1,23 } },{ "sprint",{ "",0.0199526,1,23 } },{ "sprint",{ "",0.0199526,1,23 } },{ "sprint",{ "",0.0199526,1,23 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "swim",{ "",0.0177828,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			wood[] = {{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			wood_int[] = {{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "walk",{ "",0.0199526,1,20 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "sprint",{ "",0.0199526,1,30 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			carpet[] = {{ "",0.223872,1,13 },{ "",0.0199526,1,13 },{ "",0.223872,1,13 },{ "",0.223872,1,13 },{ "",0.223872,1,13 },{ "",0.223872,1,13 },{ "",0.223872,1,13 },{ "",0.223872,1,13 },{ "run",{ "",0.223872,1,13 } },{ "run",{ "",0.223872,1,13 } },{ "run",{ "",0.223872,1,13 } },{ "run",{ "",0.223872,1,13 } },{ "run",{ "",0.223872,1,13 } },{ "run",{ "",0.223872,1,13 } },{ "run",{ "",0.223872,1,13 } },{ "run",{ "",0.223872,1,13 } },{ "walk",{ "",0.316228,1,10 } },{ "walk",{ "",0.316228,1,10 } },{ "walk",{ "",0.316228,1,10 } },{ "walk",{ "",0.316228,1,10 } },{ "walk",{ "",0.316228,1,10 } },{ "walk",{ "",0.316228,1,10 } },{ "walk",{ "",0.316228,1,10 } },{ "walk",{ "",0.316228,1,10 } },{ "sprint",{ "",0.1,1,20 } },{ "sprint",{ "",0.1,1,20 } },{ "sprint",{ "",0.1,1,20 } },{ "sprint",{ "",0.1,1,20 } },{ "sprint",{ "",0.1,1,20 } },{ "sprint",{ "",0.1,1,20 } },{ "sprint",{ "",0.1,1,20 } },{ "sprint",{ "",0.1,1,20 } },{ "crawl",{ "",0.1,1,20 } },{ "crawl",{ "",0.1,1,20 } },{ "crawl",{ "",0.1,1,20 } },{ "crawl",{ "",0.1,1,20 } },{ "standup",{ "",0.1,1,20 } },{ "standup",{ "",0.1,1,20 } },{ "standup",{ "",0.1,1,20 } },{ "standup",{ "",0.1,1,20 } },{ "laydown",{ "",0.1,1,20 } },{ "laydown",{ "",0.1,1,20 } },{ "laydown",{ "",0.1,1,20 } },{ "laydown",{ "",0.1,1,20 } },{ "bodyfall",{ "",0.1,1,20 } },{ "bodyfall",{ "",0.1,1,20 } },{ "bodyfall",{ "",0.1,1,20 } },{ "bodyfall",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.1,1,20 } },{ "slide",{ "",0.1,1,20 } },{ "slide",{ "",0.1,1,20 } },{ "ladder",{ "",0.1,1,20 } },{ "ladder",{ "",0.1,1,20 } },{ "ladder",{ "",0.1,1,20 } },{ "ladder",{ "",0.1,1,20 } },{ "ladder",{ "",0.1,1,20 } },{ "ladder",{ "",0.1,1,20 } }};
			concrete_int[] = {{ "",0.0199526,1,24 },{ "",0.0199526,1,24 },{ "",0.0199526,1,24 },{ "",0.0199526,1,24 },{ "",0.0199526,1,24 },{ "",0.0199526,1,24 },{ "",0.0199526,1,24 },{ "",0.0199526,1,24 },{ "run",{ "",0.0199526,1,24 } },{ "run",{ "",0.0199526,1,24 } },{ "run",{ "",0.0199526,1,24 } },{ "run",{ "",0.0199526,1,24 } },{ "run",{ "",0.0199526,1,24 } },{ "run",{ "",0.0199526,1,24 } },{ "run",{ "",0.0199526,1,24 } },{ "run",{ "",0.0199526,1,24 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "sprint",{ "",0.0199526,1,26 } },{ "sprint",{ "",0.0199526,1,26 } },{ "sprint",{ "",0.0199526,1,26 } },{ "sprint",{ "",0.0199526,1,26 } },{ "sprint",{ "",0.0199526,1,26 } },{ "sprint",{ "",0.0199526,1,26 } },{ "sprint",{ "",0.0199526,1,26 } },{ "sprint",{ "",0.0199526,1,26 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			concrete_ext[] = {{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "",0.0199526,1,25 },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "run",{ "",0.0199526,1,25 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "walk",{ "",0.0199526,1,19 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "sprint",{ "",0.0199526,1,28 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			metal[] = {{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			steel[] = {{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "",0.0316228,1,37 },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "run",{ "",0.0398107,1,37 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "walk",{ "",0.0316228,1,30 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "sprint",{ "",0.0562341,1,45 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "standup",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "laydown",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "bodyfall",{ "",0.0199526,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "slide",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			hallway[] = {{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			dirt[] = {{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			parkety[] = {{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			wave_plate[] = {{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
			lepenka[] = {{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "",0.0199526,1,45 },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "run",{ "",0.0199526,1,45 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "walk",{ "",0.0199526,1,35 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "sprint",{ "",0.0199526,1,48 } },{ "crawl",{ "",0.0199526,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "crawl",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "standup",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "laydown",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "bodyfall",{ "",0.0316228,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "swim",{ "",0.1,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "slide",{ "",0.0316228,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } },{ "ladder",{ "",0.0199526,1,20 } }};
		};
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
		fsmFormation = "Formation";
		leftArmToElbow[] = {"",0.5,"",0};
		leftArmFromElbow[] = {"",0,"",0.5};
		leftWrist = "";
		leftShoulder = "";
		leftHand[] = {"","","","","","","","","","","","","","","",""};
		leftArmPoints[] = {"","","",""};
		rightArmToElbow[] = {"",0.5,"",0};
		rightArmFromElbow[] = {"",0,"",0.5};
		rightWrist = "";
		rightShoulder = "";
		rightHand[] = {"","","","","","","","","","","","","","","",""};
		rightArmPoints[] = {"","","",""};
		launcherBone = "";
		handGunBone = "";
		weaponBone = "";
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class ACE_CivDummy: ACE_DummyManBase
	{
		scope = 1;
		side = 3;
		displayName = "$STR_DN_CIVILIAN";
		nameSound = "civilian2";
		model = "\x\ace\addons\main\dummy2.p3d";
		accuracy = 0.6;
		camouflage = 2.2;
		threat[] = {0.0,0.0,0.0};
		weapons[] = {"Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnWeapons[] = {"Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {};
		cost = 100000;
		fsmFormation = "ca\characters\scripts\formationC.fsm";
		fsmDanger = "ca\characters\scripts\formationCDanger.fsm";
		formationX = 2;
		formationZ = 5;
		class Wounds
		{
			tex[] = {};
			mat[] = {};
		};
	};
};
class CfgFontFamilies
{
	class ACE_DIGIT
	{
		fonts[] = {"\x\ace\addons\main\Data\Fonts\digit\Digit8","\x\ace\addons\main\Data\Fonts\digit\Digit10","\x\ace\addons\main\Data\Fonts\digit\Digit12","\x\ace\addons\main\Data\Fonts\digit\Digit13","\x\ace\addons\main\Data\Fonts\digit\Digit14","\x\ace\addons\main\Data\Fonts\digit\Digit16","\x\ace\addons\main\Data\Fonts\digit\Digit18","\x\ace\addons\main\Data\Fonts\digit\Digit20"};
		spaceWidth = 0.9;
		spacing = 0.04;
	};
	class ACE_HANDWRITTEN
	{
		fonts[] = {"\x\ace\addons\main\Data\Fonts\handwritten\Journal8","\x\ace\addons\main\Data\Fonts\handwritten\Journal10","\x\ace\addons\main\Data\Fonts\handwritten\Journal12","\x\ace\addons\main\Data\Fonts\handwritten\Journal13","\x\ace\addons\main\Data\Fonts\handwritten\Journal14","\x\ace\addons\main\Data\Fonts\handwritten\Journal16","\x\ace\addons\main\Data\Fonts\handwritten\Journal18","\x\ace\addons\main\Data\Fonts\handwritten\Journal20"};
		spaceWidth = 0.9;
		spacing = 0.04;
	};
	class ACE_EmptyFont
	{
		fonts[] = {};
	};
};