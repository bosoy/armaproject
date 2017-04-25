//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090910
// Contact: http://creobellum.org
// Purpose: Setup aerial patrol across map
///////////////////////////////////////////////////////////////////
if (!isServer) exitWith{};

_mkr = _this select 0;
_startpos = _this select 1;

_grp = createGroup east;
waitUntil {!isNil "bis_fnc_init"};
while{true} do {
	sleep 120;
	_grp = configFile >> "CfgGroups" >> "East" >> "RU" >> "Air";
	_grpx = count(_grp);
	_grps = [];
	for "_x" from 1 to _grpx - 1 do {
		_grps = _grps + [_grp select _x];
	};
	_grp = _grps select floor(random count _grps);
	//	hint _grp;
	_grp = [_startpos, east, _grp] call BIS_fnc_spawnGroup;
	_size = 0;
	if (markerSize _mkr select 0 > markerSize _mkr select 1) then {
		_size = markerSize _mkr select 0;
	} else {
		_size = markerSize _mkr select 1;
	};
	//call{[_grp, markerPos _mkr, _size] execVM "scripts\BIN_taskPatrol.sqf";};
	[_grp, markerPos _mkr, _size] call BIS_fnc_taskPatrol;
	//titleText [format["Aerial patrol go! %1", _grp],"PLAIN"];
	waitUntil{{canMove _x} count (units _grp) == 0};
};