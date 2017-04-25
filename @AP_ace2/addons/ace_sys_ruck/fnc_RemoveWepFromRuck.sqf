/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// ACE_RuckWepContents = [["weapon1", 2], ["weapon2", 11],  ....]
// arguments: [_unit, _weapon]

private ["_return", "_weapons", "_x", "_forEachIndex", "_newweapons", "_amount"];
PARAMS_2(_unit,_weapon);
DEFAULT_PARAM(2,_count,1);

_return = false;
_weapons = _unit getVariable ["ACE_RuckWepContents",[]];

{ //  reduce count on weapon entry if it exists
	if (_x select 0 == _weapon) exitwith {
		_amount = if (_count < 0) then {0} else {(_x select 1) - _count};
		_weapons set [_forEachIndex, [_x select 0, _amount]];
		_return = true;
	};
} foreach _weapons;

// create new weapon list with any zero count items purged
_newweapons = [];
{
	if ((_x select 1) > 0) then {
		PUSH(_newweapons,_x);
	};
} foreach _weapons;

_unit setvariable ["ACE_RuckWepContents", _newweapons];

if (_return) then {
    [QGVAR(changed), [-_count,1,_weapon]] call CBA_fnc_localEvent;
};

_return;