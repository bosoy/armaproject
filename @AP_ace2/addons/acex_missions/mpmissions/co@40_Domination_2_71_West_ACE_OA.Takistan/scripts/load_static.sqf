// Function file for Armed Assault
// Created by: -eutf-Myke
#define THIS_FILE "load_static.sqf"
#include "x_setup.sqf"
private ["_vehicle","_engineer","_cargo","_tr_cargo_array","_tr_full","_c_l","_alive","_cargo_type","_type_name"];

PARAMS_2(_vehicle,_engineer);
_cargo = objnull;

_tr_cargo_array = GV(_vehicle,GVAR(CARGO_AR));
if (isNil "_tr_cargo_array") then {_tr_cargo_array = []};

_doexit = false;
if (!GVAR(with_ai) && GVAR(with_ai_features) != 0) then {
	if !(GVAR(string_player) in GVAR(is_engineer)) then {
		hintSilent (localize "STR_DOM_MISSIONSTRING_68");
		_doexit = true;
	};
};

if (_doexit) exitWith {};

_tr_full = false;
if (count _tr_cargo_array >= GVAR(max_truck_cargo)) then {
	(format [(localize "STR_DOM_MISSIONSTRING_69"), GVAR(max_truck_cargo)]) call FUNC(GlobalChat);
	_tr_full = true;
};

if (_tr_full) exitWith {};

_cargo = nearestobject [_vehicle, "StaticWeapon"];
if (isNull _cargo) exitwith {hintSilent (localize "STR_DOM_MISSIONSTRING_70")};
if (!alive _cargo) exitWith {hintSilent (localize "STR_DOM_MISSIONSTRING_71")};
_cargo_type = typeof _cargo;
_type_name = [_cargo_type,0] call FUNC(GetDisplayName);
if (_cargo distance _vehicle > 10) exitwith {hintSilent format [(localize "STR_DOM_MISSIONSTRING_72"), _type_name]};
if (!alive _engineer) exitWith {};

_hxhx = __pGetVar(currently_loading);
if (isNil "_hxhx") then {_hxhx = false};
if (_hxhx) exitWith {(localize "STR_DOM_MISSIONSTRING_73") call FUNC(GlobalChat)};

__pSetVar ["currently_loading", true];
_tr_cargo_array = GV(_vehicle,GVAR(CARGO_AR));
if (isNil "_tr_cargo_array") then {_tr_cargo_array = []};
if (count _tr_cargo_array >= GVAR(max_truck_cargo)) then {
	(format [(localize "STR_DOM_MISSIONSTRING_69"), GVAR(max_truck_cargo)]) call FUNC(GlobalChat);
} else {
	_tr_cargo_array set [count _tr_cargo_array, _cargo_type];
	_vehicle setVariable [QGVAR(CARGO_AR), _tr_cargo_array, true];
};
_alive = true;
for "_i" from 10 to 1 step -1 do {
	hintSilent format [(localize "STR_DOM_MISSIONSTRING_74"), _type_name, _i];
	if (!alive _engineer || !alive _vehicle) exitWith {_alive = false};
	sleep 1;
};
if (_alive) then {
	deletevehicle _cargo;
	hintSilent format [(localize "STR_DOM_MISSIONSTRING_75"), _type_name];
};
__pSetVar ["currently_loading", false];
