#include "script_component.hpp"

disableSerialization;
_index = _this select 0 select 1;

_veh = GET_SELECTED_VEHICLE;
_veh_type = GET_SELECTED_DATA(66363);
_weapon = GET_CTRL(66365) lbData _index;
_default_magazines = getArray(configFile >> "CfgVehicles" >> _veh_type >> "Turrets" >> "MainTurret" >> "magazines");
_compatible_magazines = getArray(configFile>>"CfgWeapons">>_weapon>>"magazines");

if (_veh isKindOf "Plane" || {_veh isKindOf "Helicopter"}) then {
	{	if (_weapon in _x) then {
			{
				_compatible_magazines = _compatible_magazines + getArray(configFile>>"CfgWeapons">>_x>>"magazines");
			}forEach _x;
		};
	} forEach CHANGABLE_WEAPONS;
	_magazines = [];
	{
		if !(_x in _magazines) then {
			_magazines = _magazines + [_x];
		};
	} forEach _compatible_magazines;
	_compatible_magazines = _magazines;
};


lbClear GET_CTRL(66368);
{
	_display_name = (getText(configFile >> "CfgMagazines" >> _x >> "displayName"));
	if (_display_name=="") then {
		GET_CTRL(66368) lbAdd _x;
	} else {
		GET_CTRL(66368) lbAdd _display_name;
	};
	GET_CTRL(66368) lbSetData [(lbSize GET_CTRL(66368))-1,_x];
} forEach _compatible_magazines;

GET_CTRL(66368) lbSetCurSel 0;