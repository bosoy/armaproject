// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_server\x_createsecondary.sqf"
#include "x_setup.sqf"

#define __getPos \
_poss = [_posarx, _mtradius] call FUNC(GetRanPointCircleBig);\
if (isOnRoad _poss) then {_poss = []};\
while {count _poss == 0} do {\
	_poss = [_posarx, _mtradius] call FUNC(GetRanPointCircleBig);\
	if (isOnRoad _poss) then {_poss = []};\
	sleep 0.01;\
}

#define __specops \
__GetEGrp(_newgroup)\
_unit_array = [#specops, GVAR(enemy_side)] call FUNC(getunitliste);\
[_poss, _unit_array select 0, _newgroup,true] spawn FUNC(makemgroup);\
sleep 1.0112;\
_newgroup allowFleeing 0;\
_newgroup setVariable [QGVAR(defend), true]; \
[_newgroup,_poss] call FUNC(taskDefend); \
GVAR(reduce_groups) set [count GVAR(reduce_groups), _newgroup]

private ["_poss", "_newgroup", "_vehicle", "_mtmhandle", "_dummy", "_act2", "_nrcamps", "_i", "_wf", "_flagPole", "_trg_center", "_posarx"];
if (!isServer) exitWith {};

PARAMS_3(_wp_array,_mtradius,_trg_center);

sleep 5.234;
_d_currentcamps = [];
GVAR(east_camps) = [];
GVAR(west_camps) = [];
_nrcamps = ceil random 5;
if (_nrcamps < 3) then {_nrcamps = 3};
__TRACE_1("","_nrcamps")
_ctype = GVAR(wcamp);

GVAR(sum_camps) = _nrcamps * 2;
// east camps first
_posarx = GVAR(east_main_location_pos);
for "_i" from 1 to _nrcamps do {
	__getPos;
	_wf = createVehicle [_ctype, _poss, [], 0, "NONE"];
	_wf setDir (floor random 360);
	_wf setPos _poss;
	_d_currentcamps set [count _d_currentcamps, _wf];
	GVAR(east_camps) set [count GVAR(east_camps), _wf];
	_wf setVariable [QGVAR(SIDE), "EAST", true];
	_wf setVariable [QGVAR(INDEX), _i, true];
	_wf setVariable [QGVAR(CAPTIME), 40 + (floor random 10), true];
	_wf setVariable [QGVAR(CURCAPTIME), 0, true];
	_wf setVariable [QGVAR(CURCAPTURER), ""];
	_wf setVariable [QGVAR(STALL), false, true];
	_wf setVariable [QGVAR(TARGET_MID_POS), GVAR(east_main_location_pos)];
	
	_flagPole = createVehicle ["EAST" call FUNC(GetSideFlagType), position _wf, [], 0, "NONE"];
	_flagPole setPos [getPosASL _wf select 0, getPosASL _wf select 1, 0];
	_wf setVariable [QGVAR(FLAG), _flagPole];
	_maname = format["dcampe%1",_i];
	_wf setVariable [QGVAR(markername), _maname];
	[_maname, _poss,"ICON","ColorBlack",[0.5,0.5],"",0,"Strongpoint"] call FUNC(CreateMarkerGlobal);
	
	_wf addEventHandler ["HandleDamage", {0}];
	[_wf, _flagPole] execFSM "fsms\HandleCamp4.fsm";
	__TRACE_1("east wf","_wf")
	sleep 0.5;
};

// then west camps
_posarx = GVAR(west_main_location_pos);
for "_i" from 1 to _nrcamps do {
	__getPos;
	_wf = createVehicle [_ctype, _poss, [], 0, "NONE"];
	_wf setDir (floor random 360);
	_wf setPos _poss;
	_d_currentcamps set [count _d_currentcamps, _wf];
	GVAR(west_camps) set [count GVAR(west_camps), _wf];
	_wf setVariable [QGVAR(SIDE), "WEST", true];
	_wf setVariable [QGVAR(INDEX), _i, true];
	_wf setVariable [QGVAR(CAPTIME), 40 + (floor random 10), true];
	_wf setVariable [QGVAR(CURCAPTIME), 0, true];
	_wf setVariable [QGVAR(CURCAPTURER), ""];
	_wf setVariable [QGVAR(STALL), false, true];
	_wf setVariable [QGVAR(TARGET_MID_POS), GVAR(west_main_location_pos)];
	
	_flagPole = createVehicle ["WEST" call FUNC(GetSideFlagType), position _wf, [], 0, "NONE"];
	_flagPole setPos [getPosASL _wf select 0, getPosASL _wf select 1, 0];
	_wf setVariable [QGVAR(FLAG), _flagPole];
	_maname = format["dcampw%1",_i];
	_wf setVariable [QGVAR(markername), _maname];
	[_maname, _poss,"ICON","ColorBlue",[0.5,0.5],"",0,"Strongpoint"] call FUNC(CreateMarkerGlobal);
	
	_wf addEventHandler ["HandleDamage", {0}];
	[_wf, _flagPole] execFSM "fsms\HandleCamp4.fsm";
	__TRACE_1("west wf","_wf")
	sleep 0.5;
};

__XJIPSetVar [QGVAR(campscaptured_w), _nrcamps, true];
__XJIPSetVar [QGVAR(campscaptured_e), _nrcamps, true];

[QGVAR(currentcamps),_d_currentcamps] call FUNC(NetSetJIP);

GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","CampAnnounce",["1","",str _nrcamps,[]],true];
GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","CampAnnounce",["1","",str _nrcamps,[]],true];

sleep 2;

// TODO: TT 
GVAR(attacktstart_trigger1) = [_trg_center, [_mtradius  + 300, _mtradius + 300, 0, false],[GVAR(own_side_trigger), "PRESENT", false], ["this", "execVM 'x_server\x_createattackgroups.sqf';deleteVehicle d_attacktstart_trigger1;d_attacktstart_trigger1 = nil;if (!isNil 'd_attacktstart_trigger2') then {deleteVehicle d_attacktstart_trigger2;d_attacktstart_trigger2 = nil}", ""]] call FUNC(CreateTrigger);
GVAR(attacktstart_trigger2) = [GVAR(enemyai_mt_attack_pos), [_mtradius  + 300, _mtradius + 300, 0, false],[GVAR(own_side_trigger), "PRESENT", false], ["this", "execVM 'x_server\x_createattackgroups.sqf';deleteVehicle d_attacktstart_trigger2;d_attacktstart_trigger2 = nil;if (!isNil 'd_attacktstart_trigger1') then {deleteVehicle d_attacktstart_trigger1;d_attacktstart_trigger1 = nil}", ""]] call FUNC(CreateTrigger);
__TRACE_1("","_mtradius")

if (isNil "d_fnc_mtdone") then {
	FUNC(mtdone) = {
		GVAR(mt_done) = true;
		execVM "x_server\x_target_clear4.sqf";
	};
};

GVAR(mt_end_trigger) = [[0,0,0], [0, 0, 0, false],["ANY", "PRESENT", false], ["(X_JIPH getVariable 'd_campscaptured_w') == d_sum_camps || (X_JIPH getVariable 'd_campscaptured_e') == d_sum_camps", "call d_fnc_mtdone;deleteVehicle d_mt_end_trigger; d_mt_end_trigger = nil", ""]] call FUNC(CreateTrigger);

sleep 5.213;
GVAR(main_target_ready) = true;