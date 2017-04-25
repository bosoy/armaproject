#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(fired);
PREP(cam);
PREP(keypressed);

GVAR(NV) = 0;
GVAR(IRON) = false;

["player", [ace_sys_interaction_key_self], -9, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;

ADDON = true;
