#define THIS_FILE "x_repengineer_old.sqf"
#include "x_setup.sqf"
private ["_aid","_caller"];
_caller = _this select 1;
_aid = _this select 2;
_caller removeAction _aid;
if !(local _caller) exitWith {};
[QGVAR(rep_ar), GVAR(objectID2)] call FUNC(NetCallEvent);
disableUserInput true;
player playMove "AinvPknlMstpSlayWrflDnon_medic";
sleep 3.0;
waitUntil {animationState player != "AinvPknlMstpSlayWrflDnon_medic"};
disableUserInput false;