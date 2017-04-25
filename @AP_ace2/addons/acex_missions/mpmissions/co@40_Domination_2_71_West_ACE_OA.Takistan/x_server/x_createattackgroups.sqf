// by Xeno
#define THIS_FILE "x_server\x_createattackgroups.sqf"
#define __DEBUG__
#include "x_setup.sqf"

private ["_selectit", "_selectitmen", "_selectitvec", "_trgobj", "_radius", "_xx", "_typeidx", "_nums", "_xxx", "_nrgs", "_point", "_ccc"];

if (!isServer) exitWith{};

//sleep 10;

// TODO: less players, less groups/armor
// TODO: No players, stop attack
// TODO: target clear, what happens ?
// TODO: footunits only via paradrop ? makes more sense, no need to let them run x kilometers

_selectit = {ceil (random (((_this select 0) select (_this select 1)) select 1))};

//_type_list_attack = [["basic",0],["specops",0],["tank", [GVAR(vehicle_numbers_attack), 1] call _selectit],["bmp",[GVAR(vehicle_numbers_attack), 1] call _selectit],["brdm",[GVAR(vehicle_numbers_attack), 2] call _selectit],["uaz_mg",[GVAR(vehicle_numbers_attack), 3] call _selectit],["uaz_grenade",[GVAR(vehicle_numbers_attack), 4] call _selectit],["shilka",[GVAR(vehicle_numbers_attack), 4] call _selectit]];
_type_list_attack = [["tank", [GVAR(vehicle_numbers_attack), 1] call _selectit],["bmp",[GVAR(vehicle_numbers_attack), 1] call _selectit],["brdm",[GVAR(vehicle_numbers_attack), 2] call _selectit],["uaz_mg",[GVAR(vehicle_numbers_attack), 3] call _selectit],["uaz_grenade",[GVAR(vehicle_numbers_attack), 4] call _selectit],["shilka",[GVAR(vehicle_numbers_attack), 4] call _selectit]];

_selectit = nil;

_selectitmen = {
	private ["_a_vng2","_num_ret"];
	_a_vng2 = (_this select 0) select (_this select 1);
	if ((_a_vng2 select 0) > 0) then {_num_ret = floor (random ((_a_vng2 select 0) + 1));if (_num_ret < (_a_vng2 select 1)) then {_a_vng2 select 1} else {_num_ret}} else {0}
};

_selectitvec = {
	private ["_a_vng","_a_vng2","_num_ret"];
	_a_vng = (_this select 0) select (_this select 1);
	_a_vng2 = _a_vng select 0;
	if ((_a_vng2 select 0) > 0) then {_num_ret = floor (random ((_a_vng2 select 0) + 1));if (_num_ret < (_a_vng2 select 1)) then {_a_vng2 select 1} else {_num_ret}} else {0}
};

_number_basic_attack = [GVAR(footunits_attack), 0] call _selectitmen;
_number_specops_attack = [GVAR(footunits_attack), 1] call _selectitmen;
_number_tank_attack = [GVAR(vehicle_numbers_attack),0] call _selectitvec;
_number_bmp_attack = [GVAR(vehicle_numbers_attack),1] call _selectitvec;
_number_brdm_attack = [GVAR(vehicle_numbers_attack),2] call _selectitvec;
_number_uaz_mg_attack = [GVAR(vehicle_numbers_attack),3] call _selectitvec;
_number_uaz_grenade_attack = [GVAR(vehicle_numbers_attack),4] call _selectitvec;
_number_shilka_attack = [GVAR(vehicle_numbers_attack),5] call _selectitvec;

_selectitmen = nil;
_selectitvec = nil;

sleep 0.112;

for "_xx" from 0 to (count _type_list_attack - 1) do {
	_typeidx = _type_list_attack select _xx;
	_nums = call compile format ["_number_%1_attack", _typeidx select 0];
	if (_nums > 0) then {
		for "_xxx" from 1 to _nums do {
			_rpos = [GVAR(enemyai_respawn_pos) select 0, 600, 400, GVAR(enemyai_respawn_pos) select 1] call FUNC(GetRanPointSquare);
			__TRACE_1("","_rpos")
			_camps = switch (GVAR(enemy_side)) do {
				case "EAST": {GVAR(west_camps)};
				case "WEST": {GVAR(east_camps)};
			};
			_target_pos = position (_camps call FUNC(RandomArrayVal));
			[_typeidx select 0, [_rpos], _target_pos, _typeidx select 1, "attackeMTWF", GVAR(enemy_side),0,-1.111,2] call FUNC(makegroup);
			sleep 0.4;
		};
	};
};

_type_list_attack = nil;

execVM "x_server\x_createparas.sqf";
