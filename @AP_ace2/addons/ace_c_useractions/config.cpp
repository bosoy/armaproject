////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:23:18 2011 : Created on Fri Oct 21 13:23:18 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_useractions : config.bin{
class CfgPatches
{
	class ace_c_useractions
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.59;
		requiredAddons[] = {"ace_main","ace_sys_interaction"};
		version = "1.12.1.510";
	};
};
class CfgActions
{
	class None;
	class LoadMagazine: None
	{
		textDefault = "";
	};
	class LoadOtherMagazine: LoadMagazine
	{
		text = "$STR_ACE_DN_ACTION_LOADMAGAZINE";
		textDefault = "";
	};
	class LoadEmptyMagazine: LoadMagazine
	{
		text = "$STR_ACE_DN_ACTION_LOADMAGAZINE";
		textDefault = "";
	};
	class ManualFire: None
	{
		text = "$STR_ACE_DN_ACTION_FIRECONTROL";
		textDefault = "";
	};
	class ManualFireCancel: ManualFire
	{
		text = "$STR_ACE_DN_ACTION_DISABLEFIRECONTROL";
		textDefault = "";
	};
};
//};
