/* 
	Author: Benny
	Name: AI_TownPatrol.sqf
	Parameters:
	  0 - Team
	  1 - Town
	  2 - (Radius)
	Description:
	  This file is called upon a resistance / occupation patrol, AI will randomly patrol in towns, including the camps and the depots.
*/

Private ['_camps','_insert','_insertObject','_insertStep','_maxWaypoints','_pos','_radius','_rand1','_rand2','_team','_town','_townPos','_type','_update','_usable','_wpcompletionRadius','_wpradius','_wps','_z'];
_team = _this select 0;
_town = _this select 1;
_radius = if (count _this > 2) then {_this select 2} else {30};
if (typeName _town != 'OBJECT') exitWith {diag_log Format ["[WFBE (ERROR)] AI_TownPatrol: Object expected, %1 given",_town]};
if (isNull _team) exitWith {diag_log Format ["[WFBE (ERROR)] AI_TownPatrol: Null Groups cannot be used (Town: %1)",_town]};
_townPos = getPos _town;

_camps = _town getVariable 'camps';

_usable = [_town] + _camps;
_maxWaypoints = ('WFBE_TOWNPATROLHOPS' Call GetNamespace) + count(_usable);
_wps = [];

//--- Randomize the behaviours.
if (random 100 > 50) then {_team setFormation "DIAMOND"} else {_team setFormation "STAG COLUMN"};
if (random 100 > 50) then {_team setCombatMode "YELLOW"} else {_team setCombatMode "RED"};
if (random 100 > 50) then {_team setBehaviour "AWARE"} else {_team setBehaviour "COMBAT"};
if (random 100 > 50) then {_team setSpeedMode "NORMAL"} else {_team setSpeedMode "LIMITED"};

//--- Dyn insert.
_insertStep = if (count(_usable) != 0) then {floor(_maxWaypoints / count(_usable))} else {-1};
_insert = _insertStep;
_insertObject = objNull;
_wpradius = -1;
_wpcompletionRadius = -1;

for [{_z=0},{_z<=_maxWaypoints},{_z=_z+1}] do {
	if (_z == _insert && count _usable > 0) then {
		_insert = _insert + _insertStep;
		_insertObject = _usable select (round(random((count _usable)-1)));
		_usable = _usable - [_insertObject];
	};

	if (isNull _insertObject) then {
		_rand1 = random _radius;
		_rand2 = random _radius;
		_pos = [(_townPos select 0)+_rand1,(_townPos select 1)+_rand2,0];
        _tries = 100;
		while {surfaceIsWater _pos && _tries > 0} do {
              _tries = _tries - 1;
			_rand1 = random _radius;
			_rand2 = random _radius;
			_pos = [(_townPos select 0)+_rand1,(_townPos select 1)+_rand2,0];
		};
		_wpradius = 32;
		_wpcompletionRadius = 44;
	} else {
		_pos = getPos _insertObject;
		_wpradius = 35;
		_wpcompletionRadius = 68;
	};
	
	_type = if (_z != _maxWaypoints) then {'MOVE'} else {'CYCLE'};
	_wps = _wps + [[_pos,_type,_wpradius,_wpcompletionRadius, "", []]];
};

diag_log Format["[WFBE (INFORMATION)][frameno:%4 | ticktime:%5] AI_TownPatrol: The %1 %2 Team is patrolling the %3 town",side _team,_team,_town,diag_frameno,diag_tickTime];

[_team, true, _wps] Call AIWPAdd;