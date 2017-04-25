#define MAX_SPAWN_DAMAGE 0.001
private ["_vehicle", "_delay", "_initSQF", "_startpos", "_startdir", "_type", "_startTime", "_damageEnabled"];
if (!isServer) exitWith{};

_vehicle = _this select 0;
_delay = _this select 1;

_maxLevel = 5;
_levelIndex = 1;
if (!(_vehicle isKindOf "LandVehicle")) then
{
	_levelIndex = 2;
};
if (!isNil "paramsArray") then
{
	_maxLevel = paramsArray select _levelIndex;
};

_level = 0;
if (count _this > 2) then
{
	_level = _this select 2;
};

if (_level>_maxLevel) exitWith {deleteVehicle _vehicle;};

_initSQF = "";
if (count _this > 3) then
{
	_initSQF = _this select 3;
	[_vehicle] execVM _initSQF;
};
_startpos = getposASL _vehicle;
_startdir = getdir _vehicle;
_type = typeof _vehicle;
_startTime = - _Delay;
_damageEnabled=0;

waitUntil {!(({alive _x} count (crew _vehicle)) == 0) || ((getDammage _vehicle)>MAX_SPAWN_DAMAGE)};


while {true} do
{
	if (!(({alive _x} count (crew _vehicle)) == 0) || (_damageEnabled==1)) then {
		_damageEnabled=1;
		waitUntil {(({alive _x} count (crew _vehicle)) == 0)};	
		_startTime=time;
		waitUntil {(time > (_startTime + _delay)) || !(({alive _x} count (crew _vehicle)) == 0)};
	};
		
	if (time > (_startTime + _delay) || (_damageEnabled==0)) then
	{
		deletevehicle _vehicle;
		sleep 0.5;
		_vehicle = _type createvehicle _startpos;
		_vehicle setposASL _startpos;
		_vehicle setdir _startdir;
		_damageEnabled=0;
		if (_initSQF!="") then
		{
			[_vehicle] execVM _initSQF;
		};
		
		waitUntil {!(({alive _x} count (crew _vehicle)) == 0) || ((getDammage _vehicle)>MAX_SPAWN_DAMAGE)};
	};
};
