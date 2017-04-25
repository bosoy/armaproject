// by Xeno
#define THIS_FILE "x_teleport.sqf"
#include "x_setup.sqf"
private ["_ok","_vehicle"];

if (vehicle player != player) exitWith {(localize "STR_DOM_MISSIONSTRING_583") call FUNC(GlobalChat)};

if (!isNull (flag player)) exitWith {(localize "STR_DOM_MISSIONSTRING_584") call FUNC(GlobalChat)};

_is_swimmer = ((animationState player) in ["aswmpercmstpsnonwnondnon","aswmpercmstpsnonwnondnon_aswmpercmrunsnonwnondf","aswmpercmrunsnonwnondf_aswmpercmstpsnonwnondnon","aswmpercmrunsnonwnondf","aswmpercmsprsnonwnondf","aswmpercmwlksnonwnondf"]);
if (_is_swimmer) exitWith {(localize "STR_DOM_MISSIONSTRING_585") call FUNC(GlobalChat)};

if (dialog) then {closeDialog 0};

GVAR(beam_target) = -1;
if (GVAR(WithTeleToBase) == 0) then {
	GVAR(tele_dialog) = 2; // 0 = respawn, 1 = teleport
} else {
	GVAR(tele_dialog) = 1;
};

if (isNil QUOTE(FUNC(x_teleupdate_dlg))) then {__cppfln(FUNC(x_teleupdate_dlg),x_client\x_update_dlg.sqf)};

disableSerialization;

createDialog "d_TeleportModule";

#define __CTRL(A) (_display displayCtrl A)

_display = __uiGetVar(X_TELE_DIALOG);
__CTRL(100102) ctrlSetText (localize "STR_DOM_MISSIONSTRING_533");
__CTRL(100111) ctrlSetText (localize "STR_DOM_MISSIONSTRING_586");
if (GVAR(WithTeleToBase) == 1) then {
	__CTRL(100107) ctrlShow false;
};
__CTRL(100112) ctrlShow false;

GVAR(x_loop_end) = false;

[GVAR(last_telepoint)] call FUNC(x_update_target);

0 spawn {
	while {!GVAR(x_loop_end) && alive player && dialog} do {
		if (!GVAR(x_loop_end) && alive player) then {call FUNC(x_teleupdate_dlg)};
		sleep 1.012;
	};
	if (!alive player) then {closeDialog 0};
};