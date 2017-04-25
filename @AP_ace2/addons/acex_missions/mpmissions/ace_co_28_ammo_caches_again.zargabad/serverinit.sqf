private ["_objPos", "_safePos1", "_safePos2", "_realObjPos"];

_sortDistance =
{
	private ["_unsorted", "_sorted", "_pos", "_closest"];
	
	_unsorted = _this select 0;
	_sorted = [];
	_pos = _this select 1;

	for "_i" from 1 to (count _unsorted) do
	{
		_closest = _unsorted select 0;
		{
			if ((_x distance _pos) < (_closest distance _pos)) then
			{
				_closest = _x;
			};
		} forEach _unsorted;
		_sorted = _sorted + [_closest];
		_unsorted = _unsorted - [_closest];
	};

	_sorted
};

_countBuildingPos =
{
	// returns number of BIS positions in building
	
	private ["_building", "_i", "_bPos"];
	
	_building = _this select 0;
	_i=0;
	_bPos = _building buildingPos _i;
	
	while
	{
		((_bPos select 0) != 0) ||
		((_bPos select 1) != 0) ||
		((_bPos select 2) != 0)
	} do
	{
		_i=_i+1;
		_bPos = _building buildingPos _i;
	};
	
	_i;
};

_staticEnemies = [];
_staticEnemiesCount = 0;
while {!isNil (format ["e%1", _staticEnemiesCount])} do
{
	_staticEnemies set [_staticEnemiesCount, missionNameSpace getVariable (format ["e%1", _staticEnemiesCount])];
	_staticenemiesCount = _staticEnemiesCount + 1;
};

_patrolGroups = [];
_patrolGroupsCount = 0;
while {!isNil (format ["ge%1", _patrolGroupsCount])} do
{
	_patrolGroups set [_patrolGroupsCount, missionNameSpace getVariable (format ["ge%1", _patrolGroupsCount])];
	_patrolGroupsCount = _patrolGroupsCount + 1;
};

_reinfGroups = [];
_reinfGroupsCount = 0;
while {!isNil (format ["re%1", _reinfGroupsCount])} do
{
	_reinfGroups set [_reinfGroupsCount, missionNameSpace getVariable (format ["re%1", _reinfGroupsCount])];
	_reinfGroupsCount = _reinfGroupsCount + 1;
};

_reinfVehicles = [];
_reinfVehiclesCount = 0;
while {!isNil (format ["ve%1", _reinfVehiclesCount])} do
{
	_reinfVehicles set [_reinfVehiclesCount, missionNameSpace getVariable (format ["ve%1", _reinfVehiclesCount])];
	_reinfVehiclesCount = _reinfVehiclesCount + 1;
};

_bCont1 = true;
while {_bCont1} do
{
	_minX = markerPos "mrkSWcorner" select 0;
	_maxX = markerPos "mrkNEcorner" select 0;
	_minY = markerPos "mrkSWcorner" select 1;
	_maxY = markerpos "mrkNEcorner" select 1;
	_randomPos = [_minX + random (_maxX-_minX), _minY + random (_maxY-_minY)];
	_safePos1 = [_randomPos, 0, 40, 2, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
	if ((_safePos1 select 0) != 1) then
	{
		_bCont2=true;
		while {_bCont2} do
		{
			_safePos2 = [_randomPos, 0, 40, 2, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
			if (_safePos2 distance _safePos1 > 20) then
			{
				_bCont2=false;
			};
		};
		
		if ((_safePos2 select 0) != 1) then
		{
			_bCont1 = false;
			obj1 setPos _safePos1;
			obj2 setPos _safePos2;
			_realObjPos = [((_safePos1 select 0) + (_safePos2 select 0))/2, ((_safePos1 select 1) + (_safePos2 select 1))/2];
			_randomDir = random 360;
			_randomDist = 25 * (sqrt (random 1));
			_objPos = [(_realObjPos select 0) + _randomDist * (sin _randomDir), (_realObjPos select 1) + _randomDist * (cos _randomDir)];
			"mrkObj" setMarkerPos _objPos;
			objPos = _objPos;
			publicVariable "objPos";
		};
	};
};

"mrk1" setMarkerPos _realObjPos;
"mrk1" setMarkerSize [35 + 7 * sqrt (enemyCount), 35 + 7 * sqrt (enemyCount)];
trgReinf setPos _realObjPos;
trgReinf setTriggerArea [(1 + (random 1)) * (150 + 10 * sqrt (enemyCount)), (1 + (random 1)) * (150 + 10 * sqrt (enemyCount)), random 360, false];

_missionObjectsArray = _realObjPos nearObjects ["house", 50 + 7*(sqrt enemyCount)];

_enterableBuildingsArray = [];
{
	if (((_x buildingPos 0) select 0) != 0 || ((_x buildingPos 0) select 1) != 0 || ((_x buildingPos 0) select 2) != 0) then
	{
		_enterableBuildingsArray set [count _enterableBuildingsArray, _x];
	};
} forEach _missionObjectsArray;

_enterableBuildingsArray = [_enterableBuildingsArray, _realObjPos] call _sortDistance;

_maxEnemiesInBuildings = floor (enemyCount * (0.55 + (random 0.2)));
_enemiesInBuildings=0;
_buildingCount = count _enterableBuildingsArray;
_buildingIndex=0;
while {_enemiesInBuildings < _maxEnemiesInBuildings && _buildingIndex < _buildingCount} do
{
	if (random 1 < 0.7) then
	{
		_building = _enterableBuildingsArray select _buildingIndex;
		_posCount = [_building] call _countBuildingPos;
		_posArray=[];
		for "_i" from 0 to (_posCount-1) do
		{
			_posArray set [count _posArray, _i];
		};
		while {count _posArray > 0 && _enemiesInBuildings < _maxEnemiesInBuildings} do
		{
			_posIndex = _posArray select (floor random count _posArray);
			_posArray = _posArray - [_posIndex];
			if (random 1 < 0.3 || _enemiesInBuildings == 0) then
			{
				_enemy = _staticEnemies select _enemiesInBuildings;
				_safePos = [getPos _building, 0, 30, 0, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
				_enemy setPos _safePos;
				_enemy doMove (_building buildingPos _posIndex);
				[_enemy, "mrk1", "NOWP3"] execVM "scripts\UPSMON.sqf";
				_enemiesInBuildings = _enemiesInBuildings + 1;
			};
		};
	};
	_buildingIndex=_buildingIndex+1;
};

_maxEnemiesFar = floor ((0.15 + (random 0.1))*enemyCount);

_maxEnemiesOutside = enemyCount - _enemiesInBuildings;
if (_maxEnemiesOutside<=_maxEnemiesFar) then
{
	_maxEnemiesOutside = _maxEnemiesFar + 1;
};
_enemiesOutside=0;
_enemyPatrolGroups=0;
while {_enemiesOutside<_maxEnemiesOutside-_maxEnemiesFar} do
{
	_safePos = [_realObjPos, 0, 70, 0, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
	_group = _patrolGroups select _enemyPatrolGroups;
	{
		_x setPos _safePos;
	} forEach units _group;
	_groupSize = count units _group;
	for "_i" from 0 to (_groupSize-1) do
	{
		if (_i<2 || _enemiesOutside<_maxEnemiesOutside) then
		{
			_enemiesOutside = _enemiesOutside + 1;
		}
		else
		{
			deleteVehicle ((units _group) select (1 + floor (random ((count units _group) - 1))));
		};
	};
	_params = [units _group select 0, "mrk1"];
	if (random 1 < 0.75) then
	{
		_params set [count _params, "NOFOLLOW"];
	};
	if (random 1 < 0.4) then
	{
		_params set [count _params, "AMBUSH"];
	};
	_params execVM "scripts\UPSMON.sqf";
	_enemyPatrolGroups = _enemyPatrolGroups + 1;
};

if (_enemiesOutside>=_maxEnemiesOutside) then
{
	_maxEnemiesOutside = _enemiesOutside+1;
};

while {_enemiesOutside<_maxEnemiesOutside} do
{
	_safePos = [_realObjPos, 0, 120 + 15 * (sqrt enemyCount), 0, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
	_group = _patrolGroups select _enemyPatrolGroups;
	{
		_x setPos _safePos;
	} forEach units _group;
	_groupSize = count units _group;
	for "_i" from 0 to (_groupSize-1) do
	{
		if (_i<2 || _enemiesOutside<_maxEnemiesOutside) then
		{
			_enemiesOutside = _enemiesOutside + 1;
		}
		else
		{
			deleteVehicle ((units _group) select (1 + floor (random ((count units _group) - 1))));
		};
	};
	_params = [units _group select 0, "mrk1"];
	if (random 1 < 0.6) then
	{
		_params set [count _params, "FORTIFY"];
	};
	_params execVM "scripts\UPSMON.sqf";
	_enemyPatrolGroups = _enemyPatrolGroups + 1;
};

_maxReinf = 2 + floor (enemyCount/7);
_reinf=0;
_enemyReinfGroups=0;
reinfGroupsArr = [];
while {_reinf<_maxReinf} do
{
	_group = _reinfGroups select _enemyReinfGroups;
	_groupSize = count units _group;
	for "_i" from 0 to (_groupSize-1) do
	{
		if (_i<2 || _reinf<_maxReinf) then
		{
			_reinf = _reinf + 1;
		}
		else
		{
			deleteVehicle ((units _group) select (1 + floor (random ((count units _group) - 1))));
		};
	};
	reinfGroupsArr set [_enemyReinfGroups, _group];
	_units = units _group;
	_vehicle = _reinfVehicles select _enemyReinfGroups;
	if (_enemyReinfGroups%2==0) then
	{
		(_units select 0) moveInDriver _vehicle;
		(_units select 1) moveInGunner _vehicle;
		if (count _units>2) then
		{
			(_units select 2) moveInCargo _vehicle;
		};
	}
	else
	{
		(_units select 1) moveInDriver _vehicle;
		{
			_x moveInCargo _vehicle;
		} forEach (_units - [_units select 1]);
	};
	_enemyReinfGroups = _enemyReinfGroups + 1;
};

// delete leftovers

while {_enemiesInBuildings < _staticEnemiesCount} do
{
	deleteVehicle (_staticEnemies select _enemiesInBuildings);
	_enemiesInBuildings = _enemiesInBuildings + 1;
};

while {_enemyPatrolGroups < _patrolGroupsCount} do
{
	{
		deleteVehicle _x;
	} forEach units (_patrolGroups select _enemyPatrolGroups);
	_enemyPatrolGroups = _enemyPatrolGroups + 1;
};

while {_enemyReinfGroups < _reinfGroupsCount} do
{
	{
		deleteVehicle _x;
	} forEach units (_reinfGroups select _enemyReinfGroups);
	deleteVehicle (_reinfVehicles select _enemyReinfGroups);
	_enemyReinfGroups = _enemyReinfGroups + 1;
};