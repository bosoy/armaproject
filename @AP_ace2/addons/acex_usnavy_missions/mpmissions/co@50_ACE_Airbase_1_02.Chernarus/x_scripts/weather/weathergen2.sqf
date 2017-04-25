private ["_counter","_foggy_helper","_loop","_rainy_helper","_rainy2_helper","_rainy3_helper","_randx","_randy","_rnddir","_world_center","_x","_x_fog_ran","_x_fog_start","_x_max","_x_start","_y","_y_fog_ran","_y_ran","_y_start"];

if (!isServer) exitWith {};

if (isNil "x_dynamic_weather" || !x_dynamic_weather) exitWith {};

if (isNil "x_dynamic_weather_fog") then {x_dynamic_weather_fog = false;};
if (isNil "x_dynamic_weather_sandstorm") then {x_dynamic_weather_sandstorm = false;};
if (x_dynamic_weather_sandstorm) then {x_dynamic_weather_fog = false;};

_world_center = getArray(configFile>>"CfgWorlds">>worldName>>"centerPosition");

_x = (_world_center select 0) * 2;
_y = (_world_center select 1) * 2;
_x_max = floor (_x / 1.2);
_x_start = floor (_x / 13.1);
_y_start = floor (_y / 5.87);
_y_ran = floor (_y / 2.21);

_x_fog_start = floor (_x / 2.275);
_x_fog_ran = floor (_x / 5);
_y_fog_ran = floor (_y / 4);

_rainy_helper = [floor (_x / 8), floor (_y / 2),0];
_rainy2_helper = [floor (_x / 3), floor (_y - (_y / 8)),0];
_rainy3_helper = [floor (_x / 2), floor (_y / 5),0];
x_weather_array = [_rainy_helper,_rainy2_helper,_rainy3_helper];
if (x_dynamic_weather_fog) then {
	_foggy_helper = [floor(_x_fog_start+(random _x_fog_ran)),  floor (_x_fog_start+(random _y_fog_ran)),0];
	x_weather_array = x_weather_array + [_foggy_helper];
};
publicVariable "x_weather_array";

_counter = 0;
for [{_loop=0}, {_loop<1}, {_loop=_loop}] do
{
	if ((_rainy_helper select 0) > _x_max) then
	{
		_randx = _x_start;
		_randy = _y_start+(random _y_ran);
		_rnddir = (random 359);
		_rainy_helper = [_randx,_randy,0];
	};
	if ((_rainy2_helper select 0) > _x_max) then
	{
		_randx = _x_start;
		_randy = _y_start+(random _y_ran);
		_rnddir = (random 359);
		_rainy2_helper = [_randx,_randy,0];
	};
	if ((_rainy3_helper select 0) > _x_max) then
	{
		_randx = _x_start;
		_randy = _y_start+(random _y_ran);
		_rnddir = (random 359);
		_rainy3_helper = [_randx,_randy,0];
	};
	_rainy_helper = [(_rainy_helper select 0)+10,(_rainy_helper select 1),0];
	_rainy2_helper = [(_rainy2_helper select 0)+10,(_rainy2_helper select 1),0];
	_rainy3_helper = [(_rainy3_helper select 0)+10,(_rainy3_helper select 1),0];
	x_weather_array = [_rainy_helper,_rainy2_helper,_rainy3_helper];
	if (x_dynamic_weather_fog) then {
		if(_counter == 0) then {
			_randx = _x_fog_start+(random _x_fog_ran);
			_randy = _x_fog_start+(random _y_fog_ran);
			_rnddir = (random 359);
			_foggy_helper = [_randx,_randy,0];
			_counter = 600;
		};
		x_weather_array = x_weather_array + [_foggy_helper];
		_counter = (_counter - 1);
	};
	publicVariable "x_weather_array";
	sleep 1.011;
};
