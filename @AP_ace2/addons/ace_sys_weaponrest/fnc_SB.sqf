/* ace_sys_weaponrest | fnc_SB.sqf - " Rest a weapon on a sandbag " | (c) 2009 by rocko */

#include "script_component.hpp"

TRACE_1("",_this);

private["_ret","_data"];

PARAMS_2(_unit,_range);

_SB = nearestObjects [_unit, ["ACE_Sandbag_Build","ACE_Rucksack_crate"], _range] select 0;
if (isNil "_SB") exitWith { false };
_ret = false;
_data = [player,_SB] call CBA_fnc_headdir;
if ( !isNil "_SB" &&  {(_data select 2)} ) then {
	if ( (_data select 1) <= 18 && {(_data select 1) >= -18} )  then
	{ _ret = true; };
};
_ret


