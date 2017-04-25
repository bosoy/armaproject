private ["_crew","_delay","_disabled","_empty","_moved","_newveh","_startdir","_startpos","_type","_vehicle"];

if (!isServer) exitWith{};

_vehicle = _this select 0;
_delay = _this select 1;
_empty = true;
_disabled = false;
_startpos = getpos _vehicle;
_startdir = getdir _vehicle;
_type = typeof _vehicle;

while {true} do {
	sleep (_delay + random 15);

	_empty = (if (({alive _x} count (crew _vehicle)) > 0) then {false} else {true});

	_disabled = (if (damage _vehicle > 0.9) then {true} else {false});

	if ((_disabled && _empty) || (!(alive _vehicle) && _empty)) exitWith {
		deletevehicle _vehicle;
		sleep 0.5;
		_newveh = _type createvehicle _startpos;
		_newveh setpos _startpos;
		_newveh setdir _startdir;

		[_newveh, _delay] spawn x_vehirespawn2a;
	};
};