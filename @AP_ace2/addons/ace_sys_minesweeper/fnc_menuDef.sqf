//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_menuName", "_menuRsc", "_menus"];
private ["_requiredComponent","_component","_componentlist"];

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

#define __DN getText(configFile >> "CfgVehicles" >> typeOf _target >> "displayName")
#define __SIGHTIN format [localize "STR_ACE_SYS_EXPLOSIVES_SIGHT_IN",__DN]
#define __ASSEMBLE format [localize "STR_ACE_DN_MINESWEEPER_ASS_APOBS",__DN]
#define __DISSEMBLE format [localize "STR_ACE_DN_MINESWEEPER_DIS_APOBS",__DN]
#define __FIRE format [localize "STR_ACE_DN_MINESWEEPER_FIR_APOBS",__DN]

_isAPOBSComponent = (typeOf _target == "ACE_APOBS_A_crate" || {typeOf _target == "ACE_APOBS_B_crate"});
_hasComponent = false;
if (_isAPOBSComponent) then { // TODO: More into configs... once working
	if (typeOf _target == "ACE_APOBS_A_crate") then {
		_requiredComponent = "ACE_APOBS_B_crate";
	} else {
		_requiredComponent = "ACE_APOBS_A_crate";
	};
	_componentlist = nearestObjects [_target, [_requiredComponent], 2];
	if (count _componentlist > 0) then {
		_component = _componentlist select 0;
		_hasComponent = true;
	};
}; 
_isAPOBS = typeOf _target == "ACE_APOBS_MK7MOD2";
_isAPOBSempty = _target getVariable [QGVAR(APOBSempty),false];
_isAPOBSarmed = _target getVariable [QGVAR(APOBSarmed),false];

_isMineMarker = typeOf _target == "ACE_MineMarker";
_canPickMineMarker = ((player getVariable [QGVAR(markersleft),0] < 10) || {!("ACE_MineMarkers" in weapons player)}) ;

_isMineMarkerFlag = typeOf _target == "ACE_Minemarker_flag";
_canPickMineMarkerFlag = ((player getVariable [QGVAR(flagsleft),0] < 8) || {!("ACE_MineMarkers_MineFlag" in weapons player)}) ;


_hasMineMarkerPathSign = ("ACE_MineMarkers_PathSign" in weapons player);
_hasMineMarkerMineSign = ("ACE_MineMarkers_MineSign" in weapons player);
_hasMineMarkerLight = ("ACE_MineMarkers_Light" in weapons player);

_markerHasLight = (_target animationPhase "remove_light") == 0;
_markerHasMineSign = (_target animationPhase "remove_sign") == 0;
_markerHasPathSign = (_target animationPhase "remove_path") == 0;

GVAR(target) = _target;
GVAR(components) = if (typeOf _target == "ACE_APOBS_A_crate") then { [_target,_component] } else { [_component,_target] };

_menus =
[
	[
		["main", _menuName, _menuRsc],
		[
			[__ASSEMBLE,
				{ GVAR(components) spawn FUNC(assembleAPOBS) },
				"", "", "", -1, 1,
				_isAPOBSComponent && {_hasComponent} && {ACE_SELFINTERACTION_RESTRICTED}],
			[__SIGHTIN,
				{ GVAR(target) spawn FUNC(setupAPOBS) },
				"", "", "", -1, 1,
				_isAPOBS && {!_isAPOBSempty} && {!_isAPOBSarmed} && {ACE_SELFINTERACTION_RESTRICTED}],
			[__FIRE,
				{ GVAR(target) spawn FUNC(fireAPOBS) },
				"", "", "", -1, 1,
				_isAPOBS && {!_isAPOBSempty} && {!_isAPOBSarmed} && {ACE_SELFINTERACTION_RESTRICTED}],
			[__DISSEMBLE,
				{ GVAR(target) spawn FUNC(disassembleAPOBS) },
				"", "", "", -1, 1,
				_isAPOBS && {!_isAPOBSempty} && {!_isAPOBSarmed} && {ACE_SELFINTERACTION_RESTRICTED}],

			// Add light	
			[localize "STR_ACE_ADDMINEMMARKERLIGHT",
				{ [GVAR(target),"light",0] call FUNC(changeMineMarker) },
				"", "", "", -1, 1,
				_isMineMarker && {_hasMineMarkerLight} && {!_markerHasLight} && {ACE_SELFINTERACTION_RESTRICTED}],

			[localize "STR_ACE_REMMINEMMARKERLIGHT",
				{ [GVAR(target),"light",1] call FUNC(changeMineMarker) },
				"", "", "", -1, 1,
				_isMineMarker && {_markerHasLight} && {ACE_SELFINTERACTION_RESTRICTED}],

			// Add lane marker
			[localize "STR_ACE_ADDMINEMMARKERLANE",
				{ [GVAR(target),"path",0] call FUNC(changeMineMarker) },
				"", "", "", -1, 1,
				_isMineMarker && {_hasMineMarkerPathSign} && {!(_markerHasPathSign || {_markerHasMineSign})} && {ACE_SELFINTERACTION_RESTRICTED}],

			[localize "STR_ACE_REMMINEMMARKERLANE",
				{ [GVAR(target),"path",1] call FUNC(changeMineMarker) },
				"", "", "", -1, 1,
				_isMineMarker && {_markerHasPathSign} && {ACE_SELFINTERACTION_RESTRICTED}],

			[localize "STR_ACE_FLIPMINEMMARKERLANE",
				{ [GVAR(target),"flip",1] call FUNC(changeMineMarker) },
				"", "", "", -1, 1,
				_isMineMarker && {_markerHasPathSign} && {ACE_SELFINTERACTION_RESTRICTED}],

			// Add mine marker
			[localize "STR_ACE_ADDMINEMMARKERSIGN",
				{ [GVAR(target),"sign",0] call FUNC(changeMineMarker) },
				"", "", "", -1, 1,
				_isMineMarker && {_hasMineMarkerMineSign} && {!(_markerHasMineSign || {_markerHasPathSign})} && {ACE_SELFINTERACTION_RESTRICTED}],

			[localize "STR_ACE_REMMINEMMARKERSIGN",
				{ [GVAR(target),"sign",1] call FUNC(changeMineMarker) },
				"", "", "", -1, 1,
				_isMineMarker && {_markerHasMineSign} && {ACE_SELFINTERACTION_RESTRICTED}],

			[localize "STR_ACE_PICKUPMINEMARKER",
				{ GVAR(target) call FUNC(pickup_marker) },
				"", "", "", -1, 1,
				_isMineMarker && {ACE_SELFINTERACTION_RESTRICTED}],
				
			[localize "STR_ACE_PICKUPMINEMARKERFLAG",
				{ GVAR(target) call FUNC(pickup_flag) },
				"", "", "", -1, 1,
				_isMineMarkerFlag && {ACE_SELFINTERACTION_RESTRICTED}]
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
