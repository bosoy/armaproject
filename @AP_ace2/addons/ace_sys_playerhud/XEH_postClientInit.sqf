#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

0 spawn COMPILE_FILE(dohud);

if (!isNil "ace_sys_playerhud_force1st") then {
	execFSM QPATHTO_C(3rdperson.fsm);
};

if (!isNil "ace_sys_playerhud_withresp" && {isMultiplayer}) then {
	TRACE_1("",ace_sys_playerhud_withresp);
	#define __pSetVar player setVariable
	#define __pGetVar(pvarname) (player getVariable #pvarname)
	if ("ACE_Earplugs" in items player) then {
		__pSetVar [QGVAR(earwear), true];
	} else {
		__pSetVar [QGVAR(earwear), false];
	};
	0 spawn {
		while {true} do {
			if (alive player) then {
				if (!__pGetVar(GVAR(earwear))) then {
					if ("ACE_Earplugs" in items player || {__pGetVar(ACE_EarWear)}) then {
						__pSetVar [QGVAR(earwear), true];
					};
				} else {
					if (__pGetVar(GVAR(earwear)) && {!("ACE_Earplugs" in items player)} && {!__pGetVar(ACE_EarWear)}) then {
						__pSetVar [QGVAR(earwear), false];
					};
				};
			};
			sleep 0.5;
		};
	};
	
	0 spawn {
		waitUntil {!isNull player};
		TRACE_1("Adding eventhandlers",objNull);
		player addEventHandler ["killed", {[0] call FUNC(playerspawn)}];
		player addEventHandler ["respawn", {[1, _this] call FUNC(playerspawn)}];
	};
};

ADDON = true;
