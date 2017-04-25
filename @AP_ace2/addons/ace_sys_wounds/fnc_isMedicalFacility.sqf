#include "script_component.hpp"

private "_ret";
PARAMS_1(_unit);

if (isNull _unit) exitWith { false };

_ret = _unit getVariable "ACE_W_HEAL";
if (isNil "_ret") then {
	_ret = if (GVAR(no_medical_vehicles) && {_unit isKindOf "AllVehicles"}) then { false } else { (getNumber (configFile >> "CfgVehicles" >> typeOf _unit >> "ACE_W_HEAL") == 1) };
};

_ret;
