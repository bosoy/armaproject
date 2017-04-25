#include "Script_SightAdjustmentConfig.hpp"
#include "\x\ace\addons\sys_sight_adjustment_rifle\script_component.hpp"
private ["_wnd","_step","_max"];

_max = ACE_SYS_SA_RFL_WCFG_MAXWINDAGE;
_step = ACE_SYS_SA_RFL_WCFG_ADJWINDAGE;
_wnd = parseNumber (ctrlText 3097);
_wnd = [_wnd,_step] call FUNC(roundNumber);

if (_wnd > - _max) then {
	ctrlSetText [3097,str(_wnd - _step)];
	playsound "ace_sadj_click";
};
