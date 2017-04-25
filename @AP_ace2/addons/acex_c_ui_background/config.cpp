////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:35:17 2011 : Created on Fri Oct 21 13:35:17 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_ui_background : config.bin{
class CfgPatches
{
	class acex_c_ui_background
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAUI","CAFonts","ace_c_ui","ace_c_ui_background"};
	};
};
class RscPictureKeepAspect;
class RscStandardDisplay;
class RscDisplayLoadMission: RscStandardDisplay
{
	class controlsBackground
	{
		class LoadingPic: RscPictureKeepAspect
		{
			text = "\x\acex\addons\c_ui_background\data\ls_ACEXOA_ca.paa";
		};
	};
};
//};
