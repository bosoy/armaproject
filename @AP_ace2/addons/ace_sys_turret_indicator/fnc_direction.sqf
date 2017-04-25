private ["_vd","_wd","_a","_wvec"];

_vd = getdir (_this select 0);	//hull dir
_wvec = (_this select 0) weapondirection (_this select 1);
_wd = (_wvec select 0) atan2 (_wvec select 1);	//gun dir
if (_wd < 0) then {_wd = _wd + 360};
_a = _wd - _vd;
if (_a < 0) then {_a = 360 + _a};

[_a,_wd]

