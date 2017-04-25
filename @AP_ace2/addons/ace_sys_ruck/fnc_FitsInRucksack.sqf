/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_unit,_item,_isWep);
DEFAULT_PARAM(3,_count,1);

private["_return","_ruckSize","_confSize","_newSize"];

_return = false;
_newSize = -1;

// Do we have a ruck.
if ( _item != "" && {(_unit call FUNC(HasRuck))} ) then {
	_ruckSize = _unit call FUNC(RuckInventorySize);
	_confSize = if (_isWep) then {
		getNumber(__CONF_WEAPONS >> _item >> "ACE_Size")
	} else {
		getNumber(__CONF_MAGAZINES >> _item >> "ACE_Size")
	};
	_newSize = _ruckSize - (_confSize * _count);
	TRACE_3("Fits",_ruckSize,_confSize,_newSize);

// if not full we are good
	if ( _newSize >= 0 ) then {
		_return = true;
	};
};

_return
