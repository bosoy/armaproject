#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP(fired);
PREP(firedPFH);
PREP(injure);

[QGVAR(handle_injure), {
	{if (local (_x select 0)) then {[_x select 0,_x select 1,_this select 1] spawn ace_sys_thermobaric_fnc_injure}} foreach (_this select 0);
}] call CBA_fnc_addEventHandler;

ADDON = true;