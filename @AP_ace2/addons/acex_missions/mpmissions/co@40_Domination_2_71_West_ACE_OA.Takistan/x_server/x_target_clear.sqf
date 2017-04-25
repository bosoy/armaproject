// by Xeno
#define THIS_FILE "x_targetclear.sqf"
#include "x_setup.sqf"
private ["_current_target_pos","_dummy","_ran","_start_real"];
if (!isServer) exitWith{};

sleep 1.123;

if (!isNull GVAR(f_check_trigger)) then {deleteVehicle GVAR(f_check_trigger)};
#ifdef __TT__
if (!isNull GVAR(f_check_trigger2)) then {deleteVehicle GVAR(f_check_trigger2)};
#endif
deleteVehicle GVAR(current_trigger);
sleep 0.01;

__TargetInfo

#ifndef __TT__
GVAR(counterattack) = false;
_start_real = false;
_ran = random 100;
if (_ran > 96) then {
	GVAR(counterattack) = true;
	_start_real = true;	
	GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"CounterattackEnemy",["1","",_current_target_name,[]],true];
	execVM "x_server\x_counterattack.sqf";
};

while {GVAR(counterattack)} do {sleep 3.123};

if (_start_real) then {
	GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"CounterattackDefeated",true];
	sleep 2.321;
};
#endif

GVAR(old_target_pos) =+ ((GVAR(target_names) select __XJIPGetVar(GVAR(current_target_index))) select 0);
GVAR(old_radius) = [(GVAR(target_names) select __XJIPGetVar(GVAR(current_target_index))) select 2];

#ifndef __TT__
_resolved_targets = __XJIPGetVar(resolved_targets);
_resolved_targets set [count _resolved_targets, __XJIPGetVar(GVAR(current_target_index))];
["resolved_targets",_resolved_targets] call FUNC(NetSetJIP);
#endif

#ifdef __TT__
private ["_objects", "_wf", "_addpwest", "_addpeast"];
_objects = _wf nearEntities [["CAManBase", "Tank", "Car"], 12];
_addpwest = 0;
_addpeast = 0;
if (count _objects > 0) then {
	{
		if (alive _x) then {
			if (vehicle _x == _x) then {
				if (isPlayer _x) then {
					_x addScore (GVAR(tt_points) select 0);
					switch (side (group _x)) do {
						case west: {_addpwest = _addpwest + (GVAR(tt_points) select 0)};
						case east: {_addpeast = _addpeast + (GVAR(tt_points) select 0)};
					};
				};
			} else {
				{
					if (alive _x) then {
						if (isPlayer _x) then {
							_x addScore (GVAR(tt_points) select 0);
							switch (side (group _x)) do {
								case west: {_addpwest = _addpwest + (GVAR(tt_points) select 0)};
								case east: {_addpeast = _addpeast + (GVAR(tt_points) select 0)};
							};
						};
					};
				} forEach (crew _x);
			};
		};
	} forEach _objects;
};

GVAR(kill_points_west) = GVAR(kill_points_west) + _addpwest;
GVAR(kill_points_east) = GVAR(kill_points_east) + _addpeast;

if (GVAR(kill_points_west) > GVAR(kill_points_east)) then {
	GVAR(mt_winner) = 1;
	GVAR(points_west) = GVAR(points_west) + (GVAR(tt_points) select 0);
} else {
	if (GVAR(kill_points_east) > GVAR(kill_points_west)) then {
		GVAR(mt_winner) = 2;
		GVAR(points_east) = GVAR(points_east) + (GVAR(tt_points) select 0);
	} else {
		if (GVAR(kill_points_east) == GVAR(kill_points_west)) then {
			GVAR(mt_winner) = 3;
			GVAR(points_west) = GVAR(points_west) + (GVAR(tt_points) select 1);
			GVAR(points_east) = GVAR(points_east) + (GVAR(tt_points) select 1);
		};
	};
};
["points_array",[GVAR(points_west),GVAR(points_east),GVAR(kill_points_west),GVAR(kill_points_east)]] call FUNC(NetSetJIP);
_resolved_targets = __XJIPGetVar(resolved_targets);
_resolved_targets set [count _resolved_targets, [__XJIPGetVar(GVAR(current_target_index)),GVAR(mt_winner)]];
["resolved_targets",_resolved_targets] call FUNC(NetSetJIP);
[QGVAR(mt_winner), GVAR(mt_winner)] call FUNC(NetCallEventToClients);

sleep 0.5;
GVAR(public_points) = false;
#endif

if (!isNull GVAR(intel_unit)) then {
	deleteVehicle GVAR(intel_unit);
	GVAR(intel_unit) = objNull;
};

sleep 0.5;

if (GVAR(current_counter) < GVAR(MainTargets)) then {
	execVM "x_server\x_gettargetbonus.sqf";
} else {
	["target_clear",true] call FUNC(NetSetJIP);
#ifndef __TT__
	[QGVAR(target_clear), ""] call FUNC(NetCallEventToClients);
#else
	[QGVAR(target_clear), ["",""]] call FUNC(NetCallEventToClients);
#endif
	_tname = _current_target_name call FUNC(KBUseName);
#ifndef __TT__
	GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"Captured2",["1","",_current_target_name,[_tname]],true];
#else
	GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","Captured2",["1","",_current_target_name,[_tname]],true];
	GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","Captured2",["1","",_current_target_name,[_tname]],true];
#endif
};

sleep 2.123;

__XJIPGetVar(GVAR(current_target_index)) execFSM "fsms\DeleteUnits.fsm";

sleep 4.321;

#ifndef __TT__
if (GVAR(WithJumpFlags) == 1) then {
	if (GVAR(current_counter) < GVAR(MainTargets)) then {execVM "x_server\x_createjumpflag.sqf"};
};
#endif

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
	if (GVAR(MHQDisableNearMT) != 0) then {
		{
			if (alive _x) then {
				_fux = GV(_x,GVAR(vecfuelmhq));
				if (!isNil "_fux") then {
					if (fuel _x < _fux) then {
						[QGVAR(setFuel), [_x, _fux]] call FUNC(NetCallEventSTO);
					};
					_x setVariable [QGVAR(vecfuelmhq), nil, true];
				};
			};
		} forEach vehicles;
	};
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