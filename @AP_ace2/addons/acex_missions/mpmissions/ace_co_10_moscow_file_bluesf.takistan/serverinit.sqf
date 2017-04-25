private ["_sortDistance", "_countBuildingPos", "_staticEnemies", "_staticEnemiesCount", "_patrolGroups", "_patrolGroupsCount", "_blackList", "_bOK", "_initialObjectsArray", "_enterableBuildingsArray", "_objectiveBuilding", "_missionObjectsArray", "_maxEnemiesInBuildings", "_enemiesInBuildings", "_buildingCount", "_buildingIndex", "_building", "_posCount", "_posArray", "_posIndex", "_maxEnemiesOutside", "_enemiesOutside", "_enemyPatrolGroups", "_safePos", "_group", "_groupSize", "_params", "_startDistance"];

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
	_staticEnemies set [count _staticEnemies, missionNameSpace getVariable (format ["e%1", _staticEnemiesCount])];
	_staticenemiesCount = _staticEnemiesCount + 1;
};

_patrolGroups = [];
_patrolGroupsCount = 0;
while {!isNil (format ["ge%1", _patrolGroupsCount])} do
{
	_patrolGroups set [count _patrolGroups, missionNameSpace getVariable (format ["ge%1", _patrolGroupsCount])];
	_patrolGroupsCount = _patrolGroupsCount + 1;
};

_blackList = ["blackZone1", "blackZone2", "blackZone3"];
_bOK = false;
while {!_bOK} do
{
	
	"mrk1" setMarkerPos [300 + random 12000, 300 + random 12000];
	_initialObjectsArray = (markerPos "mrk1") nearObjects ["house", 2000];
	
	_enterableBuildingsArray = [];
	{
		if (((_x buildingPos 0) select 0) != 0 || ((_x buildingPos 0) select 1) != 0 || ((_x buildingPos 0) select 2) != 0) then
		{
			_enterableBuildingsArray set [count _enterableBuildingsArray, _x];
		};
	} forEach _initialObjectsArray;
	
	
	_objectiveBuilding = _enterableBuildingsArray select (floor (random (count _enterableBuildingsArray)));
	
	_bOK = true;
	
	{
		if ((getPos _objectiveBuilding) distance (markerPos _x) < ((markerSize _x) select 0)) then
		{
			_bOK = false;
		};
	} forEach _blackList;

};

"mrk1" setMarkerPos getPos _objectiveBuilding;
"mrk1" setMarkerSize [25 * sqrt (enemyCount), 25 * sqrt (enemyCount)];
"mrkObj" setMarkerPos getPos _objectiveBuilding;
trgEx setPos getPos _objectiveBuilding;

_missionObjectsArray = (getPos _objectiveBuilding) nearObjects ["house", 20 + 12 * (sqrt enemyCount)];

_enterableBuildingsArray = [];
{
	if (((_x buildingPos 0) select 0) != 0 || ((_x buildingPos 0) select 1) != 0 || ((_x buildingPos 0) select 2) != 0) then
	{
		_enterableBuildingsArray set [count _enterableBuildingsArray, _x];
	};
} forEach _missionObjectsArray;

_enterableBuildingsArray = [_enterableBuildingsArray, getPos _objectiveBuilding] call _sortDistance;

_maxEnemiesInBuildings = floor (enemyCount * 0.8);
_enemiesInBuildings=0;
_buildingCount = count _enterableBuildingsArray;
_buildingIndex=0;
while {_enemiesInBuildings < _maxEnemiesInBuildings && _buildingIndex < _buildingCount} do
{
	if (random 1 < 0.8 || _buildingIndex==0) then
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
			if (random 1 < 0.5 || _enemiesInBuildings == 0) then
			{
				_enemy = _staticEnemies select _enemiesInBuildings;
				_safePos = [getPos _building, 0, 30, 0, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
				_enemy setPos _safePos;
				_enemy doMove (_building buildingPos _posIndex);
				_enemiesInBuildings = _enemiesInBuildings + 1;
			};
		};
	};
	_buildingIndex=_buildingIndex+1;
};

_maxEnemiesOutside = enemyCount - _enemiesInBuildings;
_enemiesOutside=0;
_enemyPatrolGroups=0;
while {_enemiesOutside<_maxEnemiesOutside} do
{
	_safePos = [getPos _objectiveBuilding, 0, 25 * sqrt (enemyCount), 0, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
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

_safePos = [getPos _objectiveBuilding, 7, 250, 0, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
veh1 setPos _safePos;
[veh1, "mrk1"] execVM "scripts\UPSMON.sqf";

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

// starting position

_bOK = false;
while {!_bOK} do
{
	_startDistance = 650 + random 70;
	startDir = random 360;
	startPos = [
		(getPos _objectiveBuilding select 0) + _startDistance * (sin (startDir + 180)),
		(getPos _objectiveBuilding select 1) + _startdistance * (cos (startDir + 180))
	];
	startPos = [startPos, 0, 70, 0, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
	if ((startPos select 0) != 1) then
	{
		_bOK=true;
	};
};
{
	_x setDir startDir;
	_x setPos startPos;
} forEach blueforUnits;

objPos = getPos _objectiveBuilding;
publicVariable "objPos";
publicVariable "startPos";
publicVariable "startDir";