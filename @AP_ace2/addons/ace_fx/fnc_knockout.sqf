/* ace_fx_fnc_knockout

Plays knockout animation for player

Parameters:
_unit - Needed to check against player unit
_duration - How long knocked out
_allowdamage - Receive damage upon knockout

*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);

if !(alive _unit) exitWith { TRACE_1("Not alive",nil); };
if (_unit call ace_sys_wounds_fnc_isUncon) exitWith { TRACE_1("Uncon",nil); };

DEFAULT_PARAM(1,_duration,15);
DEFAULT_PARAM(2,_allowDamage,false);

// Small durations aka low energy knockouts tilt the player/unit
if (_duration < 5) exitWith {
	_unit setDir ((getDir _unit) + (random 10) + ((random 2)* _duration));
};

if (!_allowdamage && {(_duration > 30)}) then { _allowdamage = true; TRACE_2("Allowdamage true due to long _duration",_duration,_allowdamage); };
if (isNil {_unit getVariable QGVAR(knockedOut)}) then {
	_unit setVariable [QGVAR(knockedOut), false, false];
};
_ko = _unit getVariable [QGVAR(knockedOut),false]; // Already knocked out?
_un = _unit getVariable ["ace_sys_wounds_uncon",false]; // Wounds
if (!_ko && {!_un}) then {
	_onFoot = vehicle _unit == _unit;
	_curAnim = animationState _unit;
	_moves =   getText (configFile >> "CfgVehicles" >> typeof _unit >> "moves");
	_actions = getText (configFile >> _moves >> "States" >> _curAnim >> "actions");

	private ["_death", "_getup"];
	if (_onFoot) then {
		_death = getText (configFile >> _moves >> "Actions" >> _actions >> "die");
		_getup = getText (configFile >> _moves >> "Actions" >> _actions >> "Lying");
		if (_getup == "") then { _getup = _curAnim; };
	} else {
		_getup = _curAnim;
		_tmp = getArray (configFile >> _moves >> "States" >> _curAnim >> "interpolateTo");
		if (count _tmp > 0) then {
			_tmp2 = [];
			for "_i" from 0 to (count _tmp)-1 step 2 do { _tmp2 set [count _tmp2, _tmp select _i] };
			_death = _tmp2 call ACE_fnc_selectrandom;
		} else {
			_death = _curAnim;
		};
	};
	if (_death == "") then { _death = _curAnim };

	_deathVariants = [_death];
	{
		_tmp = getArray (configFile >> _moves >> "States" >> _death >> _x);
		if (count _tmp > 1) then {
			for "_i" from 0 to (count _tmp) - 1 step 2 do { _deathVariants set [count _deathVariants, _tmp select _i] };
		};
	} foreach ["variantsPlayer","variantsAI"];

	_unit setVariable [QGVAR(knockedOut), true, true];
	if (_onFoot) then {
		_unit playmove _death;
	} else {
		_unit playmove _death; // See how it works for vehicles ??
	};
	if (_unit == player) then {
		(time+_duration-0.75) spawn {
			titleCut ["","white in"];
			sleep 0.75;
			waituntil {time > _this || {!alive player}};
			titleCut ["","black in"];
		};
	};
	sleep _duration;
	_unit setVariable [QGVAR(knockedOut), false, true];

	// Should not run the event if the unit is unconscious by now - so that we don't reset the unconscious state!
	// TODO: Disabled again due to possible issues... -- Should be properly evaluated!
	//if (_unit call ace_sys_wounds_fnc_isUncon) exitWith { TRACE_1("Uncon",nil); };

	if(alive _unit && {{_x==animationState _unit} count _deathVariants > 0}) then {
		[QGVAR(ranim), [_unit,_getup]] call CBA_fnc_globalEvent;
	};
};

if (_allowdamage) then {
	if (isNil "ace_sys_wounds_enabled") then {
		_unit setDamage ( (getDammage _unit) + ( ( 1 - (getDammage _unit)) * 0.06 ) );
	} else {
		if (local _unit) then {
			[_unit,"",0.06,objNull,""] call ace_sys_wounds_fnc_hd;
		} else {
			["ace_sys_wounds_addDloc", [_unit, 0.06]] call CBA_fnc_globalEvent;
		}
	};
};