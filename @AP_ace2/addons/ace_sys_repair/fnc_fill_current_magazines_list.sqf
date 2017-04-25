#include "script_component.hpp"

_index = _this select 0 select 1;

_veh = GET_SELECTED_VEHICLE;
_veh_type = GET_SELECTED_DATA(66363);
_weapon = GET_CTRL(66365) lbData _index;
if (isNil "_index") then {
_weapon = GET_SELECTED_DATA(66365)};
_compatible_magazines = getArray(configFile>>"CfgWeapons">>_weapon>>"magazines");

if (_veh isKindOf "Plane" || {_veh isKindOf "Helicopter"}) then {
	{	if (_weapon in _x) then {
			{
				_compatible_magazines = _compatible_magazines + getArray(configFile>>"CfgWeapons">>_x>>"magazines");
			}forEach _x;
		};
	} forEach CHANGABLE_WEAPONS;
};

_current_magazines = GET_CURRENT_MAGAZINES_TURRET;

lbClear GET_CTRL(66369);
{
	if (_x in _compatible_magazines) then {
		_display_name = (getText(configFile >> "CfgMagazines" >> _x >> "displayName"));
		if (_display_name=="") then {
			GET_CTRL(66369) lbAdd _x;
		} else {
			GET_CTRL(66369) lbAdd _display_name;
		};
		GET_CTRL(66369) lbSetData [(lbSize GET_CTRL(66369))-1,_x];
	};
} forEach _current_magazines;

_cap = [] call FUNC(get_capacity);
GET_CTRL(66366) ctrlSetText format [localize "STR_ACE_REP_DL_CAP",_cap select 0,_cap select 1];
