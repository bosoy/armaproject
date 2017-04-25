//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_menuName", "_menuRsc", "_menus"];

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

#define __ON localize "STR_ACE_TURNDETECTORON"
#define __OFF localize "STR_ACE_TURNDETECTOROFF"

_isOnDetector = player getVariable [QGVAR(on),false];
_hasMarkersLeft = (player getVariable [QGVAR(markersleft),10] > 0);
if (!_hasMarkersLeft && {"ACE_MineMarkers" in (weapons player)}) then { // Reset
	player setVariable [QGVAR(markersleft),10];
};

_hasFlagsLeft = (player getVariable [QGVAR(flagsleft),8] > 0);
if (!_hasFlagsLeft && {"ACE_MineMarkers_MineFlag" in (weapons player)}) then { // Reset
	player setVariable [QGVAR(flagsleft),8];
};

_menus =
[
	[
		["main", _menuName, _menuRsc],
		[
			[__ON,
				{ [] spawn FUNC(sweep) },
				"", "", "", -1, 1,
				!_isOnDetector && {(currentWeapon player in ["ACE_Minedetector_US","ACE_VMH3","ACE_VMM3"])} && {ACE_SELFINTERACTION_RESTRICTED}],
			[__OFF,
				{ player setVariable [QGVAR(on),false] },
				"", "", "", -1, 1,
				_isOnDetector && {(currentWeapon player in ["ACE_Minedetector_US","ACE_VMH3","ACE_VMM3"])} && {ACE_SELFINTERACTION_RESTRICTED}],
			[localize "STR_ACE_PLACEMINEMARKER",
				{ player spawn FUNC(place_marker) },
				"", "", "", -1, 1,
				_hasMarkersLeft && {"ACE_MineMarkers" in (weapons player)} && {ACE_SELFINTERACTION_RESTRICTED}],
			[localize "STR_ACE_PLACEMINEMARKERFLAG",
				{ player spawn FUNC(place_flag) },
				"", "", "", -1, 1,
				_hasFlagsLeft && {"ACE_MineMarkers_MineFlag" in (weapons player)} && {ACE_SELFINTERACTION_RESTRICTED}]
		]
	]
];

//-----------------------------------------------------------------------------
_menuDef = [];
{
	if ((_x select 0) select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this} else {""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _params, __FILE__];
};

_menuDef // return value
