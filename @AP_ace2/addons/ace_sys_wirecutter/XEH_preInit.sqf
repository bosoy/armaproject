/* ace_sys_wirecutter | (c) 2010 by Xeno */

#include "script_component.hpp"

ADDON = false;

PREP(cut);
PREP(fencestr);
PREP(fencenet);

[QGVAR(cut), { _this call FUNC(fencenet) }] call CBA_fnc_addEventHandler;

ADDON = true;
