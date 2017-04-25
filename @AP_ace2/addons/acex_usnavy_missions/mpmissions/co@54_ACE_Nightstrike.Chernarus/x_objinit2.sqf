// by Xeno
private ["_dgrp", "_unit_array", "_pos", "_x_objs", "_fireone"];

if (!isServer) exitWith {};

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
_pos = markerPos "patrol2";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;
sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
_pos = markerPos "patrol2x";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;
sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
_pos = markerPos "patrol2xx";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;
sleep 2;

{

	_dgrp = ["EAST"] call x_creategroup;
	_unit_array = [_x, "EAST"] call x_getunitliste;
	_pos = markerPos "patrol1";
	[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
	[_dgrp, _pos, 150] call BI_fnc_taskPatrol;
	sleep 2;
} forEach ["basic","specops","specops"];

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = position fire1;
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BI_fnc_taskDefend;
sleep 2;

_x_objs = [markerPos "patrol1", random 0, "MediumTentCamp_RU"] call (compile (preprocessFileLineNumbers "ca\modules\dyno\data\scripts\objectMapper.sqf"));

_fireone = objNull;
{
	if (_x isKindOf "ReammoBox") then {
		deleteVehicle _x;
	} else {
		if (_x isKindOf "Car" || _x isKindOf "Tank") then {
			_x lock true;
		};
		allunits_add set [count allunits_add, _x];
		if (typeOf _x == "Land_Campfire") then {_fireone = _x};
	};
} forEach _x_objs;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol1";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
if (!isNull _fireone) then {
	((units _dgrp) select 0) action ["FireInFlame",_fireone];
	sleep 1;
};
[_dgrp, _pos] call BI_fnc_taskDefend;

if (true) exitWith {};