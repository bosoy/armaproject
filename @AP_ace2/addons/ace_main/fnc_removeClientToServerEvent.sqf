/* ----------------------------------------------------------------------------
Function: ACE_fnc_removeClientToServerEvent

Description:
	Removes an event handler previously registered with ACE_fnc_addClientToServerEventhandler.

Parameters:
	_eventType - Type of event to remove [String].

Returns:
	nil

Author:
	Xeno
---------------------------------------------------------------------------- */

#include "script_component.hpp"

if (!isNil {GVAR(event_holderCTS) getVariable _this}) then {GVAR(event_holderCTS) setVariable [_this, nil]};
