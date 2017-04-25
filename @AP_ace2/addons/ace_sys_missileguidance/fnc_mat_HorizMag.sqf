// Calculate the horizontal magnitude (X,Y) of a vector.
private ["_v", "_m"];

_v = _this;
_m = sqrt((_v select 0)*(_v select 0) + (_v select 1)*(_v select 1));
_m
