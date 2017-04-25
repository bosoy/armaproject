// by Xeno
#define THIS_FILE "x_sideflag.sqf"
#include "x_setup.sqf"
private ["_posi_array", "_ran", "_ran_pos", "_flagtype", "_ini_str", "_flag", "_owner"];

if (!isServer) exitWith {};

PARAMS_1(_posi_array);

_ran = _posi_array call FUNC(RandomFloorArray);
_ran_pos = _posi_array select _ran;

_posi_array = nil;

if (GVAR(with_ranked)) then {GVAR(sm_p_pos) = nil};

_flagtype = switch (GVAR(enemy_side)) do {
	case "WEST": {"FWEST" call FUNC(StoreGet)};
	case "EAST": {"FEAST" call FUNC(StoreGet)};
	case "GUER": {"FGUER" call FUNC(StoreGet)};
};

_flag = createVehicle [_flagtype, _ran_pos, [], 0, "NONE"];
_flag setPos _ran_pos;

switch (GVAR(enemy_side)) do {
	case "WEST": {_flag setflagside west};
	case "EAST": {_flag setflagside east};
	case "GUER": {_flag setflagside resistance};
};

sleep 2.123;
["shilka", 1, "bmp", 1, "tank", 1, _ran_pos,1,350,true] spawn FUNC(CreateArmor);
sleep 2.123;
["specops", 2, "basic", 1, _ran_pos,250,true] spawn FUNC(CreateInf);

_ran_pos = nil;
_ran = nil;
_flagtype = nil;
_ini_str = nil;

sleep 15.111;

while {true} do {
	__MPCheck;
	_owner = flagOwner _flag;
	#ifndef __TT__
	if (!isNull _owner && (_owner distance GVAR(FLAG_BASE) < 20)) exitWith {
		if (__RankedVer) then {[QGVAR(sm_p_pos), position GVAR(FLAG_BASE)] call FUNC(NetCallEventToClients)};
		_flag setFlagOwner objNull;
		deleteVehicle _flag;
		GVAR(side_mission_winner) = 2;
		GVAR(side_mission_resolved) = true;
	};
	#else
	if (!isNull _owner && (_owner distance GVAR(EFLAG_BASE) < 20)) exitWith {
		if (__RankedVer) then {[QGVAR(sm_p_pos), position GVAR(EFLAG_BASE)] call FUNC(NetCallEventToClients)};
		_flag setFlagOwner objNull;
		deleteVehicle _flag;
		GVAR(side_mission_winner) = 1;
		GVAR(side_mission_resolved) = true;
	};
	if (!isNull _owner && (_owner distance GVAR(WFLAG_BASE) < 20)) exitWith {
		if (__RankedVer) then {[QGVAR(sm_p_pos), position GVAR(WFLAG_BASE)] call FUNC(NetCallEventToClients)};
		_flag setFlagOwner objNull;
		deleteVehicle _flag;
		GVAR(side_mission_winner) = 2;
		GVAR(side_mission_resolved) = true;
	};
	#endif
	sleep 5.123;
};