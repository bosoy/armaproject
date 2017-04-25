// #define DEBUG_MODE_FULL

#include "script_component.hpp"

PARAMS_1(_v);

if (player in _v) then {
	_v setVariable [QGVAR(eon), true];
	[_v] spawn FUNC(rocko_g);
};