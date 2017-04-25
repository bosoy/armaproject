#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

_target = _this select 0;
_params = _this select 1;

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


//-----------------------------------------------------------------------------

_menus = [
	[
		["main", "ACE Flip", "popup"],
		[
			[localize "STR_ACE_UA_FLIPATV",
				{['ace_flip', CBA_ui_target] call ACE_fnc_receiverOnlyEvent;},
				"","","", -1, 1, (((vectorUp _target) select 2) < 0.6) && {(isNull driver _target)} && {(abs (speed _target) < 3)}
			]
		]
	]
];

//-----------------------------------------------------------------------------
_menuDef = [];
{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this} else {""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _this, __FILE__];
};

_menuDef
