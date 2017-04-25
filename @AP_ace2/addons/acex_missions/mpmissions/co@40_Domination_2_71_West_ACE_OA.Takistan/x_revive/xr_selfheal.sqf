// by Xeno
// #define __DEBUG__
#define THIS_FILE "x_revive\xr_selfheal.sqf"

#include "xr_macros.sqf"

private ["_endtime"];

__pSetVar [QGVARXR(pisinaction), true];

_ma = "ainvpknlmstpslaywrfldnon_medic";
player playMove _ma;
_endtime = time + 12;
waitUntil {animationState player == _ma || !alive player || __pGetVar(GVARXR(pluncon)) || time > _endtime};
waitUntil {animationState player != _ma || !alive player || __pGetVar(GVARXR(pluncon)) || time > _endtime};

if (alive player && {!__pGetVar(GVARXR(pluncon))}) then {
	player setDamage 0;
	__pSetVar [QGVARXR(overall), 0];
	__pSetVar [QGVARXR(head_hit), 0];
	__pSetVar [QGVARXR(body), 0];
	__pSetVar [QGVARXR(hands), 0];
	__pSetVar [QGVARXR(legs), 0];
	__pSetVar [QGVARXR(numheals), __pGetVar(GVARXR(numheals)) - 1];
};

__pSetVar [QGVARXR(pisinaction), false];
