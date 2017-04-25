// #define DEBUG_MODE_FULL

#include "script_component.hpp"

private ["_v", "_eo"];
PARAMS_2(_v,_eo);

if (_eo && {fuel _v == 0}) exitWith {};
if (!_eo && {!(_v getVariable QGVAR(eon))}) exitWith {};

[QGVAR(engineon), [_v,_eo]] call CBA_fnc_globalEvent;
