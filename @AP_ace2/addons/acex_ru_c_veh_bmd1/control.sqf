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
* $Id:: control.sqf 120 2009-03-23 17:34:01Z ist                            $: *
* author: ist <ist@g76.org> http://g76.org                                     *
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

if ("ARRAY" != typeName _this) exitWith {["Wrong parameters count","control"] call BMDF_echo;};
if (1 > count _this) exitWith {["Wrong parameters count","control"] call BMDF_echo;};
if (("OBJECT" != typeName (_this select 0))||("STRING" != typeName (_this select 1))) exitWith {
    ["Wrong parameters","control"] call BMDF_echo;
};
private ["_caller","_callerType","_bmd","_driver","_com","_val"];
_caller = _this select 0;
_com    = _this select 1;
if (2 < count _this) then { _val = _this select 2; };
_callerType = "unknown";
if (_caller isKindOf "Man") then {
    private ["_v"];
    _callerType = "man";
    _v = vehicle _caller;
    if (_v == _caller) exitWith {
        ["Unit not in vehicle","control"] call BMDF_echo;
    };
    if not (typeOf _v in BMDC_vehicles) exitWith {
        ["This vehicle not supported by this mod","control"] call BMDF_echo;
    };
    _bmd    = _v;
    _driver = _caller;
}
else {
    if (_caller isKindOf "LandVehicle") then {
        if not (typeOf _caller in BMDC_vehicles) exitWith {
            ["This vehicle not supported by this mod","control"] call BMDF_echo;
        };
        _callerType = "self";
        _bmd = _caller;
        _driver = driver _bmd;
    };
};
if (isNil "_bmd") exitWith {
    ["Unsuported procedure call","control"] call BMDF_echo;
};

/**
 * Functions call
 */

switch (_com) do {
    case "suspension": {
        if (isNil "_driver") exitWith {
            ["Unsuported procedure call","control"] call BMDF_echo;
        };
        if ((_callerType != "man") && (_caller != _driver)) exitWith {
            ["Unit not a driver","control"] call BMDF_echo;
        };
        [_bmd,_val] call BMDF_setClearance;
    };
    case "watershields": {
        if (isNil "_driver") exitWith {
            ["Unsuported procedure call","control"] call BMDF_echo;
        };
        if ((_callerType != "man") && (_caller != _driver)) exitWith {
            ["Unit not a driver","control"] call BMDF_echo;
        };
        [_bmd,_val] call BMDF_setCutwater;
    };
    case "marking": {
        if ("ARRAY" != typeName _val) exitWith {
            ["Marking: listen of array","control"] call BMDF_echo;
        };
        if (3 > count _val) exitWith {
            ["Not enough parameters for marking","control"] call BMDF_echo;
        };
        [_bmd,_val select 0] spawn BMDF_setBoardNum;
        [_bmd,_val select 1] spawn BMDF_setRegimentSymbol;
        [_bmd,_val select 2] spawn BMDF_setArmSymbol;
    };
	case "markingIraq": {
        if (2 > count _val) exitWith {
            ["Not enough parameters for marking","control"] call BMDF_echo;
        };
        [_bmd,_val select 0] spawn BMDF_setIraqNum;
        [_bmd,_val select 1] spawn BMDF_setIraqTurSymbol;
    };
    case "okb": {
        [_bmd,   915] spawn BMDF_setBoardNum;
        [_bmd, "915"] spawn BMDF_setRegimentSymbol;
        [_bmd, "915"] spawn BMDF_setArmSymbol;
    };
};
