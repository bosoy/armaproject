/* ace_sys_backblast (.pbo) | (c) 2008, 2009, 2010 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(backblast);

["shotBackblast", COMPILE_FILE(fnc_fired), true] call ACE_fnc_registerSimulation; // _global simulation; no need for globalEvent

ADDON = true;
