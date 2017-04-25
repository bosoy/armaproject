_player = player;

if (_player != vehicle _player) exitWith {hint "You can't repair in a vehicle."};

_scorePlr = score _player;
_vehicles = nearestObjects [_player, ["Land","Air","Ship"],10];
_vehicle = _vehicles select 1;
_vehicledamage = getDammage _vehicle;

if ((_vehicledamage) == 0) exitWith {hint "Vehicle is in perfect condition"};

{_x action ["Eject",vehicle _x]; sleep 1;} forEach (crew _vehicle);
disableUserInput true;
_effect = "SmokeShell" createVehicle getpos _vehicle;

_player playMove "AinvPknlMstpSlayWrflDnon_medic";
sleep 6;
_player playMove "AmovPercMstpSnonWnonDnon_AmovPercMstpSsurWnonDnon";
sleep 4;
_player playMove "AinvPknlMstpSlayWrflDnon_medic";

sleep 13;
_vehicle setDamage 0;
_vehicle setFuel 1;
{_x action ["Eject",vehicle _x]; sleep 1;} forEach (crew _vehicle);

deleteVehicle _effect;
disableUserInput false;
hint "Vehicle repaired";
