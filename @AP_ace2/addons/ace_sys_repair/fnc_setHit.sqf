// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfg configFile >> "CfgVehicles" >> typeOf _veh

private ["_selection"];
PARAMS_3(_veh,_part,_amount);
_part = "hit" + _part;
if !(isText(__cfg >> "hitpoints" >> _part >> "name")) exitWith {};
_selection = getText(__cfg >> "hitpoints" >> _part >> "name");
TRACE_2("",_part,_selection);
_veh setHit [_selection, _amount];
