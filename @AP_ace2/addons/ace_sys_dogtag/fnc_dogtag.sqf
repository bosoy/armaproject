/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

//closeDialog 0; // temp code for transition stage

private "_receiver";
PARAMS_1(_receiver);

TRACE_1("dogtag", _receiver);

if (!alive player) exitWith {};

[QGVAR(dogtagUnit), [_receiver, player]] call ACE_fnc_receiverOnlyEvent;

false
