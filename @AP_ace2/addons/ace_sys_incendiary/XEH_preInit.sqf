/* ace_sys_incendiary(.pbo) | (c) 2008, 2009, 2010 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

["shotIncendiary", COMPILE_FILE(fnc_fired)] call ACE_fnc_registerSimulation;

PREP(fired_incen);

[QGVAR(fired), {_this spawn FUNC(fired_incen)}] call CBA_fnc_addEventHandler;

ADDON = true;
