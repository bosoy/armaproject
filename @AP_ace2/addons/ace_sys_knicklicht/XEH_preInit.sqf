/* ace_sys_knicklicht (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

["shotKnicklicht", COMPILE_FILE(fnc_fired)] call ACE_fnc_registerSimulation;
PREP(throw_Knicklicht);
PREP(killed);
PREP(pickup);
PREP(destroy);

ADDON = true;
