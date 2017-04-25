// by Xeno
#define THIS_FILE "x_removefarp.sqf"
#include "x_setup.sqf"
private "_farp";

_farp = __pGetVar(GVAR(farp_obj));
if (isNil "_farp") exitWith {};

player playMove "AinvPknlMstpSlayWrflDnon_medic";
sleep 3;
waitUntil {animationState player != "AinvPknlMstpSlayWrflDnon_medic"};
if (!alive player) exitWith {(localize "STR_DOM_MISSIONSTRING_315") call FUNC(GlobalChat)};

_farpsar = __XJIPGetVar(GVAR(farps)); 
_farpsar = _farpsar - [_farp];
__XJIPSetVar [QGVAR(farps), _farpsar, true];

deleteVehicle _farp;
__pSetVar [QGVAR(farp_obj), objNull];

(localize "STR_DOM_MISSIONSTRING_316") call FUNC(GlobalChat);
__pSetVar [QGVAR(farp_pos), []];
_m_name = "FARP " + GVAR(string_player);
[QGVAR(p_o_r), [GVAR(string_player),_m_name]] call FUNC(NetCallEvent);