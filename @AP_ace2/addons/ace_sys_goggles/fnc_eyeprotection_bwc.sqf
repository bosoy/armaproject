/* ace_sys_goggles (.pbo) | (c) 2009, 2010 by rocko */

#include "script_component.hpp"

// Returns value for protective value to use throughout the mod for various features

// Unit to check the protective value
PARAMS_1(_unit);

if ((_unit getVariable [QGVAR(protection), 0]) in [1,3]) exitWith { false };
true
