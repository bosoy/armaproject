// by Xeno
#define THIS_FILE "x_getsidemissionclient.sqf"
private ["_do_hint","_mis_fname"];
#include "x_setup.sqf"
if (!X_Client) exitWith{};

PARAMS_1(_do_hint);

if (__XJIPGetVar(GVAR(current_mission_index)) == -1) exitWith {};

GVAR(x_sm_oldmission_index) = __XJIPGetVar(GVAR(current_mission_index));

_mfname = switch (true) do {
	case (__OAVer): {"moa"};
	case (__COVer): {"m"};
};
_mis_fname = format ["x_missions\" + _mfname + "\%2%1.sqf",__XJIPGetVar(GVAR(current_mission_index)),GVAR(mission_filename)];

if (!X_SPE) then {call compile preprocessFileLineNumbers _mis_fname};

sleep 0.01;

if (GVAR(with_ranked)) then {
	GVAR(was_at_sm) = false;
	GVAR(sm_running) = true;
};

if (__XJIPGetVar(GVAR(current_mission_index)) != -1) then {
	_posi_array = GVAR(x_sm_pos);
	_posione = _posi_array select 0;
	if (GVAR(x_sm_type) != "convoy") then {
		_m_name = format ["XMISSIONM%1", __XJIPGetVar(GVAR(current_mission_index)) + 1];
		[_m_name,_posione,"ICON","ColorRed",[1,1],(localize "STR_DOM_MISSIONSTRING_707"),0,"hd_destroy"] call FUNC(CreateMarkerLocal);
		if (GVAR(with_ranked)) then {
			_posione spawn {
				private "_posione";
				_posione = _this;
				while {GVAR(sm_running)} do {
					if (player distance _posione < (GVAR(ranked_a) select 12)) exitWith {
						GVAR(was_at_sm) = true;
						GVAR(sm_running) = false;
					};
					sleep 3.012 + random 3;
				};
			};
		};
	} else {
		_m_name = format ["XMISSIONM%1", __XJIPGetVar(GVAR(current_mission_index)) + 1];
		[_m_name, _posione,"ICON","ColorRed",[1,1],(localize "STR_DOM_MISSIONSTRING_708"),0,"hd_start"] call FUNC(CreateMarkerLocal);
		_m_name = format ["XMISSIONM2%1", __XJIPGetVar(GVAR(current_mission_index)) + 1];
		_posione = _posi_array select 1;
		[_m_name, _posione,"ICON","ColorRed",[1,1],(localize "STR_DOM_MISSIONSTRING_709"),0,"mil_pickup"] call FUNC(CreateMarkerLocal);
	};
};

if (_do_hint) then {
	playSound "IncomingChallenge2";
	hint composeText[
		parseText("<t color='#f000ffff' size='1'>" + (localize "STR_DOM_MISSIONSTRING_710") + "</t>"), lineBreak,lineBreak,
		GVAR(current_mission_text)
	];
};