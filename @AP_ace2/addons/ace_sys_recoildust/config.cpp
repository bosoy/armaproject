////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 26 17:35:42 2012 : Created on Fri Oct 26 17:35:42 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_recoildust : config.bin{
class CfgPatches
{
	class ace_sys_recoildust
	{
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","CAWeapons","CAWeapons2"};
		version = "1.14.0.576";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_recoildust
	{
		clientInit = "call ('\x\ace\addons\sys_recoildust\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class CAManBase
	{
		class ace_sys_recoildust
		{
			clientFiredBis = "_this call ace_sys_recoildust_fnc_fired";
		};
	};
};
//};
