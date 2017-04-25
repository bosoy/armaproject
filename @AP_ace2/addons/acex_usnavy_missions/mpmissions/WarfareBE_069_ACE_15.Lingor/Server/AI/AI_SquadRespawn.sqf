Private ["_availableSpawn","_autonomous","_buildings","_checks","_closestRespawn","_deathLoc","_enemySide","_hq","_isForcedRespawn","_leader","_mobileRespawns","_moveMode","_pos","_ran","_range","_rcm'","_rd","_respawn","_respawnLoc","_side","_sideText","_team","_update","_upgrades"];
_side = _this select 0;
_team = _this select 1;
_sideText = str _side;
_deathLoc = objNull;
_respawnLoc = objNull;

_rd = 'WFBE_RESPAWNDELAY' Call GetNamespace;
_rcm = 'WFBE_RESPAWNCAMPSMODE' Call GetNamespace;

sleep (random 0.5);

while {!gameOver} do {
	if (isPlayer leader _team) exitWith {};
	[str _side,'UnitsCreated',1] Call UpdateStatistics;
	waitUntil {!alive leader _team || isPlayer leader _team};
	_deathLoc = getPos (leader _team);
	diag_log format ["[WFBE (INFORMATION)][frameno:%4 | ticktime:%5] AI_SquadRespawn: AI Team Leader '%1' (Team '%2') is dead at %3",leader _team,_team,_deathLoc,diag_frameno,diag_tickTime];
	if (isPlayer leader _team) exitWith {};
	waitUntil {alive leader _team || isPlayer leader _team};
	if (isPlayer leader _team) exitWith {};

	_respawn = (_team) Call GetTeamRespawn;
	
	//--- Place the AI.
	_leader = leader _team;
	_leader removeAllEventHandlers "Killed";
	Call Compile Format ["_leader addEventHandler ['Killed',{[_this select 0,_this select 1,%1] Spawn UnitKilled}]",_side];
	_leader setPos getMarkerPos Format["%1TempRespawnMarker",_sideText];

	_availableSpawn = [];
	_isForcedRespawn = false;
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
	
	sleep _rd;

	//--- Equip the AI.
	_ran = 1 + round(random(2));
	[_leader,Format ["WFBE_%1LEADERWEAPONS%2%3",_sideText,_upgrades select 13,_ran] Call GetNamespace, Format ["WFBE_%1LEADERAMMO%2%3",_sideText,_upgrades select 13,_ran] Call GetNamespace] Call EquipLoadout;
	_hq = (_sideText) Call GetSideHQ;
	_buildings = (_sideText) Call GetSideStructures;

	//--- Check whether AI has a spawn set or not.
	_update = false;
	switch (typeName _respawn) do {
		case "STRING": {
			_update = true;
			if (_isForcedRespawn) then {[_team,""] Call SetTeamRespawn};
		}; //--- Not defined.
		case "OBJECT": {
			_respawnLoc = _respawn;
			if (!alive _respawn || isNull _respawn) then {
				[_team, ""] Call SetTeamRespawn;
				_update = true;
			};	//--- Defined.
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

	diag_log format ["[WFBE (INFORMATION)][frameno:%4 | ticktime:%5] AI_SquadRespawn: AI Team Leader %1 is respawning at: %2 (%3)",leader _team,typeOf _respawnLoc,_respawnLoc,diag_frameno,diag_tickTime];
	_pos = [getPos _respawnLoc,20,30] Call GetRandomPosition;
	_pos set [2,0];
	_leader setPos _pos;
	
	//--- Assign fresh order (tbc).
	_autonomous = (_team) Call GetTeamAutonomous;
	if !(_autonomous) then {
		_moveMode = (_team) Call GetTeamMoveMode;
		if (_moveMode == "towns") then {[_team,"resetTowns"] Call SetTeamMoveMode};
		if (_moveMode == "move") then {[_team,"resetMove"] Call SetTeamMoveMode};
		if (_moveMode == "patrol") then {[_team,"resetPatrol"] Call SetTeamMoveMode};
		if (_moveMode == "defense") then {[_team,"resetDefense"] Call SetTeamMoveMode};
	};
};