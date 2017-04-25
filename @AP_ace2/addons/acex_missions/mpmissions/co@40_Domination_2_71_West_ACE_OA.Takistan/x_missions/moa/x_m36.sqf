// by Xeno
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_36);
_mpos set [2,0];
_mpos1 = markerPos QGVAR(sm_36_1);
_mpos1 set [2,0];
_mpos2 = markerPos QGVAR(sm_36_2);
_mpos2 set [2,0];
_mpos3 = markerPos QGVAR(sm_36_3);
_mpos3 set [2,0];
_mpos4 = markerPos QGVAR(sm_36_4);
_mpos4 set [2,0];
_mpos5 = markerPos QGVAR(sm_36_5);
_mpos5 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos1, _mpos2, _mpos3, _mpos4, _mpos5]; // index: 36,   Capture the flag, Anar
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_857");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_776");
};

if (isServer) then {
	[GVAR(x_sm_pos)] execVM "x_missions\common\x_sideflag.sqf";
};