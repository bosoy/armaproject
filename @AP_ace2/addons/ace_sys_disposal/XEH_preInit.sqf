/* ace_sys_disposal (.pbo) | 2009 by zGuba and Inkompetent */

#include "script_component.hpp"

ADDON = false;

PREP(fired);
PREP(trackai);
PREP(partcheck);
PREP(launcher_prone);

if (!isDedicated) then {
	PREP(throw);
	[QGVAR(net), { if (!local (_this select 0)) then {_this call FUNC(throw)} }] call CBA_fnc_addEventHandler;

	PREP(trackplayer);
};

ADDON = true;
