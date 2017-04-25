#include "script_component.hpp"

private ["_heli"];

#define __alarmEnabled (_heli getVariable QGVAR(alarming))
#define __autoRotateEnabled (_heli getVariable QGVAR(autorotating))

_heli = vehicle player;
_heli setVariable [QGVAR(alarming),false];
_heli setVariable [QGVAR(autorotating),false];

while {vehicle player == _heli && {alive _heli}} do {
	if !(isEngineOn _heli && {canMove _heli}) then {
		if !((isEngineOn _heli && {canMove _heli}) || {__alarmEnabled}) then {
			[_heli] call FUNC(alarm);
		};
		if (!isEngineOn _heli && {alive driver _heli} && {!__autoRotateEnabled}) then {
			[_heli] call FUNC(autorotate_client);
		};
	};
	sleep 5;
};
