/* ace_sys_muzzleblast | (c) 2008, 2009, 2010 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __degree ((_distance * (2 * 3.141592)) / 360)
#define __target_height (10)
#define __aiming_point (__target_height + (_distance / _velocity) * 9.8)
#define __shrapnel_angle (__aiming_point / __degree)
#define __mine_x1 (_position select 0)
#define __mine_y1 (_position select 1)
#define __mine_x (__mine_x1 + ((sin (_direction)) * 10))
#define __mine_y (__mine_y1 + ((cos (_direction)) * 10))
#define __firing_fov (20)
#define __start_angle (_direction - (__firing_fov / 2))

private ["_random_drop", "_degree", "_position", "_velocity", "_surface", "_count", "_forward_velocity", "_upward_velocity", "_shrapnel_random", "_firing_speed", "_up_velocity" ]; 

PARAMS_4(_unit,_ammo,_distance,_direction);

_position = position _unit;

// SurfaceTypes
_surface = (surfaceType _position);
_surface_string = ([_surface, "#"] call CBA_fnc_split) select 1;
_surface_multi = getNumber(configFile >> "CfgSurfaces" >> _surface_string >> "dust");
TRACE_3("Surface multiplier for surface debris",_surface,_surface_string,_surface_multi);

_velocity = getNumber(configFile >> "CfgAmmo" >> _ammo >> "typicalSpeed");
_count = if (getNumber(configFile >> "CfgAmmo" >> _ammo >> "explosive") == 1) then { (10 * _surface_multi) } else { (10 * _surface_multi) + 4 };

_forward_velocity = _velocity * cos __shrapnel_angle;
_upward_velocity = _velocity * sin __shrapnel_angle;
_shrapnel_random = _velocity * sin __shrapnel_angle;
_firing_speed = _velocity * cos __shrapnel_angle;
_up_velocity = _velocity * sin __shrapnel_angle;
_random_drop = _velocity * (sin (__aiming_point / __degree));

for "_i" from 0 to _count do {
	_dir = __start_angle + random __firing_fov;
	_shrapnel_sim = "ACE_ATDebris";
	#ifdef DEBUG_MODE_FULL
		_shrapnel_sim = "RoadCone";
	#endif
	_shrapnel = _shrapnel_sim createVehicle [__mine_x, __mine_y,10];
	_shrapnel setVelocity [	sin _dir * _firing_speed, cos _dir * _firing_speed, _up_velocity - (random _random_drop)];
};
