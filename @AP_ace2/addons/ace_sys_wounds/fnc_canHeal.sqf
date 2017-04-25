#include "script_component.hpp"

private ["_i", "_body", "_head", "_hands", "_legs", "_ceil", "_nearMedicFacility"];
PARAMS_1(_unit);
if (isNull _unit) exitWith {false};
_i = _unit getVariable ["ace_w_hc", 0]; if (isNil "_i") then { _i = 0 };
INC(_i);
_nearMedicFacility = [_unit] call FUNC(nearMedicalFacility);

_ceil = if (_nearMedicFacility) then { 0 } else { _i * GVAR(leftDam) };

_body = _unit getVariable ["ace_w_body", 0];
if (_body > _ceil) exitWith { true };
_head = _unit getVariable ["ace_w_head_hit", 0];
if (_head > _ceil) exitWith { true };
_hands = _unit getVariable ["ace_w_hands", 0];
if (_hands > _ceil) exitWith { true };
_legs = _unit getVariable ["ace_w_legs", 0];
if (_legs > _ceil) exitWith { true };
false;
