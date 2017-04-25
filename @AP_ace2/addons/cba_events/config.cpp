////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:52 2013 : Created on Thu Jan 03 12:00:52 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_events : config.bin{
class CfgPatches
{
	class cba_events
	{
		units[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"CBA_XEH","CBA_common"};
		version = "1.0.1.196";
		author[] = {"Spooner","Sickboy","Xeno"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_events
	{
		init = "call ('\x\cba\addons\events\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\cba\addons\events\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgFunctions
{
	class CBA
	{
		class Events
		{
			class addDisplayHandler
			{
				description = "Adds an action to a displayHandler";
				file = "\x\cba\addons\events\fnc_addDisplayHandler.sqf";
			};
			class addEventHandler
			{
				description = "Registers an event handler for a specific CBA event.";
				file = "\x\cba\addons\events\fnc_addEventHandler.sqf";
			};
			class addKeyHandler
			{
				description = "Adds an action to a keyhandler";
				file = "\x\cba\addons\events\fnc_addKeyHandler.sqf";
			};
			class addKeyHandlerFromConfig
			{
				description = "Adds an action to a keyhandler, read from config";
				file = "\x\cba\addons\events\fnc_addKeyHandlerFromConfig.sqf";
			};
			class addLocalEventHandler
			{
				description = "Registers an event handler for a specific CBA event which only runs where the first parameter (object) is local.";
				file = "\x\cba\addons\events\fnc_addLocalEventHandler.sqf";
			};
			class changeKeyHandler
			{
				description = "Changes an action to a keyhandler";
				file = "\x\cba\addons\events\fnc_changeKeyHandler.sqf";
			};
			class globalEvent
			{
				description = "Raises a CBA event on all machines, including the local one.";
				file = "\x\cba\addons\events\fnc_globalEvent.sqf";
			};
			class localEvent
			{
				description = "Raises a CBA event only on the local machine.";
				file = "\x\cba\addons\events\fnc_localEvent.sqf";
			};
			class readKeyFromConfig
			{
				description = "Reads key setting from config";
				file = "\x\cba\addons\events\fnc_readKeyFromConfig.sqf";
			};
			class remoteEvent
			{
				description = "Raises a CBA event on all machines EXCEPT the local one.";
				file = "\x\cba\addons\events\fnc_remoteEvent.sqf";
			};
			class removeDisplayHandler
			{
				description = "Removes an action to a displayHandler";
				file = "\x\cba\addons\events\fnc_removeDisplayHandler.sqf";
			};
			class removeEventHandler
			{
				description = "Removes an event handler previously registered with CBA_fnc_addEventHandler.";
				file = "\x\cba\addons\events\fnc_removeEventHandler.sqf";
			};
			class removeKeyHandler
			{
				description = "Removes an action to a keyhandler";
				file = "\x\cba\addons\events\fnc_removeKeyHandler.sqf";
			};
			class removeLocalEventHandler
			{
				description = "Removes an event handler previously registered with CBA_fnc_addLocalEventHandler.";
				file = "\x\cba\addons\events\fnc_removeLocalEventHandler.sqf";
			};
			class whereLocalEvent
			{
				description = "Raises a CBA event only on the machine where parameter one is local.";
				file = "\x\cba\addons\events\fnc_whereLocalEvent.sqf";
			};
			class addClientToServerEventhandler
			{
				description = "Registers an event handler for a client to server event which only runs on the server (thus is only needed on the server)";
				file = "\x\cba\addons\events\fnc_addClientToServerEventhandler.sqf";
			};
			class clientToServerEvent
			{
				description = "Raises an CBA event only on the server (only broadcasted to server and not to other clients)";
				file = "\x\cba\addons\events\fnc_clientToServerEvent.sqf";
			};
			class removeClientToServerEvent
			{
				description = "Removes client to server event";
				file = "\x\cba\addons\events\fnc_removeClientToServerEvent.sqf";
			};
			class addReceiverOnlyEventhandler
			{
				description = "Registers an event handler for an CBA event which is only broadcasted to the receiver (and no other clients)";
				file = "\x\cba\addons\events\fnc_addReceiverOnlyEventhandler.sqf";
			};
			class receiverOnlyEvent
			{
				description = "Raises an CBA event only on the receiver and is only broadcasted there";
				file = "\x\cba\addons\events\fnc_receiverOnlyEvent.sqf";
			};
			class removeReceiverOnlyEvent
			{
				description = "Removes receiver only event";
				file = "\x\cba\addons\events\fnc_removeReceiverOnlyEvent.sqf";
			};
		};
	};
};
//};
