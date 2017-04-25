/*******************************************************************************
* Print message in side chat. Only for debuging.                               *
*                                                                              *
* @param string          _this[0] - Message                                    *
* @param string optional _this[1] - Modul name                                 *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: echoDebug.sqf 58 2009-01-28 13:51:08Z ist                           $: *
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
if not (isServer) exitWith {};

if (BMDdebuging) then {
    private ["_msg","_modul","_casper","_tm"];
    _tm = round time;
    if ("ARRAY" != typeName _this) then {
        if ("STRING" != typeName _this) exitWith { echo "Wrong parameters"; };
        _msg = _this;
    }
    else {
        if (1 > count _this) exitWith { echo "Wrong count of parameters"; };
        _msg = _this select 0;
        if (1 < count _this) then {
            _modul = _this select 1;
        };
    };
    private ["_s","_m"];
    _s = _tm % 60;
    _m = (_tm - _s) / 60;
    if (_s < 10) then { _s = format["0%1",_s]; };
    if (_m < 10) then { _m = format["0%1",_m]; };
    _tm = format ["%1:%2",_m,_s];
    _casper = [side player,"base"];
    if (isNil _modul) then {
        _casper SideChat format ["[%1] %2",_tm,_msg];
    }
    else {
        _casper SideChat format ["(%3) [%1] %2",_tm,_msg,_modul];
    };
};
true 