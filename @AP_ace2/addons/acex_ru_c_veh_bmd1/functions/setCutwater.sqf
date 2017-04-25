/*******************************************************************************
* This function change BMD cutwater state                                      *
*                                                                              *
* @param object _this[0] - BMD Object                                          *
* @param string _this[1] - Command (up, down or switch)                        *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: setCutwater.sqf 96 2009-02-19 13:38:46Z ist                         $: *
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

private ["_bmd","_do","_switch"];

_bmd = _this select 0;
_do  = _this select 1;

if not (typeOf _bmd in BMDC_hasCatwater) exitWith {
    ["This vehicle does not have cutwater.","setCutwater"] call BMDF_echo;
};
switch (_do) do {
    case "up":   { _switch = 0; };
    case "down": { _switch = 1; };
    default      { _switch = 2; };
};
_do = nil;

private ["_af"];
_af = _bmd animationPhase "wave_l";
if ((_af != 0) && (_af != 1)) exitWith {
    ["Changing cutwater position in progress.","setCutwater"] call BMDF_echo;
};

if (_switch == 2) then {
    switch (_af) do {
        case 0: { _switch = 1; };
        case 1: { _switch = 0; };
    };
};
if (_af != _switch) then {
    private ["_anim"];
    _anim = [
        "wave_l",
        "wave_r",
        "wave_c"
    ];
    for "_i" from 0 to (count _anim)-1 do {
        _bmd animate [_anim select _i, _switch];
    };
};

true 