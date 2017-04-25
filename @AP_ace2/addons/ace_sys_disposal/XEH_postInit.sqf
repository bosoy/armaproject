/* ace_sys_disposal (.pbo) | 2009 by zGuba and Inkompetent */

#include "script_component.hpp"

ADDON = false;

if (!isDedicated) then {
	0 spawn FUNC(trackplayer);
};

0 spawn FUNC(trackai);

ADDON = true;
