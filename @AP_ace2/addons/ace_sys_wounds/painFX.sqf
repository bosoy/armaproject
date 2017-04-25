#include "script_component.hpp"

private "_pain";
player setVariable ["ace_w_pain", 0];
player setVariable [QGVAR(uncon), false];
sleep 5;
if (isNil "ace_sys_wounds_enabled") exitWith {};
while {true} do {
	waitUntil {alive player};
	if (isNil "ace_sys_wounds_enabled") exitWith {};
	sleep 1;
	while {alive player} do {
		waitUntil {sleep 0.123;(player getVariable "ace_w_pain") >= 0.1 || {!alive player} || {(player call FUNC(isUncon))}};
		if (!alive player || {(player call FUNC(isUncon))}) exitWith {};
		while {(player getVariable "ace_w_pain" >= 0.1) && {alive player} && {(!(player call FUNC(isUncon)))}} do {
			_st = time + 2.5;
			waitUntil {sleep 0.123;time > _st || {!alive player} || {(player call FUNC(isUncon))}};
			if (!alive player || {(player call FUNC(isUncon))}) exitWith {};
			_pain = player getVariable ["ace_w_pain", 0];
			_sleep_time = 0;
			switch (true) do {
				case (_pain <= 0.2): {
					GVAR(blur) ppEffectEnable true;
					GVAR(blur) ppEffectAdjust [0.2];
					GVAR(blur) ppEffectCommit 1;
					_sleep_time = 3;
				};
				case (_pain <= 0.3 && {_pain > 0.2}): {
					GVAR(blur) ppEffectEnable true;
					GVAR(blur) ppEffectAdjust [0.4];
					GVAR(blur) ppEffectCommit 1;
					_sleep_time = 3;
				};
				case (_pain <= 0.5 && {_pain > 0.3}): {
					GVAR(blur) ppEffectEnable true;
					GVAR(blur) ppEffectAdjust [0.6];
					GVAR(blur) ppEffectCommit 1;
					_sleep_time = 4;
				};
				case (_pain <= 0.6 && {_pain > 0.5}): {
					GVAR(blur) ppEffectEnable true;
					GVAR(blur) ppEffectAdjust [0.8];
					GVAR(blur) ppEffectCommit 1;
					_sleep_time = 4;
				};
				case (_pain > 0.6): {
					GVAR(blur) ppEffectEnable true;
					GVAR(blur) ppEffectAdjust [1];
					GVAR(blur) ppEffectCommit 1;
					_sleep_time = 4;
				};
			};
			_st = time + _sleep_time;
			waitUntil {sleep 0.123;time > _st || {!alive player} || {(player call FUNC(isUncon))}};
			GVAR(blur) ppEffectAdjust [0];
			GVAR(blur) ppEffectCommit 1;
			135869 cutRsc["ACE_Wound_Pain","PLAIN"];
			sleep 1;
			GVAR(blur) ppEffectEnable false;
			if (!alive player || {(player call FUNC(isUncon))}) exitWith {};
			_st = time + (8 + random 15);
			waitUntil {sleep 0.123;time > _st || {!alive player} || {(player call FUNC(isUncon))}};
			if (!alive player || {(player call FUNC(isUncon))}) exitWith {};
		};
	};
	if (!alive player || {(player call FUNC(isUncon))}) then {
		if (!alive player) then {
			player setVariable ["ace_w_pain", 0];
			sleep 1;
		} else {
			waitUntil {sleep 0.123;!(player call FUNC(isUncon)) || {!alive player}};
			sleep 1;
		};
	};
};