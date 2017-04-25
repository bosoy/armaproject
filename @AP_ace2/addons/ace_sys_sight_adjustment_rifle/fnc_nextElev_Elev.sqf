#include "Script_SightAdjustmentConfig2.hpp"
#include "\x\ace\addons\sys_sight_adjustment_rifle\script_component.hpp"
private ["_i","_el","_step","_max","_table"];
//hint format ["elev %1", _el];
_max = ACE_SYS_SA_RFL_WCFG_MAXELEVATION;
_step = ACE_SYS_SA_RFL_WCFG_ADJELEVATION;
_table = ACE_SYS_SA_RFL_WCFG_TABLE;

_el = parseNumber (ctrlText 3670);
_el = [_el,_step] call FUNC(roundNumber);
if (_el<_max) then {
	ctrlSetText [3670,str(_el+_step)];
	{
		if ((_x select 1) == _el+_step) exitwith {
			ctrlSetText [3033,str(_x select 0)];
		};
	} foreach _table;
	playsound "ace_sadj_click";
};
