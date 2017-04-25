//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_armTime", "_num", "_rand"];

PARAMS_4(_object,_dummy,_grenadeType,_unit);

// Arming is done via config, at least for M433 HEDP, M406 HE

_rand = random 17;				//	Generating random arming time, 0.18-0.35 sec
_num = _rand/100;				//	or about 14-27 meters, for initSpeed 76m/s
_armTime = _num + 0.18;
sleep _armTime;

// == == == = Creating armed grenade == == =
if ((_unit distance _dummy) > 15) then {
	TRACE_4("Not too close",_object,_dummy,_unit,_unit distance _dummy);
	[_object,_dummy,_grenadeType] call FUNC(40mmG);
} else {
	TRACE_4("Too close",_object,_dummy,_unit,_unit distance _dummy);

	sleep 15;
	deletevehicle _dummy;
};
