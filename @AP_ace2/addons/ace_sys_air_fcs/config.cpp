////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:05:37 2013 : Created on Sat Jun 08 13:05:37 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_air_fcs : config.bin{
class CfgPatches
{
	class ace_sys_air_fcs
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_sys_vehicle","ace_sys_missileguidance","ace_sys_mfd"};
		version = "1.14.0.593";
		author[] = {"Headspace","q1184","zGuba"};
		class ACE_Options
		{
			title = "FCS (Air)";
			group = "VEH";
			class Lase
			{
				title = "Toggle Laser";
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_air_fcs
	{
		init = "call ('\x\ace\addons\sys_air_fcs\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_air_fcs
	{
		clientInit = "call ('\x\ace\addons\sys_air_fcs\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class Mi24_P
	{
		class ace_sys_air_fcs_dot
		{
			clientInit = "if (player in (_this select 0)) then { [] spawn ace_sys_air_fcs_fnc_enableDot}";
		};
	};
};
class Extended_FiredBIS_EventHandlers
{
	class AH1_Base
	{
		class ace_sys_air_fcs
		{
			clientFiredBis = "if (player == gunner (_this select 0)) then { if ((_this select 4) isKindOf 'BulletBase') then { if !(isnil {((_this select 0) getvariable 'ace_sys_air_fcs_fired')}) then { _this call ace_sys_air_fcs_fnc_fired }}};";
		};
	};
	class AH64_base_EP1
	{
		class ace_sys_air_fcs
		{
			clientFiredBis = "if (player == gunner (_this select 0)) then { if ((_this select 4) isKindOf 'BulletBase') then { if !(isnil {((_this select 0) getvariable 'ace_sys_air_fcs_fired')}) then { _this call ace_sys_air_fcs_fnc_fired }}};";
		};
	};
	class Kamov_Base
	{
		class ace_sys_air_fcs
		{
			clientFiredBis = "if (player == gunner (_this select 0)) then { if ((_this select 4) isKindOf 'BulletBase') then { if !(isnil {((_this select 0) getvariable 'ace_sys_air_fcs_fired')}) then { _this call ace_sys_air_fcs_fnc_fired }}};";
		};
	};
	class Mi24_Base
	{
		class ace_sys_air_fcs
		{
			clientFiredBis = "if (player == gunner (_this select 0)) then { if ((_this select 4) isKindOf 'BulletBase') then { if !(isnil {((_this select 0) getvariable 'ace_sys_air_fcs_fired')}) then { _this call ace_sys_air_fcs_fnc_fired }}};";
		};
	};
};
class Extended_GetIn_EventHandlers
{
	class Air
	{
		ace_sys_air_fcs = "_this call ace_sys_air_fcs_fnc_loop";
	};
};
class Extended_GetOut_EventHandlers{};
class ace_sys_air_fcs_RscPicture
{
	type = 0;
	idc = -1;
	style = 48;
	x = 0.1;
	y = 0.1;
	w = 0.4;
	h = 0.2;
	sizeEx = 0.023;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = "Zeppelin32";
	text = "";
};
class RscTitles
{
	class AH1Z_MFD_Text
	{
		idc = -1;
		access = 0;
		type = 0;
		style = "0x00";
		font = "TahomaB";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		sizeEx = 0.04;
	};
	class AH1Z_MFD_Display
	{
		idd = "AH1Z_MFD_Control_IDC";
		onLoad = "private ['_dummy']; _dummy = _this spawn ace_sys_air_fcs_fnc_mfdloop; _dummy;";
		movingEnable = "false";
		duration = 100000;
		fadein = 0;
		fadeout = 0;
		name = "AH-1Z Gunner MFD";
		controls[] = {"AH1Z_MFD_HeadingText","AH1Z_MFD_TimeText","AH1Z_MFD_TOFText","AH1Z_MFD_WeaponIndicator","AH1Z_MFD_DesignatorStatus","AH1Z_MFD_RangeText","AH1Z_MFD_DesignatorCircle","AH1Z_MFD_ATTKIndicator","AH1Z_MFD_Cross"};
		class AH1Z_MFD_HeadingText: AH1Z_MFD_Text
		{
			idc = 693001;
			style = "0x02";
			x = 0.3;
			y = 0.1;
			w = 0.4;
			h = 0.03;
			text = "000";
		};
		class AH1Z_MFD_TimeText: AH1Z_MFD_Text
		{
			idc = 693002;
			style = "0x00";
			x = 0.1;
			y = 0.18;
			w = 0.2;
			h = 0.2;
			text = "00:00:00";
		};
		class AH1Z_MFD_TOFText: AH1Z_MFD_Text
		{
			idc = 693009;
			style = "0x00";
			x = 0.1;
			y = 0.64;
			w = 0.2;
			h = 0.2;
			text = "TOF 0.0";
		};
		class AH1Z_MFD_WeaponIndicator: AH1Z_MFD_Text
		{
			idc = 693003;
			style = "0x00";
			x = 0.85;
			y = 0.11;
			w = 0.2;
			h = 0.2;
			text = "HF";
		};
		class AH1Z_MFD_DesignatorStatus: AH1Z_MFD_Text
		{
			idc = 693004;
			style = "0x00";
			x = 0.85;
			y = 0.18;
			w = 0.2;
			h = 0.2;
			text = "DES";
		};
		class AH1Z_MFD_RangeText: AH1Z_MFD_Text
		{
			idc = 693005;
			x = 0.3;
			y = 0.75;
			w = 0.4;
			h = 0.2;
			style = "0x02";
			text = "0000";
		};
		class AH1Z_MFD_DesignatorCircle: AH1Z_MFD_Text
		{
			idc = 693006;
			x = 0.452;
			y = 0.45;
			w = 0.1;
			h = 0.12;
			style = 48;
			text = "x\ace\addons\sys_air_fcs\data\AH1Z_laser_reticle.paa";
		};
		class AH1Z_MFD_DesignatorCircleD: AH1Z_MFD_Text
		{
			idc = 693007;
			x = 0.458;
			y = 0.45;
			w = 0.1;
			h = 0.12;
			style = 48;
			text = "x\ace\addons\sys_air_fcs\data\AH1Z_laser_reticle_dashed.paa";
		};
		class AH1Z_MFD_ATTKIndicator: AH1Z_MFD_Text
		{
			idc = 693008;
			x = 0.06;
			y = 0.4;
			w = 0.1;
			h = 0.17;
			style = 48;
			text = "x\ace\addons\sys_air_fcs\data\AH1Z_attk_indicator.paa";
		};
		class AH1Z_MFD_Cross
		{
			idc = 693010;
			type = 0;
			style = "48 + 0x800";
			movingEnable = 1;
			font = "TahomaB";
			colorBackground[] = {0,0,0,0};
			colorText[] = {0,1,0,0.5};
			text = "\ca\UI\Data\cursor_uav_gs.paa";
			sizeEx = 0.03;
			x = 0.5;
			y = 0.5;
			w = 0.1;
			h = 0.1;
			size = 0.034;
			shadow = 0;
			fixedWidth = 0;
			lineSpacing = 0;
		};
	};
	class AH64_MFD_Display: AH1Z_MFD_Display
	{
		class AH1Z_MFD_DesignatorCircle: AH1Z_MFD_DesignatorCircle
		{
			x = 0.35;
			y = 0.35;
			w = 0.3;
			h = 0.3;
			text = "x\ace\addons\sys_air_fcs\data\AH64_laser_reticle.paa";
		};
		class AH1Z_MFD_ATTKIndicator: AH1Z_MFD_ATTKIndicator
		{
			text = "x\ace\addons\sys_air_fcs\data\AH64_attk_indicator.paa";
		};
	};
	class Generic_Russian_Display: AH1Z_MFD_Display
	{
		idd = 694000;
		onLoad = "private ['_dummy']; _dummy = _this spawn ace_sys_air_fcs_fnc_rfloop; _dummy;";
		name = "Generic Russian rangefinder";
		controls[] = {"Generic_Russian_Display_HeadingText","Generic_Russian_Display_RangeText","Generic_Russian_Display_LaunchAuthorization","Generic_Russian_Display_Cross","Generic_Russian_Display_Range","Generic_Russian_Display_LaunchAuthorization2"};
		class Generic_Russian_Display_HeadingText: AH1Z_MFD_HeadingText
		{
			idc = 694001;
			colorText[] = {1,1,0,1};
		};
		class Generic_Russian_Display_RangeText: AH1Z_MFD_RangeText
		{
			idc = 694002;
			colorText[] = {1,1,0,1};
			text = "0.0";
		};
		class Generic_Russian_Display_LaunchAuthorization: AH1Z_MFD_DesignatorStatus
		{
			idc = 694003;
			x = 0.3;
			y = 0.65;
			w = 0.4;
			h = 0.2;
			colorText[] = {1,1,0,1};
			style = "0x02";
			text = "$STR_ACE_IDN_LAUNCHAUTHORIZATION_RU";
		};
		class Generic_Russian_Display_Cross
		{
			idc = 694004;
			type = 0;
			style = "48 + 0x800";
			movingEnable = 1;
			font = "TahomaB";
			colorBackground[] = {0,0,0,0};
			colorText[] = {0,1,0,0.5};
			text = "x\ace\addons\sys_air_fcs\data\crossdot_ca.paa";
			sizeEx = 0.03;
			x = 0.5;
			y = 0.5;
			w = 0.1;
			h = 0.1;
			size = 0.034;
			shadow = 0;
			fixedWidth = 0;
			lineSpacing = 0;
		};
		class Generic_Russian_Display_Range: Generic_Russian_Display_Cross
		{
			idc = 694005;
			style = "0x02";
			colorText[] = {0,1,0,0.5};
			text = "0.0";
			w = 0.05;
			h = 0.05;
		};
		class Generic_Russian_Display_LaunchAuthorization2: Generic_Russian_Display_Range
		{
			idc = 694006;
			text = "$STR_ACE_IDN_LAUNCHAUTHORIZATION_RU";
		};
	};
	class ace_sys_air_fcs_dot
	{
		idd = -1;
		movingEnable = 0;
		duration = 1e+011;
		fadein = 1;
		fadeout = 1;
		name = "ace_test_dot";
		sizeEx = 256;
		onLoad = "uiNamespace setVariable ['ace_test_dot', _this select 0]";
		class controls
		{
			class picture: ace_sys_air_fcs_RscPicture
			{
				idc = 66666;
				x = 0.45;
				y = 0.45;
				w = 0.1;
				h = 0.1;
				text = "\x\ace\addons\sys_air_fcs\circle_ca.paa";
				sizeEx = 256;
			};
		};
	};
	class ACE_Kh29Cursor
	{
		idd = -1;
		onLoad = "with uiNameSpace do { ACE_Kh29Cursor = _this select 0 }";
		movingEnable = 1;
		duration = 10000;
		fadeIn = 0;
		fadeOut = 0;
		controls[] = {"Cross","Range","Tti"};
		class Cross
		{
			idc = 1;
			type = 0;
			style = "48 + 0x800";
			movingEnable = 1;
			font = "TahomaB";
			colorBackground[] = {0,0,0,0};
			colorText[] = {1,1,0,1};
			text = "\ca\UI\Data\cursor_uav_gs.paa";
			sizeEx = 0.03;
			x = 0.5;
			y = 0.5;
			w = 0.1;
			h = 0.1;
			size = 0.034;
			shadow = 0;
			fixedWidth = 0;
			lineSpacing = 0;
		};
		class Range: Cross
		{
			idc = 2;
			style = "0x02";
			colorText[] = {0,0,0,0};
			text = "";
			w = 0.05;
			h = 0.05;
		};
		class Tti: Range
		{
			idc = 3;
		};
	};
};
class RscControlsGroup;
class RscPicture;
class RscLine;
class RscOpticsValue;
class RscText;
class RscIGText;
class RscIGProgress;
class RscIGUIText;
class RscIGUIValue;
class RscEdit;
class RscListBox;
class ace_sys_air_fcs_RscText
{
	idc = -1;
	access = 0;
	type = 0;
	style = "0x02";
	font = "TahomaB";
	colorText[] = {1,1,1,1};
	colorBackground[] = {0,0,0,0};
	sizeEx = 0.04;
};
class RscInGameUI
{
	class RscUnitInfo;
	class RscUnitInfo_AH64D_gunner
	{
		controls[] = {"CA_VisionMode","CA_FlirMode","CA_FOVMode","CA_Compass","CA_Heading","CA_Autohover","CA_BallRange"};
	};
	class ACE_RscUnitInfo_Ru_Gunner
	{
		idd = 300;
		onLoad = "uiNameSpace setVariable ['ACE_RscUnitInfo_Ru_Gunner',_this select 0]; [] call ace_sys_air_fcs_fnc_ru_gunner;";
		onUnload = "uiNameSpace setVariable ['ACE_RscUnitInfo_Ru_Gunner',nil];";
		controls[] = {"Optics"};
		class Optics: RscControlsGroup
		{
			x = "SafezoneX";
			y = "SafezoneY";
			w = "SafezoneW-SafezoneX";
			h = "SafezoneH-SafezoneY";
			idc = 170;
			class VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class Generic_Russian_Display_HeadingText: ace_sys_air_fcs_RscText
				{
					idc = 694001;
					x = "0.3-SafezoneX";
					y = "0.1-SafezoneY";
					w = 0.4;
					h = 0.03;
					text = "000";
					colorText[] = {1,1,0,1};
				};
				class Generic_Russian_Display_RangeText: ace_sys_air_fcs_RscText
				{
					idc = 694002;
					x = "0.3-SafezoneX";
					y = "0.75-SafezoneY";
					w = 0.4;
					h = 0.2;
					text = "0.0";
					colorText[] = {1,1,0,1};
				};
				class Generic_Russian_Display_LaunchAuthorization: ace_sys_air_fcs_RscText
				{
					idc = 694003;
					x = "0.3-SafezoneX";
					y = "0.65-SafezoneY";
					w = 0.4;
					h = 0.2;
					colorText[] = {1,1,0,1};
					text = "$STR_ACE_IDN_LAUNCHAUTHORIZATION_RU";
				};
			};
		};
	};
	class RscUnitInfoAir;
	class ACE_RscUnitInfoAir: RscUnitInfoAir
	{
		class ACE_ControlsGroup: RscControlsGroup
		{
			x = "SafezoneX";
			y = "SafezoneY";
			w = "SafezoneW";
			h = "SafezoneH";
			idc = 1234;
			class VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls;
		};
	};
	class ACE_RscUnitInfo_Ru_Pilot: ACE_RscUnitInfoAir
	{
		onLoad = "uiNameSpace setVariable ['ACE_RscUnitInfo_Ru_Pilot',_this select 0]; [] call ace_sys_air_fcs_fnc_ru_pilot;";
		onUnload = "uiNameSpace setVariable ['ACE_RscUnitInfo_Ru_Pilot',nil];";
		class ACE_ControlsGroup: ACE_ControlsGroup
		{
			class Controls: Controls
			{
				class Generic_Russian_Display_Cross
				{
					idc = 694004;
					type = 0;
					style = "48 + 0x800";
					movingEnable = 1;
					font = "TahomaB";
					colorBackground[] = {0,0,0,0};
					colorText[] = {0,1,0,0.5};
					text = "x\ace\addons\sys_air_fcs\data\crossdot_ca.paa";
					sizeEx = 0.03;
					x = "0.5-SafezoneX";
					y = "0.5-SafezoneY";
					w = 0.1;
					h = 0.1;
					size = 0.034;
					shadow = 0;
					fixedWidth = 0;
					lineSpacing = 0;
				};
				class Generic_Russian_Display_Range: Generic_Russian_Display_Cross
				{
					idc = 694005;
					style = "0x02";
					colorText[] = {0,1,0,0.5};
					text = "0.0";
					w = 0.05;
					h = 0.05;
				};
				class Generic_Russian_Display_LaunchAuthorization2: Generic_Russian_Display_Range
				{
					idc = 694006;
					text = "$STR_ACE_IDN_LAUNCHAUTHORIZATION_RU";
				};
			};
		};
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class 750Rnd_M197_AH1: VehicleMagazine
	{
		ace_air_fcs_drop[] = {0,0.046,0.188,0.44,0.799,1.305,1.952,2.78,3.753,4.976,6.375,7.937,9.802,12.079,14.542,17.461,20.845,24.452,28.889,33.396,39.127,44.934,51.511,59.324,67.602,77.284,87.468,99.232,112.196,127.026,143.394,161.393,181.038,203.114,227.769,255.477,285.924,319.791,356.519,398.99,444.681,495.758,553.501,617.565,688.251,766.69};
		ace_air_fcs_time[] = {0,0.11,0.21,0.32,0.43,0.56,0.68,0.76,0.94,1.09,1.24,1.39,1.56,1.74,1.93,2.14,2.34,2.55,2.79,3.01,3.28,3.54,3.81,4.11,4.42,4.75,5.08,5.44,5.82,6.22,6.64,7.08,7.54,8.02,8.54,9.08,9.67,10.25,10.87,11.55,12.25,12.99,13.79,14.63,15.52,16.45};
		ace_air_fcs_maxrange = 4500;
	};
	class 1200Rnd_30x113mm_M789_HEDP: VehicleMagazine
	{
		ace_air_fcs_drop[] = {0,0.078,0.326,0.763,1.384,2.291,3.503,4.902,6.788,8.966,11.616,14.901,18.667,23.049,28.161,33.917,40.978,48.59,57.658,68.331,79.884,93.695,109.004,126.798,146.419,169.24,195.344,224.755,258.072,295.507,338.298,387.098,442.748,506.299,578.148,660.062,754.127,862.573,988.416,1133.79,1304.58};
		ace_air_fcs_time[] = {0,0.15,0.29,0.43,0.57,0.74,0.93,1.09,1.29,1.51,1.72,1.96,2.21,2.47,2.75,3.04,3.38,3.69,4.05,4.44,4.84,5.28,5.71,6.2,6.71,7.26,7.86,8.47,9.14,9.82,10.57,11.37,12.23,13.16,14.16,15.21,16.36,17.61,19,20.53,22.23};
		ace_air_fcs_maxrange = 4500;
	};
	class 230Rnd_30mmHE_2A42: VehicleMagazine
	{
		ace_air_fcs_drop[] = {0,0.052,0.219,0.468,0.881,1.424,2.092,2.884,3.918,4.961,6.278,7.743,9.542,11.29,13.438,15.71,18.42,21.071,24.146,27.379,31.166,35.151,39.329,44.077,49.067,54.345,59.838,66.024,73.016,79.821,87.334,95.286,103.997,113.574,123.124,134.028,144.693,157.072,169.233,183.218,196.953,212.634,228.853,245.739,263.901,283.562};
		ace_air_fcs_time[] = {0,0.12,0.23,0.33,0.45,0.56,0.68,0.8,0.95,1.05,1.19,1.33,1.48,1.61,1.77,1.92,2.08,2.24,2.4,2.57,2.76,2.93,3.11,3.31,3.5,3.7,3.89,4.12,4.33,4.55,4.77,5,5.24,5.5,5.74,6.02,6.27,6.55,6.83,7.13,7.41,7.73,8.04,8.36,8.69,9.04};
		ace_air_fcs_maxrange = 4500;
	};
	class 230Rnd_30mmAP_2A42: 230Rnd_30mmHE_2A42
	{
		ace_air_fcs_drop[] = {0,0.037,0.16,0.369,0.657,1.048,1.553,2.121,2.895,3.678,4.68,5.797,7.022,8.362,9.817,11.391,13.482,15.734,17.641,20.158,22.826,25.676,28.977,32.147,35.753,39.882,44.212,48.379,53.492,58.447,64.129,69.974,76.48,83.372,90.407,98.297,106.374,115.314,124.625,134.297,144.81,155.82,167.811,180.148,193.726,207.617};
		ace_air_fcs_time[] = {0,0.1,0.2,0.29,0.39,0.49,0.59,0.69,0.8,0.91,1.03,1.15,1.27,1.4,1.52,1.63,1.8,1.93,2.05,2.2,2.35,2.5,2.67,2.82,3,3.17,3.34,3.51,3.71,3.89,4.09,4.28,4.49,4.71,4.92,5.15,5.37,5.61,5.87,6.1,6.37,6.61,6.88,7.16,7.44,7.73};
		ace_air_fcs_maxrange = 4500;
	};
	class 1470Rnd_127x108_YakB: VehicleMagazine
	{
		ace_air_fcs_drop[] = {0,0.07,0.32,0.73,1.421,2.353,3.634,5.389,7.61,10.419,13.868,18.186,23.562,30.214,38.084,48.007,59.895,74.297,91.525,112.362,137.786};
		ace_air_fcs_time[] = {0,0.14,0.25,0.41,0.57,0.75,0.94,1.16,1.4,1.65,1.93,2.23,2.57,2.95,3.34,3.79,4.28,4.81,5.38,6.02,6.71};
		ace_air_fcs_maxrange = 2000;
	};
};
class CfgVehicles
{
	class Air;
	class Helicopter: Air
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class AH1_Base: Helicopter
	{
		ace_air_fcs_enabled = 1;
	};
	class AH64_base_EP1: Helicopter
	{
		ace_air_fcs_enabled = 1;
	};
	class Mi24_Base: Helicopter
	{
		ace_air_fcs_enabled = 1;
	};
	class Kamov_Base: Helicopter
	{
		ace_air_fcs_enabled = 1;
	};
	class AW159_Lynx_BAF: Helicopter
	{
		ace_air_fcs_enabled = 1;
	};
};
//};
