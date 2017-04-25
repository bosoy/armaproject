// by Xeno
private "_poss";
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_20);
_mpos set [2,0];
_mpos2 = markerPos QGVAR(sm_20_1);
_mpos2 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos2]; // index: 20,   Convoy Nur to Garmsar, start and end position
GVAR(x_sm_type) = "convoy"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_840");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_753");
};

if (isServer) then {
	__PossAndOther
	[_poss, _pos_other, markerDir QGVAR(sm_20)] execVM "x_missions\common\x_sideconvoy.sqf";
};