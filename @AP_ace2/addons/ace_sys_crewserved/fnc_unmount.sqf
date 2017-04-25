//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __TYPE typeOf _MG
#define __MG_CFG configFile >> "CfgVehicles" >> (__TYPE)

private ["_MG","_unit", "_MGProxyType","_tripodType","_tripod","_amountOfFullMagazines","_secWep","_wepType","_maxBCofNewMagazine","_magazine","_pos","_actor"];

if (count _this == 1) then {
	call (_this select 0);
	_MG	= ACE_MG;
	ACE_MG = nil;
	_unit  = player;
	_actor = player;
} else {
	_unit  = _this select 0;
	_actor = _this select 1;
	_MG = nearestObject [_unit, "StaticWeapon"];
};
if (_actor != _unit) exitWith {};
if (getText(configFile >> "CfgVehicles" >> __TYPE >> "ACE" >> "ACE_CREWSERVED" >> "interaction") == "Tripod") exitWith {
	[_MG,player] spawn COMPILE_FILE(pickupTripod);
};

_MGProxyType = getText (configfile >> "CfgVehicles" >> __TYPE >> "ACE" >> "ACE_CREWSERVED" >> "weaponProxy");
_tripodType = getText (configfile >> "CfgVehicles" >> __TYPE >> "ACE" >> "ACE_CREWSERVED" >> "tripod");
_wepType = (getArray (configfile >> "CfgVehicles" >> __TYPE >> "Turrets" >> "MainTurret" >> "weapons")) select 0;

if (count crew _MG > 0) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
};
if (_MG getVariable QGVAR(busy)) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};
_currentBC = _MG ammo _wepType;
_currentMagazine = (_MG magazinesTurret [0]) select 0; // TODO: Make sure correct turretPath is used
_magazineTypeToUnload = getText (configFile >> "CfgMagazines" >> _currentMagazine >> "ACE" >> "ACE_CREWSERVED" >> "unloadType");
_maxBCofNewMagazine = getNumber (configfile >> "CfgMagazines" >> _magazineTypeToUnload >> "count");

TRACE_4("",_currentBC,_currentMagazine,_magazineTypeToUnload,_maxBCofNewMagazine);

_busy = _unit getVariable [QGVAR(busy), false];

if (!_busy) then {
	[_MG,true] call FUNC(setbusy);

	// PROGRESS BAR
	_unit setVariable ["ACE_PB_Result", 0];
	_time = if (_currentBC == 0) then { getNumber(__MG_CFG >> "ACE" >> "ACE_CREWSERVED" >> "mountTime") } else { (getNumber(__MG_CFG >> "ACE" >> "ACE_CREWSERVED" >> "mountTime"))*1.5 }; // More time for unmounting if weapon has ammo that needs to be removed first.
	[_time,[localize "STR_ACE_CREW_UNMOUNT"],false,true,_unit,true] spawn ace_progressbar;
	waitUntil { _unit getVariable "ACE_PB_Result" != 0 };
	_exit = _unit getVariable "ACE_PB_Result" != 1;
	_unit setVariable ["ACE_PB_Result", 0];

	if (_exit) exitWith {
		[_MG,false] call FUNC(setbusy);
	};
	_pos = getPosATL _MG;
	_dir = getDir _MG;

	_priWep = primaryWeapon _unit;
	_secWep = secondaryWeapon _unit;
	_type = getNumber (configFile >> "CfgWeapons" >> _MGProxyType >> "type");

	switch (_type) do { // Check if backpack or launcher is carried if MGProxy is launchertype
		case 4: {
			if ((_secWep == "") && {(isNull (unitBackpack _unit))}) then {
				[_unit, _MGProxyType] call CBA_fnc_addWeapon;
			} else {
				if (([_unit] call ACE_fnc_WeaponOnBackName) == "") then { // Check free weapon on back
					[_unit, _MGProxyType] call CBA_fnc_addWeapon;
					[_unit, _MGProxyType] call ACE_fnc_PutWeaponOnBack;
				} else {
					_wh = "WeaponHolder" createVehicle getpos _unit;
					_wh setPosATL [(_pos select 0)+0.3, (_pos select 1)+0.3, _pos select 2];
					_wh addWeaponCargoGlobal [_MGProxyType,1];
				};
			};
		};
		default {
			if (_priWep == "") then {
				[_unit, _MGProxyType] call CBA_fnc_addWeapon;
			} else {
				if (([_unit] call ACE_fnc_WeaponOnBackName) == "") then { // Check free weapon on back
					[_unit, _MGProxyType] call CBA_fnc_addWeapon;
					[_unit, _MGProxyType] call ACE_fnc_PutWeaponOnBack;
				} else {
					_wh = "WeaponHolder" createVehicle getpos _unit;
					_wh setPosATL [(_pos select 0)+0.3, (_pos select 1)+0.3, _pos select 2];;
					_wh addWeaponCargoGlobal [_MGProxyType,1];
				};
			};
		};
	};

	if (_tripodType == "Logic") then {
		_tripod = _tripodType createVehicleLocal [0,0,0];
	} else {
		_tripod = _tripodType createVehicle [0,0,0];
	};
	deleteVehicle _MG;
	_pos set [2,0];
	_tripod setDir _dir;
	_tripod setPosATL _pos;
	_unit reveal _tripod;
	if (_maxBCofNewMagazine > 0) then {
		_amountOfFullMagazines = floor(_currentBC / _maxBCofNewMagazine); TRACE_1("",_amountOfFullMagazines);
		for "_b" from 1 to _amountOfFullMagazines do {
			_magazine = format ["%1",_magazineTypeToUnload]; TRACE_1("",_magazine);
			_mh = "WeaponHolder" createVehicle [0,0,0];
			_mh addMagazineCargoGlobal [_magazine, 1];
			_mh setPos _pos;
			sleep 1;
		};
		if (_amountOfFullMagazines > 0) then {
			_currentBC = _currentBC - (_maxBCofNewMagazine * _amountOfFullMagazines); TRACE_1("",_currentBC);
		};
		if (_currentBC > 0) then {
			[_tripod,_magazineTypeToUnload,_currentBC,true] call ACE_fnc_addMagazineCargoEx;
			sleep 1;
		};
		_holders = nearestObjects [_tripod, ["WeaponHolder"] ,2];
		{_unit reveal _x} forEach _holders;
	};

	sleep 1;
	_unit setVariable [QGVAR(busy), false];
};
