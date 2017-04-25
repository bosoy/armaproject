// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_weaponDirection", "_dirTo", "_dirDiff"];
PARAMS_2(_unit,_unit2);
_weaponDirection = _unit call FUNC(weaponDir);
_dirTo = [_unit, _unit2] call BIS_fnc_dirTo;

_dirDiff = _dirTo - _weaponDirection; //subtract direction of unit
TRACE_3("",_weaponDirection,_dirTo,_dirDiff);

//ensure return is between 0-360
//if (_dirDiff < 0) then {_dirDiff = _dirDiff + 360};
//if (_dirDiff > 360) then {_dirDiff = _dirDiff - 360};
!(abs _dirDiff > 45)
