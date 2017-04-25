// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#define SCRIPTNAME QGVAR(fnc_turnrocket)

private ["_vel","_spd","_upx","_upy","_upz","_x1","_y1","_z1","_k","_xy"];
PARAMS_3(_bullet,_sleep,_delay);

if (_delay > 0) then {sleep _delay};
while { alive _bullet && {speed _bullet > 1} } do {
	_vel = velocity _bullet;
	_spd = _vel call ACE_fnc_magnitude;
	_x1 = (_vel select 0) / _spd;
	_y1 = (_vel select 1) / _spd;
	_z1 = (_vel select 2) / _spd;

	_upz = sqrt(_x1^2 + _y1^2);
	if (_upz <= 0.001) exitwith {
		TRACE_1("Exiting","");
	};
	_k = -_z1/_upz;		//xup = k*x1, yup = k*y1
	_upx = _k*_x1;
	_upy = _k*_y1;
	TRACE_3("Adjust vector",([_upx,_upy,_upz]),(vectorUp _bullet),(getPosATL _bullet));
	_bullet setvectorUp [_upx,_upy,_upz];

	sleep _sleep;
};
