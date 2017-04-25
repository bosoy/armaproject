// enhanced version from killjoy
private ["_dir","_pos","_vehicle"];
if (isServer && !(local player)) exitWith {};

if (vehicle player != player) exitWith {hint "Not possible in a vehicle...";};

//if (isnil ("headbugvehicle")) exitWith {hintC "You have to set a headbugvehicle somewhere on the map\nand put headbugvehicle=this in the init line"};

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