#define THIS_FILE "SatellitenBild.sqf"
#include "x_setup.sqf"
private "_exitj";
if (isNil QUOTE(FUNC(satelittenposf))) then {__cppfln(FUNC(satelittenposf),scripts\SatellitenPos.sqf)};

_exitj = false;
if (GVAR(with_ranked)) then {
	if (score player < (GVAR(ranked_a) select 19)) then {
		(format [(localize "STR_DOM_MISSIONSTRING_76"), score player,GVAR(ranked_a) select 19]) call FUNC(HQChat);
		_exitj = true;
	} else {
		[QGVAR(pas), [player, (GVAR(ranked_a) select 19) * -1]] call FUNC(NetCallEventCTS);
	};
};
if (_exitj) exitWith {};

getpos Player spawn FUNC(satelittenposf);