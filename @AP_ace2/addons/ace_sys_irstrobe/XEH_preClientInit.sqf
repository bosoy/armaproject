/* ace_sys_irstrobe (.pbo) | (c) 2008, 2009, 2010, 2011 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

["player", [ace_sys_interaction_key_self], -9567, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;
["ACE_MS2000_STROBE_OBJECT", [ace_sys_interaction_key], -9567, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;

ADDON = true;
