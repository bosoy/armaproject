//#define DEBUG_MODE_FULL

#include "script_component.hpp"

// _unit: unit, well should be clear
// _dam: (0-1) new overall damage the unit receives, pain and bleed will be calulated by this
// _uncon: true, unit will fall unconscious, false not ATTENTION: ONLY VALID IF WOUNDS ISN'T ENABLED !!!!!!!!
// _time: time the unit will stay unconscious

// if wounds is enabled, setting states is possible with the damage value
// case (_dam > 0 && _dam < 0.5)    only bleeding and pain
// case (_dam >= 0.5 && _dam < 0.8)      unit falls unconscious immediately and wakes up after some time (see _time var), may fall uncon again
// case (_dam >= 0.8)       unit falls unconscious immediately and doesn't wake up alone without proper treatment, _time variable not needed in this case

// if wounds is not enabled then the unit will fall unconscious if _uncon = true

private ["_dam", "_uncon", "_time", "_st", "_check", "_pd", "_fsm", "_dexit", "_isp", "_bdam", "_ndam"];

PARAMS_2(_unit,_dam);

if (!local _unit) exitWith {};

_isp = isPlayer _unit;

_dexit = false;
if (!isNil "ace_wounds_prevtime" && {_isp}) then {
	_dam = MAX_PMR_DAM min _dam;
} else {
	if (_dam >= 1) then {_unit setDamage 1;_dexit = true};
};
if (_dexit) exitWith {};

_uncon = _this select 2;
_time = _this select 3;

_st = _unit getVariable "ace_w_state";
if (isNil "_st") then {_unit setVariable ["ace_w_state", 0];_st = 0;};

if (isNil "ace_sys_wounds_enabled") exitWith {
	[_unit, _dam] call FUNC(setDamage);
	_st = _unit getVariable "ace_w_carry";
	if (isNil "_st") then {_unit setVariable ["ace_w_carry", objNull]};
	if (_uncon) then {
		if (vehicle _unit == _unit) then {
			[_unit, 100] call FUNC(animator2);
		};
		_unit setVariable [QGVAR(uncon), true];
		_unit setVariable ["ace_w_unconlen", time + _time];
		if (isPlayer _unit) then {
			[true] spawn FUNC(blackoutp);
		} else {
			[_unit,true] spawn FUNC(blackoutai);
		};
	};
};

// TODO: Check overlapping code; blackoutall
if (isNil {_unit getVariable "ace_w_initialized"}) then {_unit call FUNC(unitinit)};
_bdam = _unit getVariable (GVAR(parts) select 1);
if (_dam > _bdam) then { _bdam = _dam };

// First setDamage, then setHit, so the visual wounds are okay.
if (damage _unit < _bdam) then {
	_ndam = if ((!isNil "ace_wounds_prevtime") && {_isp}) then {
		MAX_PMR_DAM min _bdam;
	} else {
		_bdam; // body
	};
	_unit setDamage _ndam;
	_unit setVariable ["ace_w_overall", _ndam];
};

if (!alive _unit) exitWith {};

{
	private "_pd";
	_pd = _unit getVariable (GVAR(parts) select _x);
	TRACE_2("headbody",_unit,_pd);
	if (_pd < _dam) then {
		[_unit, _x, _dam] call FUNC(setHit);
	};
} forEach [0, 1];
{
	private "_pd";
	_pd = _unit getVariable (GVAR(parts) select _x);
	TRACE_2("handslegs",_unit,_pd);
	if (_pd < (_dam * 2)) then {
		[_unit, _x, _dam * 2] call FUNC(setHit);
	};
} forEach [2, 3];

if (!alive _unit) exitWith {};

if (_isp) then {[_unit, _dam] call FUNC(addStamina)};

if (_st != 802) then {
	switch (true) do {
		case (_dam < STATE_800_HEAD_BODY_DAM_MAX && {_dam > 0}): {
			[_unit, STATE_800_BLOSS_ADD, STATE_800_PAIN_ADD, 0] call FUNC(vchange);
			if (_st <= 800) then {
				_unit setVariable ["ace_w_state", 800];
			};
		};
		case (_dam < STATE_801_HEAD_BODY_DAM_MAX && {_dam >= STATE_800_HEAD_BODY_DAM_MAX}): {
			[_unit, STATE_801_BLOSS_ADD, STATE_801_PAIN_ADD, 0] call FUNC(vchange);
			if (_st <= 801) then {
				_unit setVariable ["ace_w_nextuncon", time];
				_unit setVariable ["ace_w_state", 801];
			};
		};
		case (_dam >= STATE_801_HEAD_BODY_DAM_MAX): {
			[_unit, STATE_802_BLOSS_ADD, STATE_802_PAIN_ADD, 1] call FUNC(vchange);
			if (_st <= 802) then {
				_unit setVariable ["ace_w_unconlen", time + MAX_UNC_TIME];
				_unit setVariable ["ace_w_state", 802];
			};
		};
	};
	_fsm = _unit getVariable ["ace_w_fsm", 0];
	if (_fsm == 0) then {
		_unit setVariable ["ace_w_fsm",1];
		[_unit] spawn FUNC(statehandler);
	};
};
