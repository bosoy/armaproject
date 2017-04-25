#include "script_component.hpp"

GVAR(currentDialog) = nil;
GVAR(currentDialogClass) = nil;

GVAR(lastKeyPressTime) = 0;
GVAR(KeyPressHandler) = nil;

GVAR(lastKeyPressed) = "-1";

GVAR(currentState) = ["WPN"];
