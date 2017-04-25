/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */

// _this (c) by Sickboy

#include "script_component.hpp"

PARAMS_4(_receiver,_sender,_answer,_action);

private["_busy"];
_busy = _receiver getVariable ["ace_sys_interaction_busy", false];

if (_busy) exitWith { (localize "STR_ACE_CALL_WAIT") spawn ace_fnc_visual; false; };

switch _answer do {
	// Maintenance
	case -2: {
		if (_receiver == player) then {
			_receiver removeAction GVAR(yes);
			_receiver removeAction GVAR(no);
		};
	};
	// Requesting
	case -1: {
		//LOG(format["Sent request -- Sender: %1 - Receiver: %2", _sender,_receiver]);
		if (_receiver == player) then {
			GVAR(sender) = _sender;
			[_receiver,_sender,_action] spawn FUNC(answer);
		};
	};
	// Negative answer
	case 0: {
		// Roles have switched here, _receiver is now _sender from before
		if (_receiver == player) then {
			GVAR(confirmed) = false;
		};
	};
	// Positive answer
	case 1: {
		if (_receiver == player) then {
			GVAR(confirmed) = true;
		};
	};
	// Calling unit out of range
	case 69: {
		if (_receiver == player) then {
			switch (_action) do {
				case "friendly": {
					_sender sidechat format [localize "STR_ACE_CALL_CALLFRIENDLY", name _receiver];
					_sender playActionNow (["GestureHi","GestureHiB","GestureHiC"] select (round(random 2)));
					format[localize "STR_ACE_CALL_WANTSOME", name _sender] spawn ace_fnc_visual;
				};
				case "enemy": {
					_sender globalchat (localize "STR_ACE_CALL_CALLHOSTILE");
					_sender playActionNow "GestureFollow";
					(localize "STR_ACE_CALL_X_WANTSOME") spawn ace_fnc_visual;
				};
			};
		};
	};
	// Tap shoulder
	case 70: {
		if (_receiver == player) then {
			format[localize "STR_ACE_CALL_X_TAPSHOULDER", name _sender] spawn ace_fnc_visual;
			// Shake
			[_receiver,0.1] spawn ace_fx_fnc_kick;
		};
	};
};

false
