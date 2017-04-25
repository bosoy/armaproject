#include "script_component.hpp"
#define DELAY 0.02

private ["_A_ID","_mine"];
_ar = _this;
if (count _this > 2) then {
	_A_ID = _this select 2;
	_mine = _this select 3;
	player removeAction _A_ID;
} else {
	_trigger = _this select 0;
	_mine = [_trigger] call FUNC(get_mine);
};

if (isNull _mine) exitwith { false };

_position = position _mine;
_z = [_mine] call CBA_fnc_realHeight;
_position = [_position select 0,_position select 1, _z];
_direction = direction _mine;
_pitch = -(_mine getVariable ["pitch",0]);

"ACE_ClayMoreExplosion" createVehicle [_position select 0,_position select 1, _z + 0.2];
[_mine] call FUNC(removeMine);

// Takes a little while for the claymore to actually explode
sleep 0.18;

// Calculate the needed upwards force
// Two meter high spread at 50 meters
_muzzle_velocity = 1200;
_target_distance = 50;
_emit_height = 0.093;
_target_height = 2 - _emit_height;

_degree = (_target_distance * (2 * 3.141592)) / 360;

_aiming_point = _target_height + (_target_distance / _muzzle_velocity) * 9.8;
_shrapnel_angle = _aiming_point / _degree;
_pitch = _pitch + _shrapnel_angle;
_forward_velocity = _muzzle_velocity * cos _pitch;
_upward_velocity = _muzzle_velocity * sin _pitch;
_shrapnel_random = _muzzle_velocity * sin _shrapnel_angle;

//q1184 - spawning pellets in multiple frames to go easy on fps
for "_i" from 0 to 2 do {
	[_position, _direction, 60, _forward_velocity, _emit_height, 60, _upward_velocity, "ACE_B_BallBearing", _shrapnel_random] call ace_sys_explosives_fnc_spawnpellets_60;
	sleep DELAY;
};
