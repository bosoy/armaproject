// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_dir"];
PARAMS_2(_veh,_whoFired);
if !(player in _veh) exitWith {};

playSound "ACE_EngineFailureAlarm_1";
_dir = [_veh, _whofired] call BIS_fnc_dirTo;
_dir2 = _dir;
if (_dir < 0) then { _dir = _dir + 360 };
_veh vehicleChat format["SHTORA: ALARM! Direction: %1 degrees", _dir];
