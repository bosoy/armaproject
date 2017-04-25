
private ["_vehicle", "_delay", "_startpos", "_startdir", "_type", "_startTime"];
if (!isServer) exitWith{};

_vehicle = _this select 0;
_delay = _this select 1;
_startpos = getpos _vehicle;
_startdir = getdir _vehicle;
_type = typeof _vehicle;



while {true} do
{
	waitUntil {!(alive _vehicle)};
	
	sleep _delay;
	
	deletevehicle _vehicle;
	sleep 0.5;
	_vehicle = _type createvehicle _startpos;
	_vehicle setpos _startpos;
	_vehicle setdir _startdir;
};
