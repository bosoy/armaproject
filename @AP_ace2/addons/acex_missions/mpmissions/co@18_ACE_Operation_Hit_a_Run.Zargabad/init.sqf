setviewdistance 2000;

execVM "briefing.sqf";
execVM "ac130_init.sqf";
if (paramsarray select 2 == 0) then {server execVM "revive_init_all.sqf"} else {server execVM "revive_init_med.sqf"};
execVM "halo_init.sqf";
execVM "DW_init.sqf";

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