#include "script_component.hpp"

ADDON = _this;

LOG(MSG_INIT);

// TODO: Lame
[] spawn {
	waitUntil { SLX_XEH_MACHINE select 5 };
	if !(SLX_XEH_MACHINE select 0) exitWith { SETVAR ["_init", true] }; // Rest only needs to be activated for clients

	// Dr.EyeBall dialog framework init
	[] spawn COMPILE_FILE(DebugInit);

	// init common functions
	[] spawn COMPILE_FILE(CommonFunctions);
	[] spawn COMPILE_FILE(CommonDialogFunctions);

	// Group Callsign module
	[] spawn COMPILE_FILE(init_cs);

	// Armalib
	if !(isNil "ArmaLib") then { if (ArmaLib) then { [] spawn COMPILE_FILE(init_armalib) } };

	// Add action to action menu
	//[["> Six Menu", QUOTE(PATHTO(ActivatePopupMenuViaAction)), [], 0, false, false, "teamSwitch"]] call CBA_fnc_addPlayerAction;
	[["player"], [ace_sys_interaction_key_self], 2, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;
	SETVAR ["_init", true];
};
