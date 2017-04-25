//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_dist","_posx","_posy","_posz","_pvehicle","_ammo","_bullet","_reloadtime","_dispersion","_speed","_pos","_dir","_dirx","_diry","_dirz","_dirang","_pelletcount"];

PARAMS_2(_unit,_weapon);
_pvehicle = vehicle _unit;
_ammo = _this select 4;
_bullet = _this select 6;
_pos = position _bullet;
_speed = (speed _bullet) / 3.6;

_dist = _pvehicle distance _bullet;
_dispersion = getNumber (configFile >> "CfgAmmo" >> _ammo >> "ACE_DISP");
_dir = _pvehicle weaponDirection _weapon;

_dirx = _dir select 0;
_diry = _dir select 1;
_dirz = _dir select 2;

_dirang = [_dirx atan2 _diry, sqrt(_diry*_diry + _dirx*_dirx) atan2 (-_dirz)];

TRACE_2("",_dist, _speed);

_pelletcount = getNumber (configFile >> "cfgAmmo" >> _ammo >> "ACE_PELLETCOUNT");

if (_pelletcount > 1) then { // canister shot
	private ["_azimuth","_elevation","_dir","_vel","_barrelradius","_wdir","_wx","_wy","_wz"];
	_speed = 1410;
	_azimuth = (_dirang select 0);
	_elevation = (_dirang select 1);
	_dir = [sin(_elevation) * sin(_azimuth), sin(_elevation) * cos(_azimuth), - cos(_elevation)];
	_vel = [(_dir select 0) * _speed, (_dir select 1) * _speed, (_dir select 2) * _speed];

	_barrelradius = 0.060; // m
	_wdir = _pvehicle weaponDirection _weapon;
	_wx = _wdir select 0;
	_wy = _wdir select 1;
	_wz = _wdir select 2;
	// points on sphere: [cos(theta)*sqrt(1-u*u),sin(theta)*sqrt(1-u*u),u)]; -r <= u <= r
	_pelletcounter = 1;
	while {_pelletcounter <= _pelletcount} do {
		_pelletratio = _pelletcounter/_pelletcount;
		_randomangle = random 360;
		_randomradius = (_pelletratio * _barrelradius) * (1-2*floor(random 2));

		// create solid sphere of pellets at end of muzzle
		_pellet = "ACE_M1028_Pellet" createVehicle [(_pos select 0) + cos(_randomangle)*sqrt(1-_randomradius*_randomradius) + 1.4*_wx,
						(_pos select 1) + sin(_randomangle)*sqrt(1-_randomradius*_randomradius) + 1.4*_wy,
						(_pos select 2) + _randomradius + 1.4*_wz];


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

			if (_y < exp(-0.5*_x*_x)) exitWith {};
		};

		if (_sign == 1) then { _x = -_x };

		_radiusdisp = _x*_dispersion/2;
		_angledisp = random 180;

		_azimuth = (_dirang select 0) + ( _radiusdisp * cos(_angledisp) ) / 1000*180/pi;
		_elevation = (_dirang select 1) + ( _radiusdisp * sin(_angledisp) ) / 1000*180/pi;


		_dir = [sin(_elevation) * sin(_azimuth), sin(_elevation) * cos(_azimuth), - cos(_elevation)];
		_vel = [(_dir select 0) * _speed, (_dir select 1) * _speed, (_dir select 2) * _speed];


		_pellet setVelocity _vel;
		_pelletcounter = _pelletcounter + 1;
	};
}
else {
	private ["_sign","_x","_y","_i","_j","_y0","_y1","_radiusdisp","_angledisp","_azimuth","_elevation","_dir","_vel"];

	_x = 0;
	_sign = 1;
	while { true } do { // generate normally-distributed random number
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

		if (_y < exp(-0.5*_x*_x)) exitWith {};
	};

	if (_sign == 0) then { _x = -_x };

	_radiusdisp = _x*_dispersion/2;
	_angledisp = random 180;

	_azimuth = (_dirang select 0) + ( _radiusdisp * cos(_angledisp) ) / 1000*180/pi;
	_elevation = (_dirang select 1) + ( _radiusdisp * sin(_angledisp) ) / 1000*180/pi;

	_dir = [sin(_elevation) * sin(_azimuth), sin(_elevation) * cos(_azimuth), - cos(_elevation)];
	_vel = [(_dir select 0) * _speed, (_dir select 1) * _speed, (_dir select 2) * _speed];

	_speed = sqrt((_vel select 0)^2+(_vel select 1)^2+(_vel select 2)^2);

	_bullet setVelocity _vel;
	_bullet setVectorDir _dir;

	#ifdef DEBUG_MODE_FULL
		hintSilent format ["Average dispersion of ammo: %1 mils\nRadial Deviation: %2 mils\nAngle of Deviation: %3 degrees",_dispersion, _radiusdisp, _angledisp];
	#endif
};
