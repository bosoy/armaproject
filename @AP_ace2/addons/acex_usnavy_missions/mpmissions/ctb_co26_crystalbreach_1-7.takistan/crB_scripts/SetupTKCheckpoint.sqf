//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090719
// Contact: http://creobellum.org
// Purpose: Setup Russian Roadblock with guards and patrols
///////////////////////////////////////////////////////////////////
//sleep 15 + random 45;

_obj = _this select 0;
_pos = position _obj;
_px = _pos select 0;
_py = _pos select 1;
_dir = direction _obj;

if(isNil "f_crB_CreateCompositionLocal") then {
	f_crB_CreateCompositionLocal = compile preprocessFileLineNumbers "crB_scripts\crB_CreateCompositionLocal.sqf";
};
if(isNil "f_crB_taskPatrol") then {
	f_crB_taskPatrol = compile preprocessFileLineNumbers "crb_scripts\crB_taskPatrol.sqf";
};
if(isNil "f_crB_spawnCrew") then {
	f_crB_spawnCrew = compile preprocessFileLineNumbers "crb_scripts\crB_spawnCrew.sqf";
};

["checkpoint1_tk", _dir, _pos] call f_crB_CreateCompositionLocal;
[_pos, 30, east] spawn f_crb_spawnCrew;
[[_px + 10, _py + 10], "Infantry", 150, "BIS_TK"] call f_crB_taskPatrol;