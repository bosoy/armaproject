/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private["_return","_size","_confItemSize","_confPackSize","_items"];

PARAMS_1(_unit);

_return = -1;
_size = 0;

_ruck = _unit call FUNC(FindRuck);
if (_ruck != "") then {
	_items = _unit getVariable ["ACE_RuckMagContents",[]];
	{
		_confItemSize = getNumber(__CONF_MAGAZINES >> (_x select 0) >> "ACE_Size");
		_size = _size + (_confItemSize * (_x select 1));
	} forEach _items;

	_items = _unit getVariable ["ACE_RuckWepContents",[]];
	{
		_confItemSize = getNumber(__CONF_WEAPONS >> (_x select 0) >> "ACE_Size");
		_size = _size + (_confItemSize * (_x select 1));
	} forEach _items;

	_confPackSize = getNumber(__CONF_WEAPONS >> _ruck >> "ACE_PackSize");
	_return = _confPackSize - _size;
	if (_return == -1) then {return = -2}; //prevent coincidental no ruck
};

_return
