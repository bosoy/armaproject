/* ace_sys_goggles (.pbo) | (c) 2009, 2010 by rocko */

#include "script_component.hpp"

// Returns value for protective value to use throughout the mod for various features

// Unit to check the protective value
PARAMS_1(_unit);

// TODO: Should return true or false??
_ear = _unit getVariable ["ACE_Ear_Protection", false];
if !(_ear) exitWith { 0 };
1
