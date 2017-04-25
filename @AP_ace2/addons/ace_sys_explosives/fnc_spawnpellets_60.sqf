#include "script_component.hpp"
PARAMS_1(_mine_position);
_mine_x = _mine_position select 0;
_mine_y = _mine_position select 1;

_mine_angle = _this select 1;

// Angle to spread shrapnel within
_firing_fov = _this select 2;

// Meters per second of shrapnel
_firing_speed = _this select 3;

// Height AGL of shrapnel emitter
_firing_origin_agl = _this select 4;

// Number of shrapnel bits
_shrapnel_count = _this select 5;

_up_velocity = _this select 6;

_mine_frag = _this select 7;

_random_drop = _this select 8;


_start_angle = _mine_angle - (_firing_fov / 2);

for "_i" from 1 to _shrapnel_count do {
	_dir = (_start_angle + random _firing_fov);
	_shrapnel = _mine_frag createVehicle [_mine_x, _mine_y, _firing_origin_agl];
	// Set shrapnel off at muzzle velocity in the direction it's pointing
	_shrapnel setVelocity [	sin _dir * _firing_speed,
				cos _dir * _firing_speed,
				(_up_velocity - random _random_drop)];
};
