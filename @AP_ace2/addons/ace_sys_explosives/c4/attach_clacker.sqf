#include "\x\ace\addons\sys_explosives\script_component.hpp"

private "_SOA_ID";

_mine = _this;
_id = _mine call FUNC(get_id);
_dn = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "name");
_cl = getNumber(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "clacker_length");

[_mine,false] call FUNC(set_ready);
if (getNumber(configFile >> "CfgMagazines" >> (getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "mine_magazine")) >> "useAction") == 0) then {
	_mine call FUNC(createClackerList);
};

while { !isNull _mine } do {
	if (_cl - (player distance _mine) >= 0) then {
		if (typeName (_mine getVariable ["SOAID",false]) == "BOOL" && {typeName (_mine getVariable ["TOAID",false]) == "BOOL"})  then {
			_A_S = format [localize "STR_ACE_SYS_EXPLOSIVES_SAFETYOFF",_dn,_id];
			missionNamespace setVariable [format ["SOA_C4_LOCK_%1", _id], false];
			_SOA_ID = player addAction [_A_S, (PATH + "safety_off.sqf"), [_mine, _id], 40, false, false, "","_target == player && {!(_target getVariable ['ace_sys_wounds_uncon',false])}"]; // TODO: Hide the safety off action
			_mine setVariable ["SOAID",_SOA_ID];
		};
	} else {
		//localize "STR_HINT_ACE_SYS_EXPLOSIVES_TOOFAR" spawn ACE_fnc_visual;
		player removeAction _SOA_ID;
		_mine setVariable ["SOAID",false];
	};
	sleep 1;
};

player removeAction _SOA_ID;
