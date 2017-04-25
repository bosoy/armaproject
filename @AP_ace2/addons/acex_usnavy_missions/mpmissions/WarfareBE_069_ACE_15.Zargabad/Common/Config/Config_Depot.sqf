Private['_c','_longestDepotBuildTime','_u'];

/* WEST - Depot */
_u = Call Compile preprocessFile Format["Common\Config\Core_Units\%1\Units_Depot_%2.sqf",WFBE_V_West_UnitsRootVersion,WFBE_V_West_Faction];
['WFBE_WESTDEPOTUNITS',_u,true] Call SetNamespace;
if (local player) then {['DEPOT','WEST',_u] Call Compile preProcessFile 'Client\Init\Init_Faction.sqf'};

/* EAST - Depot */
_u = Call Compile preprocessFile Format["Common\Config\Core_Units\%1\Units_Depot_%2.sqf",WFBE_V_East_UnitsRootVersion,WFBE_V_East_Faction];
['WFBE_EASTDEPOTUNITS',_u,true] Call SetNamespace;
if (local player) then {['DEPOT','EAST',_u] Call Compile preProcessFile 'Client\Init\Init_Faction.sqf'};

_longestDepotBuildTime = 0;
{
	_c = _x Call GetNamespace;
	if !(isNil '_c') then {
		if ((_c select QUERYUNITTIME) > _longestDepotBuildTime) then {
			_longestDepotBuildTime = (_c select QUERYUNITTIME);
		};
	} else {
		diag_log Format ["[WFBE (ERROR)][frameno:%2 | ticktime:%3] Config_Depot: '%1' is not defined in the Core files.",_x,diag_frameno,diag_tickTime];
	};
} forEach (('WFBE_EASTDEPOTUNITS' Call GetNamespace) + ('WFBE_WESTDEPOTUNITS' Call GetNamespace));

['WFBE_LONGESTDEPOTBUILDTIME',_longestDepotBuildTime,true] Call SetNamespace;

depotDistance = 21;
depotDirection = 90;

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Config_Depot: Initialization (West: %3 | East: %4) - [Done]",diag_frameno,diag_tickTime,WFBE_V_West_Faction,WFBE_V_East_Faction];