// by Xeno
private ["_poss", "_fortress", "_newgroup", "_leader"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_13);
_mpos set [2,0];
_mpos2 = markerPos QGVAR(sm_13_1);
_mpos2 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos2]; // index: 13,   Prime Minister,Nagara
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_829");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_737");
};

if (isServer) then {
	__PossAndOther
	["shilka", 1, "bmp", 1, "tank", 1, _pos_other,1,0] spawn FUNC(CreateArmor);
	sleep 2.123;
	["specops", 2, "basic", 1, _poss,200,true] spawn FUNC(CreateInf);
	sleep 2.111;
	_fortress = createVehicle [GVAR(sm_fortress), _poss, [], 0, "NONE"];
	_fortress setDir (markerDir QGVAR(sm_13));
	_fortress setPos _poss;
	__AddToExtraVec(_fortress)
	sleep 2.123;
	__GetEGrp(_newgroup)
	_sm_vehicle = _newgroup createUnit [GVAR(functionary), _poss, [], 0, "FORM"];
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
	_sm_vehicle setPos position _fortress;
	_leader = leader _newgroup;
	_leader setRank "COLONEL";
	_newgroup allowFleeing 0;
	_newgroup setbehaviour "AWARE";
	_leader disableAI "MOVE";
};