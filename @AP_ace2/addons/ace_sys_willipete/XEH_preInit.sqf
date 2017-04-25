/* ace_sys_willipete (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

["shotWP", COMPILE_FILE(fnc_fired)] call ACE_fnc_registerSimulation;

// Use sys_gas scripts
[QGVAR(fired), {_this spawn ace_sys_gas_fnc_fired_gas}] call CBA_fnc_addEventHandler;

ADDON = true;
