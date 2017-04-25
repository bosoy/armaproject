private ["_vehicle", "_delay", "_startpos", "_startdir", "_type", "_marker", "_empty", "_disabled"];

if (!isServer) exitWith{};

_vehicle = _this select 0;
_delay = _this select 1;
_startpos = getpos _vehicle;
_startdir = getdir _vehicle;
_type = typeof _vehicle;

[_vehicle, "Mobile HQ"] spawn {
	private ["_vehicle","_marker"];
	_vehicle = _this select 0;
	_marker = _this select 1;
	while {alive _vehicle} do {
		_marker setmarkerpos (_vehicle modelToWorld [0,-5,0]);
		sleep 2.2;
	};
};

x_mobile_resp = _vehicle;
publicVariable "x_mobile_resp";

//_vehicle setVehicleInit "this addEventhandler [""getin"", {_this execVM ""mobilerrespawn\x_checkdriver.sqf""}];this addEventhandler [""getout"", {_this execVM ""mobilerrespawn\x_checkdriverout.sqf""}];";
[_vehicle] execVM "mobilerrespawn\x_mrweaponcargo.sqf";

while {true} do {
	sleep (_delay + random 15);

	_empty = (({alive _x} count crew _vehicle) == 0);
	_disabled = (damage _vehicle > 0.9 || !(alive _vehicle));

	if (_disabled && _empty) then {
		deletevehicle _vehicle;
		sleep 0.5;
		_vehicle = objNull;
		_vehicle = _type createvehicle _startpos;
		_vehicle setpos _startpos;
		_vehicle setdir _startdir;
		x_mobile_resp = _vehicle;
		publicVariable "x_mobile_resp";

		[_vehicle, "Mobile HQ"] spawn {
			private ["_vehicle","_marker"];
			_vehicle = _this select 0;
			_marker = _this select 1;
			while {alive _vehicle} do {
				_marker setmarkerpos [(getpos _vehicle select 0) + 5, (getpos _vehicle select 1) + 5];
				sleep 2.2;
			};
		};

		//_vehicle setVehicleInit "this addEventhandler [""getin"", {_this execVM ""mobilerrespawn\x_checkdriver.sqf""}];this addEventhandler [""getout"", {_this execVM ""mobilerrespawn\x_checkdriverout.sqf""}];";
		[_vehicle] execVM "mobilerrespawn\x_mrweaponcargo.sqf";
	};
};