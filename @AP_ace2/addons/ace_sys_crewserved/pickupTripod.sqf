#include "script_component.hpp"

private ["_unit","_tripod","_secWep","_actor","_pickupTime"];

if ((count _this) == 2) then {
	_tripod = _this select 0;
	_unit = _this select 1;
	_actor = _unit;
} else {
	_unit = _this select 0;
	_actor = _this select 1;
	_tripod = nearestObject [_unit, 'ACE_Tripod_Base'];
};

_pickupTime = getNumber(configFile >> "CfgVehicles" >> typeOf _tripod >> "ACE" >> "ACE_CREWSERVED" >> "pickupTime");
if (_pickupTime == 0) then { _pickupTime = 8 };

if (_tripod getVariable [QGVAR(busy),false]) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};

if (_unit == _actor && !isNil "_tripod" && !(_unit getVariable [QGVAR(busy), false])) then {
	_unit setVariable [QGVAR(busy), true];
	[_tripod,true] call FUNC(setbusy);
	_tripodProxyType = getText (configfile >> "CfgVehicles" >> typeOf _tripod >> "ACE" >> "ACE_CREWSERVED" >> "tripodProxy");
	_secWep = secondaryWeapon _unit;

	// PROGRESS BAR
	_unit setVariable ["ACE_PB_Result", 0];
	[_pickupTime,[""],false,true,_unit,true] spawn ace_progressbar;
	waitUntil { (_unit getVariable "ACE_PB_Result" != 0) };
	_exit = (_unit getVariable "ACE_PB_Result" != 1);
	_unit setVariable ["ACE_PB_Result", 0];

	if (_exit) exitWith {
		_unit setVariable [QGVAR(busy), false];
		[_tripod,false] call FUNC(setbusy);
	};

	deleteVehicle _tripod; 
	// Check if backpack or launcher is carried or tripod is item class
	if ((_secWep == "" && {isNull (unitBackpack _unit)}) || {getNumber(configFile >> "CfgWeapons" >> _tripodProxyType >> "type") == 131072}) then {
		[_unit, _tripodProxyType] call CBA_fnc_addWeapon;
	} else {
		// Check free weapon on back
		if (([_unit] call ACE_fnc_WeaponOnBackName) == "") then {
			[_unit, _tripodProxyType] call CBA_fnc_addWeapon;
			[_unit, _tripodProxyType] call ACE_fnc_PutWeaponOnBack;
		} else {
			_wh = "WeaponHolder" createVehicle getpos _unit;
			_wh addWeaponCargoGlobal [_tripodProxyType,1];
			_wh setPos getPos _unit;
			_unit reveal _wh;
		};
	};
	sleep 1;
	_unit setVariable [QGVAR(busy), false];
	[_tripod,false] call FUNC(setbusy);
} else {
	(localize "STR_ACE_CREW_ERR_POS") spawn ace_fnc_visual;
};
