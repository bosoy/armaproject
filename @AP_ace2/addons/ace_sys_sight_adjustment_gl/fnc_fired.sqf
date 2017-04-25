#include "script_component.hpp"
if (player != (_this select 0)) exitwith {};
if ((_this select 1) != primaryweapon player) exitwith { GVAR(running) = false };
if ((_this select 4) isKindOf "BulletBase") exitwith { GVAR(running) = false };
if ((_this select 4) isKindOf "SmokeShell") exitwith { GVAR(running) = false }; // Disable smokeshell adjustment
if (GVAR(running)) exitwith {};

if (GVAR(sa_active)) then {
	private ["_bullet","_el","_vel","_dirang","_dir","_spd","_upx","_upy","_upz","_x1","_y1","_z1","_k"];

	_el = player getVariable "ace_sa_gl_deg";
	_bullet = _this select 6;
	_spd = (velocity _bullet) call ACE_fnc_magnitude;
	_dir = vectorDir _bullet;

	_dirang = [(_dir select 0) atan2 (_dir select 1), sqrt((_dir select 1)^2 + (_dir select 0)^2) atan2 - (_dir select 2)];
	TRACE_2("Initial azimuth and elevation",(_dirang select 0),(_dirang select 1));
	_dirang = [(_dirang select 0), (_dirang select 1) + _el];
	TRACE_2("Result azimuth and elevation",(_dirang select 0),(_dirang select 1));

	_dir = [sin(_dirang select 1) * sin(_dirang select 0), sin(_dirang select 1) * cos(_dirang select 0), - cos(_dirang select 1)];
	_vel = [(_dir select 0) * _spd, (_dir select 1) * _spd, (_dir select 2) * _spd];

	//finding proper VectorUp so grenades are departing nose forward
	_x1 = _dir select 0;
	_y1 = _dir select 1;
	_z1 = _dir select 2;
	_k = -_z1/sqrt(_x1^2 + _y1^2);
	_upx = _k*_x1;
	_upy = _k*_y1;
	_upz = sqrt (_x1^2 + _y1^2);
	
	//Applying changes
	_bullet setVelocity _vel;
	_bullet setVectorDirAndUp [_dir,[_upx,_upy,_upz]];
};
