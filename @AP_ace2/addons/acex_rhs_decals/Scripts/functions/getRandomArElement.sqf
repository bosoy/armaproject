/*******************************************************************************
* This function return random value from given array.                          *
*                                                                              *
* @param  array _ar - Array for select random key                              *
* @return mixed     - Random value from given array                            *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: getRandomArElement.sqf 2 2010-08-16 16:45:20Z ist                   $: *
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
scriptName "getRandomArElement";
private ["_val","_ar","_cnt"];
if (0 < count _this) then
{
    _ar = _this select 0;
    _cnt = count _ar;
    if (0 < count _ar) then
    {
        private ["_rand"];
        _rand = floor(random _cnt);
        if (_rand >= _cnt) then
        {
            _rand = _cnt - 1;
        };
        _val = _ar select _rand;
    };
};
_val 