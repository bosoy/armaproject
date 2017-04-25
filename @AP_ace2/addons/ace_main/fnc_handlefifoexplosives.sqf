#include "script_component.hpp"

_bomb = _this;
"ACE_PomzExplosion" createVehicle [(position _bomb) select 0,(position _bomb) select 1, 0.3 + (([_bomb] call CBA_fnc_realHeight) + 1 + (random 1.5))];
deleteVehicle _bomb;