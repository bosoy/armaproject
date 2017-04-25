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

_menus =
[
	[
		["main", localize "STR_ACE_MENU_EQUIPPLAYER", _menuRsc],
		[
			[localize "STR_ACE_CREW_TRIPOD",
				{ [player] spawn COMPILE_FILE2(\x\ace\addons\sys_crewserved\deployTripod.sqf) },
				"","","", -1, 1, ((secondaryWeapon player) call FUNC(isTripod)) && {!(player call FUNC(busy))} && {ACE_SELFINTERACTION_RESTRICTED} && {ACE_ASSEMBLE}],
			[localize "STR_ACE_CREW_DRAGON",
				{ [player] spawn FUNC(deployDragon) },
				"","","", -1, 1, ((secondaryWeapon player) == "M47Launcher_EP1") && {!(player call FUNC(busy))} && {ACE_SELFINTERACTION_RESTRICTED} && {ACE_ASSEMBLE}]
		]
	]
];

_menuDef = [];
{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this} else {""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _this, __FILE__];
};

_menuDef // return value