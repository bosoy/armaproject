//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090719
// Contact: http://creobellum.org
// Purpose: Setup and cache patrol squad - BIS_fnc_taskPatrol
///////////////////////////////////////////////////////////////////
if(!isServer) exitWith{};

_sl = _this select 0;
_dist = _this select 1;
waitUntil {!isNil "bis_fnc_init"};
call{[_sl, 1000] execVM "coop_essential\cep_cache_units.sqf"};
//[group _sl, position _sl, _dist] call BIS_fnc_taskPatrol;
call{[group _sl, position _sl, _dist] execVM "scripts\BIN_taskPatrol.sqf";};