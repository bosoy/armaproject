#include "script_component.hpp"

LOG(MSG_INIT);

GVAR(units) = [];

PREP(spawnBlood);
PREP(spurt);
PREP(bleeding);

[QGVAR(spurt), { _this call FUNC(spurt) }] call CBA_fnc_addEventHandler;
[QGVAR(bleeding), { _this call FUNC(bleeding) }] call CBA_fnc_addEventHandler;
