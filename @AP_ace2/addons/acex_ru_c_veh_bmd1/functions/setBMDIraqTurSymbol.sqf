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
    private ["_inO","_inN","_SoA","_isGuard","_num"];
    _bmd = _this select 0;
    _isGuard = false;
	_num = _this select 1;

	if (_num == 0) then {
		private ["_rand"];

		_rand = ceil(random 9);

		if (_rand < 1) then {
			_rand = _rand + 1;
		};

		_bmd setObjectTexture [5, format ["\%1\num\ir_tur_%2.paa",BMDModFName,_rand]];
	}
	else {
		if (_num > 9) then {
			_num = 9;
		};
		_bmd setObjectTexture [5, format ["\%1\num\ir_tur_%2.paa",BMDModFName,_num]];
	};
};
true 