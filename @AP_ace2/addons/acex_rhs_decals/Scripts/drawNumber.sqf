/*******************************************************************************
* Draw number.                                                                 *
*                                                                              *
* @param  object  _object          - Object.                                   *
* @param  array   _labels          - Array with labels numbers.                *
* @param  string  _style           - Use specific numbers style.               *
* @param  integer _number optional - Number. (if not present, get random)      *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: drawNumber.sqf 41 2010-08-25 23:31:23Z ist                          $: *
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
scriptName "drawNumber";
if not (isServer) exitWith {};
private ["_dmsg"];
_dmsg = "In addon \RHS_Decals\Scripts\drawNumber.sqf";
if (isNil "RHSDecalsFuncLoaded") exitWith {diag_log format ["ERROR! Addon not initsialized! %1",_dmsg];};
private ["_style","_labels","_size","_number","_dig"];
if (2 < count _this) then
{
	_object = _this select 0;
	_labels = _this select 1;
	_style  = _this select 2;
	if (3 < count _this) then
	{
		_number = _this select 3;
	} else {
		_number = 0;
	};
	if ("ARRAY" == typeName (_labels select 0)) then
	{
		private ["_i","_l","_c"];
		_size = count (_labels select 0);
		if (0 == _number) then
		{
			_number = [_size] call fRHSGetRandomNum;
		};
		_dig = [_number] call fRHSNumberToDigits;
		for "_i" from 0 to ((count _labels) - 1) do
		{
			_l = _labels select _i;
			for "_c" from 0 to ((count _l) - 1) do
			{
				_object setObjectTexture [
					_l select _c,
					format [
						"\%1\Data\Numbers\%2\%3_ca.paa",
						RHSDecalsModul,
						_style,
						_dig select _c
					]
				];
			};
		};
	} else {
		_size = count _labels;
		if (0 == _number) then
		{
			_number = [_size] call fRHSGetRandomNum;
		};
		_dig = [_number] call fRHSNumberToDigits;
		private ["_c"];
		for "_c" from 0 to (_size - 1) do
		{
			_object setObjectTexture [
				_labels select _c,
				format [
					"\%1\Data\Numbers\%2\%3_ca.paa",
					RHSDecalsModul,
					_style,
					_dig select _c
				]
			];
		};
	};
};