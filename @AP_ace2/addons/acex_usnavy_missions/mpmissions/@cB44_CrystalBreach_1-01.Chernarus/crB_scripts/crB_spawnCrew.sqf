//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090922
// Contact: http://creobellum.org
// Purpose: Crew all positions within a perimeter
// Parameter: position to search
// Parameter: Search distance
// Parameter: (optional) Group to join
///////////////////////////////////////////////////////////////////
if(!isServer) exitWith{};

_pos = _this select 0;
_dist = _this select 1;

_grp = createGroup east;
if(count _this > 2) then {
	_grp = _this select 2;
};

waitUntil {!isNil "bis_fnc_init"};

_list = _pos nearObjects ["AllVehicles", _dist];
{
	[_x, _grp] call BIS_fnc_spawnCrew;
} forEach _list;
