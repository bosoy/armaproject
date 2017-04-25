#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
if (ctrlVisible 4000) exitwith {};
private ["_c","_st"];
_c = 4000;
while { _c <= 4008 } do {
	ctrlShow [_c,true];
	_c = _c + 1;
};
_st = "";
lbClear 4005;
{
	if (_x select 0 < 100) then { _st = "           " };
	if (_x select 0 < 10) then  { _st = "            " };
	if (_x select 0 > 99) then  { _st = "         " };
	if (_x select 0 > 999) then { _st = "        " };
	if (count _x > 2) then {
		lbAdd [4005,format["%1%2%3      %4",_x select 0,_st,_x select 1, _x select 2]];
	} else {
		lbAdd [4005,format["%1%2%3",_x select 0,_st,_x select 1]];
	};
} foreach ACE_SYS_SA_WCFG_TABLE;

ctrlSetText [3147, localize "STR_ACE_SA_CLOSE"];
buttonSetAction [3147, "[] execVM ""\x\ace\addons\sys_sight_adjustment\HideRangeCard.sqf"""];
