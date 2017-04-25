/* ace_sys_sandbag (.pbo) | (c) 2009 by rocko */
// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

PARAMS_2(_target,_params);

// Exit if it's an attached item
// TODO: Make func to call
if (_target getVariable ["ace_sys_cargo_attached_front",false]) exitWith {};

GVAR(target) = _target;

_menuName = "";
_menuRsc = "popup";

if (typeName _params == typeName []) then {
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__];};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};

_isConcertinaDeployed = (typeOf _target) isKindOf "ACE_ConcertinaWire";
_isConcertinaUndeployed = (typeOf _target) isKindOf "ACE_ConcertinaWireCoil";
_isSandbag = (typeOf _target) isKindOf "LAND_HBARRIER_LARGE";
_isLadder = (typeOf _target) isKindOf "ACE_Tactical_Ladder"; // Carrying is done via sys_cargo
_ladderInUse = _target getVariable [QGVAR(inUse),false];
_ladderDeployed = _target getVariable [QGVAR(deployed),false];
_ladderDropped = _target getVariable [QGVAR(dropped),true];

//TODO: Move to MAIN as define
_isDraggingORCarrying = (player getVariable ["ace_sys_cargo_dragging",false] || {player getVariable ["ace_sys_cargo_carrying",false]});

_menus =
[
	[
		["main", localize"STR_ACE_Sandbag", _menuRsc],
		[
			// SANDBAGS
			[localize "STR_ACE_AC_PICKUPSB",
				{ GVAR(target) spawn COMPILE_FILE(pickupSB) },
				"", "", "", -1, 1, alive _target && {_isSandbag} && {getText(configFile >> "CfgVehicles" >> typeOf _target >> "ACE_Interaction") == "Move"} && {ACE_SELFINTERACTION_RESTRICTED}],
			[localize "STR_ACE_AC_CARRYSB",
				{ GVAR(target) spawn COMPILE_FILE(carrySB) },
				"", "", "", -1, 1, alive _target && {_isSandbag} && {getText(configFile >> "CfgVehicles" >> typeOf _target >> "ACE_Interaction") == "Move"} && {ACE_SELFINTERACTION_RESTRICTED}],
			[localize "STR_ACE_AC_PICKUPSB",
				{ _target spawn COMPILE_FILE(pickupSB2) },
				"", "", "", -1, 1, alive _target && {_isSandbag} && {getText(configFile >> "CfgVehicles" >> typeOf _target >> "ACE_Interaction") == "Unbuild"} && {ACE_SELFINTERACTION_RESTRICTED}],
			// WIRES
			[localize "STR_ACE_ROLLWIRE",
				{ GVAR(target) spawn COMPILE_FILE(deployCW) },
				"", "", "", -1, 1, alive _target && {_isConcertinaUndeployed} && {!_isDraggingORCarrying} && {ACE_SELFINTERACTION_RESTRICTED}],
			[localize "STR_ACE_UNROLLWIRE",
				{ GVAR(target) spawn COMPILE_FILE(pickupCW) },
				"", "", "", -1, 1, alive _target && {_isConcertinaDeployed} && {!_isDraggingORCarrying} && {ACE_SELFINTERACTION_RESTRICTED}],
			// TACTICAL LADDER
			[localize "STR_ACE_POSITION_TACLADDER", 
				{ GVAR(target) spawn COMPILE_FILE(positionTL) },
				"", "", "", -1, 1, alive _target && {_isLadder} && {!_isDraggingORCarrying} && {!_ladderInUse} && {!_ladderDeployed} && {ACE_SELFINTERACTION_RESTRICTED}],
			[localize "STR_ACE_PICKUP_TACLADDER",
				{ GVAR(target) spawn COMPILE_FILE(pickupTL) },
				"", "", "", -1, 1, alive _target && {_isLadder} && {!_isDraggingORCarrying} && {!_ladderInUse} && {!_ladderDeployed} && {_ladderDropped} && {ACE_SELFINTERACTION_RESTRICTED}]			
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
