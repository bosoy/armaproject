// by Xeno
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_29);
_mpos set [2,0];
_mpos1 = markerPos QGVAR(sm_29_1);
_mpos1 set [2,0];
_mpos2 = markerPos QGVAR(sm_29_2);
_mpos2 set [2,0];
_mpos3 = markerPos QGVAR(sm_29_3);
_mpos3 set [2,0];
_mpos4 = markerPos QGVAR(sm_29_4);
_mpos4 set [2,0];
_mpos5 = markerPos QGVAR(sm_29_5);
_mpos5 set [2,0];
_mpos6 = markerPos QGVAR(sm_29_6);
_mpos6 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos1, _mpos2, _mpos3, _mpos4, _mpos5, _mpos6]; // index: 29,   Tank depot at Cabo Juventudo
GVAR(x_sm_type) = "normal"; // "convoy"

_tank_dirs = [markerDir QGVAR(sm_29_1),markerDir QGVAR(sm_29_2),markerDir QGVAR(sm_29_3),markerDir QGVAR(sm_29_4),markerDir QGVAR(sm_29_5),markerDir QGVAR(sm_29_6)];

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_851");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_767");
};

if (isServer) then {
	[GVAR(x_sm_pos), _tank_dirs] execVM "x_missions\common\x_sidetanks.sqf";
};
