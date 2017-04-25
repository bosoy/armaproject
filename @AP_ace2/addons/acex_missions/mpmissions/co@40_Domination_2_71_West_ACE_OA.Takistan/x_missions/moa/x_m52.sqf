// by Xeno
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_52);
_mpos set [2,0];
GVAR(x_sm_pos) = [_mpos]; // index: 52,   Shot down chopper
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_813");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_812");
};

if (isServer) then {
	[GVAR(x_sm_pos),time + ((15 * 60) + random 60)]  execVM "x_missions\common\x_sideevac.sqf";
};