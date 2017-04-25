// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_target,_caller,_index);

player setVariable [QGVAR(wireDeployed),true];
_target removeAction _index;