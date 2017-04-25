// Laser pulse and optical target setting loop
// Original script by Headspace, adapted for more general use by q1184
/*
	ACE2ized by zGuba
	I have met 2 problems when I was rebuilding laserloop script for A2:
	- laser "bullet" disappearing in the middle of nowhere (config TTL time increased fixed this),
	- laser "bullet" ceasing to live immediately after spawning, at around 40 meters (fixed with rejection of too close targets, that's why lower treshold limit is 50 meters)
	increased to 100 meters since waitUntl sometimes loop catches up and goes off too early.
*/

/*
A2 OA 1.61 supplies fixed laser designator.
The only remaining purpose of this script would be BWC and radar rangefinder (Mi-24), though I'm not sure if this is really needed too
*/

// #define DEBUG_MODE_FULL
#include "script_component.hpp"

// This script fires a "pulse" of laser light (or whatever you'd like to call it)
// In the direction of the vehicle's weapon (passed as a parameter). It then returns
// the location of the "hit" so that further action can be taken.

private ["_tgtside","_laserObject","_newLaser"];

PARAMS_3(_vehicle,_weapon,_realLaser);

if !(alive _vehicle) exitWith {};
if ((player != gunner _vehicle) && {(player != _vehicle)}) exitWith {};

// Avoid multiple runs.
if !(isNil {_vehicle getVariable QGVAR(laser_working)}) exitWith {};
_vehicle setVariable [QGVAR(laser_working), true];

// New laser in betapatches, reliable and 100% safe for network

_productVersion = call {productVersion}; // Must use call {productVersion}  to not fail this script completely on versions that don't support the productVersion script command
_newLaser = !(isNil "_productVersion");

if (_newLaser) then {
	if !("Laserbatteries" in magazines _vehicle) then {
		_vehicle addMagazine "Laserbatteries";
	};
	if !("ACE_Laserdesignator_Hidden" in weapons _vehicle) then {
		_vehicle addWeapon "ACE_Laserdesignator_Hidden";
	};
	_laserObject = objNull;
	sleep 0.1; // make sure the laser weapon is "reloaded"
} else {
	if (_realLaser) then {
		switch (side _vehicle) do {
			case east: {_tgtside = "LaserTargetE"};
			case west: {_tgtside = "LaserTargetW"};
			default {_tgtside = "LaserTargetW"};//to do: create lt for resistance in config
		};
		_laserObject = _tgtside createVehicle [0,0,0];
		_laserObject setVariable ["SPON_RF_owner", name (effectiveCommander _vehicle), true]; // compatible with sys_rangefinder
		_laserObject setVariable ["ace_RF_owner",player,true];
	} else {
		_laserObject = "ACE_Target_FakeLaser" createVehicleLocal [0,0,0];
	};
};

_vehicle setVariable [QGVAR(laserObject), _laserObject];

_vehicle setVariable [QGVAR(laser_off),nil];

[_vehicle,_weapon,_realLaser,_laserObject,_newLaser] spawn FUNC(opt_laserloop_pfh);
