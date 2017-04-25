#include "script_component.hpp"

private ["_isu"];
PARAMS_1(_unit);

_isu = _unit getVariable [QGVAR(uncon), false];
if (isNil "_isu") then {_isu = false};
_isu
