// laser rangefinder. returns: range to target, position of target in world and ASL coords, angle between sight center and weapon direction,vec to target,inclination angle to target]

#include "script_component.hpp"

private ["_d","_tarveh","_vehicle", "_weapon", "_offset", "_newPos", "_spd", "_laserVec","_pulsePos", "_pulse", "_range", "_newposASL","_p","_p1"];

if (cameraView != "GUNNER") exitwith {};

_vehicle = vehicle player;
// _weapon = currentWeapon _vehicle;
_offset = [0,0,5];
_newPos = [0,0,0];
_spd = 600000;

_pulsePos = positionCameraToWorld _offset;
_pulse = "ACE_Missileguidance_LaserPulse" createVehicleLocal _pulsePos;
_pulse setPos _pulsePos;
_p = getPosASL _pulse;
_p1 = positionCameraToWorld [_offset select 0,_offset select 1,1 + (_offset select 2)];
_pulse setPos _p1;
_p1 = getPosASL _pulse;

_laservec = [(_p1 select 0)-(_p select 0),(_p1 select 1)-(_p select 1),(_p1 select 2)-(_p select 2)];
_pulse setPos _pulsePos;
_pulse setVelocity [(_laserVec select 0) * _spd, (_laserVec select 1) * _spd, (_laserVec select 2) * _spd];
_range = 0;

waitUntil {
	if (alive _pulse) then {
		_d = _pulse distance _vehicle;
		if (_d > 25 && {_d < 9999}) then { _range = _d; _newpos = getPosASL _pulse };
	};
	!alive _pulse
};

_terrainHeight = getTerrainHeightASL [_newpos select 0, _newpos select 1];
if (_terrainHeight > 0) then {
	_newpos set [2, (_newpos select 2) - _terrainHeight];
};

// Trigger incoming laser detection on targeted vehicle
_tarVeh = objNull;
{ if !(_x isKindOf "StaticWeapon") exitWith { _tarVeh = _x } } forEach (_newpos nearEntities [["LandVehicle", "Air", "Ship"],12]);
if !(isNull _tarVeh) then {
	["ace_lasertarget", [_vehicle, _tarVeh, objNull]] spawn CBA_fnc_globalEvent;
};

_range = if (_range < 25) then {0} else {_range min 9999};

[_vehicle,_range,magazines _vehicle,weapons _vehicle,true] call FUNC(setsolution);
_vehicle setVariable ["AH_DISTANCE_TO_TARGET", _range, true];
_vehicle setVariable ["RU_DISTANCE_TO_TARGET", _range, true];
