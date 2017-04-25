/* ace_sys_explosives | Pipebomb Fusing | (c) 2013 by rocko */
//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_explosives\script_component.hpp"

private ["_fuseType","_length","_burnrate"];
PARAMS_1(_mine);

_length = round(sliderPosition 1900); TRACE_1("Fuse length",_length);
_fuseType = "default";
closeDialog 0;

if (0 == _length) exitWith {};

switch (_fuseType) do {
	// Add types
	default {
		_burnrate = [105,130];
	};
};
TRACE_1("Burnrate",_burnrate);
_burnRateMin = _burnrate select 0;
_burnRateMax = _burnrate select 1;
_burnRateRandom = _burnRateMax - _burnRateMin;
_burnRateAdd = random _burnRateRandom;
_burnRateReal = _burnRateMin + _burnRateAdd; //Anyway, though each charge of a fuse would have the same burnrate ... 

_time = _burnRateReal * (_length/100); TRACE_1("Time",_time);

_mine setVariable [QGVAR(timer),_time,true];