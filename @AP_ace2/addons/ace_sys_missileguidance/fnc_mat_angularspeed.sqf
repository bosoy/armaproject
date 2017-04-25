// current angular speed taken from 2 3d vectors and dt
// in horiz and vertical plane

#include "script_component.hpp"

private ["_vec1_hmag", "_vec2_hmag", "_diffH", "_diffV"];

PARAMS_3(_vec1,_vec2,_dt);

_vec1_hmag = _vec1 call FUNC(mat_horizmag);
_vec2_hmag = _vec2 call FUNC(mat_horizmag);

_diffH = [_vec2,_vec1] call FUNC(mat_2vecanglediff);
_diffV = [[_vec2_hmag,_vec2 select 2],[_vec1_hmag,_vec1 select 2]] call FUNC(mat_2vecanglediff);

[_diffH/_dt, _diffV/_dt]