// returns horizontal and vertical offset from missile to line of sight
// sign is + when missile is to the right/up and - when left/down from the line

#include "script_component.hpp"

private ["_signV","_signH","_distV","_sinV","_cosV","_d","_offsetH","_offsetV","_off","_dh","_dv","_spdH","_spdV","_lh","_lv","_d","_c","_max","_mag","_dt","_min","_ahead","_vec1_hmag","_vec2_hmag","_vec1","_diffH","_vec2","_diffV","_diff","_H","_V","_newdirH","_newdirV","_newvec"];

_vec2 = _this select 0;
_vectortomissile = _this select 1;
_vec1 = _vectortomissile;
_signH = 1;
_signV = -1;

if (_dist < 50) exitwith {[0,0,0]};


_vec1_hmag = _vec1 call FUNC(mat_horizmag);
_vec2_hmag = _vec2 call FUNC(mat_horizmag);

_diffH = [_vec2,_vec1] call FUNC(mat_2vecanglediff);
_diffV = [[_vec2_hmag,_vec2 select 2],[_vec1_hmag,_vec1 select 2]] call FUNC(mat_2vecanglediff);

if (_diffH < 0) then {_signH = -1};
if (_diffV < 0) then {_signV = 1};

_newvec = _vec2;

// ******** Offset from los ******* //

_vectortomissile_hmag = _vectortomissile call FUNC(mat_horizmag);

//horizontal projection of the vector
_vectortomissileH = [_vectortomissile select 0,_vectortomissile select 1];


	//horizontal offset (horiz. distance from missile to aiming line)
	_wvecH = [_newvec select 0,_newvec select 1];
	_wvec_hmag = _newvec call FUNC(mat_horizmag);
	_wvecV = [_wvec_hmag, _newvec select 2];

	_cosH = [_wvecH,_vectortomissileH] call FUNC(mat_cos2Dvec);
	_sinH = sqrt (abs(1-_cosH^2));
	_distH = _vectortomissile_hmag;
	_offsetH = _distH*_sinH;

	//vertical projection of the vector to missile. Vertical plane is along the aiming line.
	_vectortomissileV = [_distH*_cosH,_vectortomissile select 2];

	//vertical offset (vert. distance from missile to aiming line)
	_cosV = [_wvecV,_vectortomissileV] call FUNC(mat_cos2Dvec);
	_sinV = sqrt (abs(1-_cosV^2));
	_distV = _vectortomissileV call FUNC(mat_horizmag);
	_offsetV = _distV*_sinV;
	_off = sqrt (_offsetH^2 + _offsetV^2);


//[format ["Horiz %1 vert %2 wH %3 wV %4 d %5 newvec %6 off %7", _offsetH,_offsetV,_wH,_wV, _d,_newvec,_off]] call ace_fdebug;

//hint format [" spdH: %1 \n spdV: %2 \n offH: %3 offV: %4 \n d: %5",_spdH,_spdV, _offsetH,_offsetV,_d];
//player sidechat format ["offH: %1 offV: %2 cosV %3 distV %4",_offsetH*_signH,_offsetV*_signV,_cosV,_distV];

[_offsetH*_signH, _offsetV*_signV, _off]
