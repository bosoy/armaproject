//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_vehicle,_position,_unit);

if (typeName _unit != "OBJECT") exitwith {};
_var = _vehicle getVariable QGVAR(fired);
if (isNil "_var") exitWith {};

_vehicle removeEventHandler ["Fired", _var];
_vehicle setVariable [QGVAR(fired), nil];