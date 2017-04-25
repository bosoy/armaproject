/*******************************************************************************
* Script for personalization BMD after loading                                 *
*                                                                              *
* @param object  _this[0] - BMD Object                                         *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: set.sqf 36 2009-01-20 22:51:03Z ist                                 $: *
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
if ("ARRAY" != typeName _this) exitWith {["Wrong parameters count","set"] call BMDF_echo;};
if (1 > count _this) exitWith {["Wrong parameters count","set"] call BMDF_echo;};
private ["_cp","_BMD"];
_cp = count _this;

switch (_cp) do {
    case 2: {
        private ["_num"];
        _BMD = _this select 0;
        _num = _this select 1;
        [_BMD,_num] call BMDF_setBoardNum;
    };
    case 3: {
        private ["_num","_reg"];
        _BMD = _this select 0;
        _num = _this select 1;
        _reg = _this select 2;
        [_BMD,_num] call BMDF_setBoardNum;
        [_BMD,_reg] call BMDF_setRegimentSymbol;
    };
    case 4: {
        private ["_num","_reg","_arm"];
        _BMD = _this select 0;
        _num = _this select 1;
        _reg = _this select 2;
        _arm = _this select 3;
        [_BMD,_num] call BMDF_setBoardNum;
        [_BMD,_reg] call BMDF_setRegimentSymbol;
        [_BMD,_arm] call BMDF_setArmSymbol;
    };
};
