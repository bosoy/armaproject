// takes: unit,variable to set and value
// checks if it already has this value and exits if so, othwerwise sets it
// (avoids redundant MP traffic)

#include "script_component.hpp"

private ["_v", "_abort"];
PARAMS_3(_unit,_var,_value);
_v = _unit getvariable _var;
_abort = false;
if (isNil "_value") then {
	if (isNil "_v") exitWith { _abort = true };
} else {
	if ((typename _value) == "BOOL") then {
		if !(isNil "_v") then { 
			if ((_v && {_value}) || {(!_v && {!_value})}) then {_abort = true};
		};
	} else {
		if !(isNil "_v") then { 
			if (_v == _value) then {_abort = true};
		};
	};
};

if (_abort) exitwith {};

_unit setvariable [_var, if (isNil "_value") then { nil } else { _value }, true];

// Trigger local event so others can listen
[QGVAR(state_change), [_unit, _var, if (isNil "_value") then { nil } else { _value }]] call CBA_fnc_localEvent;
