/*******************************************************************************
* This function set BMD Symbol of VDV regiment                                 *
*                                                                              *
* @param object _this[0] - BMD Object                                          *
* @param string _this[1] - Name (number) of VDV regiment                       *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: setBMDRegimentSymbol.sqf 127 2009-03-25 01:17:56Z ist               $: *
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
if (count _this > 1) then {
	//hint "SetRegimentSymbol is being executed.";
    private ["_inO","_inN","_SoR","_ar"];

    _inO = _this select 0;
    _inN = _this select 1;

    _ar = ["reg","reg2","reg3","reg4"];

    switch (_inN) do {
        case "106": {
            _SoR = _ar select 0;
        };
        case "76": {
            _SoR = _ar select 1;
        };
        case "7": {
            _SoR = _ar select 2;
        };
        case "kvadrat": {
            _SoR = _ar select 3;
        };
        case "915": {
            _SoR = "okb";
        };
        case "no": {
            _SoR = "no";
        };
        case "random": {
            _SoR = [_ar] call BMDF_getRandomFromArr;
        };
        default {
            _SoR = [_ar] call BMDF_getRandomFromArr;
        };
    };

    _inO setObjectTexture [4, format ["\%1\num\%2.paa",BMDModFName,_SoR]];
};

true