#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

// _this==[_target, _menuNameOrParams]
_target = _this select 0;
_params = _this select 1;

_menuName = "";
_menuRsc = "popup";

if (typeName _params == typeName []) then
{
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__];};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};
//-----------------------------------------------------------------------------
_inVehicle = (player != vehicle player);
_hasCQB = count(GVAR(cqb)) > 0; // GVAR(cqb) == [["CQB","ACE_m16a4_acg_CQB"]]
_currCQB = "";
if (_hasCQB) then
{
	if (count (GVAR(cqb) select 0) > 0) then
	{
		_currCQB = GVAR(cqb) select 0 select 0;
	};
};

_menus =
[
	[
		["main", localize "STR_ACE_MENU_EQUIPPLAYER", _menuRsc],
		[
			[format["CQB sights: (%1)", toLower _currCQB],
				format["nul=[controlNull, -1, false, false, false] call %1", QUOTE(FUNC(keypressed))],
				"", "Toggle", "", DIK_Q, 1, !_inVehicle && {_hasCQB} && {(currentWeapon player) == (primaryWeapon player)} && {primaryWeapon player != ""} && {!(currentWeapon player in ["Throw","ACE_Throw"])}]
		]
	]
];
//-----------------------------------------------------------------------------
_menuDef = [];
{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then
{
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this}else{""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _this, __FILE__];
};

_menuDef // return value
