/* ace_fx_fnc_cough

Plays coughing sounds

Parameters:
_unit - Needed to check against player unit
_inc - Increase of stamina, due to coughing
_min_sleep - Interval between coughs played

*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __cough ["ACE_Cough_1","ACE_Cough_2","ACE_Cough_3","ACE_Cough_4","ACE_Cough_5"]
#define __hcough ["ACE_Cough_H1","ACE_Cough_H2"]

PARAMS_3(_unit,_inc,_min_sleep);

if !(alive _unit) exitWith { TRACE_1("Not alive",nil); };
if (_unit call ace_sys_wounds_fnc_isUncon) exitWith { TRACE_1("Uncon",nil); };

private ["_sound","_random_sleep"];
_sound = __cough select (random 4);
_random_sleep = random (_min_sleep + 10);

if (isPlayer _unit) then {
	if (isNil {_unit getVariable QGVAR(coughing)}) then {
		[[_unit], [_sound,15]] call CBA_fnc_globalSay; [_unit,2,0.8] spawn {sleep 0.5; _this call ace_fx_fnc_dizzy}; // Delay, shake after coughing
		[_unit, _inc] call ace_sys_stamina_fnc_inc_breathing;
		_unit setVariable [QGVAR(coughing), time, false];
	} else {
		if (((_unit getVariable QGVAR(coughing)) + _random_sleep) < time) then {
			_unit setVariable [QGVAR(coughing), time, false];
			[[_unit], [_sound,15]] call CBA_fnc_globalSay; [_unit,2,0.8] spawn {sleep 0.5; _this call ace_fx_fnc_dizzy}; // Delay, shake after coughing
			[_unit, _inc] call ace_sys_stamina_fnc_inc_breathing;
		};
	};
} else {
	_unit say [_sound,10];
};
