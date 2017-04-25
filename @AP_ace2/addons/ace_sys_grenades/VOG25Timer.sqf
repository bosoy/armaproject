//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_pos","_time"];

PARAMS_2(_object,_dummy);

_time = (random 5) + 14; // 14-19 seconds delay

for "_i" from 0 to _time step 0.2 do {
	if (!alive _dummy) exitWith {};
	sleep 0.2;
};

if (alive _dummy) then {
	TRACE_2("Detonate",_object,_dummy);
	_pos = position _dummy;
	deleteVehicle _dummy;
	_object setPos _pos;
	_object setDamage 1;
} else {
	TRACE_2("Dummy dead",_object,_dummy);
};
