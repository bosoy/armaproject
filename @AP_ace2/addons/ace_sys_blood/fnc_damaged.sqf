/*
	Damaged EH: Does not fire on Killed
*/
#include "script_component.hpp"

private ["_history", "_data"];

PARAMS_3(_unit,_selection,_damage);

// Process damaged history
_history = _unit getVariable [QGVAR(damage), []];
_data = [_selection, _damage];
PUSH(_history,_data);
_unit setVariable [QGVAR(damage), _history];
