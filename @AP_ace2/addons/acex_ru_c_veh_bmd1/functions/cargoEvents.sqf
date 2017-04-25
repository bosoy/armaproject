/*******************************************************************************
* Script for cheking state of main turret guner                                *
*                                                                              *
* @param object  _this[0] - BMD Object                                         *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: cargoEvents.sqf 58 2009-01-28 13:51:08Z ist                         $: *
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
if not (isServer) exitWith {};

private ["_onMarch","_inCombat","_getCargoUnits"];
private ["_bmd","_casper","_bct","_mS","_ejectSpeed","_maxEjectSpeed"];

_bmd = _this select 0;
_casper = "Logic" createVehicle [0,0];
_mS = getNumber (configFile >> "CfgVehicles" >> (typeOf _bmd) >> "maxSpeed");

_ejectSpeed = 10;
_maxEjectSpeed = 15;

/**
 * Get rear turrets numbers of current BMD
 */ {
    scopeName "forEachUn01";
    if (_x find (typeOf _bmd) > -1) then {
        _bct = _x select 1;
        breakOut "forEachUn01";
    };
} forEach BMDC_vehiclesCargoTurrets;
/**
 * Return array of "ejectable" units in current BMD
 *
 * @return array - Units
 * @todo Remove odd units pushing (rear turrets operators) before relise mod =)
 */
_getCargoUnits = {
    private ["_cu"];
    _cu = []; {
        scopeName "BMDCARGO";
        private ["_avr"];
        _avr = assignedVehicleRole _x;
        if (count _avr > 0) then {
            switch (_avr select 0) do {
                case "Cargo": {_cu set [count _cu,_x];};
                case "Turret": {
                    if (count _avr > 1) then {
                        if ((_avr select 1) select 0 in _bct) then {
                            _cu set [count _cu,_x];
                        };
                    };
                };
            };
        };
    } forEach crew _bmd;
    _cu;
};
/**
 * Run when BMD switch to "On the march" mode
 *
 * @todo Check, if gunner ejected, put GAMELOGIC in turret and set turret
 *       direction to forward.
 */
_onMarch = {
    ["Alarm zu Ende!","cargoEvents"] call BMDF_echo;
    _bmd setBehaviour "CARELESS";
    true;
};
/**
 * Run when BMD switch to combat mode
 * @todo: remove odd debug messages
 *        remove rear gunners evacuation, when Beta period end =)
 */
_inCombat = {
    private ["_cu"];
    ["Alarm! Der schutze kam!","cargoEvents"] call BMDF_echo;
    _cu = [] call _getCargoUnits;
    _bmd setBehaviour "COMBAT";
    if (count _cu > 0) then {
        private ["_s"];
        _bmd limitSpeed _ejectSpeed;
        _bmd forceSpeed _ejectSpeed;
        waitUntil {speed _bmd <= _maxEjectSpeed}; {
            scopeName "BMDCREW";
            _x action ["EJECT", _bmd];
            waitUntil {(_x == vehicle _x) || not (alive _x)};
        } forEach _cu;
        _bmd limitSpeed _ms + 50;
        _bmd forceSpeed _mS;
        _bmd sendSimpleCommand "FAST";
    };
    true;
};
/**
 * KILLERLOOP i dont known, how many resourses need for this idiotic method
 * @todo: check "alive _bmd" - seems like BI-Bug =) try to use "damage _bmd".
 *        and add some code...
 */
while {damage _bmd < 0.96} do {
    scopeName "KILLERLOOP";
    waitUntil {
        ((gunner _bmd) isKindOf "Man" && ((gunner _bmd) distance _bmd) == 0)
        or (damage _bmd >= 0.96)
    };
    if (damage _bmd >= 0.96) then { breakOut "KILLERLOOP"; };
    call _inCombat;
    waitUntil {
        ((gunner _bmd) isKindOf "Man" && ((gunner _bmd) distance _bmd) > 0)
        or (not ((gunner _bmd) isKindOf "Man") || (damage _bmd >= 0.96))
    };
    call _onMarch;
};

["BMD in die Luft fliegen!","cargoEvents"] call BMDF_echo;
deleteVehicle _casper;

true 