//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// --- THIS SCRIPT IS LOADED EARLY - BY ACE_MAIN XEH PRECLIENTINIT ---

// Ingame settings
// Userconfig can be used for default settings

// fallback
_inuins = uiNamespace getVariable QGVAR(settings);
if (isNil "_inuins") then {
	TRACE_1("executing initall","");
	call COMPILE_FILE2(\x\ace\addons\settings\initall.sqf);
};

missionNamespace setVariable [QUOTE(FUNC(getNumber)), uiNamespace getVariable QUOTE(FUNC(getNumber))];
missionNamespace setVariable [QUOTE(FUNC(getText)), uiNamespace getVariable QUOTE(FUNC(getText))];
missionNamespace setVariable [QUOTE(FUNC(getValue)), uiNamespace getVariable QUOTE(FUNC(getValue))];