Private ["_destination","_maxWaypoints","_pos","_radius","_rand1","_rand2","_team","_type","_update","_wps","_z"];
_team = _this select 0;
_destination = _this select 1;
_radius = if (count _this > 2) then {_this select 2} else {30};
if (typeName _destination == 'OBJECT') then {_destination = getPos _destination};

_update = true;
if (side _team == west || side _team == east) then {
	_update = (_team) Call CanUpdateTeam;
};

//--- Override.
if (_update) then {_team Call UpdateTeam};

_maxWaypoints = 8;
_wps = [];
for [{_z=0},{_z<=_maxWaypoints},{_z=_z+1}] do {
    _rand1 = (random _radius) - (random _radius);
    _rand2 = (random _radius) - (random _radius);
	_pos = [(_destination select 0)+_rand1,(_destination select 1)+_rand2,0];
     _tries = 100;
	while {surfaceIsWater _pos && _tries > 0} do {
        _tries = _tries - 1;
        _rand1 = (random _radius) - (random _radius);
        _rand2 = (random _radius) - (random _radius);
		_pos = [(_destination select 0)+_rand1,(_destination select 1)+_rand2,0];
	};
	_type = if (_z != _maxWaypoints) then {'MOVE'} else {'CYCLE'};
	_wps = _wps + [[_pos,_type,35,40,"",[]]];
};

diag_log Format["[WFBE (INFORMATION)][frameno:%4 | ticktime:%5] AI_Patrol: The %1 %2 Team is patrolling at %3",side _team,_team,_destination,diag_frameno,diag_tickTime];

[_team, true, _wps] Call AIWPAdd;