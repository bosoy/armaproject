/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */
// _this (c) by Xeno
// Gathers the medical state of a person (patient).
// If the caller is not local, then send the patient's medical state via a networked answer variable back to the caller.
// Exec: local to receiver (patient)

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_receiver", "_sender", "_ruckmags"];
PARAMS_2(_receiver,_sender);

TRACE_2("Examine unit",_receiver,_sender);

if (!local _receiver) exitWith {};

_ruckmags = [];
{
	if ([configFile >> "CfgMagazines" >> (_x select 0) , configFile >> "CfgMagazines" >> "ACE_Banadage"] call CBA_fnc_inheritsFrom) then {
		_ruckmags set [count _ruckmags, _x select 0];
	};
} forEach ([_receiver] call ACE_fnc_RuckMagazinesList);
TRACE_1("",_ruckmags);

private "_answer";
// not final
_answer = [
	_sender,
	_receiver,
	_receiver getVariable "ace_w_state",
	_receiver getVariable "ace_w_epi", 
	_receiver getVariable "ace_w_bleed",
	_receiver getVariable "ace_w_pain", 
	_receiver getVariable "ace_w_wakeup",
	[_receiver] call FUNC(getDamage), 
	_receiver getVariable ["ace_w_healing_r", false],
	[_receiver] call FUNC(canHeal),
	_receiver getVariable "ace_w_bleed_add",
	_receiver getVariable ["ace_w_stabilizing_r", false],
	_ruckmags,
	_receiver getVariable ["ace_w_mor_dosage",0],
	_receiver getVariable ["ace_w_cat",false]
];
//	_receiver getVariable "ace_w_head_hit", _receiver getVariable "ace_w_body",
//	_receiver getVariable "ace_w_legs", _receiver getVariable "ace_w_head_hands"

TRACE_1("",_answer);

[QGVAR(examansw), _answer] call ACE_fnc_receiverOnlyEvent;
