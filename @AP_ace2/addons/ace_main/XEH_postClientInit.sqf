#include "script_component.hpp"

LOG(MSG_INIT);

ADDON = false;

// TODO: Update the variable / read realtime instead
GVAR(dismount_enabled) = (["ACE", "sys_immersive_dismount", "enabled"] call ace_settings_fnc_getNumber) == 1;

#include "ace_sys_ladebalken_post.sqf"

[["ATV_Base_EP1"], [ace_sys_interaction_key], 2, [QPATHTO_F(fnc_menuDef_ATV), "main"]] call CBA_ui_fnc_add;


ADDON = true;
