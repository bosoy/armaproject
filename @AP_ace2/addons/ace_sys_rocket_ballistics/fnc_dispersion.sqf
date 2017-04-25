#include "script_component.hpp"
//	This function finds the angle of dispersion using tabulated Gauss function (found in init script).
//	Then it applies the dispersion to the rocket.
//	As a result rocket dispersion follows Gaussian distribution.
//	Based heavily on NWD script published on BI forums.

private ["_unit","_speed","_dir","_dirx","_diry","_dirz","_dirang","_dispersion","_x","_sign","_j","_i","_y","_y0","_y1","_radiusdisp","_angledisp","_azimuth","_elevation","_vel","_upx","_upy","_upz","_x1","_y1","_z1","_k"];

PARAMS_3(_eh,_bullet,_dispmultiplier);
_unit = _eh select 0;
_ammo = _eh select 4;

_dir = vectorDir _bullet;
_dirx = _dir select 0;
_diry = _dir select 1;
_dirz = _dir select 2;
_dirang = [_dirx atan2 _diry, sqrt(_diry*_diry + _dirx*_dirx) atan2 (-_dirz)];

_dispersion = _dispmultiplier*getNumber (configFile >> "CfgAmmo" >> _ammo >> "ACE_DISP");

TRACE_1("",_this);
TRACE_3("",_dir,_dirang,_dispersion);

// Gaussian distribution
_x = 0;
_sign = 0;
while { true } do
{
       _j = floor (random 16777216); // 24 bit random integer
       _i = floor (random 128);
       _sign = floor (random 2);

       _x = _j * (ACE_WTAB select _i);
       _y = 0;
       if (_j < (ACE_KTAB select _i)) exitWith {};

       if (_i<127) then
       {
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
_angledisp = random 360;

//if (_dispmultiplier>1) then //debug for AI AT weapons
//{
//	 TRACE_2("",_radiusdisp,_angledisp);
// };
_azimuth = (_dirang select 0) + ( _radiusdisp * cos(_angledisp) ) / 1000*180/pi;
_elevation = (_dirang select 1) + ( _radiusdisp * sin(_angledisp) ) / 1000*180/pi;

_dir = [sin(_elevation) * sin(_azimuth), sin(_elevation) * cos(_azimuth), - cos(_elevation)];

_speed = 0.278*(speed _bullet);
_vel = [(_dir select 0) * _speed, (_dir select 1) * _speed, (_dir select 2) * _speed];

//Finding vectorUp coords for the newly found dir vector

	_x1 = _dir select 0;
	_y1 = _dir select 1;
	_z1 = _dir select 2;

	_k = -_z1/sqrt(_x1^2 + _y1^2);

	_upx = _k*_x1;
	_upy = _k*_y1;
	_upz = sqrt (_x1^2 + _y1^2);

/*if (_dispmultiplier>1) then //debug for AI AT weapons
{
	TRACE_3("",vectorDir _bullet,velocity _bullet,vectorUp _bullet);
	TRACE_3("",_dir,_vel,[_upx,_upy,_upz]);
};*/


if (_unit iskindOf "CAManBase") then
{
	//Broadcasting dispersion data over the network to synchronize the effect. Changes are applied locally on all machines.
	[QGVAR(disp), [[getPosATL _bullet, _ammo], _vel, [_dir,[_upx,_upy,_upz]]]] call CBA_fnc_globalEvent;
}
else //ffars
{
	//Applying dispersion
	_bullet setVelocity _vel;
	_bullet setVectorDirAndUp [_dir,[_upx,_upy,_upz]];
	_bullet setPosATL getPosATL _bullet;
};

//if (_dispmultiplier>1) then //debug for AI AT weapons
//{
//	TRACE_3("Resulting direction",(vectorDir _bullet),(velocity _bullet),(vectorUp _bullet));
// };
