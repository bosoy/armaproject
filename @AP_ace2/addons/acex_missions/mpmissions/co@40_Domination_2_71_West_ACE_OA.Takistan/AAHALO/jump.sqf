#define THIS_FILE "jump.sqf"
#include "x_setup.sqf"
private ["_startLocation","_uh60p","_vec","_jump_helo","_obj_jump"];

PARAMS_1(_startLocation);

if (GVAR(HALOWaitTime) > 0) then {GVAR(next_jump_time) = time + GVAR(HALOWaitTime)};

_jump_helo = switch (GVAR(player_side)) do {
	case east: {GVAR(jump_helo) select 0};
	case west: {GVAR(jump_helo) select 1};
	case resistance: {GVAR(jump_helo) select 2};
};

titleText ["","Plain"];
_uh60p = createVehicle [_jump_helo, _startLocation, [], 0, "FLY"];
_uh60p setpos [_startLocation select 0,_startLocation select 1, GVAR(HALOJumpHeight)];
_uh60p engineon true;
player moveincargo _uh60p;
_obj_jump = player;
if (vehicle player == player) exitWith {};

_obj_jump setvelocity [0,0,0];
#ifndef __ACE__
_obj_jump action["EJECT",vehicle _obj_jump];
if (vehicle _obj_jump isKindOf "ParachuteBase") then {
	_vec = vehicle _obj_jump;
	_obj_jump action["EJECT",vehicle _obj_jump];
	deleteVehicle _vec;
};
[player, player call FUNC(GetHeight)] spawn bis_fnc_halo;
#else
[_uh60p, player] execVM "x\ace\addons\sys_eject\jumpout.sqf";
#endif

sleep 3;

deleteVehicle _uh60p;
if (GVAR(with_ai)) then {
	if (alive player) then {[position player, velocity player, direction player] execVM "x_client\x_moveai.sqf"};
};