private ["_dir","_pos","_vehicle"];
if (isdedicated) exitWith {};

if (vehicle player != player) exitWith {hint "Not possible in a vehicle...";};

titleCut ["... Fixing head bug ...","black faded", 0];

_pos = position player;
_dir = direction player;
_vehicle = "UAZ_RU" createVehicleLocal _pos;
player moveincargo _vehicle;
waitUntil {vehicle player != player};
unassignVehicle player;
player action ["Eject",vehicle player];
waitUntil {vehicle player == player};
deleteVehicle _vehicle;
player setpos _pos;
player setDir _dir;

titleCut["", "BLACK in",2];

if (true) exitWith {};