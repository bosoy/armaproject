#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

ADDON = false;

LOG(MSG_INIT);

ISNIL(debugjam,false);

PREP(getin);
PREP(getout);

PREP(fired);
PREP(fired_static);

PREP(weaponArrays);

PREP(stoppage);
PREP(unjam);
PREP(swap);

PREP(keypressed);

FUNC(init) = {
	GVAR(cur) = ["", 0, 0, 0, false]; 	//[current weapon, temperature,cooling factor]
	GVAR(prev) = ["", 0, 0, 0, false]; 	//[previously used weapon, temperature,cooling factor]
	GVAR(cur1) = ["", 0, 0, 0, false]; 	//[current weapon, temperature,cooling factor]
	GVAR(prev1) = ["", 0, 0, 0, false]; 	//[previously used weapon, temperature,cooling factor]
	GVAR(unjamming) = false;
};

FUNC(respawn) = {
	PARAMS_1(_unit);
	_unit setVariable [QGVAR(lastShotTime), 0];
	call FUNC(init);
};

call FUNC(init);

#ifdef DEBUG_MODE_FULL
	//GVAR(debugjam) = true;
#endif

[QUOTE(ADDON), "Unjam", { _this call FUNC(keyPressed)}] call CBA_fnc_addKeyHandlerFromConfig;

["player", [ace_sys_interaction_key_self], 9, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add; // high priority

ADDON = true;
