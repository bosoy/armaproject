// takes 2 2D vectors
// returns the angle 2nd one has to be turned to become parallel/colinear to the 1st one.
// example of turning vec2: _newdir2 = _dir2 plus [_vec1,_vec2] call this_function

#include "script_component.hpp"

private ["_res","_dir1","_dir2","_diff"];

PARAMS_2(_vec1,_vec2);

_dir1 = [_vec1] call FUNC(mat_getvecdir);
_dir2 = [_vec2] call FUNC(mat_getvecdir);
_res = _dir1 - _dir2;
//if (abs (_res) > 180) then {_res = -_res };
if (_res < -180) then {_res = 360 + _res};
if (_res > 180) then {_res = _res - 360};

_res

