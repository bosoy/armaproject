//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [CTB]
// Created: 20090719
// Modified: 20100713
// Contact: http://creobellum.org
// Purpose: Setup and cache random waypoint patrols
///////////////////////////////////////////////////////////////////
if (!isServer) exitWith {};

_vehicle = _this select 0;
_locs = _this select 1;
_grp = nil;
if(typeName _vehicle == "GROUP") then {
	_grp = _vehicle;
	_vehicle = leader _grp;
} else {
	_grp = group _vehicle;
};
_veh = vehicle _vehicle;
_drv = assignedDriver _vehicle;

while {true} do {
	_pos = _locs select floor(random count _locs);
	_wp0 = _grp addWaypoint [_pos, 0];
	_wp0 setWaypointCompletionRadius 100;
	switch{side _drv} do {
		case civilian: {
			_wp0 setWaypointBehaviour "SAFE";
		};
		case east: {
			_wp0 setWaypointCombatMode "RED";
			_wp0 setWaypointFormation "COLUMN";
			_wp0 setWaypointSpeed "LIMITED";
			_wp0 setWaypointBehaviour "SAFE";
		};
	};
	waitUntil{currentWaypoint _grp != 0 || vehicle _drv == _drv};
	if(side _drv == civilian) then {
		_veh setDamage 0;
		_drv setDamage 0;
		_veh setPos (getPos _veh);
		[_drv] orderGetIn true;
	};
	sleep random 120;
};
