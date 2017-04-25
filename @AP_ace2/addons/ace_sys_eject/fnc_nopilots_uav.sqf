//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);
if (isNull _unit) exitWith {};
// Find parachute
_p = nearestObject [_unit, "ParachuteBase"];
if !(isNull _p) then { _p setPos [0,0,4000]; };
// Set away
_unit setPos [0,0,4000];
// Leave group
sleep 0.2;
[_unit] join grpNull;
// Kill
_unit setDamage 1;
// Delete
sleep 1;
deleteVehicle _unit;
deleteVehicle _p;
