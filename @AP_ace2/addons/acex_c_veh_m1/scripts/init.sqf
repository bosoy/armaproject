// New init script by zGuba

#include "\x\acex\addons\c_veh_m1\script_component.hpp"

PARAMS_1(_tank);

private ["_stuff","_panc","_markings"];

// Initialize stuff.sqf
_stuff = [_tank, "random"];
_stuff spawn COMPILE_FILE(scripts\stuff);

// Initialize panc.sqf
// TODO: store array elements in vehicle config
_panc = if (_tank isKindOf "ACE_M1A1HC_DESERT") then {
	[_tank, 'hide', 'unhide', 'unhide']
} else {
	[_tank, "unhide", "unhide", "hide"]
};
_panc spawn COMPILE_FILE(scripts\panc);

// Initialize markings.sqf
// TODO: store array elements in vehicle config
_markings = if (_tank isKindOf "ACE_M1A1HC_DESERT") then {
	[_tank, "random", "random", "random", "random", "empty", "empty", "00", "01"] 
} else {
	[_tank, 'random', 'random', 'random', 'random', '00', '00', '00', '01']
};

_markings spawn COMPILE_FILE(scripts\markings);
