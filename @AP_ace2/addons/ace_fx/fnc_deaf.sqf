/* ace_fx_fnc_deaf

Deafens player

Parameters:
_unit - Needed to check against player unit
_duration - How long player should be deaf
_rate - How deaf, muffled or no hearing

*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_unit,_duration,_rate);

if (isNil "_duration") then { _duration = 10 };
if (_duration < 5) then { _duration = 5 };
if (isNil "_rate") then { _rate = 0.2 };

if !(isPlayer _unit) exitWith {
	TRACE_1("Not player", (isPlayer _unit));
};

if ((getNumber (configFile >> "CfgVehicles" >> typeOf _unit >>"ACE_CrewProtection")) == 1) exitWith {};
if ([_unit] call ace_sys_goggles_fnc_earprotection) exitWith {};
if (_unit call ace_sys_wounds_fnc_isUncon) exitWith { TRACE_1("Uncon",nil); };
_crpt2 = _unit getVariable "ACE_CrewProtection_combatdeaf";if (isNil "_crpt2") then {_crpt2 = false};
if (_crpt2) exitWith {};

[_duration,_rate] spawn {
	PARAMS_2(_duration,_rate);
	0 fadesound _rate;
	0 faderadio (_rate - 0.1);
	sleep ((random 3) + _duration);
	_random = random 6;
	(_random + _duration) fadesound 1;
	(_random + _duration) faderadio 1;
	sleep ((random 6) + 4);
};

// TODO: Hook into ace_sys_combatdeaf


/*
_deaf = _unit getVariable QGVAR(deaf);
if (isNil "_deaf") then {
	GVAR(store) = ACE_SYS_COMBATDEAF_DV;
};
_unit setVariable [QGVAR(deaf), true];

[_unit,_duration] spawn {
	PARAMS_2(_unit,_duration);
	ACE_SYS_COMBATDEAF_DV = 100;
	ACE_SYS_COMBAT_DEAF = true;
	sleep _duration;
	ACE_SYS_COMBAT_DEAF = false;
	ACE_SYS_COMBATDEAF_DV = GVAR(store);
	sleep 2;
	_unit setVariable [QGVAR(deaf), nil];
};
*/
