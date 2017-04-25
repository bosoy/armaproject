////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:55 2013 : Created on Thu Jan 03 12:00:55 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_strings : config.bin{
class CfgPatches
{
	class cba_strings
	{
		units[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"CBA_common"};
		version = "1.0.1.196";
		author[] = {"Spooner","Kronzky"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
};
class CfgFunctions
{
	class CBA
	{
		class Strings
		{
			class capitalize
			{
				description = "Upper case the first letter of the string, lower case the rest.";
				file = "\x\cba\addons\strings\fnc_capitalize.sqf";
			};
			class find
			{
				description = "Finds a string within another string.";
				file = "\x\cba\addons\strings\fnc_find.sqf";
			};
			class formatElapsedTime
			{
				description = "Formats time in seconds according to a format. Intended to show time elapsed, rather than time-of-day.";
				file = "\x\cba\addons\strings\fnc_formatElapsedTime.sqf";
			};
			class formatNumber
			{
				description = "Formats a number to a minimum integer width and to a specific number of decimal places (including padding with 0s and correct rounding). Numbers are always displayed fully, never being condensed using an exponent (e.g. the number 1.234e9 would be given as ""1234000000"").";
				file = "\x\cba\addons\strings\fnc_formatNumber.sqf";
			};
			class leftTrim
			{
				description = "Trims white-space (space, tab, newline) from the left end of a string.";
				file = "\x\cba\addons\strings\fnc_leftTrim.sqf";
			};
			class replace
			{
				description = "Replaces substrings within a string. Case-dependent.";
				file = "\x\cba\addons\strings\fnc_replace.sqf";
			};
			class rightTrim
			{
				description = "Trims white-space (space, tab, newline) from the right end of a string.";
				file = "\x\cba\addons\strings\fnc_rightTrim.sqf";
			};
			class split
			{
				description = "Splits a string into substrings using a separator. Inverse of <CBA_fnc_join>.";
				file = "\x\cba\addons\strings\fnc_split.sqf";
			};
			class strLen
			{
				description = "Counts the number of characters in a string.";
				file = "\x\cba\addons\strings\fnc_strLen.sqf";
			};
			class trim
			{
				description = "Trims white-space (space, tab, newline) from the both ends of a string.";
				file = "\x\cba\addons\strings\fnc_trim.sqf";
			};
		};
	};
};
//};
