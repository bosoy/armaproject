// by Xeno
#define THIS_FILE "x_targetclear4.sqf"
#include "x_setup.sqf"
private ["_current_target_pos","_dummy","_ran","_start_real"];
if (!isServer) exitWith{};

sleep 1.123;

_old_targets_idxar = [__XJIPGetVar(GVAR(current_targets)) select 0, __XJIPGetVar(GVAR(current_targets)) select 1];
_target_list = __XJIPGetVar(GVAR(targets_list));
_idx_one = _old_targets_idxar select 0;

_new_targets_idxar = [];

_mission_over = false;
_net_ar = [];

_tar1 = format [QGVAR(target_%1), _old_targets_idxar select 0];
_tar2 = format [QGVAR(target_%1), _old_targets_idxar select 1];
_ct1 = __getMNsVar2(_tar1);
_ct2 = __getMNsVar2(_tar2);

if (__XJIPGetVar(GVAR(campscaptured_w)) == d_sum_camps) then {
	// west
	__INC(GVAR(targets_west_won));
	if (GVAR(targets_west_won) == count _target_list) exitWith {
		_mission_over = true;
	};
	for "_i" from 0 to (count _target_list - 1) do {
		if (_target_list select _i == _idx_one) exitWith {
			_new_targets_idxar = [_target_list select (_i - 1), _target_list select _i];
			_ct1 setDir 220;
			_net_ar = [_old_targets_idxar select 1, "west"];
		};
	};
} else {
	// east
	__INC(GVAR(targets_east_won));
	if (GVAR(targets_east_won) == count _target_list) exitWith {
		_mission_over = true;
	};
	for "_i" from 0 to (count _target_list - 1) do {
		if (_target_list select _i == _idx_one) exitWith {
			_new_targets_idxar = [_target_list select (_i + 1), _target_list select (_i + 2)];
			_ct2 setDir 0;
			_net_ar = [_old_targets_idxar select 0, "east"];
		};
	};
};

if (_mission_over) exitWith {
	[QGVAR(the_end),true] call FUNC(NetSetJIP);
	// TODO: Change messages when the player side loses
	0 spawn FUNC(DomEnd);
};

[QGVAR(current_targets),_new_targets_idxar] call FUNC(NetSetJIP);
sleep 0.4;
[QGVAR(u_old_m), _net_ar] call FUNC(NetCallEvent);

// TODO create new respawn position

{
	_grpx = _x;
	_type = _grpx getVariable QGVAR(grptype);
	if (_type in ["DSHKM", "AGS", "D30"]) then {
		{if (alive _x) then {_x setDamage 1}} forEach units _grpx;
	} else {
		// move to new defend target
	};
} forEach GVAR(mt_defend_groups);

if (count GVAR(respawn_ai_groups) > 0) then {
	{
		{
			private "_v";
			_v = vehicle _x;
			if (_v != _x) then {if (alive _v) then {_v setDamage 1}};
			if (alive _x) then {_x setDamage 1}
		} forEach units (_x select 0)
	} forEach GVAR(respawn_ai_groups);
};

if (true) exitWith {};

// x_jiph getVariable "d_targets_list"
// [19,17,0,1,8,3,2,4,5,18,6,7,13,15,14,16,12,11,20,10,9]

// x_jiph getVariable "d_current_targets"
// [7,13]




GVAR(old_target_pos) =+ ((GVAR(target_names) select __XJIPGetVar(GVAR(current_target_index))) select 0);
GVAR(old_radius) = [(GVAR(target_names) select __XJIPGetVar(GVAR(current_target_index))) select 2];

__XJIPGetVar(GVAR(current_target_index)) execFSM "fsms\DeleteUnits.fsm";

sleep 4.321;




GVAR(del_camps_stuff) = [];
{
	_flag = _x getVariable QGVAR(FLAG);
	_mar = format [QGVAR(camp%1),_x getVariable QGVAR(INDEX)];
	deleteMarker _mar;
	GVAR(del_camps_stuff) set [count GVAR(del_camps_stuff), _x];
	GVAR(del_camps_stuff) set [count GVAR(del_camps_stuff), _flag];
} forEach __XJIPGetVar(GVAR(currentcamps));
[QGVAR(currentcamps),[]] call FUNC(NetSetJIP);
[QGVAR(campscaptured_w),0] call FUNC(NetSetJIP);
[QGVAR(campscaptured_e),0] call FUNC(NetSetJIP);

sleep 0.245;

if (GVAR(delete_mt_vehicles_after_time) != 0) then {
	[GVAR(old_target_pos),GVAR(old_radius)] execFSM "fsms\DeleteEmpty.fsm";
};

GVAR(run_illum) = false;

if (GVAR(current_counter) < GVAR(MainTargets)) then {
	sleep 15;
#ifdef __TT__
	GVAR(kill_points_west) = 0;
	GVAR(kill_points_east) = 0;
	GVAR(public_points) = true;
#endif
	execVM "x_server\x_createnexttarget.sqf";
} else {
#ifdef __TT__
	[QGVAR(the_end),true] call FUNC(NetSetJIP);
	0 spawn FUNC(DomEnd);
#else
	if (GVAR(WithRecapture) == 0) then {
		if (count GVAR(recapture_indices) == 0) then {
			[QGVAR(the_end),true] call FUNC(NetSetJIP);
			0 spawn FUNC(DomEnd);
		} else {
			0 spawn {
				while {count GVAR(recapture_indices) > 0} do {
					sleep 2.543;
				};
				[QGVAR(the_end),true] call FUNC(NetSetJIP);
				0 spawn FUNC(DomEnd);
			};
		};
	} else {
		[QGVAR(the_end),true] call FUNC(NetSetJIP);
		0 spawn FUNC(DomEnd);
	};
#endif
};