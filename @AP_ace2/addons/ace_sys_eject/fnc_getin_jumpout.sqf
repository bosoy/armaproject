//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define ACE_TEXT_ORANGE(Text) ("<t color='#ffa500'>" + ##Text + "</t>")

private ["_jumpOut"];

/* This script is executed by a GetIn event handler for any class Air, LandVehicle, or Ship vehicle. */

PARAMS_1(_vehicle);

_vehicle spawn FUNC(weaponcheck);

// If  vehicle is an class Air vehicle with ejection capability OR is a parachute or static weapon then exit the script wthout continuing.
#define __cfg (configfile >> "CfgVehicles" >> typeOf _vehicle >> "ACE_SYS_EJECT_JUMP")
#define __bla (configfile >> "CfgVehicles" >> typeOf _vehicle >> "ace_sys_eject_side")
if (getNumber __cfg == 0) exitWith { false };

_prio = getNumber(configFile >> "CfgActions" >> "Eject" >> "priority");

if (_vehicle isKindOf "Helicopter") then {
	if (getNumber __bla == 1) then {
		// Cargo Visible
		if (isNil {_vehicle getVariable QGVAR(jumpOutL)}) then {
			_jumpOutL = _vehicle addAction [ACE_TEXT_ORANGE(localize "STR_ACE_EJECT1L"),QPATHTO_F(jumpout),"left",_prio,false,false,"Eject","(player == _this) && {((assignedVehicleRole player) select 0 in ['Cargo'])} && {(vehicle _this == _target)} && {!(_target call CBA_fnc_locked)} && {((_target getVariable 'ACE_RopeInUse') != 1)} && {!(player call ace_sys_wounds_fnc_isUncon)}"];
			_vehicle setVariable [QGVAR(jumpOutL), _jumpOutL];
		};
		if (isNil {_vehicle getVariable QGVAR(jumpOutR)}) then {
			_jumpOutR = _vehicle addAction [ACE_TEXT_ORANGE(localize "STR_ACE_EJECT1R"),QPATHTO_F(jumpout),"right",_prio,false,false,"Eject","(player == _this) && {((assignedVehicleRole player) select 0 in ['Cargo'])} && {(vehicle _this == _target)} && {!(_target call CBA_fnc_locked)} && {((_target getVariable 'ACE_RopeInUse') != 1)} && {!(player call ace_sys_wounds_fnc_isUncon)}"];
			_vehicle setVariable [QGVAR(jumpOutR), _jumpOutR];
		};
		// Pilot & Gunner Visible
		if (isNil {_vehicle getVariable QGVAR(jumpOut)}) then {
			_jumpOut = _vehicle addAction [ACE_TEXT_ORANGE(localize "STR_ACE_EJECT1"),QPATHTO_F(jumpout),"default",_prio,false,false,"Eject","(player == _this) && {!((assignedVehicleRole player) select 0 in ['Cargo'])}  && {(vehicle _this == _target)} && {!(_target call CBA_fnc_locked)} && {!(player call ace_sys_wounds_fnc_isUncon)}"];
			_vehicle setVariable [QGVAR(jumpOut), _jumpOut];
		};
	} else {
		if (isNil {_vehicle getVariable QGVAR(jumpOutLR)}) then {
			_jumpOutLR = _vehicle addAction [ACE_TEXT_ORANGE(localize "STR_ACE_EJECT1"),QPATHTO_F(jumpout),"default",_prio,false,false,"Eject","(player == _this) && {((assignedVehicleRole player) select 0 in ['Cargo'])} && {(vehicle _this == _target)} && {!(_target call CBA_fnc_locked)} && {((_target getVariable 'ACE_RopeInUse') != 1)} && {!(player call ace_sys_wounds_fnc_isUncon)}"];
			_vehicle setVariable [QGVAR(jumpOutLR), _jumpOutLR];
		};
		if (isNil {_vehicle getVariable QGVAR(jumpOut)}) then {
			_jumpOut = _vehicle addAction [ACE_TEXT_ORANGE(localize "STR_ACE_EJECT1"),QPATHTO_F(jumpout),"default",_prio,false,false,"Eject","(player == _this) && {!((assignedVehicleRole player) select 0 in ['Cargo'])}  && {(vehicle _this == _target)} && {!(_target call CBA_fnc_locked)} && {!(player call ace_sys_wounds_fnc_isUncon)}"];
			_vehicle setVariable [QGVAR(jumpOut), _jumpOut];
		};
	};
	// Pilot & Gunner Visible
	//_jumpOut = _vehicle addAction [ACE_TEXT_ORANGE(localize "STR_ACE_EJECT1"),QPATHTO_F(jumpout),"default",_prio,false,false,"Eject","(player == _this) && !((assignedVehicleRole player) select 0 in ['Cargo'])  && (vehicle _this == _target) && !(_target call CBA_fnc_locked) && !(player getVariable ['ace_sys_wounds_uncon',false])"];
} else {
	if (getNumber __bla == 1) then {	// what if ground vehicle could use it? Not many such vehicles around, but it can become useful for modders. Example: Polish BRDM-2 M96/M97
		// Cargo Visible
		if (isNil {_vehicle getVariable QGVAR(jumpOutL)}) then {
			_jumpOutL = _vehicle addAction [ACE_TEXT_ORANGE(localize "STR_ACE_EJECT1L"),QPATHTO_F(jumpout),"left",_prio,false,false,"Eject","(player == _this) && {((assignedVehicleRole player) select 0 in ['Cargo'])} && {(vehicle _this == _target)} && {!(_target call CBA_fnc_locked)} && {((_target getVariable ['ACE_RopeInUse', 0]) != 1)} && {!(player call ace_sys_wounds_fnc_isUncon)}"];
			_vehicle setVariable [QGVAR(jumpOutL), _jumpOutL];
		};
		if (isNil {_vehicle getVariable QGVAR(jumpOutR)}) then {
			_jumpOutR = _vehicle addAction [ACE_TEXT_ORANGE(localize "STR_ACE_EJECT1R"),QPATHTO_F(jumpout),"right",_prio,false,false,"Eject","(player == _this) && {((assignedVehicleRole player) select 0 in ['Cargo'])} && {(vehicle _this == _target)} && {!(_target call CBA_fnc_locked)} && {((_target getVariable ['ACE_RopeInUse', 0]) != 1)} && {!(player call ace_sys_wounds_fnc_isUncon)}"];
			_vehicle setVariable [QGVAR(jumpOutR), _jumpOutR];
		};
		// Pilot & Gunner Visible
		if (isNil {_vehicle getVariable QGVAR(jumpOut)}) then {
			_jumpOut = _vehicle addAction [ACE_TEXT_ORANGE(localize "STR_ACE_EJECT1"),QPATHTO_F(jumpout),"default",_prio,false,false,"Eject","(player == _this) && {!((assignedVehicleRole player) select 0 in ['Cargo'])}  && {(vehicle _this == _target)} && {!(_target call CBA_fnc_locked)} && {!(player call ace_sys_wounds_fnc_isUncon)}"];
			_vehicle setVariable [QGVAR(jumpOut), _jumpOut];
		};
	} else {
		// Default Visible
		if (isNil {_vehicle getVariable QGVAR(jumpOut)}) then {
			_jumpOut = _vehicle addAction [ACE_TEXT_ORANGE(localize "STR_ACE_EJECT1"),QPATHTO_F(jumpout),"default",_prio,false,false,"Eject","(player == _this) && {(vehicle _this == _target)} && {!(_target call CBA_fnc_locked)} && {!(player call ace_sys_wounds_fnc_isUncon)}"];
			_vehicle setVariable [QGVAR(jumpOut), _jumpOut];
		};
	};
};
