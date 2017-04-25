// by Xeno
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_33);
_mpos set [2,0];
_mpos1 = markerPos QGVAR(sm_33_1);
_mpos1 set [2,0];
_mpos2 = markerPos QGVAR(sm_33_2);
_mpos2 set [2,0];
_mpos3 = markerPos QGVAR(sm_33_3);
_mpos3 set [2,0];
_mpos4 = markerPos QGVAR(sm_33_4);
_mpos4 set [2,0];
_mpos5 = markerPos QGVAR(sm_33_5);
_mpos5 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos1, _mpos2, _mpos3, _mpos4, _mpos5]; // index: 33,   Capture the flag, Huzrutimam
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_856");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_776");
};

if (isServer) then {
	[GVAR(x_sm_pos)] execVM "x_missions\common\x_sideflag.sqf";
};