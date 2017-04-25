#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

PARAMS_2(_target,_params);

_menuName = "";
_menuRsc = "buttonList";

if (typeName _params == typeName []) then {
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__];};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};
//-----------------------------------------------------------------------------
_jammed = GVAR(jammed);
if (isNil "_jammed") then {_jammed = false};
if (player ammo (primaryweapon player)!= 0) then {_jammed = false};
_isMG = (getNumber(configFile >> "CfgWeapons" >> currentWeapon player >> "ace_sys_weapons_type") in [5,6]);
_hasSpareBarrel = ("ACE_SpareBarrel" in (weapons player)); // || "ACE_SpareBarrel_Pack" in (weapons player));
_menus = [];

_menus =
[
	[
		["main", localize "STR_ACE_MENU_EQUIPPLAYER", "popup"],
		[
			[localize "STR_ACE_JAMCLEARACT",
				{ [] call FUNC(keypressed) },
				"", "", "", DIK_J, 1, _jammed && {ACE_SELFINTERACTION_RESTRICTED}],
			[localize "STR_ACE_SWAPBARRELACT",
				{ [] call FUNC(swap) },
				"", "", "", DIK_S, 1, _isMG && {_hasSpareBarrel} && {ACE_SELFINTERACTION_RESTRICTED}]
		]
	]
];
//-----------------------------------------------------------------------------
_menuDef = [];
{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this}else{""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _this, __FILE__];
};

_menuDef // return value
