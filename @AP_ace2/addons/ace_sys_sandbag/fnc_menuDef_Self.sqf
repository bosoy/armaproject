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

_ladders = nearestObjects [player, ["ACE_Tactical_Ladder"], 4];
_abort = false;
if (count _ladders >= 1) then {
	{
		_ladder = _x;
		if (player modelToWorld (player selectionPosition "LeftFoot") distance (_x modelToWorld (_x selectionPosition "end")) < 1) then {
			_abort = true;
		};
	} foreach _ladders;
};

_menus =
[
	[
		["main", localize "STR_ACE_MENU_EQUIPPLAYER", _menuRsc],
		[
			[localize "STR_ACE_AC_BUILD",
				{ player execFSM QPATHTO_C(deploySB.fsm) },
				"","","", -1, 1, "ACE_SandBag_Magazine" in (magazines player) && {ACE_SELFINTERACTION_RESTRICTED}],
			[localize "STR_ACE_DROP_TACLADDER",
				{ player spawn COMPILE_FILE(deployTL) },
				"","","", -1, 1, !_abort && {"ACE_TacticalLadder_Pack" in (weapons player)} && {ACE_SELFINTERACTION_RESTRICTED}]
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