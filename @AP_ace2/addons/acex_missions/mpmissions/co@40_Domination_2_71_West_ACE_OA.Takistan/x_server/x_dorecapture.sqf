// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_dorecapture.sqf"
#include "x_setup.sqf"
private ["_radius", "_helih", "_veclist", "_unitslist", "_ulist", "_posran", "_grp", "_reta", "_vecs", "_i", "_units", "_completel", "_tname", "_vec","_target_center","_recap_index", "_counter"];

if (!isServer) exitWith	{};

PARAMS_4(_target_center,_radius,_recap_index,_helih);

__TRACE_3("","_target_center","_radius","_recap_index");
__TRACE_1("","_helih");

_veclist = [];
_unitslist = [];

{
	_ulist = [_x,GVAR(enemy_side)] call FUNC(getunitliste);
	__TRACE_1("vec","_ulist");
	_posran = [_target_center, _radius] call FUNC(GetRanPointCircleNoSlope);
	__TRACE_1("vec","_posran");
	_counter = 0;
	while {count _posran == 0 && _counter < 50} do {
		_posran = [_target_center, _radius] call FUNC(GetRanPointCircleNoSlope);
		__TRACE_1("in loop vec","_posran");
		__INC(_counter);
		sleep 0.4;
	};
	if (count _posran == 0) then {
		_posran = [_target_center, _radius] call FUNC(GetRanPointCircleOld);
	};
	_grp = [GVAR(side_enemy)] call FUNC(creategroup);
	_reta = [(2 call FUNC(RandomCeil)),_posran,_ulist select 1,_grp,0,-1.111] call FUNC(makevgroup);
	_vecs = _reta select 0;
	__TRACE_3("","_reta","_vecs","_grp");
	{_x lock true} forEach _vecs;
	sleep 0.1;
	_veclist = [_veclist, _vecs] call FUNC(arrayPushStack2);
	_unitslist = [_unitslist, _reta select 1] call FUNC(arrayPushStack2);
	__TRACE_2("","_veclist","_unitslist");
	sleep 0.1;
} forEach ["tank","bmp"];

__TRACE_2("","_veclist","_unitslist");

sleep 1.23;

for "_i" from 0 to 1 do {
	_ulist = ["basic",GVAR(enemy_side)] call FUNC(getunitliste);
	__TRACE_1("men","_ulist");
	_posran = [_target_center, _radius] call FUNC(GetRanPointCircleNoSlope);
	__TRACE_1("men","_posran");
	_counter = 0;
	 while {count _posran == 0 && _counter < 50} do {
		_posran = [_target_center, _radius] call FUNC(GetRanPointCircleNoSlope);
		__TRACE_1("in loop men","_posran");
		__INC(_counter);
		sleep 0.4;
	};
	if (count _posran == 0) then {
		_posran = [_target_center, _radius] call FUNC(GetRanPointCircleOld);
	};
	_grp = [GVAR(side_enemy)] call FUNC(creategroup);
	_units = [_posran,_ulist select 0,_grp] call FUNC(makemgroup);
	_unitslist = [_unitslist, _units] call FUNC(arrayPushStack);
	GVAR(reduce_groups) set [count GVAR(reduce_groups), _grp];
	__TRACE_3("","_units","_unitslist","_grp");
	sleep 0.1;
};

__TRACE_2("","_units","_unitslist");

sleep 10;

_completel = _unitslist;
_completel = [_completel, _veclist] call FUNC(arrayPushStack2);
__TRACE_1("","_completel");
while {(_completel call FUNC(GetAliveUnits)) > 5} do {
	#ifdef __DEBUG__
	diag_log [_completel call FUNC(GetAliveUnits)];
	#endif
	sleep 10.312
};

sleep 5;

_helih setVariable [QGVAR(recaptured), nil, true];

GVAR(recapture_indices) = GVAR(recapture_indices) - [_recap_index];

[QGVAR(recaptured), [_recap_index, 1]] call FUNC(NetCallEventToClients);
_target_array = GVAR(target_names) select _recap_index;
_target_name = _target_array select 1;
_tname = _target_name call FUNC(KBUseName);
GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"Captured3",["1","",_target_name,[_tname]],true];

sleep 300;

{
	if (!isNull _x) then {
		_vec = _x;
		_vec call FUNC(DelVecAndCrew);
	};
} forEach _veclist;

{if (!isNull _x) then {if (!isNull _x) then {deleteVehicle _x}}} forEach _unitslist;
_unitslist = nil;
_veclist = nil;