/*******************************************************************************
* Antenna sways                                                                *
*                                                                              *
* @param object _this[0] - BMD Object                                          *
* @param float  _this[1] - BMD "G" factor                                      *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: doSway.sqf 75 2009-02-13 15:21:58Z ist                              $: *
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
private ["_bmd","_amp","_g","_attenuation","_reverce"];
_revers = false;
_bmd = _this select 0;
_g = _this select 1;
_attenuation = 5;

if (_g < 0) then {
    _g = _g * -1;
    _revers = true;
};
if (10 < _g) then { _g = 10; };
_amp = _g / 10;

if (!_revers) then {
    _bmd animate ["antenna_amp_fore", _amp];
    waitUntil { _amp == _bmd animationPhase "antenna_amp_fore"; };
    _bmd animate ["antenna_amp_fore", 0];
    waitUntil { 0 == _bmd animationPhase "antenna_amp_fore"; };
    _amp = _amp - (_amp / _attenuation);
};
while {true} do {
    scopeName "swayAntena";
    if (0.1 >= _amp) then { breakOut "swayAntena"; };
    _bmd animate ["antenna_amp_aft", _amp];
    waitUntil { _amp == _bmd animationPhase "antenna_amp_aft"; };
    _bmd animate ["antenna_amp_aft", 0];
    waitUntil { 0 == _bmd animationPhase "antenna_amp_aft"; };
    _amp = _amp - (_amp / _attenuation);
    if (0.1 >= _amp) then { breakOut "swayAntena"; };
    _bmd animate ["antenna_amp_fore", _amp];
    waitUntil { _amp == _bmd animationPhase "antenna_amp_fore"; };
    _bmd animate ["antenna_amp_fore", 0];
    waitUntil { 0 == _bmd animationPhase "antenna_amp_fore"; };
    _amp = _amp - (_amp / _attenuation);
    if (0.1 >= _amp) then { breakOut "swayAntena"; };
};
_amp = 0;
if (_amp != _bmd animationPhase "antenna_amp_fore") then {
    _bmd animate ["antenna_amp_fore", _amp];
};
if (_amp != _bmd animationPhase "antenna_amp_aft") then {
    _bmd animate ["antenna_amp_aft", _amp];
};

true 