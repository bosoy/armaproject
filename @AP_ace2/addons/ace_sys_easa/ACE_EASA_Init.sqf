/* ACE2 Module: Exchangeable Armament System for Aircrafts (EASA) */
// (c) 2009 by rocko
//
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_logic);
TRACE_1("ACE_EASA Logic found and initializing",_logic);

private["_tmp_hangar","_hangar","_box","_dir","_pos","_action_holder","_no_hangar","_farp", "_nodamage", "_heightASL"];

_no_hangar = _logic getVariable ["NoHangar", false];

_lhd = _logic getVariable ["LHD", false];

_nodamage = _logic getVariable ["NoDamage", false];

_heightASL = _logic getVariable ["HeightASL", -999999];

// Track back
if (_lhd) then { _no_hangar = true; };

_farp = _logic getVariable ["FARP", false];

if (_no_hangar || {_farp}) then {
	_tmp_hangar = _logic;
} else {
	_tmp_hangar = nearestBuilding _logic;
};
if (!(_no_hangar || {_farp}) && {(!(_tmp_hangar isKindOf "Land_SS_Hangar") || {(_logic distance _tmp_hangar) > 10})} ) exitWith {
	WARNING("EASA ERROR: User");
	WARNING(localize "STR_ACE_EASA_ERR_2");
	if (!isMultiplayer && {local _logic}) then {
		0 spawn { sleep 1; (localize "STR_ACE_EASA_ERR_T") hintC [localize "STR_ACE_EASA_ERR_1"]; };
	};
};

_hangar = _tmp_hangar;
_tmp_hangar = nil;
TRACE_1("Valid hangar found","");

//_box = boundingBox _hangar; // unused variable
_dir = getDir _hangar;
_pos = getPosATL _hangar;

_action_holder = "ACE_EASA_Vehicle" createVehicle _pos;
if (_nodamage) then {
	_action_holder addEventHandler ["handleDamage", {0}];
};
if (_lhd) then { _action_holder setPosASL [_pos select 0, _pos select 1, 15.9]; };
if (_heightASL != -999999) then {_action_holder setPosASL [_pos select 0, _pos select 1, _heightASL]};
_action_holder setDir _dir;
_action_holder setVariable ["ACE_EASA_POS", _pos,true];

[_logic,_action_holder,"INIT"] call FUNC(rules);

player reveal _action_holder;

// TODO: Align _action_holder with hangar wall ?
// TODO: When "_farp" then there should be a FARP like