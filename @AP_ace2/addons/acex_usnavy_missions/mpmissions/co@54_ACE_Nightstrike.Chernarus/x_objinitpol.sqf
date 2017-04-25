// by Xeno
private ["_dgrp", "_unit_array", "_pos", "_x_objs", "_fireone"];

if (!isServer) exitWith {};

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol3";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 350] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol3";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 350] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol3";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 350] call BI_fnc_taskPatrol;

sleep 2;

_x_objs = [markerPos "crewmark", 315, "MediumTentCamp2_RU"] call (compile (preprocessFileLineNumbers "ca\modules\dyno\data\scripts\objectMapper.sqf"));

_fireone = objNull;
{
	if (_x isKindOf "ReammoBox") then {
		deleteVehicle _x;
	} else {
		if (_x isKindOf "Car" || _x isKindOf "Tank") then {
			_x lock true;
		};
		allunits_add set [count allunits_add, _x];
	};
} forEach _x_objs;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["crew", "EAST"] call x_getunitliste;
_pos = markerPos "crewmark";
d_tankunits = [_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BI_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["bmp", "EAST"] call x_getunitliste;
_pos = markerPos "polmark";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 7;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["bmp", "EAST"] call x_getunitliste;
_pos = markerPos "polmark";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 7;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["brdm", "EAST"] call x_getunitliste;
_pos = markerPos "polmark";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 7;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "polmark";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
_pos = markerPos "polmark";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "polmark";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 60;

for "_i" from 1 to 4 do {
	_dgrp = ["EAST"] call x_creategroup;
	_unit_array = ["basic", "EAST"] call x_getunitliste;
	_pos = markerPos "patrol4";
	[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
	[_dgrp, _pos, 300] call BI_fnc_taskPatrol;

	sleep 2;
};

for "_i" from 1 to 4 do {
	_dgrp = ["EAST"] call x_creategroup;
	_unit_array = ["basic", "EAST"] call x_getunitliste;
	_pos = markerPos "gormarker";
	[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
	[_dgrp, _pos, 300] call BI_fnc_taskPatrol;

	sleep 2;
};

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
_pos = markerPos "gormarker";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["bmp", "EAST"] call x_getunitliste;
_pos = markerPos "gormarker";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["bmp", "EAST"] call x_getunitliste;
_pos = markerPos "gormarker";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["brdm", "EAST"] call x_getunitliste;
_pos = markerPos "gormarker";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["brdm", "EAST"] call x_getunitliste;
_pos = markerPos "gormarker";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

if (true) exitWith {};