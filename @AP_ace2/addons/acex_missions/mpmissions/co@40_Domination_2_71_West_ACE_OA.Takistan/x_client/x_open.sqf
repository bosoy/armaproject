// by Xeno
#define THIS_FILE "x_open.sqf"
#include "x_setup.sqf"
private ["_display", "_ctrl"];

if (dialog) then {closeDialog 0};

GVAR(beam_target) = -1;
GVAR(tele_dialog) = 0; // 0 = respawn, 1 = teleport

if (isNil QUOTE(FUNC(x_teleupdate_dlg))) then {__cppfln(FUNC(x_teleupdate_dlg),x_client\x_update_dlg.sqf)};

disableSerialization;

createDialog "d_TeleportModule";

#define __CTRL(A) (_display displayCtrl A)
_display = __uiGetVar(X_TELE_DIALOG);
__CTRL(100102) ctrlSetText (localize "STR_DOM_MISSIONSTRING_298");
__CTRL(100111) ctrlSetText (localize "STR_DOM_MISSIONSTRING_299");
__CTRL(100112) ctrlShow false;
__CTRL(100103) ctrlShow false;

GVAR(x_loop_end) = false;

0 spawn {
	sleep 0.1;
	[GVAR(last_telepoint)] call FUNC(x_update_target);
	while {!GVAR(x_loop_end) && alive player && GVAR(teleport_dialog_open)} do {
		if (!GVAR(x_loop_end) && alive player) then {call FUNC(x_teleupdate_dlg)};
		sleep 1.012;
	};
	if (!alive player) then {if (GVAR(teleport_dialog_open)) then {closeDialog 0}};
};
