#include "script_component.hpp"
// Desc: Show debug output dialog
//-----------------------------------------------------------------------------
PARAMS_1(_caller);

if (_caller == player) then {
  // Need most recent value of DBG3_DebugData, so we can't pass DBG3_DebugData as param to AddAction.
  nul = [["DebugData", DBG3_DebugData]] spawn COMPILE_FILE(DebugOutputDialog);
};
