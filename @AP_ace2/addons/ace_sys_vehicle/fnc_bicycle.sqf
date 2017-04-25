// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_v,_p,_u);

if !(canStand _u) then {
	sleep 0.5;
	_u action ["EJECT", _v];
};
