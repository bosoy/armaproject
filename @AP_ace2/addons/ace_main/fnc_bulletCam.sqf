/* ----------------------------------------------------------------------------
Function: ACE_fnc_bulletCam

Description:
	BulletCam for debugging

Parameters:
	_vehicle - Object
	_projectile	- Projectile

Returns:


Examples:
	(begin example)
		[_vehicle, _projectile] spawn ACE_fnc_bulletCam;
	(end)

Author:
	(c) zGuba 2010
---------------------------------------------------------------------------- */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_vehicleSize", "_projectileSize", "_relPos"];
PARAMS_2(_vehicle,_projectile);
_vehicleSize = sizeOf typeOf _vehicle;
_projectileSize = sizeOf typeOf _projectile;

if (isNil QGVAR(bulletcamera_timeout)) then { GVAR(bulletcamera_timeout) = 10 }; // default 10s timeout

if !(isNil QGVAR(bulletcamera)) exitWith {};
GVAR(bulletcamera) = "camera" camCreate [0,0,0];
GVAR(bulletcamera) cameraeffect ["internal", "back"];
showCinemaBorder false;

if (_projectile isKindOf "MissileBase") then {
	_velocity = velocity _projectile;
	_speed = _velocity call ACE_fnc_magnitude;
	GVAR(bulletcamera) camSetTarget _projectile;
	GVAR(bulletcamera) camSetRelPos [0,-_projectileSize, _projectileSize/2];
	_relPos = [0,-_vehicleSize, _vehicleSize/2]; // [0, -0.5, 0.30]
} else {
	_relPos = [0,-_vehicleSize, _vehicleSize/2];
	_velocity = velocity _vehicle;
	_speed = _velocity call ACE_fnc_magnitude;
	GVAR(bulletcamera) camSetTarget _vehicle;
	GVAR(bulletcamera) camSetRelPos [0,-_vehicleSize, _vehicleSize/2];
};
GVAR(bulletcamera) camCommit 0;

_endTime = time + GVAR(bulletcamera_timeout);
waitUntil {
	player sideChat format ["Velocity: %1 m/s Distance: %2 m", round ((velocity _projectile) call ACE_fnc_magnitude),10*(round (((vehicle player) distance _projectile)/10))];
	if (_projectile isKindOf "MissileBase") then {
		GVAR(bulletcamera) camSetTarget _projectile;
		_velocity = velocity _projectile;
		_speed = _velocity call ACE_fnc_magnitude;
	} else {
		_velocity = velocity _vehicle;
		_speed = _velocity call ACE_fnc_magnitude;
		GVAR(bulletcamera) camSetTarget _vehicle;
	};
	GVAR(bulletcamera) camSetRelPos _relPos;
	GVAR(bulletcamera) camCommit 0;
	(GVAR(bulletcamera_timeout) > 0 && {time > _endTime}) || {!(alive _projectile && {alive GVAR(bulletcamera)})}
};

GVAR(bulletcamera) cameraeffect ["terminate", "back"];
camDestroy GVAR(bulletcamera);

GVAR(bulletcamera) = nil;
