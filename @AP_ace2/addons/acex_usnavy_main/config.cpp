////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:55:18 2013 : Created on Sat Apr 06 11:55:18 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_main : config.bin{
class CfgPatches
{
	class acex_usnavy_main
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CBA_A2_Main","CBA_A2_XEH","ace_main","acex_main"};
		version = "1.14.0.78";
		versionStr = "1.14.0.78";
		versionAr[] = {1,14,0,78};
		author[] = {"ACE Team"};
		authorUrl = "http://ace.dev-heaven.net";
	};
};
class CfgMods
{
	class acex_usnavy
	{
		dir = "@ACEX_USNAVY";
		name = "USNavy Faction - Advanced Combat Environment";
		picture = "ca\ui\data\logo_arma2ep1_ca.paa";
		hidePicture = "true";
		hideName = "true";
		actionName = "Website";
		action = "http://ace.dev-heaven.net";
	};
};
class CfgSettings
{
	class CBA
	{
		class Versioning
		{
			class acex_usnavy
			{
				level = 2;
				handler = "ace_main_fnc_mismatch";
				class Dependencies
				{
					ACE[] = {"ace_main",{1,5,1},"true"};
					ACEX[] = {"acex_main",{1,5,1},"true"};
				};
			};
		};
	};
};
//};
