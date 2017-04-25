// by Xeno
private ["_randomv", "_poss", "_vehicle"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_9);
_mpos set [2,0];
_mpos1 = markerPos QGVAR(sm_9_1);
_mpos1 set [2,0];
_mpos2 = markerPos QGVAR(sm_9_2);
_mpos2 set [2,0];
_mpos3 = markerPos QGVAR(sm_9_3);
_mpos3 set [2,0];
GVAR(x_sm_pos) = [_mpos, _mpos1, _mpos2, _mpos3]; // index: 9,   Helicopter Prototype at Rasman Airfield
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {	
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_878");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_821");
};

if (isServer) then {
	_randomv = floor random 2;
	__PossAndOther
	if (_randomv == 1) then {_poss = GVAR(x_sm_pos) select 3};
	_pos_other2  = GVAR(x_sm_pos) select 2;
	_vehicle = objNull;
	_vehicle = createVehicle [GVAR(sm_chopper), _poss, [], 0, "NONE"];
	_vehicle setDir (markerDir QGVAR(sm_9));
	_vehicle setPos _poss;
	if (GVAR(domdatabase)) then {
		_vehicle addMPEventHandler ["MPKilled", {if (isServer) then {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddChopperKillPoints)}}}];
	};
#ifndef __TT__
	_vehicle addEventHandler ["killed", FUNC(KilledSMTargetNormal)];
#else
	_vehicle addEventHandler ["killed", FUNC(KilledSMTargetTT)];
#endif
	_vehicle lock true;
	sleep 2.123;
	["specops", 1, "basic", 2, _poss,200,true] spawn FUNC(CreateInf);
	sleep 2.111;
	["shilka", 1, "bmp", 1, "tank", 0, _pos_other2,1,400,true] spawn FUNC(CreateArmor);
};