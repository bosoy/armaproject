//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090719
// Modified: 20100418
// Contact: http://creobellum.org
// Purpose: Setup random patrol squad
///////////////////////////////////////////////////////////////////
if(!isServer) exitWith{};

private["_pos","_type","_dist","_fac","_grp","_code"];
_pos = _this select 0;
_type = _this select 1;
_dist = _this select 2;
_fac = nil;
if(count _this > 3) then {
	_fac = _this select 3;
};
_code = "";
if(count _this > 4) then {
	_code = _this select 4;
};

if(isNil "f_crB_randomGroup") then {
	f_crB_randomGroup = compile preprocessFileLineNumbers "crb_scripts\crB_randomGroup.sqf";
};

_grp = [_pos, _type, _fac] call f_crB_randomGroup;
call compile _code;
//[_grp, _grp, _dist, nil, nil, nil, nil, nil, nil, "this spawn CBA_fnc_searchNearby"] call CBA_fnc_taskPatrol;
call{[_grp, position leader _grp, _dist] execVM "scripts\BIN_taskPatrol.sqf";};
