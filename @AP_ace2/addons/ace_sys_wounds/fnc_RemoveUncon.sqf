#include "script_component.hpp"

_this setVariable ["ace_w_epi", 0];
private "_isp";
_isp = isPlayer _this;

switch (_this getVariable "ace_w_state") do {
	case 801: {
		if ((_this getVariable "ace_w_bleed") == 0 && {(_this getVariable "ace_w_pain") == 0}) then {
			_this setVariable ["ace_w_state", 0];
			if (_this getVariable QGVAR(uncon)) then {
				_this setVariable [QGVAR(uncon), false, true];
			};
			if (!isNil "ace_wounds_prevtime" && {_isp}) then {
				_this setVariable ["ace_w_revive", -1];
			};
			if (_isp) then {[_this, 0] call FUNC(setStamina)};
		} else {
			// TODO: Do not artificially increase base values, those need to be treated by player
			if ((_this getVariable "ace_w_bleed") > 0) then {
				_this setVariable ["ace_w_bleed", 0.4];
				_this setVariable ["ace_w_bleed_add", STATE_801_BLOSS_ADD];
			};
			if ((_this getVariable "ace_w_pain") > 0) then {
				_this setVariable ["ace_w_pain", 0.4];
				_this setVariable ["ace_w_pain_add", STATE_801_PAIN_ADD];
			};
			_this setVariable ["ace_w_state", 800];
			_this setVariable [QGVAR(uncon), false, true];
			if (_isp) then {[_this, 2] call FUNC(divStamina)};
		};
	};
	case 802: {
		if ((_this getVariable "ace_w_bleed") == 0 && {(_this getVariable "ace_w_pain") == 0}) then {
			_this setVariable ["ace_w_state", 0];
			_this setVariable [QGVAR(uncon), false, true];
			if (!isNil "ace_wounds_prevtime" && {_isp}) then {
				_this setVariable ["ace_w_revive", -1];
			};
			if (_isp) then {[_this, 0] call FUNC(setStamina)};
		};
	};
};
