//#define DEBUG_MODE_FULL
#include "script_component.hpp"

scopeName "script_out";
PARAMS_2(_target,_caller);
private ["_weight", "_lock", "_text", "_fnc_text", "_fnc_locked", "_cont", "_max_time", "_can_continue"];

//if ( ! alive _target ) exitWith { LOG("Target Dead") };

//local functions
_fnc_text = {
    PARAMS_1(_status);
    private["_text"];
    _text = format[
        "%1 %2 %3 (%4)",
        [_weight, 1, 0, true] call CBA_fnc_formatNumber,
        localize "STR_ACE_SYS_RUCK_KILOGRAM",
        localize "STR_DN_ACE_RUCKSACK",
        _status
    ];
    _text spawn ace_fnc_visual;
};

_fnc_locked = {
    [toLower(localize "STR_DN_ACE_RUCK_LOCKED")] call _fnc_text;
};
//end local functions

_weight = _target call FUNC(GearWeight);

if (alive _target) then {
	_lock = _target getVariable ["ACE_Ruck_Lock","Team"];
	switch _lock do {
		case "": {
			// TODO: Use confirmation system from sys_interaction
			call _fnc_locked;
			breakOut "script_out";
		};
		case "Squad": {
			if ( (group _caller) != (group _target) ) then { call _fnc_locked; breakOut "script_out"; };
		};
		case "Team": {
			if ( (side (group _target)) getFriend (side (group _caller)) < 0.6 ) then { call _fnc_locked; breakOut "script_out"; };
		};
		default {
			[localize "STR_ACE_SYS_RUCK_BUSY"] call _fnc_text;
			breakOut "script_out";
		};
	};
};

[(localize "STR_ACE_SYS_RUCK_OPENING") + "..."] call _fnc_text;

// request and wait for broadcast of ruck contents
[QGVAR(RuckNet), [_target, _caller]] call ACE_fnc_receiverOnlyEvent;
_max_time = time + 10;
_c_name = name _caller;
waitUntil { sleep 0.2; time > _max_time || {( ! isNil {_target getVariable "ACE_RuckContents_Net"} && {_c_name == (_target getVariable ["ACE_Ruck_Lock","Team"])} )} };
if ( time < _max_time ) then {
    _cont = _target getVariable "ACE_RuckContents_Net";
    GVAR(Ruck_Target) = _target;
    // do gear interaction
    [_caller, _cont select 0, _cont select 1] call FUNC(TmpGear);
} else {
    LOG("Timer expired or another player beat you to accessing ruck.");
};
