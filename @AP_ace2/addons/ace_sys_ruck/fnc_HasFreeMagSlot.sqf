/* ace_sys_smallitem (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_exit","_pistol","_rifle","_binoc","_smallitem","_magType","_num","_thisType","_j","_k"];

PARAMS_2(_unit,_item);

_exit = false;

_pistol = 0;
_rifle = 0;
_binoc = 0;
_smallitem = 0;
{
	_magType = getNumber (__CONF_MAGAZINES >> _x >> "type");

	switch _magType do {
		case __Type_SlotHandGunItem: {
			INC(_pistol);
		};

		case __Type_SlotPrimaryItem: {
			INC(_rifle);
		};

		case __Type_SlotSmallItems: {
			INC(_smallitem);
		};

		case __Type_SlotBinocular: {
			INC(_binoc);
		};

		default {
			if ( _magType > (__Type_SlotPrimaryItem * __Num_SlotPrimaryItem) ) exitWith {};

			_num = _magType / __Type_SlotPrimaryItem;

			if ( _num == (round _num) ) then {
				_rifle = _rifle + _num;
			} else {
				if ( _magType > (__Type_SlotHandGunItem * __Num_SlotHandGunItem) ) exitWith {};

				_num = _magType / __Type_SlotHandGunItem;

				if ( _num == (round _num) ) then {
					_pistol = _pistol + _num;
				};
			};
		};
	};
} forEach (magazines _unit);

_thisType = getNumber (__CONF_MAGAZINES >> _item >> "type");

switch _thisType do {
	case __Type_SlotHandGunItem: {
		_num = 1;
		_j = _pistol;
		_k = __Num_SlotHandGunItem;
	};

	case __Type_SlotPrimaryItem: {
		_num = 1;
		_j = _rifle;
		_k = __Num_SlotPrimaryItem;
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
		if ( _thisType > (__Type_SlotPrimaryItem * __Num_SlotPrimaryItem) ) exitWith { _exit = true };
		_num = _thisType / __Type_SlotPrimaryItem;

		if ( _num == (round _num) ) then {
			_j = _rifle;
			_k = __Num_SlotPrimaryItem;
		} else {
			if ( _thisType > (__Type_SlotHandGunItem * __Num_SlotHandGunItem) ) exitWith { _exit = true };
			_num = _thisType / __Type_SlotHandGunItem;

			if ( _num == (round _num) ) then {
				_j = _pistol;
				_k = __Num_SlotHandGunItem;
			};
		};
	};
};

if ( !_exit && {((_k - _j) >= 1)} ) then {
	_exit = true;
};

_exit
