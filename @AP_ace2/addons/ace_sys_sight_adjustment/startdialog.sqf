#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
private ["_units","_c","_dlg","_i","_range","_table","_initelev","_dlg1"];

if (ACE_SYS_SA_WCFG_ADJMODE == "range") then { //sa dialog with range settings
	_dlg = createDialog "ACE_SYS_SA_RNG_Dialog";
	waituntil { _dlg };
	_initelev = ACE_SYS_SA_CURELEVATION;
	_table = ACE_SYS_SA_WCFG_TABLE;
	_range = 0;
	{
		if ((_x select 1) == _initelev) exitwith { _range = _x select 0 };
		if (_initelev < (_x select 1)) exitwith { _range = _x select 0 };	//if no match found, take the closest value
	} foreach _table;

	ctrlSetText [3033, str(_range)];
	_initwindage = ACE_SYS_SA_CURWINDAGE;
	ctrlSetText [3097, str(_initwindage)];
	_units = call FUNC(FindUnitText);
	ctrlSetText [3501, _units select 2];
	ctrlSetText [3502, _units select 1];
};
if (ACE_SYS_SA_WCFG_ADJMODE == "angle") then { //sa dialog with elev settings
	_dlg = createDialog "ACE_SYS_SA_ELEV_Dialog";
	waituntil { _dlg };
	_initelev = ACE_SYS_SA_CURELEVATION;
	ctrlSetText [3033, str(_initelev)];
	_initwindage = ACE_SYS_SA_CURWINDAGE;
	ctrlSetText [3097, str(_initwindage)];
	ctrlSetText [3147, localize "STR_ACE_SA_RANGETABLE"];
	buttonSetAction [3147, "[] execVM ""\x\ace\addons\sys_sight_adjustment\ShowRangeCard.sqf"""];
	_units = call FUNC(FindUnitText);
	ctrlSetText [3501,_units select 0];
	ctrlSetText [3502, _units select 1];
	for "_c" from 4000 to 4008 do {ctrlShow [_c,false]};
};
