//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090719
// Modified: 20100417
// Contact: http://creobellum.org
// Purpose: Setup and cache defensive squad - CBA_fnc_taskDefend
///////////////////////////////////////////////////////////////////
if(!isServer) exitWith{};

private["_pos","_type","_fac","_grp"];
_pos = _this select 0;
_type = _this select 1;
_fac = nil;
if(count _this > 2) then {
	_fac = _this select 2;
};

if(isNil "f_crB_randomGroup") then {
	f_crB_randomGroup = compile preprocessFileLineNumbers "crb_scripts\crB_randomGroup.sqf";
};

private["_grp"];
_grp = [_pos, _type, _fac] call f_crB_randomGroup;
//_grp setVariable ["crB_disableCache", true];
0 = [_grp, position leader _grp] execVM "scripts\BIN_taskDefend.sqf";
