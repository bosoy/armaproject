#include "\x\ace\addons\sys_explosives\script_component.hpp"

private "_TOA_ID";

_action = _this select 2;
_arguments = _this select 3;
_mine = _arguments select 0;
_id = _arguments select 1;
_dn = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "name");
_cl = getNumber(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "clacker_length");

_clackerResetTime = time + 120;

if (!(missionNamespace getVariable (format ["SOA_M18_LOCK_%1", _id]))) then {
	while { !isNull _mine && time < _clackerResetTime } do {
		if (_cl - (player distance _mine) >= 0) then {
			if (typeName (_mine getVariable ["TOAID",false]) == "BOOL") then {
				_A_S = format [localize "STR_ACE_SYS_EXPLOSIVES_TOUCHOFF",_dn,_id];
				missionNamespace setVariable [format ["SOA_M18_LOCK_%1", _id], true];
				_TOA_ID = player addAction [_A_S, (__DIR + "\fnc_detonate_M18.sqf"), _mine, 80, false, false, "","local _target && isPlayer _target && !(_target getVariable ['ace_sys_wounds_uncon',false])"]; // TODO: Generate detonation function dynamically
				_mine setVariable ["TOAID",_TOA_ID];
				player removeAction _action;
			};
		} else {
			//localize "STR_HINT_ACE_SYS_EXPLOSIVES_TOOFAR" spawn ACE_fnc_visual;
			player removeAction _TOA_ID;
			_mine setVariable ["TOAID",false];
		};		
		sleep 1;
	};
	player removeAction _TOA_ID;
	_mine setVariable ["TOAID",false];
	
	missionNamespace setVariable [format ["SOA_M18_LOCK_%1", _id], false];
	if (!isNull _mine) then {
		[_dn,_id] call FUNC(showClackerResetHint);
		_mine setVariable ["SOAID",false];
	};	
};
