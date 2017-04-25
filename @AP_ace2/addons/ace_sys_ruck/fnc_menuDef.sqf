// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

PARAMS_2(_target,_params);
private ["_menuDef","_menuName", "_menuRsc", "_menus"];

_menuName = "";
_menuRsc = "popup";

if (typeName _params == typeName []) then {
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__]};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};

//Get network ruck info
[_target] call FUNC(reqWeight);

//-----------------------------------------------------------------------------

GVAR(target) = _target;

_menus =
[
	[
		["main", _menuName, _menuRsc],
		[
			[localize "STR_DN_ACE_RUCKSACK",
				{ [cba_ui_target, player] spawn FUNC(AccessRuck) },
				"", "", "", DIK_R, 1, [_target] call FUNC(HasRuck)]
		]
	]
];

//-----------------------------------------------------------------------------
_menuDef = [];
{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2", str _menuName, if (_menuName == "") then {_params} else {""}];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _params, __FILE__];
};

_menuDef // return value
