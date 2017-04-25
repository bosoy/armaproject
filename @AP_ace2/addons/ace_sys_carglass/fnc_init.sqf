#include "script_component.hpp"

PARAMS_1(_veh);

if (count crew _veh == 0) exitWith {false};

if (player in _veh) then {
	[_veh,"DRIVER",player] call FUNC(getIn);
};
