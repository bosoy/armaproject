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
//-----------------------------------------------------------------------------

_isVS21PanelMarker = (_target isKindOf "ACE_VS21APANEL");
_isDown = (_target animationPhase "flip") == 1;
_panel_magazine = (typeOf _target) + "_M";
_panel_name = getText(configFile >> "CfgMagazines" >> _panel_magazine >> "displayName");
_aliveCL = !isNull (_target getVariable [QGVAR(CL),objNull]);
_hasCL = (_target getVariable [QGVAR(hasCL),false] && {_aliveCL});
_equCL = currentMuzzle player in ["ACE_Knicklicht_UsedMuzzle","ACE_KnicklichtMuzzle"];
_inBack = [_target,player,0] call ACE_fnc_inFront; // Reversed for PanelMarkers, no idea why...

GVAR(targets) = [_target,_panel_magazine];

_menus =
[
	[
		["main", localize "STR_ACE_MENU_EQUIPPLAYER", _menuRsc],
		[
			[format[localize "STR_DN_ACE_PICKUPPANEL",_panel_name],
				{ GVAR(targets) spawn FUNC(pickup) },
				"","","", -1, 1, alive _target],
			[format[localize "STR_DN_ACE_FLIPPANEL",_panel_name],
				{ [cba_ui_target,0] spawn FUNC(flip) },
				"","","", -1, 1, alive _target],
			[format[localize "STR_DN_ACE_DOWNPANEL",_panel_name],
				{ [cba_ui_target,1] spawn FUNC(flip) },
				"","","", -1, 1, alive _target && {!_isDown}],
			[format[localize "STR_DN_ACE_UPPANEL",_panel_name],
				{ [cba_ui_target,1] spawn FUNC(flip) },
				"","","", -1, 1, alive _target && {_isDown}],				
			[format[localize "STR_DN_ACE_PANELBACK",_panel_name],
				{ [cba_ui_target,2] spawn FUNC(flip) },
				"","","", -1, 1, alive _target && {_isVS21PanelMarker} && {!_isDown && _inBack}],
			[localize "STR_DN_ACE_PANELCHEMLIGHT",
				{ cba_ui_target spawn FUNC(attach_chemlight) },
				"","","", -1, 1, alive _target && {_isVS21PanelMarker} && {!_isDown && !_hasCL && !_inBack && _equCL}] //,
			//[localize "STR_DN_ACE_PANELCHEMLIGHTX", // Maybe later if chemlight geo fucks up
			//	{ cba_ui_target spawn FUNC(remove_chemlight) },
			//	"","","", -1, 1, alive _target && {_isVS21PanelMarker} && {!_isDown && _hasCL && !_inBack}]				
		]
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