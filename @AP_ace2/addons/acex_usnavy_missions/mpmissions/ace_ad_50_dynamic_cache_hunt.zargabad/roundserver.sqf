private ["_westNames", "_eastNames", "_safePos1", "_safePos2", "_safePos3", "_bCont1", "_bCont2", "_dir", "_dist", "_eastUnitArr", "_westUnitArr", "_westWin", "_eastWin", "_eastUnitCount", "_westUnitCount", "_minX", "_maxX", "_minY", "_maxY"];

_westNames = ["SLUS", "RifleUS", "GLUS", "MarksmanUS", "MGUS", "RifleUS1", "RifleUS2", "GLUS1", "MarksmanUS1", "MGUS1", "RifleUS3", "RifleUS4", "GLUS2", "MarksmanUS2", "MGscopeUS", "RifleUS5", "RifleUS6", "GLUS3", "MarksmanUS3", "MGscopeUS1", "RifleUSA", "RifleUSB", "GLUS4", "MarksmanUS4", "MGUS2"];
_eastNames = ["SLTK", "RifleTK", "GLTK", "MarksmanTK", "MGTK", "RifleTK1", "RifleTK2", "GLTK1", "MarksmanTK1", "MGTK1", "RifleTK3", "RifleTK4", "GLTK2", "MarksmanTK2", "MGScopeTK", "RifleTK5", "RifleTK6", "GLTK3", "MarksmanTK3", "MGScopeTK1", "RifleTKA", "RifleTKB", "GLTK4", "MarksmanTK4", "MGTK2"];

scoreW=0;
publicVariable "scoreW";
scoreE=0;
publicVariable "scoreE";

[] spawn
{
	while {true} do
	{
		sleep .01;
		{
			if (alive _x && (!isPlayer _x)) then
			{
				removeAllWeapons _x;
				missionNameSpace setVariable [format ["%1connected", vehicleVarName _x], false];
			};
		} forEach allUnits;
	};
};

while {true} do
{
	[] spawn
	{
		private ["_count"];
		while {!roundInProgress} do
		{
			{
				_x allowDamage false;
			} forEach allUnits;
			_count = count allUnits;
			waitUntil {roundInProgress || _count!=count allUnits};
		};
	};
	
	roundInProgress=false;
	publicVariable "roundInProgress";
	bLastPlayersCountdown = false;
	publicVariable "bLastPlayersCountdown";
	
	obj1 = createVehicle ["TKVehicleBox_EP1", [2,2], [], 0, "NONE"];
	obj1 setDammage 0.75;
	obj2 = createVehicle ["TKVehicleBox_EP1", [4,4], [], 0, "NONE"];
	obj2 setDammage 0.75;
	_bCont1=true;
	while {_bCont1} do
	{
		_minX = markerPos "mrkSWcorner" select 0;
		_maxX = markerPos "mrkNEcorner" select 0;
		_minY = markerPos "mrkSWcorner" select 1;
		_maxY = markerpos "mrkNEcorner" select 1;
		eastStartPos = [_minX + random (_maxX-_minX), _minY + random (_maxY-_minY)];
		_safePos1 = [eastStartPos, 0, 35, 2, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
		if ((_safePos1 select 0) != 1) then
		{
			_bCont2=true;
			while {_bCont2} do
			{
				_safePos2 = [eastStartPos, 0, 30, 2, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
				if (_safePos2 distance _safePos1 > 18) then
				{
					_bCont2=false;
				};
			};
			
			if ((_safePos2 select 0) != 1) then
			{
				obj1 setPos _safePos1;
				obj2 setPos _safePos2;
				_safePos3 = [((_safePos1 select 0) + (_safePos2 select 0)) / 2, ((_safePos1 select 1) + (_safePos2 select 1)) / 2];
				_safePos3 = [_safePos3, 0, 20, 2, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
				if ((_safePos3 select 0) != 1) then
				{
					eastStartPos=_safePos3;
					_bCont1=false;
				};
			};
		};
	};
	
	_dir = random 360;
	_dist = 65 * (sqrt (random 1));
	objPos = [(((_safePos1 select 0) + (_safePos2 select 0)) / 2) + _dist*(sin _dir), (((_safePos1 select 1) + (_safePos2 select 1)) / 2) + _dist*(sin _dir)];
	obj1Pos = _safePos1;
	obj2Pos = _safePos2;
	publicVariable "obj1Pos";
	publicVariable "obj2Pos";
	publicVariable "objPos";
	publicVariable "eastStartPos";
	
	_bCont1=true;
	while {_bCont1} do
	{
		_dist = minDist + random (maxDist - minDist);
		westStartDir = random 360;
		westStartPos = [(objPos select 0) + _dist*(sin (westStartDir+180)), (objPos select 1) + _dist*(cos (westStartDir+180))];
		_safePos1 = [westStartPos, 0, 30, 2, 0, 1, 0, [], [[1,1,1],[1,1,1]]] call BIS_fnc_findSafePos;
		if ((_safePos1 select 0) != 1) then
		{
			_bCont1=false;
		};
	};
	publicVariable "westStartPos";
	publicVariable "westStartDir";
	
	roundStartTime = time+setupTime;
	publicVariable "roundStartTime";
	setupReady=true;
	publicVariable "setupReady";
	
	sleep setupTime;
	
	{
		if (!isNull _x) then
		{
			if (_x isKindOf "MAN") then
			{
				if (!isPlayer _x) then
				{
					deleteVehicle _x;
				}
				else
				{
					[_x] spawn
					{
						_unit = _this select 0;
						waitUntil {!isPlayer _unit};
						deleteVehicle _unit;
					};
				};
			};
		};
	} forEach allDead;
	
	_toDelete = nearestObjects [markerPos "eaststart", ["weaponholder","Bag_Base_EP1", "ACE_Explosive_Object", "ACE_M86PDM_Object", "ACE_BreachObject", "Default"],10000];
	for "_i" from 0 to ((count _toDelete) - 1) do {
		deleteVehicle (_toDelete select _i);
	};
	
	roundEnd=0;
	publicVariable "roundEnd";
	roundEndTime = time + timeLimit;
	publicVariable "roundEndTime";
	roundInProgress=true;
	publicVariable "roundInProgress";
	setupReady=false;
	publicVariable "setupReady";
	
	{
		_x allowDamage true;
	} forEach allUnits;

	_eastUnitArr = [];
	_westUnitArr = [];
	{
		if ((!isNull (missionNameSpace getVariable _x)) && missionNameSpace getVariable (format ["%1connected", _x])) then
		{
			_eastUnitArr set [count _eastUnitArr, missionNameSpace getVariable _x];
		};
	} forEach _eastNames;
	{
		if ((!isNull (missionNameSpace getVariable _x)) && missionNameSpace getVariable (format ["%1connected", _x])) then
		{
			_westUnitArr set [count _westUnitArr, missionNameSpace getVariable _x];
		};
	} forEach _westNames;
	_eastUnitCount = count _eastUnitArr;
	_westUnitCount = count _westUnitArr;
	
	waitUntil
	{
		{alive _x} count _eastUnitArr == 0	
		||
		{alive _x} count _westUnitArr == 1
		||
		{alive _x} count _westUnitArr <= 0.2 * _westUnitCount
		||
		((getDammage obj1>0.9999) && (getDammage obj2>0.9999))
		||
		time>roundEndTime
	};
	
	while {roundEnd==0} do
	{
		if (time>roundEndTime) then
		{
			roundEnd=4;
			publicVariable "roundEnd";
		}
		else
		{
			if ((getDammage obj1>0.9999) && (getDammage obj2>0.9999)) then
			{
				roundEnd=3;
				publicVariable "roundEnd";
			}
			else
			{
				if ({alive _x} count _eastUnitArr == 0) then
				{
					roundEnd=2;
					publicVariable "roundEnd";
				}
				else
				{
					if ({alive _x} count _westUnitArr == 0) then
					{
						roundEnd=1;
						publicVariable "roundEnd";
					}
					else
					{
						if ((time + lastPlayersCountdown)<roundEndTime) then
						{
							roundEndTime = time + lastPlayersCountdown;
							publicVariable "roundEndTime";
							bLastPlayersCountdown = true;
							publicVariable "bLastPlayersCountdown";
						};
						WaitUntil
						{
							{alive _x} count _eastUnitArr == 0	
							||
							{alive _x} count _westUnitArr == 0
							||
							((getDammage obj1>0.9999) && (getDammage obj2>0.9999))
							||
							time>roundEndTime
						};
					};
				};
			};
		};
	};
	
	if (roundEnd==2 || roundEnd==3) then
	{
		scoreW = scoreW+1;
		publicVariable "scoreW";
	}
	else
	{
		scoreE = scoreE+1;
		publicVariable "scoreE";
	};
	
	sleep 5;
	
	if (!isNull obj1) then
	{
		deleteVehicle obj1;
	};
	if (!isNull obj2) then
	{
		deleteVehicle obj2;
	};
};