/*******************************************************************************
* Control BMD functions                                                        *
*                                                                              *
* @param object         _this[0] - Object (vehicle, player, bot and etc.)      *
* @param string         _this[1] - Command                                     *
* @param mixed optional _this[2] - Command parameter                           *
* @return void                                                                 *
*                                                                              *
* @todo Add support for waypoints, triggers and game logic.                    *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: control.sqf 188 2010-02-28 22:00:23Z ist                            $: *
* author: ist <ist@redhammer.su>                                               *
*                                                                              *
* LICENSE:  This  program  is  free  software:  you can redistribute it and/or *
* modify it under the terms of the  GNU General Public License as published by *
* the Free Software Foundation, either version 3 of the License,  or  (at your *
* option) any later version.                                                   *
* This program is  distributed in the hope that it will be useful, but WITHOUT *
* ANY  WARRANTY;   without  even  the  implied  warranty of MERCHANTABILITY or *
* FITNESS FOR A PARTICULAR PURPOSE.   See  the  GNU General Public License for *
* more details.                                                                *
* You should have received a copy of the GNU General Public License along with *
* this program. If not, see <http://www.gnu.org/licenses/gpl.txt>.             *
*                                                                              *
*******************************************************************************/
scriptName "control";

#include "script_component.hpp"

if (isNil "cBMD2FuncLoaded") exitWith {diag_log "ERROR! Required addon not loaded!";};
if ("ARRAY" != typeName _this) exitWith {diag_log format["ERROR! Wrong parameters count! in \%1\control.sqf",cBMD2AddonName];};
if (1 > count _this) exitWith {diag_log format["ERROR! Wrong parameters count! in \%1\control.sqf",cBMD2AddonName];};
if (("OBJECT" != typeName (_this select 0))||("STRING" != typeName (_this select 1))) exitWith {diag_log format["ERROR! Wrong parameters! in \%1\control.sqf",cBMD2AddonName];};
private ["_caller","_callerType","_bmd","_driver","_com","_val"];
_caller = _this select 0;
_com    = _this select 1;
if (2 < count _this) then {_val = _this select 2;};
_callerType = "unknown";
if (_caller isKindOf "Man") then
{
	private ["_v"];
	_callerType = "man";
	_v = vehicle _caller;
	if (_v == _caller) exitWith {diag_log format["ERROR! Unit not in vehicle! in \%1\control.sqf",cBMD2AddonName];};
	if not (typeOf _v in cBMD2Vehicles) exitWith {diag_log format["ERROR! This vehicle not supported by this addon! in \%1\control.sqf",cBMD2AddonName];};
	_bmd    = _v;
	_driver = _caller;
}
else {
	if (_caller isKindOf "LandVehicle") then
	{
		if not (typeOf _caller in cBMD2Vehicles) exitWith {diag_log format["ERROR! This vehicle not supported by this addon! in \%1\control.sqf",cBMD2AddonName];};
		_callerType = "self";
		_bmd = _caller;
		_driver = driver _bmd;
	};
};
if (isNil "_bmd") exitWith {diag_log format["ERROR! Unsuported procedure call! in \%1\control.sqf",cBMD2AddonName];};
switch (_com) do
{
	case "suspension":
	{
		if (isNil "_driver") exitWith {diag_log format["ERROR! Unsuported procedure call! in \%1\control.sqf",cBMD2AddonName];};
		if ((_callerType != "man") && (_caller != _driver)) exitWith {diag_log format["ERROR! Unit not a driver! in \%1\control.sqf",cBMD2AddonName];};
		[_bmd,_val] call fBMD2SetClearance;
	};
	case "marking":
	{
		if ("ARRAY" != typeName _val) exitWith {diag_log format["ERROR! Marking: listen of array! in \%1\control.sqf",cBMD2AddonName];};
		if (3 > count _val) exitWith {diag_log format["ERROR! Not enough parameters for marking! in \%1\control.sqf",cBMD2AddonName];};
		private ["_h","_bn"];
		_bn = _val select 0;
		if (100 > _bn || 999 < _bn) then {_bn = 0};
		_h = [
			_bmd,
			[
				["Number", cBMD2NumberPlaces, "Default", _bn],
				["Label",  cBMD2ArmSymPlaces, "Army",    _val select 2],
				["Label",  cBMD2PlnSymPlaces, "Platoon", _val select 1]
			]
		] spawn COMPILE_FILE2(\RHS_Decals\Scripts\init.sqf);
	};
};
