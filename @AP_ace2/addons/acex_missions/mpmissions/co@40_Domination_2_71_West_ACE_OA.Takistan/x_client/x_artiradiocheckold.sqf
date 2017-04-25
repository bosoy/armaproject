// by Xeno
#define THIS_FILE "x_artiradiocheckold.sqf"
#include "x_setup.sqf"
private ["_vec","_vec_id","_artinum"];
PARAMS_1(_artinum);
_vec_id = -8882;
_vec = objNull;
__pSetVar [QGVAR(ari1), -8881];
while {true} do {
	waitUntil {alive player};
	waitUntil {sleep 0.312; isNumber(configFile >> "CfgWeapons" >> secondaryWeapon player >> "ACE_is_radio")};
	switch (_artinum) do {
		case 1: {__pSetVar [QGVAR(ari1), player addAction [(localize "STR_DOM_MISSIONSTRING_153") call FUNC(GreyText), "x_client\x_artillery.sqf",[1,GVAR(AriTarget)],-1,false]]};
		case 2: {__pSetVar [QGVAR(ari1), player addAction [(localize "STR_DOM_MISSIONSTRING_153") call FUNC(GreyText), "x_client\x_artillery.sqf",[2,GVAR(AriTarget2)],-1,false]]};
	};
	while {isNumber(configFile >> "CfgWeapons" >> secondaryWeapon player >> "ACE_is_radio")} do {
		sleep 0.52;
		if (!alive player) exitWith {
			_id = __pGetVar(GVAR(ari1));
			if (_id != -8881) then {
				player removeAction _id;
				__pSetVar [QGVAR(ari1), -8881];
			};
			if (_vec_id != -8882) then {
				_vec removeAction _vec_id;
				_vec_id = -8882;
			};
		};
		if (vehicle player != player) then {
			_vec = vehicle player;
			if (player != driver _vec && _vec_id == -8882) then {
				switch (_artinum) do {
					case 1: {_vec_id = _vec addAction [(localize "STR_DOM_MISSIONSTRING_153") call FUNC(GreyText), "x_client\x_artillery.sqf",[1,GVAR(AriTarget)],-1,false]};
					case 2: {_vec_id = _vec addAction [(localize "STR_DOM_MISSIONSTRING_153") call FUNC(GreyText), "x_client\x_artillery.sqf",[2,GVAR(AriTarget2)],-1,false]};
				};
			} else {
				if (_vec_id != -8882 && player == driver _vec) then {
					_vec removeAction _vec_id;
					_vec_id = -8882;
				};
			};
		} else {
			if (_vec_id != -8882) then {
				_vec removeAction _vec_id;
				_vec_id = -8882;
			};
		};
	};
	if (alive player && !isNumber(configFile >> "CfgWeapons" >> secondaryWeapon player >> "ACE_is_radio")) then {
		_id = __pGetVar(GVAR(ari1));
		if (_id != -8881) then {
			player removeAction _id;
			__pSetVar [QGVAR(ari1), -8881];
		};
		if (_vec_id != -8882) then {
			_vec removeAction _vec_id;
			_vec_id = -8882;
		};
	};
	sleep 1.021;
};