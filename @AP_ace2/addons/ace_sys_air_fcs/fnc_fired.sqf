// Tank FCS by q1184
// Fired EH
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_v","_data","_index","_cur","_vel","_dirang","_curelevation","_curwindage","_dir","_spd","_ammo","_bullet","_upx","_upy","_upz","_x1","_y1","_z1","_k"];

PARAMS_7(_unit,_weapon,_bla,_bla,_ammo,_magazine,_bullet);
if (isNull _bullet) exitwith {TRACE_2("Fired EH did not bring bullet",diag_fps,diag_fpsMin)};

_data = _unit getVariable QGVAR(fired);
_index = _data find _ammo;
if (_index < 0 ) exitwith {};

_cur = _data select (_index + 1);
_curwindage = _cur select 0;
_curelevation = _cur select 1;

_v = velocity _bullet;
_spd = _v call ACE_fnc_magnitude; // No shortcuts anymore; this actually works ;-)
TRACE_2("",_v,_spd);
//if (_spd < 0.001) exitwith {};
_dir = vectorDir _bullet;
//_dir = [(_v select 0)/_spd,(_v select 1)/_spd,(_v select 2)/_spd];

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
_bullet setPosASL getPosASL _bullet;

TRACE_2("New velocity applied",(velocity _bullet),(vectorDir _bullet));
