#include "script_component.hpp"

private ["_bleed","_sleep"];
player setVariable ["ace_w_bleed", 0];
player setVariable [QGVAR(uncon), false];
sleep 5;
if (isNil "ace_sys_wounds_enabled") exitWith {};
while {true} do {
	waitUntil {alive player};
	if (isNil "ace_sys_wounds_enabled") exitWith {};
	sleep 1;
	while {alive player} do {
		waitUntil {(player getVariable "ace_w_bleed") >= 0.1 || {!alive player} || {(player call FUNC(isUncon))}};
		if (!alive player || {(player call FUNC(isUncon))}) exitWith {};
		while {(player getVariable "ace_w_bleed" >= 0.1) && {alive player} && {!(player call FUNC(isUncon))}} do {
			_bleed = player getVariable "ace_w_bleed";
			135863 cutRsc ["Default", "PLAIN"];
			switch (true) do {
				case (_bleed <= 0.2): {
					135863 cutRsc["ACE_Wound_Bleeding1","PLAIN"];
					_sleep = 3;
				};
				case (_bleed <= 0.3 && {_bleed > 0.2}): {
					135863 cutRsc["ACE_Wound_Bleeding2","PLAIN"];
					_sleep = 2.5;
				};
				case (_bleed <= 0.5 && {_bleed > 0.3}): {
					135863 cutRsc["ACE_Wound_Bleeding3","PLAIN"];
					_sleep = 1.9;
				};
				case (_bleed <= 0.6 && {_bleed > 0.5}): {
					135863 cutRsc["ACE_Wound_Bleeding4","PLAIN"];
					_sleep = 1.5;
				};
				case (_bleed > 0.6): {
					135863 cutRsc["ACE_Wound_Bleeding5","PLAIN"];
					_sleep = 1.1;
				};
			};
			sleep _sleep;
		};
	};
	if (!alive player || {(player call FUNC(isUncon))}) then {
		if (!alive player) then {
			player setVariable ["ace_w_bleed", 0];
			sleep 1;
		} else {
			waitUntil {!(player call FUNC(isUncon)) || {!alive player}};
			sleep 1;
		};
	};
};