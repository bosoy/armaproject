#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
private ["_wnd","_step","_max"];
_max = ACE_SYS_SA_WCFG_MAXWINDAGE;
_step = ACE_SYS_SA_WCFG_ADJWINDAGE;
_wnd = parseNumber (ctrlText 3097);
if (_wnd > - _max) then {
	ctrlSetText [3097,str(_wnd - _step)];
};