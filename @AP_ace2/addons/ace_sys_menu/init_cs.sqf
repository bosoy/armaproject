#include "script_component.hpp"

ace_sys_menu_cs_CS = []; ace_sys_menu_cs_GROUPS = [];
ace_sys_menu_cs_PID = [] spawn {}; // Bogus pid creation

"ace_sys_menu_cs_CS" addPublicVariableEventHandler { if (scriptDone ace_sys_menu_cs_PID) then { [] spawn ace_sys_menu_fnc_update } };

PREP(setGroupCS);
PREP(update);
PREP(getCs);
