// #define DEBUG_MODE_FULL
#include "script_component.hpp"

LOG(MSG_INIT);
ADDON = false;

[] spawn COMPILE_FILE(outdated);

ADDON = true;
