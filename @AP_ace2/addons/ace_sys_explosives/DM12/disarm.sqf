#include "\x\ace\addons\sys_explosives\script_component.hpp"

PARAMS_1(_mine);

call FUNC(anim);

_armed = GVAR(mine) getVariable [QGVAR(arm),false];

_magazine = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(mine_magazine));
if (!_armed) then {
	player addMagazine _magazine;
	if (!isnil "pzn_delete_mine") then {_mine call pzn_delete_mine};deletevehicle _mine;
} else {
	_antitamper = "ACE_ClaymoreExplosion" createVehicle [(position _mine) select 0,(position _mine) select 1, (0.8 + ([_mine] call CBA_fnc_realHeight))];
	if (!isnil "pzn_delete_mine") then {_mine call pzn_delete_mine};deletevehicle _mine;
};
