#include "script_component.hpp"

PARAMS_2(_trigger,_list);
_mine = [_trigger] call FUNC(get_mine);
if (isNull _mine) exitwith { false };

private "_vehicle";
_vehicle = _list select 0;

_explosion = "ACE_SLAMBottomEFP" createVehicle (getPos _vehicle);
_explosion attachto [_vehicle,[0,0,0]];
[_mine] call FUNC(removeMine);
