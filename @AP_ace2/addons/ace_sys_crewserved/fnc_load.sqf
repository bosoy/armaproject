//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __MG_CFG configFile >> "CfgVehicles" >> (typeOf _MG)
#define __dummyMags (getArray (__MG_CFG >> "ACE" >> "ACE_CREWSERVED" >> "magazines"))

private ["_MG","_unit","_actor","_curMag","_usedMag","_canLinkAmmo","_busy"];

// Is this called from the MG interaction dialog...
if (count _this ==1) then {	// is 1 since we pass command
	call (_this select 0);

	_MG = ACE_MG; // Object passed from its UserAction.  Destroy global variable once assigned locally.
	ACE_MG = nil;
	_unit=player;
	_actor=player;
} else {
	_unit  = _this select 0;
	_actor = _this select 1;
	_MG	= nearestObject[_unit,'StaticWeapon'];
};
if ( _actor != _unit) exitWith {};

if (isNil "_MG") exitWith {
	[localize "STR_ACE_CREW_ERR_NOWEP",[1,0,0,1],true,0] spawn ace_fnc_visual;
};

if (_MG getVariable QGVAR(busy)) exitWith { closeDialog 0 };

_weapon = getArray (__MG_CFG >> "Turrets" >> "MainTurret" >> "weapons") select 0;

// Check if player has a compatible magazine for _MG and is allowed add ammo.
// If not then exit
// Ff yes then record the first magazine found.
// TODO : Add selection dialog to choose what CSWDM we want to load

_curMag = -1;
{
	if (_x in __dummyMags) exitWith {
		_curMag = __dummyMags find _x; diag_log _curMag;
	};
} forEach magazines _unit;

// Not correct ammo found
if (_curMag == -1 || isNil "_curMag") exitWith {
	[localize "STR_ACE_CREW_ERR_NOAMMO",[1,0,0,1],true,0] spawn ace_fnc_visual;
};

// CURRENTLY USED CSWDM
// Magazine type
_usedMag = __dummyMags select _curMag;// ALL possible CSWDM must be added
_magTypeToLoad = getText (configfile >> "CfgMagazines" >> _usedMag >> "ACE" >> "ACE_CREWSERVED" >> "loadType");
//diag_log format ["%1 in (magazines player): %2", _usedMag, (_usedMag in (magazines player))];

// Rounds in to add to current ammo
//_ammoToAdd = getNumber (configfile >> "CfgMagazines" >> _usedMag >> "count");
//_ammoToAdd = _usedMag call FUNC(countBullets); diag_log _ammoToAdd;

_dummy = createAgent ["ACE_CivDummy", [10,10,0], [], 0, "FORM"];
waitUntil { alive _dummy };

_dummy disableAI "TARGET";
_dummy disableAI "AUTOTARGET";
_dummy disableAI "MOVE";
_dummy disableAI "ANIM";
removeAllWeapons _dummy;
removeAllItems _dummy;
player reveal _dummy;

_unit action ["DropMagazine",_dummy,_usedMag]; 
_dummy addWeapon "ACE_BulletCounter";
_dummy selectWeapon "ACE_BulletCounter";
waitUntil { _dummy hasWeapon "ACE_BulletCounter" && {_usedMag in (magazines _dummy)} && {someAmmo _dummy} };
reload _dummy;
sleep 1;

//diag_log format ["%1 in (magazines _dummy): %2", _usedMag, (_usedMag in (magazines _dummy))];

_ammoToAdd = _dummy ammo (primaryWeapon _dummy);
if (_ammoToAdd == 0) then { // acount 3rd party addons TODO: Make defineable _Bulletcounter_ weapon for custom CSWs
	_ammoToAdd = getNumber (configfile >> "CfgMagazines" >> _usedMag >> "count");
};


// Current ammo of the weapon
_currentAmmo = (_MG ammo _weapon);

TRACE_4("",_usedMag,_magTypeToLoad,_ammoToAdd,_currentAmmo);

// Check if ammo can be linked to an existing belt
#define __canLink ((getArray (__MG_CFG >> "ACE" >> "ACE_CREWSERVED" >> "links")) select 1)
#define __beltLength ((getArray (configFile >> "CfgVehicles" >> (typeOf _MG) >> "ACE" >> "ACE_CREWSERVED" >> "links")) select 0)
_canLinkAmmo = (__canLink == 1 && _currentAmmo <= __beltLength);

// Belt cannot be linked && Weapon is not empty -> Ammo must be removed
if (_currentAmmo > 0 && !_canLinkAmmo) exitWith {
	[localize "STR_ACE_CREW_ERR_REMOVE",[1,0,0,1],true,0] spawn ace_fnc_visual;
	// Drop magazine back to player
	_dummy action ["DropMagazine",_unit,_usedMag]; 	
};

// Belt would become too long
if (_currentAmmo > _ammoToAdd) exitWith {
	[localize "STR_ACE_CREW_ERR_BELT",[1,0,0,1],true,0] spawn ace_fnc_visual;
	// Drop magazine back to player
	_dummy action ["DropMagazine",_unit,_usedMag]; 	
};

// Player is gunner in the Weapon
_gunnerCanReload = getNumber(configFile >> "CfgVehicles" >> typeOf _MG >> "ACE" >> "ACE_CREWSERVED" >> "gunnerCanReload");
if (_gunnerCanReload == 0 && {(gunner _MG == _unit)}) exitWith {
	[localize "STR_ACE_CREW_ERR_POS",[1,0,0,1],true,0] spawn ace_fnc_visual;
};

_busy = _unit getVariable [QGVAR(busy), false];
if (_busy) exitWith {};

_totalAmmo = getNumber (configFile >> "CfgVehicles" >> typeOf _MG >> "ACE" >> "ACE_CREWSERVED" >> "max"); // Total rnds the weapon can hold

// If there is at least 5 rounds loaded in _MG then link a new belt.
private "_msg";
if (_currentAmmo >= 5 ) then {
	_msg = localize "STR_ACE_CREW_LINK";
} else {
	// If there are fewer than 5 rounds loaded in _MG then load a new belt.
	_currentAmmo = 0;
	_msg = localize "STR_CFG_CUTSCENES_REARM";
};

// PROGRESS BAR
_unit setVariable ["ACE_PB_Result", 0];
_rtime = getNumber(__MG_CFG >> "ACE" >> "ACE_CREWSERVED" >> "reloadtime");
_time = if (_canLinkAmmo) then { _rtime*1.5 } else { _rtime };
[_time,[""],false,true,_unit,true] spawn ace_progressbar;
waitUntil { (_unit getVariable "ACE_PB_Result" != 0) };
_exit = (_unit getVariable "ACE_PB_Result" != 1);
_unit setVariable ["ACE_PB_Result", 0];

if (_exit) then {
	// Drop magazine back to player
	_dummy action ["DropMagazine",_unit,_usedMag]; 
};
if (_exit) exitWith {};

[_MG,true] call FUNC(setbusy);
_unit setVariable [QGVAR(busy), true];

_loadAmmo = (_ammoToAdd + _currentAmmo)/_totalAmmo;
//_unit removeMagazine _usedMag;

// TODO: What if the gunner already emptied the gun in the meantime etc?
_magazines = _MG magazinesTurret [0];
_currentMagazine = if (count _magazines > 0) then { _magazines select 0 } else { "" }; // TODO: Make sure correct turretPath is used

// Some kind of bug currently, so using remadd always, until fixed.
//if (_currentMagazine != _magTypeToLoad || count _magazines > 1) then {
	TRACE_3("Removing Magazines, and adding correct magazine",_currentMagazine,_magTypeToLoad,_magazines);
	[QGVAR(remadd), [_MG, _magTypeToLoad, _loadAmmo]] call CBA_fnc_globalEvent;
	_currentMagazine = _magTypeToLoad;
//} else {
//	[QGVAR(sva), [_MG, _loadAmmo]] call CBA_fnc_globalEvent;
//};

TRACE_3("",_currentMagazine,_totalAmmo,_loadAmmo);

_unit setVariable [QGVAR(busy), false];
[_MG,false] call FUNC(setbusy);
deleteVehicle _dummy;
