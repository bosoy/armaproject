/* ace_sys_knicklicht (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

["player", [ace_sys_interaction_key_self], -9, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;
["ACE_Knicklicht_Object_Base", [ace_sys_interaction_key], -9, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;
ADDON = true;
