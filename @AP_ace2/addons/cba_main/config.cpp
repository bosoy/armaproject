////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:54 2013 : Created on Thu Jan 03 12:00:54 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_main : config.bin{
class CfgPatches
{
	class cba_main
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"cba_common","cba_arrays","cba_hashes","cba_strings","cba_events","cba_diagnostic","cba_network","cba_ai","cba_vectors","cba_versioning","cba_ui","cba_ui_helper","cba_help"};
		versionDesc = "C.B.A.";
		version = "1.0.1.196";
		versionStr = "1.0.1.196";
		versionAr[] = {1,0,1,196};
		author[] = {"CBA Team"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
	class CBA_A2_main
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {};
	};
	class CBA_OA_main
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {};
	};
};
class CfgSettings
{
	class CBA
	{
		class Caching
		{
			functions = 1;
		};
		class Versioning
		{
			class cba
			{
				class dependencies
				{
					CBA_TOH[] = {"cba_toh_main",{1,0,0},"isClass(configFile >> 'CfgPatches' >> 'United_States_H')"};
					XEH[] = {"cba_xeh",{1,0,0},"true"};
				};
			};
		};
		class Registry
		{
			class cba
			{
				removed[] = {};
			};
		};
	};
};
class CfgVehicles
{
	class Logic;
	class CBA_main_require: Logic
	{
		displayName = "Require CBA";
		vehicleClass = "Modules";
	};
};
//};
