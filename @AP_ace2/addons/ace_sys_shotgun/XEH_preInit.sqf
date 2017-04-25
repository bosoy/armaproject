#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

["shotSpread", COMPILE_FILE(fnc_fired)] call ACE_fnc_registerSimulation;

ADDON = true;
