#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

[QGVAR(adda), {_this call FUNC(paddaction)}] call CBA_fnc_addEventHandler;
[QGVAR(rma), {_this call FUNC(premoveaction)}] call CBA_fnc_addEventHandler;

[["Helicopter"], [ace_sys_interaction_key], 2, [QPATHTO_F(fnc_fastroping_menuDef), "main"]] call CBA_ui_fnc_add;

ADDON = true;
