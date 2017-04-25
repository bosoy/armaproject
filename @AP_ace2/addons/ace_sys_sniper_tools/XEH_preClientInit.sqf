/* ace_sys_sniper_tools (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"

LOG(MSG_INIT);

ADDON = false;

PREP(place);
PREP(pickup);

["player", [ace_sys_interaction_key_self], -9, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;

ADDON = true;
