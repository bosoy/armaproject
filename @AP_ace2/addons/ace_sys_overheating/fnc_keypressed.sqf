//#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("",_this);

_muz = (vehicle player) getVariable QGVAR(jammed);
if (isNil "_muz") exitwith { false };
[vehicle player, _muz, 0.3] spawn FUNC(unjam);

true
