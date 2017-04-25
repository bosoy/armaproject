#include "script_component.hpp"
// Desc: Activate Yes/No dialog via Action menu
// By: Dr Eyeball
// Version: 1.1 (May 2007)
//-----------------------------------------------------------------------------

_Question = ["Question", _this select 3, "Error: No question"] call fn_GetParamByName;

nul = [
  // optional parameters for user
  ["ActionParams",
    [
      ["Unit", _this select 0],
      ["Caller", _this select 1],
      ["ID", _this select 2],
      ["Params", _this select 3]
    ]
  ],
  // standard parameters required by this dialog
  ["Question", _Question]
] spawn COMPILE_FILE(YesNoDialog);
