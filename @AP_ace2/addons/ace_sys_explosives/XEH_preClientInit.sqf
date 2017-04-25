#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

ADDON = false;

LOG(MSG_INIT);

// Interaction Menu
[["ACE_Explosive_Object", "ACE_Explosive_Helper"], [ace_sys_interaction_key], 5, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;
["player", [ace_sys_interaction_key_self], -9, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;
["AllVehicles", [ace_sys_interaction_key], 5, [QPATHTO_F(fnc_menuDef_attach), "main"]] call CBA_ui_fnc_add;

ADDON = true;
pzn_minefield_time = diag_ticktime;