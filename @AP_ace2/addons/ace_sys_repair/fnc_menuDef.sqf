//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];
private ["_vehicle", "_displayNameVehicle","_exit"];
private ["_canDrag"];
// _this==[_target, _menuNameOrParams]
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
#define DISTANCE_TO_CHANGE_TYRE 10

GVAR(target) = _target;

// Check if tyres are nearby
private ["_tyres","_tyre"];
_type = getText(configFile >> "CfgVehicles" >> typeOf _target >> QGVAR(tyre_type));
_tyres = (getpos player) nearObjects [_type, DISTANCE_TO_CHANGE_TYRE];
_tyre = objNull;
if (count _tyres > 0) then {_tyre = _tyres select 0}; //Closest

// Check if vehicle needs tyre change
private ["_selections","_BISnaming"];
_selections = [];
_BISnaming = false;
TRACE_1("Trying to find BIS selection names","");
{
	if (_target animationPhase (_x + "_destruct") > 0.7) then {
		_selections set [count _selections, _x];
		TRACE_1("Found BIS selection names","");
		_BISnaming = true; // Set to true, once a BIS selection was found and added
	};
} foreach ["wheel_1_1","wheel_1_2","wheel_1_3","wheel_1_4","wheel_2_1","wheel_2_2","wheel_2_3","wheel_2_4"];

// If no selection found try to find in class HitPoints
if (count _selections == 0) then {
	TRACE_1("No BIS selection names found or vehicle has no damaged tires","");
	{
		if (_target animationPhase _x > 0.7) then {
			_selections set [count _selections, _x];
			TRACE_1("Found other selection names","");
		};
	} foreach ["HitLFWheel", "HitLBWheel", "HitRFWheel", "HitRBWheel"]; // Add selections for APCs
};

// If still no selections found, model is not compatible and cannot be repaired
if (count _selections == 0 && {!_BISnaming} && {!canMove _target}) then {
	WARNING("Model (" + str(typeOf _target) + ") is not conform to BIS standards!");
};

// Get nearest selection, and ensure player is within min distance
private ["_fuckedtyre","_min","_dist"];
_fuckedtyre = "";
_min = DISTANCE_TO_CHANGE_TYRE;
{
	private ["_dist","_sel"];
	_sel = if (_BISnaming) then { _x + "_steering" } else { getText (configFile >> "CfgVehicles" >> typeOf _target >> "HitPoints" >> _x >> "name") };
	_dist = player distance (_target modeltoworld (_target selectionPosition _sel));
	if (_dist < _min) then {
		_fuckedtyre = _sel;
		_min = _dist;
	};
	TRACE_2("",_dist,_fuckedtyre);
} foreach _selections;

GVAR(fuckedtyre) = _fuckedtyre;
GVAR(tyre) = _tyre;

private ["_tyre_needed","_correct_tyre"];
_tyre_needed = getText(configFile >> "CfgVehicles" >> typeOf _target >> QGVAR(tyre_type));
_correct_tyre = (_tyre_needed == typeof _tyre);

TRACE_4("",_tyre_needed,_correct_tyre,_fuckedtyre,_tyre);
TRACE_1("",_BISnaming);

// Transfer Fuel from targetVehicle, to nearByVehicles. for now automatically, later with a selectable list of closeby vehicles?

_isFuelcan = _target isKindOf "ACE_JerryCan";
_hasFuel = fuel _target > 0;
_nearestVehicle = if (isNull _target) then {objNull} else {
	_classes = if (_isFuelcan) then { ["Car", "Air", "Ship", "Tank"] } else { ["ACE_JerryCan", "Car", "Air", "Ship", "Tank"] };
	_nos = nearestObjects [_target, _classes,7];
	_nos = _nos - [_target];
	if (count _nos > 0) then {_nos select 0} else {objNull};
};
_nearestVehicleDistance = _target distance _nearestVehicle; // Loading distance. Should normally be relatively small
_vehicle = if (!isNull _nearestVehicle && {_nearestVehicleDistance < 7}) then {_nearestVehicle} else {objNull};
GVAR(target2) = _vehicle;

_displayNameVeh = if (isNull _vehicle) then {""} else {getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "displayName")};
_displayNameCan = getText (configFile >> "CfgVehicles" >> typeOf _target >> "displayName");

_fuelstation = objNull; 
if (_isFuelcan) then {
	_possible_fuelstations = nearestObjects [_target, ["Building"], 20];
	{
		_transportFuel = if (isClass(configFile >> "CfgVehicles" >> typeof _x)) then {
			getNumber(configFile >> "CfgVehicles" >> typeOf _x >> "transportFuel")
		} else { 0 };
		if (_transportFuel > 0) exitWith {
			_fuelstation = _x;
		};
	} foreach _possible_fuelstations;
};

_menus = [
	[
		["main", "", _menuRsc],
		[
			[localize "STR_ACE_FIXTYRE",
				{ [GVAR(target),GVAR(fuckedtyre), GVAR(tyre)] spawn FUNC(replaceTyre) },
				"", "", "", -1,
				1, !isnull _tyre && {_fuckedtyre != ""} && {_correct_tyre} && {alive _target} && {ACE_SELFINTERACTION_RESTRICTED} && {!_isFuelcan}],
			// Transfer fuel from jerrycan to car
			[format[localize "STR_ACE_TRANNYFUELCAR", _displayNameVeh],
				{ [GVAR(target), GVAR(target2)] call FUNC(transferFuel) },
				"", "", "", -1,
				1, alive _target && {if !(_vehicle isKindOf "Tank") then {alive _vehicle} else {_vehicle call ace_v_alive}} && {_target != _vehicle} && {ACE_SELFINTERACTION_RESTRICTED} && {_isFuelcan} && {_hasFuel}],
			// Refill jerrycan
			[format[localize "STR_ACE_TRANNYFUELCAN", _displayNameCan],
				{ [GVAR(target2), GVAR(target)] call FUNC(transferFuel) },
				"", "", "", -1,
				1, alive _target && {if !(_vehicle isKindOf "Tank") then {alive _vehicle} else {_vehicle call ace_v_alive}} && {_target != _vehicle} && {ACE_SELFINTERACTION_RESTRICTED} && {_isFuelcan} && {!_hasFuel}],			
			// Transfer fuel from car to jerrycan
			[format[localize "STR_ACE_TRANNYFUELCAN", _displayNameCan],
				{ GVAR(target) setFuel 1 },
				"", "", "", -1,
				1, alive _target && {!isNull _fuelstation} && {ACE_SELFINTERACTION_RESTRICTED} && {_isFuelcan} && {!_hasFuel}],			
			[localize "STR_ACE_CAPACITYCAN",
				{ [GVAR(target)] call FUNC(jerryCap) },
				"", "", "", -1,
				1, _target isKindOf "ACE_JerryCan" && {alive _target} && {ACE_SELFINTERACTION_RESTRICTED} && {_isFuelcan}]
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
