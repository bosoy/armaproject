#include "script_component.hpp"
private ["_disp", "_newvd"];
disableSerialization;

_disp = uiNamespace getVariable "ACE_SETTINGS_DIALOG";
#define __ctrl(A) (_disp displayCtrl A)

_newvd = round (_this select 1);
__ctrl(33001) ctrlSetText str(_newvd);

if (ace_sys_nvg_rangelimit_enabled) then { if (currentvisionmode player == 0) then { setViewDistance _newvd }; } else { setViewDistance _newvd };
