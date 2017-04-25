#include "script_component.hpp"

if (GVAR(burnHelp)) exitWith {}; // Busy

PARAMS_2(_unit,_helper);
_unitBurns = [_unit] call ACE_fnc_isBurning;
if !(_unitBurns) exitWith { hintSilent (localize "STR_ACE_WOUNDS_NOTBURNING"); };

GVAR(burnHelp) = true; // I'm busy!

hintSilent (localize "STR_ACE_WOUNDS_TRYINGPUTOUT");
// TODO: Action! Can't come to close to the dude or we catch fire ourselves ;D

sleep (4 + (random 3));
if (random 100 < 33) then {
	[QGVAR(burnoff), _unit] call CBA_fnc_globalEvent;
	hintSilent (localize "STR_ACE_WOUNDS_TRYINGPUTOUTSUCCESS");
} else {
	hintSilent (localize "STR_ACE_WOUNDS_TRYINGPUTOUTFAIL");
};

GVAR(burnHelp) = false; // I'm no longer busy!
