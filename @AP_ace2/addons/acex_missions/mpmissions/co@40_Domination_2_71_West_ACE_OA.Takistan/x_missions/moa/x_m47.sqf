// by Xeno
private ["_objs", "_poss"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_47);
_mpos set [2,0];
GVAR(x_sm_pos) = [_mpos]; // index: 47,   Destroy oil pumps
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_866");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_867");
};

if (isServer) then {
	__Poss
	_objs = nearestObjects [_poss, ["Land_Ind_Oil_Pump_EP1"], 150];
	if (count _objs < 3) then {_objs set [2, objNull]};
	sleep 2.123;
	["specops", 2, "basic", 1, _poss,200,true] spawn FUNC(CreateInf);
	sleep 2.221;
	["shilka", 1, "bmp", 1, "tank", 1, _poss,1,400,true] spawn FUNC(CreateArmor);
	sleep 5.123;
	[_objs select 0, _objs select 1, _objs select 2] execVM "x_missions\common\x_sidefactory.sqf";
};