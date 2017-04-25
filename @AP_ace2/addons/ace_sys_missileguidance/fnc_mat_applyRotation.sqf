#include "script_component.hpp"

private[
	"_v",
	"_r",
	"_r0",
	"_r1",
	"_r2",
	"_newVector"
];

PARAMS_2(_v,_r);

_r0 = _r select 0;
_r1 = _r select 1;
_r2 = _r select 2;

_newVector = [
	(_v select 0)*(_r0 select 0) + (_v select 1)*(_r1 select 0) + (_v select 2)*(_r2 select 0),
	(_v select 0)*(_r0 select 1) + (_v select 1)*(_r1 select 1) + (_v select 2)*(_r2 select 1),
	(_v select 0)*(_r0 select 2) + (_v select 1)*(_r1 select 2) + (_v select 2)*(_r2 select 2)
];

_newVector
