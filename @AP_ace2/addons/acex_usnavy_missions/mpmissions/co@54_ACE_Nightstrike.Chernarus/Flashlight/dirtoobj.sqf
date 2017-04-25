private ["_object1","_object2","_degree"];
_object1 = _this select 0;
_object2 = _this select 1;
_degree = ((getpos _object2 select 0) - (getpos _object1 select 0)) atan2 ((getpos _object2 select 1) - (getpos _object1 select 1));
if (_degree < 0) then {_degree = _degree + 360};

_degree