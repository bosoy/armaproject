#include "script_component.hpp"

PARAMS_2(_dragee,_unit);

while {!isNull (_dragee getVariable ["ace_w_carry", objNull])} do {
	if (!alive _unit || {(_unit call FUNC(isUncon))}) exitWith {};
	sleep 1;
};

sleep 3;
if (animationState _dragee in ["ainjppnemstpsnonwrfldb_still", "ainjpfalmstpsnonwrfldnon_carried_up"]) then {
	detach _dragee;
	if (!isNull _unit) then {
		detach _unit;
	};
	if ((alive _dragee && {(_dragee call FUNC(isUncon))}) || {!alive _dragee}) then {
		[_dragee, 101] call FUNC(animator);
	} else {
		[_dragee, 102] call FUNC(animator);
	};
	if (!isNull (_dragee getVariable ["ace_w_carry", objNull])) then {
		_dragee setVariable ["ace_w_carry", objNull, true];
	};
};