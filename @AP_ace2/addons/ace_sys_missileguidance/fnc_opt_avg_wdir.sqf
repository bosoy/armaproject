#include "script_component.hpp"

private ["_dt","_timeprev","_max","_step","_dt","_min","_vec1_hmag","_vec2_hmag","_vec1","_diffH","_vec2","_diffV","_diff","_H","_V","_wH","_wV","_saclos_cur"];

PARAMS_2(_vehicle,_projectile);
sleep 0.5;
_step = 0.1;
_timeprev = time - _step;
_vec1 = vectorDir _projectile;
_vec2 = (_vehicle getVariable QGVAR(saclos_cur)) select 0;
_max = 10;	 // max angular speed
_dt = 0.2;

while {alive _projectile} do {
	_saclos_cur = _vehicle getVariable QGVAR(saclos_cur);
	_dt = time - _timeprev;
	_vec1 = _vec2;	//prev los vector
	_vec2 = _saclos_cur select 0;	// current los vector

	_vec1_hmag = _vec1 call FUNC(mat_horizmag);
	_vec2_hmag = _vec2 call FUNC(mat_horizmag);

	_diffH = [_vec2,_vec1] call FUNC(mat_2vecanglediff);
	_diffV = [[_vec2_hmag,_vec2 select 2],[_vec1_hmag,_vec1 select 2]] call FUNC(mat_2vecanglediff);

	_wH = _diffH/_dt;
	_wV = _diffV/_dt;

	_saclos_cur set [1,_wH];
	_saclos_cur set [2,_wV];

	_saclos_cur = _vehicle setVariable [QGVAR(saclos_cur),_saclos_cur];

	_timeprev = time;
	sleep _step;
};
