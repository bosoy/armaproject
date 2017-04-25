/* ace_sys_explosives (.pbo)| M86 PDM | (c) 2011 by rocko */
#include "script_component.hpp"

#define __vel (velocity _m86) call ACE_fnc_magnitude

private ["_m86","_pos"];

_this spawn {
	_m86 = _this select 6;
	while { alive _m86 && {!isNull _m86} } do {
		sleep 0.1;
		if (__vel < 0.2) exitWith { };
	};
	_pos = getPosATL _m86;
	while { alive _m86 } do { sleep 1; };

	[QGVAR(fired), _pos] call ACE_fnc_clientToServerEvent;
};
