#include "script_component.hpp"

PARAMS_1(_vehicle);

if (player in [gunner _vehicle, driver _vehicle]) then {
	_vehicle setVariable ["RU_SYSTEMS_LOADED", nil];
	player setVariable ["MY_LITTLE_RU",_vehicle];

	sleep 0.01;

	if (isNil {_vehicle getVariable "RU_SYSTEMS_LOADED"}) then {
		cutRsc ["Generic_Russian_Display", "plain"];	// Internal will care for itself.
	};
};
