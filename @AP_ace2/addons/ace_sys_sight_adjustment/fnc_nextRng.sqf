#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
private ["_i","_el","_step","_max"];
_max = ACE_SYS_SA_WCFG_MAXELEVATION;
_step = ACE_SYS_SA_WCFG_ADJELEVATION;
_el = parseNumber (ctrlText 3033);
if (_el<_max) then {
	ctrlSetText [3033,str(_el+_step)];
};