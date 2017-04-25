#include "script_component.hpp"

private ["_w", "_class", "_return", "_ar", "_current", "_types", "_entry"];
_w = _this;
_return = [];

_class = (CFGSETTINGS >> "weapons" >> _w >> "ACE_Attach");
if (isClass _class) then {
	_ar = getArray (_class >> "ACE_ATTACH_AVAILABLE");
	if (count _ar > 0) then {
		_types = [];
		{
			_entry = getText (_class >> format["ACE_ATTACH_%1", _x]);
			if (_entry == "THIS") then {
				_current = _x;
			} else {
				_entry = [_x, _entry];
				PUSH(_types,_entry);
			};
		} forEach _ar;
		_return = _types;
	};
};
_return
