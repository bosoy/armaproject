#include "script_component.hpp"
private ["_p","_playergunner","_params","_vel","_dirang","_curelevation","_curwindage","_dir","_unit","_weapon","_spd","_ammo","_bullet","_upx","_upy","_upz","_x1","_y1","_z1","_k"];

_unit = _this select 0;
_weapon = _this select 1;
_ammo = _this select 4;
_params = _unit getVariable "ace_sys_sight_adjustment_params";
if ((typeName _params) != "ARRAY") exitwith {};
if (_weapon != _params select 2) exitwith {};
if (_params select 4) exitwith {};	//TE active
if !(_params select 7) exitwith {}; //no sa
//is the shooter a player

_p = _unit turretUnit (_params select 3);
if !(isPlayer _p) exitwith {};
//if (_ammo iskindOf "GrenadeBase" && player != _p) exitwith {};
_bullet = _this select 6; // Uses BIS Fired EH
if (isNull _bullet) exitwith {};

_curwindage = _params select 1;
_curelevation = _params select 0;
_spd = (velocity _bullet) call ACE_fnc_magnitude;
_dir = vectorDir _bullet;
_dirang = [(_dir select 0) atan2 (_dir select 1), sqrt((_dir select 1)^2 + (_dir select 0)^2) atan2 - (_dir select 2)];
_dirang = [(_dirang select 0) + _curwindage, (_dirang select 1) + _curelevation];
_dir = [sin(_dirang select 1) * sin(_dirang select 0), sin(_dirang select 1) * cos(_dirang select 0), - cos(_dirang select 1)];
_vel = [(_dir select 0) * _spd, (_dir select 1) * _spd, (_dir select 2) * _spd];

//if !(bullet isKindof "bulletBase") then
//{
	//finding proper VectorUp so grenades are departing nose forward, also used for bullets now so tracers draw properly
	_x1 = _dir select 0;
	_y1 = _dir select 1;
	_z1 = _dir select 2;
	_upz = sqrt (_x1^2 + _y1^2);
	_k = -_z1/_upz;
	_upx = _k*_x1;
	_upy = _k*_y1;
	_bullet setVectorDirAndUp [_dir,[_upx,_upy,_upz]];
//};
//Applying changes
_bullet setVelocity _vel;

// sync mp
//_bullet setPos getPos _bullet;