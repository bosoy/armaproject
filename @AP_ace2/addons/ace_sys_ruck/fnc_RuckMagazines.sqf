/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// ACE_RuckMagContents = [["mag1", 2], ["mag2", 11],  ....]
// returns the list of unit's ruck magazines, duplicating entries if count > 1
// arguments: _unit

private ["_mags","_list","_i"];

PARAMS_1(_unit);

//_mags = _unit getVariable ["ACE_RuckMagContents",[]];
__DEF_GETV(_mags,_unit,"ACE_RuckMagContents",[]);
_list = [];
{
	if ( (_x select 1) > 0 ) then {
		for "_i" from 1 to (_x select 1) do {
			PUSH(_list,(_x select 0));
		};
	};
} foreach _mags;

_list
