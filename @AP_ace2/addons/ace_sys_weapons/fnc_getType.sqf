#include "script_component.hpp"

PARAMS_1(_weap);

if (isNumber(configFile >> "CfgWeapons" >> _weap >> QGVAR(TYPE))) then { getNumber(configFile >> "CfgWeapons" >> _weap >> QGVAR(TYPE)) } else { (getNumber(configFile >> "CfgWeapons" >> _weap >> "type")) };
