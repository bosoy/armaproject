#include "Script_SightAdjustmentConfig2.hpp"
#include "\x\ace\addons\sys_sight_adjustment_rifle\script_component.hpp"
private ["_i","_el","_step","_min","_c","_table"];
_min = ACE_SYS_SA_RFL_WCFG_MINRANGE;
_table = ACE_SYS_SA_RFL_WCFG_TABLE;
_el = parseNumber (ctrlText 3033);
_c = 999;
for "_i" from 0 to ((count _table)-1) do {
	if (_el == ((_table select _i) select 0)) exitwith { _c = _i-1 };
};

if ( _c >= 0 && {((_table select _c) select 0) >= _min} ) then {
	ctrlSetText [3033,str((_table select _c) select 0)];
	ctrlSetText [3670,str((_table select _c) select 1)];
	playsound "ace_sadj_click";
};
