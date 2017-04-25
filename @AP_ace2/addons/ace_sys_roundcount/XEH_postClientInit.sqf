#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP(roundcount);
PREP(rcaction);

GVAR(disabled) = (!isNil QGVAR(disabled));

GVAR(KP) = ["KeyDown", "[0, _this] call ace_sys_roundcount_fnc_roundcount"] call CBA_fnc_addDisplayHandler;
[QUOTE(ADDON), "Roundcount", {[1, _this] call ace_sys_roundcount_fnc_roundcount}] call CBA_fnc_addKeyHandlerFromConfig;

ADDON = true;
