/* ace_sys_irstrobe (.pbo) | (c) 2008, 2009 by rocko */
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_unit", "_irStrobe", "_type", "_pos", "_irStrobe_Obj"];

_unit = _this select 0;
_irstrobe = _this select 6;

_type = getText(configFile >> "CfgAmmo" >> (_this select 4) >> "ACE_IRObject");

_pos = getPosASL _irstrobe;
TRACE_4("",_unit,_irstrobe,_type,_pos);

#define __vel ((velocity _irstrobe) call ACE_fnc_magnitude)
while { alive _irstrobe && !isNull _irstrobe } do {
	_pos = getPosASL _irstrobe;
	if (__vel < 0.2) exitWith {};
	sleep 0.1;
};
deleteVehicle _irstrobe;

// Create IR Strobe object
_irstrobe_obj = _type createVehicle _pos;
_irstrobe_obj setPosASL _pos;

TRACE_1("",_irStrobe_Obj);

[QGVAR(aradd), [_irstrobe_obj]] call CBA_fnc_globalEvent;

_irstrobe_obj setVariable [QGVAR(ison),true,true]; // Store status, Safety on

// TODO: Use BIS style for thrown IR strobes
// BIS Style: Is not possible. BIS ammo with NVG markers is not reuseable.
// BIS Style: Vehicle NVG markers are only visible with NV when the lights are on.

// TODO: Introduce battery lifetime and destroy IR Strobe after given time.
