////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:39:53 2012 : Created on Fri Nov 09 22:39:53 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_main : config.bin{
class CfgPatches
{
	class acex_ru_main
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CBA_A2_Main","CBA_A2_XEH","ace_main","acex_main"};
		version = "1.14.0.76";
		versionStr = "1.14.0.76";
		versionAr[] = {1,14,0,76};
		author[] = {"ACE Team"};
		authorUrl = "http://ace.dev-heaven.net";
	};
};
class CfgMods
{
	class acex_ru
	{
		dir = "@ACEX_RU";
		name = "RU Faction - Advanced Combat Environment";
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
			class acex_ru
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
