////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:55 2013 : Created on Thu Jan 03 12:00:55 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_ui_helper : config.bin{
class CfgPatches
{
	class cba_ui_helper
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"CAUI"};
	};
};
class RscStandardDisplay;
class RscDisplayMultiplayerSetup: RscStandardDisplay
{
	onLoad = "call compile preprocessFileLineNumbers 'x\cba\addons\ui_helper\onLoad.sqf';";
};
//};
