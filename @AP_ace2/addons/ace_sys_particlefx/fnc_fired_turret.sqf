#include "script_component.hpp"

// Workaround for missing muzzle flashes for shotFromTurret cannons
// (c) zGuba A.D. 2011

#define __class configFile >> "CfgWeapons" >> _weapon >> QUOTE(ADDON)

private ["_vehicle","_weapon","_projectile"];

_vehicle = _this select 0;
_weapon = _this select 1;
_projectile = _this select 6;

if !(isClass (__class)) exitWith {};

private ["_velocity"];

_velocity = velocity _vehicle;

private ["_shape","_timerPeriod","_lifeTime","_position","_size","_moveVelocity","_color"];

_shape = getText (__class >> "shape");
_timerPeriod = getNumber (__class >> "timerPeriod");
_lifeTime = getNumber (__class >> "lifeTime");
_position = getArray (__class >> "position");
_size = getArray (__class >> "size");
_color = getArray (__class >> "color");

drop [
	_shape,
		"",
		"Billboard",
	_timerPeriod,
	_lifeTime,
	_position,
		[(_velocity select 0),(_velocity select 1) + (random 0.1),(_velocity select 2) + (random 0.2)],
		45 - (random 90),
		0.005,
		0.0042,
		0.005,
	_size,
	_color,
		[1],
	_lifeTime,
	_lifeTime,
		"",
		"",
	_projectile
];

_light = _vehicle getVariable "ACE_shotFromTurret_light";
if (isNil "_light") then {
	_light = "#lightpoint" createVehicleLocal getPos _projectile;
	_light setPosASL getPosASL _projectile;
	_light setLightColor [0.8,0.8,0.6];
	_light setLightAmbient [0.8,0.8,0.6];
	_light setLightBrightness 0.015;
	_light setVelocity _velocity;
	
	// Control variable
	_vehicle setVariable ["ACE_shotFromTurret_light",_light];
	
	// Delete time
	_vehicle setVariable ["ACE_shotFromTurret_lighttime",time + 0.15];
	
	[_vehicle,_light] spawn {	// Todo: FIFO?
		waitUntil {sleep 0.1; time > (_this select 0) getVariable "ACE_shotFromTurret_lighttime"};
		deleteVehicle (_this select 1);
		(_this select 0) setVariable ["ACE_shotFromTurret_light",nil];
	};
} else {
	_light setPosASL getPosASL _projectile;
	_light setVelocity _velocity;
	
	_vehicle setVariable ["ACE_shotFromTurret_lighttime",time + 0.15];	// Live longer
};
