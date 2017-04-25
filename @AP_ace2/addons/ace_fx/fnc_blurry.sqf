/* ace_fx_fnc_blurry

Makes screen blurry

Parameters:
_unit - Needed to check against player unit
_durationation - How long blur stays

*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __MULTIPLY 3
#define __MIN 2

PARAMS_2(_unit,_duration);
DEFAULT_PARAM(1,_duration,5);

if !(isPlayer _unit) exitWith { TRACE_1("Not player", (isPlayer _unit)); };
if !(alive _unit) exitWith { TRACE_1("Not alive",nil); };
if (_unit call ace_sys_wounds_fnc_isUncon) exitWith { TRACE_1("Uncon",nil); };

[_duration] spawn {
	PARAMS_1(_duration);
	GVAR(blur) ppEffectEnable true;
	_i = 1; _j = 10;
	while { _i < 10 } do {
		GVAR(blur) ppEffectAdjust [_i + 5];
		GVAR(blur) ppEffectCommit 0;
		_i = _i + 1;
		sleep 0.05;
	};
	sleep _duration;
	while { _j > 1 } do {
		GVAR(blur) ppEffectAdjust [_j - 5];
		GVAR(blur) ppEffectCommit 0;
		_j = _j - 1;
		sleep 0.05;
	};
	sleep _duration/2;
	GVAR(blur) ppEffectEnable false;
	//ppEffectDestroy GVAR(blur);
};
