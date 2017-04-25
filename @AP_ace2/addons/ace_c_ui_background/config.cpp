////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 26 17:33:20 2012 : Created on Fri Oct 26 17:33:20 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_ui_background : config.bin{
class CfgPatches
{
	class ace_c_ui_background
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAUI","CAFonts","ace_c_ui"};
	};
};
class RscPicture;
class RscPictureKeepAspect;
class RscStandardDisplay;
class RscDisplayStart: RscStandardDisplay
{
	class controls
	{
		class LoadingPic: RscPictureKeepAspect
		{
			idc = 501;
			w = 0;
			h = 0;
			text = "";
			colortext[] = {1,1,1,0};
		};
		class ACE_LoadingPic: RscPictureKeepAspect
		{
			idc = 105;
			x = "SafezoneX";
			y = "SafezoneY+SafezoneH*0.075";
			w = "SafezoneW";
			h = "SafezoneH*0.85";
			text = "\x\ace\addons\c_ui_background\data\ls_ACE2_A1_ca.paa";
			colortext[] = {1,1,1,1};
		};
	};
};
class RscDisplayMain: RscStandardDisplay
{
	class controlsBackground
	{
		delete CA_ARMA2;
		class ACE_CA_ARMA2: RscPicture
		{
			idc = 1106;
			colorText[] = {1,1,1,"0.6+0.4"};
			x = "(SafeZoneW + SafeZoneX) - (0.1568627*1.5 + 0.04)";
			y = "SafeZoneY + 0.00";
			w = "0.1568627*1.5";
			h = "0.2091503*1.5";
			text = "\x\ace\addons\c_ui_background\data\logo_ACEOA_ca.paa";
		};
	};
};
//};
