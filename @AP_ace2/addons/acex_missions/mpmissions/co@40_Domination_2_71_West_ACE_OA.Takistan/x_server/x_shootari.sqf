// by Xeno
#define THIS_FILE "x_shootari.sqf"
#include "x_setup.sqf"
private ["_angle","_center_x","_center_y","_height","_i","_number_shells","_pos_enemy","_radius","_type","_wp_array","_x1","_xo","_y1","_kind"];
if (!isServer) exitWith {};

PARAMS_2(_pos_enemy,_kind);

_radius = 30;
_height = switch (_kind) do {case 0: {150};case 1: {150}; case 2: {1}};

_center_x = _pos_enemy select 0;
_center_y = _pos_enemy select 1;

_type = if (GVAR(enemy_side) == "EAST") then {
	switch (_kind) do {
		case 0: {GVAR(ArtyShellsEast) select 3};
		case 1: {GVAR(ArtyShellsEast) select 1};
		default {GVAR(ArtyShellsEast) select 2};
	}
} else {
	switch (_kind) do {
		case 0: {GVAR(ArtyShellsWest) select 3};
		case 1: {GVAR(ArtyShellsWest) select 1};
		default {GVAR(ArtyShellsWest) select 2};
	}
};


if (_kind in [0,1]) then {
	_number_shells = 3 + (ceil random 3);
#ifdef __TT__
	if ((floor random 3) == 0) then {[QGVAR(doarti), _pos_enemy] call FUNC(NetCallEventToClients)};
#else
	if ((__XJIPGetVar(GVAR(searchintel)) select 5) == 1) then {[QGVAR(doarti), _pos_enemy] call FUNC(NetCallEventToClients)};
#endif
} else {
	_number_shells = 1;
}; 

_wp_array = [];
while {count _wp_array < _number_shells} do {
	_angle = floor random 360;
	_x1 = _center_x - ((random _radius) * sin _angle);
	_y1 = _center_y - ((random _radius) * cos _angle);
	_wp_array set [count _wp_array, [_x1, _y1, _height]];
	sleep 0.0153;
};
sleep 9.25 + (random 8);
for "_i" from 0 to (_number_shells - 1) do {
	_shell = createVehicle [_type, _wp_array select _i, [], 0, "NONE"];
	_shell setVelocity [0,0,-150];
	if (_kind == 1) then {[QGVAR(artyt), [getPosASL _shell, _type]] call FUNC(NetCallEventToClients)};
	_xo = ceil random 10;
	 sleep 0.923 + (_xo / 10);
};

_wp_array = nil;