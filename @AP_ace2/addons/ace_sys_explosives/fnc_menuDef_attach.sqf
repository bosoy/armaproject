//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

#define __DN getText(configFile >> "CfgVehicles" >> typeOf GVAR(mine) >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(name))

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

// _this==[_target, _menuNameOrParams]
PARAMS_2(_target,_params);

_menuDef = [];
_menuName = "";
_menuRsc = "popup";

if (typeName _params == typeName []) then {
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__];};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};


if (_target isKindOf "Man") exitWith {_menuDef};

private ["_mine","_by","_dir","_start","_cur","_i","_canAttach"];

{
	// _cI || timer>0
	if (alive _x && {(_x getVariable [QGVAR(canInteract), false]) && {!(_x call FUNC(check_disabled))} || {0 < (_x getVariable [QGVAR(timer), -1])}}) then {
		_by = _x getVariable [QUOTE(GVARMAIN(attachedBy)), ""];
		switch (_by) do {
			// carried is prefered
			case "sys_cargo": { if (player getVariable ["ace_sys_cargo_carrying", false] && {_x == player getVariable ["ace_sys_cargo_carried_object",objNull]}) exitWith { _mine = _x }};
			// if no carried, first is prefered
			case "": { if (isNil "_mine") then { _mine = _x }};
		};
	};
} forEach nearestObjects [player, ["ACE_Pipebomb"], 2];
if (isNil "_mine") exitWith {_menuDef};

// TODO replace with CBA macro #71981
#define VECTORVAR3ADDMULTI(V1,V2,MULTI) \
	[(V1 select 0)+(V2 select 0)*MULTI,(V1 select 1)+(V2 select 1)*MULTI,(V1 select 2)+(V2 select 2)*MULTI]

//_dir = player weaponDirection (currentWeapon player);
//_start = aimPos player;
_dir = eyeDirection player;
_start = eyePos player;
_cur = _start;

_i=0;
for "_j" from 1 to 100 do {
	if (lineIntersects [_start, _cur]) exitWith {};
	_cur = VECTORVAR3ADDMULTI(_cur,_dir,0.02);
	_i=_j;
};
if (_i==100) then {_canAttach = false} else {_canAttach = true};

_cur = VECTORVAR3ADDMULTI(_cur,_dir,-0.01);

// TODO replace with private #71147
GVAR(mine) = _mine;
GVAR(attachTo) = _cur;

_menus = 
[
	[
		["main", "", _menuRsc],
		[
			[format[localize "STR_ACE_SYS_EXPLOSIVES_ATTACH",__DN],
				{ [player, GVAR(mine), cba_ui_target, GVAR(attachTo)] spawn COMPILE_FILE(SATCHEL\attach); },
				"","","",DIK_A,
				_canAttach,
				true
			]

		]
	]
];

//-----------------------------------------------------------------------------

{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this} else {""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _this, __FILE__];
};

_menuDef // return value
