private ["_display", "_map", "_hq", "_respawnCampsRuleMode", "_availableSpawn", "_buildings", "_checks", "_mobileRespawns", "_upgrades", "_range", "_farps", "_markers", "_markerIndex", "_markerName", "_spawn", "_ta", "_position", "_sorted", "_loadDefault", "_mode", "_skip", "_price", "_funds", "_safeArray", "_temp", "_listbp", "_weaps"];
disableSerialization;

MenuAction = -1;
mouseButtonUp = -1;
_display = _this select 0;
_map = _display displayCtrl 15001;

_spawn = objNull;
_availableSpawn = [];
_markers = [];
_markerIndex = 0;
_ta = "";
_lastSpawnUpdate = 0;

//--- Wait until the player respawned.
waitUntil {alive player};

//--- Position the player at the temp location during his respawn.
player setPos ([getMarkerPos Format["%1TempRespawnMarker",sideJoinedText],1,10] Call GetRandomPosition);
if (leader(group player) != player) then {(group player) selectLeader player};

//--- Call the pre respawn routine.
(player) Call PreRespawnHandler;

//--- Spawn a countdown thread.
respawnDone = false;
_handleTimer = [] Spawn {
	if (isNil 'respawnStatus') then {respawnStatus = 'WFBE_RESPAWNDELAY' Call GetNamespace};
	while {respawnStatus >= 0} do {
		sleep 1;
		respawnStatus = respawnStatus - 1;
	};
	respawnDone = true;
};

//--- Run the main respawn thread.
while {!respawnDone} do {	
	//--- Exit the thread if the client died.
	if !(alive player) exitWith {};
	
	//--- Loadout Selection.
	ctrlSetText [15004, if (WFBE_RespawnDefaultGear) then {"D"} else {"C"}];
	
	//--- Preloading Status.
	ctrlSetText [15005, if (WFBE_EnablePreload) then {"P"} else {"N"}];
	
	//--- Update the respawn info.
	if (time - _lastSpawnUpdate > 2) then {
		_lastSpawnUpdate = time;
		_lastAvailableSpawn = _availableSpawn;
		_availableSpawn = [sideJoined,deathLocation] Call GetRespawnAvailable;
		
		//--- First launch.
		if (isNull _spawn) then {
			_spawn = _availableSpawn select 0;
			_ta = ["TempAnim",getPos _spawn,"Select",1.4,"ColorBlue",1.4,1.8] Spawn MarkerAnim;
			respawnName = [typeOf _spawn, 'displayName'] Call GetConfigInfo;
		};
		
		//--- Properly update the client's map - Update removal.
		_found = false;
		{
			if !(_x in _availableSpawn) then {
				_mid = _x getVariable 'WFBE_IDRMarker';
				_markers = _markers - [_mid];
				deleteMarkerLocal _mid;
				_x setVariable ['WFBE_IDRMarker',nil];
				if (_x == _spawn && !_found) then {
					_found = true;
					_spawn = ([_x, _availableSpawn] Call SortByDistance) select 0;
					terminate _ta;
					deleteMarkerLocal "TempAnim";
					_ta = ["TempAnim",getPos _spawn,"Select",1.4,"ColorBlue",1.4,1.8] Spawn MarkerAnim;
					respawnName = [typeOf _spawn, 'displayName'] Call GetConfigInfo;
				};
			};
		} forEach _lastAvailableSpawn;
		
		//--- Properly update the client's map - Update add.
		{
			if !(_x in _lastAvailableSpawn) then {
				_markerName = Format ["respawnMarker%1",_markerIndex];
				_markers = _markers + [_markerName];
				createMarkerLocal [_markerName,getPos _x];
				_markerName setMarkerTypeLocal "Select";
				_markerName setMarkerColorLocal "ColorYellow";
				_markerName setMarkerSizeLocal [1,1];
				_markerIndex = _markerIndex + 1;
				_x setVariable ['WFBE_IDRMarker',_markerName];
			};
		} forEach _availableSpawn;
	};
	
	//--- Update the respawn timer.
	ctrlSetText [15003,Format [localize "STR_WF_RespawnStatus",respawnStatus,respawnName]];
	
	//--- The client has clicked on the map.
	if (mouseButtonUp == 0) then {
		mouseButtonUp = -1;
		if (count _availableSpawn > 1) then {
			_position = _map PosScreenToWorld[mouseX,mouseY];
			_sorted = [_position,_availableSpawn] Call SortByDistance;
			if ((_sorted select 0) distance _position < 500) then {
				_spawn = _sorted select 0;
				activeAnimMarker = false;
				terminate _ta;
				deleteMarkerLocal "TempAnim";
				_ta = ["TempAnim",getPos _spawn,"Select",1.4,"ColorBlue",1.4,1.8] Spawn MarkerAnim;
				respawnName = [typeOf _spawn, 'displayName'] Call GetConfigInfo;
			};
		};
	};
	
	sleep 0.1;
};

//--- If the spawn is null, we use the HQ.
if (isNull _spawn) then {
	_hq = (sideJoinedText) Call GetSideHQ;
	_spawn = _hq;
};

//--- Pre-render.
if (WFBE_EnablePreload) then {
	ctrlSetText [15003,localize 'STR_WF_Preload'];
	waitUntil{preloadCamera (getPos _spawn) || !(alive player)};
};

//--- Execute on respawn code only if the player's alive.
if (alive player) then {
	[player,_spawn] Call OnRespawnHandler;
};

//--- Terminate the threads & cleaning.
{deleteMarkerLocal _x} forEach _markers;
{_x setVariable ['WFBE_IDRMarker',nil]} forEach _availableSpawn;
if !(isNil "DeathCamera") then {
	DeathCamera cameraEffect["TERMINATE","BACK"];
	camDestroy DeathCamera;
};

"dynamicBlur" ppEffectEnable false;
"colorCorrections" ppEffectEnable false;
[currentFX] Spawn FX;
terminate _ta;
if !(scriptDone _handleTimer) then {terminate _handleTimer};
deleteMarkerLocal "TempAnim";
activeAnimMarker = false;
playerDead = false;
respawnDone = nil;
respawnName = nil;
respawnStatus = nil;
closeDialog 0;

hint (localize "STR_WF_RespawnInfo");