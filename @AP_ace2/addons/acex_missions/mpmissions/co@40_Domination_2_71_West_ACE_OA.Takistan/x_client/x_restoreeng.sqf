// by Xeno
#define THIS_FILE "x_restoreeng.sqf"
#include "x_setup.sqf"
if (player distance (_this select 0) > 20) exitWith {
	(localize "STR_DOM_MISSIONSTRING_339") call FUNC(GlobalChat);
};
if (!GVAR(eng_can_repfuel)) then {
	GVAR(eng_can_repfuel) = true;
	(localize "STR_DOM_MISSIONSTRING_340") call FUNC(GlobalChat);
};