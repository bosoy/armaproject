Private ["_killed","_killer","_killerTeam","_sideKiller"];
_killed = _this select 0;
_killer = _this select 1;
_sideKiller = side _killer;
_killerTeam = group _killer;

//--- Renegade.
if (_sideKiller == sideEnemy) then {
	if (_killer isKindOf westSoldierBaseClass) then {_sideKiller = west};
	if (_killer isKindOf eastSoldierBaseClass) then {_sideKiller = east};
};

//--- Benny's Garbage Collector.
if (WF_A2_Vanilla) then {
	trashQueu = trashQueu + [_killed];
	_killed Spawn TrashObject;
};

sleep random(2)+random(4);

//--- Civilian's death.
if (!isNull _killerTeam && (_sideKiller == west) || (_sideKiller == east)) then {
	if (isPlayer (leader _killerTeam)) then {
		/* Penalty */
		WFBE_Penalty = [vehicleVarName (leader _killerTeam),'CLTFNCPENALTY'];
		publicVariable 'WFBE_Penalty';
		if (isHostedServer) then {[vehicleVarName (leader _killerTeam),'CLTFNCPENALTY'] Spawn HandlePVF};
	};
};