// by Xeno
#include "x_setup.sqf"
#define THIS_FILE "x_createnexttarget.sqf"
private ["_current_target_pos","_current_target_radius","_dummy","_emptyH","_current_target_name"];
if (!isServer) exitWith{};

sleep 1;

GVAR(delvecsmt) = [];
GVAR(delinfsm) = [];
GVAR(respawn_ai_groups) = [];
GVAR(non_mt_respawn_ai_groups) = [];
GVAR(mt_done) = false;
if (!GVAR(dom4)) then {
	[QGVAR(current_target_index),GVAR(maintargets_list) select GVAR(current_counter)] call FUNC(NetSetJIP);
	__INC(GVAR(current_counter));

	sleep 1.0123;
	if (GVAR(first_time_after_start)) then {
		GVAR(first_time_after_start) = false;
		sleep 18.123;
	};

	GVAR(update_target) = false;
	GVAR(main_target_ready) = false;
	GVAR(side_main_done) = false;

	_dummy = GVAR(target_names) select __XJIPGetVar(GVAR(current_target_index));
	_current_target_pos = _dummy select 0;
	_current_target_name = _dummy select 1;
	_current_target_radius = _dummy select 2;

	GVAR(target_radius) = _current_target_radius;
	GVAR(mttarget_radius_patrol) = _current_target_radius + 400 + random 400;

	_tname = _current_target_name call FUNC(KBUseName);
	#ifndef __TT__
	_tsar = if (GVAR(WithLessArmor) == 0) then {
		["('Man' countType thislist >= d_man_count_for_target_clear) && ('Tank' countType thislist >= d_tank_count_for_target_clear) && ('Car' countType thislist  >= d_car_count_for_target_clear)", "X_JIPH setVariable ['target_clear',false,true];d_update_target=true;['d_update_target'] call d_fnc_NetCallEventToClients;d_kb_logic1 kbTell [d_kb_logic2,d_kb_topic_side,'Attack',['1','','" + _current_target_name + "',['" + _tname + "']],true];deleteVehicle d_check_trigger", ""]
	} else {
		["('Man' countType thislist >= d_man_count_for_target_clear)", "X_JIPH setVariable ['target_clear',false,true];d_update_target=true;['d_update_target'] call d_fnc_NetCallEventToClients;d_kb_logic1 kbTell [d_kb_logic2,d_kb_topic_side,'Attack',['1','','" + _current_target_name + "',['" + _tname + "']],true];deleteVehicle d_check_trigger;", ""]
	};
	#else
	_tsar = if (GVAR(WithLessArmor) == 0) then {
		["('Man' countType thislist >= d_man_count_for_target_clear) && ('Tank' countType thislist >= d_tank_count_for_target_clear) && ('Car' countType thislist  >= d_car_count_for_target_clear)", "X_JIPH setVariable ['target_clear',false,true];d_update_target=true;['d_update_target'] call d_fnc_NetCallEventToClients;d_hq_logic_en1 kbTell [d_hq_logic_en2,'HQ_W','Attack',['1','','" + _current_target_name + "',['" + _tname + "']],true];d_hq_logic_ru1 kbTell [d_hq_logic_ru2,'HQ_E','Attack',['1','','" + _current_target_name + "',['" + _tname + "']],true];deleteVehicle d_check_trigger", ""]
	} else {
		["('Man' countType thislist >= d_man_count_for_target_clear)", "X_JIPH setVariable ['target_clear',false,true];d_update_target=true;['d_update_target'] call d_fnc_NetCallEventToClients;d_hq_logic_en1 kbTell [d_hq_logic_en2,'HQ_W','Attack',['1','','" + _current_target_name + "',['" + _tname + "']],true];d_hq_logic_ru1 kbTell [d_hq_logic_ru2,'HQ_E','Attack',['1','','" + _current_target_name + "',['" + _tname + "']],true];deleteVehicle d_check_trigger", ""]
	};
	#endif

	GVAR(check_trigger) = [_current_target_pos, [_current_target_radius + 20, _current_target_radius + 20, 0, false], [GVAR(enemy_side), "PRESENT", false], _tsar] call FUNC(CreateTrigger);

	if !(__TTVer) then {	
		GVAR(enemyai_respawn_pos) = [getPosATL GVAR(FLAG_BASE), _current_target_pos] call FUNC(posbehind2); // startpoint for random camp location (if needed) plus direction
		if (surfaceIsWater (GVAR(enemyai_respawn_pos) select 0)) then {
			private ["_counter", "_tmppos", "_dirn"];
			_counter = 0;
			_tmppos = GVAR(enemyai_respawn_pos) select 0;
			while {surfaceIsWater _tmppos && _counter < 200} do {
				_tmppos = [_current_target_pos, ((random 1300) max 900)] call FUNC(GetRanPointCircleOuter);
				__INC(_counter);
			};
			if (surfaceIsWater _tmppos) then {
				//hint ((localize "STR_DOM_MISSIONSTRING_941") + _current_target_name + " found!!!!!");
				//diag_log ((localize "STR_DOM_MISSIONSTRING_941") + _current_target_name + " found!!!!!");
				_tmppos = _current_target_pos;
			};
			
			GVAR(enemyai_respawn_pos) set [0, _tmppos];
			_dirn = [_current_target_pos, _tmppos] call FUNC(DirTo);
			_dirn = _dirn + 180;
			GVAR(enemyai_respawn_pos) set [2, _dirn];
		};

		GVAR(enemyai_mt_camp_pos) = [GVAR(enemyai_respawn_pos) select 0, 600, 400, GVAR(enemyai_respawn_pos) select 1] call FUNC(GetRanPointSquare);
		#ifdef __GROUPDEBUG__
		if (str(markerPos QUOTE(enemyai_mt_camp_pos)) != "[0,0,0]") then {deleteMarkerLocal QUOTE(enemyai_mt_camp_pos)};
		[QUOTE(enemyai_mt_camp_pos),GVAR(enemyai_mt_camp_pos),"ICON","ColorBlack",[1,1],"enemy camp pos",0,"mil_dot"] call FUNC(CreateMarkerLocal);
		#endif
	};

	[_current_target_pos, _current_target_radius] execVM "x_server\x_createmaintarget.sqf";

	while {!GVAR(update_target)} do {sleep 2.123};

	#ifdef __TT__
	_tsar = ["(X_JIPH getVariable 'd_mt_radio_down') && d_side_main_done && ((X_JIPH getVariable 'd_campscaptured_e') == d_sum_camps || (X_JIPH getVariable 'd_campscaptured_w') == d_sum_camps) && ('Car' countType thislist <= d_car_count_for_target_clear) && ('Tank' countType thislist <= d_tank_count_for_target_clear) && ('Man' countType thislist <= d_man_count_for_target_clear)", "0 = [] execVM 'x_server\x_target_clear.sqf'", ""];
	#else
	_tsar = ["(X_JIPH getVariable 'd_mt_radio_down') && d_side_main_done && (X_JIPH getVariable 'd_campscaptured') == d_sum_camps && ('Car' countType thislist <= d_car_count_for_target_clear) && ('Tank' countType thislist <= d_tank_count_for_target_clear) && ('Man' countType thislist <= d_man_count_for_target_clear)", "0 = [] execVM 'x_server\x_target_clear.sqf'", ""];
	#endif

	GVAR(current_trigger) = [_current_target_pos, [_current_target_radius  + 50, _current_target_radius + 50, 0, false],[GVAR(enemy_side), "PRESENT", false], _tsar] call FUNC(CreateTrigger);

} else {
	GVAR(mt_defend_groups) = [];
	GVAR(mt_attack_groups) = [];
	_mtrd = __XJIPGetVar(GVAR(mt_radio_down));
	if (_mtrd) then {
		[QGVAR(mt_radio_down),false] call FUNC(NetSetJIP);
	};
	_cur_targets = __XJIPGetVar(GVAR(current_targets));
	__TRACE_1("","_cur_targets")
	_tar1 = format [QGVAR(target_%1), _cur_targets select 0];
	_tar2 = format [QGVAR(target_%1), _cur_targets select 1];
	_ct1ar = GV2(GVAR(targets_store),_tar1);
	_ct2ar = GV2(GVAR(targets_store),_tar2);
	_ct1 = __getMNsVar2(_tar1);
	_ct2 = __getMNsVar2(_tar2);

	__TRACE_2("","_tar1","_tar2")
	__TRACE_2("","_ct1","_ct2")

	GVAR(sum_camps) = -91;

	private ["_city_radius"];
	_city_radius = 300;
	if ((direction _ct1 < 90) || (direction _ct1 > 270)) then { // direction < 90 || > 270 = allways east side target
		GVAR(east_main_location) = _ct1;
		GVAR(east_main_location_pos) = _ct1ar select 1;
		GVAR(west_main_location) = _ct2;
		GVAR(west_main_location_pos) = _ct2ar select 1;
		// TODO: How to handle TT ?
		switch (GVAR(enemy_side)) do {
			case "EAST": {
				GVAR(enemyai_mt_start_pos) = _ct1ar select 1;
				GVAR(enemyai_mt_attack_pos) = _ct2ar select 1;
				_city_radius = _ct2ar select 4;
			};
			case "WEST": {
				GVAR(enemyai_mt_start_pos) = _ct2ar select 1;
				GVAR(enemyai_mt_attack_pos) = _ct1ar select 1;
				_city_radius = _ct1ar select 4;
			};
		};
	} else {
		GVAR(east_main_location) = _ct2;
		GVAR(east_main_location_pos) = _ct2ar select 1;
		GVAR(west_main_location) = _ct1;
		GVAR(west_main_location_pos) = _ct2ar select 1;
		switch (GVAR(enemy_side)) do {
			case "EAST": {
				GVAR(enemyai_mt_start_pos) = _ct2ar select 1;
				GVAR(enemyai_mt_attack_pos) = _ct1ar select 1;
				_city_radius = _ct1ar select 4;
			};
			case "WEST": {
				GVAR(enemyai_mt_start_pos) = _ct1ar select 1;
				GVAR(enemyai_mt_attack_pos) = _ct2ar select 1;
				_city_radius = _ct2ar select 4;
			};
		};
	};
	GVAR(enemyai_mt_start_pos) set [2,0];
	GVAR(enemyai_mt_attack_pos) set [2,0];
	GVAR(enemyai_respawn_pos) = [GVAR(enemyai_mt_attack_pos), GVAR(enemyai_mt_start_pos)] call FUNC(posbehind); // startpoint for random camp location (if needed) plus direction

	GVAR(enemyai_mt_camp_pos) = [GVAR(enemyai_respawn_pos) select 0, 600, 400, GVAR(enemyai_respawn_pos) select 1] call FUNC(GetRanPointSquare);
	#ifdef __GROUPDEBUG__
	[QUOTE(enemyai_mt_camp_pos),GVAR(enemyai_mt_camp_pos),"ICON","ColorBlack",[1,1],"enemy camp pos",0,"mil_dot"] call FUNC(CreateMarkerLocal);
	#endif

	GVAR(target_radius) = _city_radius;
	GVAR(mttarget_radius_patrol) = _city_radius + 400 + random 400;
	
	execVM "x_server\x_createmaintarget.sqf";
};
