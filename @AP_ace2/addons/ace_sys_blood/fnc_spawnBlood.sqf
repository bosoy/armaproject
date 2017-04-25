#include "script_component.hpp"

PARAMS_3(_type,_pos,_dir);

private ["_object"];
_object = _type createVehicleLocal _pos;
_object setDir (random 360);
_object setPos _pos;
[_object, 300] call ACE_fnc_add2fifo;

_object
