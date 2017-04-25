#include "script_component.hpp"

PARAMS_1(_mine);
if (isNull _mine) exitWith {};
_mine_position = getPos _mine;
_mine_x = _mine_position select 0;
_mine_y = _mine_position select 1;

// Converted all constants to defines
#define	__MINE_ANGLE 0
#define	__FIRING_FOV 360
#define	__FIRING_SPEED 1100
#define	__FIRING_ORIGIN_AGL	0.8
#define	__SHRAPNEL_COUNT 70
#define	__UP_VELOCITY -0.5
#define	__MINE_FRAG	"ACE_B_BallBearing"
#define	__RANDOM_DROP 0.5
#define	__START_ANGLE (__MINE_ANGLE - (__FIRING_FOV / 2))

for "_i" from 1 to __SHRAPNEL_COUNT do {
	_dir = __START_ANGLE + random __FIRING_FOV;
	_shrapnel = __MINE_FRAG createVehicle [_mine_x, _mine_y, __FIRING_ORIGIN_AGL];
	// Set shrapnel off at muzzle velocity in the direction it's pointing
	_shrapnel setVelocity [	sin _dir * __FIRING_SPEED, cos _dir * __FIRING_SPEED, (__UP_VELOCITY - random __RANDOM_DROP)];
};
