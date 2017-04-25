// Script by zGuba A.D. 2009
// Open door at get in and out

#include "script_component.hpp"

#define __doorsClosed (_vehicle animationPhase (_doors select 0) == 0 && {alive _vehicle})

PARAMS_3(_vehicle,_position,_unit);

private "_doors";
_doors = if ((_vehicle worldToModel (getPosATL _unit)) select 0 > 0) then {["dvere_p_vrch","dvere_p_spod"]} else {["dvere_l_vrch","dvere_l_spod"]};

if (__doorsClosed) then {
	{ _vehicle animate [_x, 1] } forEach _doors;
	//[_vehicle, "doors"] call CBA_fnc_globalSay3D;
};
