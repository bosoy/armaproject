#include "script_component.hpp"

private "_i";
PARAMS_2(_unit,_leftdamagemodifier);

// Never heal 100%, always leave some damage, and increase it depending on how many times the unit was healed.
// Unless at a medical facility, there allow full heal

_damLeft = GVAR(leftdam) * _leftdamagemodifier;

if (GVAR(leftdam) == 0) then {
	_i = 0;
} else {
	_i = _unit getVariable ["ace_w_hc", 0];
	INC(_i);
};
_unit setVariable ["ace_w_hc", _i];

// Setdamage also resets damage textures, and perhaps also the hits set with setHit
// So we do it before setHit
_dam = (_damLeft * _i) min MAX_UNFORCED_DAM;
if (damage _unit > _dam) then { _unit setDamage _dam; _unit setVariable ["ace_w_overall", _dam] };

for "_j" from 0 to 3 do {
	// Leave some damage, but never more than is already on the part
	_current = _unit getVariable [GVAR(parts) select _j, 0];
	if (_current > 0) then {
		_nd = (_damLeft * _i) min _current;
		[_unit, _j, _nd] call FUNC(setHit);
	};
};

_damage = [_unit] call FUNC(getDamage);
TRACE_2("Dam",_dam,_damage);
