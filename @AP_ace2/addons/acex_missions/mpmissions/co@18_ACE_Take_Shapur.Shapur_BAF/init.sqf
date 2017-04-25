if (IsServer and paramsArray select 1 == 2) then {0 setOvercast (random 1)};
if (IsServer and paramsArray select 1 == 3) then {0 setOvercast 0.25};
if (IsServer and paramsArray select 1 != 2 and paramsArray select 1 != 3) then {0 setOvercast (paramsArray select 1)};

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

//--- West
{
	_x setvariable ["bis_nocoreconversations",true];
	if (side _x == west) then {
		_x allowfleeing 0;
		_x setskill (random 0.9);
	};
} foreach allunits;

if (!isDedicated) then {
	waitUntil {!isNull player};
	execVM "intro.sqf";
};