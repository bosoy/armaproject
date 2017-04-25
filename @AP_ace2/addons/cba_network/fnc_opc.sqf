/*
	Internal Function: CBA_network_fnc_opc
*/
#include "script_component.hpp"

private["_plName"];
PARAMS_4(_name,_id,_obj,_cba);

_plName = if (isNull player) then { "" } else { name player };

if ((_name!= "__SERVER__") && {(_name!= format["%1", _plName])}) then
{
	if (time > 0) then
	{
		[_obj] call FUNC(sync); { _x setMarkerPos (getMarkerPos _x) } forEach GVAR(markers);
	};
};
