/*******************************************************************************
* BMD initialization                                                           *
*                                                                              *
* @param object  _this[0] - BMD Object                                         *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: BMDinit.sqf 121 2009-03-24 00:25:33Z ist                            $: *
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
private ["_bmd","_path","_boardNum"];
_bmd =  _this select 0;

if (isNil "BMDFuncLoaded") then {
	BMDFuncLoaded = 0
} else {
	BMDFuncLoaded = 1
};

if (BMDFuncLoaded == 0) then {
    BMDModFName = "x\acex_ru\addons\t_veh_bmd1";
    BMDdebuging = true;

    private ["_p"];
    //_p = format ["\%1\scripts\functions", BMDModFName];
    _p = "\x\acex_ru\addons\c_veh_bmd1\functions";

    BMDC_vehicles               = ["ACE_BMD_1P_RU", "ACE_BMD_1_RU"];
    BMDC_hasVariableClearance   = ["ACE_BMD_1P_RU", "ACE_BMD_1_RU"];
    BMDC_hasCatwater            = ["ACE_BMD_1P_RU", "ACE_BMD_1_RU"];
    BMDC_vehiclesCargoTurrets   = [
        ["ACE_BMD_1P_RU",[3,4,5]],
        ["ACE_BMD_1_RU",[3,4,5]],
        ["ACE_BMD_1P_RUS",[3,4,5]],
		["ACE_BMD_1_CDF",[3,4,5]]
    ];

    BMDF_echo = compile (
        preprocessFileLineNumbers format ["%1\%2.sqf",_p,"echoDebug"]
    );
    BMDF_getRandomNum = compile (
        preprocessFileLineNumbers format ["%1\%2.sqf",_p,"getRandomNumber"]
    );
    BMDF_getRandomFromArr = compile (
        preprocessFileLineNumbers format ["%1\%2.sqf",_p,"getRandomArElement"]
    );
    BMDF_setBoardNum = compile (
        preprocessFileLineNumbers format ["%1\%2.sqf",_p,"setBMDNumber"]
    );
    BMDF_setArmSymbol = compile (
        preprocessFileLineNumbers format ["%1\%2.sqf",_p,"setBMDArmSymbol"]
    );
    BMDF_setRegimentSymbol = compile (
        preprocessFileLineNumbers format ["%1\%2.sqf",_p,"setBMDRegimentSymbol"]
    );
    BMDF_setClearance = compile (
        preprocessFileLineNumbers format ["%1\%2.sqf",_p,"setClearance"]
    );
    BMDF_setCutwater = compile (
        preprocessFileLineNumbers format ["%1\%2.sqf",_p,"setCutwater"]
    );

};

// Set BMD number
[_bmd,0] call BMDF_setBoardNum;
// Set BMD arm symbol
[_bmd,"vdv"] call BMDF_setArmSymbol;
// Set BMD regiment symbol
[_bmd,"random"] call BMDF_setRegimentSymbol;
