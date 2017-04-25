/* ace_sys_irstrobe (.pbo) | (c) 2008, 2009, 2010, 2011 by rocko */
// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

PARAMS_2(_target,_params);

_menuName = "";
_menuRsc = "popup";

if (typeName _params == typeName []) then {
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__];};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};

_menus =
[
	[
		["main", localize"STR_ACE_Sandbag", _menuRsc],
		[
			[localize "STR_ACE_PICK_UP_IR",
				{ cba_ui_target call FUNC(pickup) },
				"", "", "", -1, 1, alive cba_ui_target]
			//[localize "STR_ACE_TURNON_IR",
			//	{ [cba_ui_target,"on"] call(turnonoff) },
			//	"", "", "", -1, 1, alive cba_ui_target && !(cba_ui_target getVariable QGVAR(isOn))],
			//[localize "STR_ACE_TURNOFF_IR",
			//	{ [cba_ui_target,"off"] call (turnonoff) },
			//	"", "", "", -1, 1, alive cba_ui_target && cba_ui_target getVariable [QGVAR(isOn),false]]				
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
