// by Xeno
#define THIS_FILE "x_removemash.sqf"
#include "x_setup.sqf"
private "_m_name";

if (isNil {__pGetVar(medic_tent)}) exitWith {};
player playMove "AinvPknlMstpSlayWrflDnon_medic";
sleep 3;
waitUntil {animationState player != "AinvPknlMstpSlayWrflDnon_medic"};
if (!alive player) exitWith {(localize "STR_DOM_MISSIONSTRING_317") call FUNC(GlobalChat)};

deleteVehicle __pGetVar(medic_tent);
__pSetVar ["medic_tent", objNull];

(localize "STR_DOM_MISSIONSTRING_318") call FUNC(GlobalChat);
__pSetVar [QGVAR(medtent), []];
_m_name = "Mash " + GVAR(string_player);
[QGVAR(p_o_r), [GVAR(string_player),_m_name]] call FUNC(NetCallEvent);
