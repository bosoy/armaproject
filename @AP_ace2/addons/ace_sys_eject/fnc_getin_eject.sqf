// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfg (configfile >> "CfgVehicles" >> typeOf _vehicle >> "ACE_SYS_EJECT_EJECT")
#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")

#define ACE_TEXT_GREEN(Text) ("<t color='#00FF00'>" + ##Text + "</t>")
#define ACE_TEXT_YELLOW(Text) ("<t color='#FFFF00'>" + ##Text + "</t>")

private ["_eject"];

/* This script is executed by a GetIn event handler for any class Air vehicle. */
PARAMS_1(_vehicle);

// If the vehicle is NOT one of the air vehicles that have ejection capability OR is a parachute exit the script wthout continuing.
if (getNumber __cfg == 0) exitWith { false };

if (!isNil {_vehicle getVariable QGVAR(eject)}) exitWith {};

_engage_eject = _vehicle addAction [ACE_TEXT_GREEN(localize "STR_ACE_ENG_EJECT"),QPATHTO_F(engage_eject),[],-888100,false,false,"","(player == _this) && {player == driver _target} && {(vehicle _this == _target)} && {!(_target call CBA_fnc_locked)} && {!(player call ace_sys_wounds_fnc_isUncon)} && {!(_target getVariable ['ace_sys_eject_engaged',false])}"];
_disengage_eject = _vehicle addAction [ACE_TEXT_YELLOW(localize "STR_ACE_DISENG_EJECT"),QPATHTO_F(disengage_eject),[],-888100,false,false,"","(player == _this) && {player == driver _target} && {(vehicle _this == _target)} && {!(_target call CBA_fnc_locked)} && {!(player call ace_sys_wounds_fnc_isUncon)} && {(_target getVariable ['ace_sys_eject_engaged',false])}"];
_eject = _vehicle addAction [ACE_TEXT_RED(localize "STR_ACE_EJECT0"),QPATHTO_F(eject),[],100,false,false,"Eject","(player == _this) && {(vehicle _this == _target)} && {!(_target call CBA_fnc_locked)} && {!(player call ace_sys_wounds_fnc_isUncon)} && {(_target getVariable ['ace_sys_eject_engaged',false])}"];

// Set a variable to the vehicle to record the action ID.
_vehicle setVariable [QGVAR(eng_eject), _engage_eject];
_vehicle setVariable [QGVAR(diseng_eject), _disengage_eject];
_vehicle setVariable [QGVAR(eject), _eject];
