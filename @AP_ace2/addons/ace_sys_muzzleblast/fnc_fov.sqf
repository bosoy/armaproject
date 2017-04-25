#include "script_component.hpp"

private["_dif", "_infov"];

_pos_obj1 = getpos (_this select 0);
_pos_obj2 = getpos (_this select 1);

_dif = ((_pos_obj2 select 0) - (_pos_obj1 select 0)) atan2 ((_pos_obj2 select 1) - (_pos_obj1 select 1));

if (_dif < 0) then { _dif = 360 + _dif };
if (_dif > 180) then { _dif = _dif - 360 };
_infov = (abs _dif < 10);

["", _dif, _infov]
