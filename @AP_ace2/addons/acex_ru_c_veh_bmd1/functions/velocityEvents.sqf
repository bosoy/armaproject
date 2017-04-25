/*******************************************************************************
* Script for cheking speed vector of BMD                                       *
*                                                                              *
* @param object  _this[0] - BMD Object                                         *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: velocityEvents.sqf 75 2009-02-13 15:21:58Z ist                      $: *
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

private ["_bmd","_at","_dt","_memHypot"];
private ["_hypot","_sway"];

_bmd = _this select 0;
_at = 10;  // Acceleration threshold
_dt = -10; // Deceleration threshold
_memHypot = 0;

/**
 * Calculating the hypotenuse
 *
 * @param  float _this[0] - Cathetus 1
 * @param  float _this[0] - Cathetus 2
 * @return float          - Hypotenuse
 */
_hypot = {
    private ["_c1","_c2"];
    _c1 = _this select 0;
    _c2 = _this select 1;
    sqrt ((_c1 * _c1) + (_c2 * _c2));
};
/**
 * Wait for event...
 */
while {damage _bmd < 0.96} do {
    scopeName "VeloCalc";
    private ["_x","_z","_dg","_h","_acc","_msg"];
    waitUntil { (speed _bmd != 0) || (damage _bmd >= 0.96) };
    _x = velocity _bmd select 0;
    _z = velocity _bmd select 1;
    _dg = _x atan2 _z;
    if (_dg < 0) then { _dg = 360 + _dg; };
    _h = [_x,_z] call _hypot;
    _acc = _h - _memHypot;
    _memHypot = _h;
    //_msg = format ["Dir (acc/veh): (%1 / %2) ACC: %3",_dg,direction _bmd,_acc];
    //[_msg,"velocityEvents"] call BMDF_echo;
    [_bmd,_acc] call BMDF_doSway;
    sleep 0.5;
};

true 