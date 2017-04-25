////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:46:10 2013 : Created on Sat Apr 06 11:46:10 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_playerhud : config.bin{
class CfgPatches
{
	class ace_sys_playerhud
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main"};
		version = "1.14.0.590";
		author[] = {"Xeno"};
		class ACE_Options
		{
			group = "OTHER";
			title = " ";
		};
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ACE_SYS_Force1st_Logic: ACE_Logic
	{
		displayName = "$STR_ACE_PHUD_1st_ENABLE";
		icon = "\x\ace\addons\sys_playerhud\data\icon\icon_sys_phud_1st_ca.paa";
		picture = "\x\ace\addons\sys_playerhud\data\icon\icon_sys_phud_1st_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then {ace_sys_playerhud_force1st = true; publicVariable 'ace_sys_playerhud_force1st'}";
		};
	};
	class ACE_SYS_PRespawn_Logic: ACE_Logic
	{
		displayName = "$STR_ACE_PHUD_RESP_ENABLE";
		icon = "\x\ace\addons\sys_playerhud\data\icon\icon_sys_prespawn_ca.paa";
		picture = "\x\ace\addons\sys_playerhud\data\icon\icon_sys_prespawn_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then {ace_sys_playerhud_withresp = true; publicVariable 'ace_sys_playerhud_withresp'}";
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_playerhud
	{
		clientInit = "call ('\x\ace\addons\sys_playerhud\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_playerhud
	{
		clientInit = "call ('\x\ace\addons\sys_playerhud\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class RscPicture;
class ACE_GDF_RscActiveText
{
	access = 0;
	type = 11;
	style = 2;
	color[] = {0,0,0,1};
	colorActive[] = {0.3,0.4,0,1};
	soundEnter[] = {"",0.1,1};
	soundPush[] = {"",0.1,1};
	soundClick[] = {"",0.1,1};
	soundEscape[] = {"",0.1,1};
	text = "";
	default = 0;
	idc = -1;
	x = 0;
	y = 0;
	h = 0.035;
	w = 0.035;
	font = "Zeppelin32";
	shadow = 2;
	sizeEx = 0.03921;
	colortext[] = {0,0,0,1};
};
class ACE_GDF_RscPicture
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
	fixedWidth = 0;
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.2;
	h = 0.15;
};
class ACE_GDF_RscControlsGroup
{
	class VScrollbar
	{
		color[] = {1,1,1,1};
		width = 0.001;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = 0;
		shadow = 0;
	};
	class HScrollbar
	{
		color[] = {1,1,1,1};
		height = 0.001;
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
class RscTitles
{
	class ACE_PHud_Stance
	{
		idd = -1;
		movingEnable = "false";
		fadein = 0;
		fadeout = 0;
		duration = 1e+011;
		name = "ACE_PHud_Stance";
		onload = "uiNamespace setVariable ['ACE_PHud_Stance', _this select 0]";
		class controls
		{
			class ACE_PH_StanceIndicator
			{
				type = 0;
				idc = 1000;
				style = 48;
				x = "SafeZoneX + SafeZoneW - 0.06";
				y = "SafeZoneY + 0.06";
				w = 0.04;
				h = 0.04;
				font = "Zeppelin32";
				sizeEx = 0.023;
				colorText[] = {0.4,0.6745,0.2784,0.7};
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class ACE_PH_WalkingToggleIndicator: ACE_PH_StanceIndicator
			{
				idc = 1001;
				x = "SafeZoneX + SafeZoneW - 0.04";
				y = "SafeZoneY + 0.06";
				w = 0.04;
				h = 0.04;
			};
		};
	};
	class ACE_RscGearFast
	{
		idd = -1;
		movingEnable = 1;
		duration = 20;
		fadein = 0;
		fadeout = 0;
		name = "ACE_RscGearFast";
		onLoad = "uiNamespace setVariable ['ACE_RscGearFast', _this select 0];call ace_sys_playerhud_fnc_fillgdfdialog";
		class controls
		{
			class G_GearItems: ACE_GDF_RscControlsGroup
			{
				idc = 1000;
				x = "SafeZoneX + SafeZoneW + 0.01";
				y = 0.3;
				w = 0.228;
				h = 0.55;
				class Controls
				{
					class CA_Gear_slot_item1: ACE_GDF_RscActiveText
					{
						idc = 109;
						x = 0;
						y = 0;
						w = 0.055;
						h = 0.074;
						style = "0x30+ 0x800";
						color[] = {1,1,1,0.6};
						colorBackground[] = {0.6,0.8392,0.4706,1.0};
						colorBackgroundSelected[] = {0.6,0.8392,0.4706,1.0};
						colorFocused[] = {0.0,0.0,0.0,0};
					};
					class CA_Gear_slot_item2: CA_Gear_slot_item1
					{
						idc = 110;
						x = 0.057;
						y = 0;
					};
					class CA_Gear_slot_item3: CA_Gear_slot_item1
					{
						idc = 111;
						x = 0.114;
						y = 0;
					};
					class CA_Gear_slot_item4: CA_Gear_slot_item1
					{
						idc = 112;
						x = 0.171;
						y = 0;
					};
					class CA_Gear_slot_item5: CA_Gear_slot_item1
					{
						idc = 113;
						x = 0;
						y = 0.077;
					};
					class CA_Gear_slot_item6: CA_Gear_slot_item1
					{
						idc = 114;
						x = 0.057;
						y = 0.077;
					};
					class CA_Gear_slot_item7: CA_Gear_slot_item1
					{
						idc = 115;
						x = 0.114;
						y = 0.077;
					};
					class CA_Gear_slot_item8: CA_Gear_slot_item7
					{
						idc = 116;
						x = 0.171;
						y = 0.077;
					};
					class CA_Gear_slot_item9: CA_Gear_slot_item7
					{
						idc = 117;
						x = 0;
						y = 0.154;
					};
					class CA_Gear_slot_item10: CA_Gear_slot_item7
					{
						idc = 118;
						x = 0.057;
						y = 0.154;
					};
					class CA_Gear_slot_item11: CA_Gear_slot_item7
					{
						idc = 119;
						x = 0.114;
						y = 0.154;
					};
					class CA_Gear_slot_item12: CA_Gear_slot_item7
					{
						idc = 120;
						x = 0.171;
						y = 0.154;
					};
					class CA_Gear_slot_handgun_item1: CA_Gear_slot_item1
					{
						idc = 122;
						x = 0;
						y = 0.274;
						w = 0.055;
						h = 0.074;
					};
					class CA_Gear_slot_handgun_item2: CA_Gear_slot_handgun_item1
					{
						idc = 123;
						x = 0.057;
						y = 0.274;
					};
					class CA_Gear_slot_handgun_item3: CA_Gear_slot_handgun_item1
					{
						idc = 124;
						x = 0.114;
						y = 0.274;
					};
					class CA_Gear_slot_handgun_item4: CA_Gear_slot_handgun_item1
					{
						idc = 125;
						x = 0.171;
						y = 0.274;
					};
					class CA_Gear_slot_handgun_item5: CA_Gear_slot_handgun_item1
					{
						idc = 126;
						x = 0;
						y = 0.35099998;
					};
					class CA_Gear_slot_handgun_item6: CA_Gear_slot_handgun_item5
					{
						idc = 127;
						x = 0.057;
						y = 0.35099998;
					};
					class CA_Gear_slot_handgun_item7: CA_Gear_slot_handgun_item5
					{
						idc = 128;
						x = 0.114;
						y = 0.35099998;
					};
					class CA_Gear_slot_handgun_item8: CA_Gear_slot_handgun_item5
					{
						idc = 129;
						x = 0.171;
						y = 0.35099998;
					};
					class ACE_IFAK_1PGDF: ACE_GDF_RscPicture
					{
						idc = 1050;
						style = "0x30+ 0x800";
						x = 0.025;
						y = 0.42799997;
						w = 0.043;
						h = 0.043;
						colorText[] = {1,1,1,0.6};
						text = "";
					};
					class ACE_IFAK_2PGDF: ACE_IFAK_1PGDF
					{
						idc = 1051;
						x = 0.082;
					};
					class ACE_IFAK_3PGDF: ACE_IFAK_1PGDF
					{
						idc = 1052;
						x = 0.139;
					};
					class ACE_IFAK_1CGDF: ACE_GDF_RscActiveText
					{
						idc = 1100;
						style = "0x02";
						x = 0.029;
						y = 0.48299998;
						w = 0.043;
						h = "0.043* 0.7";
						sizeEx = 0.03521;
						color[] = {0.4,0.6745,0.2784,0.6};
						colorActive[] = {0.4,0.6745,0.2784,0.5};
						colorText[] = {0.4,0.6745,0.2784,0.5};
						text = "";
					};
					class ACE_IFAK_2CGDF: ACE_IFAK_1CGDF
					{
						idc = 1101;
						x = 0.085999995;
					};
					class ACE_IFAK_3CGDF: ACE_IFAK_1CGDF
					{
						idc = 1102;
						x = 0.14299999;
					};
				};
			};
		};
	};
};
//};
