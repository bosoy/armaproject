// by Xeno
private ["_officer", "_fortress", "_poss", "_ogroup", "_bpos", "_leadero"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_1);
_mpos set [2,0];
_mpos2 = markerPos QGVAR(sm_1_1);
_mpos2 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos2]; // Officer, Shamali, second array = position Shilka
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_824");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_729");
};

if (isServer) then {
	_officer = GVAR(soldier_officer);
	__PossAndOther
	["shilka", 1, "", 0, "", 0, _pos_other,1,0,false] spawn FUNC(CreateArmor);
	sleep 2.123;
	_fortress = createVehicle [GVAR(sm_fortress), _poss, [], 0, "NONE"];
	_fortress setDir (markerDir QGVAR(sm_1));
	_fortress setPos _poss;
	__AddToExtraVec(_fortress)
	sleep 2.123;
	__GetEGrp(_ogroup)
	_sm_vehicle = _ogroup createUnit [_officer, _poss, [], 0, "FORM"];
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
	sleep 2.123;
	["specops", 2, "basic", 2, _poss, 200,true] spawn FUNC(CreateInf);
	sleep 2.123;
	_leadero = leader _ogroup;
	_leadero setRank "COLONEL";
	_ogroup allowFleeing 0;
	_ogroup setbehaviour "AWARE";
	_leadero disableAI "MOVE";
};