/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private["_weight","_items","_confItemWeight"];

PARAMS_1(_unit);

_weight = 0;

_items = _unit getVariable ["ACE_RuckMagContents",[]];
if (!isNil "_items") then { // saftey check because of getVar default issues
	{
		_confItemWeight = __CONF_MAGAZINES >> (_x select 0) >> "ACE_Weight";

		if ( isNumber(_confItemWeight) ) then {
			_weight = _weight + (_x select 1) * getNumber(_confItemWeight);
		};
	} forEach _items;
};

_items = _unit getVariable ["ACE_RuckWepContents",[]];
if (!isNil "_items") then { // saftey check because of getVar default issues
	{
		_confItemWeight = __CONF_WEAPONS >> (_x select 0) >> "ACE_Weight";

		if ( isNumber(_confItemWeight) ) then {
			_weight = _weight + (_x select 1) * getNumber(_confItemWeight);
		};
	} forEach _items;
};

_weight
