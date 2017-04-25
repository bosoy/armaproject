#include "script_component.hpp"

disableSerialization;
_veh = GET_SELECTED_VEHICLE;
_veh_type = GET_SELECTED_DATA(66363);
GET_CTRL(66362) ctrlSetText (getText(configFile >> "CfgVehicles" >> typeOf(_veh) >> "picture"));


lbClear GET_CTRL(66364);
_default_magazines = getArray(configFile >> "CfgVehicles" >> _veh_type >> "magazines");
_weapons = _veh weaponsTurret [-1];
if !((_weapons select 0) in ["FakeWeapon","CarHorn","BikeHorn","TruckHorn","TruckHorn2","SportCarHorn","MiniCarHorn"]) then {
	GET_CTRL(66364) lbAdd "Hull";
	GET_CTRL(66364) lbSetValue [(lbSize GET_CTRL(66364))-1,-1];
};
if (isClass(configFile >> "CfgVehicles" >> _veh_type >> "Turrets")) then {
	_turrets = (configFile >> "CfgVehicles" >> _veh_type >> "Turrets");
	for "_i" from 0 to ((count _turrets)-1) do {
		_turret = _turrets select _i;
		_weapons = _veh weaponsTurret [_i];

		if !(isNil {_weapons select 0}) then {
			GET_CTRL(66364) lbAdd getText(_turret >> "gunnerName");
			GET_CTRL(66364) lbSetValue [(lbSize GET_CTRL(66364))-1,_i];
			_default_magazines = _default_magazines +  getArray(_turret >> "magazines");
		};
		_subturrets = _turret >> "Turrets";
		for "_j" from 0 to (count _subturrets)-1 do {
			_turret = _subturrets select _j;
			_weapons = _veh weaponsTurret [_i,_j];
			if !(isNil {_weapons select 0}) then {
				GET_CTRL(66364) lbAdd getText(_turret >> "gunnerName");
				GET_CTRL(66364) lbSetValue [(lbSize GET_CTRL(66364))-1,-2-_i*10-_j];
				_default_magazines = _default_magazines +  getArray(_turret >> "magazines");
			};
		};
	};
}else{};
lbClear GET_CTRL(66367);
{
	_display_name = (getText(configFile >> "CfgMagazines" >> _x >> "displayName"));
	if (_display_name=="") then {
		GET_CTRL(66367) lbAdd str _x;
	} else {
		GET_CTRL(66367) lbAdd _display_name;
	};
	GET_CTRL(66367) lbSetData [(lbSize GET_CTRL(66367))-1,_x];
} forEach _default_magazines;

GET_CTRL(66364) lbSetCurSel 0;

[] call FUNC(fill_weapon_list);