// by Xeno
private ["_ogroup", "_poss", "_leadero"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_42);
_mpos set [2,0];
GVAR(x_sm_pos) = [_mpos]; // index: 42,   Officer in forrest near Nur
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
#ifndef __TT__
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_861");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_792");
#else
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_862");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_794");
#endif
};

if (isServer) then {
	__PossAndOther
	__GetEGrp(_ogroup)
	_sm_vehicle = _ogroup createUnit [GVAR(soldier_officer), _poss, [], 0, "FORM"];
	if (GVAR(without_nvg) == 0) then {
		if (_sm_vehicle hasWeapon "NVGoggles") then {_sm_vehicle removeWeapon "NVGoggles"};
	};
	_sm_vehicle setVariable ["BIS_noCoreConversations", true];
	__addDeadAI(_sm_vehicle)
	if (GVAR(domdatabase)) then {
		_sm_vehicle addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddAIKillPoints)}}];
	};
#ifndef __TT__
	_sm_vehicle addEventHandler ["killed", FUNC(KilledSMTarget500)];
	removeAllWeapons _sm_vehicle;
#else
	_sm_vehicle addEventHandler ["killed", FUNC(KilledSMTargetTT)];
#endif
	sleep 2.123;
	["specops", 3, "basic", 2, _poss, 200,true] spawn FUNC(CreateInf);
	sleep 2.123;
	_leadero = leader _ogroup;
	_leadero setRank "COLONEL";
	_ogroup setbehaviour "AWARE";
	_leadero disableAI "MOVE";
#ifndef __TT__
	[_sm_vehicle] execVM "x_missions\common\x_sidearrest.sqf";
#endif
};