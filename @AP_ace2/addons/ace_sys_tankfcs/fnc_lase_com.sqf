// simple LRF for commander

#include "script_component.hpp"

#define __vehcfg configFile >> "cfgVehicles" >> typeof _veh
#define __maxrng getNumber(__vehcfg >> "ace_tankfcs_maxlrfrange")
#define __minrng getNumber(__vehcfg >> "ace_tankfcs_minlrfrange")
#define __acc getNumber(__vehcfg >> "ace_tankfcs_lrfaccuracy")
#define __cooltime getNumber(__vehcfg >> "ace_tankfcs_lrfcooldowntime")

if (cameraView != "GUNNER") exitwith {};

private ["_maxrng","_minrng","_lrf","_range","_veh","_wpn"];

_veh = vehicle player;

if (time - (_veh getvariable ["ace_tankfcs_lastlasetime", 0]) < __cooltime) exitwith {};

_wpn = (weapons _veh) select 0;
_rd = false;
_lrf = [_veh,_wpn] call FUNC(findrange);
_range = _lrf select 0;
_range = _range + random (__acc) - random (__acc);
_veh setvariable ["ace_tankfcs_lastlasetime", time];

_maxrng = __maxrng;
_minrng = __minrng;

// flash if range outside of LRF limits
switch (true) do {
	case (_range > _maxrng): {
		[0,_maxrng,_minrng] spawn FUNC(rangedisplay);
	};
	case (_range < _minrng): {
		[0,_maxrng,_minrng] spawn FUNC(rangedisplay);
	};
	default {
		[_range,_maxrng,_minrng] spawn FUNC(rangedisplay);
	};
};