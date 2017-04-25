private ["_shot", "_ran", "_marker", "_pos"];

if (!isServer) exitwith {};

sleep 10;

xartix = 0;
publicVariable "xartix";

sleep 2;

_shot = [];

while {count _shot < 24} do {
	_ran = floor random 24;
	while {_ran in _shot} do {
		_ran = floor random 24;
	};
	_shot set [count _shot, _ran];
	_marker = format ["bomb%1", _ran + 1];
	_pos = markerpos _marker;
	"Sh_105_HE" createvehicle _pos;
	sleep 0.8 + random 2;
};

_shot = nil;

if (true) exitwith {};