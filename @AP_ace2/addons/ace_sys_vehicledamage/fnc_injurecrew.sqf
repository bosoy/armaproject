//takes vehicle and prob of injuring of each occupant
//calls dmg func for local and non-local occupants

#include "script_component.hpp"
PARAMS_3(_vehicle,_p,_max);
private ["_nonlocals","_injcount","_toinjure","_cur","_c","_ind","_u","_cc"];
_nonlocals = [];
_c = crew _vehicle;
_cc = count _c;
if (_cc == 0) exitwith {};
_ind = [];
_toinjure = []; //indices of dudes to injure

//array of available crew indices
for "_i" from 0 to (_cc - 1) do {
	_ind set[_i,_i];
};
// randomized list of ppl to injure
for "_i" from 0 to (_cc - 1) do {
	if (_p > random 1) then {
		_cur = _ind call ACE_fnc_selectrandom;
		PUSH(_toinjure,_cur);
		_ind = _ind - [_cur];
		_u = _c select _cur;	//current unit
		if (true) then {
			if (isNull _u) exitwith { TRACE_1("Injuring: isNull",_u); };
			if (! alive _u) exitwith { TRACE_1("Injuring: Not alive",_u); };
			if !(local _u) then {
				PUSH(_nonlocals,_u);
			} else {
				[_u] spawn FUNC(injureman);
			};
		};
	};
	if (count _toinjure >= _max) exitwith {};
};

//MP broadcast for non-local occupants

if (count _nonlocals > 0) then {
	[QGVAR(handle_injurecrew), _nonlocals] call CBA_fnc_globalEvent;
};
