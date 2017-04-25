/* ace_sys_minesweeper (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

ADDON = false;

LOG(MSG_INIT);

[["ACE_APOBS_MK7MOD2","ACE_APOBS_A_crate","ACE_APOBS_B_crate","ACE_MineMarker"], [ace_sys_interaction_key], 2, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;
["player", [ace_sys_interaction_key_self], -9, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;

ADDON = true;
