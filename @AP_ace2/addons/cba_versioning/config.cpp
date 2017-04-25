////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:56 2013 : Created on Thu Jan 03 12:00:56 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_versioning : config.bin{
class CfgPatches
{
	class cba_versioning
	{
		units[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"CBA_common","CBA_strings","CBA_hashes","CBA_diagnostic","CBA_events","CBA_network","CBA_XEH"};
		version = "1.0.1.196";
		author[] = {"Sickboy"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_versioning
	{
		init = "call ('\x\cba\addons\versioning\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class cba_versioning
	{
		init = "call ('\x\cba\addons\versioning\XEH_postInit.sqf' call SLX_XEH_COMPILE)";
		serverInit = "call ('\x\cba\addons\versioning\XEH_postInitServer.sqf' call SLX_XEH_COMPILE)";
		clientInit = "if !(isServer) then { call ('\x\cba\addons\versioning\XEH_postInitClient.sqf' call SLX_XEH_COMPILE)}";
	};
};
//};
