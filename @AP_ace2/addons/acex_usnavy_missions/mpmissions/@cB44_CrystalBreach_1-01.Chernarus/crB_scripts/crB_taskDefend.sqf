//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090719
// Contact: http://creobellum.org
// Purpose: Setup and cache defensive squad - BIS_fnc_taskDefend
///////////////////////////////////////////////////////////////////
if(!isServer) exitWith{};

_sl = _this select 0;
_cache = false;
if(count _this > 1) then {
	_cache = _this select 1;
};

waitUntil {!isNil "bis_fnc_init"};
if (_cache) then {
	call{[_sl, 1000] execVM "coop_essential\cep_cache_units.sqf"};
}; // breaks BIS_fnc_taskDefend
//[group _sl, position _sl] call BIS_fnc_taskDefend;
call{[group _sl, position _sl] execVM "scripts\BIN_taskDefend.sqf";};