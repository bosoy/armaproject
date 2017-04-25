#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(keypressed);
PREP(newWeap);
PREP(setDegrees);
PREP(fired);

ACE_SYS_SA_AT = ACE_SYS_SA_NEW;

[QUOTE(ADDON), "Elevation_Up", { [_this, 0] call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Elevation_Down", { [_this, 1] call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;

ADDON = true;
