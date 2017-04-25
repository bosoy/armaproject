#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

ADDON = false;

0 spawn {
	sleep 5;
	if (isNil "ACE_CSWFORAI") then { ACE_CSWFORAI = false; };
	if (ACE_CSWFORAI) then {
		if (!isDedicated) then {
			GVAR(actionmon) = [] spawn COMPILE_FILE(actionmon);
		};
	};
};
if(!isDedicated) then {
	[FUNC(dragonMonitorInventory), 0.25] call CBA_fnc_addPerFramehandler;
};
if !(isDedicated) then { [["AllVehicles"], [ace_sys_interaction_key], 2, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add };
ADDON = true;
