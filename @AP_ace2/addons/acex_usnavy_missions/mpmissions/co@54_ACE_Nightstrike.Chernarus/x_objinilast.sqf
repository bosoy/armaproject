// by Xeno
private ["_dgrp", "_unit_array", "_pos", "_x_objs", "_fireone"];

if (!isServer) exitWith {};

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol6";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 350] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol6";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 350] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
_pos = markerPos "patrol6";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 350] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol7";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 350] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol7";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 350] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
_pos = markerPos "patrol7";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos, 350] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["bmp", "EAST"] call x_getunitliste;
_pos = markerPos "patrol8";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["bmp", "EAST"] call x_getunitliste;
_pos = markerPos "patrol8";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["tank", "EAST"] call x_getunitliste;
_pos = markerPos "patrol8";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["tank", "EAST"] call x_getunitliste;
_pos = markerPos "patrol8";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol13";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BI_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol13";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BI_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
_pos = markerPos "patrol10";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BI_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["specops", "EAST"] call x_getunitliste;
_pos = markerPos "patrol10";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BI_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol11";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BI_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol11";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BI_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol12";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BI_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["basic", "EAST"] call x_getunitliste;
_pos = markerPos "patrol12";
[_pos, (_unit_array select 0), _dgrp, false,false] call x_makemgroup;
[_dgrp, _pos] call BI_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["bmp", "EAST"] call x_getunitliste;
_pos = markerPos "patrol14";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos] call BI_fnc_taskDefend;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["bmp", "EAST"] call x_getunitliste;
_pos = markerPos "patrol14";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 2;

_dgrp = ["EAST"] call x_creategroup;
_unit_array = ["tank", "EAST"] call x_getunitliste;
_pos = markerPos "patrol14";
[1, _pos, (_unit_array select 2), (_unit_array select 1), _dgrp, 0, -1.111, false, false] call x_makevgroup;
[_dgrp, _pos, 200] call BI_fnc_taskPatrol;

sleep 2;

berezino_ready = true;

if (true) exitWith {};