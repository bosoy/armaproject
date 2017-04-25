// by Xeno
private "_poss";
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_50);
_mpos set [2,0];
GVAR(x_sm_pos) = [_mpos]; // index: 50,   Artillery base
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = "Finally we've found the enemy artillery base. If you can destroy all artillery guns the artillery observers at main targets have nothing to call in artillery strikes anymore.";
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_810");
};

if (isServer) then {
	__Poss
	[_poss] execVM "x_missions\common\x_sidearti.sqf";
};