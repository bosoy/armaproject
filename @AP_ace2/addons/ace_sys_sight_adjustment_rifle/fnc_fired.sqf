#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

//if !(ACE_SYS_SA_RFL_ENABLED) exitwith {};
//if ((_this select 1) != ACE_SYS_SA_RFL_CURWEAPON) exitwith {};
//if ((_this select 0) != player) exitwith {};
//if !(isNull GMJ_SA) exitwith {};
//player sidechat format ["sa feh %1",_this];
private ["_vel","_dirang","_curelevation","_curwindage","_dir","_spd","_ammo","_bullet","_upx","_upy","_upz","_x1","_y1","_z1","_k"];

_bullet = _this select 6; // uses BIS fired EH
if (isNull _bullet) exitwith {};

PARAMS_2(_unit,_weapon);
_ammo = _this select 4;

_spd = (velocity _bullet) call ACE_fnc_magnitude;
_dir = vectorDir _bullet;

_curwindage = _unit getvariable "ace_sa_rfl_wnd";
_curelevation = _unit getvariable "ace_sa_rfl_el";

//player sidechat format ["el %1 w %2",_curelevation,_curwindage];

// dirang = [azimuth,elevation] (degrees)
_dirang = [(_dir select 0) atan2 (_dir select 1), sqrt((_dir select 1)^2 + (_dir select 0)^2) atan2 - (_dir select 2)];
TRACE_3("",_weapon,(_dirang select 0),(_dirang select 1));

_dirang = [(_dirang select 0) + _curwindage, (_dirang select 1) + _curelevation];
TRACE_3("",_weapon,(_dirang select 0),(_dirang select 1));

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
TRACE_2("",(velocity _bullet),(vectorDir _bullet));
