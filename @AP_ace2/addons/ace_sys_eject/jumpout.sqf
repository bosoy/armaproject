//#define DEBUG_MODE_FULL
#include "script_component.hpp"
private ["_engine", "_fx", "_exit"];

/* This script is executed by the "Jump Out" addAction command. */

// Argument(s) passed from addAction command. 0 = the vehicle the event handler is assigned to. 1 = The unit activating the action.
PARAMS_3(_vehicle,_jumper,_id);
DEFAULT_PARAM(3,_side,"left");

// If jumper is not inside the vehicle then exit the script without continuing.
if !(local _jumper && {_jumper in _vehicle}) exitWith {};	// localty check

// If vehicle is locked then exit the script without continuing.
if (_vehicle call CBA_fnc_locked) exitWith { hint (localize "STR_ACE_EJECT_VEHLOCKED"); };	// not needed now

if (player == _jumper) then { _jumper setVariable [QGVAR(jumpedout),true]; };

// New implementation brings new issues...
_engine = isEngineOn _vehicle;

// Make jumper get out of a vehicle (without parachute).
moveOut _jumper;

// ...solution for moveOut stopping the engine
if (_engine && {(!isEngineOn _vehicle)}) then { _vehicle action ["EngineOn", _vehicle] };

#ifdef DEBUG_MODE_FULL
	// If jumper is too low to the ground exit the script without continuing. --> will only attempt to start HALO sequence if you jump out above this height.
	_debugMsg = format["Checking _jumper %1 for ATL:%2 at tickTime:%3",name _jumper, getPosATL _jumper, diag_tickTime];
	LOG(_debugMsg);
#endif

if (((getPosATL _jumper) select 2) < 10) exitWith {
	#ifdef DEBUG_MODE_FULL
		_debugMsg = format["_jumper %1 is not high enough for free fall to begin at ATL:%2 at tickTime:%3",name _jumper, getPosATL _jumper, diag_tickTime];
		LOG(_debugMsg);
	#endif

	// Leave left or right
	// TODO: Make function
	switch (toLower _side) do {
		case "left": {
			_dir = getDir _vehicle;
			_new_dir = _dir - 90;
			_pos = getPosATL _vehicle;
			_range_to_memoryPoint = 3;
			_position_of_memoryPoint = [0,0,0]; // TODO: mirror for both sides
			_left_pos = [(_pos select 0) + ((sin _new_dir)*3), (_pos select 1) + ((cos _new_dir*3)), _pos select 2];
			_jumper setPos _left_pos;
			_jumper setDir _new_dir;
		};
		case "right": {
			_dir = getDir _vehicle;
			_new_dir = _dir + 90;
			_pos = getPosATL _vehicle;
			_range_to_memoryPoint = 3;
			_position_of_memoryPoint = [0,0,0]; // TODO: mirror for both sides
			_left_pos = [(_pos select 0) + ((sin _new_dir)*3), (_pos select 1) + ((cos _new_dir*3)), _pos select 2];
			_jumper setPos _left_pos;
			_jumper setDir _new_dir;
		};
	};
};

waitUntil {!(_jumper in _vehicle)};
if (player == _jumper) then {
	_jumper spawn {
		sleep 1.5;
		_this setVariable [QGVAR(jumpedout),false]; /// Y U NO WORK!???
	};
};
	
[_jumper] spawn COMPILE_FILE(jumpout_cord);

if (_jumper == player) then {
	_jumper spawn {
		if (_this == player) then {
			setAperture 0.05;
			setAperture -1;
			"DynamicBlur" ppEffectEnable true;
			"DynamicBlur" ppEffectAdjust [8.0];
			"DynamicBlur" ppEffectCommit 0.01;
		};

		sleep 1;

		if (_this == player) then {
			"DynamicBlur" ppEffectAdjust [0.0];
			"DynamicBlur" ppEffectCommit 3;
			sleep 3;
		};

		"DynamicBlur" ppEffectEnable false;
		"RadialBlur" ppEffectAdjust [0.0, 0.0, 0.0, 0.0];
		"RadialBlur" ppEffectCommit 1;
		"RadialBlur" ppEffectEnable false;
	};
};
