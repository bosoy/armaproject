/*******************************************************************************
* This function return random value from given array.                          *
*                                                                              *
* @param  array _this[0] - Array for select random key                         *
* @return mixed          - Random value from given array                       *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: getRandomArElement.sqf 2 2009-01-17 06:00:33Z ist                   $: *
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
private ["_val","_ar","_cnt"];

if (count _this > 0) then {
    _ar = _this select 0;
    _cnt = count _ar;
    if (count _ar > 0) then {
        private ["_rand"];
        _rand = floor(random _cnt);
        if (_rand >= _cnt) then {
            _rand = _cnt - 1;
        };
        _val = _ar select _rand;
    };
};

_val