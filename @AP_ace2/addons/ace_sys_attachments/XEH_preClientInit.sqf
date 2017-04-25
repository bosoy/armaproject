#include "script_component.hpp"
/* ace_sys_attachments - by Sickboy (sb_at_dev-heaven.net)
 * Status: Alpha
*/

LOG(MSG_INIT);

// Announce start of initialization
ADDON = false;

GVAR(available) = [];
GVAR(available_Pistol) = [];
GVAR(cqb) = [];
GVAR(key_pid) = [] spawn {};

// Load functions
PREP(keyPressed);
PREP(weapon);
PREP(weaponCQB);
PREP(switchWep);


[QUOTE(ADDON), "cqb", { _this call FUNC(keyPressed)}] call CBA_fnc_addKeyHandlerFromConfig;

// Announce succesful initialization
ADDON = true;
