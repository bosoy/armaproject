private ["_pos","_vehicle"];

if !(local player) exitWith {};

if (vehicle player != player) exitWith {
	player sideChat "Not possible in a vehicle...";
};

if (x_bike_created) exitWith {
	[playerSide,"HQ"] sideChat format ["Creating a %1 is only possible once after respawn...",x_immediate_transport];
};

_pos = position player;
[side player,"HQ"] sideChat format ["Creating %1, stand by...",x_immediate_transport];
sleep 3.123;
x_bike_created = true;
_pos = position player;
_vehicle = x_immediate_transport createVehicle _pos;
_vehicle setDir direction player;

player moveInDriver _vehicle;

[] spawn {
	waitUntil {!alive player};
	x_bike_created = false;
};

if (!alive _vehicle) exitWith {
	deleteVehicle _vehicle;
};

sleep 10.123;

[_vehicle] spawn {
	_vehicle = _this select 0;
	while {true} do {
		if (({alive _x} count (crew _vehicle)) == 0) exitWith {
			deleteVehicle _vehicle;
		};
		if (!alive _vehicle) exitWith {
			deleteVehicle _vehicle;
		};
		sleep 15.123;
	};
};