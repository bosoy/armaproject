//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

PARAMS_2(_target,_params);

_menuName = "";
_menuRsc = "buttonList";

if (typeName _params == typeName []) then {
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__]};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};

private ["_chemlight_inventory", "_chemlight_used", "_chemlight_attached"];
_chemlight_inventory = ((currentMagazine player) in ["ACE_Knicklicht_IR","ACE_Knicklicht_R","ACE_Knicklicht_B","ACE_Knicklicht_G","ACE_Knicklicht_W","ACE_Knicklicht_Y","ACE_Knicklicht_IR_Used","ACE_Knicklicht_R_Used", "ACE_Knicklicht_W_Used", "ACE_Knicklicht_G_Used", "ACE_Knicklicht_Y_Used", "ACE_Knicklicht_B_Used"] );
_chemlight_attached = player getVariable ["ace_attached_knicklicht", false];
_chemlight_used = player getVariable ["ace_used_knicklicht", false];

_menus =
[
	[
		["main", localize "STR_ACE_MENU_EQUIPPLAYER", _menuRsc],
		[
			[localize "STR_DN_ACE_KNICKLICHT_MENU", "", "", "",
				[QPATHTO_F(fnc_menuDef_Self), "chemlights", 1],
				-1, 1, (_chemlight_inventory && {ACE_SELFINTERACTION_RESTRICTED}) || {_chemlight_attached}]
		]
	]
];

if (_menuName == "chemlights") then {
	_menus set [count _menus,
		[
			["chemlights", localize "STR_DN_ACE_KNICKLICHT_MENU", "popup", ""],
			[
				[localize "STR_ACE_UA_KNICKLICHT_ANBRINGEN",
				{ player spawn COMPILE_FILE(ua_knicklicht_anbringen) },
				"", "", "", -1, 1,!_chemlight_attached],
				
				[localize "STR_ACE_UA_KNICKLICHT_AB",
				{ player spawn COMPILE_FILE(ua_knicklicht_entfernen) },
				"", "", "", -1, 1,_chemlight_attached],				

				[localize "STR_ACE_UA_KNICKLICHT_LEUCHT",
				{ player spawn COMPILE_FILE(ua_knicklicht_leuchten) },
				"", "", "", -1, 1,!_chemlight_used && {!_chemlight_attached}]
			]
		]
	];
};

//-----------------------------------------------------------------------------
_menuDef = [];
{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this} else {""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _this, __FILE__];
};

_menuDef // return value