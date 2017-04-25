// by Xeno
private ["_vehicle", "_poss"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_14);
_mpos set [2,0];
_mpos2 = markerPos QGVAR(sm_14_1);
_mpos2 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos2]; // index: 14,   Radio tower at mount Jabal os Saraj
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_830");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_831");
};

if (isServer) then {
	__PossAndOther
	_vehicle = createVehicle [GVAR(illum_tower), _poss, [], 0, "NONE"];
	_vehicle setPos _poss;
	_vehicle setVectorUp [0,0,1];
#ifndef __TT__
	[_vehicle] execFSM "fsms\XCheckSMHardTarget.fsm";
#else
	[_vehicle] execFSM "fsms\XCheckSMHardTargetTT.fsm";
#endif
	sleep 2.22;
	["shilka", 1, "bmp", 1, "tank", 1, _pos_other,1,300,true] spawn FUNC(CreateArmor);
	sleep 2.333;
	["specops", 1, "basic", 2, _poss,200,true] spawn FUNC(CreateInf);
	__AddToExtraVec(_vehicle)
};