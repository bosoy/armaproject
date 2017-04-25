#include "script_component.hpp"
disableserialization;
private "_key";
_key = _this select 1;

if (_key in (actionKeys "TurnLeft")) exitWith {
	ACEChute_Steer = "CENTER";
	false
};
if (_key in (actionKeys "TurnRight")) exitWith {
	ACEChute_Steer = "CENTER";
	false
};
if (_key in (actionKeys "MoveForward")) exitWith {
	ACEChute_Pitch = "CENTER";
	false
};
if (_key in (actionKeys "MoveBack")) exitWith {
	ACEChute_Pitch = "CENTER";
	false
};

false