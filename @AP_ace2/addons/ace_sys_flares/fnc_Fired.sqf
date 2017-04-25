//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __EXCLUDE_SLOWDESCENT ["F_HuntIR","ACE_IRStrobe","ACE_M86PDM","ACE_SS_White","ACE_SS_Green","ACE_SS_Red","ACE_SS_Yellow"]
#define __EXCLUDE_VISIBLEFLARE ["F_HuntIR","ACE_F_40mm_IR","ACE_IRStrobe","ACE_M86PDM"]

// Increase flight time
if (getNumber(configFile >> "CfgAmmo" >> _this select 4 >> QGVAR(SLOW)) == 1) then {
	_this spawn FUNC(SlowDescent);
};

// Visible flare in daylight
if (getNumber(configFile >> "CfgAmmo" >> _this select 4 >> QGVAR(DAY)) == 1) then {
	[QGVAR(fired), _this] call CBA_fnc_globalEvent;
};
