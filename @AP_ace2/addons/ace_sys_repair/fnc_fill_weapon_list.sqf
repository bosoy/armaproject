#include "script_component.hpp"

disableSerialization;
_veh = GET_SELECTED_VEHICLE;
_veh_type = GET_SELECTED_DATA(66363);
_index_turret = GET_INDEX_TURRET;
_weapons = GET_WEAPONS_TURRET;

lbClear GET_CTRL(66365);
{
	GET_CTRL(66365) lbAdd str _x;
	GET_CTRL(66365) lbSetData [(lbSize GET_CTRL(66365))-1,_x];
} forEach _weapons;
GET_CTRL(66365) lbSetCurSel 0;


[[0,0]] call FUNC(fill_compatible_magazines_list);
[[0,0]] call FUNC(fill_current_magazines_list);

GET_CTRL(66369) lbSetCurSel 0;
GET_CTRL(66368) lbSetCurSel 0;