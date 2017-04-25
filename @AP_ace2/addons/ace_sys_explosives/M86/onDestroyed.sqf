#include "\x\ace\addons\sys_explosives\script_component.hpp"

PARAMS_2(_mine,_ex);

[_mine] call FUNC(spawnpellets_360);
_ex createVehicle [(position _mine) select 0,(position _mine) select 1, 0.3 + ([_mine] call CBA_fnc_realHeight)];
