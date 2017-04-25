#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(fillgdfdialog);
PREP(keypressed);
PREP(playerspawn);

GVAR(mag_check_open) = false;

[QUOTE(ADDON), "quick_mag_check", {_this call FUNC(keypressed)}] call CBA_fnc_addKeyHandlerFromConfig;

ADDON = true;
