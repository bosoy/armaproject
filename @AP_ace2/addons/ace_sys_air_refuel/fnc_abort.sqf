/* ace_sys_air_refuel | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

if !((_this select 1) in actionKeys "CarBack") exitWith { false; };
GVAR(abort) = true;
false;
