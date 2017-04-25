#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP(dogtagUnit);
PREP(unitInit);
PREP(removedogtag);

FUNC(respawn) = {
	PARAMS_1(_unit);
	if !(alive _unit) exitWith {};
	
	_unit setVariable [QGVAR(DogTagTaken), nil];
	_nameu = _unit getVariable QGVAR(name);
	if (isNil "_nameu" || {_nameu != name _unit}) then {
		_unit setVariable [QGVAR(name), name _unit];
	};
};

[QGVAR(dogtagUnit), { _this call FUNC(dogtagUnit) }] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(removeDogtag), { _this call FUNC(removedogtag) }] call ACE_fnc_addReceiverOnlyEventhandler;

ADDON = true;
