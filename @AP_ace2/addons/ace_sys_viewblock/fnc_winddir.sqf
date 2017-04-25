#include "script_component.hpp"

private["_wd","_ws","_wind"];

_wind = ACE_wind;
_wd = (_wind select 0) atan2 (_wind select 1);
if (_wd < 0) then {_wd = _wd + 360};

_ws = (round ((SQRT((_wind select 0)^2 + (_wind select 1)^2)) * 100)) / 100;

[_wd,_ws]
