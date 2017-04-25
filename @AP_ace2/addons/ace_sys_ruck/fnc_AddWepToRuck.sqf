/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// ACE_RuckWepContents = [["wep1", 2], ["wep2", 11],  ....]
// arguments: [_unit, _weapon, _count] (_count is optional )

PARAMS_2(_unit,_weapon);
DEFAULT_PARAM(2,_count,1);

private ["_added","_weapons"];

_added = false;

//_weapons = _unit getVariable ["ACE_RuckWepContents",[]];
__DEF_GETV(_weapons,_unit,"ACE_RuckWepContents",[]);

{  // if there is an existing entry update count.
	if (_x select 0 == _weapon) exitwith {
		_weapons set [_forEachIndex, [_x select 0, (_x select 1) + _count]];
		_added = true;
	};

} foreach _weapons;

// otherwise append to list
if (!_added) then {
	_pshd = [_weapon, _count];
	PUSH(_weapons,_pshd);
};

TRACE_1("result",_weapons);

//not needed with PUSH/set
//(_unit) setvariable ["ACE_RuckWepContents", _weapons];

[QGVAR(changed), [_count,1,_weapon]] call CBA_fnc_localEvent; //#19453