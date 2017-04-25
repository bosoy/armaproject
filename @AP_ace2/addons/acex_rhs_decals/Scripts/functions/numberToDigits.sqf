/*******************************************************************************
* Convert number to digits array.                                              *
*                                                                              *
* @param  integer _num - Number.                                               *
* @return array        - Array with digits.                                    *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: numberToDigits.sqf 2 2010-08-16 16:45:20Z ist                       $: *
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
scriptName "numberToDigits";
private ["_num","_digs","_size"];
if (0 < count _this) then
{
	private ["_div","_str","_i"];
	_num = _this select 0;
	_digs = [];
	_size = 0;
	_div = 2;
	while {true} do
	{
		scopeName "countSize";
		_size = _size + 1;
		if (isNil "_str") then {_str = "1";}
		else {_str = _str + "0";};
		_div = floor (_num / parseNumber _str);
		if ((10 > _div) && (1 <= _div)) then { breakOut "countSize"; };
	};
	for "_i" from 0 to (_size - 1) do
	{
		_str = "1" + (["0", (_size - (_i + 1))] call fRHSRepeatString);
		if (_i < _size) then
		{
			_digs set [_i, (floor ((_num / parseNumber _str) % 10))];
		}
		else {
			_digs set [_i, ((_num % 10) - ((_num % 10) % 1))];
		};
	};
};
_digs 