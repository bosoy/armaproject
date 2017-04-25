// Function file for Armed Assault
// Created by: -eutf-Myke
#define THIS_FILE "unload_static.sqf"
#include "x_setup.sqf"
private ["_vehicle","_engineer","_cargo","_ele","_static","_tr_cargo_array","_do_exit","_place_error","_pos_to_set","_dir_to_set","_type_name"];

PARAMS_2(_vehicle,_engineer);
_cargo = "";
_do_exit = false;

GVAR(cargo_selected_index) = -1;

_tr_cargo_array = GV(_vehicle,GVAR(CARGO_AR));
if (isNil "_tr_cargo_array") then {_tr_cargo_array = []};

if (!GVAR(with_ai) && GVAR(with_ai_features) != 0) then {
	if !(GVAR(string_player) in GVAR(is_engineer)) exitWith {hintSilent (localize "STR_DOM_MISSIONSTRING_79")};
};

if (vehicle _engineer == _vehicle) exitWith {hintSilent (localize "STR_DOM_MISSIONSTRING_80")};

if (count _tr_cargo_array > 0) then {
	GVAR(current_truck_cargo_array) = _tr_cargo_array;
	createDialog "XD_UnloadDialog";
} else {
	_do_exit = true;
};

if (_do_exit) exitWith {hintSilent (localize "STR_DOM_MISSIONSTRING_81")};

waitUntil {GVAR(cargo_selected_index) != -1 || !GVAR(unload_dialog_open) || !alive player};

if (!alive player) exitWith {if (GVAR(unload_dialog_open)) then {closeDialog 0}};

if (GVAR(cargo_selected_index) == -1) exitWith {(localize "STR_DOM_MISSIONSTRING_82") call FUNC(GlobalChat)};

if ((GVAR(cargo_selected_index) + 1) > count _tr_cargo_array) exitWith {
	hintSilent (localize "STR_DOM_MISSIONSTRING_83");
};

_cargo = _tr_cargo_array select GVAR(cargo_selected_index);
{
	if (_x == _cargo) exitWith {_tr_cargo_array set [_forEachIndex, -1]};
} forEach _tr_cargo_array;

_tr_cargo_array = _tr_cargo_array - [-1];
_vehicle setVariable [QGVAR(CARGO_AR), _tr_cargo_array, true];

_pos_to_set = _engineer modeltoworld [0,5,0];
_static = _cargo createVehicleLocal _pos_to_set;
_static lock true;
_dir_to_set = getdir _engineer;

_place_error = false;
(localize "STR_DOM_MISSIONSTRING_84") call FUNC(GlobalChat);
GVAR(e_placing_running) = 0; // 0 = running, 1 = placed, 2 = placing canceled
GVAR(e_placing_id1) = player addAction [(localize "STR_DOM_MISSIONSTRING_85") call FUNC(RedText), "x_client\x_cancelplacestatic.sqf"];
GVAR(e_placing_id2) = player addAction [(localize "STR_DOM_MISSIONSTRING_86") call FUNC(GreyText), "x_client\x_placestatic.sqf",[], 0];
while {GVAR(e_placing_running) == 0} do {
	_pos_to_set = _engineer modeltoworld [0,5,0];
	_dir_to_set = getdir _engineer;

	_static setPos [_pos_to_set select 0, _pos_to_set select 1, 0];
	_static setdir _dir_to_set;
	sleep 0.211;
	if (_vehicle distance _engineer > 20) exitWith {
		(localize "STR_DOM_MISSIONSTRING_87") call FUNC(GlobalChat);
		_place_error = true;
	};
	if (!alive _engineer || !alive _vehicle) exitWith {
		_place_error = true;
		if (GVAR(e_placing_id1) != -1000) then {
			player removeAction GVAR(e_placing_id1);
			GVAR(e_placing_id1) = -1000;
		};
		if (GVAR(e_placing_id2) != -1000) then {
			player removeAction GVAR(e_placing_id2);
			GVAR(e_placing_id2) = -1000;
		};
	};
};

deleteVehicle _static;

if (_place_error) exitWith {
	_tr_cargo_array set [count _tr_cargo_array, _cargo];
	_vehicle setVariable [QGVAR(CARGO_AR), _tr_cargo_array, true];
};

if (GVAR(e_placing_running) == 2) exitWith {
	(localize "STR_DOM_MISSIONSTRING_88") call FUNC(GlobalChat);
	_tr_cargo_array set [count _tr_cargo_array, _cargo];
	_vehicle setVariable [QGVAR(CARGO_AR), _tr_cargo_array, true];
};

_type_name = [_cargo,0] call FUNC(GetDisplayName);

_static = createVehicle [_cargo, _pos_to_set, [], 0, "NONE"];
_static setdir _dir_to_set;
_static setPos [_pos_to_set select 0, _pos_to_set select 1, 0];
player reveal _static;
[QGVAR(ad), _static] call FUNC(NetCallEventCTS);

_str_placed = format [(localize "STR_DOM_MISSIONSTRING_89"), _type_name];
hintSilent _str_placed;
_str_placed call FUNC(GlobalChat);
