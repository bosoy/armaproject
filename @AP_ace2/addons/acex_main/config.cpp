////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:51:45 2013 : Created on Sat Apr 06 11:51:45 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_main : config.bin{
class CfgPatches
{
	class acex_main
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"ace_main"};
		version = "1.14.0.371";
		versionStr = "1.14.0.371";
		versionAr[] = {1,14,0,371};
		author[] = {"ACE Team"};
		authorUrl = "http://ace.dev-heaven.net";
	};
};
class CfgMods
{
	class acex
	{
		dir = "@ACEX";
		name = "eXtras - Advanced Combat Environment";
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
			class acex
			{
				level = 2;
				handler = "ace_main_fnc_mismatch";
				class Dependencies
				{
					ACE[] = {"ace_main",{1,5,1},"true"};
				};
			};
		};
	};
};
//};
