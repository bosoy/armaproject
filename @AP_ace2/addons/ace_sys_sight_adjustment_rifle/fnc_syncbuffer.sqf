// avoids broadcasting new elev/windage for every click
// does so only after __SYNCDELAY seconds after last key press

#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
#define __SYNCDELAY 1

GVAR(clicktime) = time;
//if !(isMultiplayer) exitwith {};
if !(GVAR(listening)) then {
	GVAR(listening) = true;
	0 spawn {
		waituntil {(time - GVAR(clicktime) >= __SYNCDELAY)};
		call FUNC(setdegrees);
		GVAR(listening) = false;
	};
};