// by Xeno
#define THIS_FILE "x_createpara2.sqf"
#include "x_setup.sqf"
#define __exitchop if (isNull _chopper || !alive _chopper || !canMove _chopper || !alive driver _chopper) exitWith {[_crew_vec, _chopper,240 + random 100] spawn _delveccrew}
private ["_assigned","_helifirstpoint","_chopper","_paragrp","_pos_end","_u","_unit_array","_vgrp","_wp","_xx","_heliendpoint","_wp2","_del_me","_delveccrew","_crew_vec"];
if (!isServer) exitWith {};

PARAMS_4(_vgrp,_chopper,_helifirstpoint,_heliendpoint);
_crew_vec = crew _chopper;

sleep 2.123;

_wp = _vgrp addWaypoint [_helifirstpoint, 30];
_wp setWaypointBehaviour "CARELESS";
_wp setWaypointSpeed "NORMAL";
_wp setwaypointtype "MOVE";
_wp setWaypointFormation "WEDGE";

_wp2 = _vgrp addWaypoint [_heliendpoint, 0];
_wp2 setwaypointtype "MOVE";
_wp2 setWaypointBehaviour "CARELESS";
_wp2 setWaypointSpeed "NORMAL";
_wp2 setwaypointtype "MOVE";

_chopper flyinheight 100;

#ifndef __TT__
if (!GVAR(banti_airdown)) then {_chopper spawn FUNC(AirMarkerMove)};
if ((__XJIPGetVar(GVAR(searchintel)) select 0) == 1) then {
	GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"TellInfiltrateAttack",true];
};
#endif

_parachute_type = GVAR(enemy_side) call FUNC(GetParachuteSide);

_delveccrew = {
	private ["_crew_vec","_vehicle","_time"];
	PARAMS_3(_crew_vec,_vehicle,_time);
	sleep _time;
	{if (!isNull _x) then {_x setDamage 1.1}} forEach _crew_vec;
	sleep 1;
	if (!isNull _vehicle && ({isPlayer _x} count (crew _vehicle)) == 0) then {_vehicle setDamage 1};
};

while {_helifirstpoint distance (leader _vgrp) > 150} do {
	__exitchop;
	sleep 2.123;
};

if (alive _chopper && !isNull _chopper && canMove _chopper && alive driver _chopper) then {
	__GetEGrp(_paragrp)
	_unit_array = ["sabotage", GVAR(enemy_side)] call FUNC(getunitliste);
	_real_units = _unit_array select 0;
	_unit_array = nil;
	sleep 0.1;
	{
		_one_unit = _paragrp createunit [_x, [0,0,0], [], 300,"NONE"];
		if (GVAR(without_nvg) == 0) then {
			if (_one_unit hasWeapon "NVGoggles") then {_one_unit removeWeapon "NVGoggles"};
		};
		_one_unit setVariable ["BIS_noCoreConversations", true];
		[_one_unit, {__addDeadAI(_this)}] call FUNC(setUnitCode);
		if (GVAR(domdatabase)) then {
			[_one_unit, {_this addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddAIKillPoints)}}]}] call FUNC(setUnitCode);
		};
#ifdef __TT__
		[_one_unit, {_this addEventHandler ["killed", {[[15, 3, 2, 1],_this select 1, _this select 0] call FUNC(AddKills)}]}] call FUNC(setUnitCode);
#endif
		if (GVAR(with_ai)) then {
			if (__RankedVer) then {
				[_one_unit, {_this addEventHandler ["killed", {[1,_this select 1] call FUNC(AddKillsAI)}]}] call FUNC(setUnitCode);
			};
		};
		_one_unit setSkill ((GVAR(skill_array) select 0) + (random (GVAR(skill_array) select 1)));
		
		_para = createVehicle [_parachute_type, position _chopper, [], 20, 'NONE'];
		_para setDir random 360;
		_para setpos [(position _chopper) select 0, (position _chopper) select 1, ((position _chopper) select 2) - 10];
		_one_unit moveInDriver _para;
		sleep 0.551;
	} forEach _real_units;
	_paragrp allowFleeing 0;
	_paragrp setCombatMode "YELLOW";
	_paragrp setBehaviour "AWARE";
	
	sleep 0.113;
	_paragrp spawn {
		private "_grp";
		_grp = _this;
		sleep 20;
		if ((_grp call FUNC(GetAliveUnitsGrp)) > 0) then {
			[_grp, GVAR(base_array) select 0, [GVAR(base_array) select 0,GVAR(base_array) select 1,GVAR(base_array) select 2,GVAR(base_array) select 3]] spawn FUNC(MakePatrolWPX);
			_grp setVariable [QGVAR(PATR),true];
		};
		GVAR(reduce_groups) set [GVAR(reduce_groups), _grp];
	};
	sleep 0.112;
	[_paragrp] execVM "x_server\x_sabotage.sqf";
};

__exitchop;

while {(_heliendpoint distance (leader _vgrp) > 300)} do {
	__exitchop;
	sleep 5.123;
};

if (!isNull _chopper) then {_chopper call FUNC(DelVecAndCrew)};