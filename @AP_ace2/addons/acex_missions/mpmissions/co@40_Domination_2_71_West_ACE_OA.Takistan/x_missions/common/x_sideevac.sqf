// by Xeno
#define THIS_FILE "x_sideevac.sqf"
#include "x_setup.sqf"
private ["_endtime", "_poss", "_wreck", "_owngroup", "_pilot1", "_pilot2", "_rescued", "_winner", "_resctimestarted", "_nobjs", "_ran", "_i", "_newgroup", "_units", "_leader"];
if (!isServer) exitWith {};

PARAMS_2(_pos_array,_endtime);

_poss = _pos_array select 0;

_side_crew = if (GVAR(enemy_side) == "EAST") then {west} else {east};

_wreck = createVehicle [GVAR(sm_wrecktype), _poss, [], 0, "NONE"];
_wreck setDir (random 360);
_wreck setPos _poss;
_wreck lock true;
__AddToExtraVec(_wreck)

sleep 2;

_owngroup = [_side_crew] call FUNC(creategroup);
_pilot1 = _owngroup createUnit [GVAR(sm_pilottype), _poss, [], 60, "FORM"];
if (GVAR(without_nvg) == 0) then {
	if (_pilot1 hasWeapon "NVGoggles") then {_pilot1 removeWeapon "NVGoggles"};
};
_pilot1 setVariable ["BIS_noCoreConversations", true];

_pilot2 = _owngroup createUnit [GVAR(sm_pilottype), position _pilot1, [], 60, "FORM"];
if (GVAR(without_nvg) == 0) then {
	if (_pilot2 hasWeapon "NVGoggles") then {_pilot2 removeWeapon "NVGoggles"};
};
_pilot2 setVariable ["BIS_noCoreConversations", true];

_owngroup setVariable [QGVAR(gstate), 1];

sleep 15;
_side_crew = nil;
_pilot1 disableAI "MOVE";
_pilot1 setDamage 0.5;
_pilot1 setUnitPos "DOWN";
_pilot2 disableAI "MOVE";
_pilot2 setDamage 0.5;
_pilot2 setUnitPos "DOWN";

_is_dead = false;
_pilots_at_base = false;
_rescued = false;
_winner = 0;
_time_over = 3;
_enemy_created = false;
_resctimestarted = time;

while {!_pilots_at_base && !_is_dead} do {
	if (X_MP) then {waitUntil {sleep (1.012 + random 1);_pnum = call FUNC(PlayersNumber); if (_pnum == 0) then {_resctimestarted = time};_pnum > 0}};
	if (!alive _pilot1 && !alive _pilot2) then {
		_is_dead = true;
	} else {
		if (!_rescued) then {
			_nobjs = [];
			if (alive _pilot1) then {_nobjs = (position _pilot1) nearEntities ["CAManBase", 20]};
			if (alive _pilot2) then {[_nobjs, (position _pilot2) nearEntities ["CAManBase", 20]] call FUNC(arrayPushStack2)};
			if (count _nobjs > 0) then {
				{
					if (isPlayer _x) exitWith {
						_resctimestarted = time;
						_rescued = true;
						if (alive _pilot1) then {
							_pilot1 setUnitPos "AUTO";
							_pilot1 enableAI "MOVE";
							[QGVAR(joing), [group _x, [_pilot1]]] call FUNC(NetCallEventSTO);
						};
						if (alive _pilot2) then {
							_pilot2 setUnitPos "AUTO";
							_pilot2 enableAI "MOVE";
							[QGVAR(joing), [group _x, [_pilot2]]] call FUNC(NetCallEventSTO);
						};
					};
					sleep 0.01;
				} forEach _nobjs;
			};
			if (time - _resctimestarted > 1800 && !_rescued) then {
				_is_dead = true;
			};
		} else {
			if (alive _pilot1 && alive _pilot2) then {
				if (_pilot1 distance GVAR(FLAG_BASE) < 20 && _pilot2 distance GVAR(FLAG_BASE) < 20) then {_pilots_at_base = true};
			} else {
				if (_pilot1 distance GVAR(FLAG_BASE) < 20 || _pilot2 distance GVAR(FLAG_BASE) < 20) then {_pilots_at_base = true};
			};
			if (time - _resctimestarted > 1800) then {
				_is_dead = true;
			};
		};
	};

	sleep 5.621;
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
			_enemy_created = true;
			_estart_pos = [_poss,250] call FUNC(GetRanPointCircleOuter);
			_unit_array = ["basic", GVAR(enemy_side)] call FUNC(getunitliste);
			_ran = [3,5] call FUNC(GetRandomRangeInt);
			for "_i" from 1 to _ran do {
				_newgroup = [GVAR(enemy_side)] call FUNC(creategroup);
				_units = [_estart_pos, _unit_array select 0, _newgroup] call FUNC(makemgroup);
				sleep 1.045;
				_leader = leader _newgroup;
				_leader setRank "LIEUTENANT";
				_newgroup allowFleeing 0;
				[_newgroup, _poss] call FUNC(AttackWP);
				GVAR(extra_mission_remover_array) = [GVAR(extra_mission_remover_array), _units] call FUNC(arrayPushStack);
				GVAR(reduce_groups) set [count GVAR(reduce_groups), _newgroup];
				sleep 1.012;
			};
			_unit_array = nil;
		};
	};
};

if (_is_dead) then {
	GVAR(side_mission_winner) = -700;
	if (!isNull _pilot1) then {
		if (vehicle _pilot1 != _pilot1) then {
			_pilot1 action ["eject", vehicle _pilot1];
			unassignVehicle _pilot1;
			_pilot1 setPos [0,0,0];
		};
	};
	if (!isNull _pilot2) then {
		if (vehicle _pilot2 != _pilot2) then {
			_pilot2 action ["eject", vehicle _pilot2];
			unassignVehicle _pilot2;
			_pilot2 setPos [0,0,0];
		};
	};
	sleep 0.5;
	deleteVehicle _pilot1;
	deleteVehicle _pilot2;
} else {
	if (_pilots_at_base) then {
		if (GVAR(with_ranked)) then {
			if !(__TTVer) then {
				[QGVAR(sm_p_pos), position GVAR(FLAG_BASE)] call FUNC(NetCallEventToClients);
			} else {
				if (_winner == 1) then {
					[QGVAR(sm_p_pos), position GVAR(EFLAG_BASE)] call FUNC(NetCallEventToClients);
				} else {
					[QGVAR(sm_p_pos), position GVAR(WFLAG_BASE)] call FUNC(NetCallEventToClients);
				}
			};
		};
		if (_winner != 0) then {
			GVAR(side_mission_winner) = _winner;
		} else {
			GVAR(side_mission_winner) = 2;
		};
		sleep 2.123;
		if (alive _pilot1) then {
			if (vehicle _pilot1 != _pilot1) then {
				_pilot1 action ["eject", vehicle _pilot1];
				unassignVehicle _pilot1;
				_pilot1 setPos [0,0,0];
			};
		};
		if (alive _pilot2) then {
			if (vehicle _pilot2 != _pilot2) then {
				_pilot2 action ["eject", vehicle _pilot2];
				unassignVehicle _pilot2;
				_pilot2 setPos [0,0,0];
			};
		};
		sleep 0.5;
		deleteVehicle _pilot1;
		deleteVehicle _pilot2;
	};
};

GVAR(side_mission_resolved) = true;