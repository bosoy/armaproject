// 2010 by Xeno
if (!(isNil "ace_sys_map_enabled") && {ace_sys_map_enabled} && {local _this}) then {  // Removes default map, relies MM adds ItemMap or ACE_Map to the unit
	if (_this hasWeapon "ItemMap") then {
		_this removeWeapon "ItemMap";
	};
	if (count units group _this > 1 && {_this == leader group _this}) then { // Gives squadleader a map
		if !(_this hasWeapon "ACE_Map") then { 
			_this addWeapon "ACE_Map";
		};
	};
};
