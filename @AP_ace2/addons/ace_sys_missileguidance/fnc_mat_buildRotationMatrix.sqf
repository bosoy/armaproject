#include "script_component.hpp"

private [
	"_ct",
	"_cr",
	"_cp",
	"_st",
	"_sr",
	"_sp",
	"_rotation"
];

PARAMS_3(_x,_y,_z);

_ct = cos(_x);
_cr = cos(_y);
_cp = cos(_z);
_st = sin(_x);
_sr = sin(_y);
_sp = sin(_z);

_rotation = [
	[_cp*_cr, -1*_sp*_ct + _cp*_sr*_st, _sp*_st + _cp*_sr*_ct],
	[_sp*_cr, _cp*_ct + _sp*_sr*_st, -1*_cp*_st + _sp*_sr*_ct],
	[-1*_sr, _cr*_st, _cr*_ct]
];

_rotation
