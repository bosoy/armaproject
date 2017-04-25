#include "script_component.hpp"

private ["_v", "_sel", "_dam"];

PARAMS_3(_v,_sel,_dam);

if (_sel == "glass1") then {
   _v setVariable ["ACE_glass_damage",_dam];
};
