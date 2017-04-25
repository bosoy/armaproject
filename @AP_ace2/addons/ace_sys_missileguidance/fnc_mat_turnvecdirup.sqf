// Turns vector by direction and up vectors
// Made by zGuba 2009
// Maths provided by Panda[PL] - thank You!!!
#include "script_component.hpp"

private ["_i", "_newVec"];

PARAMS_3(_vec,_vecDir,_vecUp);

_i = [_vecDir, _vecUp] call BIS_fnc_crossProduct;

_newVec = [[_i, _vec] call ACE_fnc_dotProduct, [_vecDir, _vec] call ACE_fnc_dotProduct, [_vecUp, _vec] call ACE_fnc_dotProduct];

_newVec