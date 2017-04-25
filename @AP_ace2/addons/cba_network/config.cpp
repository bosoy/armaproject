////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:54 2013 : Created on Thu Jan 03 12:00:54 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_network : config.bin{
class CfgPatches
{
	class cba_network
	{
		units[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"CBA_XEH","CBA_common","CBA_events"};
		version = "1.0.1.196";
		author[] = {"Sickboy"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_network
	{
		init = "call ('\x\cba\addons\network\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class cba_network
	{
		serverInit = "call ('\x\cba\addons\network\XEH_postServerInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgFunctions
{
	class CBA
	{
		class Network
		{
			class getMarkerPersistent
			{
				description = "Checks if a global marker is persistent for JIP players.";
				file = "\x\cba\addons\network\fnc_getMarkerPersistent.sqf";
			};
			class globalExecute
			{
				description = "Executes code on given destinations";
				file = "\x\cba\addons\network\fnc_globalExecute.sqf";
			};
			class globalSay
			{
				description = "Says sound on all client computer";
				file = "\x\cba\addons\network\fnc_globalSay.sqf";
			};
			class globalSay3d
			{
				description = "Says sound on all client computer in 3d";
				file = "\x\cba\addons\network\fnc_globalSay3d.sqf";
			};
			class publicVariable
			{
				description = "CBA_fnc_publicVariable does only broadcast the new value if it doesn't exist in missionNamespace or the new value is different to the one in missionNamespace. Checks also for different types. Nil as value gets always broadcasted.";
				file = "\x\cba\addons\network\fnc_publicVariable.sqf";
			};
			class setMarkerPersistent
			{
				description = "Sets or unsets JIP persistency on a global marker.";
				file = "\x\cba\addons\network\fnc_setMarkerPersistent.sqf";
			};
			class setVarNet
			{
				description = "Same as setVariable [""name"",var, true] but only broadcasts when the value of var is different to the one which is already saved in the variable space. Checks also for different types. Nil as value gets always broadcasted.";
				file = "\x\cba\addons\network\fnc_setVarNet.sqf";
			};
		};
	};
};
//};
