/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */

// _this (c) by Xeno

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_receiver,_sender);

private ["_name", "_state"];

_state = _receiver getVariable QGVAR(DogTagTaken);
if (isNil "_state") then {
	_state = 0;
};

TRACE_1("",_state);

if (_state == 1) then {
	_name = "";
} else {
	_name = _receiver getVariable QGVAR(name);
	if (isNil "_name") then {
		_name = "";
		_state = -1;
	};
};
TRACE_1("",_name);

[QGVAR(dogtagAnsw), [_sender, _receiver, [_state, _name]]] call ACE_fnc_receiverOnlyEvent;
