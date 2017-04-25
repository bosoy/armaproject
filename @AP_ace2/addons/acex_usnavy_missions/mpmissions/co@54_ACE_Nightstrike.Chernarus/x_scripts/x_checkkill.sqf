// by Xeno
private ["_killed"];

_killed = _this select 0;

sleep  90 + 5 + (random 15);
deleteVehicle _killed;

if (true) exitWith {};
