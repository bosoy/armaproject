#include "script_component.hpp"

PARAMS_1(_veh);
if !(alive _veh) exitWith {};
DEFAULT_PARAM(1,_dirOffset,0);
DEFAULT_PARAM(2,_pitchOffset,0);

[_veh,_dirOffset,_pitchOffset] call FUNC(Kh29_lasepfh);