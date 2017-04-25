#include "script_component.hpp"

ADDON = false;

PREP(keypressed);
PREP(keypressed_sa);
PREP(fired);
PREP(hasGL);
PREP(set_el);
PREP(init);

GVAR(running) = false;
GVAR(sa_active) = false;
GVAR(presstime) = 0;

ADDON = true;

[QUOTE(ADDON), "Toggle_Elevation_Info", { _this call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Elevation_Up", { [_this, 1] call FUNC(keypressed_sa) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Elevation_Down", { [_this, 0] call FUNC(keypressed_sa) }] call CBA_fnc_addKeyHandlerFromConfig;
