/* ace_sys_map (.pbo) | Adds possibility to view someone elses map IF player does not own a map (not depending on the module) */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

_target = _this select 0;
_params = _this select 1;

_menuDef = [];
_menuName = "";
_menuRsc = "popup";

if (typeName _params == typeName []) then {
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__];};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};

//-----------------------------------------------------------------------------

GVAR(target) = _target;
_otherHasMap = ("ACE_Map" in weapons GVAR(target) || {"ItemMap" in weapons GVAR(target)});
_playerHasMap = ("ACE_Map" in weapons player || {"ItemMap" in weapons player});

_menus =
[
	[
		["main", _menuName, _menuRsc],
		[
			[localize "STR_DN_ACE_SYS_MAP_READ_MAP",
				{ [cba_ui_target, player] spawn COMPILE_FILE(maplook) },
				"", "", "", -1, 1,
				_otherHasMap && {!_playerHasMap}]
		]
	]
];

//-----------------------------------------------------------------------------

{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this}else{""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _params, __FILE__];
};

if(isNil "_menuDef") then {_menuDef = [] };
_menuDef // return value
