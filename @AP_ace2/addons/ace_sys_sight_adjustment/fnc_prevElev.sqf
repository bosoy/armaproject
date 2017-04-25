#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
private ["_i","_el","_step","_min"];
_min = ACE_SYS_SA_WCFG_MINELEVATION;
_step = ACE_SYS_SA_WCFG_ADJELEVATION;
_el = parseNumber (ctrlText 3033);
if (_el > _min) then {
	ctrlSetText [3033, (round(_el-_step)) call CBA_fnc_intToString];
};