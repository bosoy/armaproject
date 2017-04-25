#include "script_component.hpp"

PARAMS_3(_veh,_p,_unit);

if (!local _unit) exitWith {};

if (GVAR(caraction) != -9999) then {
	_veh removeAction GVAR(caraction);
	GVAR(caraction) = -9999;
};