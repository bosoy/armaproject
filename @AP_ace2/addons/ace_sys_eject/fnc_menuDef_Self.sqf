/*
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
_capable = alive player && !(player call ace_sys_wounds_fnc_isUncon);
_restricted = _capable && (player != vehicle player);
TRACE_2("",_capable,_restricted);

if (!_capable) exitWith {};

_hasAAD = getNumber(configFile >> "CfgWeapons" >> 

_menus =
[
	[
		["main", localize "STR_ACE_MENU_EQUIPPLAYER", _menuRsc],
		[
			[localize "STR_DSS_ACE_IRSTROBE" + " >", "", "", "",
				[QPATHTO_F(fnc_menuDef_Self), "irstrobes", 1],
				-1, 1, _irstrobes_inventory && !_restricted]
		]
	]
];

if (_menuName == "irstrobes") then {
	_menus set [count _menus,
		[
			["irstrobes", localize "STR_DSS_ACE_IRSTROBE", "popup", ""],
			[
				// MS 2000 an
				[format["<t size='0.9'>%1 (%2)</t>", localize "STR_ACE_TURNON_IR", "MS-2000"],
					{ [player, QUOTE(IR_Strobe_Marker)] execFSM QPATHTO_C(ace_irstrobe_on.fsm) },
					"","","", -1, 1, "IR_Strobe_Marker" in (magazines player) && !GVAR(ison) && !("IR_Strobe_Target" in (player getVariable QGVAR(active_strobes)))],
				// MS 2000 aus
				[format["<t size='0.9'>%1 (%2)</t>", localize "STR_ACE_TURNOFF_IR", "MS-2000"],
					{ player spawn COMPILE_FILE(ace_irstrobe_off) },
					"","","", -1, 1, "IR_Strobe_Marker" in (magazines player) && GVAR(ison) && "IR_Strobe_Marker" in (player getVariable QGVAR(active_strobes))],
				// VIP an
				[format["<t size='0.9'>%1 (%2)</t>", localize "STR_ACE_TURNON_IR", "VIP"],
					{ [player, QUOTE(IR_Strobe_Target)] execFSM QPATHTO_C(ace_irstrobe_on.fsm) },
					"","","", -1, 1, "IR_Strobe_Target" in (magazines player) && !GVAR(ison) && !("IR_Strobe_Marker" in (player getVariable QGVAR(active_strobes)))],
				// VIP aus
				[format["<t size='0.9'>%1 (%2)</t>", localize "STR_ACE_TURNOFF_IR", "VIP"],
					{ player spawn COMPILE_FILE(ace_irstrobe_off) },
					"","","", -1, 1, "IR_Strobe_Target" in (magazines player) && GVAR(ison) && "IR_Strobe_Target" in (player getVariable QGVAR(active_strobes))]
			]
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
*/