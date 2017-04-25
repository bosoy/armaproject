/*******************************************************************************
* This function generate random number                                         *
*                                                                              *
* @param  integer _size - Number of digits                                     *
* @return integer       - Generated random nuber                               *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: getRandomNumber.sqf 2 2010-08-16 16:45:20Z ist                      $: *
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
scriptName "getRandomNumber";
private ["_rand","_size","_max","_min","_i"];
if (0 < count _this) then
{
	_size = _this select 0;
	_max = "9";
	_min = "1";
	for "_i" from 1 to (_size - 1) do
	{
		_max = _max + "9";
		_min = _min + "0";
	};
	_max = parseNumber _max;
	_min = parseNumber _min;
	_rand = ceil(random (_max - 1));
	if (_rand < _min) then
	{
		_rand = _rand + _min;
	};
};
_rand 