#include "script_component.hpp"

PARAMS_1(_veh);

if (_veh isKindOf "ParachuteBase") exitWith {};

if (vehicle player == _veh) then {
	[] spawn FUNC(engineloop);
};
