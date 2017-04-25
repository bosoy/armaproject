// #define DEBUG_MODE_FULL
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

if (!isNil "ACE_NoFastRope") exitWith {};

GVAR(target) = _target;
TRACE_1("",_target);

_canFastRope = [_target] call FUNC(canFastRope);
_isHovering = (abs(speed _target) < 5 && {(getPos _target select 2) >= 10} && {(getPos _target select 2) <= 40});
_hasRope = ([player] call FUNC(hasropemag)) != "";

_isCargo = if (count (assignedVehicleRole player) > 0) then {
	((assignedVehicleRole player) select 0) in ["Cargo"];
} else {
	false;
};

TRACE_4("",_canFastrope,_isHovering,_hasRope,_isCargo);


_menus =
[
	[
		["main", "", _menuRsc],
		[
			[localize "STR_ACE_DEPLOYFASTROPE",
				{ [vehicle player] spawn FUNC(deployFastropes)},
				"", "", "", DIK_S,
				_isCargo && {_hasRope}, _isHovering && {_canFastRope}]
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
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _params, __FILE__];
};

_menuDef // return value
