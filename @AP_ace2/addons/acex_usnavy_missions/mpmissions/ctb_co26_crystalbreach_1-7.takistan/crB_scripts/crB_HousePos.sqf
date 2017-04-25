//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [CTB]
// Created: 20100705
// Modified: 20100706
// Contact: http://creobellum.org
// Purpose: Move or patrol a unit to random house positions
//
// The following code is an extract from Random Building Position Script v1.0 by Tophe of Östgöta Ops
// Usage:
// Move unit to random house position within 10m
// 0 = [this] execVM  "crB_scripts\crB_HousePos.sqf";
//
// Move unit to random house position within 50m
// 0 = [this, 50] execVM "crB_scripts\crB_HousePos.sqf";
//
// Patrol unit to random house positions within 50m with a maximum
// 	wait time 300 sec between positions
// 0 = [this, 50, true] execVM "crB_scripts\crB_HousePos.sqf";
//
// Patrol unit to random house positions within 50m with a maximum
// 	wait time 600 sec between positions
// 0 = [this, 50, true, 600] execVM "crB_scripts\crB_HousePos.sqf";
//////////////////////////////////////////////////////////////////
if (!isServer) exitwith {};
private["_obj","_radius","_patrol","_maxwait","_pos","_bldgpos","_i","_j","_nearbldgs"];
_obj = _this select 0;
_radius = 10;
if(count _this > 1) then {_radius = _this select 1;};
_patrol = false;
if(count _this > 2) then {_patrol = _this select 2;};
_maxwait = 300;
if(count _this > 3) then {_maxwait = _this select 3;};
_pos = getPos _obj;

_bldgpos = [];
_i = 0;
_j = 0;
_nearbldgs = nearestObjects [_pos, ["Building"], _radius];
{
	private["_y"];
	_y = _x buildingPos _i;
	while {format["%1", _y] != "[0,0,0]"} do {
		_bldgpos set [_j, _y];
		_i = _i + 1;
		_j = _j + 1;
		_y = _x buildingPos _i;
	};
	_i = 0;
} forEach _nearbldgs;

_pos = _bldgpos select floor(random count _bldgpos);
if(_patrol) then {
	_obj setSpeedMode "LIMITED";
} else {
//	_obj disableAI "MOVE";
//	_obj disableAI "TARGET";
	_obj setDir (random 360);
};
_obj setCombatMode "YELLOW";
_obj setPos _pos;
//waitUntil{unitReady _obj;};
while{_patrol && alive _obj} do {
	sleep (random _maxwait);
	_pos = _bldgpos select floor(random count _bldgpos);
	_obj move _pos;
//	waitUntil{unitReady _obj;};
//	_obj setDirection (random 360);
};
//////////////////////////////////////////////////////////////////
