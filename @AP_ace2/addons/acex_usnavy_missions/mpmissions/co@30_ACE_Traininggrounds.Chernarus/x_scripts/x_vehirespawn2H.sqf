// by Xeno
private ["_vehicle", "_delay", "_startpos", "_startdir", "_type", "_disabled", "_empty"];
if (!isServer) exitWith{};

_vehicle = _this select 0;
_delay = _this select 1;
_startpos = getpos _vehicle;
_startdir = getdir _vehicle;
_type = typeof _vehicle;

_vehicle setVehicleInit "this addeventhandler [""getin"", {_this execVM ""x_scripts\x_checkhelipilot.sqf"";}]";
processInitCommands;

waitUntil {!isNil "x_chopprespawn"};
if (!x_chopprespawn) exitWith {};

while {true} do {
	sleep (_delay + random 15);
	if (({alive _x} count (crew _vehicle)) == 0) then {
		_disabled = (if (damage _vehicle > 0.9) then {true} else {false});
		if (_disabled || !(alive _vehicle)) then {
			clearVehicleInit _vehicle;
			deletevehicle _vehicle;
			sleep 0.5;
			_vehicle = _type createvehicle _startpos;
			_vehicle setpos _startpos;
			_vehicle setdir _startdir;
			_vehicle setVehicleInit "this addeventhandler [""getin"", {_this execVM ""x_scripts\x_checkhelipilot.sqf"";}]";
			processInitCommands;
		};
	};
};
