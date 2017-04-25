// by Xeno
#define THIS_FILE "x_recruitaiaction.sqf"
#include "x_setup.sqf"
private ["_grpplayer", "_exitj", "_rank", "_target"];

_grpplayer = group player;

if (player != leader _grpplayer) exitWith {
	(localize "STR_DOM_MISSIONSTRING_311") call FUNC(HQChat);
};

PARAMS_1(_target);

if (player distance _target > 50) exitWith {
	(localize "STR_DOM_MISSIONSTRING_312") call FUNC(HQChat);
};

GVAR(current_ai_num) = 0;
{
	if (!isPlayer _x && alive _x) then {
		__INC(GVAR(current_ai_num));
	};
} forEach units _grpplayer;

createDialog "XD_AIRecruitDialog";