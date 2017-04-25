/* ace_sys_smallitem (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_exit","_pistol","_rifle","_launcher","_binoc","_smallitem","_wepType","_num","_thisType","_j","_k"];

PARAMS_2(_unit,_item);

_exit = false;

_pistol = 0;
_rifle = 0;
_launcher = 0;
_binoc = 0;
_smallitem = 0;
{
	_wepType = getNumber (__CONF_WEAPONS >> _x >> "type");

	switch _wepType do {
		case __Type_SlotHandGun: {
			INC(_pistol);
		};

		case __Type_SlotPrimary: {
			INC(_rifle);
		};

		case __Type_SlotSecondary: {
			INC(_launcher);
		};

		case __Type_SlotBinocular: {
			INC(_binoc);
		};

		case __Type_SlotSmallItems: {
			INC(_smallitem);
		};

		default {
			if ( _wepType > (__Type_SlotBinocular * __Num_SlotBinocular) ) exitWith {};

			_num = _wepType / __Type_SlotBinocular;

			if ( _num == (round _num) ) then {
				_binoc = _binoc + _num;
			} else {
				if ( _wepType > (__Type_SlotSmallItems * __Num_SlotSmallItems) ) exitWith {};

				_num = _wepType / __Type_SlotSmallItems;

				if ( _num == (round _num) ) then {
					_smallitem = _smallitem + _num;
				};
			};
		};
	};
} forEach (weapons _unit);

_thisType = getNumber (__CONF_WEAPONS >> _item >> "type");

switch _thisType do {
	case __Type_SlotHandGun: {
		_num = 1;
		_j = _pistol;
		_k = __Num_SlotHandGun;
	};

	case __Type_SlotPrimary: {
		_num = 1;
		_j = _rifle;
		_k = __Num_SlotPrimary;
	};

	case __Type_SlotSecondary: {
		_num = 1;
		_j = _launcher;
		_k = __Num_SlotSecondary;
	};

	case __Type_SlotSmallItems: {
		_num = 1;
		_j = _smallitem;
		_k = __Num_SlotSmallItems;
	};

	case __Type_SlotBinocular: {
		_num = 1;
		_j = _binoc;
		_k = __Num_SlotBinocular;
	};

	default {
		if ( _thisType > (__Type_SlotBinocular * __Num_SlotBinocular) ) exitWith { _exit = true };
		_num = _thisType / __Type_SlotBinocular;

		if ( _num == (round _num) ) then {
			_j = _launcher;
			_k = __Num_SlotBinocular;
		} else {
			if ( _thisType > (__Type_SlotSmallItems * __Num_SlotSmallItems) ) exitWith { _exit = true };
			_num = _thisType / __Type_SlotSmallItems;

			if ( _num == (round _num) ) then {
				_j = _smallitem;
				_k = __Num_SlotSmallItems;
			};
		};
	};
};

if ( !_exit && {((_k - _j) >= 1)} ) then {
	_exit = true;
};

_exit
