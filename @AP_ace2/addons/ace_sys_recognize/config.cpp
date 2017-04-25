////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:07:40 2013 : Created on Mon Oct 14 23:07:40 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_recognize : config.bin{
class CfgPatches
{
	class ace_sys_recognize
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_settings","CACharacters_E"};
		version = "1.14.0.597";
		author[] = {"Rocko"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_recognize
	{
		clientInit = "call ('\x\ace\addons\sys_recognize\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_recognize
	{
		clientInit = "call ('\x\ace\addons\sys_recognize\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class RscStructuredText;
class RscTitles
{
	class ACE_Recog_Overlay
	{
		idd = 135999;
		movingEnable = 1;
		duration = 9999;
		fadein = "false";
		fadeout = "true";
		name = "ACE_Recog_Overlay";
		onLoad = "with uiNameSpace do { ACE_Recog_Overlay = _this select 0 };ace_sys_recognize_shown = true;";
		onUnload = "ace_sys_recognize_shown = false;";
		class controls
		{
			class ACE_RSC_RECOGNIZE_TEXT: RscStructuredText
			{
				idc = -1;
				colorBackground[] = {0,0,0,0.0};
				colorText[] = {0,0,0,0};
				text = "";
				style = "0x00";
				font = "Zeppelin32";
				size = 0.03;
				sizeEx = 0.01;
				x = "SafeZoneX+ (SafeZoneW/2) - 0.15";
				y = "SafeZoneY+ (SafeZoneH/2) + 0.15";
				w = 0.4;
				h = "0.15*2";
				class Attributes
				{
					font = "Zeppelin32";
					color = "#e0d8a6";
					align = "center";
					shadow = 0;
				};
				shadow = 0;
			};
		};
	};
	class ACE_Recog_Vehicle_Overlay: ACE_Recog_Overlay
	{
		idd = 135696;
		name = "ACE_Recog_Vehicle_Overlay";
		onLoad = "uiNameSpace setVariable ['ACE_Recog_Vehicle_Overlay', _this select 0];ace_sys_recognize_shown = true;";
		onUnload = "ace_sys_recognize_shown = false;";
		class controls: controls
		{
			class ACE_RSC_RECOGNIZE_VEHICLE_TEXT: RscStructuredText
			{
				colorBackground[] = {0.2,0.15,0.1,0.5};
				colorText[] = {0,0,0,0};
				sizeEx = 0.03;
				x = "(0.5 - (0.2 / 2)) + 0.2";
				y = "(SafeZoneY+ SafeZoneH- 0.2)";
				w = 0.2;
				h = "0.35*3";
				shadow = 0;
			};
		};
	};
};
class CfgVehicles
{
	class SoldierWB;
	class US_Soldier_Base_EP1: SoldierWB{};
	class Drake: US_Soldier_Base_EP1
	{
		accuracy = 1000;
		ace_sys_recognize_accuracyOnly = 1;
	};
	class US_Soldier_Pilot_EP1: US_Soldier_Base_EP1{};
	class Pierce: US_Soldier_Pilot_EP1
	{
		accuracy = 1000;
		ace_sys_recognize_accuracyOnly = 1;
	};
	class US_Soldier_Crew_EP1: US_Soldier_Base_EP1{};
	class Herrera: US_Soldier_Crew_EP1
	{
		accuracy = 1000;
		ace_sys_recognize_accuracyOnly = 1;
	};
	class US_Delta_Force_EP1: US_Soldier_Base_EP1{};
	class Graves: US_Delta_Force_EP1
	{
		accuracy = 1000;
		ace_sys_recognize_accuracyOnly = 1;
	};
	class SoldierGB;
	class Soldier_Base_PMC: SoldierGB{};
	class Special_Character_Base_PMC: Soldier_Base_PMC
	{
		accuracy = 1000;
		ace_sys_recognize_accuracyOnly = 1;
	};
};
//};
