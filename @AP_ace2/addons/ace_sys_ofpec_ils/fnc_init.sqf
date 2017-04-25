//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_v);

if (count crew _v == 0) exitWith { false };
if !(player in crew _v) exitWith { TRACE_1("not in crew",""); };
if (player != driver _v) exitWith { TRACE_1("u r driver",""); };

if (local player) then {
	_v spawn {
		waitUntil { format["%1", findDisplay 46] != "No display" };
		TRACE_1("addin key EH","");
		call FUNC(ADDKEYPRESS);
		GVAR(aircraft) = _this;
		_ils = _this getVariable [QGVAR(ILS), false]; // hmmm....
		_this setVariable [QGVAR(ILS),false,false];
		GVAR(ils) = false;
		TRACE_1("Aircraft",GVAR(aircraft));
	};
};
