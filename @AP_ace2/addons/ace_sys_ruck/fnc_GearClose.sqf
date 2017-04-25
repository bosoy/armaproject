//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);

if (local _unit && {!isNil QGVAR(diag_to_close)}) then {
    call compile format["closeDialog %1",GVAR(diag_to_close)];
};
