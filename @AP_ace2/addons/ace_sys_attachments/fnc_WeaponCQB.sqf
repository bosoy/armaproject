#include "script_component.hpp"

private ["_w", "_class", "_return", "_ar", "_current", "_types", "_entry"];
_w = _this;
_return = [];

_class = (CFGSETTINGS >> "weapons" >> _w >> "ACE_CQB");
if (isClass _class) then {
	_types = [];
	{
		_entry = getText (_class >> format["ACE_CQB_%1", _x]);
		if (_entry == "THIS") then {
			_current = _x;
		} else {
			_entry = [_x, _entry];
			PUSH(_types,_entry);
		};
	} forEach ["SCOPE", "CQB"];
	_return = _types;
};
_return
