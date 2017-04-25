//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

// Eventhandler to stop "C" key press while dragging
PARAMS_5(_control,_dikCode,_shift,_ctrl,_alt);
_prone_dragging = (((player call CBA_fnc_getUnitAnim) select 0) == "prone");
_dikCode_check = if (_prone_dragging) then {
	(actionKeys "moveForward" + actionKeys "moveFastForward" + actionKeys "evasiveforward") //stop moving forward while prone dragging
} else {
	(actionKeys "NetworkStats" + actionKeys "stand") //stop standing up while dragging
};

if (!_shift && {!_ctrl} && {!_alt}) then {
	(_dikCode in _dikCode_check)
};
