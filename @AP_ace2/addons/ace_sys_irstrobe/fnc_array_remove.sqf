/* ace_sys_irstrobe (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

PARAMS_1(_ace_irstrobe_valuetoremove);
if (_ace_irstrobe_valuetoremove in GVAR(local_array)) then {
	TRACE_1("Rem",_ace_irstrobe_valuetoremove);
	GVAR(local_array) = GVAR(local_array) - [_ace_irstrobe_valuetoremove];
	if !(isDedicated) then {
		[_ace_irstrobe_valuetoremove] call FUNC(endStrobe);
		[_ace_irstrobe_valuetoremove] call FUNC(endStrobeHuntIR);
	};
};
