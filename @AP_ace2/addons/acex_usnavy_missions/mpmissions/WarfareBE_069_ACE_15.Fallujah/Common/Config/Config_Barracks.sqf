Private['_c','_longestBarracksBuildTime','_u'];

/* WEST - Barracks */
_u = Call Compile preprocessFile Format["Common\Config\Core_Units\%1\Units_Barracks_%2.sqf",WFBE_V_West_UnitsRootVersion,WFBE_V_West_Faction];
['WFBE_WESTBARRACKSUNITS',_u,true] Call SetNamespace;
if (local player) then {['BARRACKS','WEST',_u] Call Compile preProcessFile 'Client\Init\Init_Faction.sqf'};

/* EAST - Barracks */
_u = Call Compile preprocessFile Format["Common\Config\Core_Units\%1\Units_Barracks_%2.sqf",WFBE_V_East_UnitsRootVersion,WFBE_V_East_Faction];
['WFBE_EASTBARRACKSUNITS',_u,true] Call SetNamespace;
if (local player) then {['BARRACKS','EAST',_u] Call Compile preProcessFile 'Client\Init\Init_Faction.sqf'};

if (isServer) then {
	/* Allies */
	if (('WFBE_ALLIES' Call GetNamespace) > 0) then {
		//--- CDF Allies.
		_u = Call Compile preprocessFile "Common\Config\Core_Units\Vanilla\Units_Barracks_CDF.sqf";
		['WFBE_WESTALLIESBARRACKSUNITS',_u,true] Call SetNamespace;	
		['WFBE_WESTALLIESSOLDIER','CDF_Soldier',true] Call SetNamespace;
		
		//--- Insurgent Allies.
		_u = Call Compile preprocessFile "Common\Config\Core_Units\Vanilla\Units_Barracks_INS.sqf";
		['WFBE_EASTALLIESBARRACKSUNITS',_u,true] Call SetNamespace;	
		['WFBE_EASTALLIESSOLDIER','Ins_Soldier_1',true] Call SetNamespace;
	};
};

/* Root classes */
westSoldierBaseClass = 'SoldierWB';
eastSoldierBaseClass = 'SoldierEB';
resistanceSoldierBaseClass = 'SoldierGB';

_longestBarracksBuildTime = 0;
{
	_c = _x Call GetNamespace;
	if !(isNil '_c') then {
		if ((_c select QUERYUNITTIME) > _longestBarracksBuildTime) then {
			_longestBarracksBuildTime = (_c select QUERYUNITTIME);
		};
	} else {
		diag_log Format ["[WFBE (ERROR)][frameno:%2 | ticktime:%3] Config_Barracks: '%1' is not defined in the Core files.",_x,diag_frameno,diag_tickTime];
	};
} forEach (('WFBE_EASTBARRACKSUNITS' Call GetNamespace) + ('WFBE_WESTBARRACKSUNITS' Call GetNamespace));

['WFBE_LONGESTBARRACKSBUILDTIME',_longestBarracksBuildTime,true] Call SetNamespace;

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Config_Barracks: Initialization (West: %3 | East: %4) - [Done]",diag_frameno,diag_tickTime,WFBE_V_West_Faction,WFBE_V_East_Faction];