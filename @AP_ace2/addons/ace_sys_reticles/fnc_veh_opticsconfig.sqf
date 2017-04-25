//return min and max fov for optics and (if present) back-up sight

#include "script_component.hpp"
#define __vcfg configfile>>"cfgvehicles">>typeof _veh

private ["_wpn","_veh","_cfg","_res","_t","_turret","_pos"];
_veh = _this select 0;
_wpn = _this select 1;
_res = [];
_pos = assignedvehiclerole player;
_turret = [];
//if (_pos select 0 == "Turret") then {
	_turret = _pos select 1;
	//if (count _turret == 0) exitwith {};
	//if !(_wpn in (_veh weaponsturret _turret)) exitwith {};
	_t = [_veh,_turret] call CBA_fnc_getTurret;
	if (isClass(_t>>"opticsin")) then 
	{
		_t = _t>>"opticsIn";
		for "_i" from 0 to (count _t - 1) do
		{
			if (isClass (_t select _i)) then
			{
				_res set [count _res,[getNumber((_t select _i)>>"maxfov"),getNumber((_t select _i)>>"minfov")]];
			};
		};
	} else 
	{
		if (isClass(_t>>"viewoptics")) then 
		{
			_res set [count _res,[getNumber(_t>>"viewoptics">>"maxfov"),getNumber(_t>>"viewoptics">>"minfov")]];
		};
	};
//};

_res