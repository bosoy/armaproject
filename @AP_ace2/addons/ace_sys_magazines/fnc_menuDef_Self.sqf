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

_magazines_menu = false;
private ["_magazines_array", "_magazine_name", "_magazine_action", "_magazine_icon", "_magazines_tracker"];
_magazines_array = [];
_magazines_tracker = [];
_magazines_array set [0, [localize "STR_DN_ACE_UNLOADWEAPON_MENU", "player spawn ace_sys_magazines_fnc_unload", "", "", "", -1, true, true]];

{
	if !(_x in _magazines_tracker) then {
		_magazine_count = getNumber(configFile >> "CfgMagazines" >> _x >> "count");
		if (_magazine_count <= 1) exitWith {};
		_magazines_tracker set [count _magazines_tracker, _x];
		_magazine_name = getText(configFile >> "CfgMagazines" >> _x >> "displayName");
		_magazine_icon = getText(configFile >> "CfgMagazines" >> _x >> "picture");
		_magazine_action = "[player, '" + _x + "'] spawn ace_sys_magazines_fnc_refill";
		_magazines_array set [count _magazines_array, [_magazine_name, _magazine_action, _magazine_icon, "", "", -1, true, true]];
		_magazines_menu = true;
	};
} foreach (magazines player);

_menus =
[
	[
		["main", localize "STR_ACE_MENU_EQUIPPLAYER", _menuRsc],
		[
			[localize "STR_DN_ACE_MAGAZINES_MENU", "", "", "",
				[QPATHTO_F(fnc_menuDef_Self), "magazines", 1],
				-1, 1, _magazines_menu && {!(vehicle player isKindOf "StaticWeapon")}]
		]
	]
];

if (_menuName == "magazines") then {
	_menus set [count _menus,
		[
			["magazines", localize "STR_DN_ACE_MAGAZINESREFILL_MENU", "popup", ""],
			_magazines_array
		]
	];
};

_menuDef = [];
{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this} else {""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _this, __FILE__];
};

_menuDef // return value			