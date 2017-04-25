#define THIS_FILE "x_server\x_createparas.sqf"
// by Xeno
#include "x_setup.sqf"
private ["_type","_startpoint","_attackpoint","_heliendpoint","_number_vehicles","_parachute_type","_make_jump","_current_target_pos","_dummy","_delveccrew"];
if (!isServer) exitWith {};

_basempos = markerPos "d_base_marker"; // d_base_marker_w   d_base_marker_e
_basempos set [2,0];
_startpoint = call FUNC(GetRanPointOuterAir);
while {_basempos distance _startpoint < 1200} do {
	sleep 0.1;
	_startpoint = call FUNC(GetRanPointOuterAir);
};

_heliendpoint = call FUNC(GetRanPointOuterAir);
while {_basempos distance _heliendpoint < 1200} do {
	sleep 0.1;
	_heliendpoint = call FUNC(GetRanPointOuterAir);
};

_camps = switch (GVAR(enemy_side)) do {
	case "EAST": {GVAR(west_camps)};
	case "WEST": {GVAR(east_camps)};
};
_attackpoint = position (_camps call FUNC(RandomArrayVal));

_number_vehicles = (ceil random 5) max 2;

_delveccrew = {
	private ["_crew_vec", "_vehicle", "_time"];
	PARAMS_3(_crew_vec,_vehicle,_time);
	sleep _time;
	{if (!isNull _x) then {_x setDamage 1}} forEach _crew_vec;
	sleep 1;
	if (!isNull _vehicle && ({isPlayer _x} count (crew _vehicle)) == 0) then {_vehicle setDamage 1};
};

_make_jump = {
	private ["_vgrp", "_vehicle", "_attackpoint", "_heliendpoint", "_driver_vec", "_wp", "_stop_me", "_parachute_type", "_dummy", "_current_target_pos", "_paragrp", "_unit_array", "_real_units", "_i", "_type", "_one_unit", "_para", "_grp_array","_crew_vec","_delveccrew"];
	PARAMS_5(_vgrp,_vehicle,_attackpoint,_heliendpoint,_delveccrew);
	
	__TRACE("_make_jump");
	
	_startpos = position _vehicle;
	_driver_vec = driver _vehicle;
	_crew_vec = crew _vehicle;
	
	_wp = _vgrp addWaypoint [_attackpoint, 0];
	_wp setWaypointBehaviour "CARELESS";
	_wp setWaypointSpeed "NORMAL";
	_wp setwaypointtype "MOVE";
	_wp setWaypointFormation "VEE";
	_wp = _vgrp addWaypoint [_heliendpoint, 0];
	
	_vehicle flyInHeight 100;
	
	sleep 10.0231;
	
	_stop_me = false;
	_checktime = time + 300;
	while {_attackpoint distance (leader _vgrp) > 300} do {
		#ifdef __DEBUG__
		_ddd = _attackpoint distance (leader _vgrp);
		__TRACE_1("","_ddd");
		#endif
		if (isNull _vehicle || !alive _vehicle || !alive _driver_vec || !canMove _vehicle) exitWith {};
		sleep 0.01;
		if (_attackpoint distance (leader _vgrp) > 1300) exitWith {
			[_crew_vec, _vehicle, 1 + random 1] spawn _delveccrew;
			_stop_me = true;
		};
		sleep 0.01;
		if (time > _checktime) then {
			if (_startpos distance position _vehicle < 500) then {
				[_crew_vec, _vehicle, 1 + random 1] spawn _delveccrew;
				_stop_me = true;
			} else {
				_checktime = time + 9999999;
			};
		};
		if (_stop_me) exitWith {};
		sleep 2.023;
	};
	if (_stop_me) exitWith {};
	
	sleep 0.534;
	
	_parachute_type = GVAR(enemy_side) call FUNC(GetParachuteSide);
	
	if (!isNull _vehicle && alive _vehicle && alive _driver_vec && canMove _vehicle) then {
		_current_target_pos = GVAR(enemyai_mt_attack_pos);
		if (_vehicle distance _current_target_pos < 500) then {
			_cur_radius = _dummy select 2;
			__GetEGrp(_paragrp)
			_unit_array = ["heli", GVAR(enemy_side)] call FUNC(getunitliste);
			_real_units = _unit_array select 0;
			_unit_array = nil;
			sleep 0.1;
			{
				_one_unit = _paragrp createunit [_x, [10,10,0], [], 300,"NONE"];
				[_one_unit, {__addDeadAI(_this)}] call FUNC(setUnitCode);
				if (GVAR(domdatabase)) then {
					[_one_unit, {_this addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddAIKillPoints)}}]}] call FUNC(setUnitCode);
				};
#ifdef __TT__
				[_one_unit, {_this addEventHandler ["killed", {[1,_this select 1] call FUNC(AddKills)}]}] call FUNC(setUnitCode);
#endif
				if (GVAR(with_ai)) then {
					if (__RankedVer) then {
						[_one_unit, {_this addEventHandler ["killed", {[1,_this select 1] call FUNC(AddKillsAI)}]}] call FUNC(setUnitCode);
					};
				};
				_one_unit setSkill ((GVAR(skill_array) select 0) + (random (GVAR(skill_array) select 1)));
				
				_para = createVehicle [_parachute_type, position _vehicle, [], 20, 'NONE'];
				_para setpos [(position _vehicle) select 0, (position _vehicle) select 1, ((position _vehicle) select 2)- 10];
				_para setDir random 360;
				_one_unit moveInDriver _para;
				sleep 0.551;
			} forEach _real_units;
			_paragrp allowFleeing 0;
			_paragrp setCombatMode "YELLOW";
			_paragrp setBehaviour "AWARE";
			
			[_paragrp, _current_target_pos, _cur_radius] spawn {
				private ["_grp", "_pos", "_rad"];
				PARAMS_3(_grp,_pos,_rad);
				sleep 20;
				if ((_grp call FUNC(GetAliveUnitsGrp)) > 0) then {
					[_grp, _pos, [_pos, _rad], [10, 20, 50], "call {private '_xxgrp';_xxgrp = this call d_fnc_getgroup; if ((_xxgrp call d_fnc_GetAliveUnitsGrp) > 1) then {[this] spawn d_fnc_searchNearby}}"] call FUNC(MakePatrolWPX);
					_grp setVariable [QGVAR(PATR),true];
					GVAR(reduce_groups) set [GVAR(reduce_groups), _grp];
				};
			};
			
			sleep 0.112;
			
			while {(_heliendpoint distance (leader _vgrp) > 300)} do {
				if (isNull _vehicle || !alive _vehicle || !alive _driver_vec || !canMove _vehicle) exitWith {};
				sleep 5.123;
			};
			
			if (!isNull _vehicle && (_heliendpoint distance _vehicle) > 300) then {
				[_crew_vec, _vehicle, 240 + random 100] spawn _delveccrew;
			} else {
				_vehicle call FUNC(DelVecAndCrew);
			};
			if (!isNull _driver_vec) then {_driver_vec setDamage 1.1};
		};
	} else {
		[_crew_vec, _vehicle, 240 + random 100] spawn _delveccrew;
	};
};

_current_target_pos = GVAR(enemyai_mt_attack_pos);

#ifndef __TT__
if ((__XJIPGetVar(GVAR(searchintel)) select 0) == 1) then {
	GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"TellAirDropAttack",true];
};
#endif

for "_i" from 1 to _number_vehicles do {
	_new_current_target_pos = GVAR(enemyai_mt_attack_pos);
	__GetEGrp(_vgrp)
	_heli_type = GVAR(transport_chopper) call FUNC(RandomArrayVal);
	_spos = [_startpoint select 0, _startpoint select 1, 300];
	_cdir = [_spos, _attackpoint] call FUNC(DirTo);
	_veca = [_spos, _cdir, _heli_type, _vgrp] call FUNC(spawnVehicle);
	_vehicle = _veca select 0;
	if !((toUpper _heli_type) in GVAR(heli_wreck_lift_types)) then {__addDead(_vehicle)};
	if (GVAR(domdatabase)) then {
		_vehicle addMPEventHandler ["MPKilled", {if (isServer) then {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddChopperKillPoints)}}}];
	};
#ifdef __TT__
	_vehicle addEventHandler ["killed", {[8,_this select 1] call FUNC(AddKills)}];
#else
	if (!GVAR(banti_airdown)) then {_vehicle spawn FUNC(AirMarkerMove)};
#endif
	if (GVAR(with_ai)) then {
		if (__RankedVer) then {_vehicle addEventHandler ["killed", {[8,_this select 1] call FUNC(AddKillsAI)}]};
	};
	if (GVAR(LockAir) == 0) then {_vehicle lock true};
	sleep 5.012;
	
	_vehicle flyInHeight 100;
	
	[_vgrp,_vehicle,_attackpoint,_heliendpoint, _delveccrew] spawn _make_jump;
	
	sleep 40 + random 30;
};
