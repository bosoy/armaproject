#include "script_component.hpp"

// BIS bug fixer
// Script by zGuba

private ["_vehicle", "_bullet", "_velocity","_position","_vector","_vectorDir"];

_vehicle = _this select 0;
_bullet = _this select 6; // uses BIS Fired EH

_version = call {productVersion}; // Must use call {productVersion}  to not fail this script completely on versions that don't support the productVersion script command
_build = if (isNil "_version") then {0} else {_version select 3};
if (_build >= 88111) exitWith {};

_type = typeOf _bullet;
_velocity = velocity _bullet;
_position = getPosASL _bullet;
_vectorDir = vectorDir _bullet;
_vector = [_vectorDir, vectorUp _bullet];

deleteVehicle _bullet;
_bullet = _type createVehicle [0,0,100];
_bullet setPosASL [(_position select 0) + (_vectorDir select 0)*5, (_position select 1) + (_vectorDir select 1)*5, (_position select 2) + (_vectorDir select 2)*5];
_bullet setVectorDirAndUp _vector;
_bullet setVelocity _velocity;
