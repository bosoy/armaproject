//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_this);

//this script is called when weight has not yet been broadcast but was requested
if (local _this) then {
	_weight = _this call FUNC(GearWeight); //calling this function will broadcast weight variable internally
};