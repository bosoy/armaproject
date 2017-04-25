// by Xeno
#define THIS_FILE "x_counterattack.sqf"
#include "x_setup.sqf"
private ["_dummy", "_numbervecs", "_xx", "_typeidx", "_nums", "_i"];
if (!isServer) exitWith {};

_dummy = GVAR(target_names) select __XJIPGetVar(GVAR(current_target_index));
_current_target_pos = _dummy select 0;
_current_target_radius = _dummy select 2;

_start_array = [_current_target_pos, _current_target_radius + 200] call FUNC(getwparray2);

_vecs_counter_attack = 5 call FUNC(RandomFloor);
if (_vecs_counter_attack < 2) then {_vecs_counter_attack = 2};
_numbervecs = _vecs_counter_attack - 2;
if (_numbervecs <= 0) then {_numbervecs = 1};

_type_list_attack = [["basic",0,ceil (random _vecs_counter_attack)],["specops",0,ceil (random _vecs_counter_attack)],["tank",(ceil random _numbervecs),ceil (random (_vecs_counter_attack - 1))],["bmp",(ceil random _numbervecs),ceil (random (_vecs_counter_attack - 1))]];

sleep 120 + random 120;

GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"CounterattackStarts",true];

for "_xx" from 0 to (count _type_list_attack - 1) do {
	_typeidx = _type_list_attack select _xx;
	_nums = _typeidx select 2;
	if (_nums > 0) then {
		for "_i" from 1 to _nums do {
			[_typeidx select 0, _start_array, _current_target_pos, _typeidx select 1, "attack",GVAR(enemy_side),0,-1.111] call FUNC(makegroup);
			sleep 5.123
		};
	};
};

_start_array = nil;
_type_list_attack = nil;

sleep 301.122;
GVAR(current_trigger) = [_current_target_pos, [350, 350, 0, false], [GVAR(enemy_side), "PRESENT", false], ["(""Tank"" countType thislist  < 2) && (""CAManBase"" countType thislist < 6)", "d_counterattack = false;deleteVehicle d_current_trigger", ""]] call FUNC(CreateTrigger);

_current_target_pos = nil;