/* ace_sys_explosives (.pbo)| M86 PDM Munition | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

PARAMS_2(_trigger,_list);
_mine = [_trigger] call FUNC(get_mine);
if (isNull _mine) exitwith { false };

[_mine] call FUNC(spawnpellets_360);
"ACE_M86PDMExplosion" createVehicle [(position _mine) select 0,(position _mine) select 1, 0.3 + (([_mine] call CBA_fnc_realHeight) + 1 + (random 1.5))];
[_mine] call FUNC(removeMine);