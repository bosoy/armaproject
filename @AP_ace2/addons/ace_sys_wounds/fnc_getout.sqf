//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_vehicle,_posvec,_unit);

if (!local _unit) exitWith {};

// Vehicle on fire?
_vof = [_vehicle] call ace_fnc_isBurning;
if (!_vof) exitWith {};

// Already on fire, exit!
_sof = [_unit] call ace_fnc_isBurning;
if (_sof) exitWith {};

TRACE_1("vehicle on fire",_vof);

[_unit] call FUNC(checkBurn);
