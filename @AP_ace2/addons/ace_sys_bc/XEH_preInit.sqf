// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PREP(ups);
PREP(upsMON);
PREP(man_init);
PREP(joinGroup);
[QUOTE(GVAR(joinGroup)), { _this call FUNC(joinGroup) }] call CBA_fnc_addEventHandler;

FUNC(getName) = {
	private ["_name", "_c", "_i", "_entry"];
	PARAMS_1(_unit);
	_name = _unit getVariable QUOTE(GVAR(name));
	if (isNil "_name") then {
		_name = toArray (name _unit);
		_i = 0; _c = count _name;
		while {_i < _c} do {
			_entry = _name select _i;
			if (_entry in [32, 126,96,33,64,35,36,37,94,38,42,40,41,45,61,43,123,125,124,92,47,58,59,34,39,60,62,63,46,44]) then { _name set [_i, 95] };
			ADD(_i,1);
		};
		_name = toString _name;
		_unit setVariable [QUOTE(GVAR(name)), _name];
	};
	_name;
};
