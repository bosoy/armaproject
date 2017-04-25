#include "script_component.hpp"
disableserialization;
private "_key";
_key = _this select 1;

if (_key in (actionKeys "TurnLeft")) exitWith {
	ACE_HALO_DIR = ACE_HALO_DIR + (-0.5);
	ACEChute_Steer = "LEFT";
	false
};
if (_key in (actionKeys "TurnRight")) exitWith {
	ACE_HALO_DIR = ACE_HALO_DIR + 0.5;
	ACEChute_Steer = "RIGHT";
	false
};
if (_key in (actionKeys "MoveForward")) exitWith {
	ACE_HALO_ACCEL = ACE_HALO_ACCEL + 0.1;
	ACEChute_Pitch = "FORWARD";
	false
};
if (_key in (actionKeys "MoveBack")) exitWith {
	ACE_HALO_ACCEL = ACE_HALO_ACCEL - 0.05;
	ACEChute_Pitch = "BACK";
	false
};

false
