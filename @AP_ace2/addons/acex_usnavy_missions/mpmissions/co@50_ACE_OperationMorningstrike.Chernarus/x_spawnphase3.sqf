private ["_tent", "_dgrp", "_officer", "_pos"];

if (!isServer) exitwith {};

sleep 30;

_x_objs = [markerPos "hq", random 0, "Camp1_RU"] call (compile (preprocessFileLineNumbers "ca\modules\dyno\data\scripts\objectMapper.sqf"));

_tent = objNull;
{
	allunits_add set [count allunits_add, _x];
	if (typeOf _x == "Land_tent_east") then {
		_tent = _x;
	};
} forEach _x_objs;

_dgrp = ["EAST"] call x_creategroup;
_officer = _dgrp createUnit ["RU_Commander", markerPos "hq", [], 0, "FORM"];
[_officer] joinSilent _dgrp;
_officer addEventHandler ["killed", {officer_dead = officer_dead + 1}];
allunits_add set [count allunits_add, _officer];

_officer move position _tent;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "hq";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BIS_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 100] call BIS_fnc_taskPatrol;

sleep 5;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 100] call BIS_fnc_taskPatrol;

sleep 5;

_x_objs = [markerPos "hq_1", random 0, "Camp1_RU"] call (compile (preprocessFileLineNumbers "ca\modules\dyno\data\scripts\objectMapper.sqf"));

_tent = objNull;
{
	allunits_add set [count allunits_add, _x];
	if (typeOf _x == "Land_tent_east") then {
		_tent = _x;
	};
} forEach _x_objs;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_officer = _dgrp createUnit ["RU_Commander", markerPos "hq_1", [], 0, "FORM"];
[_officer] joinSilent _dgrp;
_officer addEventHandler ["killed", {officer_dead = officer_dead + 1}];
allunits_add set [count allunits_add, _officer];

_officer move position _tent;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "hq_1";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BIS_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 100] call BIS_fnc_taskPatrol;

sleep 5;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 100] call BIS_fnc_taskPatrol;

sleep 5;

_x_objs = [markerPos "hq_2", random 0, "Camp1_RU"] call (compile (preprocessFileLineNumbers "ca\modules\dyno\data\scripts\objectMapper.sqf"));

_tent = objNull;
{
	allunits_add set [count allunits_add, _x];
	if (typeOf _x == "Land_tent_east") then {
		_tent = _x;
	};
} forEach _x_objs;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_officer = _dgrp createUnit ["RU_Commander", markerPos "hq_2", [], 0, "FORM"];
[_officer] joinSilent _dgrp;
_officer addEventHandler ["killed", {officer_dead = officer_dead + 1}];
allunits_add set [count allunits_add, _officer];

_officer move position _tent;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "hq_2";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BIS_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 100] call BIS_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 100] call BIS_fnc_taskPatrol;

if (true) exitwith {};