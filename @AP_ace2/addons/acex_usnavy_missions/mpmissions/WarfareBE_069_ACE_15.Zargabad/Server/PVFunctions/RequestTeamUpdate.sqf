private ["_args","_team"];

_args = _this;
_team = _args select 0;

//--- One team.
if (typeName _team == "ARRAY") then {
	{
		_x setBehaviour (_args select 1);
		_x setCombatMode (_args select 2);
		_x setFormation (_args select 3);
		_x setSpeedMode (_args select 4);
		diag_log Format["[WFBE (INFORMATION)][frameno:%6 | ticktime:%7] RequestTeamUpdate: The %1 Team properties has been updated (Behavior: %2 | Combat Mode: %3 | Formation: %4 | Speed Mode: %5)",_x,(_args select 1),(_args select 2),(_args select 3),(_args select 4),diag_frameno,diag_tickTime];
	} forEach _team;
};

//--- The whole team.
if (typeName _team == "SIDE") then {
	{
		_x setBehaviour (_args select 1);
		_x setCombatMode (_args select 2);
		_x setFormation (_args select 3);
		_x setSpeedMode (_args select 4);
	} forEach (Format["WFBE_%1TEAMS",str _team] Call GetNamespace);
	diag_log Format["[WFBE (INFORMATION)][frameno:%6 | ticktime:%7] RequestTeamUpdate: The %1 Teams properties have been updated (Behavior: %2 | Combat Mode: %3 | Formation: %4 | Speed Mode: %5)",_team,(_args select 1),(_args select 2),(_args select 3),(_args select 4),diag_frameno,diag_tickTime];
};