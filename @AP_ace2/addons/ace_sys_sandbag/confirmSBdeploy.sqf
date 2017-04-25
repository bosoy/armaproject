/* ace_sys_sandbag (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"

_confirmSB = (_this select 3) select 0;
GVAR(height_exploit) = false;

_ex = [_confirmSB] execFSM QPATHTO_C(heightExploit.fsm);
waitUntil { GVAR(height_exploit) };

if ((_this select 0) getVariable QGVAR(exploit)) then {
	(_this select 0) setVariable [QGVAR(confirmed), false];
	[localize "STR_ACE_CANNOTSB",[1,0,0,1],true,1] spawn ace_fnc_visual;
} else {
	(_this select 0) setVariable [QGVAR(confirmed), true];
};
