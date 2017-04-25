/* ace_sys_cartridges (.pbo) | (c) 2008, 2009, 2010 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(fired);

GVAR(enabled) = ([QUOTE(PREFIX), QUOTE(COMPONENT), "enabled"] call ace_settings_fnc_getNumber) == 1;

ADDON = true;
