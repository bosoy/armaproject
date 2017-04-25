#include "script_component.hpp"

#define __vehcfg configFile >> "cfgVehicles" >> typeof _unit
#define __maxranges getArray(__vehcfg >> "ace_tankfcs_maxranges")

private ["_v","_data","_index","_cur","_vel","_dirang","_curelevation","_curwindage","_dir","_spd","_ammo","_bullet","_upx","_upy","_upz","_x1","_y1","_z1","_k"];

_bullet = _this select 6;
if (isNull _bullet) exitwith {};

PARAMS_2(_unit,_weapon);
_ammo = _this select 4;

_data = _unit getvariable ["ace_tankfcs_fired", []];
_index = _data find _ammo;
if (_index < 0 ) exitwith {};

_cur = _data select (_index + 1);
_curwindage = _cur select 0;
_curelevation = _cur select 1;

_v = velocity _bullet;
_spd = _v call ACE_fnc_magnitude;
//if (_spd < 0.001) exitwith {};
_dir = if (getNumber(__vehcfg>>"ace_tankfcs_maxlead") == 0) then {
	[(_v select 0)/_spd,(_v select 1)/_spd,(_v select 2)/_spd]
} else {
	vectorDir _bullet
};

_dirang = [(_dir select 0) atan2 (_dir select 1), sqrt((_dir select 1)^2 + (_dir select 0)^2) atan2 - (_dir select 2)];
_dirang = [(_dirang select 0) + _curwindage, (_dirang select 1) + _curelevation];

_dir = [sin(_dirang select 1) * sin(_dirang select 0), sin(_dirang select 1) * cos(_dirang select 0), - cos(_dirang select 1)];
_vel = [(_dir select 0) * _spd, (_dir select 1) * _spd, (_dir select 2) * _spd];

//vectorup for properly drawn tracers
_x1 = _dir select 0;
_y1 = _dir select 1;
_z1 = _dir select 2;
_upz = sqrt (_x1^2 + _y1^2);
_k = -_z1/_upz;
_upx = _k*_x1;
_upy = _k*_y1;

//Applying changes
_bullet setVectorDirAndUp [_dir,[_upx,_upy,_upz]];
_bullet setVelocity _vel;

// sync mp
_bullet setPos getPos _bullet;
TRACE_2("New velocity",(velocity _bullet),(vectorDir _bullet));