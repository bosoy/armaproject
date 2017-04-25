/* ace_sys_groundmarker | (c) 2010,2011,2012 by rocko */
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

_panel_array = [];
_panel_magazines = ["ACE_VS17PANEL_M","ACE_VS21APANEL_M","ACE_VS21BPANEL_M","ACE_VS21CPANEL_M","ACE_VS21MEDICPANEL_M"];
{
	if (_x in (magazines player)) then {
		_panel_name = getText(configFile >> "CfgMagazines" >> _x >> "displayName");
		_panel_type = getText(configFile >> "CfgMagazines" >> _x >> "descriptionShort");
		_panel_menu_title = format[localize "STR_DN_ACE_PLACEPANEL",_panel_name,_panel_type];
		_panel_action = "[player,'"+_x+"'] spawn ace_sys_groundmarker_fnc_place";
		_panel_array set [count _panel_array,[_panel_menu_title,_panel_action,"","","",-1,1,ACE_SELFINTERACTION_RESTRICTED]];
	};
} foreach _panel_magazines;

_menus =
[
	[
		["main", localize "STR_ACE_MENU_EQUIPPLAYER", _menuRsc],
		[] + _panel_array
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