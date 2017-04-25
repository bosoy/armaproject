/*******************************************************************************
* Draw symbol.                                                                 *
*                                                                              *
* @param object          _object - Vehicle object                              *
* @param array           _labels - List of Id's for place symbol.              *
* @param integer         _type   - Symbol type                                 *
* @param string optional _symbol - Symbol name                                 *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: drawSymbol.sqf 41 2010-08-25 23:31:23Z ist                          $: *
* author: ist <ist@redhamer.su>                                                *
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
scriptName "drawSymbol";
if not (isServer) exitWith {};
private ["_dmsg"];
_dmsg = "In addon \RHS_Decals\Scripts\drawSymbol.sqf";
if (isNil "RHSDecalsFuncLoaded") exitWith
{
	diag_log format ["ERROR! Addon not initsialized! %1",_dmsg];
};
private ["_object","_labels","_type","_symbol","_variant"];
if (3 <= count _this) then
{
	_object = _this select 0;
	_labels = _this select 1;
	_type   = _this select 2;
	if ("ARRAY" != typeName _labels) exitWith
	{
		diag_log format ["ERROR! Bad parameters (need array): %1 %2",_labels,_dmsg];
	};
	private ["_getIndex","_idx","_dkv","_i"];
	_getIndex = compile (
		preprocessFileLineNumbers format [
			"\%1\Data\Labels\%2\index.sqf",
			RHSDecalsModul,
			_type
		]
	);
	_idx = [] call _getIndex;
	while{isNil "fRHSGetRandomArElement"} do
	{
		//diag_log text "Waiting symbols.";
		sleep 0.5;
	};
	if (4 == count _this) then
	{
		_symbol = _this select 3;
		if ("ARRAY" == typeName _symbol) then
		{
			_variant = _symbol select 1;
			_symbol = _symbol select 0;
			_dkv = _idx select _symbol;
			_dkv = _dkv select _variant;
		} else {
			_dkv = _idx select _symbol;
			if (1 < count _dkv) then
			{
				_dkv = [_dkv] call fRHSGetRandomArElement;
			} else {
				_dkv = _dkv select 0;
			};
		};
	} else {
		_dkv = [_idx] call fRHSGetRandomArElement;
		if (1 < count _dkv) then
		{
			_dkv = [_dkv] call fRHSGetRandomArElement;
		} else {
			_dkv = _dkv select 0;
		};
	};
	for "_i" from 0 to ((count _labels) - 1) do
	{
		private ["_c"];
		if (1 < count _dkv) then
		{
			_c = [_dkv] call fRHSGetRandomArElement;
		} else {
			_c = _dkv select 0;
		};
		_object setObjectTexture [
			_labels select _i,
			format [
				"\%1\Data\Labels\%2\%3",
				RHSDecalsModul,
				_type,
				_c
			]
		];
	};
};