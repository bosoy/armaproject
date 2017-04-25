////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:50 2013 : Created on Thu Jan 03 12:00:50 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_arrays : config.bin{
class CfgPatches
{
	class cba_arrays
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
		class Arrays
		{
			class filter
			{
				description = "Filter each element of an array via a function.";
				file = "\x\cba\addons\arrays\fnc_filter.sqf";
			};
			class getArrayDiff
			{
				description = "A function used to return the differences between two arrays. Parameters: Two Arrays of strings (must not contain scalars) Example: _distance = [[0,0,1], [0,0,0]] call CBA_fnc_getArrayDiff Returns: Array Differences (for above example, return is [[1],[0]]) Author: Rommel";
				file = "\x\cba\addons\arrays\fnc_getArrayDiff.sqf";
			};
			class getArrayElements
			{
				description = "A function used to return the element counts in an array. Parameters: Array Example: _types = [0,0,1,1,1,1] call CBA_fnc_getArrayElements Returns: Array element counts (for above example, return would be [0,2,1,4]) Author: Rommel && sbsmac";
				file = "\x\cba\addons\arrays\fnc_getArrayElements.sqf";
			};
			class inject
			{
				description = "Accumulates a value by passing elements of an array ""through"" a function.";
				file = "\x\cba\addons\arrays\fnc_inject.sqf";
			};
			class join
			{
				description = "Joins an array of values into a single string, joining each fragment around a separator string. Inverse of <CBA_fnc_split>.";
				file = "\x\cba\addons\arrays\fnc_join.sqf";
			};
			class reject
			{
				description = "Reject array elements for which the block returns true";
				file = "\x\cba\addons\arrays\fnc_reject.sqf";
			};
			class select
			{
				description = "Select array elements for which the block returns true";
				file = "\x\cba\addons\arrays\fnc_select.sqf";
			};
			class shuffle
			{
				description = "Shuffles an array's contents into random order, returning a new array.";
				file = "\x\cba\addons\arrays\fnc_shuffle.sqf";
			};
			class sortNestedArray
			{
				description = "Used to sort a nested array from lowest to highest using quick sort based on the specified column, which must have numerical data. Parameters: _array: array - Nested array to be sorted _index: integer - sub array item index to be sorted on Example: _array = [_array,1] call CBA_fnc_sortNestedArray Returns: Passed in array Author: Standard algorithm";
				file = "\x\cba\addons\arrays\fnc_sortNestedArray.sqf";
			};
		};
	};
};
//};
