// #define DEBUG_MODE_FULL
#include "script_component.hpp"

// if ((_this select 0) getVariable ["ace_w_healing_r", false]) exitWith {}; // already getting healed
(_this select 0) setVariable ["ace_w_healing_r", true];
_this spawn {
	PARAMS_2(_unit,_timeOut);
	_timeOut = time + _timeOut;
	_anim = "ainjppnemstpsnonwrfldnon"; // OnBack
	_anim2 = "amovppnemstpsraswrfldnon"; // Normal

	TRACE_4("",time,_timeOut,_anim,_anim2);
	
	// TODO: Improve this??
	while {alive _unit && {(_unit getVariable ["ace_w_healing_r", false])} && {(time < _timeOut)}} do {
		if !(_unit call FUNC(isUncon)) then {
			TRACE_1("Is con",_unit);
			_unit playMoveNow _anim; // lay down on the ground!
			_wt = time + 4;
			waitUntil { (animationState _unit == _anim) || {!alive _unit} || {time > _wt} || {(time > _timeOut)}};
			_wt = time + 4;
			waitUntil { (animationState _unit != _anim) || {!alive _unit} || {time > _wt}};
			if (alive _unit && {!(_unit call FUNC(isUncon))}) then { _unit playMoveNow _anim2 };
		} else {
			TRACE_1("Is uncon",_unit);
		};
		sleep 1;
	};
	_unit setVariable ["ace_w_healing_r", false];
	TRACE_2("Exit",_unit, animationState _unit);
};
