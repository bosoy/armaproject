#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP(hasropemag);

PREP(attachSlingRopeToHelicopter);
PREP(attachSlingRopeToCargo);
PREP(detachSlingRopeFromCargo);

[QGVAR(lock), { PARAMS_2(_unit,_lock); _unit lock _lock } ] call CBA_fnc_addEventhandler;

ADDON = true;
