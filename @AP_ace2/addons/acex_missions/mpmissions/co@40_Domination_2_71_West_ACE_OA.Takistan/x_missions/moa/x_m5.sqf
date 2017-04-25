// by Xeno
private ["_xtank", "_vehicle", "_poss"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_5);
_mpos set [2,0];
GVAR(x_sm_pos) = [_mpos]; //  destroy power generator in mine near Feruz-Abad
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_870");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_871");
};

if (isServer) then {
	__PossAndOther
	_vehicle = createVehicle ["Land_Misc_Cargo2E_EP1", _poss, [], 0, "NONE"];
	_vehicle setDir (markerDir QGVAR(sm_5));
	_vehicle setPos _poss;
#ifndef __TT__
	[_vehicle] execFSM "fsms\XCheckSMHardTarget.fsm";
#else
	[_vehicle] execFSM "fsms\XCheckSMHardTargetTT.fsm";
#endif
	__AddToExtraVec(_vehicle)
	sleep 2.123;
	["specops", 2, "basic", 3, _poss,200,true] spawn FUNC(CreateInf);
	sleep 2.321;
	["shilka", 1, "bmp", 1, "tank", 1, _poss,1,350,true] spawn FUNC(CreateArmor);
};