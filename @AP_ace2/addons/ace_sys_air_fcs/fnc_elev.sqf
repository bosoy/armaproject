#include "script_component.hpp"

#define __magcfg configFile >> "cfgMagazines" >> _mag

PARAMS_2(_mag,_range);
private ["_index","_droplist","_timelist","_drop0","_time0","_drop1","_time1","_drop","_flighttime","_k","_elev"];

if !(isArray(__magcfg >> "ace_air_fcs_drop")) exitwith {[0,0]};

_droplist = getArray (__magcfg >> "ace_air_fcs_drop");
_timelist = getArray (__magcfg >> "ace_air_fcs_time");

_index = floor(_range/100);

if (_index >= (count _droplist) - 1) then {
	_index = (count _droplist) - 1;
	_range = _index*100;
	_drop = _droplist select _index;
	_flighttime = _timelist select _index;
} else {
	// Interpolate drop and flight time
	_drop0 = _droplist select _index;
	_time0 = _timelist select _index;
	_drop1 = _droplist select (_index + 1);
	_time1 = _timelist select (_index + 1);

	_k = (_range - _index*100) / 100;
	_drop = _drop0 + (_drop1 - _drop0)*_k;
	_flighttime = _time0 + (_time1 - _time0)*_k;
};
_elev = _drop atan2 _range;

[_elev,_flighttime]
