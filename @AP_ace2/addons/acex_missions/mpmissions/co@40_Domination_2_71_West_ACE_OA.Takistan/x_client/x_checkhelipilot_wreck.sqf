// by Xeno
#define THIS_FILE "x_checkhelipilot_wreck.sqf"
#include "x_setup.sqf"
private ["_vehicle","_position","_enterer","_was_engineon"];

_enterer = _this select 2;
__notlocalexit(_enterer);

PARAMS_2(_vehicle,_position);

_was_engineon = isEngineOn _vehicle;

_exit_it = false;

#ifdef __TT__
_d_side = GV(_vehicle,GVAR(side));
if (!isNil "_d_side") then {
	if (GVAR(player_side) == west && _d_side == east) then {
		_exit_it = true;
		[(localize "STR_DOM_MISSIONSTRING_173"), "SIDE"] call FUNC(HintChatMsg);
	} else {
		if (GVAR(player_side) == east && _d_side == west) then {
			_exit_it = true;
			[(localize "STR_DOM_MISSIONSTRING_178"), "SIDE"] call FUNC(HintChatMsg);
		};
	};
};
#endif

if (!_exit_it && _position == "driver") then {
	if (GVAR(with_ranked)) then {
		_index = (toUpper GVAR(wreck_lift_rank)) call FUNC(GetRankIndex);
		_indexp = (rank player) call FUNC(GetRankIndex);
		if (_indexp < _index) exitWith {
			(format [(localize "STR_DOM_MISSIONSTRING_179"), rank player,(toUpper GVAR(wreck_lift_rank)) call FUNC(GetRankString)]) call FUNC(HQChat);
			_exit_it = true;
		};
	};
	if (_exit_it) exitWith {};
	_may_fly = true;
	if (count GVAR(only_pilots_can_fly) > 0) then {
		if !(str(_enterer) in GVAR(only_pilots_can_fly)) then {
			_may_fly = false;
			//hintSilent (localize "STR_DOM_MISSIONSTRING_175");
			_exit_it = true;
		};
	};
	if (_may_fly && _enterer == player) then {
		if (GVAR(chophud_on)) then {
			__pSetVar [QGVAR(hud_id), _vehicle addAction [(localize "STR_DOM_MISSIONSTRING_176") call FUNC(GreyText), "x_client\x_sethud.sqf",0,-1,false]];
		} else {
			__pSetVar [QGVAR(hud_id), _vehicle addAction [(localize "STR_DOM_MISSIONSTRING_177") call FUNC(GreyText), "x_client\x_sethud.sqf",1,-1,false]];
		};
		[_vehicle] execVM "x_client\x_helilift_wreck.sqf";
	};
};

if (_exit_it) exitWith {
	if (!_was_engineon && isEngineOn _vehicle) then {
		_vehicle engineOn false;
		_enterer action ["engineOff", _vehicle];
	};
	_enterer action["Eject",_vehicle];
};