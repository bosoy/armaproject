#include "script_component.hpp"
// ace_remove_eject.sqf
// OBSOLETE IN A2
private ["_vehicle"];

/* This script is executed by a GetOut event handler for any class Air vehicle. */

// Argument(s) passed from the GetOut event handler. 0 = the vehicle the event handler is assigned to.
PARAMS_1(_vehicle);

// If the vehicle is NOT one of the air vehicles that have ejection capability or is a parachute exit the script wthout continuing.
#define __cfg (configfile >> "CfgVehicles" >> typeOf _vehicle >> "ACE_SYS_EJECT_EJECT")
if (getNumber __cfg == 0) exitWith { false };

// Get the "Eject" action ID for this vehicle and use it to remove the option.
#define __id (_vehicle getVariable QGVAR(eject))
#define __id2 (_vehicle getVariable QGVAR(diseng_eject))
#define __id3 (_vehicle getVariable QGVAR(eng_eject))
_vehicle removeAction __id;
_vehicle removeAction __id2;
_vehicle removeAction __id3;
_vehicle setVariable [QGVAR(ejectEnabled),false,false];
