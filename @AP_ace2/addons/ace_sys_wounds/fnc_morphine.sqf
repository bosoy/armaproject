/* ace_sys_wounds(.pbo)  */
#include "script_component.hpp"

// _this (c) by Xeno

closeDialog 0;

private ["_receiver", "_state", "_allowed"];
PARAMS_2(_receiver,_state);

TRACE_1("Morphine", _receiver);

if (!alive player) exitWith {};

if (!alive _receiver) exitWith {
	hintSilent format [localize "STR_ACE_WOUNDS_XDEAD", name _receiver];
};

_isUncon = _receiver call ace_sys_wounds_fnc_isUncon;

if (_isUncon) then {
	_allowed = [_receiver, player, MOR] call FUNC(takeItem);
	if (_allowed) then {
		player setVariable ["ace_w_busy",true];
		player setVariable ["ACE_PB_Result", 0];
		_delay = if ([player] call FUNC(isMedic)) then { 12 } else { 15 };
		[_delay,[localize "STR_ACE_UA_USEMORPHI"],false,true,player,true] spawn ace_progressbar;
		playSound "ACE_Injector";
		waitUntil { (player getVariable "ACE_PB_Result" != 0) };
		if (player getVariable "ACE_PB_Result" == 1) then {
			[_receiver, 1] call FUNC(animator2);
			[MOR,player] call FUNC(litter);
		};	
	};
} else {
	_action = "morphine";
	ace_sys_interaction_confirmed = nil;
	if (!isNil "ace_sys_interaction_inProgress" && {ace_sys_interaction_inProgress}) exitWith {};
	ace_sys_interaction_inProgress = true;
	private "_endtime";
	if (isPlayer _receiver) then {
		TRACE_1("Reqesting  action","");
		[QUOTE(ace_sys_interaction_confirmation), [_receiver, player, -1, _action]] call ACE_fnc_receiverOnlyEvent;
		_endtime = time + 8;
	} else {
		TRACE_1("Requesting action from AI","");
		ace_sys_interaction_confirmed = true;
		_endtime = time + MAX_UNC_TIME;
	};	
	sleep 0.5;
	waitUntil { !isNil QUOTE(ace_sys_interaction_confirmed) || {time > _endtime} };
	sleep 0.5;
	
	if (!isNil QUOTE(ace_sys_interaction_confirmed)) then {
		switch (ace_sys_interaction_confirmed) do {
			case true: {
				GVAR(icantouchu) = true;
			};
			case false: {
				GVAR(icantouchu) = false;
			};
		};
	};

	ace_sys_interaction_inProgress = false;	
	
	if !(GVAR(icantouchu)) exitWith {};
	
	[player, player, MOR] call FUNC(takeItem);

	player setVariable ["ace_w_busy",true];
	player setVariable ["ACE_PB_Result", 0];
	_delay = if ([player] call FUNC(isMedic)) then { 12 } else { 15 };
	[_delay,[localize "STR_ACE_UA_USEMORPHI"],false,true,player,true] spawn ace_progressbar;
	playSound "ACE_Injector";
	waitUntil { (player getVariable "ACE_PB_Result" != 0) };
	if (player getVariable "ACE_PB_Result" == 1) then {
		[_receiver, 1] call FUNC(animator2);
		[MOR,player] call FUNC(litter);
	};
};

player setVariable ["ace_w_busy",false];
false
