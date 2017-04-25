/* ----------------------------------------------------------------------------
Function: ACE_fnc_delPropertyObj

Description:
	Func

Parameters:
	-

Returns:
		nil

Examples:
	(begin example)
		[object, "propertyArrayName"] call ACE_fnc_delPropertyObj
	(end)

Author:
	(c) Rocko 2009
---------------------------------------------------------------------------- */
#include "script_component.hpp"

private["_o", "_d", "_pa", "_i", "_c", "_f"];
PARAMS_2(_o,_a);
_d = { _t = true;if (count(_this select 0)>= 0) then { _t = false };!_t };
if (count _this == 2) then {
	_pa = call compile _a;
	if ([_pa] call _d) then {
		_i = (count _pa)-1;
		_f = false;
		while { _i>= 0 && {!_f} } do { _f = (((_pa select _i)select 0) == _o); _i = _i-1; };

		if (_f) then {
			call compile format["%1 set[%2,{ DEL }];%1 = %1-[{ DEL }]", _a,_i+1];
		};
	};
};
