#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

ADDON = false;
LOG(MSG_INIT);

GVAR(key_pid) = [] spawn {};

PREP(keypressed);
PREP(check);
PREP(bipod);
PREP(sb);
PREP(tp);

[QUOTE(ADDON), "Rest_weapon", { _this call FUNC(keyPressed)}] call CBA_fnc_addKeyHandlerFromConfig;

ADDON = true;
