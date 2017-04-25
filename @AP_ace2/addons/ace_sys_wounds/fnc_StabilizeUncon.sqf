/* ace_sys_wounds(.pbo) - fnc_StabilizeUncon.sqf | (c) 2012, 2013 by rocko */
#include "script_component.hpp"

PARAMS_1(_unit);
_isp = isPlayer _unit;

switch (_unit getVariable "ace_w_state") do {
	case 800: {}; // Nothing
	// Stabilize only in state 801:
	// Prevent overdosage of Epinephrine
	// If going uncon from time to time due to pain, we have the possibility to 'remove' player from that state by 
	// Stabilizing him
	case 801: {
		// If player is going unconscious due to bleeding - bad luck
		// Stabilizing will only relief some pain
		if (_unit getVariable "ace_w_bleed" < SH_STATE_800_MAX_BLEED) then {
			// Make pain relief
			_curPain = _unit getVariable "ace_w_pain";
			_newPain = _curPain / 2;
			// Reduce pain while being stabilized
			_curPainAdd = _unit getVariable "ace_w_pain_add";
			_newPainAdd = _curPainAdd / 1.5;
			_unit setVariable ["ace_w_pain", _newPain];
			_unit setVariable ["ace_w_pain_add", _newPainAdd];
			// PMR
			//if (!(isNil "ace_wounds_prevtime") && _isp) then {	
			//	_unit setVariable ["ace_w_revive", -1];
			//};
			// Push down to a previous state
			_unit setVariable ["ace_w_state", 800];
			// If unit is currently unconscious, make him wake up
			if (_unit getVariable QGVAR(uncon)) then {
				_unit setVariable [QGVAR(uncon), false, true];
			};
			// Remove the need for epinephrine, per time being
			_unit setVariable ["ace_w_epi", 0];			
			if (_isp) then {[_unit, 2] call FUNC(divStamina)};
		};
	};
	case 802: {}; // Nothing, yet
};
