// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_sender,_count,_zones);

if !(isServer) exitWith {};
if (count _zones == 0) exitWith {};

[GVAR(hash), _sender, _count] call CBA_fnc_hashSet;
publicVariable QUOTE(GVAR(hash));

if (GETVAR(ready)) then {
	_zones spawn { { _x call FUNC(spawnZone) } forEach _this };
} else {
	{ PUSH(GVAR(zones),_x) } forEach _zones;
	if !(_sender in GVAR(commanders)) then { PUSH(GVAR(commanders),_sender) };
};
