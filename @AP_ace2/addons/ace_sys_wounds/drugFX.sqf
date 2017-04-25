/* ace_sys_wounds(.pbo) - fnc_drugFX.sqf | (c) 2012, 2013 by rocko */
#include "script_component.hpp"

private "_toxic";
sleep 5;
if (isNil "ace_sys_wounds_enabled") exitWith {};
while {true} do {
	waitUntil {alive player};
	if (isNil "ace_sys_wounds_enabled") exitWith {};
	sleep 1;
	while {alive player} do {
		waitUntil {sleep 0.123;(player getVariable "ace_w_mor_dosage") >= 3 || {!alive player} || {player call FUNC(isUncon)}};
		if (!alive player || {player call FUNC(isUncon)}) exitWith {};
		while {(player getVariable "ace_w_mor_dosage" >= 3) && {alive player} && {(!(player call FUNC(isUncon)))}} do {
			_st = time + 2.5;
			waitUntil {sleep 0.123;time > _st || {!alive player} || {(player call FUNC(isUncon))}};
			if (!alive player || {player call FUNC(isUncon)}) exitWith {};
			_toxic = player getVariable ["ace_w_mor_dosage", 0];
			_sleep_time = 0;
			if (time - (player getVariable ["ace_w_mor_time",time]) > MOR_DURATION) then {
				player setVariable ["ace_w_mor_dosage",0];
			};
			switch (true) do {
				case (_toxic == 3): {
					//TODO: Myosis pt.1 (narrowed pupils) -> similar to stamina fatigue overlay, just permanently, not so closed
					GVAR(mor_intox) ppEffectEnable true;
					GVAR(mor_intox) ppEffectAdjust [0, 0.1, 0, 0, 0.17, 0, 0, 0, 0.17, 0, 0, 0, 0, 1, 0];
					GVAR(mor_intox) ppEffectCommit 0;
					[player,30,0.01] call ace_fx_fnc_dizzy;
					_sleep_time = 30.1;
				};
				case (_toxic == 4): {
					//TODO: spasms (setdir back and forth)
					//TODO: Myosis pt.2 -> closed some more
					GVAR(mor_intox) ppEffectEnable true;
					GVAR(mor_intox) ppEffectAdjust [0, 0.1, 0, 0, 0.20, 0, 0, 0, 0.20, 0, 0, 0, 0, 1, 0];
					GVAR(mor_intox) ppEffectCommit 0;
					[player,30,0.02] call ace_fx_fnc_dizzy;
					_sleep_time = 30.1;
					// TODO: trembling
				};
				case (_toxic == 5): {
					GVAR(mor_intox) ppEffectEnable true;
					GVAR(mor_intox) ppEffectAdjust [0, 0.1, 0, 0, 0.25, 0, 0, 0, 0.25, 0, 0, 0, 0, 2, 0];
					GVAR(mor_intox) ppEffectCommit 0;
					[player,30,0.03] call ace_fx_fnc_dizzy;
					_sleep_time = 30.1;
				};
				case (_toxic == 6): {
					GVAR(mor_intox) ppEffectEnable true;
					GVAR(mor_intox) ppEffectAdjust [0, 0.1, 0, 0, 0.30, 0, 0, 0, 0.30, 0, 0, 0, 0, 2, 0];
					GVAR(mor_intox) ppEffectCommit 0;
					[player,30,0.045] call ace_fx_fnc_dizzy;
					_sleep_time = 30.1;
				};
				case (_toxic > 6): {
					GVAR(mor_intox) ppEffectEnable true;
					GVAR(mor_intox) ppEffectAdjust [0, 0.2, 0, 0, 0.34, 0, 0, 0, 0.34, 0, 0, 0, 0, 2.5, 0];
					GVAR(mor_intox) ppEffectCommit 0;
					[player,30,0.06] call ace_fx_fnc_dizzy;
					_sleep_time = 30.1;
				};				
			};
			_st = time + _sleep_time;
			waitUntil {sleep 0.123;time > _st || {!alive player} || {(player call FUNC(isUncon))}};
			GVAR(mor_intox) ppEffectAdjust [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
			GVAR(mor_intox) ppEffectCommit 1;
			sleep 1;
			GVAR(mor_intox) ppEffectEnable false; 
			if (!alive player || {(player call FUNC(isUncon))}) exitWith {};
			_st = time + (8 + random 15);
			waitUntil {sleep 0.123;time > _st || {!alive player} || {(player call FUNC(isUncon))}};
			if (!alive player || {(player call FUNC(isUncon))}) exitWith {};
		};
	};
	if (!alive player || {(player call FUNC(isUncon))}) then {
		if (!alive player) then {
			player setVariable ["ace_w_mor_dosage", 0];
			sleep 1;
		} else {
			waitUntil {sleep 0.123;!(player call FUNC(isUncon)) || {!alive player}};
			sleep 1;
		};
	};
};