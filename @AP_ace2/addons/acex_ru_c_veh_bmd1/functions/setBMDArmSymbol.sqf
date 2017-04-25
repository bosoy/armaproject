/*******************************************************************************
* This function set BMD symbol of arm                                          *
*                                                                              *
* @param object  _this[0] - BMD Object                                         *
* @param string  _this[1] - Symbol of arm name                                 *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: setBMDArmSymbol.sqf 127 2009-03-25 01:17:56Z ist                    $: *
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
if (count _this == 2) then {
	//hint "ArmySymbol is being executed.";
    private ["_inO","_inN","_SoA","_isGuard"];
    _inO = _this select 0;
    _isGuard = false;
    if ("ARRAY" == typeName (_this select 1)) then {
        private ["_tmp"];
        _tmp = _this select 1;
        if (2 != count _tmp) exitWith {
            ["Incorrect parameters","setBMDArmSymbol"] call BMDF_echo;
        };
        _inN = _tmp select 0;
        _isGuard = _tmp select 1;
    }
    else {
        if ("STRING" != typeName (_this select 1)) exitWith {
            ["Incorrect parameters","setBMDArmSymbol"] call BMDF_echo;
        };
        _inN = _this select 1;
    };

    switch (_inN) do {
        case "vdv": { _SoA = "vdv"; };
        case "gru": { _SoA = "gru"; };
        case "mvd": { _SoA = "mvd"; };
        case "915": { _SoA = "okb"; };
        case "no":  { _SoA = "no"; };
        default     { _SoA = "vdv"; };
    };
    _inO setObjectTexture [3, format ["\%1\num\%2.paa",BMDModFName,_SoA]];
    if (_isGuard) then {
        _inO setObjectTexture [5, format ["\%1\num\gvard.paa",BMDModFName]];
    }
    else {
        _inO setObjectTexture [5, format ["\%1\num\%2.paa",BMDModFName,_SoA]];
    };
};
true 