//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __MG_CFG configFile >> "CfgVehicles" >> (typeOf _MG)
#define __wepType ((getArray (__MG_CFG >> "Turrets" >> "MainTurret" >> "weapons")) select 0)

private ["_MG","_unit","_percentAmmo","_correctAmmo","_magHolder","_curPercentAmmo","_canLinkAmmo","_numBulletsRemoved","_numPercentRemoved","_pos","_actor", "_busy"];

if (count _this == 1) then {
	call (_this select 0);
	_MG = ACE_MG;
	ACE_MG = nil;
	_unit = player;
	_actor = player;
} else {
	_unit  = _this select 0;
	_actor = _this select 1;
	_MG = nearestObject [_unit, 'StaticWeapon']
};
// Not player
if (_actor != _unit) exitWith {};

// Player is gunner = bad
if (gunner _MG == _unit) exitWith {
	[localize "STR_ACE_CREW_ERR_POS",[1,0,0,1],true,0] spawn ace_fnc_visual;
};

_currentAmmo = _MG ammo __wepType;
_currentMagazine = (_MG magazinesTurret [0]) select 0; // TODO: Make sure correct turretPath is used
_currentMagazineMaxAmmo = getNumber(configFile >> "CfgMagazines" >> _currentMagazine >> "count");
_magazineTypeToUnload = getText (configFile >> "CfgMagazines" >> _currentMagazine >> "ACE" >> "ACE_CREWSERVED" >> "unloadType");
_fullMagRds = getNumber (configfile >> "CfgMagazines" >> _magazineTypeToUnload >> "count");
_totalAmmo =  getNumber (__MG_CFG >> "ACE" >> "ACE_CREWSERVED" >> "max");


TRACE_6("",_currentAmmo,_currentMagazine,_magazineTypeToUnload,_currentMagazineMaxAmmo,_fullMagRds,_totalAmmo);

if (_currentAmmo == 0) exitWith {
	[localize "STR_ACE_CREW_ERR_LOWAMMO",[1,0,0,1],true,0] spawn ace_fnc_visual;
};

// Weapon / Mortar is in "Fire on Load" mode
if (_MG getVariable [QGVAR(fireReload), false]) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};

// Weapon is occupied
if (_MG getVariable QGVAR(busy)) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};
_busy = _unit getVariable [QGVAR(busy), false];
if (_busy) exitWith {};

_percentAmmo = ((_currentAmmo /_fullMagRds) * 100) min 100;

// Remove magazine if count of CSWDM equals totalammo
_magazineTypeToUnloadAmmo = getNumber (configFile >> "CfgMagazines" >> _correctAmmo >> "count");
_magazineRemoved = false;
if (_currentAmmo == _magazineTypeToUnloadAmmo) then {
	_magazineRemoved = true;
	TRACE_2("Removing magazine flag",_magazineTypeToUnloadAmmo,_currentAmmo);
};

_curPercentAmmo = (_currentAmmo / _currentMagazineMaxAmmo);
_numBulletsRemoved = (_fullMagRds * (_percentAmmo/100));

// If currently loaded magazine is bigger than the max count of the weapon, remove all of them and multiply the taken magazines
// Useful for mortar compatibility (8 round mag) etc
_amount = 1;
if (_currentAmmo > _totalAmmo) then {
	_numBulletsRemoved = _currentAmmo;
	_amount = round(_currentAmmo / _magazineTypeToUnloadAmmo);
	_magazineRemoved = true;
};
_ammoTaken = round _numBulletsRemoved;

_canLinkAmmo = (_totalAmmo == _fullMagRds);
_numPercentRemoved = _numBulletsRemoved / _currentMagazineMaxAmmo;
// what do we need link info for during unloading anyway???
// _numPercentRemoved = if !(_canLinkAmmo) then { _curPercentAmmo } else { _numBulletsRemoved / _currentMagazineMaxAmmo };

TRACE_8("", _magazineTypeToUnloadAmmo,_percentAmmo,_correctAmmo,_curPercentAmmo,_numBulletsRemoved,_canLinkAmmo,_numPercentRemoved,_currentMagazineMaxAmmo);

// PROGRESS BAR
_unit setVariable ["ACE_PB_Result", 0];
_time = getNumber(__MG_CFG >> "ACE" >> "ACE_CREWSERVED" >> "reloadtime");
[_time,[""],true,true, _unit] spawn ace_progressbar;
waitUntil { (_unit getVariable "ACE_PB_Result" != 0) };
_exit = (_unit getVariable "ACE_PB_Result" != 1);
_unit setVariable ["ACE_PB_Result", 0];

if (_exit) exitWith {};

[_MG,true] call FUNC(setbusy);
_unit setVariable [QGVAR(busy), true];

// New: use ACE_fnc_addMagazineCargoEx!
for "_i" from 1 to _amount do {
	[_MG,_magazineTypeToUnload,_currentAmmo,true] call ACE_fnc_addMagazineCargoEx;
};

if (_magazineRemoved) then {
	[QGVAR(rem), [_MG, _currentMagazine]] call CBA_fnc_globalEvent;
} else {
	[QGVAR(sva), [_MG, (_curPercentAmmo - _numPercentRemoved)]] call CBA_fnc_globalEvent;
};

_msg = format [localize "STR_ACE_CREW_DELINK",_ammoTaken,_currentAmmo - _ammoTaken];
if (local _unit) then { _msg spawn ace_fnc_visual; };
_unit setVariable [QGVAR(busy), false];
[_MG,false] call FUNC(setbusy);
