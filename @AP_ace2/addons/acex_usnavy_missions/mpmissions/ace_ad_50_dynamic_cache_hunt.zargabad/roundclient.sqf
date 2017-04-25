Private ["_westStartMarker", "_objMarker", "_obj1Marker", "_obj2Marker"];

waitUntil {alive player};
if (loadouts>0) then
{
	call compile preprocessFile "assigngear.sqf";
}
else
{
	call compile preprocessFile "defaultload.sqf";
};

missionNameSpace setVariable [format ["%1connected", vehicleVarName player], true];
publicVariable (format ["%1connected", vehicleVarName player]);

if (playerSide == WEST) then
{
	_westStartMarker = createMarkerLocal ["mrkWestStart", [1,1]];
	_westStartMarker setMarkerShapeLocal "ICON";
	_westStartMarker setMarkerTypeLocal "Start";
	_westStartMarker setMarkerTextLocal "Insertion";
	_westStartMarker setMarkerColorLocal "COLORGREEN";
	_westStartMarker setMarkerSizeLocal [1.1,1.1];
	_objMarker = createMarkerLocal ["mrkObj", [1,1]];
	_objMarker setMarkerShapeLocal "ICON";
	_objMarker setMarkerTypeLocal "mil_objective";
	_objMarker setMarkerColorLocal "COLORRED";
	_objMarker setMarkerSizeLocal [1.1,1.1];
	
	waitUntil {!isNil "westStartPos"};
	_westStartMarker setMarkerPosLocal westStartPos;
	waitUntil {!isNil "westStartDir"};
	_westStartMarker setMarkerDirLocal westStartDir;
	waitUntil {!isNil "objPos"};
	_objMarker setMarkerPosLocal objPos;
}
else
{
	_obj1Marker = createMarkerLocal ["mrkObj1", [1000,1000]];
	_obj2Marker = createMarkerLocal ["mrkObj2", [1,1]];
	{
		_x setMarkerShapeLocal "ICON";
		_x setMarkerTypeLocal "Dot";
		_x setMarkerColorLocal "COLORRED";
	} forEach [_obj1Marker, _obj2Marker];
	waitUntil {!isNil "obj1Pos"};
	_obj1Marker setMarkerPosLocal obj1Pos;
	waitUntil {!isNil "obj2Pos"};
	_obj2Marker setMarkerPosLocal obj2Pos;
};

execVM "timermsg.sqf";

while {isNil "roundStartTime"} do
{
	waitUntil {!isNil "roundStartTime" || !alive player};
	if (!alive player) then
	{
		waitUntil {alive player};
		execVM "loadloadout.sqf";
	};
};
if (roundStartTime>time) then
{
	[roundStartTime-time] execVM "setupmsg.sqf";
};

while {isNil "roundInProgress"} do
{
	waitUntil {!isNil "roundInProgress" || !alive player};
	if (!alive player) then
	{
		waitUntil {alive player};
		execVM "loadloadout.sqf";
	};
};

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

ace_sys_spectator_can_exit_spectator = true;

if (roundInProgress) then
{
	ace_sys_spectator_exit_spectator = nil;
	[] spawn ace_fnc_startSpectator;
	while {roundInProgress} do
	{
		waitUntil {!roundInProgress || !alive player};
		if (!alive player) then
		{
			waitUntil {alive player};
			execVM "loadloadout.sqf";
		};
	};
};

while {true} do
{
	while {!setupReady} do
	{
		waitUntil {setupReady || !alive player};
		if (!alive player) then
		{
			waitUntil {alive player};
			execVM "loadloadout.sqf";
		};		
	};
	if (playerSide == WEST) then
	{
		_westStartMarker setMarkerPosLocal westStartPos;
		_westStartMarker setMarkerDirLocal westStartDir;
		_objMarker setMarkerPosLocal objPos;
	}
	else
	{
		_obj1Marker setMarkerPosLocal obj1Pos;
		_obj2Marker setMarkerPosLocal obj2Pos;
	};
	ace_sys_spectator_exit_spectator = true;
	
	while {!roundInProgress} do
	{
		waitUntil {roundInProgress || !alive player};
		if (!alive player) then
		{
			waitUntil {alive player};
			execVM "loadloadout.sqf";
		};		
	};

	player setVelocity [0,0,0];	
	if (playerSide == WEST) then
	{
		player setPos westStartPos;
		player setDir westStartDir;
	}
	else
	{
		player setPos eastStartPos;
	};
	player setDammage 0;
	player call ace_sys_wounds_fnc_RemoveUncon;
	{
		_x allowDamage true;
	} forEach allUnits;
	
	if (loadouts==0) then
	{
		call compile preprocessFile "defaultload.sqf";
		execVM "saveloadout.sqf";
	}
	else
	{
		execVM "loadloadout.sqf";
	};	
	waitUntil {!(alive player) || !roundInProgress};
	if (!alive player) then
	{
		waitUntil {alive player};
		call compile preprocessFile "loadloadout.sqf";
		ace_sys_spectator_exit_spectator = nil;
		[] spawn ace_fnc_startSpectator;
	}
	else
	{
		if (playerSide == WEST) then
		{
			player setPos markerPos "respawn_west";
		}
		else
		{
			player setPos markerPos "respawn_east";
		};
		player setDammage 0;
		player call ace_sys_wounds_fnc_RemoveUncon;
		execVM "loadloadout.sqf";
	};
	while {roundInProgress} do
	{
		waitUntil {!roundInProgress || !alive player};
		if (!alive player) then
		{
			waitUntil {alive player};
			call compile preprocessFile "loadloadout.sqf";
		};
	};
	execVM "roundmsg.sqf";
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
};