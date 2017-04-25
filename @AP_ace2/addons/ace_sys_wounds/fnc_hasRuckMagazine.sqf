#include "script_component.hpp"

private ["_magazinesList", "_found"];
PARAMS_2(_unit,_mag);
if !([_unit] call ACE_fnc_HasRuck) exitWith {false};
_MagazinesList = [_unit] call ACE_fnc_RuckMagazinesList;
_found = false;
{
	if ((_x select 0) == _mag && {(_x select 1) > 0}) exitWith { _found = true };
} forEach _MagazinesList;
_found;
