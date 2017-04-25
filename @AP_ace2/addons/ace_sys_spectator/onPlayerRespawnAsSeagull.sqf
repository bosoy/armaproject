#include "script_component.hpp"
if (isNil "ACE_referee") then { ACE_referee = false };
if (isNil "ACE_NOSPECT") then { ACE_NOSPECT = false };

// Check if ACE_referee
if (ACE_referee) then {
	// Launch Troopmon when ACE_Referee_mon is defined, else spectator
	if (isNil "ACE_referee_mon") then { _this spawn COMPILE_FILE(specta) } else { [] spawn COMPILE_FILE2_SYS("CHN_TroopMon\scripts\MonInit.sqf") };
} else {
	// If not, run spectator if ACE_NOSPECT is NOT defined
	if !(ACE_NOSPECT) then { _this spawn COMPILE_FILE(specta) };
};
