private ["_dgrp", "_pos"];
if (!isServer) exitwith {};

sleep 30;

_x_objs = [markerPos "artillery", random 360, "Firebase1_RU"] call (compile (preprocessFileLineNumbers "ca\modules\dyno\data\scripts\objectMapper.sqf"));

{
	if (typeOf _x == "D30_RU" || typeOf _x == "KamazReammo") then {
		_x lock true;
		_x addEventHandler ["killed", {firebase_killed = firebase_killed + 1}];
	};
	allunits_add set [count allunits_add, _x];
} forEach _x_objs;

sleep 3;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "artillery";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BIS_fnc_taskDefend;

sleep 10;

_x_objs = [markerPos "supply_depot", random 0, "FuelDump1_RU"] call (compile (preprocessFileLineNumbers "ca\modules\dyno\data\scripts\objectMapper.sqf"));

{
	if (typeOf _x == "KamazRefuel") then {
		_x lock true;
		_x addEventHandler ["killed", {fuel_dump_down = true; publicVariable "fuel_dump_down"}];
	};
	allunits_add set [count allunits_add, _x];
} forEach _x_objs;

sleep 3;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "supply_depot";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BIS_fnc_taskDefend;

if (true) exitwith {};