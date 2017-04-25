////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:53 2013 : Created on Thu Jan 03 12:00:53 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_hashes : config.bin{
class CfgPatches
{
	class cba_hashes
	{
		units[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"CBA_common"};
		version = "1.0.1.196";
		author[] = {"Spooner"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
};
class CfgFunctions
{
	class CBA
	{
		class Hashes
		{
			class hashCreate
			{
				description = "Check if a Hash has a value defined for a key.";
				file = "\x\cba\addons\hashes\fnc_hashCreate.sqf";
			};
			class hashEachPair
			{
				description = "Iterate through all keys and values in a Hash.";
				file = "\x\cba\addons\hashes\fnc_hashEachPair.sqf";
			};
			class hashGet
			{
				description = "Gets a value for a given key from a Hash.";
				file = "\x\cba\addons\hashes\fnc_hashGet.sqf";
			};
			class hashHasKey
			{
				description = "Check if a Hash has a value defined for a key.";
				file = "\x\cba\addons\hashes\fnc_hashHasKey.sqf";
			};
			class hashRem
			{
				description = "Removes given key from given Hash.";
				file = "\x\cba\addons\hashes\fnc_hashRem.sqf";
			};
			class hashSet
			{
				description = "Sets a value for a given key in a Hash.";
				file = "\x\cba\addons\hashes\fnc_hashSet.sqf";
			};
			class isHash
			{
				description = "Check if a value is a Hash data structure.";
				file = "\x\cba\addons\hashes\fnc_isHash.sqf";
			};
		};
	};
};
//};
