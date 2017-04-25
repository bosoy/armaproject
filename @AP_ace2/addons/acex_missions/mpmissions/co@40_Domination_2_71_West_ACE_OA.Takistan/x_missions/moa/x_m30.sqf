// by Xeno
#include "x_setup.sqf"
private ["_trigger", "_cm", "_endtime", "_ran", "_i", "_newgroup", "_units", "_leader"];

_mpos = markerPos QGVAR(sm_30);
_mpos set [2,0];
GVAR(x_sm_pos) = [_mpos]; //  cruise missile
GVAR(x_sm_type) = "normal"; // "convoy"

#ifdef __SMMISSIONS_MARKER__
if (true) exitWith {};
#endif

if (X_Client) then {
	GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_772");
	GVAR(current_mission_resolved_text) = (localize "STR_DOM_MISSIONSTRING_773");
};

if (isServer) then {
	_trigger = objNull;
	_exact_pos = [GVAR(x_sm_pos) select 0, 300] call FUNC(GetRanPointCircleOld);
	_cm = createVehicle [GVAR(cruise_missile), _exact_pos, [], 0, "NONE"];
	_cm setDir (random 360);
	_cm setPos _exact_pos;
	_cm lock true;
	__AddToExtraVec(_cm)
	_cm addEventHandler ["killed", {_this call FUNC(KilledSMTargetNormal);(_this select 0) spawn {sleep 2;deleteVehicle _this}}];
	sleep 20;
	_time_over = 3;
	_enemy_created = false;
	GVAR(cruise_m_enemy) = false;
	_endtime = time + (15 * 60);
	while {true} do {
		if (isNull _cm || !alive _cm || GVAR(cruise_m_enemy)) exitWith {};
		if (_time_over > 0) then {
			if (_time_over == 3) then {
				if (_endtime - time <= 600) then {
					_time_over = 2;
#ifndef __TT__
					GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"TimeLimitSM",["1","","10",[]],true];
#else
					GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"TimeLimitSM",["1","","10",[]],true];
					GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"TimeLimitSM",["1","","10",[]],true];
#endif

				};
			} else {
				if (_time_over == 2) then {
					if (_endtime - time <= 300) then {
						_time_over = 1;
#ifndef __TT__
                        GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"TimeLimitSM",["1","","5",[]],true];
#else
                        GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"TimeLimitSM",["1","","5",[]],true];
                        GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"TimeLimitSM",["1","","5",[]],true];
#endif
					};
				} else {
					if (_time_over == 1) then {
						if (_endtime - time <= 120) then {
							_time_over = 0;
#ifndef __TT__
                            GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"TimeLimitSMTwoM",true];
#else
                            GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"TimeLimitSMTwoM",true];
                            GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"TimeLimitSMTwoM",true];
#endif
						};
					};
				};
			};
		} else {
			if (!_enemy_created) then {
				_trigger = [_exact_pos, [20,20,0,false], [GVAR(enemy_side),"PRESENT",false], ["this","d_cruise_m_enemy = true",""]] call FUNC(CreateTrigger);
				_enemy_created = true;
				_estart_pos = [_exact_pos,300] call FUNC(GetRanPointCircleOuter);
				_unit_array = ["basic", GVAR(enemy_side)] call FUNC(getunitliste);
				_ran = [3,5] call FUNC(GetRandomRangeInt);
				for "_i" from 1 to _ran do {
					_newgroup = [GVAR(enemy_side)] call FUNC(creategroup);
					_units = [_estart_pos, _unit_array select 0, _newgroup] call FUNC(makemgroup);
					sleep 1.045;
					_leader = leader _newgroup;
					_leader setRank "LIEUTENANT";
					_newgroup allowFleeing 0;
					_newgroup setVariable [QGVAR(gstate), 1];
					[_newgroup, _exact_pos] call FUNC(AttackWP);
					GVAR(extra_mission_remover_array) = [GVAR(extra_mission_remover_array), _units] call FUNC(arrayPushStack);
					GVAR(reduce_groups) set [count GVAR(reduce_groups), _newgroup];
					sleep 1.012;
				};
				_unit_array = nil;
			};
		};
		sleep 5.223;
	};

	if (!isNull _trigger) then {deleteVehicle _trigger};

	if (GVAR(cruise_m_enemy) && !isNull _cm) then {
		_cm removeAllEventHandlers "killed";
		GVAR(side_mission_winner) = -878;
	};

	GVAR(cruise_m_enemy) = nil;

	GVAR(side_mission_resolved) = true;
};