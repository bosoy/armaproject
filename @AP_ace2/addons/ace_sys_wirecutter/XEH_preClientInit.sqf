/* ace_sys_wirecutter | (c) 2010 by Xeno */

#include "script_component.hpp"

ADDON = false;

["player", [ace_sys_interaction_key_self], -9, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;

ADDON = true;
