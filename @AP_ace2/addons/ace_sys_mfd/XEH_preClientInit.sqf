//#define DEBUG_MODE_FULL
#include "script_component.hpp"

ADDON = false;

PREP(openDialog);
PREP(closeDialog);

PREP(onDialogOpen);
PREP(onDialogClose);

PREP(onKeyPress);

PREP(renderDisplay);

// text handling functions
PREP(setRowText);
PREP(setRowText_AlignRight);
PREP(getRowText);
PREP(clearAllText);

// Helpers
PREP(getMaxRows);
PREP(getMaxCols);

// XEH handlers
PREP(onGetOut);

PREP(hasLaserGuided);

// state machine
PREP(stateMachine);
PREP(resetState);
GVAR(currentState) = ["WPN"];

GVAR(stateTable) = [
	["WPN", COMPILE_FILE(states\wpn), [
		["ammunition_status", COMPILE_FILE(states\WPN_ammunition_status), nil],
		["missile_fire_control", COMPILE_FILE(states\WPN_missile_fire_control), [
			["set_laser_code", COMPILE_FILE(states\WPN_missile_set_laser_code), nil],
			["set_fire_mode", COMPILE_FILE(states\WPN_missile_set_fire_mode), nil],
			["set_cbu_altitude", COMPILE_FILE(states\WPN_cbu_set_altitude), nil],
			nil
		]],
		["fire_control_system", COMPILE_FILE(states\WPN_fire_control_system), nil],
		["laser_designation_control", COMPILE_FILE(states\WPN_laser_designation_control), nil],
		nil
	]],
	["FCR", COMPILE_FILE(states\fcr), nil],
	nil
];

// Key Handlers
// Add cba keyhandler
FUNC(onToggleMfdKeyPressed) = {
	PARAMS_1(_player);
	TRACE_1("", _this);
	if (!isNull player) then {
		if (alive player) then {
			if !(isNil QGVAR(currentDialog)) then {
				LOG("closing");
				[] call FUNC(closeDialog);
			} else {
				LOG("opening");
				[] call FUNC(openDialog);
			};
		};
	};
	false
};
[QUOTE(ADDON), "Toggle_MFD_Open", { player call FUNC(onToggleMfdKeyPressed) }, "DOWN"] call CBA_fnc_addKeyHandlerFromConfig;

// GVAR inits
GVAR(currentDialog) = nil;
GVAR(currentDialogClass) = nil;

GVAR(lastKeyPressTime) = 0;
GVAR(KeyPressHandler) = nil;

GVAR(lastKeyPressed) = "-1";


ADDON = true;
