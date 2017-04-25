// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_serverfuncs.sqf"
#include "x_setup.sqf"

#ifdef __TT__
#define __addpw(wpoints) GVAR(points_west) = GVAR(points_west) + wpoints
#define __addpe(epoints) GVAR(points_east) = GVAR(points_east) + epoints

// gameplay change:
// _points is now an array
// [points if the killer (player) is infantry unit, points if the killer is inside an APC, points if the killer is inside a tank, points if the player is inside an air vehicle]
// now, the lowest points number should be given for air vehicles and the highest for inf units
// second change: distance to target, the lower the higher, Only for infantry!!!!
FUNC(AddKills) = {
	private ["_points","_killer","_killed","_vec","_dist","_endpoints","_coef"];
	PARAMS_3(_points,_killer,_killed);
	if (isNull _killer || {!isPlayer _killer}) exitWith {};
	_vec = vehicle _killer;
	_endpoints = if (_vec == _killer) then {
		_dist = if (isNull _killed) then {500} else {_killed distance _killer};
		if (_dist < 0) then {_dist = 500};
		_coef = switch (true) do {
			case (_dist < 20): {3};
			case (_dist < 70): {2};
			default {1};
		};
		_killer addScore round ((_points select 0) / 5);
		((_points select 0) * _coef)
	} else {
		switch (true) do {
			case (_vec isKindOf "Wheeled_APC"): {_points select 1};
			case (_vec isKindOf "Tank"): {_points select 2};
			case (_vec isKindOf "Air"): {_points select 3};
			default {1};
		};
	};
	switch (side (group _killer)) do {
		case west: {__addkpw(_endpoints)};
		case east: {__addkpe(_endpoints)};
	};
};
FUNC(AddPoints) = {
	private ["_points","_killer"];
	if (!isPlayer _killer) exitWith {};
	PARAMS_2(_points,_killer);
	switch (side (group _killer)) do {
		case west: {__addpw(_points)};
		case east: {__addpe(_points)};
	};
	_killer addScore _points;
};

FUNC(TTAddKEH) = {
	(_this select 0) addEventHandler ["killed", {
		[5, _this select 1] call FUNC(AddPoints);
	}];
};
#endif

if (GVAR(domdatabase)) then {
	// TODO: Add kills to array to count all kills for stats dialog
	// something like: Overall AI killed on the server, radio towers destroyed on the server, etc, etc
	FUNC(PAddAIKillPoints) = {
		private ["_uid", "_pa"];
		_uid = getPlayerUID _this;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			_pa set [19, (_pa select 19) + 1];
		};
	};
	
	FUNC(PAddHumKillPoints) = {
		private ["_uid", "_pa"];
		_uid = getPlayerUID _this;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			_pa set [20, (_pa select 20) + 1];
		};
	};
	
	FUNC(PAddCarKillPoints) = {
		private ["_uid", "_pa"];
		_uid = getPlayerUID _this;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			_pa set [21, (_pa select 21) + 1];
		};
	};
	
	FUNC(PAddAPCKillPoints) = {
		private ["_uid", "_pa"];
		_uid = getPlayerUID _this;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			_pa set [22, (_pa select 22) + 1];
		};
	};
	
	FUNC(PAddTankKillPoints) = {
		private ["_uid", "_pa"];
		_uid = getPlayerUID _this;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			_pa set [23, (_pa select 23) + 1];
		};
	};
	
	FUNC(PAddPlaneKillPoints) = {
		private ["_uid", "_pa"];
		_uid = getPlayerUID _this;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			_pa set [24, (_pa select 24) + 1];
		};
	};
	
	FUNC(PAddChopperKillPoints) = {
		private ["_uid", "_pa"];
		_uid = getPlayerUID _this;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			_pa set [25, (_pa select 25) + 1];
		};
	};
	
	FUNC(PAddRadioTowerKillPoints) = {
		private ["_uid", "_pa"];
		_uid = getPlayerUID _this;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			_pa set [26, (_pa select 26) + 1];
		};
	};
	
	FUNC(PAddMTObjKillPoints) = {
		private ["_uid", "_pa"];
		_uid = getPlayerUID _this;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			_pa set [27, (_pa select 27) + 1];
		};
	};
	
	FUNC(PAddSMResolvedPoints) = {
		private ["_uid", "_pa"];
		_uid = getPlayerUID _this;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			_pa set [28, (_pa select 28) + 1];
		};
	};
	
	FUNC(PAddUnconKilledPoints) = {
		private ["_uid", "_pa"];
		_uid = getPlayerUID _this;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			_pa set [29, (_pa select 29) + 1];
		};
	};
	
	FUNC(PAddTeamKillPoints) = {
		private ["_uid", "_pa"];
		_uid = getPlayerUID _this;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			_pa set [16, (_pa select 16) + 1];
		};
	};
};

if (GVAR(with_ai)) then {
	if (__RankedVer) then {
		FUNC(AddKillsAI) = {
			private ["_points","_killer"];
			PARAMS_2(_points,_killer);
			if (!isPlayer _killer && {side (group _killer) != GVAR(side_enemy)}) then {[QGVAR(ai_kill), [_killer,_points]] call FUNC(NetCallEventToClients)}
		};
	};
};

#ifdef __GROUPDEBUG__
FUNC(map_group_count_marker) = {
	_mname = "all_groups_yeah";
	_mtext = "Groups: %1, alive units: %2, inf without leader: %3";
	[_mname, [3000,0,0],"ICON","ColorBlack",[2,2],format [_mtext, 0,0],0,"mil_dot"] call FUNC(CreateMarkerLocal);
	while {true} do {
		GVAR(all_marker_groups) = GVAR(all_marker_groups) - [objNull, grpNull];
		_grpcounter = count GVAR(all_marker_groups);
		_units = 0;
		_remgrps = [];
		{
			_alu = _x call FUNC(GetAliveUnitsGrp);
			if (_alu > 0) then {
				_units = _units + _alu;
			} else {
				_remgrps set [count _remgrps, _x];
			};
		} forEach GVAR(all_marker_groups);
		if (count _remgrps > 0) then {
			GVAR(all_marker_groups) = GVAR(all_marker_groups) - _remgrps;
		};
		_mname setMarkerTextLocal format [_mtext, _grpcounter,_units, GVAR(infunitswithoutleader)];
		sleep 1;
	};
};

GVAR(gcounter) = -1;
GVAR(infunitswithoutleader) = 0;
FUNC(groupmarker) = {
	private ["_grp", "_mname", "_mnamel", "_leader", "_p1", "_wps", "_idx", "_curwppos", "_gname"];
	PARAMS_1(_grp);
	waitUntil {sleep 0.221;(_grp call FUNC(GetAliveUnitsGrp)) > 0};
	_helper = str(_grp);
	_gname = if (_helper != "") then {_helper} else {__INC(GVAR(gcounter));str(GVAR(gcounter))};
	_mname = _gname + "dgrp";
	_mnamel = _mname + "lm";
	_mnamewp = _mname + "wpm";
	_gname = _gname;
	sleep 1;
	GVAR(all_marker_groups) set [count GVAR(all_marker_groups), _grp];
	_vec = vehicle leader _grp;
	_mtype = if (_vec == leader _grp) then {
		if (side _grp == west) then {"b_inf"} else {"o_inf"}
	} else {
		switch (true) do {
			case (_vec isKindOf "Wheeled_APC"): {if (side _grp == west) then {"b_mech_inf"} else {"o_mech_inf"}};
			case (_vec isKindOf "Car"): {if (side _grp == west) then {"b_motor_inf"} else {"o_motor_inf"}};
			case (_vec isKindOf "Tank"): {if (side _grp == west) then {"b_armor"} else {"o_armor"}};
			case (_vec isKindOf "Helicopter"): {if (side _grp == west) then {"b_air"} else {"o_air"}};
			case (_vec isKindOf "Plane"): {if (side _grp == west) then {"b_plane"} else {"o_plane"}};
			case (_vec isKindOf "StaticCannon"): {if (side _grp == west) then {"b_art"} else {"o_art"}};
			case (_vec isKindOf "StaticMortar"): {if (side _grp == west) then {"b_mortar"} else {"o_mortar"}};
			default {if (side _grp == west) then {"b_support"} else {"n_support"}};
		}
	};
	[_mname, [0,0,0],"ICON",(if (side _grp == east) then {"ColorRed"} else {"ColorBlue"}),[0.8,0.8],_gname,0,_mtype] call FUNC(CreateMarkerLocal);
	_gname = _gname + " (%1)";
	while {true} do {
		if (isNull _grp || (_grp call FUNC(GetAliveUnitsGrp)) == 0) exitWith {
			deleteMarkerLocal _mname;
			deleteMarkerLocal _mnamel;
			deleteMarkerLocal _mnamewp;
		};
		_leader = leader _grp;
		if (!isNull _leader) then {
			_p1 = getPosASL _leader;
			_p1 set [2,0];
			_mname setMarkerPosLocal _p1;
			_mname setMarkerTextLocal format [_gname, _grp call FUNC(GetAliveUnitsGrp)];
			_wps = waypoints _grp;
			_idx = currentWaypoint _grp;
			if (_idx < count _wps && _idx > 0) then {
				_curwppos = waypointPosition (_wps select _idx);
				_curwppos set [2,0];
				_mpos = markerPos _mnamewp;
				if ((_mpos select 0) == 0 &&  (_mpos select 1) == 0 && (_mpos select 2) == 0) then {
					[_mnamewp,_curwppos,"ICON","ColorGreen",[0.7, 0.7],"",0,"waypoint"] call FUNC(CreateMarkerLocal);
				} else {
					_mnamewp setMarkerPosLocal _curwppos;
				};
				[_p1, _curwppos, _mnamel] call FUNC(linemaker2);
			} else {
				deleteMarkerLocal _mnamel;
				deleteMarkerLocal _mnamewp;
			};
		} else {
			deleteMarkerLocal _mnamel;
			deleteMarkerLocal _mnamewp;
		};
		sleep (0.6 + random 0.2);
	};
};
#endif

FUNC(creategroup) = {
	private ["_grp","_side","_side_str"];
	PARAMS_1(_side);
	_side_str = if (typeName _side == "STRING") then {_side call FUNC(StoreGet)} else {_side};
	_grp = createGroup _side_str;
	// GVAR(gstate)
	// 0 = created
	// 1 = filled with units
	// 2 = reduced
	_grp setVariable [QGVAR(gstate), 0];
	#ifdef __GROUPDEBUG__
	if (isNil QGVAR(all_marker_groups)) then {
		GVAR(all_marker_groups) = [];
		0 spawn FUNC(map_group_count_marker);
	};
	[_grp] spawn FUNC(groupmarker);
	#endif
	_grp
};

FUNC(getwparray) = {
	private["_tc", "_radius","_wp_a","_point"];
	PARAMS_2(_tc,_radius);
	_wp_a = [];_wp_a resize 100;
	for "_i" from 0 to 99 do {
		_point = [_tc, _radius] call FUNC(GetRanPointCircle);
		if (count _point == 0) then {
			for "_e" from 0 to 99 do {_point = [_pos_center, _radius] call FUNC(GetRanPointCircle);if (count _point > 0) exitWith {}};
		};
		_wp_a set [_i, _point];
	};
	_wp_a
};

FUNC(getwparray2) = {
	private["_tc", "_radius","_wp_a","_point"];
	PARAMS_2(_tc,_radius);
	_wp_a = [];_wp_a resize 100;
	for "_i" from 0 to 99 do {
		_point = [_tc, _radius] call FUNC(GetRanPointCircleOuter);
		if (count _point == 0) then {
			for "_e" from 0 to 99 do {_point = [_tc, _radius] call FUNC(GetRanPointCircleOuter);if (count _point > 0) exitWith {}};
		};
		_wp_a set [_i, _point];
	};
	_wp_a
};

FUNC(getwparray3) = {
	private ["_pos","_a","_b","_angle","_wp_a","_point"];
	PARAMS_4(_pos,_a,_b,_angle);
	_wp_a = [];_wp_a resize 100;
	for "_i" from 0 to 99 do {
		_point = [_pos, _a, _b, _angle] call FUNC(GetRanPointSquare);
		if (count _point == 0) then {
			for "_e" from 0 to 99 do {_point = [_pos, _a, _b, _angle] call FUNC(GetRanPointSquare);if (count _point > 0) exitWith {}};
		};
		_wp_a set [_i, _point];
	};
	_wp_a
};

FUNC(getunitliste) = {
	private ["_grptype","_how_many","_list","_one_man","_side","_side_char","_unitliste","_vehiclename","_varray"];
	PARAMS_2(_grptype,_side);
	_unitliste = [];_vehiclename = "";_varray = [];
	_side_char = if (typeName _side == "STRING") then {
		switch (_side) do {case "EAST": {"E"};case "WEST": {"W"};case "GUER": {"G"};case "CIV": {"W"};}
	} else {
		switch (_side) do {case east: {"E"};case west: {"W"};case resistance: {"G"};case civilian: {"W"};}
	};
	switch (_grptype) do {
		case "basic": {_list = missionNamespace getVariable format [QGVAR(allmen_%1),_side_char];_unitliste = _list call FUNC(RandomArrayVal)};
		case "specops": {_how_many = ceil random 5; if (_how_many < 2) then {_how_many = 2};_list = missionNamespace getVariable format [QGVAR(specops_%1),_side_char];_unitliste resize _how_many;for "_i" from 0 to _how_many - 1 do {_unitliste set [_i, _list call FUNC(RandomArrayVal)]}};
		case "artiobserver": {_unitliste = [missionNamespace getVariable format[QGVAR(arti_observer_%1),_side_char]]};
		case "heli": {_list = missionNamespace getVariable format [QGVAR(allmen_%1),_side_char];_unitliste = _list call FUNC(RandomArrayVal)};
		case "tank": {_varray = (missionNamespace getVariable format [QGVAR(veh_a_%1), _side_char]) select 0;_vehiclename = _varray call FUNC(RandomArrayVal)};
		case "bmp": {_varray = (missionNamespace getVariable format [QGVAR(veh_a_%1), _side_char]) select 1;_vehiclename = _varray call FUNC(RandomArrayVal)};
		case "brdm": {_varray = (missionNamespace getVariable format [QGVAR(veh_a_%1), _side_char]) select 2;_vehiclename = _varray call FUNC(RandomArrayVal)};
		case "shilka": {_varray = (missionNamespace getVariable format [QGVAR(veh_a_%1), _side_char]) select 3;_vehiclename = _varray call FUNC(RandomArrayVal)};
		case "uaz_mg": {_varray = (missionNamespace getVariable format [QGVAR(veh_a_%1), _side_char]) select 4;_vehiclename = _varray call FUNC(RandomArrayVal)};
		case "uaz_grenade": {_varray = (missionNamespace getVariable format [QGVAR(veh_a_%1), _side_char]) select 5;_vehiclename = _varray call FUNC(RandomArrayVal)};
		case "DSHKM": {_varray = (missionNamespace getVariable format [QGVAR(veh_a_%1), _side_char]) select 6;_vehiclename = _varray call FUNC(RandomArrayVal)};
		case "AGS": {_varray = (missionNamespace getVariable format [QGVAR(veh_a_%1), _side_char]) select 7;_vehiclename = _varray call FUNC(RandomArrayVal)};
		case "D30": {_varray = (missionNamespace getVariable format [QGVAR(veh_a_%1), _side_char]) select 8;_vehiclename = _varray call FUNC(RandomArrayVal)};
		case "uralfuel": {_varray = (missionNamespace getVariable format [QGVAR(veh_a_%1), _side_char]) select 9;_vehiclename = _varray call FUNC(RandomArrayVal)};
		case "uralrep": {_varray = (missionNamespace getVariable format [QGVAR(veh_a_%1), _side_char]) select 10;_vehiclename = _varray call FUNC(RandomArrayVal)};
		case "uralammo": {_varray = (missionNamespace getVariable format [QGVAR(veh_a_%1), _side_char]) select 11;_vehiclename = _varray call FUNC(RandomArrayVal)};
		case "civilian": {_unitliste resize 11; for "_i" from 0 to 10 do {_one_man = GVAR(civilians_t) call FUNC(RandomArrayVal);_unitliste set [_i,_one_man]}};
		case "sabotage": {_how_many = ceil random 11; if (_how_many < 6) then {_how_many = 6};_list = missionNamespace getVariable format [QGVAR(sabotage_%1),_side_char];_unitliste resize _how_many; for "_i" from 0 to _how_many - 1 do {_unitliste set [_i, _list call FUNC(RandomArrayVal)]}};
	};
	[_unitliste, _vehiclename]
};

FUNC(getmixedliste) = {
	private ["_side", "_ret_list", "_list"];
	PARAMS_1(_side);
	_ret_list = [];
	{
		_list = [_x,_side] call FUNC(getunitliste);
		_ret_list set [count _ret_list, [_list select 1, _list select 2]];
	} forEach [switch (floor random 2) do {case 0: {"brdm"};case 1: {"uaz_mg"};}, "bmp", "tank", "shilka"];
	_ret_list
};

FUNC(handleDeadVec) = {
	private ["_v", "_type", "_dir", "_pos", "_vel", "_dv", "_fuel", "_putsmex"];
	PARAMS_1(_v);
	_type = typeOf _v;
	_dir = direction _v;
	_pos = position _v;
	_vel = velocity _v;
	_fuel = (fuel _v) / 2;
	_putsmex = !isNil {GV(_v,GVAR(smvec))};
	{deleteVehicle _x} forEach ([_v] + crew _v);
	_dv = createVehicle [_type, _pos, [], 0, "CAN_COLLIDE"];
	_dv setDir _dir;
	_dv setPos _pos;
	_dv setVelocity _vel;
	_dv setFuel _fuel;
	_dv setDamage 1;
	_dv setVariable [QGVAR(ddeadt), diag_tickTime];
	__addDead(_dv)
	if (_putsmex) then {GVAR(extra_mission_vehicle_remover_array) set [count GVAR(extra_mission_vehicle_remover_array), _dv]};
};

FUNC(makevgroup) = {
	private ["_numbervehicles", "_pos", "_vehiclename", "_grp", "_direction", "_crews", "_grpskill", "_n", "_dir", "_vehicle", "_npos", "_do_points", "_radius", "_the_vehicles"];
	PARAMS_6(_numbervehicles,_pos,_vehiclename,_grp,_radius,_direction);
	_do_points = (count _this > 6);
	_the_vehicles = [];
	_crews = [];
	_npos = _pos;
	
	_grpskill = if (_vehiclename isKindOf "StaticWeapon") then {1.0} else {(GVAR(skill_array) select 0) + (random (GVAR(skill_array) select 1))};
	
	_the_vehicles resize _numbervehicles;
	for "_n" from 0 to _numbervehicles - 1 do {
		_dir = if (_direction != -1.111) then {_direction} else {floor random 360};
		
		_vec_array = [_npos, _dir, _vehiclename, _grp] call FUNC(spawnVehicle);
		_vehicle = _vec_array select 0;
		_crews = [_crews, _vec_array select 1] call FUNC(arrayPushStack2);
		
		_the_vehicles set [_n, _vehicle];
		_npos = _vehicle modelToWorld [0,-12,0];
		
		_is_air_vec = false;
		switch (true) do {
			case (_vehicle isKindOf "Tank"): {
				if !((toUpper _vehiclename) in GVAR(heli_wreck_lift_types)) then {
					#ifdef __ACE__
					__addRemoveVehi(_vehicle)
					#endif
					_vehicle addEventHandler ["killed", FUNC(handleDeadVec)];
					__addDead(_vehicle)
				};
				if (GVAR(domdatabase)) then {
					_vehicle addMPEventHandler ["MPKilled", {if (isServer && {isPlayer (_this select 1)}) then {(_this select 1) call FUNC(PAddTankKillPoints)}}];
				};
				if (GVAR(LockArmored) == 0) then {_vehicle lock true};
			};
			case (_vehicle isKindOf "Wheeled_APC"): {
				if !((toUpper _vehiclename) in GVAR(heli_wreck_lift_types)) then {
					#ifdef __ACE__
					__addRemoveVehi(_vehicle)
					#endif
					__addDead(_vehicle)
					_vehicle addEventHandler ["killed",FUNC(handleDeadVec)];
				};
				if (GVAR(domdatabase)) then {
					_vehicle addMPEventHandler ["MPKilled", {if (isServer && {isPlayer (_this select 1)}) then {(_this select 1) call FUNC(PAddAPCKillPoints)}}];
				};
				if (GVAR(LockCars) == 0) then {_vehicle lock true};
			};
			case (_vehicle isKindOf "Car"): {
				if !((toUpper _vehiclename) in GVAR(heli_wreck_lift_types)) then {
					#ifdef __ACE__
					__addRemoveVehi(_vehicle)
					#endif
					__addDead(_vehicle)
					_vehicle addEventHandler ["killed",FUNC(handleDeadVec)];
				};
				if (GVAR(domdatabase)) then {
					_vehicle addMPEventHandler ["MPKilled", {if (isServer && {isPlayer (_this select 1)}) then {(_this select 1) call FUNC(PAddCarKillPoints)}}];
				};
				if (GVAR(LockCars) == 0) then {_vehicle lock true};
			};
			default {
				if !((toUpper _vehiclename) in GVAR(heli_wreck_lift_types)) then {
					__addDead(_vehicle)
				};
				if (GVAR(domdatabase)) then {
					if (_vehicle isKindOf "Helicopter") then {
						_vehicle addMPEventHandler ["MPKilled", {if (isServer && {isPlayer (_this select 1)}) then {(_this select 1) call FUNC(PAddChopperKillPoints)}}];
					} else {
						if (_vehicle isKindOf "Plane") then {
							_vehicle addMPEventHandler ["MPKilled", {if (isServer && {isPlayer (_this select 1)}) then {(_this select 1) call FUNC(PAddPlaneKillPoints)}}];
						};
					};
				};
				if (_vehicle isKindOf "Air") then {_is_air_vec = true;if (GVAR(LockAir) == 0) then {_vehicle lock true}};
			};
		};
		#ifdef __TT__
		if (_do_points) then {
			if (!_is_air_vec) then {
				_vehicle addEventHandler ["killed", {[[20, 3, 2, 1],_this select 1, _this select 0] call FUNC(AddKills)}];
			} else {
				_vehicle addEventHandler ["killed", {[[30, 3, 2, 1],_this select 1, _this select 0] call FUNC(AddKills)}];
			};
		};
		#endif
		if (GVAR(with_ai)) then {if (__RankedVer) then {_vehicle addEventHandler ["killed", {[5,_this select 1] call FUNC(AddKillsAI)}]}};
	};
	(leader _grp) setSkill _grpskill;
	_grp setVariable [QGVAR(gstate), 1];
	[_the_vehicles, _crews]
};

FUNC(makemgroup) = {
	private ["_pos", "_unitliste", "_grp", "_ret", "_do_points"];
	PARAMS_3(_pos,_unitliste,_grp);
	_do_points = (count _this > 3);_ret = [];
	{
		_one_unit = _grp createunit [_x, _pos, [], 10,"NONE"];
		if (GVAR(without_nvg) == 0) then {
			if (_one_unit hasWeapon "NVGoggles") then {_one_unit removeWeapon "NVGoggles"};
		};
		_svec = sizeOf _x;
		_isFlat = (position _one_unit) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _one_unit];
		if (count _isFlat > 1) then {
			_isFlat set [2,0];
			if (_one_unit distance _isFlat < 50) then {
				_one_unit setPos _isFlat;
			};
		};
		_one_unit setVariable ["BIS_noCoreConversations", true];
		[_one_unit, {__addDeadAI(_this)}] call FUNC(setUnitCode);
		if (GVAR(domdatabase)) then {
			[_one_unit, {_this addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddAIKillPoints)}}]}] call FUNC(setUnitCode);
		};
		#ifdef __TT__
		if (_do_points) then {
			[_one_unit, {_this addEventHandler ["killed", {[[15, 3, 2, 1],_this select 1, _this select 0] call FUNC(AddKills)}]}] call FUNC(setUnitCode);
		};
		#endif
		if (GVAR(with_ai)) then {
			if (__RankedVer) then {
				[_one_unit, {_this addEventHandler ["killed", {[1,_this select 1] call FUNC(AddKillsAI)}]}] call FUNC(setUnitCode);
			};
		};
		_one_unit setUnitAbility ((GVAR(skill_array) select 0) + (random (GVAR(skill_array) select 1)));
		_ret set [count _ret, _one_unit];
		// does not subtract if a unit dies!
		#ifdef __GROUPDEBUG__
		if (side _grp == GVAR(side_enemy)) then {
			__INC(GVAR(infunitswithoutleader));
		};
		#endif
	} foreach _unitliste;
	#ifdef __GROUPDEBUG__
	if (side _grp == GVAR(side_enemy)) then {
		__DEC(GVAR(infunitswithoutleader));
	};
	#endif
	(leader _grp) setRank "SERGEANT";
	_grp setVariable [QGVAR(gstate), 1];
	_ret
};

FUNC(CreateInf) = {
	private ["_radius", "_pos", "_nr", "_nrg", "_typenr", "_i", "_newgroup", "_units", "_pos_center", "_do_patrol", "_ret_grps"];
	_pos_center = _this select 4;
	_radius = _this select 5;
	_do_patrol = if (count _this == 7) then {_this select 6} else {false};
	if (_radius < 50) then {_do_patrol = false};
	
	_ret_grps = [];
	_pos = [];
	
	for "_nr" from 0 to 1 do {
		_nrg = _this select (1 + (_nr * 2));
		if (_nrg > 0) then {
			if (GVAR(MissionType) == 2) then {_nrg = _nrg + 2};
			_typenr = _this select (_nr * 2);
			for "_i" from 1 to _nrg do {
				_newgroup = [GVAR(side_enemy)] call FUNC(creategroup);
				_unit_array = [_typenr, GVAR(enemy_side)] call FUNC(getunitliste);
				if (_radius > 0) then {
					_pos = [_pos_center, _radius] call FUNC(GetRanPointCircle);
					if (count _pos == 0) then {
						for "_ee" from 0 to 99 do {_pos = [_pos_center, _radius] call FUNC(GetRanPointCircle);if (count _pos > 0) exitWith {}};
					};
				} else {
					_pos = _pos_center;
				};
				_units = [_pos, _unit_array select 0, _newgroup] call FUNC(makemgroup);
				_newgroup allowFleeing 0;
				if (!_do_patrol) then {
					_newgroup setCombatMode "YELLOW";
					_newgroup setFormation (["COLUMN","STAG COLUMN","WEDGE","ECH LEFT","ECH RIGHT","VEE","LINE","DIAMOND"] call FUNC(RandomArrayVal));
					_newgroup setFormDir (floor random 360);
					_newgroup setSpeedMode "NORMAL";
				};
				_ret_grps set [count _ret_grps, _newgroup];
				if (_do_patrol) then {
					[_newgroup, _pos, [_pos_center, _radius], [5, 15, 30], "d_xxgrp = this call d_fnc_getgroup; if ((d_xxgrp call d_fnc_GetAliveUnitsGrp) > 1) then {if ((random 100) > 60) then {[this] spawn d_fnc_searchNearby}}"] spawn FUNC(MakePatrolWPX);
				} else {
					_newgroup setVariable [QGVAR(defend), true];
					[_newgroup, _pos_center] spawn FUNC(taskDefend);
				};
				GVAR(extra_mission_remover_array) = [GVAR(extra_mission_remover_array), _units] call FUNC(arrayPushStack);
				GVAR(reduce_groups) set [count GVAR(reduce_groups), _newgroup];
			};
		};
	};
	_ret_grps
};

FUNC(CreateArmor) = {
	private ["_numvehicles", "_radius", "_pos", "_nr", "_nrg", "_typenr", "_i", "_newgroup", "_reta", "_pos_center", "_do_patrol", "_ret_grps"];
	_pos_center = _this select 6;
	_numvehicles = _this select 7;
	_radius = _this select 8;
	_do_patrol = if (count _this == 10) then {_this select 9} else {false};
	if (_radius < 50) then {_do_patrol = false};
	_ret_grps = [];
	_pos = [];
	
	for "_nr" from 0 to 2 do {
		_nrg = _this select (1 + (_nr * 2));
		if (_nrg > 0) then {
			if (GVAR(MissionType) == 2) then {_nrg = _nrg + 2};
			_typenr = _this select (_nr * 2);
			for "_i" from 1 to _nrg do {
				_newgroup = [GVAR(side_enemy)] call FUNC(creategroup);
				if (_radius > 0) then {
					_pos = [_pos_center, _radius] call FUNC(GetRanPointCircle);
					if (count _pos == 0) then {
						for "_ee" from 0 to 99 do {_pos = [_pos_center, _radius] call FUNC(GetRanPointCircle);if (count _pos > 0) exitWith {}};
					};
				} else {
					_pos = _pos_center;
				};
				_unit_array = [_typenr, GVAR(enemy_side)] call FUNC(getunitliste);
				_reta = [_numvehicles, _pos, _unit_array select 1, _newgroup, 0,-1.111] call FUNC(makevgroup);
				{_x setVariable [QGVAR(smvec), true]} forEach (_reta select 0);
				GVAR(extra_mission_vehicle_remover_array) = [GVAR(extra_mission_vehicle_remover_array), _reta select 0] call FUNC(arrayPushStack2);
				GVAR(extra_mission_remover_array) = [GVAR(extra_mission_remover_array), _reta select 1] call FUNC(arrayPushStack2);
				_newgroup allowFleeing 0;
				if (!_do_patrol) then {
					_newgroup setCombatMode "YELLOW";
					_newgroup setFormation (["COLUMN","STAG COLUMN","WEDGE","ECH LEFT","ECH RIGHT","VEE","LINE","DIAMOND"] call FUNC(RandomArrayVal));
					_newgroup setFormDir (floor random 360);
					_newgroup setSpeedMode "NORMAL";
				};
				_ret_grps set [count _ret_grps, _newgroup];
				if (_do_patrol) then {[_newgroup, _pos, [_pos_center, _radius], [5, 15, 30]] spawn FUNC(MakePatrolWPX)};
			};
		};
	};
	_ret_grps
};

FUNC(setUnitCode) = {
	private "_uc";
	(_this select 0) call (_this select 1);
	_uc = (_this select 0) getVariable QGVAR(unitcode);
	if (isNil "_uc") then {
		_uc = [_this select 1];
	} else {
		_uc set [count _uc, _this select 1];
	};
	(_this select 0) setVariable [QGVAR(unitcode), _uc];
};

FUNC(GuardWP) = {
	private ["_ggrp"];
	_ggrp = _this;
	_ggrp setCombatMode "YELLOW";
	_ggrp setFormation (["COLUMN","STAG COLUMN","WEDGE","ECH LEFT","ECH RIGHT","VEE","LINE","FILE","DIAMOND"] call FUNC(RandomArrayVal));
	_ggrp setFormDir (floor random 360);
	_ggrp setSpeedMode "NORMAL";
	_ggrp setBehaviour "SAFE";
};

FUNC(AttackWP) = {
	private ["_ggrp","_gtarget_pos","_gwp"];
	PARAMS_2(_ggrp,_gtarget_pos);
	_ggrp setbehaviour "AWARE";
	_gwp = _ggrp addWaypoint [_gtarget_pos,30];
	_gwp setwaypointtype "SAD";
	_gwp setWaypointCombatMode "YELLOW";
	_gwp setWaypointSpeed "FULL";
};

FUNC(checknextwf) = {
	private ["_grp", "_istaking", "_camps"];
	PARAMS_1(_grp);
	_grp = _grp call FUNC(getgroup);
	__TRACE_1("checknextwf",_grp)
	_istaking = GV(_grp,GVAR(takingwf));
	if (isNil "_istaking") then {_istaking = false};
	if (_istaking) exitWith {};
	_camps = switch (side _grp) do {
		case east: {GVAR(west_camps)};
		case west: {GVAR(east_camps)};
	};
	if (count _camps > 0) then {
		_target_pos = position (_camps call FUNC(RandomArrayVal));
		[_grp, _target_pos] call FUNC(TakeWFWP);
	} else {
		// TODO: No camps left, and enough units in group, wait for next target and attack
		// if target is not too far away
	};
};

FUNC(TakeWFWP) = {
	private ["_ggrp","_gtarget_pos","_gwp"];
	PARAMS_2(_ggrp,_gtarget_pos);
	_ggrp = _ggrp call FUNC(getgroup);
	__TRACE_2("TakeWFWP",_ggrp,_gtarget_pos)
	_ggrp setbehaviour "AWARE";
	_gwp = _ggrp addWaypoint [_gtarget_pos, 0];
	_gwp setwaypointtype "MOVE";
	_gwp setWaypointCombatMode "YELLOW";
	_gwp setWaypointSpeed "NORMAL";
	_gwp setWaypointTimeout [60, 60 + random 20, 80 + random 20];
	_gwp setWaypointStatements ["TRUE", "call {private '_xxgrp';_xxgrp = this call d_fnc_getgroup; _xxgrp setVariable ['d_takingwf', false];if ((_xxgrp call d_fnc_GetAliveUnitsGrp) > 0) then {[_xxgrp] call d_fnc_checknextwf}}"];
	_ggrp setVariable [QGVAR(takingwf), true];
};

#ifndef __ACE__
FUNC(GetWreck) = {
	private ["_no","_rep_station","_types"];
	PARAMS_2(_rep_station,_types);
	_no = nearestObjects [position _rep_station, _types, 8];
	if (count _no > 0) then {if (damage (_no select 0) >= 1) then {_no select 0} else {objNull}} else {objNull}
};
#else
FUNC(GetWreck) = {
	private ["_no","_rep_station","_types","_ret"];
	PARAMS_2(_rep_station,_types);
	_ret = objNull;
	_no = nearestObjects [position _rep_station, _types, 8];
	if (count _no > 0) then {if (damage (_no select 0) >= 1) then {_ret = _no select 0} else {_isv = (_no select 0) call ace_v_alive;if (!isNil "_isv") then {if (!_isv) then {_ret = _no select 0}}}};
	_ret
};
#endif

FUNC(OutOfBounds) = {
	private ["_vec", "_p_x", "_vec", "_p_y"];
	_vec = _this;
	_p_x = getPosASL _vec select 0;
	_p_y = getPosASL _vec select 1;
	((_p_x < 0 || _p_x > GVAR(island_x_max)) && (_p_y < 0 || _p_y > GVAR(island_y_max)))
};

// supports also patrols in square areas, including angle
FUNC(MakePatrolWPX) = {
	private ["_grp", "_start_pos", "_wp_array", "_i", "_wp_pos", "_counter", "_wp", "_wppos", "_pos", "_cur_pos","_no_pos_found", "_wpstatements", "_timeout", "_wp1"];
	PARAMS_3(_grp,_start_pos,_wp_array);
	if (typeName _wp_array == "OBJECT") then {_wp_array = position _wp_array};
	if (typeName _wp_array != "ARRAY") exitWith {};
	if (typeName _start_pos == "OBJECT") then {_start_pos = position _start_pos};
	if (typeName _start_pos != "ARRAY") exitWith {};
	if (count _start_pos == 0) exitWith {};
	if (isNull _grp) exitWith {};
	_timeout = if (count _this > 3) then {_this select 3} else {[]};
	_wpstatements = if (count _this > 4) then {_this select 4} else {""};
	_grp setBehaviour "SAFE";
	_cur_pos = _start_pos;
	_no_pos_found = false;
	for "_i" from 0 to (2 + (floor (random 3))) do {
		_wp_pos = switch (count _wp_array) do {
			case 2: {[_wp_array select 0, _wp_array select 1] call FUNC(GetRanPointCircle)};
			case 4: {[_wp_array select 0, _wp_array select 1, _wp_array select 2, _wp_array select 3] call FUNC(GetRanPointSquare)};
		};
		if (count _wp_pos == 0) exitWith {_no_pos_found = true};
		_counter = 0;
		while {_wp_pos distance _cur_pos < ((_wp_array select 1)/6) && _counter < 100} do {
			_wp_pos = switch (count _wp_array) do {
				case 2: {[_wp_array select 0, _wp_array select 1] call FUNC(GetRanPointCircle)};
				case 4: {[_wp_array select 0, _wp_array select 1, _wp_array select 2, _wp_array select 3] call FUNC(GetRanPointSquare)};
			};
			if (count _wp_pos == 0) exitWith {};
			__INC(_counter);
		};
		if (count _wp_pos == 0) exitWith {_no_pos_found = true};
		_wp_pos = _wp_pos call FUNC(WorldBoundsCheck);
		_cur_pos = _wp_pos;
		_wp = _grp addWaypoint [_wp_pos, 0];
		_wp setWaypointType "MOVE";
		_wp setWaypointCompletionRadius (0 + random 10);
		if (count _timeout > 0) then {_wp setWaypointTimeout _timeout};
		
		if (_i == 0) then {
			_wp setWaypointSpeed "LIMITED";
			_wp setWaypointFormation "STAG COLUMN";
		};
		if (_wpstatements != "") then {
			_wp setWaypointStatements ["TRUE", _wpstatements];
		};
	};
	if (_no_pos_found) exitWith {
		_wp1 = _grp addWaypoint [_start_pos, 0];
		_wp1 setWaypointType "SAD";
	};
	_wp1 = _grp addWaypoint [_start_pos, 0];
	_wp1 setWaypointType "MOVE";
	_wp1 setWaypointCompletionRadius (10 + random 10);
	if (count _timeout > 0) then {_wp1 setWaypointTimeout _timeout};
	if (_wpstatements != "") then {
		_wp1 setWaypointStatements ["TRUE", _wpstatements];
	};
	_wp = _grp addWaypoint [_start_pos, 0];
	_wp setWaypointType "CYCLE";
	_wp setWaypointCompletionRadius (10 + random 10);
};

// supports also patrols in square areas, including angle
FUNC(MakePatrolWPX2) = {
	private ["_grp", "_start_pos", "_wp_array", "_i", "_wp_pos", "_counter", "_wp", "_wppos", "_pos", "_cur_pos","_no_pos_found", "_wpstatements", "_timeout", "_wp1"];
	PARAMS_3(_grp,_start_pos,_wp_array);
	if (typeName _wp_array == "OBJECT") then {_wp_array = position _wp_array};
	if (typeName _wp_array != "ARRAY") exitWith {};
	if (typeName _start_pos == "OBJECT") then {_start_pos = position _start_pos};
	if (typeName _start_pos != "ARRAY") exitWith {};
	if (count _start_pos == 0) exitWith {};
	_timeout = if ((count _this) > 3) then {_this select 3} else {[]};
	_wpstatements = if (count _this > 4) then {_this select 4} else {""};
	_grp setBehaviour "AWARE";
	_grp setSpeedMode "FULL";
	_cur_pos = _start_pos;
	_no_pos_found = false;
	for "_i" from 0 to (2 + (floor (random 3))) do {
		_wp_pos = switch (count _wp_array) do {
			case 2: {[_wp_array select 0, _wp_array select 1] call FUNC(GetRanPointCircle)};
			case 4: {[_wp_array select 0, _wp_array select 1, _wp_array select 2, _wp_array select 3] call FUNC(GetRanPointSquare)};
		};
		if (count _wp_pos == 0) exitWith {_no_pos_found = true};
		_counter = 0;
		while {_wp_pos distance _cur_pos < ((_wp_array select 1)/6) && _counter < 100} do {
			_wp_pos = switch (count _wp_array) do {
				case 2: {[_wp_array select 0, _wp_array select 1] call FUNC(GetRanPointCircle)};
				case 4: {[_wp_array select 0, _wp_array select 1, _wp_array select 2, _wp_array select 3] call FUNC(GetRanPointSquare)};
			};
			if (count _wp_pos == 0) exitWith {};
			__INC(_counter);
		};
		if (count _wp_pos == 0) exitWith {_no_pos_found = true};
		_wp_pos = _wp_pos call FUNC(WorldBoundsCheck);
		_cur_pos = _wp_pos;
		_wp = _grp addWaypoint [_wp_pos, 0];
		_wp setWaypointType "MOVE";
		_wp setWaypointCompletionRadius (0 + random 10);
		if (count _timeout > 0) then {_wp setWaypointTimeout _timeout};
		
		if (_i > 0) then {
			_wp setWaypointSpeed "LIMITED";
			_wp setWaypointFormation "STAG COLUMN";
			_wp setWaypointBehaviour "SAFE";
		} else {
			_wp setWaypointSpeed "FULL";
			_wp setWaypointBehaviour "AWARE";
			_wp setWaypointFormation "STAG COLUMN";
		};
		if (_wpstatements != "") then {
			_wp setWaypointStatements ["TRUE", _wpstatements];
		};
	};
	if (_no_pos_found) exitWith {
		_wp1 = _grp addWaypoint [_start_pos, 0];
		_wp1 setWaypointType "SAD";
	};
	_wp1 = _grp addWaypoint [_start_pos, 0];
	_wp1 setWaypointType "MOVE";
	_wp1 setWaypointCompletionRadius (10 + random 10);
	if (count _timeout > 0) then {_wp1 setWaypointTimeout _timeout};
	if (_wpstatements != "") then {
		_wp1 setWaypointStatements ["TRUE", _wpstatements];
	};
	_wp = _grp addWaypoint [_start_pos, 0];
	_wp setWaypointType "CYCLE";
	_wp setWaypointCompletionRadius (10 + random 10);
};

FUNC(DelVecAndCrew) = {{deleteVehicle _x} forEach ([[_this], crew _this] call FUNC(arrayPushStack2))};

FUNC(PlacedObjKilled) = {
	private ["_val", "_ar"];
	_val = (_this select 0) getVariable QGVAR(owner);
	if (!isNil "_val") then {
		_ar = GVAR(placed_objs_store) getVariable _val;
		if (!isNil "_ar") then {
			_ar = _ar - [_this select 0];
			GVAR(placed_objs_store) setVariable [_val, _ar];
		};
		[QGVAR(p_o_an), _val] call FUNC(NetCallEventToClients);
	};
};

FUNC(GetPlayerArray) = {
	private ["_uid","_parray"];
	PARAMS_1(_uid);
	_parray = GV2(GVAR(player_store),_uid);
	if (!isNil "_parray") then {
		_parray set [4, _this select 1];
		_parray set [5, _this select 2];
		__TRACE_2("GetPlayerArray","_uid","_pa");
	};
};

if (GVAR(domdatabase)) then {
	FUNC(ServerGetPlayerStats) = {
		_pl = _this;
		if (isNull _pl) exitWith {};
		_uid = getPlayerUID _pl;
		_pa = GV2(GVAR(player_store),_uid);
		if (!isNil "_pa") then {
			[QGVAR(sendps), [_pl, _pa]] call FUNC(NetCallEventSTO);
		};
	};
};

FUNC(TKKickCheck) = {
	private ["_tk", "_p", "_sel", "_numtk", "_uid"];
	_tk = _this select 2;
	_tk addScore (GVAR(sub_tk_points) * -1);
	_uid = getPlayerUID _tk;
	__TRACE_2("TKKickCheck","_tk","_uid");
	_p = GV2(GVAR(player_store),_uid);
	if (!isNil "_p") then {
		_numtk = _p select 7;
		__INC(_numtk);
		_p set [7, _numtk];
		if (GVAR(domdatabase)) then {
			_p set [16, (_p select 16) + 1];
		};
		if (_numtk >= GVAR(maxnum_tks_forkick)) exitWith {
			_pna = _p select 6;
			// god damn, servercommand was removed instead of fixing the heart of the problem, hackers/cheaters bypassing signature system
			// I'm really pissed by this
			serverCommand ("#kick " + _pna);
			diag_log format ["Player %1 was kicked automatically because of teamkilling, # team kills: %3, ArmA 2 Key: %2", _pna, _uid, _numtk];
			[QGVAR(tk_an), [_pna, _numtk]] call FUNC(NetCallEventToClients);
			[QGVAR(em), [_tk]] call FUNC(NetCallEventSTO);
		};
		#ifdef __ACE__
		[QGVAR(haha), [_tk]] call FUNC(NetCallEventSTO);
		#endif
	};
};

FUNC(KickPlayerBS) = {
	private ["_pl", "_uid", "_reason"];
	PARAMS_3(_pl,_pl_name,_reason);
	_uid = getPlayerUID _pl;
	serverCommand ("#kick " + _pl_name);
	[QGVAR(em), [_pl]] call FUNC(NetCallEventSTO);
	if (_reason != -1) then {
		switch (_reason) do {
			case 0: {
				diag_log format [(localize "STR_DOM_MISSIONSTRING_943"), _pl_name, _uid];
			};
			case 1: {
				diag_log format [(localize "STR_DOM_MISSIONSTRING_944"), _pl_name, _uid];
			};
			case 2: {
				diag_log format [(localize "STR_DOM_MISSIONSTRING_945"), _pl_name, _uid];
			};
			case 3: {
				diag_log format [(localize "STR_DOM_MISSIONSTRING_946"), _pl_name, _uid];
			};
		};
		[QGVAR(ps_an), [_pl_name, _reason]] call FUNC(NetCallEventToClients);
	};
};

FUNC(RptMsgBS) = {
	private ["_pl", "_uid", "_reason"];
	PARAMS_3(_pl,_pl_name,_reason);
	_uid = getPlayerUID _pl;
	__TRACE_2("RptMsgBS","_uid","_pl_name");
	switch (_reason) do {
		case 0: {
			diag_log format [(localize "STR_DOM_MISSIONSTRING_947"), _pl_name, _uid];
		};
		case 1: {
			diag_log format [(localize "STR_DOM_MISSIONSTRING_948"), _pl_name, _uid];
		};
	};
};

FUNC(AdminDelTKs) = {
	private ["_p"];
	_p = GV2(GVAR(player_store),_this);
	if (!isNil "_p") then {
		_p set [7, 0];
		__TRACE_2("AdminDelTKs","_p","_this");
	};
};

FUNC(AddPlayerScore) = {
	private ["_uid", "_score", "_pa"];
	PARAMS_2(_uid,_score);
	_pa = GV2(GVAR(player_store),_uid);
	if (!isNil "_pa") then {
		_pa set [3, _score];
		__TRACE_2("fnc_AddPlayerScore","_score","_pa")
	};
};

FUNC(GetPlayerStats) = {
	private ["_uid", "_pa", "_pl"];
	_pl = _this;
	_uid = getPlayerUID _pl;
	_pa = GV2(GVAR(player_store),_uid);
	__TRACE_1("fnc_GetPlayerStats","_uid")
	if (!isNil "_pa") then {
		_pa set [18, score _pl];
		[QGVAR(p_ar), [_pl, _pa]] call FUNC(NetCallEventSTO);
	};
};

FUNC(GetAdminArray) = {
	private ["_uid", "_h"];
	_uid = _this select 1;
	_h = GV2(GVAR(player_store),_uid);
	if (isNil "_h") then {_h = []};
	[QGVAR(s_p_inf), [_this select 0, _h]] call FUNC(NetCallEventSTO);
};

FUNC(ChangeRLifes) = {
	private ["_p", "_pl"];
	_pl = _this select 0;
	_p = GV2(GVAR(player_store),_pl);
	if (!isNil "_p") then {
		_p set [8, _this select 1];
		__TRACE_1("ChangeRLifes","_p");
	};
};

FUNC(GetEnemyFlagType) = {("F" + GVAR(enemy_side)) call FUNC(StoreGet)};

FUNC(GetOwnFlagType) = {("F" + GVAR(own_side)) call FUNC(StoreGet)};

FUNC(GetSideFlagType) = {("F" + _this) call FUNC(StoreGet)};

FUNC(selectCrew) = {
	/*
	File: selectCrew.sqf
	Author: Joris-Jan van 't Land
	
	Description:
	Return an appropriate crew type for a certain vehicle.
	
	Parameter(s):
	_this select 0: side (Side)
	_this select 1: vehicle config entry (Config)
	
	Returns:
	Array - crew type, cargo types (array) for Wheeled APCs
	*/
	if (count _this < 2) exitWith {};
	private ["_side", "_entry", "_type"];
	PARAMS_3(_side,_entry,_type);
	if (typeName _side != typeName sideEnemy) exitWith {""};
	if (typeName _entry != typeName configFile) exitWith {""};
	private ["_crew", "_typcargo"];
	_crew = "";
	_typcargo = [];
	_crew = getText (_entry >> "crew");
	if (_crew == "") then {
		switch (_side) do {
			case west: {_crew = GVAR(vec_spawn_default_Crew) select 0};
			case east: {_crew = GVAR(vec_spawn_default_Crew) select 1};
			default {};
		};
	} else {
		if (_type isKindOf "Car" || _type isKindOf "Tracked_APC") then {
			_typcargo = (getArray (_entry >> "typicalCargo")) - [_crew,"Soldier"];
		};
	};
	[_crew, _typcargo]
};

FUNC(SideMissionResolved) = {
	execFSM "fsms\XClearSidemission.fsm";
	if (X_SPE) then {
		deleteMarkerLocal (format ["XMISSIONM%1", __XJIPGetVar(GVAR(current_mission_index)) + 1]);
		if (GVAR(x_sm_type) == "convoy") then {deleteMarkerLocal (format ["XMISSIONM2%1", __XJIPGetVar(GVAR(current_mission_index)) + 1])};
	};
	[QGVAR(current_mission_index),-1] call FUNC(NetSetJIP);
	if (GVAR(side_mission_winner) > 0) then {
		#ifdef __TT__
		switch (GVAR(side_mission_winner)) do {
			case 1: {GVAR(points_east) = GVAR(points_east) + (GVAR(tt_points) select 4)};
			case 2: {GVAR(points_west) = GVAR(points_west) + (GVAR(tt_points) select 4)};
		};	
		#endif
		execVM "x_server\x_getbonus.sqf";
	};
	if (GVAR(side_mission_winner) in [-1,-2,-300,-400,-500,-600,-700,-878,-879]) then {
		[QGVAR(sm_res_client), [GVAR(side_mission_winner), ""]] call FUNC(NetCallEventToClients);
		#ifndef __TT__
		GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"MissionFailure",true];
		#else
		GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","MissionFailure",true];
		GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","MissionFailure",true];
		#endif
		if (!X_SPE) then {GVAR(side_mission_winner) = 0};
	};
};

FUNC(RemABox) = {
	private ["_boxes", "_mname"];
	if (typeName _this == "SCALAR") exitWith {};
	_boxes = __XJIPGetVar(GVAR(ammo_boxes));
	{
		if ((_x select 0) distance _this < 5) exitWith {
			_mname = _x select 1;
			deleteMarker _mname;
			_boxes set [_forEachIndex, -1];
		};
	} forEach _boxes;
	_boxes = _boxes - [-1];
	__XJIPSetVar [QGVAR(ammo_boxes), _boxes, true];
};

#ifndef __TT__
FUNC(CreateDroppedBox) = {
	private ["_the_box_pos","_boxes","_mname"];
	PARAMS_1(_the_box_pos);
	_mname = "bm_" + str(_the_box_pos);
	_boxes = __XJIPGetVar(GVAR(ammo_boxes));
	_boxes set [count _boxes, [_the_box_pos,_mname]];
	[QGVAR(ammo_boxes),_boxes] call FUNC(NetSetJIP);
	[_mname, _the_box_pos, "ICON", "ColorBlue",[0.5,0.5],(localize "STR_DOM_MISSIONSTRING_523"),0,GVAR(dropped_box_marker)] call FUNC(CreateMarkerGlobal);
};
#else
FUNC(CreateDroppedBox) = {
	private ["_the_box_pos", "_boxside", "_boxes", "_mname"];
	PARAMS_2(_the_box_pos,_boxside);
	_mname = "bm_" + str(_the_box_pos);
	_boxes = __XJIPGetVar(GVAR(ammo_boxes));
	_boxes set [count _boxes, [_the_box_pos,_mname, _boxside]];
	[QGVAR(ammo_boxes),_boxes] call FUNC(NetSetJIP);
	[_mname, _the_box_pos,"ICON","ColorBlue",[0.5,0.5],(localize "STR_DOM_MISSIONSTRING_523"),0,GVAR(dropped_box_marker)] call FUNC(CreateMarkerGlobal);
	[QGVAR(r_mark), [_mname, _boxside]] call FUNC(NetCallEventToClients);
};
#endif

FUNC(CheckMTShotHD) = {
	private ["_tower", "_r", "_val"];
	PARAMS_1(_tower);
	_r = 0;
	if ((toUpper(getText(configFile >> "CfgAmmo" >> (_this select 4) >> "simulation")) in GVAR(hd_sim_types)) || ((_this select 4) == "ACE_PipebombExplosion")) then {
		_r = (_this select 2) / 5;
	} else {
		if (GVAR(MTTowerSatchelsOnly) == 1) then {
			if (getText(configFile >> "CfgAmmo" >> (_this select 4) >> "CraterEffects") == "BombCrater") then {
				_r = _this select 2;
			};
		};
	};
	_val = _tower getVariable QGVAR(damt);
	if (isNil "_val") then {_val = 0};
	_r = _r + _val;
	_tower setVariable [QGVAR(damt), _r];
	_r
};

FUNC(CheckMTHardTarget) = {
	private ["_vehicle", "_trigger", "_trigger2","_hdeh"];
	PARAMS_1(_vehicle);
	[_vehicle] execFSM "fsms\XRemoveVehiExtra.fsm";
	_vehicle addEventHandler ["killed", {
		GVAR(mt_spotted) = false;
		[QGVAR(mt_radio_down),true] call FUNC(NetSetJIP);
		deleteMarker "main_target_radiotower";
		#ifndef __TT__
		GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"MTRadioTowerDown",true];
		#else
		GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","MTRadioTowerDown",true];
		GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","MTRadioTowerDown",true];
		[GVAR(tt_points) select 2,_this select 1] call FUNC(AddPoints);
		_killedby = switch (_this select 1) do {case west: {"US"};case east: {"EAST"};default {"N"};};
		if (_killedby != "N") then {
			GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","MTRadioAnnounce",["1","",_killedby,[]],["2","",str(GVAR(tt_points) select 2),[]],true];
			GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","MTRadioAnnounce",["1","",_killedby,[]],["2","",str(GVAR(tt_points) select 2),[]],true];
		};
		#endif
		if (GVAR(domdatabase)) then {
			if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddRadioTowerKillPoints)};
		};
	}];
	_hdeh = _vehicle addEventHandler ["handleDamage", FUNC(CheckMTShotHD)];
};

// get a random point inside a circle
// parameters:
// center position, radius of the circle
// example: _random_point = [position trigger1, 200] call FUNC(GetRanPointCircle);
FUNC(GetRanPointCircle) = {
	private ["_center", "_radius", "_co", "_angle", "_x1", "_y1", "_no", "_valid", "_slope", "_center_x", "_center_y"];
	PARAMS_2(_center,_radius);
	_center_x = _center select 0;_center_y = _center select 1;
	_ret_val = [];
	for "_co" from 0 to 99 do {
		_angle = floor (random 360);
		_x1 = _center_x - ((random _radius) * sin _angle);
		_y1 = _center_y - ((random _radius) * cos _angle);
		if !(surfaceiswater [_x1, _y1]) then {
			_no = [_x1, _y1, 0] nearestObject "Static";
			_valid = true;
			if (!isNull _no) then {
				if ([_x1, _y1, 0] distance _no < 11) then {_valid = false};
			};
			if (_valid) then {
				_slope = [[_x1, _y1, 0], 5] call FUNC(GetSlope);
				if (_slope < 0.7) then {_ret_val = [_x1, _y1,0]};
			};
		};
		if (count _ret_val != 0) exitWith {};
	};
	_ret_val
};

// get a random point inside a circle
// parameters:
// center position, radius of the circle
// example: _random_point = [position trigger1, 200] call FUNC(GetRanPointCircleNoSlope);
FUNC(GetRanPointCircleNoSlope) = {
	private ["_center", "_radius", "_co", "_angle", "_x1", "_y1", "_no", "_valid", "_slope", "_center_x", "_center_y"];
	PARAMS_2(_center,_radius);
	_center_x = _center select 0;_center_y = _center select 1;
	_ret_val = [];
	for "_co" from 0 to 99 do {
		_angle = floor (random 360);
		_x1 = _center_x - ((random _radius) * sin _angle);
		_y1 = _center_y - ((random _radius) * cos _angle);
		if !(surfaceiswater [_x1, _y1]) then {
			_no = [_x1, _y1, 0] nearestObject "Static";
			_valid = true;
			if (!isNull _no) then {
				if ([_x1, _y1, 0] distance _no < 11) then {_valid = false};
			};
			if (_valid) then {
				_ret_val = [_x1, _y1,0];
			};
		};
		if (count _ret_val != 0) exitWith {};
	};
	_ret_val
};

// no slope check, for patrolling
FUNC(GetRanPointCircleOld) = {
	private ["_center", "_radius", "_center_x", "_center_y", "_ret_val", "_co", "_angle", "_x1", "_y1"];
	PARAMS_2(_center,_radius);
	_center_x = _center select 0;_center_y = _center select 1;
	_ret_val = [];
	for "_co" from 0 to 99 do {
		_angle = floor (random 360);
		_x1 = _center_x - ((random _radius) * sin _angle);
		_y1 = _center_y - ((random _radius) * cos _angle);
		if !(surfaceiswater [_x1, _y1]) then {_ret_val = [_x1, _y1, 0]};
		if (count _ret_val != 0) exitWith {};
	};
	_ret_val
};

// get a random point inside a circle for bigger objects
// parameters:
// center position, radius of the circle
// example: _random_point = [position trigger1, 200] call FUNC(GetRanPointCircleBig);
FUNC(GetRanPointCircleBig) = {
	private ["_center", "_radius", "_co", "_angle", "_x1", "_y1", "_no", "_valid", "_slope", "_center_x", "_center_y"];
	PARAMS_2(_center,_radius);
	_center_x = _center select 0;_center_y = _center select 1;
	_ret_val = [];
	for "_co" from 0 to 99 do {
		_angle = floor (random 360);
		_x1 = _center_x - ((random _radius) * sin _angle);
		_y1 = _center_y - ((random _radius) * cos _angle);
		if !(surfaceiswater [_x1, _y1]) then {
			_no = [_x1, _y1, 0] nearestObject "Static";
			_valid = true;
			if (!isNull _no) then {
				if ([_x1, _y1, 0] distance _no < 21) then {_valid = false};
			};
			if (_valid) then {
				_slope = [[_x1,_y1,0], 5] call FUNC(GetSlope);
				if (_slope < 0.7 && !(isOnRoad ([_x1,_y1,0]))) then {_ret_val = [_x1,_y1,0]};
			};
		};
		if (count _ret_val != 0) exitWith {};
	};
	_ret_val
};

// get a random point at the borders of a circle
// parameters:
// center position, radius of the circle
// example: _random_point = [position trigger1, 200] call FUNC(GetRanPointCircleOuter);
FUNC(GetRanPointCircleOuter) = {
	private ["_center", "_radius", "_co", "_angle", "_x1", "_y1", "_no", "_valid", "_slope", "_center_x", "_center_y"];
	PARAMS_2(_center,_radius);
	_center_x = _center select 0;_center_y = _center select 1;
	_ret_val = [];
	for "_co" from 0 to 150 do {
		_angle = floor (random 360);
		_x1 = _center_x - (_radius * sin _angle);
		_y1 = _center_y - (_radius * cos _angle);
		if !(surfaceiswater [_x1, _y1]) then {
			_no = [_x1, _y1, 0] nearestObject "Static";
			_valid = true;
			if (!isNull _no) then {
				if ([_x1, _y1, 0] distance _no < 11) then {_valid = false};
			};
			if (_valid) then {
				_slope = [[_x1, _y1, 0], 5] call FUNC(GetSlope);
				if (_slope < 0.7) then {_ret_val = [_x1, _y1, 0]};
			};
		};
		if (count _ret_val != 0) exitWith {};
	};
	_ret_val
};

// get a random point inside a square
// parameters:
// center position, a and b (like in triggers), angle
// example: _random_point  = [position trigger2, 200, 300, 30] call FUNC(GetRanPointSquare);
FUNC(GetRanPointSquare) = {
	private ["_pos", "_a", "_b", "_angle", "_centerx", "_centery", "_leftx", "_lefty", "_width", "_height", "_co", "_px1", "_py1", "_radius", "_atan", "_x1", "_y1", "_no", "_valid", "_slope"];
	PARAMS_4(_pos,_a,_b,_angle);
	_centerx = _pos select 0;_centery = _pos select 1;_leftx = _centerx - _a;_lefty = _centery - _b;
	_width = 2 * _a;_height = 2 * _b;_ret_val = [];
	for "_co" from 0 to 99 do {
		_px1 = _leftx + random _width; _py1 = _lefty + random _height;
		_radius = _pos distance [_px1,_py1];
		_atan = (_centerx - _px1) atan2 (_centery - _py1);
		_x1 = _centerx - (_radius * sin (_atan + _angle));
		_y1 = _centery - (_radius * cos (_atan + _angle));
		if !(surfaceiswater [_x1, _y1]) then {
			_no = [_x1, _y1, 0] nearestObject "Static";
			_valid = true;
			if (!isNull _no) then {
				if ([_x1, _y1, 0] distance _no < 11) then {_valid = false};
			};
			if (_valid) then {
				_slope = [[_x1, _y1, 0], 5] call FUNC(GetSlope);
				if (_slope < 0.7) then {_ret_val = [_x1, _y1, 0]};
			};
		};
		if (count _ret_val != 0) exitWith {};
	};
	_ret_val
};

// no slope check, for patrolling
FUNC(GetRanPointSquareOld) = {
	private ["_pos", "_a", "_b", "_angle", "_centerx", "_centery", "_leftx", "_lefty", "_width", "_height", "_ret_val", "_co", "_px1", "_py1", "_radius", "_atan", "_x1", "_y1"];
	PARAMS_4(_pos,_a,_b,_angle);
	_centerx = _pos select 0;_centery = _pos select 1;_leftx = _centerx - _a;_lefty = _centery - _b;
	_width = 2 * _a;_height = 2 * _b;_ret_val = [];
	for "_co" from 0 to 99 do {
		_px1 = _leftx + random _width; _py1 = _lefty + random _height;
		_radius = _pos distance [_px1,_py1];
		_atan = (_centerx - _px1) atan2 (_centery - _py1);
		_x1 = _centerx - (_radius * sin (_atan + _angle));
		_y1 = _centery - (_radius * cos (_atan + _angle));
		if !(surfaceiswater [_x1, _y1]) then {_ret_val = [_x1, _y1, 0]};
		if (count _ret_val != 0) exitWith {};
	};
	_ret_val
};

// get a random point at the borders of a square
// parameters:
// center position, a and b (like in triggers), angle
// example: _random_point  = [position trigger2, 200, 300, 30] call FUNC(GetRanPointSquareOuter);
FUNC(GetRanPointSquareOuter) = {
	private ["_pos", "_a", "_b", "_angle", "_centerx", "_centery", "_leftx", "_lefty", "_width", "_height", "_co", "_rside", "_px1", "_py1", "_radius", "_atan", "_x1", "_y1", "_no", "_valid", "_slope"];
	PARAMS_4(_pos,_a,_b,_angle);
	_centerx = _pos select 0;_centery = _pos select 1;_leftx = _centerx - _a;_lefty = _centery - _b;
	_width = 2 * _a;_height = 2 * _b;_ret_val = [];
	for "_co" from 0 to 99 do {
		_rside = floor (random 4);
		_px1 = switch (_rside) do {
			case 0: {_leftx + random _width};
			case 1: {_leftx + _width};
			case 2: {_leftx + random _width};
			case 3: {_leftx};
		};
		_py1 = switch (_rside) do {
			case 0: {_lefty + _height};
			case 1: {_lefty + random _height};
			case 2: {_lefty};
			case 3: {_lefty + random _height};
		};
		_radius = _pos distance [_px1,_py1];
		_atan = (_centerx - _px1) atan2 (_centery - _py1);
		_x1 = _centerx - (_radius * sin (_atan + _angle));
		_y1 = _centery - (_radius * cos (_atan + _angle));
		if !(surfaceiswater [_x1, _y1]) then {
			_no = [_x1, _y1, 0] nearestObject "Static";
			_valid = true;
			if (!isNull _no) then {
				if ([_x1, _y1, 0] distance _no < 11) then {_valid = false};
			};
			if (_valid) then {
				_slope = [[_x1, _y1, 0], 5] call FUNC(GetSlope);
				if (_slope < 0.7) then {_ret_val = [_x1, _y1,0]};
			};
		};
		if (count _ret_val != 0) exitWith {};
	};
	_ret_val
};

// get a random point at the borders of a square
// parameters:
// center position, a and b (like in triggers), angle
// example: _random_point  = [position trigger2, 200, 300, 30] call FUNC(GetRanPointSquareOuter);
/*FUNC(GetRanPointSquareOuter) = {
private ["_pos", "_a", "_b", "_angle", "_centerx", "_centery", "_leftx", "_lefty", "_width", "_height", "_co", "_rside", "_px1", "_py1", "_radius", "_atan", "_x1", "_y1", "_no", "_valid", "_slope"];
PARAMS_4(_pos,_a,_b,_angle);
_centerx = _pos select 0;_centery = _pos select 1;_leftx = _centerx - _a;_lefty = _centery - _b;
_width = 2 * _a;_height = 2 * _b;_ret_val = [];
for "_co" from 0 to 99 do {
_rside = floor (random 4);
_px1 = switch (_rside) do {
case 0: {_leftx + random _width};
case 1: {_leftx + _width};
case 2: {_leftx + random _width};
case 3: {_leftx};
};
_py1 = switch (_rside) do {
case 0: {_lefty + _height};
case 1: {_lefty + random _height};
case 2: {_lefty};
case 3: {_lefty + random _height};
};
_radius = _pos distance [_px1,_py1];
_atan = (_centerx - _px1) atan2 (_centery - _py1);
_x1 = _centerx - (_radius * sin (_atan + _angle));
_y1 = _centery - (_radius * cos (_atan + _angle));
if (!(surfaceiswater [_x1, _y1])) then {
_no = [_x1, _y1, 0] nearestObject "Static";
_valid = true;
if (!isNull _no) then {
if ([_x1, _y1, 0] distance _no < 11) then {_valid = false};
};
if (_valid) then {
_slope = [[_x1, _y1, 0], 5] call FUNC(GetSlope);
if (_slope < 0.5) then {_ret_val = [_x1, _y1,0]};
};
};
if (count _ret_val != 0) exitWith {};
};
_ret_val
};*/

// get a random point at the borders of the current island for spawning air vehicles (no slope check, no is water check, etc)
// parameters:
// center position, left x, left y, width, height, angle (optional)
FUNC(GetRanPointOuterAir) = {
	private ["_pos", "_centerx", "_centery", "_leftx", "_lefty", "_width", "_height", "_rside", "_px1", "_py1", "_radius", "_atan", "_x1", "_y1"];
	_pos = GVAR(island_center);
	_centerx = _pos select 0; _centery = _pos select 1;
	_leftx = 250;_lefty = 250;
	_width = (2 * (_pos select 0)) - 500;
	_height = (2 * (_pos select 1)) - 500;
	_rside = floor (random 4);
	_px1 = switch (_rside) do {
		case 0: {_leftx + random _width};
		case 1: {_leftx + _width};
		case 2: {_leftx + random _width};
		case 3: {_leftx};
	};
	_py1 = switch (_rside) do {
		case 0: {_lefty + _height};
		case 1: {_lefty + random _height};
		case 2: {_lefty};
		case 3: {_lefty + random _height};
	};
	_radius = _pos distance [_px1,_py1,_pos select 2];
	_atan = (_centerx - _px1) atan2 (_centery - _py1);
	_x1 = _centerx - (_radius * sin _atan);
	_y1 = _centery - (_radius * cos _atan);
	[_x1, _y1, 300]
};

FUNC(GetLinePoints) = {
	private ["_startpoint", "_endpoint", "_radius", "_ret", "_curpoint", "_wpdist", "_wpangle", "_x1", "_y1"];
	PARAMS_2(_startpoint,_endpoint);
	_radius = if (count _this > 2) then {_this select 2} else {8000};
	if (typeName _startpoint == "OBJECT") then {_startpoint = position _startpoint};
	if (typeName _endpoint == "OBJECT") then {_endpoint = position _endpoint};
	_ret = [];
	_curpoint = _startpoint;
	_wpdist = _curpoint distance _endpoint;
	if (_wpdist > _radius) then {
		_wpangle = [_curpoint, _endpoint] call FUNC(DirTo);
		while {_wpdist > _radius} do {
			_x1 = (_curpoint select 0) + (_radius * sin _wpangle);
			_y1 = (_curpoint select 1) + (_radius * cos _wpangle);
			_curpoint = [_x1, _y1, 0];
			_wpdist = _curpoint distance _endpoint;
			_ret set [count _ret, _curpoint];
		};
	};
	_ret set [count _ret, [_endpoint select 1, _endpoint select 2, 0]];
	_ret
};

FUNC(WorldBoundsCheck) = {
	private "_pos";
	_pos = _this;
	if (_pos select 0 < 0) then {_pos set [0, 400]};
	if (_pos select 1 < 0) then {_pos set [1, 400]};
	if (_pos select 0 > (GVAR(island_x_max) - 2)) then {_pos set [0, GVAR(island_x_max) - 400]};
	if (_pos select 1 > (GVAR(island_y_max) - 2)) then {_pos set [1, GVAR(island_y_max) - 400]};
	_pos
};

FUNC(GetSMTargetMessage) = {
	switch (_this) do {
		case "gov_dead": {(localize "STR_DOM_MISSIONSTRING_949")};
		#ifdef __CO__
		case "radar_down": {(localize "STR_DOM_MISSIONSTRING_950")};
		#endif
		#ifdef __OA__
		case "radar_down": {(localize "STR_DOM_MISSIONSTRING_951")};
		#endif
		case "ammo_down": {(localize "STR_DOM_MISSIONSTRING_952")};
		case "apc_down": {(localize "STR_DOM_MISSIONSTRING_953")};
		case "hq_down": {(localize "STR_DOM_MISSIONSTRING_954")};
		case "light_down": {(localize "STR_DOM_MISSIONSTRING_955")};
		case "heavy_down": {(localize "STR_DOM_MISSIONSTRING_956")};
		case "artrad_down": {(localize "STR_DOM_MISSIONSTRING_957")};
		case "airrad_down": {(localize "STR_DOM_MISSIONSTRING_958")};
		case "lopo_dead": {(localize "STR_DOM_MISSIONSTRING_959")};
		case "dealer_dead": {(localize "STR_DOM_MISSIONSTRING_960")};
		case "sec_over": {(localize "STR_DOM_MISSIONSTRING_961")};
	};
};

FUNC(MTSMTargetKilled) = {
	private "_type";
	_type = _this select (count _this - 1);
	GVAR(side_main_done) = true;
	#ifdef __TT__
	private ["_si", "_type", "_s", "_westmsg", "_eastmsg","_killedby2"];
	_si = side (group (_this select 1));
	_type = if (side (group (_this select 1)) in [west,east]) then {_type} else {"sec_over"};
	_s = _type call FUNC(GetSMTargetMessage);
	if (_type != "sec_over") then {
		_westmsg = if (_si == west) then {_s} else {(localize "STR_DOM_MISSIONSTRING_962")};
		_eastmsg = if (_si == east) then {_s} else {(localize "STR_DOM_MISSIONSTRING_962")};
	} else {
		_westmsg = _s;
		_eastmsg = _s;
	};
	GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","Dummy",["1","",_westmsg,[]],true];
	GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","Dummy",["1","",_eastmsg,[]],true];
	[GVAR(tt_points) select 3,_this select 1] call FUNC(AddPoints);
	_killedby2 = switch (_this select 1) do {case west: {"US"};case east: {"EAST"};default {"N"};};
	if (_killedby2 != "N") then {
		GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","MTSMAnnounce",["1","",_killedby2,[]],["2","",str(GVAR(tt_points) select 3),[]],true];
		GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","MTSMAnnounce",["1","",_killedby2,[]],["2","",str(GVAR(tt_points) select 3),[]],true];
	};
	#else
	private "_s";
	_s = (if (side (_this select 1) == GVAR(side_player)) then {_type} else {"sec_over"}) call FUNC(GetSMTargetMessage);
	GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"Dummy",["1","",_s,[]],true];
	#endif
	["sec_kind",0] call FUNC(NetSetJIP);
};

#ifndef __TT__
GVAR(airmarker_counter) = 0;
FUNC(AirMarkerMove) = {
	private ["_vec", "_markern"];
	_vec = _this;
	sleep 30;
	if (!isNull _vec && alive _vec && canMove _vec && !GVAR(banti_airdown)) then {
		_markern = str(_vec) + str(GVAR(airmarker_counter));
		__INC(GVAR(airmarker_counter));
		[_markern, [0,0,0],"ICON","ColorRed",[0.5,0.5],(localize "STR_DOM_MISSIONSTRING_963"),0,"Air"] call FUNC(CreateMarkerGlobal);
		while {!isNull _vec && alive _vec && canMove _vec && !GVAR(banti_airdown)} do {
			_markern setMarkerPos getPosASL _vec;
			sleep (3 + random 1);
		};
		deleteMarker _markern;
	};
};

GVAR(isledefmarker_counter) = 0;
FUNC(IsleDefMarkerMove) = {
	private ["_grp", "_markern"];
	_grp = _this;
	sleep 30;
	if (!isNull _grp && (_grp call FUNC(GetAliveUnitsGrp)) > 0) then {
		_markern = str(_grp) + "i_d_f_m" + str(GVAR(IsleDefMarkerMove));
		__INC(GVAR(IsleDefMarkerMove));
		[_markern, [0,0,0],"ICON","ColorRed",[0.5,0.5],(localize "STR_DOM_MISSIONSTRING_964"),0,GVAR(isle_defense_marker)] call FUNC(CreateMarkerGlobal);
		while {!isNull _grp && (_grp call FUNC(GetAliveUnitsGrp)) > 0} do {
			private "_lead";
			_lead = leader _grp;
			if (!isNull _lead) then {
				_markern setMarkerPos getPosASL _lead;
			};
			sleep (10 + random 10);
		};
		deleteMarker _markern;
	};
};
#endif

FUNC(getgroup) = {
	if (tolower (typeName _this) == "group") exitwith {_this};
	group _this
};

FUNC(getnearestbuilding) = {
	private ["_building", "_i"];
	_building = nearestBuilding _this;
	_i = 0;
	while {str(_building buildingPos _i) != "[0,0,0]"} do {__INC(_i)};
	[_building, _i]
};

// by Rommel
FUNC(searchNearby) = {
	private ["_group", "_leader", "_behaviour", "_array", "_building", "_indices", "_count", "_units", "_timeout", "_unit", "_gstate"];
	_group = (_this select 0) call FUNC(getgroup);
	_gstate = _group getVariable QGVAR(gstate);
	if (isNil "_gstate") then {_gstate = 2};
	if (_gstate == 2) exitWith {};
	_group lockwp true;
	private ["_leader","_behaviour"];
	_leader = leader _group;
	_behaviour = behaviour _leader;
	_group setbehaviour "combat";
	
	private ["_array", "_building", "_indices"];
	_array = _leader call FUNC(getnearestbuilding);
	if (count _array < 2) exitWith {_group lockwp false};
	_building = _array select 0;
	if (_leader distance _building > 200) exitWith {_group lockwp false};
	_indices = _array select 1;
	_group setformdir ([_leader, _building] call FUNC(DirTo));
	
	private ["_count","_units"];
	_units = units _group;
	_count = (count _units) - 1;
	
	_timeout = time + 600;
	
	while {_indices > 0 && _count > 0 && _timeout > time} do {
		sleep 10;
		while {_indices > 0 && _count > 0 && _timeout > time} do {
			private "_unit";
			_unit = _units select _count;
			if (unitready _unit) then {
				_unit commandmove (_building buildingpos _indices);
				_indices = _indices - 1;
			};
			_count = _count - 1;
		};
		_units = units _group;
		_count = (count _units) - 1;
	};
	waituntil {sleep 3;	{unitready _x} count _units >= count (units _group) - 1 || (_units call FUNC(GetAliveUnits)) == 0 || time > _timeout};
	if ((_units call FUNC(GetAliveUnits)) > 0) then {
		{_x dofollow _leader} foreach _units;
		_group setbehaviour _behaviour;
		_group lockwp false;
	};
};

if (GVAR(NoMHQTeleEnemyNear) > 0) then {
	FUNC(createMHQEnemyTeleTrig) = {
		private ["_mhq", "_trig", "_trigger"];
		_mhq = _this;
		
		_trig = GV(_mhq,GVAR(enemy_trigger));
		if (!isNil "_trig") then {
			if (!isNull _trig) then {
				deleteVehicle _trig;
			};
			_mhq setVariable [QGVAR(enemy_trigger), nil];
		};
		
		_trigger = [
		position _mhq,
		[GVAR(NoMHQTeleEnemyNear), GVAR(NoMHQTeleEnemyNear), 0, false],
		[GVAR(enemy_side), "PRESENT", true],
		["this",
		format ["%1 setVariable ['d_enemy_near', true, true]", str(_mhq)],
		format ["%1 setVariable ['d_enemy_near', false, true]", str(_mhq)]
		]
		] call FUNC(CreateTrigger);
		
		_mhq setVariable [QGVAR(enemy_trigger), _trigger];
		
		_trigger attachTo [_mhq, [0,0,0]];
	};
	
	FUNC(removeMHQEnemyTeleTrig) = {
		private ["_mhq", "_trig"];
		_mhq = _this;
		_trig = GV(_mhq,GVAR(enemy_trigger));
		if (!isNil "_trig") then {
			if (!isNull _trig) then {
				deleteVehicle _trig;
			};
		};
		_mhq setVariable [QGVAR(enemy_trigger), nil];
		_mhq setVariable [QGVAR(enemy_near), false, true];
	};
};

FUNC(TKR) = {
	PARAMS_2(_unit,_killer);
	_par = GVAR(player_store) getVariable (getPlayerUID _unit);
	__TRACE_1("_unit",_par);
	_namep = if (isNil "_par") then {"Unknown"} else {_par select 6};
	_par = GVAR(player_store) getVariable (getPlayerUID _killer);
	__TRACE_1("_killer",_par);
	_namek = if (isNil "_par") then {"Unknown"} else {_par select 6};
	[_namek, _namep, _killer] call FUNC(TKKickCheck);
	[QGVAR(unit_tk2), [_namep,_namek]] call FUNC(NetCallEventToClients);
};

FUNC(fuelCheck) = {
	private "_vec";
	PARAMS_1(_vec);
	_vec setVariable [QGVAR(fuel), fuel _vec];
};
