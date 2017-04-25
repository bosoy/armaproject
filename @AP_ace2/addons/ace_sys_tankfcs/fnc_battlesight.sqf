// set battle sight mode

#include "script_component.hpp"

#define __vehcfg configFile >> "cfgVehicles" >> typeof _veh
#define __magcfg configFile >> "cfgMagazines" >> _mag
#define __maxrng getNumber(__vehcfg >> "ace_tankfcs_maxlrfrange")
#define __minrng getNumber(__vehcfg >> "ace_tankfcs_minlrfrange")
#define __maxranges getArray(__vehcfg >> "ace_tankfcs_maxranges")
#define __acc getNumber(__vehcfg >> "ace_tankfcs_lrfaccuracy")

if (cameraView != "GUNNER") exitwith {};

private ["_ammo","_magz","_rd","_maxrng","_minrng","_range","_veh","_wpn"];

_veh = vehicle player;
_wpn = (weapons _veh) select 0;
_range = getNumber(__vehcfg >> "ace_tankfcs_battlesight");

_mag = currentmagazine _veh;
_magz = __maxranges;
_maxrng = __maxrng;
_minrng = __minrng;

if (_mag in _magz) then {
	_maxrng = _magz select ((_magz find _mag)+1);
};
[_range,_maxrng,_minrng] spawn FUNC(rangedisplay);
if (_range > _maxrng) then {_range = _maxrng};

[_veh,_range,_magz,_wpn,true] call FUNC(setsolution);