//#define DEBUG_MODE_FULL
#include "script_component.hpp"
if (isNil QGVAR(currentDialog)) exitWith { false };

TRACE_1("ENTER", _this);

call FUNC(clearAllText);
GVAR(currentState) = [GVAR(currentState), GVAR(stateTable)] call FUNC(stateMachine);
