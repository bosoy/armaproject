// by Xeno
#define THIS_FILE "x_dropradiocheckold.sqf"
#include "x_setup.sqf"
private ["_vec","_dropaction","_vec_id"];
_vec_id = -8884;
_vec = objNull;
__pSetVar [QGVAR(dropaction), -8883];
while {true} do {
	waitUntil {alive player};
	waitUntil {sleep 0.312; isNumber(configFile >> "CfgWeapons" >> secondaryWeapon player >> "ACE_is_radio")};
	__pSetVar [QGVAR(dropaction), player addAction [(localize "STR_DOM_MISSIONSTRING_230") call FUNC(GreyText), "x_client\x_calldrop.sqf",[],-1,false]];
	while {isNumber(configFile >> "CfgWeapons" >> secondaryWeapon player >> "ACE_is_radio")} do {
		sleep 0.512;
		if (!alive player) exitWith {
			_id = __pGetVar(GVAR(dropaction));
			if (_id != -8883) then {
				player removeAction _id;
				__pSetVar [QGVAR(dropaction), -8883];
			};
			if (_vec_id != -8884) then {
				_vec removeAction _vec_id;
				_vec_id = -8884;
			};
		};
		if (vehicle player != player) then {
			_vec = vehicle player;
			if (player != driver _vec && _vec_id == -8884) then {
				_vec_id = _vec addAction [(localize "STR_DOM_MISSIONSTRING_230") call FUNC(GreyText), "x_client\x_calldrop.sqf",[],-1,false];
			} else {
				if (_vec_id != -8884 && player == driver _vec) then {
					_vec removeAction _vec_id;
					_vec_id = -8884;
				};
			};
		} else {
			if (_vec_id != -8884) then {
				_vec removeAction _vec_id;
				_vec_id = -8884;
			};
		};
	};
	if (alive player && !(isNumber(configFile >> "CfgWeapons" >> secondaryWeapon player >> "ACE_is_radio"))) then {
		_id = __pGetVar(GVAR(dropaction));
		if (_id != -8883) then {
			player removeAction _id;
			__pSetVar [QGVAR(dropaction), -8883];
		};
		if (_vec_id != -8884) then {
			_vec removeAction _vec_id;
			_vec_id = -8884;
		};
	};
	sleep 1.021;
};