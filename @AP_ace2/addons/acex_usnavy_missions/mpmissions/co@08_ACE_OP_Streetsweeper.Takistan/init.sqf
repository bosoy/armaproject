if (IsServer and paramsArray select 0 == 1) then {skiptime (random -96)};
if (IsServer and paramsArray select 0 == 2) then {setDate [2020, 7, 20, 1, 0]};
if (IsServer and (paramsArray select 0 != 1) and (paramsArray select 0 != 2)) then {skiptime (paramsArray select 0)};
if (IsServer and paramsArray select 2 == 2) then {0 setOvercast (random 1)};
if (IsServer and paramsArray select 2 == 3) then {0 setOvercast 0.25};
if (IsServer and paramsArray select 2 != 2 and paramsArray select 2 != 3) then {0 setOvercast (paramsArray select 2)};

execVM "briefing.sqf";
server execVM "revive_init.sqf";

//--- East
{
	_x setvariable ["bis_nocoreconversations",true];
	if (side _x == east) then {
		_x allowfleeing 0;
		_x setskill (random 0.9);
	};
} foreach allunits;

waitUntil {!(isNull player)};
execVM "intro.sqf";