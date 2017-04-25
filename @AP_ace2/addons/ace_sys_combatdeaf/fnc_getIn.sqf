//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_vehicle,_position,_unit);

if (typeName _unit != "OBJECT") exitwith {};
if (_unit != player) exitWith {};

_eh = _vehicle addEventHandler ["Fired", {_this call FUNC(fired)}];

_vehicle setVariable [QGVAR(fired), _eh];
