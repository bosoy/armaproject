//returns cosine of angle between 2 2D vectors
private ["_v","_v1","_a","_b","_a1","_b1","_cos","_d"];

_v = _this select 0;
_v1 = _this select 1;

_a = _v select 0;
_b = _v select 1;
_a1 = _v1 select 0;
_b1 = _v1 select 1;
_d = sqrt((_a^2 + _b^2)*(_a1^2 + _b1^2));
if (_d == 0) then {_cos = 0} else {_cos = (_a*_a1 + _b*_b1)/_d};

_cos