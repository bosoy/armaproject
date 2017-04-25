
private ["_vehicle", "_delay", "_startpos", "_startdir", "_type", "_startTime", "_bContinue"];
if (!isServer) exitWith{};

_vehicle = _this select 0;
_delay = _this select 1;
_initSQF = _this select 2;
_startpos = getpos _vehicle;
_startdir = getdir _vehicle;
_type = typeof _vehicle;

if (_initSQF==_initSQF) then
{
	[_vehicle] execVM _initSQF;
};

while {true} do
{
	waitUntil {!(({alive _x} count (crew _vehicle)) == 0) || ((getDammage _vehicle)>0.02)};
	if (({alive _x} count (crew _vehicle)) == 0) then
	{
		sleep _delay;
		deletevehicle _vehicle;
		sleep 0.5;
		_vehicle = _type createvehicle _startpos;
		_vehicle setpos _startpos;
		_vehicle setdir _startdir;
	}
	else
	{
		_bContinue=true;
		while {_bContinue} do
		{
			waitUntil {(({alive _x} count (crew _vehicle)) == 0)};
			_startTime=time;
			waitUntil {(time > (_startTime + _delay)) || !(({alive _x} count (crew _vehicle)) == 0)};
	
			if (time > (_startTime + _delay)) then
			{
				deletevehicle _vehicle;
				sleep 0.5;
				_vehicle = _type createvehicle _startpos;
				_vehicle setpos _startpos;
				_vehicle setdir _startdir;
				
				if (_initSQF==_initSQF) then
				{
					[_vehicle] execVM _initSQF;
				};
			
				_bContinue=false;
			};
		};
	};
};
