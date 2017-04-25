#include "script_component.hpp"

PARAMS_1(_unit);
if (GVAR(all_medics)) exitWith { true };
private "_ret";
_ret = _unit getVariable "ace_w_ismedic";
if (isNil "_ret") then {
	_ret = (getNumber (configFile >> "CfgVehicles" >> typeOf _unit >> "attendant") == 1);
};

_ret;
