/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// ACE_RuckWepContents = [["weapon1", 2], ["weapon2", 11],  ....]
// returns the list of unit's ruck weapons, duplicating entries if count > 1
// arguments: _unit

private ["_weapons","_list","_i"];

PARAMS_1(_unit);

//_weapons = _unit getVariable ["ACE_RuckWepContents",[]];
__DEF_GETV(_weapons,_unit,"ACE_RuckWepContents",[]);
_list = [];
{
	if ( (_x select 1) > 0 ) then {
		for "_i" from 1 to (_x select 1) do {
			PUSH(_list,(_x select 0));
		};
	};
} foreach _weapons;

_list
