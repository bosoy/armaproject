/* ace_fx_fnc_kick

Small kick back of head

Parameters:
_unit - Needed to check against player unit
_rate - Rate of kick, 1 = max

*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __MP 5
#define __MB 5

PARAMS_2(_unit,_rate);
DEFAULT_PARAM(1,_rate,1);

if !(isPlayer _unit) exitWith { TRACE_1("Not player",nil); };
if !(alive _unit) exitWith { TRACE_1("Not alive",nil); };
if (_unit call ace_sys_wounds_fnc_isUncon) exitWith { TRACE_1("Uncon",nil); };

if (_rate > 1) then { _rate = 1 };

[_unit,_rate] spawn {
	PARAMS_2(_unit,_rate);
	[
		_unit,
		([-__MP, __MP] select (random 1 > 0.5))*_rate,
		([-__MB, __MB] select (random 1 > 0.5))*_rate
	] call BIS_fnc_setPitchBank;
	135998 cutText["", "BLACK IN", _rate];
	135998 cutFadeOut _rate;
	sleep 0.05;
	[_unit, 0, 0] call BIS_fnc_setPitchBank;
};
