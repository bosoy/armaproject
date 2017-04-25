// by Xeno
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_25);
_mpos set [2,0];
GVAR(x_sm_pos) = [_mpos]; // Specop camp near Nur
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_845");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_760");
};

if (isServer) then {
	[GVAR(x_sm_pos) select 0] execVM "x_missions\common\x_sidespecops.sqf";
};