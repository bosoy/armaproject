/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */

// _this (c) by Xeno

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_receiver,_sender,_state);

if (_receiver != player) exitWith {};
if (!alive player) exitWith {};

if ((_state select 0) == -1) exitWith {
	hintSilent (localize "STR_ACE_DOGNOBODY"); 	// "I seem to cannot find his dogtag"
};

_this spawn FUNC(dogtagAnsw);

false
