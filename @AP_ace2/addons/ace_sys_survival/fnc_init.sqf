// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_lifeboat);

_lifeboat spawn {
	_lifeboat = _this;
	_lifeboat setFuel 0;
	_lifeboat setVariable [QGVAR(deflate),false,true];
};
