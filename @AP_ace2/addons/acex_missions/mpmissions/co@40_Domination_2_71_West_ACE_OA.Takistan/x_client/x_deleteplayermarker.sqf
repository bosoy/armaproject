// by Xeno
#define THIS_FILE "x_deleteplayermarker.sqf"
#include "x_setup.sqf"
private "_marker";

_d_show_player_marker = GVAR(show_player_marker);
if (_d_show_player_marker > 0) then {
	switch (_d_show_player_marker) do {
		case 1: {(localize "STR_DOM_MISSIONSTRING_205") call FUNC(GlobalChat)};
		case 2: {(localize "STR_DOM_MISSIONSTRING_206") call FUNC(GlobalChat)};
		case 3: {(localize "STR_DOM_MISSIONSTRING_207") call FUNC(GlobalChat)};
		case 4: {(localize "STR_DOM_MISSIONSTRING_208") call FUNC(GlobalChat)};
	};
};

if (_d_show_player_marker == 0) then {
	(localize "STR_DOM_MISSIONSTRING_209") call FUNC(GlobalChat);
	sleep 2.123;
	{
		_marker = _x;
		_marker setMarkerPosLocal [0,0];
		_marker setMarkerAlphaLocal 0;
	} forEach GVAR(player_entities);
	(localize "STR_DOM_MISSIONSTRING_210") call FUNC(GlobalChat);
} else {
	{
		_marker = _x;
		_marker setMarkerAlphaLocal 1;
	} forEach GVAR(player_entities);
};