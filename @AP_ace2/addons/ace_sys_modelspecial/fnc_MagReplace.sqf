#include "script_component.hpp"

private ["_unit","_mag","_weapon","_compatibles","_newmag","_oldmag","_mag_re","_weap_re","_action","_currentWeapon","_currentMagazine","_ammo"];

PARAMS_4(_unit,_weapon,_compatibles,_mag); //_mag = current mag being checked

_mag_re = getNumber (configFile >> "CfgMagazines" >> _mag >> "ace_replace");
_weap_re = getNumber (configFile >> "CfgWeapons" >> _weapon >> "ace_replace");
if (_mag_re == 1 && {_weap_re == 1}) then {
	_oldmag = _mag;
	if (isText (configFile >> "CfgMagazines" >> _oldmag >> QGVAR(replacements) >> _weapon)) then {
		_newmag = getText (configFile >> "CfgMagazines" >> _oldmag >> QGVAR(replacements) >> _weapon);
		if (_newmag != _oldmag && {_newmag in _compatibles}) then {
			// Check whether weapon is loaded already
			_currentMagazine = currentMagazine _unit;
			_ammo = _unit ammo _weapon;
			while { ({_x == _oldmag} count (magazines _unit)) > 0 } do {
				_action = [_unit, _oldmag] call CBA_fnc_removeMagazine;
				_action = [_unit, _newmag] call CBA_fnc_addMagazine;
			};
			// FIX: Reload weapon after magazine exchange
			_currentWeapon = currentWeapon _unit;
			if (_currentMagazine == _oldmag && {_ammo != 0}) then {
				_unit removeWeapon _weapon;
				_unit addWeapon _weapon;
			};
			if (_weapon == _currentWeapon) then {
				_unit selectWeapon _weapon;
			};
		};
	};
};
