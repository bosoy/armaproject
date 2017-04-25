// by Xeno
#define THIS_FILE "x_farp.sqf"
#include "x_setup.sqf"
private ["_nos", "_notruck", "_vt", "_helper1", "_helper2", "_helper3", "_helper4", "_mt", "_helper", "_farptype", "_farp", "_exitit"];

if (__pGetVar(GVAR(isinaction))) exitWith {
	GVAR(commandingMenuIniting) = false;
};

if (player distance GVAR(name_flag_base) < 30) exitWith {
	(localize "STR_DOM_MISSIONSTRING_246") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

if ((player call FUNC(GetHeight)) > 5) exitWith {
	(localize "STR_DOM_MISSIONSTRING_241") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

_d_farp_pos = __pGetVar(GVAR(farp_pos));
if (count _d_farp_pos > 0) exitWith {
	(localize "STR_DOM_MISSIONSTRING_242") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

_nos = (position player) nearEntities ["Truck", 20];
_notruck = true;
if (count _nos > 0) then {
	{
		_vt = GV(_x,GVAR(vec_type));
		if (isNil "_vt") then {_vt = ""};
		if (_vt == "Engineer") exitWith {_notruck = false};
	} forEach _nos;
};

if (_notruck) exitWith {
	(localize "STR_DOM_MISSIONSTRING_243") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

_d_farp_pos = player modeltoworld [0,8,0];
_d_farp_pos set [2,0];

if (surfaceIsWater [_d_farp_pos select 0, _d_farp_pos select 1]) exitWith {
	(localize "STR_DOM_MISSIONSTRING_244") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

_exitit = false;
if (GVAR(with_ranked)) then {
	if (score player < (GVAR(ranked_a) select 20)) then {
		(format [(localize "STR_DOM_MISSIONSTRING_245"), score player, GVAR(ranked_a) select 20]) call FUNC(HQChat);
		_exitit = true;
	};
};
if (_exitit) exitWith {
	GVAR(commandingMenuIniting) = false;
};

_helper1 = GVAR(HeliHEmpty) createVehicleLocal [_d_farp_pos select 0, (_d_farp_pos select 1) + 4, 0];
_helper2 = GVAR(HeliHEmpty) createVehicleLocal [_d_farp_pos select 0, (_d_farp_pos select 1) - 4, 0];
_helper3 = GVAR(HeliHEmpty) createVehicleLocal [(_d_farp_pos select 0) + 4, _d_farp_pos select 1, 0];
_helper4 = GVAR(HeliHEmpty) createVehicleLocal [(_d_farp_pos select 0) - 4, _d_farp_pos select 1, 0];

_exit_it = false;
if ((abs (((getPosASL _helper1) select 2) - ((getPosASL _helper2) select 2)) > 2) || (abs (((getPosASL _helper3) select 2) - ((getPosASL _helper4) select 2)) > 2)) then {
	(localize "STR_DOM_MISSIONSTRING_246") call FUNC(GlobalChat);
	_exit_it = true;
};

for "_mt" from 1 to 4 do {call compile format ["deleteVehicle _helper%1;", _mt]};

if (_exit_it) exitWith {
	GVAR(commandingMenuIniting) = false;
};

__pSetVar [QGVAR(isinaction), true];

if (GVAR(with_ranked)) then {[QGVAR(pas), [player, (GVAR(ranked_a) select 20) * -1]] call FUNC(NetCallEventCTS)};

player playMove "AinvPknlMstpSlayWrflDnon_medic";
sleep 3;
waitUntil {animationState player != "AinvPknlMstpSlayWrflDnon_medic"};
GVAR(commandingMenuIniting) = false;
if (!alive player) exitWith {
	(localize "STR_DOM_MISSIONSTRING_247") call FUNC(GlobalChat);
	__pSetVar [QGVAR(isinaction), false];
};

_dir_to_set = getdir player;

#ifndef __CO__
_farptype = switch (GVAR(player_side)) do {
	case west: {"US_WarfareBVehicleServicePoint_Base_EP1"};
	case east: {"TK_WarfareBVehicleServicePoint_Base_EP1"};
};
#else
_farptype = switch (GVAR(player_side)) do {
	case west: {"USMC_WarfareBVehicleServicePoint"};
	case east: {"RU_WarfareBVehicleServicePoint"};
};
#endif

_farp = createVehicle [_farptype, _d_farp_pos, [], 0, "NONE"];
_farp setdir _dir_to_set;
_farp setPos _d_farp_pos;
[_farp, 0] call FUNC(SetHeight);
player reveal _farp;
_d_farp_pos = position _farp;
__pSetVar [QGVAR(farp_pos), _d_farp_pos];

__pSetVar [QGVAR(farp_obj), _farp];

_farpsar = __XJIPGetVar(GVAR(farps));
_farpsar set [count _farpsar, _farp];
__XJIPSetVar [QGVAR(farps), _farpsar, true];

(localize "STR_DOM_MISSIONSTRING_248") call FUNC(GlobalChat);
_m_name = "FARP " + GVAR(string_player);
[QGVAR(p_o_a), [GVAR(string_player), [_farp,_m_name,GVAR(name_pl),GVAR(player_side)]]] call FUNC(NetCallEvent);

_farp addAction [(localize "STR_DOM_MISSIONSTRING_249") call FUNC(RedText), "x_client\x_removefarp.sqf"];

[QGVAR(farp_e), _farp] call FUNC(NetCallEventToClients);

__pSetVar [QGVAR(isinaction), false];
