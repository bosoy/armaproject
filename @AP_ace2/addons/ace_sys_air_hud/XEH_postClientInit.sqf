//XEH_postClientInit.sqf
#include "script_component.hpp"

[QGVAR(syncBomb), {_this call FUNC(syncBomb)}] call CBA_fnc_addEventHandler;
[QUOTE(ADDON), "Pickle_Weapon", { _this call FUNC(keyboard_pickleWeaponDown)}, "keydown"] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Pickle_Weapon", { _this call FUNC(keyboard_pickleWeaponUp)}, "keyup"] call CBA_fnc_addKeyHandlerFromConfig;

if ((vehicle player) != player) then { 
	if((vehicle player) isKindOf "Air") then {
		[(vehicle player), '', player] call ace_sys_air_hud_fnc_getIn;
	};
};