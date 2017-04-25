#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
private ["_st","_st1","_dlg","_ctrl1"];
_dlg = createDialog "ACE_SYS_SA_RangeCard";
waituntil { _dlg };
_st = "";
lbClear 4005;
{
	if (_x select 0 < 100) then { _st = "         " };
	if (_x select 0 < 10) then  { _st = "           " };
	if (_x select 0 > 99) then  { _st = "        " };
	if (_x select 0 > 999) then { _st = "       " };

	if (count _x > 2) then {
		lbAdd [4005,format["%1%2%3      %4",_x select 0,_st,_x select 1, _x select 2]];
	} else {
		lbAdd [4005,format["%1%2%3",_x select 0,_st,_x select 1]];
	};

} foreach ACE_SYS_SA_WCFG_TABLE;
