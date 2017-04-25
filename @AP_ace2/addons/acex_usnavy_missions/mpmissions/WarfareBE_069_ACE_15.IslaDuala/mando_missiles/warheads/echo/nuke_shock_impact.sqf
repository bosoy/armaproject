#include "nuke.h"

private [
	"_pos",
	"_yield",
	"_range",
	"_shock",
	"_dist",
	"_delay"
];

_pos  = _this select 0;
_yield  = _this select 1;

_range = 718.35*(_yield/kPa_SHOCK)^(1/3);

_dist = ( (vehicle player) distance _pos ) max 1;
_shock = 75/(abs(log(_range/(_dist^3))));
//diag_log format["Range %1, Distance %2, Shock %3", _range, _dist, _shock];

if ( _range >= _dist ) then {
	_delay = _dist/SHOCK_SPEED;
	sleep _delay;
	addCamShake [_shock, 0.2, 20]; 
};
