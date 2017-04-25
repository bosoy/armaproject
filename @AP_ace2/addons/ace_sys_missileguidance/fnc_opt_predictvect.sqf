//cur = [_wdir,_wH,_wV,_offH,_offV]
//Predicts next los direction based on angular speed (wH and wV), plus compensates for distance from missile to los
#include "script_component.hpp"

private ["_t","_wH","_wV","_mag","_min","_aheadH","_aheadV","_vec1_hmag","_vec2_hmag","_vec1","_offH","_offHprev","_vec2","_offV","_offVprev","_diff","_H","_V","_newdirH","_newdirV","_newvec","_saclos_cur"];

PARAMS_6(_vec1,_vec2,_dt,_vectortomissile,_dist,_vehicle);

_aheadH = 1;
_aheadV = 1;

if (!isNil {_vehicle getVariable QGVAR(saclos_cur)}) then {
	_saclos_cur = _vehicle getVariable QGVAR(saclos_cur);
	_saclos_cur set [0,_vec2]; //cur weapon dir
} else {
	_saclos_cur = [_vec2,0,0,0,0];
};

_offHprev = _saclos_cur select 3;
_offVprev = _saclos_cur select 4;

_vec2_hmag = _vec2 call FUNC(mat_horizmag);

_wH = _saclos_cur select 1;
_wV = _saclos_cur select 2;

_H = [_vec2] call FUNC(mat_getvecdir);
_V = [[_vec2_hmag,_vec2 select 2]] call FUNC(mat_getvecdir);


_t = [_vec2,_vectortomissile] call FUNC(opt_losoffset);

_offH = _t select 0;
_offV = _t select 1;

_saclos_cur set [3,_offH];
_saclos_cur set [4,_offV];

_aheadH = 1 + abs _offH;
_aheadV = 1 + abs _offV;

_wdirH = _H + _wH*_dt*_aheadH;
_wdirV = _V + _wV*_dt*_aheadV;
_mag = _vec2 call ACE_fnc_magnitude;
_newvec = [_mag*sin(_wdirH) * sin(_wdirV), _mag*cos(_wdirH) * sin (_wdirV), _mag*cos (_wdirV)];

// store information.
_vehicle setVariable [QGVAR(saclos_cur),_saclos_cur];
//[format ["aheadH %1 aheadV %2 vec2 %3 newvec %4 wh %5 wV %6", _aheadH,_aheadV,_vec2,_newvec, _wH,_wV]] call ace_fdebug;

[_newvec]
