//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090719
// Contact: http://creobellum.org
// Purpose: Setup and cache random waypoint patrols
///////////////////////////////////////////////////////////////////
WP_MARKERS = 16;
if (!isServer) exitWith {};
sleep .1;
_vehicle = _this select 0;
_grp = group _vehicle;

call {[leader _grp, 1000] execVM "coop_essential\cep_cache_units.sqf"};

while {true} do {
	_wp_marker = format["wp_P%1", ceil(random WP_MARKERS)];
//	player sideChat format["WP %1", _wp_marker];
	_wp0 = _grp addWaypoint [markerPos _wp_marker, 0];
	_wp0 setWaypointCombatMode "RED";
	_wp0 setWaypointFormation "COLUMN";
	_wp0 setWaypointSpeed "LIMITED";
	_wp0 setWaypointBehaviour "SAFE";
	waitUntil{currentWaypoint _grp != 0};
	sleep 0.2;
};
