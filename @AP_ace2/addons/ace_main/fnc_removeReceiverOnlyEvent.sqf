/* ----------------------------------------------------------------------------
Function: ACE_fnc_removeReceiverOnlyEvent

Description:
	Removes an event handler previously registered with ACE_fnc_addReceiverOnlyEventhandler.

Parameters:
	_eventType - Type of event to remove [String].

Returns:
	nil

Author:
	Xeno
---------------------------------------------------------------------------- */

#include "script_component.hpp"

if (!isNil {GVAR(event_holderToR) getVariable _this}) then {GVAR(event_holderToR) setVariable [_this, nil]};
