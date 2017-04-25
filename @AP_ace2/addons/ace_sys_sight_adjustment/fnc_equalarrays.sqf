#include "script_component.hpp"
private ["_res"];

PARAMS_2(_a,_b);

_res = false;
if (count _a == count _b) then {
	_res = true;
	for "_i" from 0 to (count _a) - 1 do {
		if (_a select _i != _b select _i) exitwith { _res = false };
	};
};
_res