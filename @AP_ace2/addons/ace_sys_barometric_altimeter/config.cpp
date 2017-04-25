////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Apr 16 10:36:32 2012 : Created on Mon Apr 16 10:36:32 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_barometric_altimeter : config.bin{
class CfgPatches
{
	class ace_sys_barometric_altimeter
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.6;
		requiredAddons[] = {"Extended_EventHandlers","ace_main"};
		version = "1.13.0.542";
		author[] = {"zGuba"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_barometric_altimeter
		{
			list[] = {"ace_sys_barometric_altimeter"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_barometric_altimeter
	{
		clientInit = "call ('\x\ace\addons\sys_barometric_altimeter\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
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
class RscInGameUI
{
	class RscUnitInfo;
	class RscUnitInfoAir: RscUnitInfo
	{
		onLoad = "uiNameSpace setVariable ['ACE_RscUnitInfoAir',_this select 0]; [] spawn ace_sys_barometric_altimeter_fnc_altimeter";
		onUnload = "uiNameSpace setVariable ['ACE_RscUnitInfoAir',displayNull];";
		controls[] = {"CA_Weapon","CA_Mode","CA_Ammo","CA_ValueFuelBackground","CA_ValueFuel","CA_GunnerWeapon","CA_SpeedBackground","CA_TextSpeed","CA_Speed","CA_AltBackground","CA_TextAlt","CA_Alt","CA_HeadingBackground","CA_Heading","CA_ValueArmor","CA_TextFlares","CA_TextFlaresMode","ACE_ControlsGroup"};
		class ACE_ControlsGroup: RscControlsGroup
		{
			x = "SafezoneX";
			y = "SafezoneY";
			w = "SafezoneW-SafezoneX";
			h = "SafezoneH-SafezoneY";
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
			class Controls
			{
				class ACE_RscBarometricAltimeter_Text: RscIGUIText
				{
					idc = 1591613;
					type = 0;
					style = 1;
					text = "ASL";
					x = "0.76 - SafezoneX";
					y = 0.015;
					w = 0.12;
				};
				class ACE_RscBarometricAltimeter_Value: ACE_RscBarometricAltimeter_Text
				{
					idc = 1591614;
					style = 0;
					x = "0.76 - SafezoneX";
					y = 0.015;
					w = 0.12;
					text = "0";
				};
				class ACE_RscBarometricAltimeter_Background: RscEdit
				{
					idc = 1591615;
					sizeEx = 0.034;
					colorBackground[] = {0,0,0,0};
					colorText[] = {0.4,0.6745,0.2784,1};
					colorSelection[] = {0,0,0,0};
					style = "0x02 + 0x40";
					type = 0;
					x = "0.76 - SafezoneX";
					y = 0.017;
					w = 0.06;
					h = 0.033;
				};
				class ACE_RscVariometer_Text: RscIGUIText
				{
					idc = 1591623;
					type = 0;
					style = 0;
					text = "VAR";
					x = "0.122 - SafezoneX";
					y = 0.015;
					w = 0.12;
				};
				class ACE_RscVariometer_Value: ACE_RscBarometricAltimeter_Text
				{
					idc = 1591624;
					style = 1;
					x = "0.122 - SafezoneX";
					y = 0.015;
					w = 0.12;
					text = "0";
				};
				class ACE_RscVariometer_Background: RscEdit
				{
					idc = 1591625;
					sizeEx = 0.034;
					colorBackground[] = {0,0,0,0};
					colorText[] = {0.4,0.6745,0.2784,1};
					colorSelection[] = {0,0,0,0};
					style = "0x02 + 0x40";
					shadow = 2;
					type = 0;
					x = "0.179 - SafezoneX";
					y = 0.017;
					w = 0.06;
					h = 0.033;
				};
			};
		};
	};
};
//};
