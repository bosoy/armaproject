/* ace_sys_disposal | 2009 by zGuba & Inkompetent*/

#include "script_component.hpp"

#define __config configFile >> "CfgWeapons" >> _weapon

private ["_usedWeapon", "_tubeModel", "_usedWeaponMagazines", "_usedMagazine", "_weaponDirection"];

PARAMS_2(_unit,_weapon);

_usedWeapon = getText (__config >> "ace_disposable_used");
_tubeModel = getText (__config >> "ace_disposable_model");

_usedWeaponMagazines = getArray (configFile >> "CfgWeapons" >> _usedWeapon >> "magazines");
_usedMagazine = nil;

if (count _usedWeaponMagazines > 0) then {
	_usedMagazine = _usedWeaponMagazines select 0;
	_unit addMagazine _usedMagazine;
	_unit addWeapon _usedWeapon;
	_unit removeWeapon _weapon;
	_unit selectWeapon _usedWeapon;
	TRACE_1("usedWeaponMagazines > 0",_usedMagazine);
};

if (_unit == player) then {
	// Waituntil the player drops the tube
	sleep 0.3;

	ACE_WOB_DISPB = false;
	_dummyar = [toUpper _usedWeapon, toUpper _weapon];
	while {(toUpper (currentWeapon _unit) in _dummyar) && !ACE_WOB_DISPB && alive _unit} do {
		TRACE_1("Player still holding launcher","");
		sleep 0.3;
	};

	TRACE_2("Drop weapon manually",(toUpper(_usedWeapon)),(weapons _unit));
} else {
	// Sleep 0.5 seconds until AI Drops the tube
	sleep 0.5;	// New anims cause AI to hurt itself
};

if (_usedWeapon in (weapons _unit)) then {
	// Replace tube
	[QGVAR(net), [_unit, _tubeModel]] call CBA_fnc_remoteEvent;

	if !(isDedicated) then {
		[_unit, _tubeModel, _unit weaponDirection _usedWeapon] call FUNC(throw); // Eye-candy on local machine
	};

	if (_usedWeapon in weapons _unit) then { _unit removeWeapon _usedWeapon };
	if (_usedMagazine in magazines _unit) then { _unit removeMagazines _usedMagazine };

	if !(isPlayer _unit) then {
		_unit doTarget objNull;
		_primary = primaryWeapon _unit;

		if (_primary != "") then {
			_unit selectWeapon _primary;
			_unit selectWeapon ((getArray (configFile >> "cfgWeapons" >> _primary >> "muzzles")) select 0);
		};
	};
};
