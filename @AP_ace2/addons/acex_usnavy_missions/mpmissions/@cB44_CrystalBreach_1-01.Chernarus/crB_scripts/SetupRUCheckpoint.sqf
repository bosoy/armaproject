//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090719
// Contact: http://creobellum.org
// Purpose: Setup Russian Roadblock with guards and patrols
///////////////////////////////////////////////////////////////////
_obj = _this select 0;
_pos = position _obj;
_px = _pos select 0;
_py = _pos select 1;
_dir = direction _obj;

["checkpoint1_ru", _dir, _pos] call (compile (preprocessFile "scripts\CreateCompositionLocal.sqf"));
[_pos, 150] call (compile (preprocessFile "crb_scripts\crb_spawnCrew.sqf"));
call {[[_px + 2, _py + 3], "Infantry", 0] execVM "crb_scripts\crb_randomGroup.sqf"};
call {[[_px + 7, _py + 0], "Infantry", 100] execVM "crb_scripts\crb_randomGroup.sqf"};