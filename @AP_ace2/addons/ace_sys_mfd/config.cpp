////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:45:52 2013 : Created on Sat Apr 06 11:45:52 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_mfd : config.bin{
class CfgPatches
{
	class ace_sys_mfd
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_vehicle","ace_c_weapon","ace_sys_missileguidance"};
		version = "1.14.0.590";
		author[] = {"jaynus"};
		class ACE_Options
		{
			group = "VEH";
			title = "MFDs";
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_mfd
	{
		clientInit = "call ('\x\ace\addons\sys_mfd\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_GetOut_EventHandlers
{
	class Air
	{
		class ace_sys_mfd
		{
			clientGetOut = "if (player == (_this select 2)) then { _this call ace_sys_mfd_fnc_onGetOut };";
		};
	};
};
class Extended_FiredBIS_EventHandlers
{
	class Air
	{
		class ace_sys_mfd
		{
			clientFiredBIS = "if (player == ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_mfd_fnc_renderDisplay };";
		};
	};
};
class Extended_Init_Eventhandlers
{
	class Air
	{
		class ace_sys_mfd
		{
			init = "if (isNil {(_this select 0) getVariable 'ACE_CURRENT_LASERTARGET_CODE'}) then {(_this select 0) setVariable ['ACE_CURRENT_LASERTARGET_CODE', 1001]}";
		};
	};
};
class CfgVehicles
{
	class Helicopter;
	class Air;
	class Plane: Air
	{
		ACE_mfdClass = "ace_sys_mfd_MFD_Dialog";
	};
	class AH64_base_EP1: Helicopter
	{
		ACE_mfdClass = "ace_sys_mfd_MFD_Dialog";
	};
	class UAV;
	class MQ9PredatorB: UAV
	{
		ACE_mfdClass = "ace_sys_mfd_MFD_Dialog";
	};
};
class RscTitles
{
	class ace_sys_mfd_MFD_Dialog
	{
		idd = 6421100;
		movingEnable = 0;
		name = "ace_sys_mfd_MFD_Dialog";
		duration = 999999;
		fadein = 0;
		onUnload = "[(_this select 0)] call ace_sys_mfd_fnc_onDialogClose;";
		onLoad = "[(_this select 0), 6421100, ""ace_sys_mfd_MFD_Dialog""] call ace_sys_mfd_fnc_onDialogOpen;";
		ACE_textRowCount = 22;
		ACE_textColumnCount = 44;
		controlsBackground[] = {"ace_sys_mfd_BackgroundImage"};
		objects[] = {};
		class ace_sys_mfd_BackgroundImage
		{
			type = 0;
			idc = 6421199;
			style = 48;
			colorBackground[] = {0,0,0,0};
			colorText[] = {1,1,1,1};
			font = "EtelkaMonospaceProBold";
			sizeEx = 0.04;
			x = "SafeZoneX";
			y = "(SafeZoneY + SafeZoneH) - (SafeZoneW * 0.35)";
			w = "(SafeZoneW * 0.35)";
			h = "(SafeZoneW * 0.35)";
			text = "\x\ace\addons\sys_mfd\data\ah64d_MFD_background_CO.paa";
		};
		class controls
		{
			class 1001
			{
				idc = 1001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1002
			{
				idc = 1002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1003
			{
				idc = 1003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1004
			{
				idc = 1004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1005
			{
				idc = 1005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1006
			{
				idc = 1006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1007
			{
				idc = 1007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1008
			{
				idc = 1008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1009
			{
				idc = 1009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1010
			{
				idc = 1010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1011
			{
				idc = 1011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1012
			{
				idc = 1012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1013
			{
				idc = 1013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1014
			{
				idc = 1014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1015
			{
				idc = 1015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1016
			{
				idc = 1016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1017
			{
				idc = 1017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1018
			{
				idc = 1018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1019
			{
				idc = 1019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1020
			{
				idc = 1020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1021
			{
				idc = 1021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1022
			{
				idc = 1022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1023
			{
				idc = 1023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1024
			{
				idc = 1024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1025
			{
				idc = 1025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1026
			{
				idc = 1026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1027
			{
				idc = 1027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1028
			{
				idc = 1028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1029
			{
				idc = 1029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1030
			{
				idc = 1030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1031
			{
				idc = 1031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1032
			{
				idc = 1032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1033
			{
				idc = 1033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1034
			{
				idc = 1034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1035
			{
				idc = 1035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1036
			{
				idc = 1036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1037
			{
				idc = 1037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1038
			{
				idc = 1038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1039
			{
				idc = 1039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1040
			{
				idc = 1040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1041
			{
				idc = 1041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1042
			{
				idc = 1042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1043
			{
				idc = 1043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 1044
			{
				idc = 1044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 0) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2001
			{
				idc = 2001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2002
			{
				idc = 2002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2003
			{
				idc = 2003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2004
			{
				idc = 2004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2005
			{
				idc = 2005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2006
			{
				idc = 2006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2007
			{
				idc = 2007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2008
			{
				idc = 2008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2009
			{
				idc = 2009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2010
			{
				idc = 2010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2011
			{
				idc = 2011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2012
			{
				idc = 2012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2013
			{
				idc = 2013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2014
			{
				idc = 2014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2015
			{
				idc = 2015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2016
			{
				idc = 2016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2017
			{
				idc = 2017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2018
			{
				idc = 2018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2019
			{
				idc = 2019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2020
			{
				idc = 2020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2021
			{
				idc = 2021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2022
			{
				idc = 2022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2023
			{
				idc = 2023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2024
			{
				idc = 2024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2025
			{
				idc = 2025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2026
			{
				idc = 2026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2027
			{
				idc = 2027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2028
			{
				idc = 2028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2029
			{
				idc = 2029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2030
			{
				idc = 2030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2031
			{
				idc = 2031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2032
			{
				idc = 2032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2033
			{
				idc = 2033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2034
			{
				idc = 2034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2035
			{
				idc = 2035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2036
			{
				idc = 2036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2037
			{
				idc = 2037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2038
			{
				idc = 2038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2039
			{
				idc = 2039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2040
			{
				idc = 2040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2041
			{
				idc = 2041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2042
			{
				idc = 2042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2043
			{
				idc = 2043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 2044
			{
				idc = 2044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 1) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3001
			{
				idc = 3001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3002
			{
				idc = 3002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3003
			{
				idc = 3003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3004
			{
				idc = 3004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3005
			{
				idc = 3005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3006
			{
				idc = 3006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3007
			{
				idc = 3007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3008
			{
				idc = 3008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3009
			{
				idc = 3009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3010
			{
				idc = 3010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3011
			{
				idc = 3011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3012
			{
				idc = 3012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3013
			{
				idc = 3013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3014
			{
				idc = 3014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3015
			{
				idc = 3015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3016
			{
				idc = 3016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3017
			{
				idc = 3017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3018
			{
				idc = 3018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3019
			{
				idc = 3019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3020
			{
				idc = 3020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3021
			{
				idc = 3021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3022
			{
				idc = 3022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3023
			{
				idc = 3023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3024
			{
				idc = 3024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3025
			{
				idc = 3025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3026
			{
				idc = 3026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3027
			{
				idc = 3027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3028
			{
				idc = 3028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3029
			{
				idc = 3029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3030
			{
				idc = 3030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3031
			{
				idc = 3031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3032
			{
				idc = 3032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3033
			{
				idc = 3033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3034
			{
				idc = 3034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3035
			{
				idc = 3035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3036
			{
				idc = 3036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3037
			{
				idc = 3037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3038
			{
				idc = 3038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3039
			{
				idc = 3039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3040
			{
				idc = 3040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3041
			{
				idc = 3041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3042
			{
				idc = 3042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3043
			{
				idc = 3043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 3044
			{
				idc = 3044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 2) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4001
			{
				idc = 4001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4002
			{
				idc = 4002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4003
			{
				idc = 4003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4004
			{
				idc = 4004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4005
			{
				idc = 4005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4006
			{
				idc = 4006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4007
			{
				idc = 4007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4008
			{
				idc = 4008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4009
			{
				idc = 4009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4010
			{
				idc = 4010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4011
			{
				idc = 4011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4012
			{
				idc = 4012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4013
			{
				idc = 4013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4014
			{
				idc = 4014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4015
			{
				idc = 4015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4016
			{
				idc = 4016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4017
			{
				idc = 4017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4018
			{
				idc = 4018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4019
			{
				idc = 4019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4020
			{
				idc = 4020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4021
			{
				idc = 4021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4022
			{
				idc = 4022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4023
			{
				idc = 4023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4024
			{
				idc = 4024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4025
			{
				idc = 4025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4026
			{
				idc = 4026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4027
			{
				idc = 4027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4028
			{
				idc = 4028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4029
			{
				idc = 4029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4030
			{
				idc = 4030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4031
			{
				idc = 4031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4032
			{
				idc = 4032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4033
			{
				idc = 4033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4034
			{
				idc = 4034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4035
			{
				idc = 4035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4036
			{
				idc = 4036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4037
			{
				idc = 4037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4038
			{
				idc = 4038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4039
			{
				idc = 4039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4040
			{
				idc = 4040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4041
			{
				idc = 4041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4042
			{
				idc = 4042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4043
			{
				idc = 4043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 4044
			{
				idc = 4044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 3) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5001
			{
				idc = 5001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5002
			{
				idc = 5002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5003
			{
				idc = 5003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5004
			{
				idc = 5004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5005
			{
				idc = 5005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5006
			{
				idc = 5006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5007
			{
				idc = 5007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5008
			{
				idc = 5008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5009
			{
				idc = 5009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5010
			{
				idc = 5010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5011
			{
				idc = 5011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5012
			{
				idc = 5012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5013
			{
				idc = 5013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5014
			{
				idc = 5014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5015
			{
				idc = 5015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5016
			{
				idc = 5016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5017
			{
				idc = 5017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5018
			{
				idc = 5018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5019
			{
				idc = 5019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5020
			{
				idc = 5020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5021
			{
				idc = 5021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5022
			{
				idc = 5022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5023
			{
				idc = 5023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5024
			{
				idc = 5024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5025
			{
				idc = 5025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5026
			{
				idc = 5026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5027
			{
				idc = 5027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5028
			{
				idc = 5028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5029
			{
				idc = 5029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5030
			{
				idc = 5030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5031
			{
				idc = 5031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5032
			{
				idc = 5032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5033
			{
				idc = 5033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5034
			{
				idc = 5034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5035
			{
				idc = 5035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5036
			{
				idc = 5036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5037
			{
				idc = 5037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5038
			{
				idc = 5038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5039
			{
				idc = 5039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5040
			{
				idc = 5040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5041
			{
				idc = 5041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5042
			{
				idc = 5042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5043
			{
				idc = 5043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 5044
			{
				idc = 5044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 4) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6001
			{
				idc = 6001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6002
			{
				idc = 6002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6003
			{
				idc = 6003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6004
			{
				idc = 6004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6005
			{
				idc = 6005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6006
			{
				idc = 6006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6007
			{
				idc = 6007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6008
			{
				idc = 6008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6009
			{
				idc = 6009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6010
			{
				idc = 6010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6011
			{
				idc = 6011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6012
			{
				idc = 6012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6013
			{
				idc = 6013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6014
			{
				idc = 6014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6015
			{
				idc = 6015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6016
			{
				idc = 6016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6017
			{
				idc = 6017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6018
			{
				idc = 6018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6019
			{
				idc = 6019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6020
			{
				idc = 6020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6021
			{
				idc = 6021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6022
			{
				idc = 6022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6023
			{
				idc = 6023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6024
			{
				idc = 6024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6025
			{
				idc = 6025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6026
			{
				idc = 6026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6027
			{
				idc = 6027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6028
			{
				idc = 6028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6029
			{
				idc = 6029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6030
			{
				idc = 6030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6031
			{
				idc = 6031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6032
			{
				idc = 6032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6033
			{
				idc = 6033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6034
			{
				idc = 6034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6035
			{
				idc = 6035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6036
			{
				idc = 6036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6037
			{
				idc = 6037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6038
			{
				idc = 6038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6039
			{
				idc = 6039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6040
			{
				idc = 6040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6041
			{
				idc = 6041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6042
			{
				idc = 6042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6043
			{
				idc = 6043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 6044
			{
				idc = 6044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 5) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7001
			{
				idc = 7001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7002
			{
				idc = 7002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7003
			{
				idc = 7003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7004
			{
				idc = 7004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7005
			{
				idc = 7005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7006
			{
				idc = 7006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7007
			{
				idc = 7007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7008
			{
				idc = 7008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7009
			{
				idc = 7009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7010
			{
				idc = 7010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7011
			{
				idc = 7011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7012
			{
				idc = 7012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7013
			{
				idc = 7013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7014
			{
				idc = 7014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7015
			{
				idc = 7015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7016
			{
				idc = 7016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7017
			{
				idc = 7017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7018
			{
				idc = 7018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7019
			{
				idc = 7019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7020
			{
				idc = 7020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7021
			{
				idc = 7021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7022
			{
				idc = 7022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7023
			{
				idc = 7023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7024
			{
				idc = 7024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7025
			{
				idc = 7025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7026
			{
				idc = 7026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7027
			{
				idc = 7027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7028
			{
				idc = 7028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7029
			{
				idc = 7029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7030
			{
				idc = 7030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7031
			{
				idc = 7031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7032
			{
				idc = 7032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7033
			{
				idc = 7033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7034
			{
				idc = 7034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7035
			{
				idc = 7035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7036
			{
				idc = 7036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7037
			{
				idc = 7037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7038
			{
				idc = 7038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7039
			{
				idc = 7039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7040
			{
				idc = 7040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7041
			{
				idc = 7041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7042
			{
				idc = 7042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7043
			{
				idc = 7043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 7044
			{
				idc = 7044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 6) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8001
			{
				idc = 8001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8002
			{
				idc = 8002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8003
			{
				idc = 8003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8004
			{
				idc = 8004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8005
			{
				idc = 8005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8006
			{
				idc = 8006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8007
			{
				idc = 8007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8008
			{
				idc = 8008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8009
			{
				idc = 8009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8010
			{
				idc = 8010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8011
			{
				idc = 8011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8012
			{
				idc = 8012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8013
			{
				idc = 8013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8014
			{
				idc = 8014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8015
			{
				idc = 8015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8016
			{
				idc = 8016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8017
			{
				idc = 8017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8018
			{
				idc = 8018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8019
			{
				idc = 8019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8020
			{
				idc = 8020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8021
			{
				idc = 8021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8022
			{
				idc = 8022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8023
			{
				idc = 8023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8024
			{
				idc = 8024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8025
			{
				idc = 8025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8026
			{
				idc = 8026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8027
			{
				idc = 8027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8028
			{
				idc = 8028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8029
			{
				idc = 8029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8030
			{
				idc = 8030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8031
			{
				idc = 8031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8032
			{
				idc = 8032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8033
			{
				idc = 8033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8034
			{
				idc = 8034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8035
			{
				idc = 8035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8036
			{
				idc = 8036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8037
			{
				idc = 8037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8038
			{
				idc = 8038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8039
			{
				idc = 8039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8040
			{
				idc = 8040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8041
			{
				idc = 8041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8042
			{
				idc = 8042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8043
			{
				idc = 8043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 8044
			{
				idc = 8044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 7) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9001
			{
				idc = 9001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9002
			{
				idc = 9002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9003
			{
				idc = 9003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9004
			{
				idc = 9004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9005
			{
				idc = 9005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9006
			{
				idc = 9006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9007
			{
				idc = 9007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9008
			{
				idc = 9008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9009
			{
				idc = 9009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9010
			{
				idc = 9010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9011
			{
				idc = 9011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9012
			{
				idc = 9012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9013
			{
				idc = 9013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9014
			{
				idc = 9014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9015
			{
				idc = 9015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9016
			{
				idc = 9016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9017
			{
				idc = 9017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9018
			{
				idc = 9018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9019
			{
				idc = 9019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9020
			{
				idc = 9020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9021
			{
				idc = 9021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9022
			{
				idc = 9022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9023
			{
				idc = 9023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9024
			{
				idc = 9024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9025
			{
				idc = 9025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9026
			{
				idc = 9026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9027
			{
				idc = 9027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9028
			{
				idc = 9028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9029
			{
				idc = 9029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9030
			{
				idc = 9030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9031
			{
				idc = 9031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9032
			{
				idc = 9032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9033
			{
				idc = 9033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9034
			{
				idc = 9034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9035
			{
				idc = 9035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9036
			{
				idc = 9036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9037
			{
				idc = 9037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9038
			{
				idc = 9038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9039
			{
				idc = 9039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9040
			{
				idc = 9040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9041
			{
				idc = 9041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9042
			{
				idc = 9042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9043
			{
				idc = 9043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 9044
			{
				idc = 9044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 8) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10001
			{
				idc = 10001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10002
			{
				idc = 10002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10003
			{
				idc = 10003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10004
			{
				idc = 10004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10005
			{
				idc = 10005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10006
			{
				idc = 10006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10007
			{
				idc = 10007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10008
			{
				idc = 10008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10009
			{
				idc = 10009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10010
			{
				idc = 10010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10011
			{
				idc = 10011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10012
			{
				idc = 10012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10013
			{
				idc = 10013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10014
			{
				idc = 10014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10015
			{
				idc = 10015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10016
			{
				idc = 10016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10017
			{
				idc = 10017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10018
			{
				idc = 10018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10019
			{
				idc = 10019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10020
			{
				idc = 10020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10021
			{
				idc = 10021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10022
			{
				idc = 10022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10023
			{
				idc = 10023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10024
			{
				idc = 10024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10025
			{
				idc = 10025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10026
			{
				idc = 10026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10027
			{
				idc = 10027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10028
			{
				idc = 10028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10029
			{
				idc = 10029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10030
			{
				idc = 10030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10031
			{
				idc = 10031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10032
			{
				idc = 10032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10033
			{
				idc = 10033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10034
			{
				idc = 10034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10035
			{
				idc = 10035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10036
			{
				idc = 10036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10037
			{
				idc = 10037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10038
			{
				idc = 10038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10039
			{
				idc = 10039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10040
			{
				idc = 10040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10041
			{
				idc = 10041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10042
			{
				idc = 10042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10043
			{
				idc = 10043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 10044
			{
				idc = 10044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 9) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11001
			{
				idc = 11001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11002
			{
				idc = 11002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11003
			{
				idc = 11003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11004
			{
				idc = 11004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11005
			{
				idc = 11005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11006
			{
				idc = 11006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11007
			{
				idc = 11007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11008
			{
				idc = 11008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11009
			{
				idc = 11009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11010
			{
				idc = 11010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11011
			{
				idc = 11011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11012
			{
				idc = 11012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11013
			{
				idc = 11013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11014
			{
				idc = 11014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11015
			{
				idc = 11015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11016
			{
				idc = 11016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11017
			{
				idc = 11017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11018
			{
				idc = 11018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11019
			{
				idc = 11019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11020
			{
				idc = 11020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11021
			{
				idc = 11021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11022
			{
				idc = 11022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11023
			{
				idc = 11023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11024
			{
				idc = 11024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11025
			{
				idc = 11025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11026
			{
				idc = 11026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11027
			{
				idc = 11027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11028
			{
				idc = 11028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11029
			{
				idc = 11029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11030
			{
				idc = 11030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11031
			{
				idc = 11031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11032
			{
				idc = 11032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11033
			{
				idc = 11033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11034
			{
				idc = 11034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11035
			{
				idc = 11035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11036
			{
				idc = 11036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11037
			{
				idc = 11037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11038
			{
				idc = 11038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11039
			{
				idc = 11039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11040
			{
				idc = 11040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11041
			{
				idc = 11041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11042
			{
				idc = 11042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11043
			{
				idc = 11043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 11044
			{
				idc = 11044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 10) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12001
			{
				idc = 12001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12002
			{
				idc = 12002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12003
			{
				idc = 12003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12004
			{
				idc = 12004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12005
			{
				idc = 12005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12006
			{
				idc = 12006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12007
			{
				idc = 12007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12008
			{
				idc = 12008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12009
			{
				idc = 12009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12010
			{
				idc = 12010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12011
			{
				idc = 12011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12012
			{
				idc = 12012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12013
			{
				idc = 12013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12014
			{
				idc = 12014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12015
			{
				idc = 12015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12016
			{
				idc = 12016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12017
			{
				idc = 12017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12018
			{
				idc = 12018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12019
			{
				idc = 12019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12020
			{
				idc = 12020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12021
			{
				idc = 12021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12022
			{
				idc = 12022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12023
			{
				idc = 12023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12024
			{
				idc = 12024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12025
			{
				idc = 12025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12026
			{
				idc = 12026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12027
			{
				idc = 12027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12028
			{
				idc = 12028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12029
			{
				idc = 12029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12030
			{
				idc = 12030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12031
			{
				idc = 12031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12032
			{
				idc = 12032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12033
			{
				idc = 12033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12034
			{
				idc = 12034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12035
			{
				idc = 12035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12036
			{
				idc = 12036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12037
			{
				idc = 12037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12038
			{
				idc = 12038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12039
			{
				idc = 12039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12040
			{
				idc = 12040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12041
			{
				idc = 12041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12042
			{
				idc = 12042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12043
			{
				idc = 12043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 12044
			{
				idc = 12044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 11) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13001
			{
				idc = 13001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13002
			{
				idc = 13002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13003
			{
				idc = 13003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13004
			{
				idc = 13004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13005
			{
				idc = 13005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13006
			{
				idc = 13006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13007
			{
				idc = 13007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13008
			{
				idc = 13008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13009
			{
				idc = 13009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13010
			{
				idc = 13010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13011
			{
				idc = 13011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13012
			{
				idc = 13012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13013
			{
				idc = 13013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13014
			{
				idc = 13014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13015
			{
				idc = 13015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13016
			{
				idc = 13016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13017
			{
				idc = 13017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13018
			{
				idc = 13018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13019
			{
				idc = 13019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13020
			{
				idc = 13020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13021
			{
				idc = 13021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13022
			{
				idc = 13022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13023
			{
				idc = 13023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13024
			{
				idc = 13024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13025
			{
				idc = 13025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13026
			{
				idc = 13026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13027
			{
				idc = 13027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13028
			{
				idc = 13028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13029
			{
				idc = 13029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13030
			{
				idc = 13030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13031
			{
				idc = 13031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13032
			{
				idc = 13032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13033
			{
				idc = 13033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13034
			{
				idc = 13034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13035
			{
				idc = 13035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13036
			{
				idc = 13036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13037
			{
				idc = 13037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13038
			{
				idc = 13038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13039
			{
				idc = 13039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13040
			{
				idc = 13040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13041
			{
				idc = 13041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13042
			{
				idc = 13042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13043
			{
				idc = 13043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 13044
			{
				idc = 13044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 12) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14001
			{
				idc = 14001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14002
			{
				idc = 14002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14003
			{
				idc = 14003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14004
			{
				idc = 14004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14005
			{
				idc = 14005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14006
			{
				idc = 14006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14007
			{
				idc = 14007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14008
			{
				idc = 14008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14009
			{
				idc = 14009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14010
			{
				idc = 14010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14011
			{
				idc = 14011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14012
			{
				idc = 14012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14013
			{
				idc = 14013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14014
			{
				idc = 14014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14015
			{
				idc = 14015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14016
			{
				idc = 14016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14017
			{
				idc = 14017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14018
			{
				idc = 14018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14019
			{
				idc = 14019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14020
			{
				idc = 14020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14021
			{
				idc = 14021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14022
			{
				idc = 14022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14023
			{
				idc = 14023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14024
			{
				idc = 14024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14025
			{
				idc = 14025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14026
			{
				idc = 14026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14027
			{
				idc = 14027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14028
			{
				idc = 14028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14029
			{
				idc = 14029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14030
			{
				idc = 14030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14031
			{
				idc = 14031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14032
			{
				idc = 14032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14033
			{
				idc = 14033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14034
			{
				idc = 14034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14035
			{
				idc = 14035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14036
			{
				idc = 14036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14037
			{
				idc = 14037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14038
			{
				idc = 14038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14039
			{
				idc = 14039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14040
			{
				idc = 14040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14041
			{
				idc = 14041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14042
			{
				idc = 14042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14043
			{
				idc = 14043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 14044
			{
				idc = 14044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 13) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15001
			{
				idc = 15001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15002
			{
				idc = 15002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15003
			{
				idc = 15003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15004
			{
				idc = 15004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15005
			{
				idc = 15005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15006
			{
				idc = 15006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15007
			{
				idc = 15007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15008
			{
				idc = 15008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15009
			{
				idc = 15009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15010
			{
				idc = 15010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15011
			{
				idc = 15011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15012
			{
				idc = 15012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15013
			{
				idc = 15013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15014
			{
				idc = 15014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15015
			{
				idc = 15015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15016
			{
				idc = 15016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15017
			{
				idc = 15017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15018
			{
				idc = 15018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15019
			{
				idc = 15019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15020
			{
				idc = 15020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15021
			{
				idc = 15021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15022
			{
				idc = 15022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15023
			{
				idc = 15023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15024
			{
				idc = 15024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15025
			{
				idc = 15025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15026
			{
				idc = 15026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15027
			{
				idc = 15027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15028
			{
				idc = 15028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15029
			{
				idc = 15029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15030
			{
				idc = 15030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15031
			{
				idc = 15031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15032
			{
				idc = 15032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15033
			{
				idc = 15033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15034
			{
				idc = 15034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15035
			{
				idc = 15035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15036
			{
				idc = 15036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15037
			{
				idc = 15037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15038
			{
				idc = 15038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15039
			{
				idc = 15039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15040
			{
				idc = 15040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15041
			{
				idc = 15041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15042
			{
				idc = 15042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15043
			{
				idc = 15043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 15044
			{
				idc = 15044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 14) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16001
			{
				idc = 16001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16002
			{
				idc = 16002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16003
			{
				idc = 16003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16004
			{
				idc = 16004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16005
			{
				idc = 16005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16006
			{
				idc = 16006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16007
			{
				idc = 16007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16008
			{
				idc = 16008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16009
			{
				idc = 16009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16010
			{
				idc = 16010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16011
			{
				idc = 16011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16012
			{
				idc = 16012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16013
			{
				idc = 16013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16014
			{
				idc = 16014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16015
			{
				idc = 16015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16016
			{
				idc = 16016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16017
			{
				idc = 16017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16018
			{
				idc = 16018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16019
			{
				idc = 16019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16020
			{
				idc = 16020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16021
			{
				idc = 16021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16022
			{
				idc = 16022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16023
			{
				idc = 16023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16024
			{
				idc = 16024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16025
			{
				idc = 16025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16026
			{
				idc = 16026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16027
			{
				idc = 16027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16028
			{
				idc = 16028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16029
			{
				idc = 16029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16030
			{
				idc = 16030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16031
			{
				idc = 16031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16032
			{
				idc = 16032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16033
			{
				idc = 16033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16034
			{
				idc = 16034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16035
			{
				idc = 16035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16036
			{
				idc = 16036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16037
			{
				idc = 16037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16038
			{
				idc = 16038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16039
			{
				idc = 16039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16040
			{
				idc = 16040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16041
			{
				idc = 16041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16042
			{
				idc = 16042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16043
			{
				idc = 16043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 16044
			{
				idc = 16044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 15) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17001
			{
				idc = 17001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17002
			{
				idc = 17002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17003
			{
				idc = 17003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17004
			{
				idc = 17004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17005
			{
				idc = 17005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17006
			{
				idc = 17006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17007
			{
				idc = 17007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17008
			{
				idc = 17008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17009
			{
				idc = 17009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17010
			{
				idc = 17010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17011
			{
				idc = 17011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17012
			{
				idc = 17012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17013
			{
				idc = 17013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17014
			{
				idc = 17014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17015
			{
				idc = 17015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17016
			{
				idc = 17016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17017
			{
				idc = 17017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17018
			{
				idc = 17018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17019
			{
				idc = 17019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17020
			{
				idc = 17020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17021
			{
				idc = 17021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17022
			{
				idc = 17022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17023
			{
				idc = 17023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17024
			{
				idc = 17024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17025
			{
				idc = 17025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17026
			{
				idc = 17026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17027
			{
				idc = 17027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17028
			{
				idc = 17028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17029
			{
				idc = 17029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17030
			{
				idc = 17030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17031
			{
				idc = 17031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17032
			{
				idc = 17032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17033
			{
				idc = 17033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17034
			{
				idc = 17034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17035
			{
				idc = 17035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17036
			{
				idc = 17036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17037
			{
				idc = 17037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17038
			{
				idc = 17038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17039
			{
				idc = 17039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17040
			{
				idc = 17040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17041
			{
				idc = 17041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17042
			{
				idc = 17042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17043
			{
				idc = 17043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 17044
			{
				idc = 17044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 16) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18001
			{
				idc = 18001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18002
			{
				idc = 18002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18003
			{
				idc = 18003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18004
			{
				idc = 18004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18005
			{
				idc = 18005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18006
			{
				idc = 18006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18007
			{
				idc = 18007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18008
			{
				idc = 18008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18009
			{
				idc = 18009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18010
			{
				idc = 18010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18011
			{
				idc = 18011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18012
			{
				idc = 18012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18013
			{
				idc = 18013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18014
			{
				idc = 18014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18015
			{
				idc = 18015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18016
			{
				idc = 18016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18017
			{
				idc = 18017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18018
			{
				idc = 18018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18019
			{
				idc = 18019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18020
			{
				idc = 18020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18021
			{
				idc = 18021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18022
			{
				idc = 18022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18023
			{
				idc = 18023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18024
			{
				idc = 18024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18025
			{
				idc = 18025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18026
			{
				idc = 18026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18027
			{
				idc = 18027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18028
			{
				idc = 18028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18029
			{
				idc = 18029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18030
			{
				idc = 18030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18031
			{
				idc = 18031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18032
			{
				idc = 18032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18033
			{
				idc = 18033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18034
			{
				idc = 18034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18035
			{
				idc = 18035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18036
			{
				idc = 18036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18037
			{
				idc = 18037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18038
			{
				idc = 18038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18039
			{
				idc = 18039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18040
			{
				idc = 18040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18041
			{
				idc = 18041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18042
			{
				idc = 18042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18043
			{
				idc = 18043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 18044
			{
				idc = 18044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 17) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19001
			{
				idc = 19001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19002
			{
				idc = 19002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19003
			{
				idc = 19003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19004
			{
				idc = 19004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19005
			{
				idc = 19005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19006
			{
				idc = 19006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19007
			{
				idc = 19007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19008
			{
				idc = 19008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19009
			{
				idc = 19009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19010
			{
				idc = 19010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19011
			{
				idc = 19011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19012
			{
				idc = 19012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19013
			{
				idc = 19013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19014
			{
				idc = 19014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19015
			{
				idc = 19015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19016
			{
				idc = 19016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19017
			{
				idc = 19017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19018
			{
				idc = 19018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19019
			{
				idc = 19019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19020
			{
				idc = 19020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19021
			{
				idc = 19021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19022
			{
				idc = 19022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19023
			{
				idc = 19023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19024
			{
				idc = 19024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19025
			{
				idc = 19025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19026
			{
				idc = 19026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19027
			{
				idc = 19027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19028
			{
				idc = 19028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19029
			{
				idc = 19029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19030
			{
				idc = 19030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19031
			{
				idc = 19031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19032
			{
				idc = 19032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19033
			{
				idc = 19033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19034
			{
				idc = 19034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19035
			{
				idc = 19035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19036
			{
				idc = 19036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19037
			{
				idc = 19037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19038
			{
				idc = 19038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19039
			{
				idc = 19039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19040
			{
				idc = 19040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19041
			{
				idc = 19041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19042
			{
				idc = 19042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19043
			{
				idc = 19043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 19044
			{
				idc = 19044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 18) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20001
			{
				idc = 20001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20002
			{
				idc = 20002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20003
			{
				idc = 20003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20004
			{
				idc = 20004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20005
			{
				idc = 20005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20006
			{
				idc = 20006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20007
			{
				idc = 20007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20008
			{
				idc = 20008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20009
			{
				idc = 20009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20010
			{
				idc = 20010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20011
			{
				idc = 20011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20012
			{
				idc = 20012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20013
			{
				idc = 20013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20014
			{
				idc = 20014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20015
			{
				idc = 20015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20016
			{
				idc = 20016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20017
			{
				idc = 20017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20018
			{
				idc = 20018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20019
			{
				idc = 20019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20020
			{
				idc = 20020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20021
			{
				idc = 20021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20022
			{
				idc = 20022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20023
			{
				idc = 20023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20024
			{
				idc = 20024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20025
			{
				idc = 20025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20026
			{
				idc = 20026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20027
			{
				idc = 20027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20028
			{
				idc = 20028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20029
			{
				idc = 20029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20030
			{
				idc = 20030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20031
			{
				idc = 20031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20032
			{
				idc = 20032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20033
			{
				idc = 20033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20034
			{
				idc = 20034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20035
			{
				idc = 20035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20036
			{
				idc = 20036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20037
			{
				idc = 20037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20038
			{
				idc = 20038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20039
			{
				idc = 20039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20040
			{
				idc = 20040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20041
			{
				idc = 20041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20042
			{
				idc = 20042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20043
			{
				idc = 20043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 20044
			{
				idc = 20044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 19) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21001
			{
				idc = 21001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21002
			{
				idc = 21002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21003
			{
				idc = 21003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21004
			{
				idc = 21004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21005
			{
				idc = 21005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21006
			{
				idc = 21006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21007
			{
				idc = 21007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21008
			{
				idc = 21008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21009
			{
				idc = 21009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21010
			{
				idc = 21010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21011
			{
				idc = 21011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21012
			{
				idc = 21012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21013
			{
				idc = 21013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21014
			{
				idc = 21014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21015
			{
				idc = 21015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21016
			{
				idc = 21016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21017
			{
				idc = 21017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21018
			{
				idc = 21018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21019
			{
				idc = 21019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21020
			{
				idc = 21020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21021
			{
				idc = 21021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21022
			{
				idc = 21022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21023
			{
				idc = 21023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21024
			{
				idc = 21024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21025
			{
				idc = 21025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21026
			{
				idc = 21026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21027
			{
				idc = 21027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21028
			{
				idc = 21028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21029
			{
				idc = 21029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21030
			{
				idc = 21030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21031
			{
				idc = 21031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21032
			{
				idc = 21032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21033
			{
				idc = 21033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21034
			{
				idc = 21034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21035
			{
				idc = 21035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21036
			{
				idc = 21036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21037
			{
				idc = 21037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21038
			{
				idc = 21038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21039
			{
				idc = 21039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21040
			{
				idc = 21040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21041
			{
				idc = 21041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21042
			{
				idc = 21042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21043
			{
				idc = 21043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 21044
			{
				idc = 21044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 20) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22001
			{
				idc = 22001;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 0) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22002
			{
				idc = 22002;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 1) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22003
			{
				idc = 22003;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 2) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22004
			{
				idc = 22004;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 3) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22005
			{
				idc = 22005;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 4) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22006
			{
				idc = 22006;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 5) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22007
			{
				idc = 22007;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 6) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22008
			{
				idc = 22008;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 7) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22009
			{
				idc = 22009;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 8) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22010
			{
				idc = 22010;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 9) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22011
			{
				idc = 22011;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 10) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22012
			{
				idc = 22012;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 11) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22013
			{
				idc = 22013;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 12) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22014
			{
				idc = 22014;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 13) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22015
			{
				idc = 22015;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 14) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22016
			{
				idc = 22016;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 15) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22017
			{
				idc = 22017;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 16) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22018
			{
				idc = 22018;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 17) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22019
			{
				idc = 22019;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 18) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22020
			{
				idc = 22020;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 19) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22021
			{
				idc = 22021;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 20) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22022
			{
				idc = 22022;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 21) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22023
			{
				idc = 22023;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 22) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22024
			{
				idc = 22024;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 23) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22025
			{
				idc = 22025;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 24) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22026
			{
				idc = 22026;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 25) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22027
			{
				idc = 22027;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 26) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22028
			{
				idc = 22028;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 27) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22029
			{
				idc = 22029;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 28) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22030
			{
				idc = 22030;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 29) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22031
			{
				idc = 22031;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 30) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22032
			{
				idc = 22032;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 31) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22033
			{
				idc = 22033;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 32) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22034
			{
				idc = 22034;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 33) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22035
			{
				idc = 22035;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 34) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22036
			{
				idc = 22036;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 35) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22037
			{
				idc = 22037;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 36) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22038
			{
				idc = 22038;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 37) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22039
			{
				idc = 22039;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 38) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22040
			{
				idc = 22040;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 39) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22041
			{
				idc = 22041;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 40) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22042
			{
				idc = 22042;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 41) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22043
			{
				idc = 22043;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 42) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
			class 22044
			{
				idc = 22044;
				x = "(((0.06) * safeZoneW) + ((0.005*safeZoneW) * 43) + safeZoneX)";
				y = "(((0.63) * safeZoneW) + ((0.0104*safeZoneW) * 21) + safeZoneX)";
				w = "0.0118854*SafeZoneW";
				h = "0.0118854*SafeZoneW";
				colorText[] = {0,1,0,1};
				sizeEx = "0.015*SafeZoneW";
				type = 0;
				style = "0x00";
				font = "EtelkaMonospaceProBold";
				colorBackground[] = {0,0,0,0};
				text = "";
			};
		};
	};
};
//};
