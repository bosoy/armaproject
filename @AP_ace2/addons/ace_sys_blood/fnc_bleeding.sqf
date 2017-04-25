#include "script_component.hpp"

PARAMS_1(_unit);

if (!isNil {_unit getVariable QGVAR(bleeding)}) exitWith {};

PUSH(GVAR(units),_unit);
_unit setVariable [QGVAR(bleeding), true];
