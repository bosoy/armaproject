/*******************************************************************************
* Repeated concatenation.                                                      *
*                                                                              *
* @param  string  _str - Any string.                                           *
* @param  integer _num - Number of repeats.                                    *
* @return string       - Result.                                               *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: repeatString.sqf 2 2010-08-16 16:45:20Z ist                         $: *
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
scriptName "repeatString";
private ["_result","_str","_num"];
_result = "";
if (2 == count _this) then
{
	_str = _this select 0;
	_num = _this select 1;
	if (1 <= _num) then
	{
		private ["_i"];
		for "_i" from 1 to _num do
		{
			_result = _result + _str;
		};
	};
};
_result 