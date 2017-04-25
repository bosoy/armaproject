#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP(dogtagAnsw);
PREP(dogtagAnsw2);

//PREP(spawnDogtag);
PREP(fill_itemsdialog);
PREP(lbSelChanged);

PREP(dogtag);

[QGVAR(dogtagAnsw), { _this call FUNC(dogtagAnsw2) }] call ACE_fnc_addReceiverOnlyEventhandler;

["CAManBase", [ace_sys_interaction_key], 5, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;

ADDON = true;
