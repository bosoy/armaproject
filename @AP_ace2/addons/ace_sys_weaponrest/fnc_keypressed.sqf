#include "script_component.hpp"

#define __stand ["amovpercmstpsraswrfldnon", "aidlpercmstpsraswrfldnon_aiming01", "aidlpercmstpsraswrfldnon_idlesteady01", "aidlpercmstpsraswrfldnon_idlesteady02", "aidlpercmstpsraswrfldnon_idlesteady03", "aidlpercmstpsraswrfldnon_idlesteady04", "aidlpercmstpsraswrfldnon_aiming02"]
#define __kneel ["amovpknlmstpsraswrfldnon", "aidlpknlmstpsraswrfldnon_player_idlesteady01", "aidlpknlmstpsraswrfldnon_player_idlesteady02", "aidlpknlmstpsraswrfldnon_player_idlesteady03", "aidlpknlmstpsraswrfldnon_player_idlesteady04"]
#define __prone ["amovppnemstpsraswrfldnon"]

private ["_r"];
TRACE_1("",_this);
_r = false;
if (scriptDone GVAR(key_pid)) then {
	if ( (animationstate player) in (__stand + __prone + __kneel) ) then {
		GVAR(key_pid) = [animationstate player] spawn FUNC(check);
		_r = true; // Cannot properly implement because of required spawn, sleeps etc. etc.
	};
};

_r;
