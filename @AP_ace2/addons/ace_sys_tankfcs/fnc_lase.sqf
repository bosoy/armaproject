//lase for range, update display and set elevation/lead

#include "script_component.hpp"

#define __vehcfg configFile >> "cfgVehicles" >> typeof _veh
#define __magcfg configFile >> "cfgMagazines" >> _mag
#define __maxrng getNumber(__vehcfg >> "ace_tankfcs_maxlrfrange")
#define __minrng getNumber(__vehcfg >> "ace_tankfcs_minlrfrange")
#define __maxranges getArray(__vehcfg >> "ace_tankfcs_maxranges")
#define __acc getNumber(__vehcfg >> "ace_tankfcs_lrfaccuracy")
#define __cooltime getNumber(__vehcfg >> "ace_tankfcs_lrfcooldowntime")

if (cameraView != "GUNNER") exitwith {};

private ["_offset","_ammo","_magz","_rd","_maxrng","_minrng","_lrf","_range","_veh","_wpn"];

_veh = vehicle player;

if (time - (_veh getvariable ["ace_tankfcs_lastlasetime", 0]) < __cooltime) exitwith {};

_wpn = (weapons _veh) select 0;
_rd = false;
_lrf = [_veh,_wpn] call FUNC(findrange);
_range = _lrf select 0;
_veh setvariable ["ace_tankfcs_lastlasetime", time];

_mag = currentmagazine _veh;
_magz = __maxranges;
_maxrng = __maxrng;
_minrng = __minrng;

// flash if range outside of LRF limits
if (_range > _maxrng) then {
	//diag_log format["%3: ACE Tank FCS: measured range too high (%1) fps %2 veh %4 mag %5",_range,diag_fps,time,typeof _veh,_mag];
	[0,_maxrng,_minrng] spawn FUNC(rangedisplay);
	_rd = true;
};
if (_range < _minrng) then {
	//diag_log format["%3: ACE Tank FCS: measured range too low (%1) fps %2 veh %4 mag %5",_range,diag_fps,time,typeof _veh,_mag];
	[0,_maxrng,_minrng] spawn FUNC(rangedisplay);
	_rd = true;
	_range = _minrng;
};
if !(_rd) then {
	_range = _range + random (__acc) - random (__acc);
	if (_mag in _magz) then {
		_maxrng = _magz select ((_magz find _mag)+1);
		_rd = true;
	} else {
		//check max missile control range if it's selected, flash if exceeded
		_ammo = getText(__magcfg>>"ammo");
		if (_ammo isKindOf "MissileBase") then {
			_maxrng = getNumber(configFile>>"cfgAmmo">>_ammo>>"maxcontrolrange");
		};
	};
	[_range,_maxrng,_minrng] spawn FUNC(rangedisplay);
	if (_range > _maxrng && _rd) then {_range = _maxrng};
};

// for low velocity projectiles, account for vert angle to target
if (_mag in _magz)  then {
	if (getNumber(__magcfg >> "initspeed") <= 300) then {
		_range = _range*cos abs(_lrf select 4);
	};
};

[_veh,_range,_magz,_wpn,false] call FUNC(setsolution);
