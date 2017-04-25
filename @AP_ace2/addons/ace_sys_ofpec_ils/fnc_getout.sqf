//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_v,_p,_u);

if !(isPlayer _u) exitWith { TRACE_1("u r no player",""); };
if (_p != "DRIVER") exitWith { TRACE_1("u r driver",""); };

if (local _u) then {
	TRACE_1("removin key EH","");
	call FUNC(REMOVEKEYPRESS);
	_v setVariable [QGVAR(ILS),false,false];
	GVAR(ils) = false;
};
