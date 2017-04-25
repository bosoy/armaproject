#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

// _this==[_target, _menuNameOrParams]
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
private["_hasAdjustment"];
_elevDialogIsOpen = false; // TODO: modify startdialog.sqf/dialog.hpp->onLoad to indicate dialog is already open somehow
_inVehicle = (player != vehicle player);
_role = assignedVehicleRole player;
_isUsingTurret = if (count _role > 0) then {_role select 0 == "Turret"} else {false};
_hasAdjustment = getNumber(configFile >> "CfgVehicles" >> typeOf (vehicle player) >> "ace_sa_enabled")==1;
_canUse = _inVehicle && {_isUsingTurret} && {_hasAdjustment};

_displayName = getText (configFile >> "cfgVehicles" >> typeOf _target >> "displayName");
if (_displayName == "") then {_displayName = typeOf _target};

_menus =
[
	[
		["main", _displayName, "popup"],
		[
			[localize "STR_ACE_SA_SA",
				format["0=[] execVM '%1'", QUOTE(PATHTO(startdialog))],
				"", "Adjust", "", DIK_S, !_elevDialogIsOpen, _canUse]
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
