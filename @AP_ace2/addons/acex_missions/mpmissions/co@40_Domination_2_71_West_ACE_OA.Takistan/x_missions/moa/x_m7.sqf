// by Xeno
private ["_vehicle", "_poss", "_ogroup", "_unit", "_officer", "_endtime"];
#include "x_setup.sqf"

_mpos = markerPos QGVAR(sm_7);
_mpos set [2,0];
GVAR(x_sm_pos) = [_mpos]; //  destroy scud
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_874");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_875");
};

if (isServer) then {
	_MissionCompleted = {
	#ifndef __TT__
		GVAR(side_mission_winner) = 2;
	#else
		if (GVAR(sm_points_west) > GVAR(sm_points_east)) then {
			GVAR(side_mission_winner) = 2;
		} else {
			if (GVAR(sm_points_east) > GVAR(sm_points_west)) then {
				GVAR(side_mission_winner) = 1;
			} else {
				if (GVAR(sm_points_east) == GVAR(sm_points_west)) then {
					GVAR(side_mission_winner) = 123;
				};
			};
		};
	#endif
		GVAR(side_mission_resolved) = true;
	};

	__PossAndOther
	// TODO: Check if A3 still has SCUD
	_vehicle = createVehicle [GVAR(sm_SCUD), _poss, [], 0, "NONE"];
	_vehicle setDir (markerDir QGVAR(sm_7));
	_vehicle setPos _poss;
	_vehicle setFuel 0;
	#ifdef __TT__
	_vehicle addEventHandler ["killed", FUNC(AddSMPoints)];
	#endif
	__GetEGrp(_ogroup)
	_unit = _ogroup createUnit [GVAR(sm_simple_soldier_east), _poss, [], 0, "FORM"];
	if (GVAR(without_nvg) == 0) then {
		if (_unit hasWeapon "NVGoggles") then {_unit removeWeapon "NVGoggles"};
	};
	_unit setVariable ["BIS_noCoreConversations", true];
	__addDeadAI(_unit)
	if (GVAR(domdatabase)) then {
		_unit addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddAIKillPoints)}}];
	};
	_unit moveInDriver _vehicle;
	__AddToExtraVec(_unit)
	__AddToExtraVec(_vehicle)
	if (GVAR(domdatabase)) then {
		_vehicle addMPEventHandler ["MPKilled", {if (isServer) then {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddCarKillPoints)}}}];
	};
	sleep 2.123;
	["specops", 2, "basic", 2, _poss,200,true] spawn FUNC(CreateInf);
	sleep 2.321;
	["shilka", 1, "bmp", 1, "tank", 0, _poss,1,350,true] spawn FUNC(CreateArmor);
	
	_endtime = time + 900 + random 100;
	waitUntil {sleep 0.321;!alive _vehicle || time > _endtime};
	if (alive _vehicle) then {
		[QGVAR(smsg)] call FUNC(NetCallEventToClients);
		_vehicle action ["ScudLaunch",_vehicle];
	} else {
		call _MissionCompleted;
	};
	sleep 30;
	if (alive _vehicle) then {
		_vehicle action ["ScudStart",_vehicle];
		GVAR(side_mission_winner) = -879;
		GVAR(side_mission_resolved) = true;
	} else {
		call _MissionCompleted;
	};
};