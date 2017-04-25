/* ace_sys_lademeister (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"

PARAMS_1(_v);

if !(player in _v) exitWith { TRACE_1("not in crew",""); };
if (player == driver _v) exitWith { TRACE_1("u r driver",""); };

// Tastendruck zum herauslehnen
if (local player) then {
	0 spawn {
		waitUntil { !isNull (findDisplay 46) };
		TRACE_1("addin key EH","");
		call GVAR(ADDKEYPRESS);
	};
};
 