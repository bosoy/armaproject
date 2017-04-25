// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfg configFile >> "CfgAmmo" >> _ammo
#define __wcfg configFile >> "CfgWeapons" >> _weapon
private ["_dir","_pos1", "_dirx ", "_diry ", "_dirz ", "_dirang", "_pos", "_initpos", "_ammo", "_bullet", "_vel"];

PARAMS_2(_unit,_weapon);
_ammo = _this select 4;
_pvehicle = vehicle player;
_bullet = _this select 6; // uses BIS Fired EH
if (isNull _bullet || {!isNumber (__cfg >> "ace_pelletcount")}) exitwith {};

_pos = getposASL _bullet;
_initpos = getpos _bullet;
_speed = (velocity _bullet) call ACE_fnc_magnitude;
if (_speed < 0.1) exitwith {};
_dir = velocity _bullet; //player weaponDirection _weapon;
_dirx = (_dir select 0)/_speed;
_diry = (_dir select 1)/_speed;
_dirz = (_dir select 2)/_speed;
_dirang = [_dirx atan2 _diry, sqrt(_diry^2 + _dirx^2) atan2 (-_dirz)];
//_pos1 = [(_pos select 0) + 0.05*_dirx,(_pos select 1) + 0.05*_diry,(_pos select 2) + 0.05*_dirz];

//muzzle mem point is ~ 45 cm inside model in BIS weapons
_pos1 = [(_pos select 0) + 0.5*_dirx,(_pos select 1) + 0.5*_diry,(_pos select 2) + 0.5*_dirz];

#define __pelletcount (getNumber (__cfg >> "ace_pelletcount"))
#define __dispersion (getNumber (__cfg >> "ace_disp"))

//player sidechat format ["%1 %2 %3 %4 %5 %6 %7 %8 %9", _ammo, _pvehicle, _bullet, _pos, _initpos, _speed, _dir, _pelletcount, __dispersion];

if (__pelletcount > 0) then {
	//player sidechat "pelletcount > 0";

	private ["_cspeed", "_pellet", "_sign", "_azimuth", "_elevation", "_dir", "_vel", "_x", "_j", "_i", "_y", "_y0", "_y1"];
	// points on sphere: [cos(theta)*sqrt(1-u*u),sin(theta)*sqrt(1-u*u),u)]; -r <= u <= r
	for "_pelletcounter" from 1 to __pelletcount do {
		// create solid sphere of pellets at end of muzzle
		if (_pelletcounter > 1) then {
			_pellet = _ammo createVehicle [_pos1 select 0, _pos1 select 1, 100];
			_pos = _pos1;
		} else {
			_pellet = _bullet;
		};
		_pellet setposASL _pos;
		// Gaussian distribution
		_x = 0;
		_sign = 0;
		while { true } do {
			_j = floor (random 16777216);
			_i = floor (random 128);
			_sign = floor (random 2);

			_x = _j * (ACE_WTAB select _i);
			_y = 0;
			if (_j < (ACE_KTAB select _i)) exitWith {};

			if (_i<127) then {
				_y0 = ACE_YTAB select _i;
				_y1 = ACE_YTAB select (_i+1);
				_y = _y1+(_y0-_y1)*(random 1);
			} else {
				_x = ACE_PARAM_R - ln(1.0-(random 1))/ACE_PARAM_R;
				_y = exp(-ACE_PARAM_R*(x-0.5*ACE_PARAM_R))*(random 1);
			};

			if (_y < exp(-0.5*_x^2)) exitWith {};
		};

		if (_sign == 1) then { _x = -_x };

		_radiusdisp = (_x*__dispersion)/2;
		_angledisp = random 180;

		_azimuth = (_dirang select 0) + ( _radiusdisp * cos(_angledisp) )*180/(1000*pi);
		_elevation = (_dirang select 1) + ( _radiusdisp * sin(_angledisp) )*180/(1000*pi); 		/// 1000*180/pi;
		_cspeed = _speed - random 8 + random 8;
		_dir = [sin(_elevation) * sin(_azimuth), sin(_elevation) * cos(_azimuth), - cos(_elevation)];
		_vel = [(_dir select 0) * _cspeed, (_dir select 1) * _cspeed, (_dir select 2) * _cspeed];

		_pellet setvelocity _vel;
	};
};
