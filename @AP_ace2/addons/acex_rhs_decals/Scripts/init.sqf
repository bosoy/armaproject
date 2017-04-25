/*******************************************************************************
* Draw decal.                                                                  *
*                                                                              *
* @param  object _object - Vehicle object.                                     *
* @param  array  _params - Decal parameters.                                   *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: init.sqf 47 2010-08-27 01:59:55Z ist                                $: *
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
scriptName "init";
private ["_dmsg"];
_dmsg = "In addon \RHS_Decals\Scripts\init.sqf";
if (!(isNil "RHSDecalsOff") && {RHSDecalsOff}) exitWith {};
if (isNil "RHSDecalsFuncLoaded") then
{
	RHSDecalsVersion = 1.227;
	RHSDecalsModul = "RHS_Decals";
	RHSDecalsFuncLoaded = true;
	RHSDecalsDebugMode = false;
	private ["_p"];
	_p = format ["\%1\Scripts\functions", RHSDecalsModul];
	fRHSEchoDebug = compile (
		preprocessFileLineNumbers format ["%1\%2.sqf",_p,"echoDebug"]
	);
	fRHSGetRandomNum = compile (
		preprocessFileLineNumbers format ["%1\%2.sqf",_p,"getRandomNumber"]
	);
	fRHSGetRandomArElement = compile (
		preprocessFileLineNumbers format ["%1\%2.sqf",_p,"getRandomArElement"]
	);
	fRHSRepeatString = compile (
		preprocessFileLineNumbers format ["%1\%2.sqf",_p,"repeatString"]
	);
	fRHSNumberToDigits = compile (
		preprocessFileLineNumbers format ["%1\%2.sqf",_p,"numberToDigits"]
	);
};
if (("ARRAY" == typeName _this) && (2 == count _this)) then
{
	private ["_object","_params","_i"];
	_object = _this select 0;
	_params = _this select 1;
	if ("OBJECT" != typeName _object) exitWith
	{
		diag_log format ["ERROR! Bad parameters (need object): %1 %2",_object,_dmsg];
	};
	if ("ARRAY" != typeName _params) exitWith
	{
		diag_log format ["ERROR! Bad parameters (need array): %1 %2",_params,_dmsg];
	};
	//for "_i" from 0 to count _params do
	for "_i" from 0 to ((count _params) - 1) do
	{
		private ["_q","_rq","_th"];
		_q = _params select _i;
		if ("ARRAY" != typeName _q) exitWith
		{
			diag_log format ["ERROR! Bad parameters (need array): %1 %2",_q,_dmsg];
		};
		switch (_q select 0) do
		{
			case "Number" :
			{
				_q set [0,_object];
				_th = _q execVM format [
					"\%1\Scripts\drawNumber.sqf",
					RHSDecalsModul
				];
			};
			case "Label" :
			{
				_q set [0,_object];
				_th = _q execVM format [
					"\%1\Scripts\drawSymbol.sqf",
					RHSDecalsModul
				];
			};
		};
	}
};