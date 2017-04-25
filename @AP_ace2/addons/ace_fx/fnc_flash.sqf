/* ace_fx_fnc_flash

Creates a short or timed flash on the screen

Parameters:
_unit - Needed to check against player unit
_duration - How long does the flash stay (optional, default value is 1)
_fade - How long it takes to return to normal (optional, default value is 2)

*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_unit,_duration,_fade);
DEFAULT_PARAM(1,_duration,1);
DEFAULT_PARAM(2,_fade,1);

if (_duration < 1) exitWith {};

if !(isPlayer _unit) exitWith { TRACE_1("Not player",nil); };
if !(alive _unit) exitWith { TRACE_1("Not alive",nil); };
if (_unit call ace_sys_wounds_fnc_isUncon) exitWith { TRACE_1("Uncon",nil); };

135997 cutText["", "WHITE IN", _duration];
135997 cutFadeOut _fade;

//if (_duration < 2) then {
//	[_unit,10,0.1] call ace_fx_fnc_dizzy; // Kick
//};
