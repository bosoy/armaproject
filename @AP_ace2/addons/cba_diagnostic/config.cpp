////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:51 2013 : Created on Thu Jan 03 12:00:51 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_diagnostic : config.bin{
class CfgPatches
{
	class cba_diagnostic
	{
		units[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"CBA_XEH","CBA_common","CBA_events"};
		version = "1.0.1.196";
		author[] = {"Spooner","Sickboy"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
};
class CfgFunctions
{
	class CBA
	{
		class Diagnostic
		{
			class benchmarkFunction
			{
				description = "Benchmarks a function to see how long it will take to execute.";
				file = "\x\cba\addons\diagnostic\fnc_benchmarkFunction.sqf";
			};
			class debug
			{
				description = "General Purpose Debug Message Writer";
				file = "\x\cba\addons\diagnostic\fnc_debug.sqf";
			};
			class error
			{
				description = "Logs an error message to the RPT log.";
				file = "\x\cba\addons\diagnostic\fnc_error.sqf";
			};
			class log
			{
				description = "Logs a message to the RPT log.";
				file = "\x\cba\addons\diagnostic\fnc_log.sqf";
			};
			class peek
			{
				description = "Peek at variable on the server To receive the variable content back, you will have to [""cba_diagnostics_receive_peak"", {_this call myFunction}] call CBA_fnc_addEventHandler;";
				file = "\x\cba\addons\diagnostic\fnc_peek.sqf";
			};
			class test
			{
				description = "Runs unit tests for an addon or component.";
				file = "\x\cba\addons\diagnostic\fnc_test.sqf";
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_diagnostic
	{
		init = "call ('\x\cba\addons\diagnostic\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
//};
