// by Xeno
#define THIS_FILE "x_gettargetbonus.sqf"
#include "x_setup.sqf"
private ["_vehicle", "_endpos", "_dir", "_extra_bonus_number", "_extra_bonus_number2", "_vehicle2", "_d_bonus_air_positions", "_d_bap_counter", "_d_bonus_vec_positions", "_d_bvp_counter", "_d_bonus_air_positions2", "_d_bap_counter2", "_d_bonus_vec_positions2", "_d_bvp_counter2", "_endpos2", "_dir2", "_cur_tar_obj"];

if (!isServer) exitWith {};

_cur_tar_obj = missionNamespace getVariable format [QGVAR(target_%1), X_JIPH getVariable QUOTE(GVAR(current_target_index))];

sleep 1.012;

private "_vectypetouse";
#ifndef __TT__
_vectypetouse = "";
#else
private ["_vectypetouse_w", "_vectypetouse_e"];
_vectypetouse_w = "";
_vectypetouse_e = "";
#endif

if (GVAR(mainTargetBonus) == 0) then {
	#ifndef __TT__
	if (!isNil "_cur_tar_obj") then {
		if (!isNull _cur_tar_obj) then {
			_vectypesv = GV(_cur_tar_obj,GVAR(bonusvec));
			if (!isNil "_vectypesv") then {
				_vectypetouse = _vectypesv;
			};
		};
	};
	if (_vectypetouse == "") then {
		_vectypetouse = GVAR(mt_bonus_vehicle_array) select (GVAR(mt_bonus_vehicle_array) call FUNC(RandomFloorArray));
	};
	_vehicle = createVehicle [_vectypetouse, GVAR(bonus_create_pos), [], 0, "NONE"];
	_endpos = [];
	_dir = 0;
	if (_vehicle isKindOf "Air") then {
		_endpos = (GVAR(bonus_air_positions) select GVAR(bap_counter)) select 0;
		_dir = (GVAR(bonus_air_positions) select GVAR(bap_counter)) select 1;
		__INC(GVAR(bap_counter));
		if (GVAR(bap_counter) > (count GVAR(bonus_air_positions) - 1)) then {GVAR(bap_counter) = 0};
	} else {
		_endpos = (GVAR(bonus_vec_positions) select GVAR(bvp_counter)) select 0;
		_dir = (GVAR(bonus_vec_positions) select GVAR(bvp_counter)) select 1;
		__INC(GVAR(bvp_counter));
		if (GVAR(bvp_counter) > (count GVAR(bonus_vec_positions) - 1)) then {GVAR(bvp_counter) = 0};
	};
	_vehicle setDir _dir;
	_vehicle setPos _endpos;
	_vehicle execFSM "fsms\Wreckmarker.fsm";
	#else
	if (!isNil "_cur_tar_obj") then {
		if (!isNull _cur_tar_obj) then {
			_vectypesv = GV(_cur_tar_obj,GVAR(bonusvec_w));
			if (!isNil "_vectypesv") then {
				_vectypetouse_w = _vectypesv;
			};
			_vectypesv = GV(_cur_tar_obj,GVAR(bonusvec_e));
			if (!isNil "_vectypesv") then {
				_vectypetouse_e = _vectypesv;
			};
		};
	};

	if (_vectypetouse_w == "") then {
		_extra_bonus_number = (GVAR(mt_bonus_vehicle_array) select 0) call FUNC(RandomFloorArray);
		_vectypetouse_w = (GVAR(mt_bonus_vehicle_array) select 0) select _extra_bonus_number;
	};
	if (_vectypetouse_w == "") then {
		_extra_bonus_number2 = (GVAR(mt_bonus_vehicle_array) select 1) call FUNC(RandomFloorArray);
		_vectypetouse_e = (GVAR(mt_bonus_vehicle_array) select 1) select _extra_bonus_number2;
	};

	_vehicle2 = objNull;

	if (GVAR(mt_winner) == 1) then {
		_vehicle = createVehicle [_vectypetouse_w, GVAR(bonus_create_pos_w), [], 0, "NONE"];
		_vehicle setVariable ["D_VEC_SIDE", 2];
		_d_bonus_air_positions = GVAR(bonus_air_positions_w);
		_d_bap_counter = GVAR(bap_counter_w);
		_d_bonus_vec_positions = GVAR(bonus_vec_positions_w);
		_d_bvp_counter = GVAR(bvp_counter_w);
	} else {
		if (GVAR(mt_winner) == 2) then {
			_vehicle = createVehicle [_vectypetouse_e, GVAR(bonus_create_pos_e), [], 0, "NONE"];
			_vehicle setVariable ["D_VEC_SIDE", 1];
			_d_bonus_air_positions = GVAR(bonus_air_positions_e);
			_d_bap_counter = GVAR(bap_counter_e);
			_d_bonus_vec_positions = GVAR(bonus_vec_positions_e);
			_d_bvp_counter = GVAR(bvp_counter_e);
		} else {
			_vehicle = createVehicle [_vectypetouse_w, GVAR(bonus_create_pos_w), [], 0, "NONE"];
			_vehicle2 = createVehicle [_vectypetouse_e, GVAR(bonus_create_pos_e), [], 0, "NONE"];
			_vehicle setVariable ["D_VEC_SIDE", 2];
			_vehicle2 setVariable ["D_VEC_SIDE", 1];
			_d_bonus_air_positions = GVAR(bonus_air_positions_w);
			_d_bonus_air_positions2 = GVAR(bonus_air_positions_e);
			_d_bap_counter = GVAR(bap_counter_w);
			_d_bap_counter2 = GVAR(bap_counter_e);
			_d_bonus_vec_positions = GVAR(bonus_vec_positions_w);
			_d_bonus_vec_positions2 = GVAR(bonus_vec_positions_e);
			_d_bvp_counter = GVAR(bvp_counter_w);
			_d_bvp_counter2 = GVAR(bvp_counter_e);
		};
	};

	_endpos = [];
	_dir = 0;
	if (_vehicle isKindOf "Air") then {
		_endpos = (_d_bonus_air_positions select _d_bap_counter) select 0;
		_dir = (_d_bonus_air_positions select _d_bap_counter) select 1;
		switch (GVAR(mt_winner)) do {
			case 1: {
				__INC(GVAR(bap_counter_w));
				if (GVAR(bap_counter_w) > (count GVAR(bonus_air_positions_w) - 1)) then {GVAR(bap_counter_w) = 0};
			};
			case 2: {
				__INC(GVAR(bap_counter_e));
				if (GVAR(bap_counter_e) > (count GVAR(bonus_air_positions_e) - 1)) then {GVAR(bap_counter_e) = 0};
			};
			case 3: {
				__INC(GVAR(bap_counter_w));
				if (GVAR(bap_counter_w) > (count GVAR(bonus_air_positions_w) - 1)) then {GVAR(bap_counter_w) = 0};
				__INC(GVAR(bap_counter_e));
				if (GVAR(bap_counter_e) > (count GVAR(bonus_air_positions_e) - 1)) then {GVAR(bap_counter_e) = 0};
			};
		};
	} else {
		_endpos = (_d_bonus_vec_positions select _d_bvp_counter) select 0;
		_dir = (_d_bonus_vec_positions select _d_bvp_counter) select 1;
		switch (GVAR(mt_winner)) do {
			case 1: {
				__INC(GVAR(bvp_counter_w));
				if (GVAR(bvp_counter_w) > (count GVAR(bonus_vec_positions_w) - 1)) then {GVAR(bvp_counter_w) = 0};
			};
			case 2: {
				__INC(GVAR(bvp_counter_e));
				if (GVAR(bvp_counter_e) > (count GVAR(bonus_vec_positions_e) - 1)) then {GVAR(bvp_counter_e) = 0};
			};
			case 3: {
				__INC(GVAR(bvp_counter_w));
				if (GVAR(bvp_counter_w) > (count GVAR(bonus_vec_positions_w) - 1)) then {GVAR(bvp_counter_w) = 0};
				__INC(GVAR(bvp_counter_e));
				if (GVAR(bvp_counter_e) > (count GVAR(bonus_vec_positions_e) - 1)) then {GVAR(bvp_counter_e) = 0};
			};
		};
	};

	if (!isNull _vehicle2) then {
		if (_vehicle2 isKindOf "Air") then {
			_endpos2 = (_d_bonus_air_positions2 select _d_bap_counter2) select 0;
			_dir2 = (_d_bonus_air_positions2 select _d_bap_counter2) select 1;
		} else {
			_endpos2 = (_d_bonus_vec_positions2 select _d_bvp_counter2) select 0;
			_dir2 = (_d_bonus_vec_positions2 select _d_bvp_counter2) select 1;
		};
	};

	_vehicle setPos _endpos;
	_vehicle setDir _dir;
	_vehicle setVariable [QGVAR(WreckMaxRepair), GVAR(WreckMaxRepair), true];
	_vehicle execFSM "fsms\Wreckmarker.fsm";
	if (!isNull _vehicle2) then {
		_vehicle2 setDir _dir2;
		_vehicle2 setPos _endpos2;
		_vehicle2 setVariable [QGVAR(WreckMaxRepair), GVAR(WreckMaxRepair), true];
		_vehicle2 execFSM "fsms\Wreckmarker.fsm";
	};
	#endif
};

["target_clear",true] call FUNC(NetSetJIP);
#ifndef __TT__
[QGVAR(target_clear), _vectypetouse] call FUNC(NetCallEventToClients);
#else
[QGVAR(target_clear), [_vectypetouse_w,_vectypetouse_e]] call FUNC(NetCallEventToClients);
#endif
__TargetInfo
_tname = _current_target_name call FUNC(KBUseName);
#ifndef __TT__
GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"Captured",["1","",_current_target_name,[_tname]],true];
#else
GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","Captured",["1","",_current_target_name,[_tname]],true];
GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","Captured",["1","",_current_target_name,[_tname]],true];
#endif