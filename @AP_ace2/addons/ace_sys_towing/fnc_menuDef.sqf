// #define DEBUG_MODE_FULL
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
_hasRopeM = (QUOTE(ROPE_M) in (magazines player));
_rope = player getVariable QGVAR(rope);
_hasRope = if (isNil "_rope") then { _rope = _target getVariable QGVAR(rope); false } else { true };
_hasRopeA = false; _hasRopeB = false;
_hasRopeAA = false; _hasRopeBB = false;

// TODO: ATV can pull other ATV's, but not trucks, etc. etc.
_canPull = true;
_canBePulled = true;

if !(isNil "_rope") then {
	if !(isNull _rope) then {
	_ropeA = _rope getVariable QGVAR(A);
	_ropeB = _rope getVariable QGVAR(B);
	_hasRopeA = if !(isNil "_ropeA") then { if !(isNull _ropeA) then { _hasRopeAA = true; (_target == _ropeA)} else { false } } else { false };
	_hasRopeB = if !(isNil "_ropeB") then { if !(isNull _ropeB) then { _hasRopeBB = true; (_target == _ropeB)} else { false } } else { false };
	};
};

_menus =
[
	[
		["main", _displayName, "popup"],
		[
			[localize "STR_ACE_TOW_ACTION_1",
				{ [CBA_ui_target, QGVAR(A)] call FUNC(attachRope)},
				"", "Adjust", "", DIK_S, true, _canPull && {(_hasRopeM || {_hasRope})} && {!_hasRopeAA} && {!_hasRopeB}],
			[localize "STR_ACE_TOW_ACTION_2",
				{ [CBA_ui_target, QGVAR(B)] call FUNC(attachRope)},
				"", "Adjust", "", DIK_S, true, _canBePulled && {(_hasRopeM || {_hasRope})} && {!_hasRopeBB} && {!_hasRopeA}],
			[localize "STR_ACE_TOW_ACTION_3",
				{ [CBA_ui_target, QGVAR(A)] call FUNC(detachRope)},
				"", "Adjust", "", DIK_S, true, _hasRopeA],
			[localize "STR_ACE_TOW_ACTION_4",
				{ [CBA_ui_target, QGVAR(B)] call FUNC(detachRope)},
				"", "Adjust", "", DIK_S, true, _hasRopeB]
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
