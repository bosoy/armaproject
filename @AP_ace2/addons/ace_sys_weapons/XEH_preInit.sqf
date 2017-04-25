#include "script_component.hpp"
// sys_weapons by Sickboy
LOG(MSG_INIT);

ADDON = false; // Announce start of initialization

GVAR(magicbox_weapons_count) = 2;
GVAR(magicbox_magazines_count) = 12;

// Prepare Functions & Scripts
PREP(determineFactions);
PREP(determineZoom);
PREP(determineType);
PREP(init);
PREP(getType);
//PREP(process);
//PREP(processMagazines);
if (isNil QGVAR(test)) then { GVAR(test) = false };

if (isNil QGVAR(lock)) then { GVAR(lock) = [true] }; // use for admins and other lock abilities for class lock etc

/*
SIX_SYS_MENU_WEAPON_SELECT = [];

GVAR(pid) = [] spawn {};

FUNC(temp) = {
	switch (_this select 0) do {
		case 0: {
			private ["_ar"];
			_ar = [];
			if !(GVAR(lock) select 0) then {
				{
					_ar = _ar + [ [ ["Item", ("Attach: " + (_x select 0))], ["Action", format["if (scriptDone six_sys_weapons_pid) then { six_sys_weapons_pid = %1 spawn ace_sys_attachments_fnc_action }", _x] ] ] ];
				} forEach ace_sys_attachments_available;
			};
			_ar
		};
		case 1: {
			private ["_ar"];
			_ar = []; {
				_ar = _ar + [ [ ["Item", ("Switch To: " + (_x select 0))], ["Action", format["if (scriptDone six_sys_weapons_pid) then { six_sys_weapons_pid = %1 spawn ace_sys_attachments_fnc_action }", _x] ] ] ];
			} forEach ace_sys_attachments_cqb;
			_ar
		};
		case 2: {
			private ["_ar"];
			_ar = [];
			if !(GVAR(lock) select 0) then {
				{
					_ar = _ar + [ [ ["Item", ("Attach Pistol: " + (_x select 0))], ["Action", format["if (scriptDone six_sys_weapons_pid) then { six_sys_weapons_pid = %1 spawn ace_sys_attachments_fnc_actionPistol }", _x] ] ] ];
				} forEach ace_sys_attachments_available_Pistol;
			};
			_ar
		};
		case 11: {
			[1] spawn six_sys_menu_fnc_showMap;
		};
	};
};

if (isNil "six_sys_menu_CUSTOM") then { six_sys_menu_CUSTOM = [] };
six_sys_menu_CUSTOM = six_sys_menu_CUSTOM +
[ {
		if (six_sys_menu getVariable "config_weapons") then {
			_mainItems = _mainItems +
			[
				[ ["Item", "Open Weapons Menu >"], ["Action", QUOTE([] spawn COMPILE_FILE(menu_weapons))] ]
			];
		};
	}
];
*/

ADDON = true; // Announce end of initialization
