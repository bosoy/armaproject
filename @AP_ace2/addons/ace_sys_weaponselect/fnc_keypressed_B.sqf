//#define DEBUG_MODE_FULL
#include "script_component.hpp"

if (GVAR(Bdown)) exitwith {true};
GVAR(Bdown) = true;
if (!alive player || vehicle player != player) exitWith {GVAR(Bdown) = false; false};

private["_handled","_dikCode","_shift","_ctrl","_alt","_binocs","_curWeapon","_binocnt"];

_handled = false;
_dikCode = _this select 1;
_shift = _this select 2;
_ctrl = _this select 3;
_alt = _this select 4;

if (!_ctrl && {!_alt} && {_dikCode in (actionKeys "Binocular")}) then {
	if (player call ace_sys_wounds_fnc_isUncon) exitWith {};
	_binocs = [player] call FUNC(getBinoculars);
	_binocnt = count _binocs;
	if (_binocnt > 0) then { // have binoculars
		_curWeapon = currentWeapon player;
		if (_binocs find _curWeapon == -1) then {
			GVAR(lastw) = _curWeapon;
			player selectweapon (_binocs select (if (_binocnt > 1 && {_shift}) then {1} else {0}));
		} else { // holding binocs
			player selectweapon GVAR(lastw);
		};
		_handled = true;
	};
};
GVAR(Bdown) = false;
_handled;
