/* ace_sys_explosives (.pbo)| POMZ | (c) 2008, 2009, 2010, 2011, 2012 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_trigger,_list);
_mine = [_trigger] call FUNC(get_mine);
if (isNull _mine) exitwith { false };

[_mine] call FUNC(spawnpellets_360);
"ACE_PomzExplosion" createVehicle [(position _mine) select 0,(position _mine) select 1, 0.3 + ([_mine] call CBA_fnc_realHeight)];
[_mine] call FUNC(removeMine);
