// by Xeno
private ["_officer", "_poss", "_fortress", "_newgroup", "_bpos", "_leader"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_17);
_mpos set [2,0];
_mpos2 = markerPos QGVAR(sm_17_1);
_mpos2 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos2]; // index: 17,   Officer in mine near Feruz-Abad
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_836");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_729");
};

if (isServer) then {
	_officer = GVAR(soldier_officer);
	__PossAndOther
	["shilka", 1, "bmp", 1, "tank", 1, _pos_other,1,400,true] spawn FUNC(CreateArmor);
	sleep 2.123;
	["specops", 2, "basic", 1, _poss,200,true] spawn FUNC(CreateInf);
	sleep 2.111;
	_fortress = createVehicle [GVAR(sm_fortress), _poss, [], 0, "NONE"];
	_fortress setPos _poss;
	__AddToExtraVec(_fortress)
	sleep 2.123;
	__GetEGrp(_newgroup)
	_sm_vehicle = _newgroup createUnit [_officer, _poss, [], 0, "FORM"];
	if (GVAR(without_nvg) == 0) then {
		if (_sm_vehicle hasWeapon "NVGoggles") then {_sm_vehicle removeWeapon "NVGoggles"};
	};
	_sm_vehicle setVariable ["BIS_noCoreConversations", true];
	__addDeadAI(_sm_vehicle)
	if (GVAR(domdatabase)) then {
		_sm_vehicle addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddAIKillPoints)}}];
	};
#ifndef __TT__
	_sm_vehicle addEventHandler ["killed", FUNC(KilledSMTargetNormal)];
#else
	_sm_vehicle addEventHandler ["killed", FUNC(KilledSMTargetTT)];
#endif
	sleep 2.123;
	_bpos = position _fortress;
	_sm_vehicle setPos _bpos;
	_leader = leader _newgroup;
	_leader setRank "COLONEL";
	_newgroup allowFleeing 0;
	_newgroup setbehaviour "AWARE";
	_leader disableAI "MOVE";
};