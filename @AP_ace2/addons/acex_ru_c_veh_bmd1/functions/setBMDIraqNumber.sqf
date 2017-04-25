/*******************************************************************************
* This function set BMD board number                                           *
*                                                                              *
* @param object  _this[0] - BMD Object                                         *
* @param integer _this[1] - Number (from 100 to 999)                           *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: setBMDNumber.sqf 98 2009-02-20 11:08:57Z ist                        $: *
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
private ["_bmd","_inN","_n","_i"];
//hint "SetNumber is being executed.";
if (count _this == 2) then {
    _bmd = _this select 0;
    _inN = _this select 1;

    if ((_inN > 99999) || (_inN < 10000)) then {
        _inN = [] call BMDF_getRandom5Num;
    };

    _n =
    [
        floor ((_inN / 10000) % 10),
        floor ((_inN / 1000) % 10),
		floor ((_inN / 100) % 10),
		floor ((_inN / 10) % 10),
        ((_inN % 10) - ((_inN % 10) % 1))
    ];

    for "_i" from 0 to 4 do {
        _bmd setObjectTexture [_i, format ["\%1\num\ir_%2.paa",BMDModFName,(_n select _i)]];
    };
};

true