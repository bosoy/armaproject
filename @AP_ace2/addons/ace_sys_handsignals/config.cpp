////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:06:44 2013 : Created on Sat Jun 08 13:06:44 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_handsignals : config.bin{
class CfgPatches
{
	class ace_sys_handsignals
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_sys_interaction"};
		version = "1.14.0.593";
		author[] = {"Rocko","Xeno"};
		class ACE_Options
		{
			group = "INTERACTION";
			title = "$STR_ACE_TITLE_HANDSIGNALS";
			class Mouse_Gesture
			{
				title = "$STR_ACE_TITLE_HANDSIGNALS";
			};
			class HS_STOP
			{
				title = "$STR_ACE_HANDSIGNAL_FREEZE";
			};
			class HS_GO
			{
				title = "$STR_ACE_HANDSIGNAL_GO";
			};
			class HS_COVER
			{
				title = "$STR_ACE_HANDSIGNAL_TAKECOVER";
			};
			class HS_ATTACK
			{
				title = "$STR_ACE_HANDSIGNAL_OPENFIRE";
			};
			class HS_CEASEFIRE
			{
				title = "$STR_ACE_HANDSIGNAL_CEASEFIRE";
			};
			class HS_FOLLOW
			{
				title = "$STR_ACE_HANDSIGNAL_FOLLOW";
			};
			class HS_UP
			{
				title = "$STR_ACE_HANDSIGNAL_UP";
			};
			class HS_ADVANCE
			{
				title = "$STR_ACE_HANDSIGNAL_ADVANCE";
			};
			class HS_POINT
			{
				title = "$STR_ACE_HANDSIGNAL_WATCH";
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_handsignals
	{
		clientInit = "call ('\x\ace\addons\sys_handsignals\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class ACEControlsGroup
{
	type = 15;
	idc = -1;
	style = 0;
	x = 0;
	y = 0;
	w = 0;
	h = 0;
	class VScrollbar
	{
		color[] = {1,1,1,1};
		width = 0.021;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = "false";
	};
	class HScrollbar
	{
		color[] = {1,1,1,1};
		height = 0.028;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = "false";
	};
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
	class Controls{};
};
class RscPicture;
class RscPictureKeepAspect;
class ACE_EmptyMouseGestureDialog
{
	idd = -1;
	movingEnable = 1;
	onLoad = "uiNamespace setVariable ['ACE_EmptyMouseGestureDialog', _this select 0]";
	class controls
	{
		class ABackground: RscPictureKeepAspect
		{
			idc = 999;
			x = "SafeZoneX";
			y = "SafeZoneY";
			w = "SafeZoneW";
			h = "SafeZoneH";
			colorText[] = {1,1,1,0.7};
			text = "";
		};
		class MouseHandler: ACEControlsGroup
		{
			onMouseMoving = "_this call ace_sys_handsignals_fnc_MouseMovingFunc";
			onMouseButtonDown = "_this call ace_sys_handsignals_fnc_MouseButtonDownFunc";
			onMouseButtonUp = "_this call ace_sys_handsignals_fnc_MouseButtonUpFunc";
			x = "SafeZoneX";
			y = "SafeZoneY";
			w = "SafeZoneW";
			h = "SafeZoneH";
			colorBackground[] = {0.2,0.0,0.0,0.0};
		};
	};
};
//};
