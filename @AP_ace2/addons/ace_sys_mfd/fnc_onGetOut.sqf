#include "script_component.hpp"

GVAR(currentDialogClass) = nil;

if !(isNil QGVAR(currentDialog)) then {
	[] call FUNC(closeDialog);
	[] call FUNC(resetState);
};
