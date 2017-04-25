/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// ACE_RuckMagContents = [["mag1", 2,[count ammo mag1, count ammo mag2, ...]], ["mag2", 11,[count ammo mag1, count ammo mag2, ...]]  ....]
// arguments: [_unit, _mag]

private ["_return", "_mags", "_x", "_forEachIndex", "_newmags", "_amount"];
PARAMS_2(_unit,_magazine);
DEFAULT_PARAM(2,_count,1);

_return = [];
_mags = _unit getVariable ["ACE_RuckMagContents",[]];
TRACE_1("1",_mags);

{ //  reduce count on magazine entry if it exists
	if ((_x select 0) == _magazine) exitwith {
		_amount = if (_count < 0) then {0} else {(_x select 1) - _count};
		#ifdef DEBUG_MODE_FULL
		_helper = _x select 1;
		TRACE_2("",_amount,_helper);
		#endif
		if (_amount == 0) then {
			_return =+ _x select 2;
			_mags set [_forEachIndex, -1];
		} else {
			private ["_newar"];
			_newar = _x select 2;
			_oldc = count _newar;
			TRACE_2("",_newar,_oldc);
			for "_i" from 0 to (_oldc - _amount - 1) do {
				_return set [count _return, _newar select _i];
				_newar set [_i, -99];
			};
			_newar = _newar - [-99];
			TRACE_1("22",_newar);
			_mags set [_forEachIndex, [_x select 0, _amount, _newar]];
		};
	};
} foreach _mags;

_mags = _mags - [-1];
TRACE_1("2",_mags);

_unit setvariable ["ACE_RuckMagContents", _mags];

if (count _return > 0) then {
    [QGVAR(changed), [-_count,2,_magazine]] call CBA_fnc_localEvent;
};

TRACE_1("",_return);

_return;