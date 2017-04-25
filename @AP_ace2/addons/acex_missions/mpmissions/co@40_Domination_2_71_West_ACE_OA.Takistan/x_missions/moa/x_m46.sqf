// by Xeno
private ["_objs", "_poss"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_46);
_mpos set [2,0];
GVAR(x_sm_pos) = [_mpos]; // index: 46,   Destroy factory building in Lalezar
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_864");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_865");
};

if (isServer) then {
	__Poss
	_objs = nearestObjects [_poss, ["Land_Ind_TankBig"], 50];
	sleep 2.123;
	["specops", 2, "basic", 1, _poss,200,true] spawn FUNC(CreateInf);
	sleep 2.221;
	["shilka", 1, "bmp", 1, "tank", 1, _poss,1,400,true] spawn FUNC(CreateArmor);
	[_objs select 0, _objs select 1, _objs select 2] execVM "x_missions\common\x_sidefactory.sqf";
};