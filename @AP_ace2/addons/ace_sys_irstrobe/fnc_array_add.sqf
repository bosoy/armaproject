/* ace_sys_irstrobe (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

PARAMS_1(_ace_irstrobe_valuetoadd);
if !(_ace_irstrobe_valuetoadd in GVAR(local_array)) then {
	TRACE_1("Add",_ace_irstrobe_valuetoadd);
	GVAR(local_array) set [count GVAR(local_array), _ace_irstrobe_valuetoadd];
	if !(isDedicated) then {
		if (ace_sys_nvg_on) then { [_ace_irstrobe_valuetoadd] call FUNC(startStrobe) };
		if (ace_sys_huntir_IRON) then { [_ace_irstrobe_valuetoadd] call FUNC(startStrobeHuntIR) }
	};
};
