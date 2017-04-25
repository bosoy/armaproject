/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// ACE_RuckMagContents = [["mag1", 2,[count ammo mag1, count ammo mag2, ...]], ["mag2", 11,[count ammo mag1, count ammo mag2, ...]]  ....]
// arguments: [_unit, _magazine, _count,_ammocount] (_count _ammocount is optional )

PARAMS_2(_unit,_magazine);
DEFAULT_PARAM(2,_count,1);
DEFAULT_PARAM(3,_ammocount,-1); // -1 = default max ammo from CfgMagazines

private ["_added", "_mags", "_pshd", "_maxcount"];

_added = false;

_maxcount = getNumber(configFile>>"CfgMagazines">>_magazine>>"count");
if (_ammocount == -1 || {_ammocount > _maxcount}) then {
	_ammocount = _maxcount;
};

//_mags = _unit getVariable ["ACE_RuckMagContents",[]];
__DEF_GETV(_mags,_unit,"ACE_RuckMagContents",[]);

{ // if there is an existing entry update count.
	if ((_x select 0) == _magazine) exitwith {
		_acar = _x select 2;
		for "_i" from 1 to _count do {
			_acar set [count _acar, _ammocount];
		};
		_mags set [_forEachIndex, [_x select 0, (_x select 1) + _count, _acar]];
		_added = true;
	};
} foreach _mags;

// otherwise append to list
if (!_added) then {
	_acar = [];
	for "_i" from 1 to _count do {
		_acar set [count _acar, _ammocount];
	};
	_pshd = [_magazine,_count,_acar];
	PUSH(_mags,_pshd);
};

TRACE_1("result",_mags);

//not needed with PUSH/set
//(_unit) setvariable ["ACE_RuckMagContents", _mags];

[QGVAR(changed), [_count,2,_magazine]] call CBA_fnc_localEvent;