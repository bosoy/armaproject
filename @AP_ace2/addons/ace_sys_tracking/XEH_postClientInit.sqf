// #define DEBUG_MODE_FULL
#include "script_component.hpp"

LOG(MSG_INIT);
// TODO: Completely enable BLUEFORCE TRACKER / REDFORCE TRACKER. Only allow disabling BLUEFORCE TRACKER
// TODO: Remove the preset colors REFERENCE IN SCRIPTS
// TODO: Remove option in settings for group markers in options
// TODO: For BT / RT a GPS and a RADIO is ALWAYS required (optionally bind to ACRE)
// TODO: Trackin only visible on:
// VEHICLE: MAP / GPS when vehicle has GPS
// PLAYER: GPS when player has the "DEVICE" / DAGR with DEVICE / GPS with DEVICE  .. AND RADIO ..

// TODO: Also do track empty vehicles

if (!isDedicated) then {
	[["Tank","Car","Air"], [ace_sys_interaction_key], 2, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;
};

if (isNil QGVAR(markers_debug)) then { GVAR(markers_debug) = false };
if (!isNil QGVAR(markers_enabled)) then {
	GVAR(enabled) = GVAR(markers_enabled);
};
if (isNil QGVAR(enabled)) then {
	GVAR(enabled) = true;
	if (isServer) then { publicVariable QGVAR(enabled) };
};
// Prepare Functions & Scripts
PREP(findLaser);
PREP(hasGPS);

if (GVAR(enabled)) then { [] spawn COMPILE_FILE(loop_markers) };
