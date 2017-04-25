//#define DEBUG_MODE_FULL
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
//-----------------------------------------------------------------------------

_enabled = GVAR(enabled);
_hasGPS = getNumber (configFile >> "CfgVehicles" >> typeOf _target >> "enableGPS") == 1;
_isArmyVehicle = getNumber (configFile >> "CfgVehicles" >> typeOf _target >> "side") != 3;
_FBCB2on = _target getVariable [QGVAR(device_active),false];
_in = player in (crew _target);
_slot = if (_target isKindOf "Tank") then { player == (commander _target) } else { player in [(commander _target)] || {player in (assignedCargo _target)} };

GVAR(target) = _target;

_menus = [
	[
		["main", "", _menuRsc],
		[
			[localize "STR_ACE_FBCB2ON",
				{ GVAR(target) setVariable ["ace_sys_tracking_device_active",true,true] },
				"", "", "", -1, 1, _hasGPS && {_isArmyVehicle} && {!_FBCB2on} && {_in} && {_enabled} && {_slot}],
			[localize "STR_ACE_FBCB2OFF",
				{ GVAR(target) setVariable ["ace_sys_tracking_device_active",false,true] },
				"", "", "", -1, 1, _FBCB2on && {_in} && {_slot}]
				
			//[localize "STR_ACE_OPENCREATEDEVICE",
			//	{ [GVAR(target)] spawn FUNC(create_device) },
			//	"", "", "", -1, 1, _FBCB2on && {_enabled} && {_in} && {_slot}]		
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

_menuDef // return value
