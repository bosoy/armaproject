// by Xeno
private ["_vehicle", "_poss"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_6);
_mpos set [2,0];
_mpos1 = markerPos QGVAR(sm_6_1);
_mpos1 set [2,0];
_mpos2 = markerPos QGVAR(sm_6_2);
_mpos2 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos1, _mpos2]; // index: 6,   Hangar near Falar
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_873");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_815");
};

if (isServer) then {
	__PossAndOther
	_pos_other2 = GVAR(x_sm_pos) select 2;
	_vehicle = createVehicle [GVAR(sm_hangar), _poss, [], 0, "NONE"];
	_vehicle setPos _poss;
#ifndef __TT__
	[_vehicle] execFSM "fsms\XCheckSMHardTarget.fsm";
#else
	[_vehicle] execFSM "fsms\XCheckSMHardTargetTT.fsm";
#endif
	_vehicle setDir (markerDir QGVAR(sm_6));
	sleep 2.123;
	["specops", 1, "basic", 1, _pos_other,200,true] spawn FUNC(CreateInf);
	sleep 2.012;
	["shilka", 1, "bmp", 1, "tank", 1, _pos_other2,1,400,true] spawn FUNC(CreateArmor);
	__AddToExtraVec(_vehicle)
};