private ["_delay","_disabled","_empty","_ifdamage","_newveh","_startdir","_startpos","_type","_vehicle"];
if (!isServer) exitWith{};

_vehicle = _this select 0;
_delay = _this select 1;
_ifdamage = _this select 2;
_empty = true;
_disabled = false;
_startpos = getpos _vehicle;
_startdir = getdir _vehicle;
_type = typeof _vehicle;

if (typeName x_immediate_transport == "ARRAY") then {
	_st = "";
	for "_i" from 0 to ((count x_immediate_transport) - 1) do {
		_st = _st + format ["this addAction ['Create %1','x_bike2.sqf','%1',-1,false,false];", x_immediate_transport select _i];
	};
	_vehicle setVehicleInit _st;
} else {
	_vehicle setVehicleInit "this addAction ['Create Vehicle','x_bike.sqf']";
};
processInitCommands;

_vehicle lock true;

while {true} do {
	sleep _delay + random 15;

	_empty = (({alive _x} count (crew _vehicle)) == 0);

	_disabled = false;
	if (_empty) then {
		if (!_ifdamage) then {
			if (_empty && _vehicle distance _startpos > 10) then {
				_disabled = true;
			};
		} else {
			if (damage _vehicle > 0.86) then {_disabled = true;};
		};
	};

	if ((_disabled && _empty) || (!(alive _vehicle) && _empty)) then {
		sleep 0.1;
		deletevehicle _vehicle;
		sleep 0.5;
		_vehicle = objNull;
		_vehicle = _type createvehicle _startpos;
		_vehicle setpos _startpos;
		_vehicle setdir _startdir;
		_vehicle lock true;
		if (typeName x_immediate_transport == "ARRAY") then {
			_st = "";
			for "_i" from 0 to ((count x_immediate_transport) - 1) do {
				_st = _st + format ["this addAction ['Create %1','x_bike2.sqf','%1',-1,false,false];", x_immediate_transport select _i];
			};
			_vehicle setVehicleInit _st;
		} else {
			_vehicle setVehicleInit "this addAction ['Create Vehicle','x_bike.sqf']";
		};
		processInitCommands;
	};
};
