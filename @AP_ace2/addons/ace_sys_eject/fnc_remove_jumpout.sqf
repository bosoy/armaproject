#include "script_component.hpp"
// ace_remove_jumpout.sqf
// OBSOLETE IN A2
private ["_vehicle"];
/* This script is executed by a GetOut event handler for any class Air, LandVehicle or Ship vehicle. */

// Argument(s) passed from the GetOut event handler. 0 = the vehicle the event handler is assigned to.
PARAMS_1(_vehicle);

// If the vehicle is one of the air vehicles that have ejection capability or is a parachute exit the script wthout continuing.
#define __cfg (configfile >> "CfgVehicles" >> typeOf _vehicle >> "ACE_SYS_EJECT_JUMP")
if (getNumber __cfg == 0) exitWith { false };

// Get the "Jump Out" action ID for this vehicle and use it to remove the option.
#define __id (_vehicle getVariable QGVAR(jumpOut))
_vehicle removeAction __id;
_vehicle setVariable [QGVAR(jumpEnabled),false,false];
