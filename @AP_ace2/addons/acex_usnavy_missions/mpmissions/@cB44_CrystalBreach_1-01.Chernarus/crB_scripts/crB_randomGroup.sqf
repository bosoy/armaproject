//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]/(AEF)Odin [2CAV]
// Created: 20090819
// Contact: http://creobellum.org
// Purpose: Create function to randomly spawn OPFOR groups
// Parameter: position to spawn group
// Parameter: type = Infantry/Motorized/Mechanized/Armored/Air
// Parameter: (optional)radius = 0(Defend) or radius(Patrol)
///////////////////////////////////////////////////////////////////
if(!isServer) exitWith{};
private["_pos","_type","_grpx","_grps","_grp","_radius"];

_pos = _this select 0;
_type = _this select 1;

waitUntil {!isNil "bis_fnc_init"};

_grpx = count(configFile >> "CfgGroups" >> "East" >> "RU" >> _type);
_grps = [];
for "_x" from 1 to _grpx - 1 do {
	_grps = _grps + [(configFile >> "CfgGroups" >> "East" >> "RU" >> _type) select _x];
};
_grp = _grps select floor(random count _grps);
//		hint _grp;
_spawnGrp = [_pos, east, _grp] call BIS_fnc_spawnGroup;

if (count _this < 3) exitWith{_spawnGrp;};

// You will need scripts in place for this
_radius = _this select 2;
if (_radius > 0) then {
	call {[leader _spawnGrp, _radius] execVM "crb_scripts\crb_taskPatrol.sqf"};
} else {
	call {[leader _spawnGrp] execVM "crb_scripts\crb_taskDefend.sqf"};
};