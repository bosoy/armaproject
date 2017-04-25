// Original SPON Rangefinder script, modified by tcp
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_targetClass", "_targets", "_target", "_playerPos", "_dir","_pos", "_distance", "_weaponVector"];

switch (playerSide) do {
	case west: { _targetClass = "LaserTargetW"; };
	case east: { _targetClass = "LaserTargetE"; };
	default { _targetClass = "LaserTargetC"; };
};
_baseTargetClass = "LaserTarget";

_detectorPos = [0, 0, 0]; // Position of SPON_RF_targetDetector logic.
_target = objNull; // The laser target we are trying to find.
_weaponVector = player weaponDirection (currentWeapon player); // Calculate direction of weapon

TRACE_1("",_weaponVector);

// Step along the path, but only collide with the ground if we are well beneath it

_detected = 0; //for MLT

for [{_distance = 100},
    {(_distance <= viewdistance) && ((_detectorPos select 2) > -2) && (isNull _target)},
    {_distance = _distance + 100}] do {
	_detectorPos = positionCameraToWorld [0, 0, _distance];
	_targets = _detectorPos nearEntities [_baseTargetClass, 100];
	
	TRACE_2("",_detectorPos,_targets);

	{ 	// If any of the detected targets lack an owner, then they must be ours
		_owner = _x getVariable "ace_RF_owner";
		_owned = false;
		if (!isNil "_owner") then { if (_owner == player) exitWith {_target = _x;}; _owned = true; };
		TRACE_6("Detected laser target",_x,typeOf _x,_owner,player distance _x,_weaponVector,vectorDir _x);

		if (!_owned && {local _x} && {(_weaponVector distance (vectorDir _x)) < 1} && {typeOf _x == _targetClass}) exitWith { //  Your own target has vectorDir equal to your weapon's dir
			_target = _x;
			_target setVariable ["ace_RF_owner",player,true];
			_target setVariable ["ACE_LASERTARGET_CODE", GVAR(currentLaserCode), true];
		};
		_detected = _detected + 1;
	} forEach _targets;
};

player setVariable ["ACE_CurLaserObj", _target];
[QGVAR(Lazing), [_target,_detected]] call CBA_fnc_localEvent;

[_target,_detected];
