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

private ["_goggles_menu", "_top", "_wearingGoggle", "_wearingMask", "_wearingGasmask", "_wearingEarplug", "_wearingNothing"];
_goggles_menu = false;

_top = player getVariable [QGVAR(protection), -1];
_wearingNothing = (_top in [-1]);
_wearingGoggle = (_top in [0,1]);
_wearingMask = (_top in [2]);
_wearingGasmask = (_top in [3]);
//_wearingVisor = (_top in [4] || {player getVariable [QGVAR(visorDown),false]});
_wearingEarplug = player getVariable [QGVAR(earplugs), false];


private ["_goggles_array", "_goggle_name", "_goggle_action", "_goggle_icon"];
_goggles_array = [];
{ // cycle through all wearables
	if (getNumber(configFile >> "CfgWeapons" >> _x >> "ACE_IsGoggle") == 1) then {
		_goggle_name = getText(configFile >> "CfgWeapons" >> _x >> "displayName");
		_goggle_icon = getText(configFile >> "CfgWeapons" >> _x >> "picture");
		if (_x == "ACE_Earplugs") then {
			_goggle_action = "[player] execFSM '\x\ace\addons\sys_goggles\use_earplug.fsm'";
			_goggles_array set [count _goggles_array,	[_goggle_name, _goggle_action, _goggle_icon, _goggle_name, "", -1, 1, !_wearingEarplug]];
		} else {
			if (_x != "ACE_GlassesMFS") then {
				_goggle_action = "[player, '" + _x + "'] execFSM '\x\ace\addons\sys_goggles\use_glasses.fsm'";
				_goggles_array set [count _goggles_array,	[_goggle_name, _goggle_action, _goggle_icon, _goggle_name, "", -1, GVAR(configured), _wearingNothing]];	
			} else {
				if ([player] call ACE_fnc_isPilot) then { // Only pilots can wear MFS
					_goggle_action = "[player, '" + _x + "'] execFSM '\x\ace\addons\sys_goggles\use_glasses.fsm'";
					_goggles_array set [count _goggles_array,	[_goggle_name, _goggle_action, _goggle_icon, _goggle_name, "", -1, GVAR(configured), _wearingNothing]];				 
				};
			};
		};
		_goggles_menu = true;
	};
} forEach (weapons player);

if (_wearingGoggle || {_wearingMask} || {_wearingGasmask} || {_wearingEarplug}) then {
	_goggles_menu = true;
};

TRACE_4("",_wearingGoggle,_wearingMask,_wearingGasmask,_wearingEarplug);

_menus =
[
	[
		["main", localize "STR_ACE_MENU_EQUIPPLAYER", _menuRsc],
		[
			[localize "STR_DN_ACE_GOGGLE_MENU", "", "", "",
				[QPATHTO_F(fnc_menuDef_Self), "goggles", 1],
				-1, 1, _goggles_menu && {ACE_SELFINTERACTION_POSSIBLE} && {ACE_IDENTITYDEFAULT}]
		]
	]
];

if (_menuName == "goggles") then {
	_menus set [count _menus,
		[
			["goggles", localize "STR_DN_ACE_GOGGLE_MENU", "popup", ""],
			[
				// Put off / Take out stuff
				[localize "STR_ACE_GOG_TAKEOFF",
				{ [player] execFSM QPATHTO_C(remove_glasses.fsm) },
				"", "", "", -1, GVAR(configured),_wearingGoggle],

				[localize "STR_ACE_MSK_TAKEOFF",
				{ [player] execFSM QPATHTO_C(remove_glasses.fsm) },
				"", "", "", -1, GVAR(configured),_wearingMask],

				[localize "STR_ACE_MSK_TAKEOFFGASMASK",
				{ [player] execFSM QPATHTO_C(remove_glasses.fsm) },
				"", "", "", -1, GVAR(configured),_wearingGasmask],

				[format["<t size='0.85'>%1</t>", localize "STR_ACE_EARPLUG_TAKEOFF"],
				{ [player] execFSM QPATHTO_C(remove_earplug.fsm) },
				"", "", "", -1, 1,_wearingEarplug]
				
				//[localize "STR_ACE_VISOR_DOWN",
				//{ [player] call FUNC(visor_down) },
				//"", "", "", -1, GVAR(configured),!_wearingVisor && {[player] call ACE_fnc_isPilot} && {!(player getVariable [QGVAR(visorDown),false])} && {!((player getVariable [QGVAR(identity),"ACE_Original_Identity"]) in ["ACE_GlassesGasMask_US","ACE_GlassesGasMask_RU", "ACE_GlassesGasMask2_US"])}],

				//[localize "STR_ACE_VISOR_UP",
				//{ [player] call FUNC(visor_up) },
				//"", "", "", -1, GVAR(configured),_wearingVisor]				
				
			] + _goggles_array // Earplugs, Masks, Goggles
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