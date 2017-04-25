/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private["_count","_type"];

_type = -1;
_count = 0;

switch (_this) do {
	case __Type_NoSlot: {
		_type = _this;
		_count = 1;
	};

	case __Type_SlotPrimary: {
		_type = _this;
		_count = 1;
	};

	case __Type_SlotHandGun: {
		_type = _this;
		_count = 1;
	};

	case __Type_SlotSecondary: {
		_type = _this;
		_count = 1;
	};

	case (__Type_SlotSecondary + __Type_SlotPrimary): {
		_type = __Type_SlotPrimary;
		_count = 2;
	};

	case __Type_SlotHandGunItem: {
		_type = _this;
		_count = 1;
	};

	case __Type_SlotPrimaryItem: {
		_type = _this;
		_count = 1;
	};

	case __Type_SlotPrimaryItem: {
		_type = _this;
		_count = 1;
	};

	case __Type_SlotBinocular: {
		_type = _this;
		_count = 1;
	};

	case __Type_HardMounted: {
		_type = _this;
		_count = 1;
	};

	case __Type_SlotSmallItems: {
		_type = _this;
		_count = 1;
	};

	default {
		{
			scopeName "Scan";

			if ( _x < _this ) then {
				_type = _x;
				_count = ceil(_this/_type);
				breakOut("Scan");
			};
		} forEach [__Type_SlotSmallItems, __Type_HardMounted, __Type_SlotBinocular, __Type_SlotPrimaryItem, __Type_SlotHandGunItem];
	};
};

TRACE_2("Parse",_type,_count);
[_type, _count]
