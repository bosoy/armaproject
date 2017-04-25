#include "script_component.hpp"

LOG(MSG_INIT);

if !(isNil "ace_sys_menu") exitWith {};

CREATELOGICGLOBALTEST;
SETVAR ["config_group", false, true];
SETVAR ["config_config", true, true];

// TODO: Move to specific addons
SETVAR ["config_laser", true, true];
SETVAR ["config_character", false, true];
SETVAR ["config_weapons", false, true];
SETVAR ["config_teamstatus", false, true];
//SETVAR ["set", true, true];
