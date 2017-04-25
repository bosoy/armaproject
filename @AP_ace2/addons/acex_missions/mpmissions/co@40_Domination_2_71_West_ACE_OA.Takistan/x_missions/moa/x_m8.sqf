// by Xeno
private ["_vehicle", "_poss"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_8);
_mpos set [2,0];
GVAR(x_sm_pos) = [_mpos]; // index: 8,   Radio tower near Landay
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_876");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_877");
};

if (isServer) then {
	__Poss
	_vehicle = createVehicle [GVAR(illum_tower), _poss, [], 0, "NONE"];
	_vehicle setPos _poss;
	_vehicle setVectorUp [0,0,1];
#ifndef __TT__
	[_vehicle] execFSM "fsms\XCheckSMHardTarget.fsm";
#else
	[_vehicle] execFSM "fsms\XCheckSMHardTargetTT.fsm";
#endif
	sleep 2.22;
	["specops", 1, "basic", 2, _poss,0] spawn FUNC(CreateInf);
};