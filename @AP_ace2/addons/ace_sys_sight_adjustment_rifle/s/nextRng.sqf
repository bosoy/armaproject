#include "Script_SightAdjustmentConfig.hpp"
#include "\x\ace\addons\sys_sight_adjustment_rifle\script_component.hpp"
private ["_i","_el","_step","_max","_c","_table"];
//hint format ["elev %1", _el];
_max = ACE_SYS_SA_RFL_WCFG_MAXELEVATION;
_table = ACE_SYS_SA_RFL_WCFG_TABLE;
_el = parseNumber (ctrlText 3033);
_c = 999;
for "_i" from 0 to ((count _table)-1) do {
	if (_el == ((_table select _i) select 0)) exitwith { _c = _i+1 };
};

if ( (_c < (count _table)) && {(((_table select _c) select 0) <= _max) }) then {
	ctrlSetText [3033,str((_table select _c) select 0)];
	playsound "ace_sadj_click";
};
