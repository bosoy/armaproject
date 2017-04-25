/* ----------------------------------------------------------------------------
Function: ACE_fnc_clientToServerEvent

Description:
	Raises an ACE event only on the server (only broadcasted to server and not to other clients)

Parameters:
	_eventType - Type of event to publish [String].
	_params - Parameters to pass to the event handlers [Array].

Returns:
	nil

Author:
	Xeno
---------------------------------------------------------------------------- */

#include "script_component.hpp"

if (isServer) then { // for hosted environment
	_this call FUNC(NetRunEventCTS);
} else {
	GVAR(ncts) = _this;
	publicVariableServer QGVAR(ncts);
};