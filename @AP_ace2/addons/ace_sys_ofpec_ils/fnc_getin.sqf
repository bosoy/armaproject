//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_v,_p,_u);

if !(isPlayer _u) exitWith {};
if (_p != "DRIVER") exitWith {};

if (local _u) then {
	TRACE_1("addin key EH","");
	call FUNC(ADDKEYPRESS);
	GVAR(ils) = false;
};
