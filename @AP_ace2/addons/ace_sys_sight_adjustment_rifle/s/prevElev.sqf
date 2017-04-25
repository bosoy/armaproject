#include "Script_SightAdjustmentConfig.hpp"
#include "\x\ace\addons\sys_sight_adjustment_rifle\script_component.hpp"
private ["_i","_el","_step","_min"];
_min = ACE_SYS_SA_RFL_WCFG_MINELEVATION;
_step = ACE_SYS_SA_RFL_WCFG_ADJELEVATION;
_el = parseNumber (ctrlText 3033);
_el = [_el,_step] call FUNC(roundNumber);

if (_el > _min) then {
	ctrlSetText [3033,str(_el-_step)];
	playsound "ace_sadj_click";
};
