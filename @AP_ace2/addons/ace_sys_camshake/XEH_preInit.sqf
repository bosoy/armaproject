#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(firednear);
PREP(fired_veh);

PREP(fired);
PREP(replace);
PREP(track);
PREP(trigger);

[QGVAR(trigger), {_this call FUNC(trigger)}] call CBA_fnc_addEventhandler;

ADDON = true;
