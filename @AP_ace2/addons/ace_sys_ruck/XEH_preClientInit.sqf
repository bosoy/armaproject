#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(QuickCheck);
PREP(DragRuck);

["CAManBase", [ace_sys_interaction_key], 4, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;

[QUOTE(ADDON), "quick_ruck_check", {_this call FUNC(QuickCheck)}] call CBA_fnc_addKeyHandlerFromConfig;

[QUOTE(ADDON), "drag_nearest_ruck", {_this call FUNC(DragRuck)}] call CBA_fnc_addKeyHandlerFromConfig;

ADDON = true;
