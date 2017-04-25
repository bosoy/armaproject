// by Xeno
#define THIS_FILE "x_getbonus.sqf"
#include "x_setup.sqf"
private ["_chance", "_btype", "_vec_type", "_vecclass", "_bonus_num", "_d_bonus_create_pos", "_d_bonus_air_positions", "_d_bonus_vec_positions", "_d_bap_counter", "_d_bvp_counter", "_btype_e", "_btype_w", "_bonus_num_e", "_vec_typex", "_bonus_num_w", "_d_bonus_create_pos2", "_vec_type2", "_d_bonus_air_positions2", "_d_bonus_vec_positions2", "_d_bvp_counter2", "_d_bap_counter2", "_vehicle", "_endpos", "_dir", "_vehicle2", "_endpos2", "_dir2","_airval", "_bonus_number"];

if (!isServer) exitWith {};

if (GVAR(MissionType) == 2 || GVAR(sideMissionBonus) == 1) exitWith {
	[QGVAR(sm_res_client), [GVAR(side_mission_winner), ""]] call FUNC(NetCallEventToClients);
#ifndef __TT__
	GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"MissionAccomplished",true];
#else
	if (GVAR(side_mission_winner) == 1) then {
		GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","MissionFailure",true];
		GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","MissionAccomplished",true];
	} else {
		GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","MissionAccomplished",true];
		GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","MissionFailure",true];
	};
#endif

	if (!X_SPE) then {GVAR(side_mission_winner) = 0};
};

#ifndef __TT__
_vec_type = "";
if (GVAR(current_sm_bonus_vec) == "") then {
	_airval = 72;
	_chance = 0;

	if (GVAR(land_bonus_vecs) == 0) then {
		_chance = _airval + 1;
	} else {
		if (GVAR(air_bonus_vecs) == 0) then {
			_chance = 0;
		} else {
			if (GVAR(air_bonus_vecs) > GVAR(land_bonus_vecs)) then {
				_airval = floor ((GVAR(land_bonus_vecs) / GVAR(air_bonus_vecs)) * 100);
			};
			_chance = floor (random 100);
		};
	};

	_btype = "";

	while {_btype == ""} do {
		_bonus_number = GVAR(sm_bonus_vehicle_array) call FUNC(RandomFloorArray);
		_vec_type = GVAR(sm_bonus_vehicle_array) select _bonus_number;
		_vecclass = toUpper (getText(configFile >> "CfgVehicles" >> _vec_type >> "vehicleClass"));
		if (_chance > _airval) then {
			if (_vecclass == "AIR") then {if (GVAR(last_bonus_vec) != _vec_type) then {_btype = _vec_type}};
		} else {
			if (_vecclass != "AIR") then {if (GVAR(last_bonus_vec) != _vec_type) then {_btype = _vec_type}};
		};
		sleep 0.01;
	};
} else {
	_vec_type = GVAR(current_sm_bonus_vec);
	GVAR(current_sm_bonus_vec) = "";
};

GVAR(last_bonus_vec) = _vec_type;
_bonus_num = _bonus_number;
_d_bonus_create_pos = GVAR(bonus_create_pos);
//_vec_type = GVAR(sm_bonus_vehicle_array) select _bonus_number;
_d_bonus_air_positions = GVAR(bonus_air_positions);
_d_bonus_vec_positions = GVAR(bonus_vec_positions);
_d_bap_counter = GVAR(bap_counter);
_d_bvp_counter = GVAR(bvp_counter);
#else
_airval = 50;
_chance = floor (random 100);

_bonus_number = 1;
_btype_e = "";
_btype_w = "";

switch (GVAR(side_mission_winner)) do {
	case 1: {
		if (GVAR(current_sm_bonus_vec) select 1 == "") then {
			while {_btype_e == ""} do {
				_bonus_num_e = (GVAR(sm_bonus_vehicle_array) select 1) call FUNC(RandomFloorArray);
				_vec_typex = (GVAR(sm_bonus_vehicle_array) select 1) select _bonus_num_e;
				_vecclass = toUpper (getText(configFile >> "CfgVehicles" >> _vec_typex >> "vehicleClass"));
				// 50 % chance for an Air vehicle now
				if (_chance > _airval) then {
					if (_vecclass == "AIR") then {_btype_e = _vec_typex};
				} else {
					if (_vecclass != "AIR") then {_btype_e = _vec_typex};
				};
				sleep 0.01;
			};
		} else {
			_btype_e = GVAR(current_sm_bonus_vec) select 1;
		};
		_d_bonus_create_pos = GVAR(bonus_create_pos_e);
		_vec_type = _btype_e;
		_d_bonus_air_positions = GVAR(bonus_air_positions_e);
		_d_bonus_vec_positions = GVAR(bonus_vec_positions_e);
		_d_bvp_counter = GVAR(bvp_counter_e);
		_d_bap_counter = GVAR(bap_counter_e);
	};
	case 2: {
		if (GVAR(current_sm_bonus_vec) select 0 == "") then {
			while {_btype_w == ""} do {
				_bonus_num_w = (GVAR(sm_bonus_vehicle_array) select 0) call FUNC(RandomFloorArray);
				_vec_typex = (GVAR(sm_bonus_vehicle_array) select 0) select _bonus_num_w;
				_vecclass = toUpper (getText(configFile >> "CfgVehicles" >> _vec_typex >> "vehicleClass"));
				// 50 % chance for an Air vehicle now
				if (_chance > _airval) then {
					if (_vecclass == "AIR") then {_btype_w = _vec_typex};
				} else {
					if (_vecclass != "AIR") then {_btype_w = _vec_typex};
				};
				sleep 0.01;
			};
		} else {
			_btype_w = GVAR(current_sm_bonus_vec) select 0;
		};
		_d_bonus_create_pos = GVAR(bonus_create_pos_w);
		_vec_type = _btype_w;
		_d_bonus_air_positions = GVAR(bonus_air_positions_w);
		_d_bonus_vec_positions = GVAR(bonus_vec_positions_w);
		_d_bvp_counter = GVAR(bvp_counter_w);
		_d_bap_counter = GVAR(bap_counter_w);
	};
	case 123: {
		if (GVAR(current_sm_bonus_vec) select 1 == "") then {
			while {_btype_e == ""} do {
				_bonus_num_e = (GVAR(sm_bonus_vehicle_array) select 1) call FUNC(RandomFloorArray);
				_vec_typex = (GVAR(sm_bonus_vehicle_array) select 1) select _bonus_num_e;
				_vecclass = toUpper (getText(configFile >> "CfgVehicles" >> _vec_typex >> "vehicleClass"));
				// 50 % chance for an Air vehicle now
				if (_chance > _airval) then {
					if (_vecclass == "AIR") then {_btype_e = _vec_typex};
				} else {
					if (_vecclass != "AIR") then {_btype_e = _vec_typex};
				};
				sleep 0.01;
			};
		} else {
			_btype_e = GVAR(current_sm_bonus_vec) select 1;
		};
		_d_bonus_create_pos = GVAR(bonus_create_pos_e);
		_vec_type = _btype_e;
		_d_bonus_air_positions = GVAR(bonus_air_positions_e);
		_d_bonus_vec_positions = GVAR(bonus_vec_positions_e);
		_d_bvp_counter = GVAR(bvp_counter_e);
		_d_bap_counter = GVAR(bap_counter_e);
		
		if (GVAR(current_sm_bonus_vec) select 0 == "") then {
			while {_btype_w == ""} do {
				_bonus_num_w = (GVAR(sm_bonus_vehicle_array) select 0) call FUNC(RandomFloorArray);
				_vec_typex = (GVAR(sm_bonus_vehicle_array) select 0) select _bonus_num_w;
				_vecclass = toUpper (getText(configFile >> "CfgVehicles" >> _vec_typex >> "vehicleClass"));
				// 50 % chance for an Air vehicle now
				if (_chance > _airval) then {
					if (_vecclass == "AIR") then {_btype_w = _vec_typex};
				} else {
					if (_vecclass != "AIR") then {_btype_w = _vec_typex};
				};
				sleep 0.01;
			};
		} else {
			_btype_w = GVAR(current_sm_bonus_vec) select 0;
		};
		
		_d_bonus_create_pos2 = GVAR(bonus_create_pos_w);
		_vec_type2 = _btype_w;
		_d_bonus_air_positions2 = GVAR(bonus_air_positions_w);
		_d_bonus_vec_positions2 = GVAR(bonus_vec_positions_w);
		_d_bvp_counter2 = GVAR(bvp_counter_w);
		_d_bap_counter2 = GVAR(bap_counter_w);
	};
};
GVAR(current_sm_bonus_vec) = ["",""];
#endif

sleep 1.012;

#ifndef __TT__
_vehicle = createVehicle [_vec_type, _d_bonus_create_pos, [], 0, "NONE"];
_endpos = [];
_dir = 0;

if (_vehicle isKindOf "Air") then {
	_endpos = (_d_bonus_air_positions select _d_bap_counter) select 0;
	_dir = (_d_bonus_air_positions select _d_bap_counter) select 1;
	__INC(GVAR(bap_counter));
	if (GVAR(bap_counter) > (count _d_bonus_air_positions - 1)) then {GVAR(bap_counter) = 0};
} else {
	_endpos = (_d_bonus_vec_positions select _d_bvp_counter) select 0;
	_dir = (_d_bonus_vec_positions select _d_bvp_counter) select 1;
	__INC(GVAR(bvp_counter));
	if (GVAR(bvp_counter) > (count _d_bonus_vec_positions - 1)) then {GVAR(bvp_counter) = 0};
};

_vehicle setDir _dir;
_vehicle setPos _endpos;

_vehicle execFSM "fsms\Wreckmarker.fsm";
#else
_vehicle2 = objNull;

_vehicle = createVehicle [_vec_type, _d_bonus_create_pos, [], 0, "NONE"];
if (GVAR(side_mission_winner) == 123) then {
	_vehicle2 = createVehicle [_vec_type2, _d_bonus_create_pos2, [], 0, "NONE"];
};

if (_vehicle isKindOf "Air") then {
	_endpos = (_d_bonus_air_positions select _d_bap_counter) select 0;
	_dir = (_d_bonus_air_positions select _d_bap_counter) select 1;
	switch (GVAR(side_mission_winner)) do {
		case 1: {
			_vehicle setVariable ["D_VEC_SIDE", 1];
			__INC(GVAR(bap_counter_e));
			if (GVAR(bap_counter_e) > (count _d_bonus_air_positions - 1)) then {GVAR(bap_counter_e) = 0};
		};
		case 2: {
			_vehicle setVariable ["D_VEC_SIDE", 2];
			__INC(GVAR(bap_counter_w));
			if (GVAR(bap_counter_w) > (count _d_bonus_air_positions - 1)) then {GVAR(bap_counter_w) = 0};
		};
		case 123: {
			_vehicle setVariable ["D_VEC_SIDE", 1];
			_vehicle2 setVariable ["D_VEC_SIDE", 2];
			__INC(GVAR(bap_counter_e));
			if (GVAR(bap_counter_e) > (count _d_bonus_air_positions - 1)) then {GVAR(bap_counter_e) = 0};
			__INC(GVAR(bap_counter_w));
			if (GVAR(bap_counter_w) > (count _d_bonus_air_positions2 - 1)) then {GVAR(bap_counter_w) = 0};
		};
	};
} else {
	_endpos = (_d_bonus_vec_positions select _d_bvp_counter) select 0;
	_dir = (_d_bonus_vec_positions select _d_bvp_counter) select 1;
	switch (GVAR(side_mission_winner)) do {
		case 1: {
			_vehicle setVariable ["D_VEC_SIDE", 1];
			__INC(GVAR(bvp_counter_e));
			if (GVAR(bvp_counter_e) > (count _d_bonus_vec_positions - 1)) then {GVAR(bvp_counter_e) = 0};
		};
		case 2: {
			_vehicle setVariable ["D_VEC_SIDE", 2];
			__INC(GVAR(bvp_counter_w));
			if (GVAR(bvp_counter_w) > (count _d_bonus_vec_positions - 1)) then {GVAR(bvp_counter_w) = 0};
		};
		case 123: {
			_vehicle setVariable ["D_VEC_SIDE", 1];
			_vehicle2 setVariable ["D_VEC_SIDE", 2];
			__INC(GVAR(bvp_counter_e));
			if (GVAR(bvp_counter_e) > (count _d_bonus_vec_positions - 1)) then {GVAR(bvp_counter_e) = 0};
			__INC(GVAR(bvp_counter_w));
			if (GVAR(bvp_counter_w) > (count _d_bonus_vec_positions2 - 1)) then {GVAR(bvp_counter_w) = 0};
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

_vehicle setDir _dir;
_vehicle setPos _endpos;
_vehicle setVariable [QGVAR(WreckMaxRepair), GVAR(WreckMaxRepair), true];
_vehicle execFSM "fsms\Wreckmarker.fsm";
if (!isNull _vehicle2) then {
	_vehicle2 setDir _dir2;
	_vehicle2 setPos _endpos2;
	_vehicle2 setVariable [QGVAR(WreckMaxRepair), GVAR(WreckMaxRepair), true];
	_vehicle2 execFSM "fsms\Wreckmarker.fsm";
};
#endif

[QGVAR(sm_res_client), [GVAR(side_mission_winner),_vec_type]] call FUNC(NetCallEventToClients);
#ifndef __TT__
GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"MissionAccomplished",true];
#else
if (GVAR(side_mission_winner) == 1) then {
	GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","MissionFailure",true];
	GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","MissionAccomplished",true];
} else {
	if (GVAR(side_mission_winner) == 2) then {
		GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","MissionAccomplished",true];
		GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","MissionFailure",true];
	} else {
		if (GVAR(side_mission_winner) == 123) then {
			GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","MissionAccomplished",true];
			GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","MissionAccomplished",true];
		} else {
			GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","MissionFailure",true];
			GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","MissionFailure",true];
		};
	};
};
#endif

if (!X_SPE) then {GVAR(side_mission_winner) = 0};