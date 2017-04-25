#include "\x\ace\addons\sys_explosives\script_component.hpp"

PARAMS_2(_mine,_take);

_magazine = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(mine_magazine));

call FUNC(anim);

if (_take) then {
	player addMagazine _magazine;
	if (!isnil "pzn_delete_mine") then {_mine call pzn_delete_mine};deletevehicle _mine;
} else {
	_am = _mine getVariable ["ace_sys_explosives_attackmode", "BLABLA"];
	if (_am in ["SIDE","BOTTOM"]) then {
		_antitamper = "ACE_ClaymoreExplosion" createVehicle [(position _mine) select 0,(position _mine) select 1, (0.8 + ([_mine] call CBA_fnc_realHeight))];
		if (!isnil "pzn_delete_mine") then {_mine call pzn_delete_mine};deletevehicle _mine;
	} else {
		_wh = "WeaponHolder" createVehicle getPos _mine;
		_wh setpos getpos _mine;
		if (!isnil "pzn_delete_mine") then {_mine call pzn_delete_mine};deletevehicle _mine;
		_wh addMagazineCargoGlobal [_magazine,1];
	};
};
