private ["_aid","_caller"];
_caller = _this select 1;
_aid = _this select 2;
_caller removeAction _aid;
if (!(local _caller)) exitWith {};
rep_array = [objectID2];
["rep_array",rep_array] call XSendNetStartScriptAll;
[objectID2] spawn x_repall;
disableUserInput true;
player playMove "AinvPknlMstpSlayWrflDnon_medic";
sleep 3.0;
WaitUntil {animationState player != "AinvPknlMstpSlayWrflDnon_medic"};
disableUserInput false;
if (true) exitWith {};
