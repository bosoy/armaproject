// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_createmaintarget.sqf"
#include "x_setup.sqf"
private ["_type_list_guard", "_selectit", "_type_list_guard_static", "_type_list_patrol", "_type_list_guard_static2", "_trgobj", "_radius","_number_basic_guard", "_selectitmen", "_number_specops_guard","_number_tank_guard", "_selectitvec", "_number_bmp_guard", "_number_brdm_guard", "_number_uaz_mg_guard", "_number_uaz_grenade_guard", "_number_basic_patrol", "_selectitmen", "_number_specops_patrol", "_number_tank_patrol", "_number_bmp_patrol", "_number_brdm_patrol", "_number_uaz_mg_patrol", "_number_uaz_grenade_patrol", "_number_basic_guardstatic", "_number_specops_guardstatic", "_number_tank_guardstatic", "_number_bmp_guardstatic", "_number_shilka_guardstatic", "_number_DSHKM_guardstatic", "_number_AGS_guardstatic", "_trg_center", "_trgobj", "_wp_array", "_radius", "_xx", "_type_list_guard", "_typeidx", "_number_", "_xxx", "_wp_ran", "_type_list_guard_static", "_type_list_guard_static2", "_point", "_ccc", "_type_list_patrol", "_baseran", "_fbobjs", "_dgrp", "_unit_array", "_agrp", "_xx_ran", "_xpos", "_units", "_patrol_radius", "_wp_array_pat"];

if (!isServer) exitWith{};

_selectit = {(ceil (random (((_this select 0) select (_this select 1)) select 1)))};

_type_list_guard = [["basic",0],["specops",0],["tank",[GVAR(vehicle_numbers_guard), 0] call _selectit],["bmp",[GVAR(vehicle_numbers_guard), 1] call _selectit],["brdm",[GVAR(vehicle_numbers_guard), 2] call _selectit],["uaz_mg",[GVAR(vehicle_numbers_guard), 3] call _selectit],["uaz_grenade",[GVAR(vehicle_numbers_guard), 4] call _selectit]];

_type_list_guard_static = [["basic",0],["specops",0],["tank",[GVAR(vehicle_numbers_guard_static), 0] call _selectit],["bmp",[GVAR(vehicle_numbers_guard_static), 1] call _selectit],["shilka",[GVAR(vehicle_numbers_guard_static), 2] call _selectit]];

_type_list_patrol = [["basic",0],["specops",0],["tank",[GVAR(vehicle_numbers_patrol), 0] call _selectit],["bmp",[GVAR(vehicle_numbers_patrol), 1] call _selectit],["brdm",[GVAR(vehicle_numbers_patrol), 2] call _selectit],["uaz_mg",[GVAR(vehicle_numbers_patrol), 3] call _selectit],["uaz_grenade",[GVAR(vehicle_numbers_patrol), 4] call _selectit]];
_type_list_guard_static2 = [["DSHKM",1],["AGS",1]];

_selectit = nil;

if (!GVAR(dom4)) then {
	PARAMS_2(_trgobj,_radius);
	_patrol_radius = _radius + 400 + random 400;
} else {
	_trgobj = GVAR(enemyai_mt_start_pos);
	_radius = GVAR(target_radius);
	_patrol_radius = GVAR(mttarget_radius_patrol);
};

__TRACE_3("","_trgobj","_radius","_patrol_radius")

_selectitmen = {
	private ["_a_vng2","_num_ret"];
	_a_vng2 = (_this select 0) select (_this select 1);
	if ((_a_vng2 select 0) > 0) then {_num_ret = floor (random ((_a_vng2 select 0) + 1));if (_num_ret < (_a_vng2 select 1)) then {_a_vng2 select 1} else {_num_ret}} else {0}
};

_number_basic_guard = [GVAR(footunits_guard), 0] call _selectitmen;
_number_specops_guard = [GVAR(footunits_guard), 1] call _selectitmen;

_selectitvec = {
	private ["_a_vng","_a_vng2","_num_ret"];
	_a_vng = (_this select 0) select (_this select 1);
	_a_vng2 = _a_vng select 0;
	if ((_a_vng2 select 0) > 0) then {_num_ret = floor (random ((_a_vng2 select 0) + 1));if (_num_ret < (_a_vng2 select 1)) then {_a_vng2 select 1} else {_num_ret}} else {0}
};

_number_tank_guard = [GVAR(vehicle_numbers_guard),0] call _selectitvec;
_number_bmp_guard = [GVAR(vehicle_numbers_guard),1] call _selectitvec;
_number_brdm_guard = [GVAR(vehicle_numbers_guard),2] call _selectitvec;
_number_uaz_mg_guard = [GVAR(vehicle_numbers_guard),3] call _selectitvec;
_number_uaz_grenade_guard = [GVAR(vehicle_numbers_guard),4] call _selectitvec;
sleep 0.1;

_number_basic_patrol = [GVAR(footunits_patrol), 0] call _selectitmen;
_number_specops_patrol = [GVAR(footunits_patrol), 1] call _selectitmen;
_number_tank_patrol = [GVAR(vehicle_numbers_patrol),0] call _selectitvec;
_number_bmp_patrol = [GVAR(vehicle_numbers_patrol),1] call _selectitvec;
_number_brdm_patrol = [GVAR(vehicle_numbers_patrol),2] call _selectitvec;
_number_uaz_mg_patrol = [GVAR(vehicle_numbers_patrol),3] call _selectitvec;
_number_uaz_grenade_patrol = [GVAR(vehicle_numbers_patrol),4] call _selectitvec;
sleep 0.1;
_number_basic_guardstatic = [GVAR(footunits_guard_static), 0] call _selectitmen;
_number_specops_guardstatic = [GVAR(footunits_guard_static), 1] call _selectitmen;
_number_tank_guardstatic = [GVAR(vehicle_numbers_guard_static),0] call _selectitvec;
_number_bmp_guardstatic = [GVAR(vehicle_numbers_guard_static),1] call _selectitvec;
_number_shilka_guardstatic = [GVAR(vehicle_numbers_guard_static),2] call _selectitvec;
_number_DSHKM_guardstatic = ceil (random 4);
_number_AGS_guardstatic = ceil (random 3);
sleep 0.1;

_selectitmen = nil;
_selectitvec = nil;

_trg_center = if (typeName _trgobj == "OBJECT") then {position _trgobj} else {_trgobj};
_wp_array = [_trg_center, _radius] call FUNC(getwparray);
_wp_array_pat = [_trg_center, _patrol_radius] call FUNC(getwparray);
__TRACE_1("","_wp_array")
__TRACE_1("","_wp_array_pat")

sleep 0.112;

for "_xx" from 0 to (count _type_list_guard - 1) do {
	_typeidx = _type_list_guard select _xx;
	_nums = call compile format ["_number_%1_guard", _typeidx select 0];
	if (_nums > 0) then {
		for "_xxx" from 1 to _nums do {
			_wp_ran = (count _wp_array) call FUNC(RandomFloor);
			[_typeidx select 0, [_wp_array select _wp_ran], _trg_center, _typeidx select 1, "guard", GVAR(enemy_side),0,-1.111,1,[_trg_center, _radius]] call FUNC(makegroup);
			_wp_array set [_wp_ran, -1];
			_wp_array = _wp_array - [-1];
			sleep 0.4;
		};
	};
};

sleep 0.233;

for "_xx" from 0 to (count _type_list_guard_static - 1) do {
	_typeidx = _type_list_guard_static select _xx;
	_nums = call compile format ["_number_%1_guardstatic", _typeidx select 0];
	if (_nums > 0) then {
		for "_xxx" from 1 to _nums do {
			_wp_ran = (count _wp_array) call FUNC(RandomFloor);
			[_typeidx select 0, [_wp_array select _wp_ran], _trg_center, _typeidx select 1, "guardstatic",GVAR(enemy_side),0,-1.111,1,[_trg_center, _radius]] call FUNC(makegroup);
			_wp_array set [_wp_ran, -1];
			_wp_array = _wp_array - [-1];
			sleep 0.4;
		};
	};
};

for "_xx" from 0 to (count _type_list_guard_static2 - 1) do {
	_typeidx = _type_list_guard_static2 select _xx;
	_nrgs = call compile format["_number_%1_guardstatic;", _typeidx select 0];
	if (_nrgs > 0) then {
		for "_xxx" from 1 to _nrgs do {
			_point = [_trg_center, _radius] call FUNC(GetRanPointCircleBig);
			_ccc = 0;
			while {count _point == 0 && _ccc < 100} do {
				_point = [_trg_center, _radius] call FUNC(GetRanPointCircleBig);
				__INC(_ccc);
				sleep 0.01;
			};
			[_typeidx select 0, [_point], _trg_center, _typeidx select 1, "guardstatic2",GVAR(enemy_side),0,-1.111,1,[_trg_center, _radius]] call FUNC(makegroup);
			sleep 0.1;
		};
	};
};

GVAR(delfirebase_objects) = [];
GVAR(ai_artiller_unit_vecs) = [];
#ifndef __TT__
_baseran = floor (random 4);
if (_baseran < 1) then {_baseran = 1};

for "_xxx" from 1 to _baseran do {
	_point = [_trg_center, _radius] call FUNC(GetRanPointCircleBig);
	if (isOnRoad _point) then {_point = []};
	_ccc = 0;
	while {count _point == 0 && _ccc < 100} do {
		_point = [_trg_center, _radius] call FUNC(GetRanPointCircleBig);
		if (isOnRoad _point) then {_point = []};
		__INC(_ccc);
	};
	if (count _point > 0) then {
		_fbobjs = [_point, random 360, GVAR(firebase)] call FUNC(objectMapper);
		sleep 0.1;
		{
			if (!(_x isKindOf "Air") && !(_x isKindOf "Car") && !(_x isKindOf "Tank")) then {
				GVAR(delfirebase_objects) set [count GVAR(delfirebase_objects), _x]
			} else {
				if (_x isKindOf "StaticCannon") then {
					GVAR(ai_artiller_unit_vecs) set [count GVAR(ai_artiller_unit_vecs), _x];
					GVAR(delfirebase_objects) set [count GVAR(delfirebase_objects), _x];
					_x lock true;
				};
			};
			__addDead(_x)
		} forEach _fbobjs;
		sleep 0.1;
		_dgrp = [GVAR(side_enemy)] call FUNC(creategroup);
		_unit_array = ["basic", GVAR(enemy_side)] call FUNC(getunitliste);
		[_point, _unit_array select 0, _dgrp,true] spawn FUNC(makemgroup);
		sleep 0.4;
		_dgrp setVariable [QGVAR(defend), true];
		[_dgrp, _point] spawn FUNC(taskDefend);
		GVAR(reduce_groups) set [count GVAR(reduce_groups), _dgrp];
	};
	sleep 0.5;
};
#endif
if (random 1 > 0.6) then {
	_point = [_trg_center, _radius] call FUNC(GetRanPointCircleBig);
	if (isOnRoad _point) then {_point = []};
	_ccc = 0;
	while {count _point == 0 && _ccc < 100} do {
		_point = [_trg_center, _radius] call FUNC(GetRanPointCircleBig);
		if (isOnRoad _point) then {_point = []};
		__INC(_ccc);
	};
	if (count _point > 0) then {
		_mg = createVehicle ["Mass_grave", _point, [], 0, "NONE"];
		_mg setPos _point;
		GVAR(delfirebase_objects) set [count GVAR(delfirebase_objects), _mg];
	};
};
sleep 0.01;

for "_xx" from 0 to (count _type_list_patrol - 1) do {
	_typeidx = _type_list_patrol select _xx;
	_nums = call compile format ["_number_%1_patrol", _typeidx select 0];
	if (_nums > 0) then {
		for "_xxx" from 1 to _nums do {
			_wp_ran = (count _wp_array_pat) call FUNC(RandomFloor);
			[_typeidx select 0, [_wp_array_pat select _wp_ran], _trg_center, _typeidx select 1, if ((_typeidx select 0) in ["basic","specops"]) then {"patrol2mt"} else {"patrol"},GVAR(enemy_side),0,-1.111,1,[_trg_center, _patrol_radius]] call FUNC(makegroup);
			_wp_array_pat set [_wp_ran, -1];
			_wp_array_pat = _wp_array_pat - [-1];
			sleep 0.4;
		};
	};
};

_type_list_guard = nil;
_type_list_guard_static = nil;
_type_list_guard_static2 = nil;
_type_list_patrol = nil;

sleep 2.124;

if (GVAR(WithEnemyArtySpotters) == 0 && !GVAR(no_more_observers)) then {
	GVAR(nr_observers) = floor random 4;
	if (GVAR(nr_observers) < 2) then {GVAR(nr_observers) = 2};

	GVAR(obs_array) = [objNull, objNull, objNull];
	_unit_array = ["artiobserver", GVAR(enemy_side)] call FUNC(getunitliste);
	for "_xx" from 0 to GVAR(nr_observers) - 1 do {
		__GetEGrp(_agrp)
		_xx_ran = (count _wp_array) call FUNC(RandomFloor);
		_xpos = _wp_array select _xx_ran;
		_wp_array set [_xx_ran, -1];
		_wp_array = _wp_array - [-1];
		_units = [_xpos, _unit_array select 0, _agrp, true] call FUNC(makemgroup);
		[_agrp, _xpos, [_trg_center, _radius], [5, 20, 40]] spawn FUNC(MakePatrolWPX);
		_agrp setVariable [QGVAR(PATR),true];
		_observer = _units select 0;
		_observer addEventHandler ["killed", {GVAR(nr_observers) = GVAR(nr_observers) - 1;
			if (GVAR(nr_observers) == 0) then {
#ifndef __TT__
				GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"AllObserversDown",true];
#else
				GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","AllObserversDown",true];
				GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","AllObserversDown",true];
#endif
			}
		}];
		GVAR(obs_array) set [_xx, _observer];
		sleep 0.4;
	};
	_unit_array = nil;

#ifndef __TT__
	GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"TellNrObservers",["1","",str(GVAR(nr_observers)),[]],true];
#else
	GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","TellNrObservers",["1","",str(GVAR(nr_observers)),[]],true];
	GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","TellNrObservers",["1","",str(GVAR(nr_observers)),[]],true];
#endif
	execVM "x_server\x_handleobservers.sqf";
	sleep 1.214;
};

if (!GVAR(dom4)) then {
	[_wp_array, GVAR(target_radius), _trg_center] execVM "x_server\x_createsecondary.sqf";
} else {
	[_wp_array, GVAR(target_radius), _trg_center] execVM "x_server\x_createsecondary2.sqf";
};

#ifndef __TT__
execFSM "fsms\RespawnGroups.fsm";
#endif

if (GVAR(IllumMainTarget) == 0) then {
	GVAR(run_illum) = true;
	[_trg_center, _radius] execFSM "fsms\Illum.fsm";
};

_wp_array_pat = nil;