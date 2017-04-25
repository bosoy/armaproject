/* Enhanced Respawn Management via Multiplayer Event Handler - Experimental */
Private ['_autonomous','_availableSpawn','_buildings','_checks','_closestRespawn','_corpse','_deathLoc','_hq','_i','_isForcedRespawn','_mobileRespawns','_moveMode','_pos','_ran','_range','_rcm','_rd','_respawn','_respawnLoc','_respawnedUnit','_side','_sideText','_skip','_team','_update','_upgrades'];

_respawnedUnit = _this select 0;
_corpse = _this select 1;

_deathLoc = getPos _corpse;
_rd = 'WFBE_RESPAWNDELAY' Call GetNamespace;
_rcm = 'WFBE_RESPAWNCAMPSMODE' Call GetNamespace;

_side = side _respawnedUnit;
//--- Ensure that the side is not civilian.
if (_side == civilian) then {
	if (_respawnedUnit isKindOf westSoldierBaseClass) then {_side = west};
	if (_respawnedUnit isKindOf eastSoldierBaseClass) then {_side = east};
};
_sideText = str _side;
_team = group _respawnedUnit;
_respawn = (_team) Call GetTeamRespawn;
_respawnLoc = objNull;

diag_log format ["[WFBE (INFORMATION)][frameno:%7 | ticktime:%8] AI_AdvancedRespawn: AI Team Leader '%1' (Team '%2', Rank '%3', Type '%4', Side '%5') has respawned after dieing at %6",_respawnedUnit,_team,rank _respawnedUnit,typeOf _respawnedUnit,_side,_deathLoc,diag_frameno,diag_tickTime];

//--- Remove previous EH.
_respawnedUnit removeAllEventHandlers "Killed";
Call Compile Format ["_respawnedUnit addEventHandler ['Killed',{[_this select 0,_this select 1,%1] Spawn UnitKilled}]",_side];

//--- Place the leader on a 'safe' position.
_respawnedUnit setPos getMarkerPos Format["%1TempRespawnMarker",_sideText];

_availableSpawn = [];
_isForcedRespawn = false;

//--- Ensure that the ai is not forced to respawn.
if (typeName _respawn == 'STRING') then {if (_respawn == "forceRespawn") then {_isForcedRespawn = true}};

//--- Towns.
if (_rcm > 0 && !_isForcedRespawn) then {
	_availableSpawn = _availableSpawn + ([_deathLoc, _side] Call GetRespawnCamps);
};

_upgrades = (_sideText) Call GetSideUpgrades;

//--- Mobile Respawn.
if (paramMobileRespawn && !_isForcedRespawn) then {
	_mobileRespawns = Format ["WFBE_%1AMBULANCES",_sideText] Call GetNamespace;
	_range = (Format["WFBE_RESPAWNMOBILERANGE%1",(_upgrades select 7)] Call GetNamespace);
	_checks = _deathLoc nearEntities[_mobileRespawns,_range];
	if (count _checks > 0) then {
		{if (alive _x) then {_availableSpawn = _availableSpawn + [_x]}} forEach _checks;
	};
};

//--- Wait.
_i = _rd;
_skip = false;
while {_i > 0} do {
	if (isPlayer(_respawnedUnit) || !(alive _respawnedUnit)) exitWith {_skip = true};
	
	_i = _i - 1;	
	sleep 1;
};

//--- Make sure that the AI didn't die or that a player hasn't replaced him before going any further.
if !(_skip) then {
	//--- Equip the AI.
	_ran = 1 + round(random(2));
	[_respawnedUnit,Format ["WFBE_%1LEADERWEAPONS%2%3",_sideText,_upgrades select 13,_ran] Call GetNamespace, Format ["WFBE_%1LEADERAMMO%2%3",_sideText,_upgrades select 13,_ran] Call GetNamespace] Call EquipLoadout;
	_hq = (_sideText) Call GetSideHQ;
	_buildings = (_sideText) Call GetSideStructures;

	//--- Check whether AI has a spawn set or not.
	_update = false;
	switch (typeName _respawn) do {
		case "STRING": {
			//--- Not defined.
			_update = true;
			if (_isForcedRespawn) then {[_team,""] Call SetTeamRespawn};
		};
		case "OBJECT": {
			//--- Defined.
			_respawnLoc = _respawn;
			if (!alive _respawn || isNull _respawn) then {
				[_team, ""] Call SetTeamRespawn;
				_update = true;
			};
		};
	};
	
	//--- Default respawn.
	if (_update) then {
		_respawnLoc = _hq;
		if (count _buildings > 0) then {
			_closestRespawn = [_hq,_buildings] Call SortByDistance;
			_respawnLoc = _closestRespawn select 0;
		};
	};
	
	//--- Alternative spawn location.
	if (count _availableSpawn > 0) then {
		_respawnLoc = _availableSpawn select (round(random((count _availableSpawn)-1)));
	};

	diag_log format ["[WFBE (INFORMATION)][frameno:%4 | ticktime:%5] AI_AdvancedRespawn: AI Team Leader %1 is respawning at: %2 (%3)",_respawnedUnit,typeOf _respawnLoc,_respawnLoc,diag_frameno,diag_tickTime];
	
	_pos = [getPos _respawnLoc,20,30] Call GetRandomPosition;
	_pos set [2,0];
	_respawnedUnit setPos _pos;
	
	//--- Assign fresh order if the AI is not on autonomous mode.
	_autonomous = (_team) Call GetTeamAutonomous;
	if !(_autonomous) then {
		_moveMode = (_team) Call GetTeamMoveMode;
		if (_moveMode == "towns") then {[_team,"resetTowns"] Call SetTeamMoveMode};
		if (_moveMode == "move") then {[_team,"resetMove"] Call SetTeamMoveMode};
		if (_moveMode == "patrol") then {[_team,"resetPatrol"] Call SetTeamMoveMode};
		if (_moveMode == "defense") then {[_team,"resetDefense"] Call SetTeamMoveMode};
	};
};