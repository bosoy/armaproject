// by Xeno
#define THIS_FILE "x_target_clear_client.sqf"
#include "x_setup.sqf"
private ["_current_target_name","_target_array2","_extra_bonusn"];

if (!X_Client) exitWith {};

_extra_bonusn = _this;

__TargetInfo

_current_target_name setMarkerColorLocal "ColorGreen";

if (!isNil QGVAR(task1)) then {GVAR(task1) setTaskState "Succeeded"};

if (!isNil QGVAR(current_task)) then {
	GVAR(current_task) setTaskState "Succeeded";
	[GVAR(current_task), "SUCCEEDED"] spawn FUNC(TaskHint);
};

if (count __XJIPGetVar(resolved_targets) < GVAR(MainTargets)) then {
	_bonus_pos = (localize "STR_DOM_MISSIONSTRING_569");
	
	_mt_str = format [(localize "STR_DOM_MISSIONSTRING_570"), _current_target_name];
#ifndef __TT__
	if (_extra_bonusn != "") then {
		_bonus_string = format[(localize "STR_DOM_MISSIONSTRING_571"), [_extra_bonusn, 0] call FUNC(GetDisplayName), _bonus_pos];
		
		hint composeText[
			parseText("<t color='#f02b11ed' size='1'>" + _mt_str + "</t>"), lineBreak,lineBreak,
			(localize "STR_DOM_MISSIONSTRING_572"), lineBreak,lineBreak,
			_bonus_string, lineBreak,lineBreak,
			(localize "STR_DOM_MISSIONSTRING_573")
		];
	} else {
		hint composeText[
			parseText("<t color='#f02b11ed' size='1'>" + _mt_str + "</t>"), lineBreak,lineBreak,
			(localize "STR_DOM_MISSIONSTRING_572"), lineBreak,lineBreak,
			(localize "STR_DOM_MISSIONSTRING_573")
		];
	};
	
	if (GVAR(with_ranked)) then {
		_current_target_pos = _target_array2 select 0;
		if (player distance _current_target_pos < (GVAR(ranked_a) select 10)) then {
			(format [(localize "STR_DOM_MISSIONSTRING_574"), GVAR(ranked_a) select 9]) call FUNC(HQChat);
			0 spawn {
				sleep (0.5 + random 2);
				[QGVAR(pas), [player, GVAR(ranked_a) select 9]] call FUNC(NetCallEventCTS);
			};
		};
	};
#else
	_points_array = __XJIPGetVar(points_array);
	_kill_points_west = _points_array select 2;
	_kill_points_east = _points_array select 3;
	_winner_string = switch (GVAR(mt_winner)) do {
		case 1: {format [(localize "STR_DOM_MISSIONSTRING_575"),_kill_points_west,_kill_points_east, GVAR(tt_points) select 0]};
		case 2: {format [(localize "STR_DOM_MISSIONSTRING_576"),_kill_points_east,_kill_points_west, GVAR(tt_points) select 0]};
		case 3: {format [(localize "STR_DOM_MISSIONSTRING_577"),_kill_points_east, GVAR(tt_points) select 1]};
		default {""};
	};
	_team = switch (GVAR(mt_winner)) do {
		case 1: {(localize "STR_DOM_MISSIONSTRING_578")};
		case 2: {(localize "STR_DOM_MISSIONSTRING_579")};
		case 3: {(localize "STR_DOM_MISSIONSTRING_580")};
		default {(localize "STR_DOM_MISSIONSTRING_581")};
	};
	
	_vecnn = switch (GVAR(player_side)) do {
		case west: {_extra_bonusn select 0};
		case east: {_extra_bonusn select 1};
		default {""};
	};
	if (_vecnn != "") then {
		_bonus_string = format[(localize "STR_DOM_MISSIONSTRING_582"), _team, _bonus_pos];
		
		hint composeText[
			parseText("<t color='#f02b11ed' size='1'>" + _mt_str + "</t>"), lineBreak,lineBreak,
			(localize "STR_DOM_MISSIONSTRING_572"), lineBreak,lineBreak,
			_bonus_string, lineBreak,lineBreak,
			(localize "STR_DOM_MISSIONSTRING_573")
		];
	} else {
		hint composeText[
			parseText("<t color='#f02b11ed' size='1'>" + _mt_str + "</t>"), lineBreak,lineBreak,
			(localize "STR_DOM_MISSIONSTRING_572"), lineBreak,lineBreak,
			(localize "STR_DOM_MISSIONSTRING_573")
		];
	};
	
	titleText [_winner_string, "PLAIN"];
	
	if (GVAR(with_ranked)) then {
		_current_target_pos = _target_array2 select 0;
		if (player distance _current_target_pos < 400) then {
			(format [(localize "STR_DOM_MISSIONSTRING_574"), GVAR(ranked_a) select 9]) call FUNC(HQChat);
			0 spawn {
				sleep (0.5 + random 2);
				[QGVAR(pas), [player, GVAR(ranked_a) select 9]] call FUNC(NetCallEventCTS);
			};
		};
	};
#endif
} else {
	_mt_str = format [(localize "STR_DOM_MISSIONSTRING_570"), _current_target_name];
#ifndef __TT__
	hint  composeText[
		parseText("<t color='#f02b11ed' size='1'>" + _mt_str + "</t>"), lineBreak,lineBreak,
		(localize "STR_DOM_MISSIONSTRING_572")
	];
#else
	_points_array = __XJIPGetVar(points_array);
	_kill_points_west = _points_array select 2;
	_kill_points_east = _points_array select 3;
	_winner_string = switch (GVAR(mt_winner)) do {
		case 1: {format [(localize "STR_DOM_MISSIONSTRING_575"),_kill_points_west,_kill_points_east, GVAR(tt_points) select 0]};
		case 2: {format [(localize "STR_DOM_MISSIONSTRING_576"),_kill_points_east,_kill_points_west, GVAR(tt_points) select 0]};
		case 3: {format [(localize "STR_DOM_MISSIONSTRING_577"),_kill_points_east, GVAR(tt_points) select 1]};
		default {""};
	};
	hint  composeText[
		parseText("<t color='#f02b11ed' size='1'>" + _mt_str + "</t>"), lineBreak,lineBreak,
		(localize "STR_DOM_MISSIONSTRING_572")
	];
	titleText [_winner_string, "PLAIN"];
#endif
};

sleep 2;

if (!X_SPE) then {__XJIPSetVar [QGVAR(current_target_index), -1]};