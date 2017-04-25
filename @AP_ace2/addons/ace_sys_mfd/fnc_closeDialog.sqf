#include "script_component.hpp"

if !(isNil QGVAR(currentDialog)) then {
	// override the rsc?
	DISPLAY_ID cutFadeOut 0.1;
};
GVAR(currentDialog) = nil;

// remove the override key handler
(findDisplay 46) displayRemoveEventHandler ["KeyDown", GVAR(KeyPressHandler)];
GVAR(KeyPressHandler) = nil;