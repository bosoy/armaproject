#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

// Windmeter
PREP(onload);
PREP(windmeter);
GVAR(kestrel_on) = false;
GVAR(running) = false;

["player", [ace_sys_interaction_key_self], -9, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;
