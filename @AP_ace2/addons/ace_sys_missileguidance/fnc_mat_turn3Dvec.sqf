//turns 3D vector by _angleH degrees in X-Y plane and _angleV degrees in XY-Z plane
#include "script_component.hpp"

private ["_angleH","_angleV","_vmag","_vec_hmag","_vec","_H","_V","_newdirH","_newdirV","_newvec"];

_vec = _this select 0;
_angleH = _this select 1;
_angleV = _this select 2;
_vmag = _vec call ACE_fnc_magnitude;
_vec_hmag = _vec call FUNC(mat_horizmag);

_H = [_vec] call FUNC(mat_getvecdir);
_V = [[_vec_hmag,_vec select 2]] call FUNC(mat_getvecdir);

_newdirH = _H + _angleH;
_newdirV = _V + _angleV;

_newvec = [_vmag*sin(_newdirH) * sin(_newdirV), _vmag*cos(_newdirH) * sin (_newdirV), _vmag*cos (_newdirV)];

_newvec