/* ace_sys_lademeister (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"

PARAMS_3(_v,_p,_u);

if !(isPlayer _u) exitWith {};
if (_p == "DRIVER") exitWith {};

// Tastendruck zum herauslehnen
if (local _u) then {
	call GVAR(ADDKEYPRESS);
};