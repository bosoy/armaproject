/* ace_sys_gas (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

["shotCS", COMPILE_FILE(fnc_fired)] call ACE_fnc_registerSimulation;

PREP(fired_gas);
PREP(fx_server);

[QGVAR(fired), {_this spawn FUNC(fired_gas)}] call CBA_fnc_addEventHandler;

ADDON = true;
