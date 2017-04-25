/* ----------------------------------------------------------------------------
Function: CBA_fnc_dropMagazine

Description:
	Drop a magazine.

	Function which verifies existence of _item and _unit, returns false in case
	of trouble, or when able to remove _item from _unit true in case of success.

Parameters:
	_unit   - the unit that should drop a magazine [Object]
	_item   - class name of the magazine to drop [String]

Returns:
	true if successful, false otherwise 

Examples:
	(begin example)
	_result = [player, "SmokeShell"] call CBA_fnc_dropMagazine
	(end)

Author:

---------------------------------------------------------------------------- */

#include "script_component.hpp"
SCRIPT(dropMagazine);

#define __scriptname fnc_dropMagazine

#define __cfg (configFile >> "CfgMagazines")
#define __action "DROPMAGAZINE"
#define __ar (magazines _unit)

private ["_unit", "_item", "_holder"];
PARAMS_1(_unit);
if (typeName _unit != "OBJECT") exitWith
{
	TRACE_2("Unit not Object",_unit,_item);
	false
};
_item = _this select 1;
if (typeName _item != "STRING") exitWith
{
	TRACE_2("Item not String",_unit,_item);
	false
};
if (isNull _unit) exitWith
{
	TRACE_2("Unit isNull",_unit,_item);
	false
};
if (_item == "") exitWith
{
	TRACE_2("Empty Item",_unit,_item);
	false
};
if !(isClass (__cfg >> _item)) exitWith
{
	TRACE_2("Item not exist in Config",_unit,_item);
	false
};
if !(_item in __ar) exitWith
{
	TRACE_2("Item not available on Unit",_unit,_item);
	false
};
if (count _this > 2) then
{
	_holder = _this select 2;
} else {
	_holder = _unit;
};
if (typeName _holder != "OBJECT") exitWith
{
	TRACE_3("Holder not object",_unit,_item,_holder);
	false
};
if (isNull _holder) exitWith
{
	TRACE_3("Holder isNull",_unit,_item,_holder);
	false
};
_unit action [__action, _holder, _item];
TRACE_3("Holder: %3 - Success",_unit,_item,_holder);
true
