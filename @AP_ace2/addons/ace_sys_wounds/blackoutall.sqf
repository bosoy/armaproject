//#define DEBUG_MODE_FULL

#include "script_component.hpp"

private ["_unit", "_time", "_st", "_check", "_iss", "_fsm", "_xdam", "_isp", "_bdam", "_ndam"];

PARAMS_2(_unit,_time);

if (!local _unit) exitWith {};

_isp = isPlayer _unit;

_st = _unit getVariable "ace_w_state";
if (isNil "_st") then {_unit setVariable ["ace_w_state", 0]};
if (isNil "ace_sys_wounds_enabled") then {
	if (isNil {_unit getVariable "ace_w_carry"}) then {_unit setVariable ["ace_w_carry", objNull]};
	if (vehicle _unit == _unit) then {
		[_unit, 100] call FUNC(animator2);
	};
	_unit setVariable [QGVAR(uncon), true];
	_unit setVariable ["ace_w_unconlen", time + _time]; // bleeding and pain
	if (_isp) then {
		[true] spawn FUNC(blackoutp);
	} else {
		[_unit,true] spawn FUNC(blackoutai);
	};
} else {
	// TODO: Check overlapping code; setw
	if (isNil {_unit getVariable "ace_w_initialized"}) then {_unit call FUNC(unitinit)};
	if !(_unit call FUNC(isUncon)) then {
		if (vehicle _unit == _unit) then {
			[_unit, 100] call FUNC(animator2);
		};
		_unit setVariable [QGVAR(uncon), true, true];
		if (_time != -1) then { // time = -1 unit will stay in uncon mode until a medic treats it
			_iss = _unit getVariable "ace_w_state";
			if (_iss < 801) then {
				[_unit, STATE_801_BLOSS_ADD, STATE_801_PAIN_ADD, 0] call FUNC(vchange);
				_unit setVariable ["ace_w_nextuncon", time];
				_unit setVariable ["ace_w_unconlen", time + _time]; // bleeding and pain
				_unit setVariable ["ace_w_state", 801];
			} else {
				if (_iss == 801) then {
					_unit setVariable ["ace_w_unconlen", time + _time];
				};
			};
			_xdam = 0.2;
		} else {
			_iss = _unit getVariable "ace_w_state";
			if (_iss < 802) then {
				[_unit, STATE_802_BLOSS_ADD, STATE_802_PAIN_ADD, 1] call FUNC(vchange);
				_unit setVariable ["ace_w_unconlen", time + MAX_UNC_TIME];
				_unit setVariable ["ace_w_state", 802];
			};
			_xdam = 0.4;
		};

		_bdam = _unit getVariable (GVAR(parts) select 1);
		if (_xdam > _bdam) then { _bdam = _xdam };

		if (damage _unit < _bdam) then {
			_ndam = if (!isNil "ace_wounds_prevtime" && {_isp}) then {
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
			if (_pd < _xdam) then {
				_unit setVariable [GVAR(parts) select _x, _xdam];
			};
		} forEach [0, 1];
		{
			private "_pd";
			_pd = _unit getVariable (GVAR(parts) select _x);
			TRACE_2("handslegs",_unit,_pd);
			if (_pd < (_xdam * 2)) then {
				_unit setVariable [GVAR(parts) select _x, _xdam * 2];
			};
		} forEach [2, 3];

		if (!alive _unit) exitWith {};
		
		_knock = (_unit getVariable "ace_w_state") == 801;
		if (_isp) then {
			[_knock] spawn FUNC(blackoutp);
		} else {
			[_unit,_knock] spawn FUNC(blackoutai);
		};

		_fsm = _unit getVariable ["ace_w_fsm", 0];
		if (_fsm == 0) then {
			_unit setVariable ["ace_w_fsm",1];
			[_unit] spawn FUNC(statehandler);
		};
	};
};
