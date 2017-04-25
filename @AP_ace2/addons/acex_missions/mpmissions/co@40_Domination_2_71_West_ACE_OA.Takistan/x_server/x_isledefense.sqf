// by Xeno
#define THIS_FILE "x_isledefense.sqf"
#include "x_setup.sqf"
private ["_isle_grps", "_i", "_retval", "_make_isle_grp", "_igrpa", "_igrp", "_make_new", "_units","_posigrp", "_leader"];
if (!isServer) exitWith {};

sleep 35.321;

GVAR(old_old_start) = [0,0,0];
GVAR(isle_retval) = [];

_make_isle_grp = {
	private ["_units", "_start_point", "_dc", "_agrp", "_elist", "_vecs", "_rand", "_leader", "_grp_array", "_npos"];
	_units = [];
	_dc = 0;
	_start_point = [GVAR(with_isledefense) select 0,GVAR(with_isledefense) select 1,GVAR(with_isledefense) select 2,GVAR(with_isledefense) select 3] call FUNC(GetRanPointSquare);
	#ifndef __TT__
	while {(count _start_point < 3 || (_start_point distance GVAR(FLAG_BASE) < 2000) || (_start_point distance GVAR(old_old_start) < 500)) && _dc < 99} do {
	#else
	while {(count _start_point == 0 || (_start_point distance GVAR(WFLAG_BASE) < 1500) || (_start_point distance GVAR(EFLAG_BASE) < 1500) || _start_point distance GVAR(old_old_start) < 500) && _dc < 99} do {
	#endif
		_start_point = [GVAR(with_isledefense) select 0,GVAR(with_isledefense) select 1,GVAR(with_isledefense) select 2,GVAR(with_isledefense) select 3] call FUNC(GetRanPointSquare);
		sleep 0.353;
		__INC(_dc);
	};
	_start_point = _start_point call FUNC(WorldBoundsCheck);
	sleep 0.01;
	GVAR(old_old_start) = _start_point;
	__GetEGrp(_agrp)
	_elist = [GVAR(enemy_side)] call FUNC(getmixedliste);
	_vecs = [];
	_npos = _start_point;
	{
		_rand = floor random 2;
		if (_rand > 0) then {
			_reta = [_rand,_npos,_x select 0,_agrp,0,-1.111] call FUNC(makevgroup);
			_vecs = [_vecs, _reta select 0] call FUNC(arrayPushStack2);
			_units = [_units, _reta select 1] call FUNC(arrayPushStack2);
			sleep 0.73;
			_npos = ((_reta select 0) select 0) modelToWorld [0,-12,0];
		};
	} forEach _elist;
	_elist = nil;
	sleep 0.31;
	
	_agrp setVariable [QGVAR(PATR),true];
	_agrp setVariable [QGVAR(PATR_ISLE),true];
	[_agrp, _start_point, [GVAR(with_isledefense) select 0,GVAR(with_isledefense) select 1,GVAR(with_isledefense) select 2,GVAR(with_isledefense) select 3]] spawn FUNC(MakePatrolWPX);
#ifndef __TT__
	if ((__XJIPGetVar(GVAR(searchintel)) select 6) == 1) then {
		_agrp spawn FUNC(IsleDefMarkerMove);
	};
#endif
	GVAR(isle_retval) = [_agrp, _units, [0,0,0], _vecs];
};

_isle_grps = [];
for "_i" from 1 to (GVAR(with_isledefense) select 4) do {
	_retval = 0 spawn _make_isle_grp;
	waitUntil {sleep 0.212;scriptDone _retval};
	_isle_grps set [count _isle_grps, GVAR(isle_retval)];
	sleep 3.012;
};

while {true} do {
	__MPCheck;
	sleep 600 + random 600;
	{
		_igrp = _x select 0;
		_make_new = false;
		if (!isNull _igrp) then {
			if ((_igrp call FUNC(GetAliveUnitsGrp)) == 0) then {
				_make_new = true;
			} else {
				_posigrp = _x select 2;
				_leader = leader _igrp;
				if (!isNull _leader) then {
					if (_posigrp distance _leader < 100) then {
						_make_new = true;
					} else {
						_x set [2, position _leader];
					};
				};
			};
		} else {
			_make_new = true;
		};
		if (_make_new) then {
			_units = _x select 1;
			_vecs = _x select 3;
			{if (!isNull _x) then {_x call FUNC(DelVecAndCrew)};sleep 0.01} forEach _vecs;
			sleep 0.01;
			{if (!isNull _x) then {deleteVehicle _x};sleep 0.01} forEach _units;
			_units = nil;
			_vecs = nil;
			_retval = 0 spawn _make_isle_grp;
			waitUntil {sleep 0.212;scriptDone _retval};
			_isle_grps set [_forEachIndex, GVAR(isle_retval)];
			sleep 3.012;
		};
		sleep 100 + random 100;
	} forEach _isle_grps;
};