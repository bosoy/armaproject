//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090910
// Contact: http://creobellum.org
// Purpose: Setup aerial patrol across map
// Usage: call{[rectMarker, spawnPos, spawnDelay(opt 600s default), faction(optional)] execVM "crB_scripts\crB_aerialPatrol.sqf";};
///////////////////////////////////////////////////////////////////
if (!isServer) exitWith{};

_mkr = _this select 0;
_startpos = _this select 1;
_delay = 600;
if (count _this > 2) then { _delay = _this select 2; };
_fac = nil;
if (count _this > 3) then { _fac = _this select 3; };

if(isNil "f_crB_randomGroup") then {
	f_crB_randomGroup = compile preprocessFileLineNumbers "crb_scripts\crB_randomGroup.sqf";
};

while{true} do {
	_grp = nil;
	while {isNil "_grp"} do {
		_grp = [_startpos, "Air", _fac] call f_crB_randomGroup;
	};
	_grp setVariable ["crB_disableCache", true];
	{_x setSkill 1;} count (units _grp);

	sleep 5;

	_px = (markerPos _mkr) select 0;
	_py = (markerPos _mkr) select 1;
	_sx = (markerSize _mkr) select 0;
	_sy = (markerSize _mkr) select 1;

	//titleText [format["Aerial patrol go! %1", _grp],"PLAIN"];
	while{({canMove _x && ((getPos _x select 2) + (_x distance (getPos _x)) > 5)} count (units _grp)) > 0} do {
		_pos = [_px + (random _sx) - (_sx / 2), _py + (random _sy) - (_sy / 2)];

		_grp move _pos;
		_grp setCombatMode "RED";
		_grp setBehaviour "COMBAT";
		waitUntil{leader _grp distance _pos < 150 || ({canMove _x && (count assignedVehicleRole _x) > 0} count (units _grp)) == 0};
	};
	{_x setDamage 1;} count (units _grp);
	sleep _delay;
};