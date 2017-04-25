#include "script_component.hpp"

ADDON = false;

[["Car", "Air", "Wheeled_APC", "Tank", "ACE_Spare_Tyre", "ACE_JerryCan"], [ace_sys_interaction_key], 2, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;

["Truck", [ace_sys_interaction_key], 2, [QPATHTO_F(fnc_menuDef_support), "main"]] call CBA_ui_fnc_add;

ADDON = true;
