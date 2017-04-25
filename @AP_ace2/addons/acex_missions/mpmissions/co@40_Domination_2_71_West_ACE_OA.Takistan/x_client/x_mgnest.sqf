// by Xeno
#define THIS_FILE "x_mgnest.sqf"
#include "x_setup.sqf"
private ["_dir_to_set","_m_name","_marker","_d_mgnest_pos","_exit_it"];

if (__pGetVar(GVAR(isinaction))) exitWith {
	GVAR(commandingMenuIniting) = false;
};

if (player distance GVAR(name_flag_base) < 30) exitWith {
	(localize "STR_DOM_MISSIONSTRING_292") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

if ((player call FUNC(GetHeight)) > 5) exitWith {
	(localize "STR_DOM_MISSIONSTRING_241") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

_d_mgnest_pos = __pGetVar(GVAR(mgnest_pos));
if (count _d_mgnest_pos > 0) exitWith {
	(localize "STR_DOM_MISSIONSTRING_289") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

_d_mgnest_pos = player modeltoworld [0,2,0];
_d_mgnest_pos set [2,0];

if (surfaceIsWater [_d_mgnest_pos select 0, _d_mgnest_pos select 1]) exitWith {
	(localize "STR_DOM_MISSIONSTRING_290") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

_exit_it = false;
if (GVAR(with_ranked)) then {
	if (score player < (GVAR(ranked_a) select 14)) then {
		(format [(localize "STR_DOM_MISSIONSTRING_291"), score player,(GVAR(ranked_a) select 14)]) call FUNC(HQChat);
		_exit_it = true;
	};
};

if (_exit_it) exitWith {
	GVAR(commandingMenuIniting) = false;
};

_helper1 = GVAR(HeliHEmpty) createVehicleLocal [_d_mgnest_pos select 0, (_d_mgnest_pos select 1) + 4, 0];
_helper2 = GVAR(HeliHEmpty) createVehicleLocal [_d_mgnest_pos select 0, (_d_mgnest_pos select 1) - 4, 0];
_helper3 = GVAR(HeliHEmpty) createVehicleLocal [(_d_mgnest_pos select 0) + 4, _d_mgnest_pos select 1, 0];
_helper4 = GVAR(HeliHEmpty) createVehicleLocal [(_d_mgnest_pos select 0) - 4, _d_mgnest_pos select 1, 0];

_exit_it = false;
if ((abs (((getPosASL _helper1) select 2) - ((getPosASL _helper2) select 2)) > 2) || (abs (((getPosASL _helper3) select 2) - ((getPosASL _helper4) select 2)) > 2)) then {
	(localize "STR_DOM_MISSIONSTRING_292") call FUNC(GlobalChat);
	_exit_it = true;
};

for "_mt" from 1 to 4 do {call compile format ["deleteVehicle _helper%1;", _mt]};

if (_exit_it) exitWith {
	GVAR(commandingMenuIniting) = false;
};

__pSetVar [QGVAR(isinaction), true];

if (GVAR(with_ranked)) then {[QGVAR(pas), [player, (GVAR(ranked_a) select 14) * -1]] call FUNC(NetCallEventCTS)};

player playMove "AinvPknlMstpSlayWrflDnon_medic";
sleep 3;
waitUntil {animationState player != "AinvPknlMstpSlayWrflDnon_medic"};
GVAR(commandingMenuIniting) = false;
if (!alive player) exitWith {
	(localize "STR_DOM_MISSIONSTRING_293") call FUNC(GlobalChat);
	__pSetVar [QGVAR(isinaction), false];
};

_dir_to_set = getdir player;

_mg_nest = createVehicle [GVAR(mg_nest), _d_mgnest_pos, [], 0, "NONE"];
_mg_nest setdir _dir_to_set;
_mg_nest setPos _d_mgnest_pos;
[_mg_nest, 0] call FUNC(SetHeight);

__pSetVar ["mg_nest", _mg_nest];
player reveal _mg_nest;

_d_mgnest_pos = position _mg_nest;
__pSetVar [QGVAR(mgnest_pos), _d_mgnest_pos];

(localize "STR_DOM_MISSIONSTRING_294") call FUNC(GlobalChat);
_m_name = "MG Nest " + GVAR(string_player);

[QGVAR(p_o_a), [GVAR(string_player), [_mg_nest,_m_name,GVAR(name_pl),GVAR(player_side)]]] call FUNC(NetCallEvent);

_mg_nest addAction [(localize "STR_DOM_MISSIONSTRING_295") call FUNC(RedText),"x_client\x_removemgnest.sqf",[],-1,false,true,"","vehicle player == player"];

player moveInGunner _mg_nest;

__pSetVar [QGVAR(isinaction), false];