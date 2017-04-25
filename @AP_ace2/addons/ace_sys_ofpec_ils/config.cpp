class CfgPatches
{
	class ace_sys_ofpec_ils
	{
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main"};
		version = "1.14.0.597";
		author[] = {"Mandoble","OFPEC","Rocko"};
		class ACE_Options
		{
			group = "VEH";
			title = " ";
			class ils
			{
				title = "Toggle ILS";
			};
		};
	};
};
class CfgActions
{
	class None;
	class Land: None
	{
		show = 0;
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_ofpec_ils
	{
		clientInit = "call ('\x\ace\addons\sys_ofpec_ils\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class Plane
	{
		class ace_sys_ofpec_ils
		{
			clientInit = "_this call ace_sys_ofpec_ils_fnc_init";
		};
	};
};
class Extended_GetIn_EventHandlers
{
	class Plane
	{
		class ace_sys_ofpec_ils
		{
			clientGetIn = "if (player == _this select 2) then { _this call ace_sys_ofpec_ils_fnc_getIn}";
			exclude[] = {"BIS_Steerable_Parachute"};
		};
	};
};
class Extended_GetOut_EventHandlers
{
	class Plane
	{
		class ace_sys_ofpec_ils
		{
			clientGetOut = "if (player == _this select 2) then { _this call ace_sys_ofpec_ils_fnc_getOut}";
			exclude[] = {"BIS_Steerable_Parachute"};
		};
	};
};
class OFPEC_AirPortSelector
{
	idd = -1;
	movingEnable = 1;
	onload = "_this call ace_sys_ofpec_ils_fnc_onload";
	onUnload = "ace_sys_ofpec_ils_airportevents= false";
	class controls
	{
		class OFPEC_AIRPORTBACKGROUND
		{
			idc = -1;
			type = 0;
			colorText[] = {1,1,1,1};
			font = "Bitstream";
			colorBackground[] = {0,0,1,0.5};
			text = "";
			style = 128;
			sizeEx = 0.015;
			x = 0.4;
			y = 0.4;
			w = 0.2;
			h = "0.2 + 0.025*3 + 0.2";
		};
		class OFPEC_AIRPORTLIST
		{
			type = 5;
			style = 0;
			idc = 108;
			x = 0.405;
			y = "0.4+0.005";
			w = 0.19;
			h = 0.2;
			colorSelect[] = {0,1.0,0,1};
			colorSelectBackground[] = {0.4,0.4,0.4,0.4};
			colorText[] = {0.2,0.85,0,1};
			colorBackground[] = {0.0,0.0,1.0,0.8};
			font = "Bitstream";
			sizeEx = 0.02;
			rowHeight = 0.03;
			soundSelect[] = {"",0.1,1};
			autoScrollSpeed = -1;
			autoScrollDelay = 5;
			autoScrollRewind = 0;
			maxHistoryDelay = 1;
			class ScrollBar
			{
				color[] = {1,1,1,0.6};
				colorActive[] = {1,1,1,1};
				colorDisabled[] = {1,1,1,0.3};
				thumb = "#(argb,8,8,3)color(1,1,1,1)";
				arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
				arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
				border = "#(argb,8,8,3)color(1,1,1,1)";
			};
		};
		class OFPEC_ACTIVATEILS
		{
			type = 1;
			idc = -1;
			style = 2;
			x = 0.405;
			y = "0.4+0.22";
			w = 0.08;
			h = 0.04;
			sizeEx = 0.02;
			text = "$STR_OFPEC_ILS_ACTIVATE";
			action = "[""OFPEC_ACTIVATEILS"", []] call ace_sys_ofpec_ils_fnc_airportevents";
			access = 0;
			colorText[] = {0,0,0,1};
			font = "Bitstream";
			soundPush[] = {0.2,1};
			soundClick[] = {"\ca\ui\data\sound\new1",0.2,1};
			soundEscape[] = {"\ca\ui\data\sound\onescape",0.2,1};
			default = 0;
			colorDisabled[] = {0.3,0.3,0.3,1};
			colorBackground[] = {0.6,0.6,0.6,0.9};
			colorBackgroundActive[] = {0.8,0.8,0.8,0.9};
			colorBackgroundDisabled[] = {0.6,0.6,0.6,1};
			colorFocused[] = {0,0,0,1};
			colorShadow[] = {0,0,0,0.1};
			colorBorder[] = {0,0,0,1};
			offsetX = 0.004;
			offsetY = 0.004;
			offsetPressedX = 0.002;
			offsetPressedY = 0.002;
			soundEnter[] = {"\ca\ui\data\sound\onover",0.2,1};
			borderSize = 0.0;
		};
		class OFPEC_CLOSESELECTOR: OFPEC_ACTIVATEILS
		{
			x = 0.515;
			y = "0.4+0.22";
			text = "$STR_OFPEC_ILS_CANCEL";
			action = "[""OFPEC_CLOSESELECTOR"", []] call ace_sys_ofpec_ils_fnc_airportevents";
		};
	};
};
class RscTitles
{
	class ofpec_ils
	{
		idd = 100;
		movingEnable = 1;
		duration = 84600;
		fadein = 0;
		fadeout = 0;
		name = "ofpec_ils";
		onLoad = "with uiNameSpace do { ofpec_ils_disp = _this select 0 };";
		class controls
		{
			class OFPECILS_BACKGROUND
			{
				idc = 101;
				type = 0;
				colorText[] = {1,1,1,1};
				font = "Bitstream";
				colorBackground[] = {0,0,0,0};
				text = "";
				style = 128;
				sizeEx = 0.015;
				x = 0.4;
				y = 0.4;
				w = 0.2;
				h = "0.2 + 0.025*3 + 0.2";
			};
			class OFPECILS_HORBAR
			{
				idc = 102;
				type = 0;
				style = 48;
				font = "Bitstream";
				sizeEx = 0.04;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0,0.5,0,0.5};
				text = "\x\ace\addons\sys_ofpec_ils\data\ofpec_horiz.paa";
				x = "0.5-0.1";
				y = "0.5-0.05/2";
				w = 0.2;
				h = 0.05;
			};
			class OFPECILS_VERTBAR: OFPECILS_HORBAR
			{
				idc = 103;
				text = "\x\ace\addons\sys_ofpec_ils\data\ofpec_vert.paa";
				x = "0.5-0.03/2";
				y = "0.5-0.1";
				w = 0.04;
				h = 0.2;
			};
			class OFPECILS_AIMF: OFPECILS_VERTBAR
			{
				idc = 104;
				text = "\x\ace\addons\sys_ofpec_ils\data\ofpec_circle.paa";
				y = "0.5-0.05/2";
				h = 0.05;
			};
			class OFPECILS_AIMB: OFPECILS_AIMF
			{
				idc = 105;
				text = "\x\ace\addons\sys_ofpec_ils\data\ofpec_rect.paa";
			};
			class OFPECILS_TARGET
			{
				idc = 106;
				type = 0;
				style = 0;
				x = "0.5-0.1+0.005";
				y = "0.4 + 0.2";
				w = 0.19;
				h = 0.03;
				colorText[] = {0,1,0,1};
				colorBackground[] = {0,0,0,1};
				font = "Bitstream";
				sizeEx = 0.02;
				text = "";
			};
			class OFPECILS_RANGE: OFPECILS_TARGET
			{
				idc = 107;
				y = "0.4 + 0.2+0.023";
				w = 0.19;
			};
			class OFPECILS_ALT: OFPECILS_TARGET
			{
				idc = 108;
				y = "0.4 + 0.2+0.023*2";
			};
			class OFPECILS_CROSS: OFPECILS_TARGET
			{
				idc = 110;
				style = 48;
				sizeEx = 0.04;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0,1,0,0.5};
				text = "\x\ace\addons\sys_ofpec_ils\data\ofpec_cross.paa";
				x = "0.5-0.02";
				y = "0.5-0.025";
				w = 0.04;
				h = 0.05;
			};
			class OFPECILS_SPEEDWARN
			{
				idc = 111;
				type = 0;
				style = 0;
				x = "0.5-0.1+0.005";
				y = "0.5 + 0.1 - 0.04";
				w = 0.19;
				h = 0.03;
				colorText[] = {0,1,0,1};
				colorBackground[] = {0,0,0,0};
				font = "Bitstream";
				sizeEx = 0.02;
				text = "";
			};
			class OFPECILS_ALTWARN: OFPECILS_SPEEDWARN
			{
				idc = 112;
				x = "0.5+0.04";
				y = "0.5 + 0.1 - 0.04";
			};
		};
	};
};
class CfgSounds
{
	class ofpec_destination
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_ofpec_ils\sound\ofpec_destination.ogg","db+25",1.0};
		titles[] = {};
	};
	class ofpec_enabled
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_ofpec_ils\sound\ofpec_enabled.ogg","db+25",1.0};
		titles[] = {};
	};
	class ofpec_final_aproach
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_ofpec_ils\sound\ofpec_final_aproach.ogg","db+25",1.0};
		titles[] = {};
	};
	class ofpec_firstwp
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_ofpec_ils\sound\ofpec_firstwp.ogg","db+25",1.0};
		titles[] = {};
	};
	class ofpec_toofast
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_ofpec_ils\sound\ofpec_toofast.ogg","db+25",1.0};
		titles[] = {};
	};
	class ofpec_toohigh
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_ofpec_ils\sound\ofpec_toohigh.ogg","db+25",1.0};
		titles[] = {};
	};
	class ofpec_toolow
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_ofpec_ils\sound\ofpec_toolow.ogg","db+25",1.0};
		titles[] = {};
	};
	class ofpec_tooslow
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_ofpec_ils\sound\ofpec_tooslow.ogg","db+25",1.0};
		titles[] = {};
	};
	class ofpec_outermarker
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_ofpec_ils\sound\Outer_marker.ogg","db+10",1.0};
		titles[] = {};
	};
	class ofpec_middlemarker
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_ofpec_ils\sound\Middle_marker.ogg","db+10",1.0};
		titles[] = {};
	};
	class ofpec_innermarker
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_ofpec_ils\sound\Inner_marker.ogg","db+10",1.0};
		titles[] = {};
	};
	class ofpec_clear
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_ofpec_ils\sound\clear.ogg","db+10",1.0};
		titles[] = {};
	};
};