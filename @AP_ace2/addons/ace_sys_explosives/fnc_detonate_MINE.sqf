/* ace_sys_explosives (.pbo)| Mine | (c) 2008, 2009, 2010, 2011 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_trigger,_list);

private ["_vehicle","_mine"];
_mine = [_trigger] call FUNC(get_mine);
if (isNull _mine) exitwith { false };
_vehicle = _list select 0;

_type = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "explosion_type");
_explosion = _type createVehicle [(position _mine) select 0,(position _mine) select 1, 0.3 + ([_mine] call CBA_fnc_realHeight)];
_explosion attachto [_vehicle,[0,0,0]];
[_mine] call FUNC(removeMine);
