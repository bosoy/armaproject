// by Xeno
#define THIS_FILE "x_update_dlg.sqf"
#include "x_setup.sqf"
private ["_pos", "_dir", "_trenchtype", "_trench"];

if (__pGetVar(GVAR(isinaction))) exitWith {
	GVAR(commandingMenuIniting) = false;
};

if ((player call FUNC(GetHeight)) > 5) exitWith {
	(localize "STR_DOM_MISSIONSTRING_241") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

if (!isNull __pGetVar(GVAR(trench))) exitWith {
	(localize "STR_DOM_MISSIONSTRING_587") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

_pos = player modeltoworld [0,1,0];
_pos set [2, 0];
_dir = direction player;

if (surfaceIsWater _pos) exitWith {
	(localize "STR_DOM_MISSIONSTRING_588") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

if (isOnRoad _pos) exitWith {
	(localize "STR_DOM_MISSIONSTRING_589") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

__pSetVar [QGVAR(isinaction), true];

(localize "STR_DOM_MISSIONSTRING_590") call FUNC(GlobalChat);

_trenchtype = 
#ifndef __CO__
	"Fort_EnvelopeSmall_EP1";
#else
	"Fort_EnvelopeSmall";
#endif

player playMove "AinvPknlMstpSlayWrflDnon_medic";
sleep 3;
waitUntil {animationState player != "AinvPknlMstpSlayWrflDnon_medic"};
GVAR(commandingMenuIniting) = false;
if (!alive player) exitWith {
	(localize "STR_DOM_MISSIONSTRING_591") call FUNC(GlobalChat);
	__pSetVar [QGVAR(isinaction), false];
};

_trench = createVehicle [_trenchtype, _pos, [], 0, "NONE"];
_trench setdir _dir;
_trench setPos _pos;

[QGVAR(p_o_a2), [GVAR(string_player), _trench]] call FUNC(NetCallEventCTS);
__pSetVar [QGVAR(trench), _trench];
__pSetVar [QGVAR(isinaction), false];
