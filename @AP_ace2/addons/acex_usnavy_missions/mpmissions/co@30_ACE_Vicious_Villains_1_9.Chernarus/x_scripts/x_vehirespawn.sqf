// by Xeno
private ["_delay","_disabled","_moved","_newveh","_startdir","_startpos","_type","_vehicle"];
if (!isServer) exitWith{};

_vehicle = _this select 0;
_delay = _this select 1;
_moved = false;
_startpos = getpos _vehicle;
_startdir = getdir _vehicle;
_type = typeof _vehicle;

while {true} do {
	sleep (_delay + random 15);

	_moved = (if (_vehicle distance _startpos > 5) then {true} else {false});

	_empty = (if (({alive _x} count (crew _vehicle)) > 0) then {false} else {true});

	_disabled = (if (damage _vehicle > 0) then {true} else {false});

	if ((_disabled && _empty) || (_moved && _empty) || (_empty && !(alive _vehicle))) then {
		deletevehicle _vehicle;
		_vehicle = objNull;
		sleep 0.5;
		_vehicle = _type createvehicle _startpos;
		_vehicle setpos _startpos;
		_vehicle setdir _startdir;
	};
};
