#include "script_component.hpp"

disableSerialization;

uiNamespace setVariable [QGVAR(currentDialog), _this select 0];

GVAR(currentDialog) = _this select 1;

[] spawn FUNC(renderDisplay);
