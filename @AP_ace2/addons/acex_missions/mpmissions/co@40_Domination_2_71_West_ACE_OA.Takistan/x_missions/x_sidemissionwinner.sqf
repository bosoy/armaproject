// by Xeno
#define THIS_FILE "x_sidemissionwinner.sqf"
#include "x_setup.sqf"
private ["_bonus_string","_s", "_bonus_vecn"];

if (!X_Client) exitWith {};

_bonus_vecn = _this;

sleep 1;

deleteMarkerLocal (format ["XMISSIONM%1", GVAR(x_sm_oldmission_index) + 1]);
if (GVAR(x_sm_type) == "convoy") then {deleteMarkerLocal (format ["XMISSIONM2%1", GVAR(x_sm_oldmission_index) + 1])};

GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_712");

if (GVAR(side_mission_winner) != 0 && _bonus_vecn != "") then {
	if (GVAR(with_ranked)) then {
		_get_points = false;
		if (isNil QGVAR(sm_p_pos)) then {
			_posi_array = GVAR(x_sm_pos);
			_posione = _posi_array select 0;
			if (player distance _posione < (GVAR(ranked_a) select 12)) then {_get_points = true};
		} else {
			if (!isNil QGVAR(sm_p_pos) && GVAR(was_at_sm) && GVAR(x_sm_type) != "convoy") then {
				if (player distance GVAR(sm_p_pos) < (GVAR(ranked_a) select 12)) then {_get_points = true};
			} else {
				if !(isNil QGVAR(sm_p_pos)) then {
					if (player distance GVAR(sm_p_pos) < (GVAR(ranked_a) select 12)) then {_get_points = true};
				};
			};
		};
		if (_get_points) then {
			(format [(localize "STR_DOM_MISSIONSTRING_713"),(GVAR(ranked_a) select 11)]) call FUNC(HQChat);
			0 spawn {
				sleep (0.5 + random 2);
				[QGVAR(pas), [player, GVAR(ranked_a) select 11]] call FUNC(NetCallEventCTS);
			};
		};
		GVAR(sm_p_pos) = nil;
	};

#ifndef __TT__
	_bonus_string = format[(localize "STR_DOM_MISSIONSTRING_714"), [_bonus_vecn,0] call FUNC(GetDisplayName)];
#else
	_team = switch (GVAR(side_mission_winner)) do {
		case 1: {(localize "STR_DOM_MISSIONSTRING_579")};
		case 2: {(localize "STR_DOM_MISSIONSTRING_578")};
		case 123: {(localize "STR_DOM_MISSIONSTRING_580")};
	};
	_bonus_string = format[(localize "STR_DOM_MISSIONSTRING_715"), _team];
#endif

	if (GVAR(MissionType) != 2 && GVAR(sideMissionBonus) == 0) then {
		hint composeText[
			parseText("<t color='#f0ffff00' size='1'>Sidemission resolved</t>"), lineBreak,lineBreak,
			(localize "STR_DOM_MISSIONSTRING_572"), lineBreak,lineBreak,
			GVAR(current_mission_resolved_text), lineBreak, lineBreak,
			_bonus_string
		];
	} else {
		hint composeText[
			parseText("<t color='#f0ffff00' size='1'>Sidemission resolved</t>"), lineBreak,lineBreak,
			(localize "STR_DOM_MISSIONSTRING_572"), lineBreak,lineBreak,
			GVAR(current_mission_resolved_text)
		];
	};
} else {
	_s = switch (GVAR(side_mission_winner)) do {
		case -1: {(localize "STR_DOM_MISSIONSTRING_716")};
		case -2: {(localize "STR_DOM_MISSIONSTRING_717")};
		case -300: {(localize "STR_DOM_MISSIONSTRING_718")};
		case -400: {(localize "STR_DOM_MISSIONSTRING_719")};
		case -500: {(localize "STR_DOM_MISSIONSTRING_720")};
		case -600: {(localize "STR_DOM_MISSIONSTRING_721")};
		case -700: {(localize "STR_DOM_MISSIONSTRING_722")};
		case -878: {(localize "STR_DOM_MISSIONSTRING_723")};
		case -879: {(localize "STR_DOM_MISSIONSTRING_724")};
		default {""};
	};
	if (_s != "") then {
		hint composeText[
			parseText("<t color='#f0ff00ff' size='1'>" + (localize "STR_DOM_MISSIONSTRING_725") + "</t>"), lineBreak,lineBreak,
			_s
		];
	};
};

sleep 1;
GVAR(side_mission_winner) = 0;