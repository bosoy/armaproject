// by Xeno
#define THIS_FILE "x_sideconvoy.sqf"
#include "x_setup.sqf"
private ["_direction", "_numconfv", "_newgroup", "_reta", "_vehicles", "_nextpos", "_leader", "_i", "_wp", "_endtime"];

PARAMS_3(_pos_start,_pos_end,_direction);

_crew_member = "";

#ifdef __TT__
GVAR(sm_points_west) = 0;
GVAR(sm_points_east) = 0;
#endif

if (GVAR(with_ranked)) then {GVAR(sm_p_pos) = nil};

GVAR(confvdown) = 0;
_numconfv = count GVAR(sm_convoy_vehicles);
_newgroup = [GVAR(side_enemy)] call FUNC(creategroup);
_reta = [1, _pos_start, (GVAR(sm_convoy_vehicles) select 0), _newgroup, 0, _direction] call FUNC(makevgroup);
_vehicles = _reta select 0;
(_vehicles select 0) lock true;
_nextpos = (_vehicles select 0) modeltoworld [0, -9, 0];
_nextpos set [2,0];
(_vehicles select 0) addEventHandler ["killed", {__INC(GVAR(confvdown));
	#ifdef __TT__
	_this call FUNC(AddSMPoints)
	#endif
}];

GVAR(extra_mission_vehicle_remover_array) = [GVAR(extra_mission_vehicle_remover_array), _vehicles] call FUNC(arrayPushStack2);
GVAR(extra_mission_remover_array) = [GVAR(extra_mission_remover_array), _reta select 1] call FUNC(arrayPushStack);
_leader = leader _newgroup;
_leader setRank "LIEUTENANT";
_newgroup allowFleeing 0;
_newgroup setCombatMode "GREEN";
_newgroup setFormation "COLUMN";
_newgroup setSpeedMode "LIMITED";
sleep 1.933;
_vehicles = nil;
_allSMVecs = [];
for "_i" from 1 to (_numconfv - 1) do {
	_reta = [1, _nextpos, (GVAR(sm_convoy_vehicles) select _i), _newgroup, 20, _direction] call FUNC(makevgroup);
	_vehicles = _reta select 0;
	(_vehicles select 0) lock true;
	_nextpos = (_vehicles select 0) modeltoworld [0, -9, 0];
	_nextpos set [2,0];
	(_vehicles select 0) addEventHandler ["killed", {__INC(GVAR(confvdown));
		#ifdef __TT__
		_this call FUNC(AddSMPoints)
		#endif
	}];
	_allSMVecs set [count _allSMVecs, _vehicles select 0];
	GVAR(extra_mission_vehicle_remover_array) = [GVAR(extra_mission_vehicle_remover_array), _vehicles] call FUNC(arrayPushStack2);
	GVAR(extra_mission_remover_array) = [GVAR(extra_mission_remover_array), _reta select 1] call FUNC(arrayPushStack);
	sleep 1.933;
	_vehicles = nil;
};

_wp =_newgroup addWaypoint[_pos_start, 0];
_wp setWaypointBehaviour "SAFE";
_wp setWaypointSpeed "NORMAL";
_wp setwaypointtype "MOVE";
_wp setWaypointFormation "COLUMN";
_wp setWaypointTimeout [60,80,70];
_wp = _newgroup addWaypoint[_pos_end, 0];

sleep 20.123;

_convoy_reached_dest = false;
_convoy_destroyed = false;
_endtime = time + 3600;

while {true} do {
	__MPCheck;
	if (GVAR(confvdown) == _numconfv) exitWith {
		_convoy_destroyed = true;
	};
	if ({canMove _x} count _allSMVecs == 0) exitWith {
		_convoy_destroyed = true;
	};
	if ((position (leader _newgroup)) distance _pos_end < 40) exitWith {
		_convoy_reached_dest = true;
	};
	if (GVAR(with_ranked)) then {[QGVAR(sm_p_pos), position _leader] call FUNC(NetCallEventToClients)};
	if (time > _endtime) exitWith {_convoy_reached_dest = true};
	sleep 5.123;
};

if (_convoy_reached_dest) then {
	GVAR(side_mission_winner) = -300;
} else {
#ifndef __TT__
	if (_convoy_destroyed) then {GVAR(side_mission_winner) = 2};
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
};

GVAR(side_mission_resolved) = true;